CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: task1_run task1_test task2_test

task1_run: demo/demo_listutils.c src/listutils.c
	$(CC) $(CFLAGS) -Iinclude -o task1_run demo/demo_listutils.c src/listutils.c

task1_test: tests/test_task1.c src/listutils.c
	$(CC) $(CFLAGS) -Iinclude -o task1_test tests/test_task1.c src/listutils.c

task2_test: tests/test_task2.c src/custom_getline.c
	$(CC) $(CFLAGS) -Iinclude -o task2_test tests/test_task2.c src/custom_getline.c

clean:
	rm -f task1_run task1_test task2_test

.PHONY: all clean
