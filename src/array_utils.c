#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"

void fill_random(int N, int array[][100]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            array[i][j] = rand() % 100;
}

void rotate_90(int N, int array[][100], int rotated[][100]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            rotated[j][N - 1 - i] = array[i][j];
}

void print_array(int N, int array[][100]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }
}

uint32_t arr_checksum(const int *arr, size_t n) {
    uint64_t sum = 0;
    for (size_t i = 0; i < n; ++i) {
        sum += (uint64_t)(uint32_t)arr[i];
    }
    return (uint32_t)sum;
}