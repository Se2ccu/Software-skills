CC#gcc
CFLAGS#-c -w all

all:	test

test:	test.o five.o
	$(CC) -o test test.o five.o

test.o :	test.c
	$(CC) $(CFLAGS) test.c

five.o :	five.c
	$(CC) $(CFLAGS) five.c

clean:	
	rm test
	rm *.o
