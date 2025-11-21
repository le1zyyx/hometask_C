CC = gcc
CFLAGS = -Wall -Wextra -std=c99
CUNIT = $(shell pkg-config --cflags --libs cunit)

all: liblistutils.so demo_run test_task

liblistutils.so: src/listutils.c include/listutils.h
	$(CC) $(CFLAGS) -fPIC -shared -Iinclude -o liblistutils.so src/listutils.c

demo_run: demo/demo_listutils.c liblistutils.so
	$(CC) $(CFLAGS) -Iinclude -o demo_run demo/demo_listutils.c -L. -llistutils

test_task: tests/test_task.c liblistutils.so
	$(CC) $(CFLAGS) -Iinclude -o test_task tests/test_task.c -L. -llistutils $(CUNIT)

clean:
	rm -f demo_run test_task *.o *.so *.txt liblistutils.so

leaks_demo:
	leaks --atExit -- ./demo_run

leaks_test:
	leaks --atExit -- ./test_task

.PHONY: all clean leaks_demo leaks_test
