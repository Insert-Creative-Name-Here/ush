#ifndef PARSER_H
#define PARSER_H

#define TOK_BUFSIZE     64
#define TOK_DELIM       " \t\n"

char **parse_line(char *line);

#endif
