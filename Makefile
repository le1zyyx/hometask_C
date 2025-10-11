CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17
GTEST_INC := -I/opt/homebrew/Cellar/googletest/1.17.0/include
GTEST_LIB := -L/opt/homebrew/Cellar/googletest/1.17.0/lib -lgtest_main -lgtest -pthread

all: gtest-demo

demo.o: demo.cpp
	$(CXX) $(CXXFLAGS) $(GTEST_INC) -c demo.cpp -o demo.o

gtest-demo: demo.o
	$(CXX) demo.o -o gtest-demo $(GTEST_LIB)

reverse2d: reverse2d.c
	$(CC) $(CFLAGS) reverse2d.c -o reverse2d

clean:
	rm -f demo.o gtest-demo
