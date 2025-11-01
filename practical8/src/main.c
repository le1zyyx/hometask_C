#include "array_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    const int size = 3;
    void** arr = allocate_2d_array(size);
    
    if (arr == NULL) return 1;
    
    fill_2d_array(arr, size);
    printf("Random array:\n");
    print_2d_array((const void**)arr, size);
    
    sort_2d_array(arr, size);
    printf("\nSorted array:\n");
    print_2d_array((const void**)arr, size);
    
    free_2d_array(arr, size);
    return 0;
}
