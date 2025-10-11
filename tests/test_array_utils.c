#include <assert.h>
#include "array_utils.h"
#include <stdio.h>

int main() {
    int A[3][100] = {
        {0, 1, 2},
        {10, 11, 12},
        {20, 21, 22}
    };
    int R[3][100];
    rotate_90(3, A, R);
    assert(R[0][0] == 20 && R[0][1] == 10 && R[0][2] == 0);
    assert(R[1][0] == 21 && R[1][1] == 11 && R[1][2] == 1);
    assert(R[2][0] == 22 && R[2][1] == 12 && R[2][2] == 2);
    printf("tests passed\n");
    return 0;
}
