#include <stdio.h>
#include <ctype.h>

int main() {
    int n, key;
    printf("Enter the number of characters to encrypt: ");
    scanf("%d", &n);
    printf("Enter encryption key [-128, 127]: ");
    scanf("%d", &key);

    for (int i = 0; i < n;) {
        char c;
        printf("Enter character %d: ", i + 1);
        scanf(" %c", &c);

        if (!isalpha(c)) {
            printf("Invalid input: must be a valid alphabetic character\n");
            continue;
        }
        char base = islower(c) ? 'a' : 'A';
        char encrypted = ((tolower(c) - 'a' + key) % 26 + 26) % 26 + base;
        printf("Encrypted character: %c\n", encrypted);
        i++;
    }
    return 0;
}
