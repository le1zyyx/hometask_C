#include <stdio.h>
#include <string.h>
#include <ctype.h>

int areAnagrams(char str1[], char str2[]) {
    int count[256] = {0};
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (len1 != len2) {
        return 0;
    }
    
    for (int i = 0; i < len1; i++) {
        count[tolower(str1[i])]++;
        count[tolower(str2[i])]--;
    }
    
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    char str1[100], str2[100];
    
    printf("Введіть перший рядок: ");
    scanf("%s", str1);
    
    printf("Введіть другий рядок: ");
    scanf("%s", str2);
    
    if (areAnagrams(str1, str2)) {
        printf("Рядки є анаграмами.\n");
    } else {
        printf("Рядки не є анаграмами.\n");
    }
    
    return 0;
}

//Часова складність: O(n)
//Просторова складність: O(1)
