CXX = gcc
CFLAGS =
OBJECTS = ush.o parser.o builtins.o aliases.o

ush: $(OBJECTS)
	$(CXX) -lreadline $(CFLAGS) -o ush $(OBJECTS)
	rm $(OBJECTS)

ush.o: src/ush.c src/ush.h
	$(CXX) -c src/ush.c

parser.o: src/parser.c src/ush.h
	$(CXX) -c src/parser.c

builtins.o: src/builtins.c src/ush.h
	$(CXX) -c src/builtins.c

aliases.o: src/aliases.c src/ush.h
	$(CXX) -c src/aliases.c

clean:
	rm ush
