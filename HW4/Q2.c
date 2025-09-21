// GitHub: https://github.com/alitalhq

/*
 * Create a program for a class of 25 students that assigns random names (using pointers).
 * The program should divide the students into random groups of three and list these groups.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STUDENT_COUNT 25
#define GROUP_SIZE 3

void shuffle(char **students, int n);

int main(void) {
    srand((unsigned)time(NULL));

    char *students[STUDENT_COUNT] = {
        "name1", "name2", "name3", "name4", "name5",
        "name6", "name7", "name8", "name9", "name10",
        "name11", "name12", "name13", "name14", "name15",
        "name16", "name17", "name18", "name19", "name20",
        "name21", "name22", "name23", "name24", "name25"
    };

    shuffle(students, STUDENT_COUNT);

    printf("Groups:\n");
    for (int i = 0; i < STUDENT_COUNT / GROUP_SIZE; i++) {
        printf("Group %d: ", i + 1);
        for (int j = 0; j < GROUP_SIZE; j++) {
            printf("%s ", students[i * GROUP_SIZE + j]);
        }
        printf("\n");
    }
    
    int remaining_students = STUDENT_COUNT % GROUP_SIZE;
    if (remaining_students > 0) {
        printf("Group %d: ", STUDENT_COUNT / GROUP_SIZE + 1);
        for (int i = STUDENT_COUNT - remaining_students; i < STUDENT_COUNT; i++) {
            printf("%s ", students[i]);
        }
        printf("\n");
    }

    return 0;
}

void shuffle(char **students, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        char *temp = students[i];
        students[i] = students[j];
        students[j] = temp;
    }
}
