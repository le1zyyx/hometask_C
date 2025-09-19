CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: cipher float_representation

cipher: cipher.c
	$(CC) $(CFLAGS) cipher.c -o cipher

float_representation: float_representation.c
	$(CC) $(CFLAGS) float_representation.c -o float_representation

clean:
	rm -f cipher float_representation
