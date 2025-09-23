#include <stdio.h>

int main() {
    int num;
    printf("Enter permission: ");
    scanf("%d", &num);
    int digits[3] = { num/100, (num/10)%10, num%10 };
    if (digits[0]>7||digits[1]>7||digits[2]>7||num<0) {
        printf("Error: Invalid input\n");
        return 1;
    }
    printf("Permissions: ");
    for(int i=0;i<3;i++){
        printf("%c", digits[i]&4 ? 'r' : '-');
        printf("%c", digits[i]&2 ? 'w' : '-');
        printf("%c", digits[i]&1 ? 'x' : '-');
    }
    printf("\n");
    return 0;
}
