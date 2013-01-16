CC=gcc
CFLAGS=-c -Wall -g -lrt -W
LDFLAGS=
SOURCES=main.c Graph.c Hamilton.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=program
LIBRARY=lib.h

all: $(SOURCES) $(EXECUTABLE) run 
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:$(LIBRARY)
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
run:
	./$(EXECUTABLE)

test memory:
	 valgrind ./$(EXECUTABLE) clean
	
