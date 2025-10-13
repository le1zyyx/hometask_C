#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H
#include <stddef.h>
#include <stdint.h>


void fill_random(int N, int array[][100]);
void rotate_90(int N, int array[][100], int rotated[][100]);
void print_array(int N, int array[][100]);
uint32_t arr_checksum(const int *arr, size_t n);

#endif