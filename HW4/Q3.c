// GitHub: https://github.com/alitalhq

/*
 * Dynamic Memory Two-Dimensional Array Multiplication:
 * A function should be written to work with two-dimensional arrays using dynamic memory.
 * This function will take two matrices (two-dimensional arrays) as parameters, perform their multiplication,
 * and assign the result to another dynamically allocated array. The function will return the resulting matrix.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **matrix_multiply(int **m1, int **m2, int rows1, int cols1, int cols2);
int **allocate_matrix(int rows, int cols);
void fill_matrix(int **matrix, int rows, int cols);
void print_matrix(int **matrix, int rows, int cols);
void free_matrix(int **matrix, int rows);

int main(void) {
    srand((unsigned)time(NULL));

    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("These matrices cannot be multiplied.\n");
        return 1;
    }

    int **m1 = allocate_matrix(rows1, cols1);
    int **m2 = allocate_matrix(rows2, cols2);

    fill_matrix(m1, rows1, cols1);
    fill_matrix(m2, rows2, cols2);

    printf("\nMatrix 1:\n");
    print_matrix(m1, rows1, cols1);

    printf("\nMatrix 2:\n");
    print_matrix(m2, rows2, cols2);

    int **result = matrix_multiply(m1, m2, rows1, cols1, cols2);

    printf("\nResult of Matrix Multiplication:\n");
    print_matrix(result, rows1, cols2);

    free_matrix(m1, rows1);
    free_matrix(m2, rows2);
    free_matrix(result, rows1);

    return 0;
}

int **matrix_multiply(int **m1, int **m2, int rows1, int cols1, int cols2) {
    int **result = allocate_matrix(rows1, cols2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return result;
}

int **allocate_matrix(int rows, int cols) {
    int **matrix = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    }
    return matrix;
}

void fill_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 21 - 10;
        }
    }
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
