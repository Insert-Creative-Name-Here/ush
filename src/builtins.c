#include "ush.h"
#include <limits.h>

// Current working dir
char cwdir[PATH_MAX];
char lwdir[PATH_MAX];

char *builtins[] = {
    "exit",
    "cd"
};

int (*builtin_funcs[]) (char**) = {
    &exit_shell,
    &cd
};

int num_builtins(void) {
    return sizeof(builtins) / sizeof(char *);
}

int cd(char **args)
{
    if (args[1] == NULL)
        args[1] = getenv("HOME");

    if (strcmp(args[1], "-") == 0) {
        chdir(lwdir);
        return 0;
    }

    if (!(getcwd(lwdir, sizeof(lwdir)) != NULL))
        perror("getcwd() error");

    if(chdir(args[1]) != 0)
        perror("chdir() error");

    if (!(getcwd(cwdir, sizeof(cwdir)) != NULL))
        perror("getcwd() error");

    return 0;
}

int exit_shell(char **args)
{
    exit(EXIT_FAILURE);
}
