CC = gcc
CFLAGS = -Wall -Wextra -std=c11

PROGS = caesar break_caesar bits_change anagram set_zeroes

all: $(PROGS)

caesar: caesar.c
	$(CC) $(CFLAGS) $< -o $@

break_caesar: break_caesar.c
	$(CC) $(CFLAGS) $< -o $@

bits_change: bits_change.c
	$(CC) $(CFLAGS) $< -o $@

anagram: anagram.c
	$(CC) $(CFLAGS) $< -o $@

set_zeroes: set_zeroes.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(PROGS)
