#include "parser.h"
#include "input.h"
#include "fork.h"

#include <stdlib.h>

void interactive_loop(void);

int main(int argc, char **argv)
{
    // Load config files, if any...
    setenv("OLDPWD", getenv("PWD"), 1); // Initialize OLDPWD

    // Interactive mode
    interactive_loop();

    // Then, do some cleanup...


    return 0;
}

void interactive_loop(void)
{
    char *line;
    int argc;
    char **argv;
    int status;

    do {
        line = read_command();
        argv = parse_line(line);
        argc = sizeof(argv) / sizeof(char);
        status = exec_cmd(argc, argv);
    } while (!status);
}

