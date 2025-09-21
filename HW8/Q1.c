// GitHub: https://github.com/alitalhq

/*
 * a) Write a function that creates a matrix with dimensions entered from the keyboard and randomly assigns elements with values between 5 and 75
 * Then, for each row, calculate the largest value, the second largest value (second max), and the indices of these values.
 * The randomly generated matrix and the calculated values will be saved to a random-access file.
 * 
 * b) Write a function that sorts a specified row in descending order.
 * Using the row number entered by the user, sort the corresponding row and write this sorted row to a sequential-access file.
 * 
 * c) Display the specified row on the screen.
 * 
 * Menu Options should be as follows:
 *     Create/Compute Matrix and Write to Random Access File
 *     Sort Row
 *     Display Row (Enter Row Number)
 *     Write Sorted Matrix to Sequential Access File
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **matrix = NULL;
int rows = 0, cols = 0;

void create_and_write_matrix(void);
void sort_row(void);
void display_row(void);
void write_sorted_matrix_to_file(void);

int main(void) {
    int choice;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Create/Compute Matrix and Write to Random Access File\n");
        printf("2. Sort Row\n");
        printf("3. Display Row (Enter Row Number)\n");
        printf("4. Write Sorted Matrix to Sequential File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_and_write_matrix();
                break;
            case 2:
                sort_row();
                break;
            case 3:
                display_row();
                break;
            case 4:
                write_sorted_matrix_to_file();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void create_and_write_matrix(void) {
    FILE *file = fopen("matrix.txt", "w");

    printf("Number of rows: ");
    scanf("%d", &rows);
    printf("Number of columns: ");
    scanf("%d", &cols);

    srand((unsigned)time(NULL));

    matrix = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        matrix[i] = malloc(cols * sizeof(int));

    for (int i = 0; i < rows; i++) {
        int max = -1, second = -1;
        int ind1 = -1, ind2 = -1;

        fprintf(file, "Row %d: ", i);
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 71 + 5;
            printf("%3d ", matrix[i][j]);
            fprintf(file, "%d ", matrix[i][j]);

            if (matrix[i][j] > max) {
                second = max;
                ind2 = ind1;
                max = matrix[i][j];
                ind1 = j;
            } else if (matrix[i][j] > second) {
                second = matrix[i][j];
                ind2 = j;
            }
        }
        printf("| Max: %d (i:%d), 2nd Max: %d (i:%d)\n", max, ind1, second, ind2);
        fprintf(file, "| Max: %d (i:%d), 2nd Max: %d (i:%d)\n", max, ind1, second, ind2);
    }

    fclose(file);
    printf("Matrix and details have been written to matrix.txt.\n");
}

void sort_row(void) {
    int r;
    printf("Enter row number to sort (0-%d): ", rows - 1);
    scanf("%d", &r);
    if (r < 0 || r >= rows) {
        printf("Invalid row.\n");
        return;
    }

    int *temp = malloc(cols * sizeof(int));
    for (int i = 0; i < cols; i++)
        temp[i] = matrix[r][i];

    for (int i = 0; i < cols - 1; i++) {
        for (int j = 0; j < cols - i - 1; j++) {
            if (temp[j] < temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    printf("Row %d sorted: ", r);
    for (int i = 0; i < cols; i++)
        printf("%d ", temp[i]);
    printf("\n");

    FILE *file = fopen("sorted.txt", "w");
    fprintf(file, "Row %d sorted:\n", r);
    for (int i = 0; i < cols; i++)
        fprintf(file, "%d ", temp[i]);
    fprintf(file, "\n");
    fclose(file);
    printf("Sorted row has been written to sorted.txt.\n");

    free(temp);
}

void display_row(void) {
    int r;
    printf("Enter row number to display (0-%d): ", rows - 1);
    scanf("%d", &r);
    if (r < 0 || r >= rows) {
        printf("Invalid row.\n");
        return;
    }

    printf("Row %d: ", r);
    for (int i = 0; i < cols; i++)
        printf("%d ", matrix[r][i]);
    printf("\n");
}

void write_sorted_matrix_to_file(void) {
    FILE *file = fopen("sorted.txt", "a");

    fprintf(file, "\n--- Entire Matrix ---\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            fprintf(file, "%d ", matrix[i][j]);
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Entire matrix has been appended to sorted.txt.\n");
}
