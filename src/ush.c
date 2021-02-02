#include "ush.h"

int main(int argc, char **argv)
{
    // Load config files, if any...
    setenv("OLDPWD", getenv("PWD"), 1); // Initialize OLDPWD

    // Interactive mode
    loop();


    // Then, do some cleanup...


    return 0;
}

void loop(void)
{
    char *line;
    int argc;
    char **argv;
    int status;

    do {
        line = read_command();
        argv = parse_line(line);
        argc = sizeof(argv) / sizeof(char);
        status = execute_command(argc, argv);
    } while (!status);
}

int exec_extern_command(int argc, char **argv)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(argv[0], argv) == -1)
            perror("execvp");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork error");
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 0;
}

int execute_command(int argc, char **argv)
{
    if (argv[0] == NULL) {
        return 0;
    }

    for (int i = 0; i < num_aliases(); i++)
        if (strcmp(argv[0], aliases[i]) == 0)
            argv[0] = alias_expansion[i];

    for (int i = 0; i < num_builtins(); i++)
        if (strcmp(argv[0], builtins[i]) == 0)
            return (*builtin_funcs[i])(argc, argv);

    return exec_extern_command(argc, argv);
}
