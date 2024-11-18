CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: matmult

matmult: main.o matmult.o
	$(CC) $(CFLAGS) -o matmult main.o matmult.o

main.o: main.c matmult.h
	$(CC) $(CFLAGS) -c main.c

matmult.o: matmult.c matmult.h
	$(CC) $(CFLAGS) -c matmult.c

clean:
	rm -f *.o matmult
