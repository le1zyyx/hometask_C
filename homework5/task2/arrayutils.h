#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H
#include <stddef.h>

void fill_rand_array(int *arr, int N);
void print_array(int *arr, int N);
int sum_main_diag(int *arr, int N);
int sum_secondary_diag(int *arr, int N);

#endif
