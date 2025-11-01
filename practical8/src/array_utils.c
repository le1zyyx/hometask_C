#include "array_utils.h"
#include <stdlib.h>
#include <stdio.h>

void** allocate_2d_array(int size) {
    void** arr = (void**)malloc(size * sizeof(void*));
    if (arr == NULL) return NULL;
    
    for (int i = 0; i < size; i++) {
        arr[i] = (void*)malloc(size * sizeof(int));
        if (arr[i] == NULL) {
            for (int j = 0; j < i; j++) free(arr[j]);
            free(arr);
            return NULL;
        }
    }
    return arr;
}

void fill_2d_array(void** arr, int size) {
    for (int i = 0; i < size; i++) {
        int* row = (int*)arr[i];
        for (int j = 0; j < size; j++) {
            row[j] = rand() % 100;
        }
    }
}

void print_2d_array(const void** arr, int size) {
    for (int i = 0; i < size; i++) {
        int* row = (int*)arr[i];
        for (int j = 0; j < size; j++) {
            printf("%d ", row[j]);
        }
        printf("\n");
    }
}

void sort_2d_array(void** arr, int size) {
    for (int i = 0; i < size; i++) {
        int* row = (int*)arr[i];
        for (int a = 0; a < size - 1; a++) {
            for (int b = 0; b < size - a - 1; b++) {
                if (row[b] > row[b + 1]) {
                    int temp = row[b];
                    row[b] = row[b + 1];
                    row[b + 1] = temp;
                }
            }
        }
    }
}

void free_2d_array(void** arr, int size) {
    if (arr == NULL) return;
    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);
}

int binary_search(const int arr[], int size, int target) {
    if (arr == NULL || size <= 0) return -1;
    
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int fill_2d_array_from_file(void** arr, int size, const char *filename) {
    if (arr == NULL || filename == NULL || size <= 0) return -1;
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) return -1;
    
    for (int i = 0; i < size; i++) {
        int* row = (int*)arr[i];
        for (int j = 0; j < size; j++) {
            if (fscanf(file, "%d", &row[j]) != 1) {
                fclose(file);
                return -1;
            }
        }
    }
    fclose(file);
    printf("Array filled from file %s\n", filename);
    return 0;
}
