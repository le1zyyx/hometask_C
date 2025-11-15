CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: demo_run test_task1 test_task2

demo_run: demo/demo_listutils.c src/listutils.c
	$(CC) $(CFLAGS) -Iinclude -o demo_run demo/demo_listutils.c src/listutils.c

test_task1: tests/test_task1.c src/listutils.c
	$(CC) $(CFLAGS) -Iinclude -o test_task1 tests/test_task1.c src/listutils.c

test_task2: tests/test_task2.c src/listutils.c
	$(CC) $(CFLAGS) -Iinclude -o test_task2 tests/test_task2.c src/listutils.c

run: all
	./test_task1
	./test_task2
	./demo_run

clean:
	rm -f demo_run test_task1 test_task2 test.txt list.txt

.PHONY: all run clean
