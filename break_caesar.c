#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[1000];
    printf("Enter encrypted string: ");
    scanf("%999s", text);

    int best_key = 0;
    int max_count = 0;
    int len = strlen(text);

    for (int key = 0; key < 26; key++) {
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (isalpha(text[i])) {
                char decrypted = ((tolower(text[i]) - 'a' - key + 26) % 26) + 'a';
                if (decrypted == 'e') count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            best_key = key;
        }
    }

    printf("Encryption key: %d\n", best_key);

    printf("Decrypted text: ");
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            char decrypted = ((tolower(text[i]) - 'a' - best_key + 26) % 26) + 'a';
            printf("%c", decrypted);
        } else {
            printf("%c", text[i]);
        }
    }
    printf("\n");

    return 0;
}
