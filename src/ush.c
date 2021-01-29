#include "ush.h"

int main(int argc, char **argv)
{
    loop();

    return 0;
}

void loop(void)
{
    char *line;
    char **args;
    int status;

    do {
        print_prompt();
        line = read_command();
        args = parse_line(line);
        status = execute_command(args);
    } while (status);
}

void print_prompt(void)
{
    printf("> ");
}

char *read_command()
{
    char *line = NULL;
    size_t bufsize = 0;

    if(getline(&line, &bufsize, stdin) == -1) {
        if (feof(stdin)) {
            exit(EXIT_SUCCESS); // received EOF
        } else {
            perror("readline");
            exit(EXIT_FAILURE);
        }
    }

    return line;
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
        perror("pid lower than 0");
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int execute_command(char **args)
{
    if (args[0] == NULL) {
        return 1;
    }

    for(int i = 0; i < num_builtins(); i++) {
        if(strcmp(args[0], builtins[i]) == 0)
            return (*builtin_funcs[i])(args);
    }

    return exec_extern_command(args);
}
