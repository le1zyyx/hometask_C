CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: caesar break_caesar bits_change

caesar: caesar.c
	$(CC) $(CFLAGS) caesar.c -o caesar

break_caesar: break_caesar.c
	$(CC) $(CFLAGS) break_caesar.c -o break_caesar

bits_change: bits_change.c
	$(CC) $(CFLAGS) bits_change.c -o bits_change

clean:
	rm -f caesar break_caesar bits_change
