CC = gcc
CFLAGS = -Wall -Wextra -std=c99

TASK1_TARGET = task1_run
TASK1_SRC = task1/main.c task1/listutils.c

TASK2_TARGET = task2_run
TASK2_SRC = task2/main.c task2/arrayutils.c

TEST1_TARGET = test1_runner
TEST1_SRC = task1/tests.c task1/listutils.c

TEST2_TARGET = test2_runner
TEST2_SRC = task2/tests.c task2/arrayutils.c

all: $(TASK1_TARGET) $(TASK2_TARGET) $(TEST1_TARGET) $(TEST2_TARGET)

$(TASK1_TARGET): $(TASK1_SRC)
	$(CC) $(CFLAGS) -o $(TASK1_TARGET) $(TASK1_SRC)

$(TASK2_TARGET): $(TASK2_SRC)
	$(CC) $(CFLAGS) -o $(TASK2_TARGET) $(TASK2_SRC)

$(TEST1_TARGET): $(TEST1_SRC)
	$(CC) $(CFLAGS) -o $(TEST1_TARGET) $(TEST1_SRC)

$(TEST2_TARGET): $(TEST2_SRC)
	$(CC) $(CFLAGS) -o $(TEST2_TARGET) $(TEST2_SRC)

run1:
	./$(TASK1_TARGET)

run2:
	./$(TASK2_TARGET)

test1:
	./$(TEST1_TARGET)

test2:
	./$(TEST2_TARGET)

clean:
	rm -f $(TASK1_TARGET) $(TASK2_TARGET) $(TEST1_TARGET) $(TEST2_TARGET)
