#ifndef USH_H
#define USH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define TOK_BUFSIZE    64
#define TOK_DELIM " \t\n"
#define PROMPT  "> "

void loop(void);
int execute_command(int argc, char **argv);
char *read_command(void);
char **parse_line(char *line);

// Aliases
extern char *aliases[];
extern char *alias_expansion[];
int num_aliases(void);

// Builtins
extern char *builtins[];
extern int (*builtin_funcs[]) (int, char **);
int num_builtins(void);

#endif // USH_H
