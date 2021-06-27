#include "input.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

char *read_command()
{
    char *line = (char *) NULL;

    line = readline(PROMPT);

    return line;
}
