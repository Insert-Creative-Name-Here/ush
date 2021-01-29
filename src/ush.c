#include "ush.h"

int main(int argc, char **argv)
{
    // Config files...


    // Interactive mode
    loop();


    // Then should come some cleanup


    return 0;
}

void loop(void)
{
    char *line;
    char **args;
    int status;

    do {
        line = read_command();
        args = parse_line(line);
        status = execute_command(args);
    } while (!status);
}

int exec_extern_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1)
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

char *expand_variable(char *arg) {
    char *look_for = arg + 1;
    printf("%s\n", look_for);

    return getenv(look_for);
}

int execute_command(char **args)
{
    if (args[0] == NULL) {
        return 0;
    }

    for (int i = 0; i < num_aliases(); i++)
        if (strcmp(args[0], aliases[i]) == 0)
            args[0] = alias_expansion[i];

    for (int i = 0; i < num_builtins(); i++) {
        if (strcmp(args[0], builtins[i]) == 0)
            return (*builtin_funcs[i])(args);
    }

    return exec_extern_command(args);
}
