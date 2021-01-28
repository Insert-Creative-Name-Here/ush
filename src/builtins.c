#include "ush.h"

char *builtins[] = {
    "cd",
};

int (*builtin_funcs[]) (char**) = {
    &cd,
};

int num_builtins(void) {
    return sizeof(builtins) / sizeof(char *);
}

int cd(char **args)
{
    if (args[1] == NULL) {
        args[1] = getenv("HOME");
    } 

    if(chdir(args[1]) != 0)
        perror("cd");

    return 1;
}
