CC 			= gcc
VPATH 		= src:
CFLAGS 		= -Wall -Wpedantic -Wextra -g -lreadline
INSTALL_DIR = ~/bin
BIN_NAME 	= ush
OBJECTS 	= main.o aliases.o builtins.o input.o fork.o parser.o

.PHONY: all
all: $(OBJECTS)
	$(CC) $(CFLAGS) -o ush $(OBJECTS)

main.o: main.c input.h parser.h builtins.h aliases.h

aliases.o: aliases.c aliases.h

builtins.o: builtins.c builtins.h

input.o: input.c input.h

fork.o: fork.c fork.h aliases.h builtins.h

parser.o: parser.c parser.h

.PHONY: install
install: $(BIN_NAME)
	mv $(BIN_NAME) $(INSTALL_DIR)

.PHONY: clean
clean:
	rm $(OBJECTS)
