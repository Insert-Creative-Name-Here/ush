#ifndef BUILTINS_H
#define BUILTINS_H

extern char *builtins[];
extern int (*builtin_funcs[]) (int, char **);
int num_builtins(void);

int cd(int argc, char **argv);
int help(int argc, char **argv);
int exit_shell(int argc, char **argv);

#endif
