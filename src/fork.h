#ifndef FORK_H
#define FORK_H

int fork_program(char *prog_name, char **prog_args);
int exec_cmd(int argc, char **prog_args);

#endif
