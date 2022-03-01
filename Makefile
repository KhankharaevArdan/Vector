CC = gcc
CFLAGS = -O2

all: test

vector.o: vector.c 
	$(CC) $(CFLAGS) vector.c -c -o vector.o

test_sort.o: test_sort.c 
	$(CC) $(CFLAGS) test_sort.c -c -o test_sort.o

test: vector.o test_sort.o
	$(CC) $(CFLAGS) vector.o test_sort.o -o test

clean:
	rm *.o