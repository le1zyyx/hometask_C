#include <stdio.h>

void print_binary(unsigned int n);

int main(void) {
    unsigned int value, key;

    printf("Enter a value: ");
    scanf("%u", &value);

    printf("Enter a key (number for XOR): ");
    scanf("%u", &key);

    unsigned int encrypted = value ^ key;
    unsigned int decrypted = encrypted ^ key;

    printf("\nOriginal value (Decimal): %u\nBinary: ", value);
    print_binary(value);

    printf("Encrypted value (Decimal): %u\nBinary: ", encrypted);
    print_binary(encrypted);

    printf("Decrypted value (Original): %u\nBinary: ", decrypted);
    print_binary(decrypted);

    return 0;
}

void print_binary(unsigned int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}
