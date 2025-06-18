#include <stdio.h>

int main() {
    int matrix1[3][2], matrix2[2][3], result[3][3];
    int i,j,k;

    printf("Enter elements of the first 3x2 matrix:\n");
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 2; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of the second 2x3 matrix:\n");
    for ( i = 0; i < 2; i++) {
        for ( j = 0; j < 3; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            result[i][j] = 0;
            for ( k = 0; k < 2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("\nResult of multiplication is:\n");
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
