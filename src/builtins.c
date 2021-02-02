#include "ush.h"

int cd(int argc, char **argv);
int help(int argc, char **argv);
int exit_shell(int argc, char **argv);

char *builtins[] = {
    "exit",
    "cd"
};

int (*builtin_funcs[]) (int, char**) = {
    &exit_shell,
    &cd
};

int num_builtins(void) {
    return sizeof(builtins) / sizeof(char *);
}

int cd(int argc, char **argv)
{
    if (argv[1] == NULL)
        argv[1] = getenv("HOME");

    char *OLDPWD = getenv("OLDPWD");

    if (strcmp(argv[1], "-") == 0)
        argv[1] = OLDPWD;

    if(chdir(argv[1]) != 0)
        perror("cd");

    setenv("OLDPWD", OLDPWD, 1); // Update OLDPWD

    return 0;
}

int exit_shell(int argc, char **argv)
{
    exit(EXIT_SUCCESS);
}
