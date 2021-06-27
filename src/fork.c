#include "fork.h"
#include "aliases.h"
#include "builtins.h"

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fork_program(char *prog_name, char **prog_args)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(prog_name, prog_args) == -1)
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

int exec_cmd(int argc, char **argv)
{
    if (argv[0] == NULL)
        return 0;

    for (int i = 0; i < num_builtins(); i++) {
        if (strcmp(argv[0], aliases[i]) == 0) {
            argv[0] = alias_expansion[i];
            break;
        }
    }

    for (int i = 0; i < num_builtins(); i++)
        if (strcmp(argv[0], builtins[i]) == 0)
            return (*builtin_funcs[i])(argc, argv);

    return exec_cmd(argc, argv);
}
