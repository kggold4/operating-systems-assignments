# variables
CC = gcc
WGC = -Wall -g -c
THREAD = -D_REENTRANT -pthread

all: solution

solution: solution.o
	$(CC) $(THREAD) -Wall solution.o -o solution -lm

solution.o: solution.c
	$(CC) $(WGC) solution.c -lm

.PHONY: clean all

clean:
	rm -f *.o *.out *.gch solution