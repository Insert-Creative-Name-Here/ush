#include "ush.h"
#include <readline/readline.h>
#include <readline/history.h>

char *read_command()
{
    char *line = (char *) NULL;

    line = readline(PROMPT);
    if (line) 
        add_history(line);

    return line;
}

char **parse_line(char *line)
{
    int bufsize = TOK_BUFSIZE;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens) {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOK_DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position > bufsize) {
            bufsize += TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOK_DELIM);
    }

    tokens[position] = NULL;

    return tokens;
}
