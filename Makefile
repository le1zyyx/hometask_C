CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

TASK1_TARGET = task1
TASK1_SRC = src/bisection.c main.c

TASK2_TARGET = task2
TASK2_SRC = src/array_utils.c task2_main.c

all: $(TASK1_TARGET) $(TASK2_TARGET)

$(TASK1_TARGET): $(TASK1_SRC)
	$(CC) $(CFLAGS) -o $(TASK1_TARGET) $(TASK1_SRC) -lm

$(TASK2_TARGET): $(TASK2_SRC)
	$(CC) $(CFLAGS) -o $(TASK2_TARGET) $(TASK2_SRC)

test1:
	$(CC) $(CFLAGS) -o test1_runner src/bisection.c tests/test_bisection.c -lm
	./test1_runner

test2:
	$(CC) $(CFLAGS) -o test2_runner tests/test_array_utils.c src/array_utils.c -lm
	./test2_runner

test: test1 test2

test3:
	$(CC) $(CFLAGS) -o test3_runner tests/test_task3_checksum.c src/array_utils.c
	./test3_runner


clean:
	rm -f $(TASK1_TARGET) $(TASK2_TARGET) test1_runner test2_runner

.PHONY: all test test1 test2 clean