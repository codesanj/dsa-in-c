#include <stdio.h>

void findNonZeroElements(int mat[][100], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (mat[i][j] != 0) {
                count++;
            }
        }
    }
    printf("Nonzero elements: %d\n", count);
}

void displayUpperTriangular(int mat[][100], int size) {
    printf("Upper triangular matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j >= i) {
                printf("%d ", mat[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void displayDiagonalElements(int mat[][100], int size) {
    printf("Elements above and below the main diagonal:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == i - 1 || j == i + 1) {
                printf("%d ", mat[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter size of the square matrix: ");
    scanf("%d", &size);
    
    int mat[100][100];
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    findNonZeroElements(mat, size);
    displayUpperTriangular(mat, size);
    displayDiagonalElements(mat, size);

    return 0;
}
