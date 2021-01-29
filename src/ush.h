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

// Builtins
extern char *builtins[];
int num_builtins(void);
extern int (*builtin_funcs[]) (char **);
int cd(char **args);
int help(char **args);
int exit_shell(char **args);

#endif // USH_H
