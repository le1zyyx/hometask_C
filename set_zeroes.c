#include <stdio.h>

int main() {
    int matrix[100][100], zeroRow[100], zeroCol[100];
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &matrix[i][j]);

    for (int i = 0; i < n; i++) zeroRow[i] = 0;
    for (int j = 0; j < m; j++) zeroCol[j] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == 0) {
                zeroRow[i] = 1;
                zeroCol[j] = 1;
            }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (zeroRow[i] || zeroCol[j])
                matrix[i][j] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}


//Часова складність: O(m×n)
//Просторова складність: O(m+n)