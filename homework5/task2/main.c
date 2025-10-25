#include "arrayutils.h"
#include <stdio.h>

int main() {
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    int arr[N][N];

    fill_rand_array((int *)arr, N);
    printf("Generated array:\n");
    print_array((int *)arr, N);

    int main_sum = sum_main_diag((int *)arr, N);
    int sec_sum = sum_secondary_diag((int *)arr, N);

    printf("Sum of main diagonal: %d\n", main_sum);
    printf("Sum of secondary diagonal: %d\n", sec_sum);

    return 0;
}
