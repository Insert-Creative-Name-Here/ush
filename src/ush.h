#ifndef USH_H
#define USH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#define TOK_BUFSIZE    64
#define TOK_DELIM " \t\r\n\a"
#define PROMPT  "> "

void loop(void);
int execute_command(char **args);
char *read_command(void);
char **parse_line(char *line);

// Aliases
extern char *aliases[];
extern char *alias_expansion[];
int num_aliases(void);

// Builtins
extern char *builtins[];
extern int (*builtin_funcs[]) (char **);
int num_builtins(void);
int cd(char **args);
int help(char **args);
int exit_shell(char **args);

#endif // USH_H
