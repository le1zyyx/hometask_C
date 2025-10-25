#include "arrayutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

void fill_rand_array(int *arr, int N) {
    srand(time(NULL));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            *(arr + i*N + j) = rand() % 11;
}

void print_array(int *arr, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            printf("%d ", *(arr + i*N + j));
        printf("\n");
    }
}

int sum_main_diag(int *arr, int N) {
    int sum = 0;
    for (int i = 0; i < N; ++i)
        sum += *(arr + i*N + i);
    return sum;
}

int sum_secondary_diag(int *arr, int N) {
    int sum = 0;
    for (int i = 0; i < N; ++i)
        sum += *(arr + i*N + (N - 1 - i));
    return sum;
}
