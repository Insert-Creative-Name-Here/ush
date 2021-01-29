CXX = gcc
CFLAGS = -lreadline
OBJECTS = ush.o parser.o builtins.o

ush: $(OBJECTS)
	$(CXX) $(CFLAGS) -o ush $(OBJECTS)
	rm $(OBJECTS)

ush.o: src/ush.c src/ush.h
	$(CXX) -c src/ush.c

parser.o: src/parser.c src/ush.h
	$(CXX) -c src/parser.c

builtins.o: src/builtins.c src/ush.h
	$(CXX) -c src/builtins.c

clean:
	rm ush
