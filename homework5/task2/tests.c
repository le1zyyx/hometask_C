#include "arrayutils.h"
#include <stdio.h>

void test_manual_main_diag() {
    int arr[3][3] = {
        {2, 0, 7},
        {1, 5, 6},
        {8, 9, 3}
    };
    int main_d = sum_main_diag((int *)arr, 3); 
    printf("%s\n", (main_d == 10) ? "PASS" : "FAIL");
}

void test_manual_secondary_diag() {
    int arr[3][3] = {
        {4, 0, 7},
        {1, 5, 6},
        {9, 2, 3}
    };
    int sec_d = sum_secondary_diag((int *)arr, 3);
    printf("%s\n", (sec_d == 21) ? "PASS" : "FAIL");
}

void test_zero_diag() {
    int arr[2][2] = {
        {0,0},
        {0,0}
    };
    int main_d = sum_main_diag((int *)arr, 2);
    int sec_d = sum_secondary_diag((int *)arr, 2);
    printf("%s\n", (main_d == 0 && sec_d == 0) ? "PASS" : "FAIL");
}

void test_print_array() {
    int arr[2][2] = {{9, 8}, {7, 6}};
    printf("Print array:\n");
    print_array((int *)arr, 2); 
}

void test_random_fill() {
    int arr[2][2];
    fill_rand_array((int *)arr, 2);
    int valid = 1;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if (arr[i][j]<0 || arr[i][j]>10) valid=0;
    printf("%s\n", valid ? "PASS" : "FAIL");
}

int main() {
    test_manual_main_diag();
    test_manual_secondary_diag();
    test_zero_diag();
    test_print_array();
    test_random_fill();
    return 0;
}
