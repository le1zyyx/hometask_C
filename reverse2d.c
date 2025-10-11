#include <stdio.h>

void reverse2D(int *arr, int N) {
    int *start = arr;
    int *end = arr + N * N - 1;
    while (start < end) {
        int tmp = *start;
        *start = *end;
        *end = tmp;
        ++start;
        --end;
    }
}

void print2D(int *arr, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            printf("%d ", *(arr + i*N + j));
        printf("\n");
    }
}

int main(void) {
    int N = 3;
    int matrix[9] = {1,2,3, 4,5,6, 7,8,9};

    printf("To reverse\n");
    print2D(matrix, N);

    reverse2D(matrix, N);

    printf("\nAfter reverse:\n");
    print2D(matrix, N);

    return 0;
}
