CC=gcc
CFLAGS=-c -Wall -g
LDFLAGS=
SOURCES=main.c point.c segment.c tests.c polygon.c collinear.c pointinsearch.c
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
	./$(EXECUTABLE) <test 

test memory:
	 valgrind ./$(EXECUTABLE) clean
	
