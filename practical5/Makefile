CC=gcc
CFLAGS=-std=c11 -Wall -Wextra
INCLUDE=include
SRC=src
TESTS=tests
test: $(SRC)/array_utils.c $(TESTS)/tests.c
	$(CC) $(CFLAGS) -I$(INCLUDE) $(SRC)/array_utils.c $(TESTS)/tests.c -o tests/tests
clean:
	rm -f tests/tests
