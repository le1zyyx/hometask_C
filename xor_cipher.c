#include <stdio.h>

void print_binary(unsigned int n);

int main(void) {
    unsigned int value, key;

    printf("Enter a value: ");
    scanf("%u", &value);
    
    printf("Enter a key (number for XOR): ");
    scanf("%u", &key);
    if (key == 0) { printf("Key cannot be 0\n"); return 1; }
    unsigned int encrypted = value ^ key;
    unsigned int decrypted = encrypted ^ key;
    printf("\nOriginal value: %u\nBinary: ", value); print_binary(value);
    printf("Encrypted value: %u\nBinary: ", encrypted); print_binary(encrypted);
    printf("Decrypted value: %u\nBinary: ", decrypted); print_binary(decrypted);
    return 0;
}

void print_binary(unsigned int n) {
    for (int i = 31; i >= 0; i--) printf("%d", (n >> i) & 1);
    printf("\n");
}
