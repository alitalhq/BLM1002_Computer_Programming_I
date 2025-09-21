// GitHub: https://github.com/alitalhq

/*
 * Write a program that takes student information (name, ID number, and grade) from the user and saves it to a file named students.txt
 * Then, create a second function that reads this file and prints the students whose grades are 50 or higher.
 * (Student information should be stored in a struct.)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int id;
    int grade;
} Student;

void printPassingStudents() {
    FILE *file = fopen("students.txt", "r");
    Student student;

    while (fscanf(file, "%s %d %d", student.name, &student.id, &student.grade) != EOF) {
        if (student.grade >= 50) {
            printf("Name: %s, ID: %d, Grade: %d\n", student.name, student.id, student.grade);
        }
    }

    fclose(file);
}

int main() {
    FILE *file = fopen("students.txt", "w");
    int student_count;

    printf("How many students will you enter? ");
    scanf("%d", &student_count);

    Student *students = (Student *)malloc(student_count * sizeof(Student));

    for (int i = 0; i < student_count; i++) {
        Student *ptr = &students[i];

        printf("\nEnter the name of student %d: ", i + 1);
        scanf("%s", ptr->name);

        printf("Enter the ID number: ");
        scanf("%d", &ptr->id);

        printf("Enter the grade: ");
        scanf("%d", &ptr->grade);

        fprintf(file, "%s %d %d\n", ptr->name, ptr->id, ptr->grade);
    }

    fclose(file);
    free(students);

    printf("\nStudents with grade 50 or above:\n");
    printPassingStudents();

    return 0;
}
