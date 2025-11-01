CC = gcc
CXX = clang++
CFLAGS = -Wall -Wextra -std=c99
CXXFLAGS = -Wall -Wextra -std=c++17

GTEST_DIR = /opt/homebrew/Cellar/googletest/1.17.0/include
GTEST_LIB = /opt/homebrew/Cellar/googletest/1.17.0/lib

OBJS = src/array_utils.o

all: test_runner

src/array_utils.o: src/array_utils.c include/array_utils.h
	$(CC) $(CFLAGS) -I./include -c src/array_utils.c -o src/array_utils.o

test_runner: $(OBJS) tests/fill_array_tests.cpp tests/sort_array_tests.cpp tests/binary_search_tests.cpp
	$(CXX) $(CXXFLAGS) -I./include -I$(GTEST_DIR) $(OBJS) tests/fill_array_tests.cpp tests/sort_array_tests.cpp tests/binary_search_tests.cpp -o test_runner -L$(GTEST_LIB) -lgtest -lgtest_main -lpthread

run: test_runner
	./test_runner

clean:
	rm -f test_runner src/array_utils.o

.PHONY: all run clean
