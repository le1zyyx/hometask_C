#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"

int main() {
    int N;
    printf("Enter array size N: ");
    scanf("%d", &N);

    int A[100][100];
    int R[100][100];

    fill_random(N, A);
    rotate_90(N, A, R);

    printf("Original array:\n");
    print_array(N, A);

    printf("Rotated array (90° clockwise):\n");
    print_array(N, R);

    return 0;
}

// Складність: O(N^2)