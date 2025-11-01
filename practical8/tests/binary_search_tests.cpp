extern "C" {
#include "array_utils.h"
}

#include <gtest/gtest.h>

TEST(BinarySearchTest, EmptyArray) {
    EXPECT_EQ(-1, binary_search(nullptr, 0, 5));
}

TEST(BinarySearchTest, OneElement) {
    const int arr[] = {42};
    int n = 1;
    EXPECT_EQ(0, binary_search(arr, n, 42));
    EXPECT_EQ(-1, binary_search(arr, n, 43));
}

TEST(BinarySearchTest, TwoElements) {
    const int arr[] = {10, 20};
    int n = 2;
    EXPECT_EQ(0, binary_search(arr, n, 10));
    EXPECT_EQ(1, binary_search(arr, n, 20));
    EXPECT_EQ(-1, binary_search(arr, n, 15));
}

TEST(BinarySearchTest, ThreeElements) {
    const int arr[] = {5, 15, 25};
    int n = 3;
    EXPECT_EQ(0, binary_search(arr, n, 5));
    EXPECT_EQ(1, binary_search(arr, n, 15));
    EXPECT_EQ(2, binary_search(arr, n, 25));
    EXPECT_EQ(-1, binary_search(arr, n, 10));
}

TEST(BinarySearchTest, EvenNumberOfElements) {
    const int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = 7;
    for (int i = 0; i < n; ++i) {
        EXPECT_EQ(i, binary_search(arr, n, arr[i]));
    }
}

TEST(BinarySearchTest, ElementNotFound) {
    const int arr[] = {1, 3, 5, 7, 9};
    int n = 5;
    EXPECT_EQ(-1, binary_search(arr, n, 2));
    EXPECT_EQ(-1, binary_search(arr, n, 4));
}
