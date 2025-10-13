#include <stdio.h>
#include "array_utils.h"

int main() {
    int arr[4] = {1, 4, 7, 3};
    int cs = arr_checksum(arr, 4);
    printf("Checksum: %d\n", cs);
    return 0;
}