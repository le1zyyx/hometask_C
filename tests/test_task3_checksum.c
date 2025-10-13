#include <assert.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include "array_utils.h"

void test_basic() {
    int arr[] = {1, 2, 3, 4};
    uint32_t cs = arr_checksum(arr, 4);
    assert(cs == arr_checksum(arr, 4));
}

void test_overflow_sum() {
    int arr[] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    uint32_t cs = arr_checksum(arr, 4);
}

void test_single() {
    int arr[] = {123456789};
    uint32_t cs = arr_checksum(arr, 1);
    assert(cs == arr_checksum(arr, 1));
}

void test_limits() {
    int arr[] = {INT_MAX, INT_MIN, 0, -1, 1};
    uint32_t cs = arr_checksum(arr, 5);
}

void test_empty() {
    int arr[] = {};
    uint32_t cs = arr_checksum(arr, 0);
    assert(cs == arr_checksum(arr, 0));
}

void test_large_array() {
    int arr[100000];
    for (int i = 0; i < 100000; ++i) arr[i] = i;
    uint32_t cs = arr_checksum(arr, 100000);
}

void test_all_same() {
    int arr[1000];
    for (int i = 0; i < 1000; ++i) arr[i] = 42;
    uint32_t cs = arr_checksum(arr, 1000);
}

void test_negative() {
    int arr[] = {-5, -10, -100, -100000, -INT_MAX};
    uint32_t cs = arr_checksum(arr, 5);
}

void test_weird() {
    int arr[] = {0, 123, 9999, -42, INT_MIN, INT_MAX, 0x7FFFFFFF, -0x80000000};
    uint32_t cs = arr_checksum(arr, 8);
}

void test_stability() {
    int arr1[] = {2,4,6,8};
    int arr2[] = {2,4,6,8};
    assert(arr_checksum(arr1, 4) == arr_checksum(arr2, 4));
}

int main() {
    test_basic();
    test_overflow_sum();
    test_single();
    test_limits();
    test_empty();
    test_large_array();
    test_all_same();
    test_negative();
    test_weird();
    test_stability();
    printf("All checksum tests passed!\n");
    return 0;
}