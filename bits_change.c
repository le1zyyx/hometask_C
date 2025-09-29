#include <stdio.h>

int main() {
    int x, y;
    
    printf("Enter X: ");
    scanf("%d", &x);
    printf("Enter Y: ");
    scanf("%d", &y);
    
    int different_bits = x ^ y;
    int count = 0;
    
    while (different_bits > 0) {
        count += different_bits & 1;
        different_bits >>= 1;
    }
    
    printf("Number of bits to change: %d\n", count);
    return 0;
}
