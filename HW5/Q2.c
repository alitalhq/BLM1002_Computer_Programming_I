// GitHub: https://github.com/alitalhq

/*
 * Develop a C program that stores n words entered by the user using dynamic memory allocation (malloc)
 * and sorts them using the Bubble Sort algorithm.
 * The sorting should be able to be done in alphabetical or reverse alphabetical order,
 * and the user should select the sorting type.
 * Use function pointers to make the sorting process flexible.
 * Use strcmp() for alphabetical sorting, define a different function for reverse sorting,
 * and free the allocated memory at the end of the program.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascendingSort(const char *, const char *);
int descendingSort(const char *, const char *);
void sortWords(char **list, int count, int (*compare)(const char *, const char *));

int main(void) {

    int count, choice;

    printf("How many words do you want to enter: ");
    scanf("%d", &count);
    getchar();

    char **list = (char **)malloc(count * sizeof(char *));

    for (int i = 0; i < count; i++) {
        char temp[50];
        printf("Enter word %d: ", i + 1);
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = '\0';
        list[i] = (char *)malloc((strlen(temp) + 1) * sizeof(char));
        strcpy(list[i], temp);
    }

    printf("\nSelect sorting type:\n");
    printf("1 - Alphabetical (A to Z)\n");
    printf("2 - Reverse Alphabetical (Z to A)\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    int (*sortFunc)(const char *, const char *) = NULL;
    if (choice == 1)
        sortFunc = ascendingSort;
    else if (choice == 2)
        sortFunc = descendingSort;
    else {
        printf("Invalid choice\n");
        return 1;
    }

    sortWords(list, count, sortFunc);

    printf("\nSorted words:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", list[i]);
    }

    for (int i = 0; i < count; i++) {
        free(list[i]);
    }
    free(list);

    return 0;
}

int ascendingSort(const char *a, const char *b) {
    return strcmp(a, b);
}

int descendingSort(const char *a, const char *b) {
    return strcmp(b, a);
}

void sortWords(char **list, int count, int (*compare)(const char *, const char *)) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            if (compare(list[j], list[j + 1]) > 0) {
                char *temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
