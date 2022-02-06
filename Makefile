CC = gcc
CFLAGS = -Wall -Wextra -O2

all: test

vector.o: vector.c 
	$(CC) $(CFLAGS) vector.c -c -o vector.o

test_main.o: test_main.c 
	$(CC) $(CFLAGS) test_main.c -c -o test_main.o

test: vector.o test_main.o
	$(CC) $(CFLAGS) vector.o test_main.o -o test

clean:
	rm *.o