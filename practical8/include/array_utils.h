#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

void** allocate_2d_array(int size);
void fill_2d_array(void** arr, int size);
void print_2d_array(const void** arr, int size);
void sort_2d_array(void** arr, int size);
void free_2d_array(void** arr, int size);
int binary_search(const int arr[], int size, int target);
int fill_2d_array_from_file(void** arr, int size, const char *filename);

#endif
