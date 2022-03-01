CC = gcc
CFLAGS = -O2

all: test

container.o: $(container)
	$(CC) $(CFLAGS) $(container) -c -o container.o

test_sort.o: $(test_sort)
	$(CC) $(CFLAGS) $(test_sort) -c -o test_sort.o

test: container.o test_sort.o
	$(CC) $(CFLAGS) container.o test_sort.o -o test

clean:
	rm *.o

