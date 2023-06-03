#include <stdio.h>
#define ROWS 10
#define COLS 10

int isSymmetric(int matrix[ROWS][COLS], int rows, int cols) {
    if (rows != cols) {
        return 0;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }

    return 1;
}
void printMatrix(int matrix[ROWS][COLS], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS];
    int rows, cols;

    printf("Enter the number of rows  ");
    scanf("%d", &rows);
    printf("Enter the number of columns ");
    scanf("%d", &cols);

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printMatrix(matrix, rows, cols);

    if (isSymmetric(matrix, rows, cols)) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is non-symmetric.\n");
    }

    return 0;
}
