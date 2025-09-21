// GitHub: https://github.com/alitalhq

/*
 * A struct is desired to store information for 10 students,
 * including: student ID, answers to a 20-question test, and result information.
 * The answers will be stored in a 10x20 integer array within the struct.
 * (Value 1 represents option a, 2 represents b, 3 represents c, 4 represents d, and 0 represents an unanswered question.)
 * Student IDs will be automatically assigned starting from 1000 and incremented by 1.
 * Create an answer key yourself (20 questions with values from 1 to 5).
 * Write a program that saves each student's ID, number of correct answers, number of wrong answers, and number of unanswered questions to a file.
 * The answers in the struct array will be compared with the answer key (a 1x20 array), and for each student,
 * the number of correct, wrong, and unanswered answers will be stored in a 10x3 results array, which should also be saved to a file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STUDENT_COUNT 10
#define QUESTION_COUNT 20

typedef struct {
    int id;
    int answers[QUESTION_COUNT];
    int results[3]; //0, 1, 2 -> correct, wrong, blank
} Student;

int main(void) {
    Student students[STUDENT_COUNT];
    int answer_key[QUESTION_COUNT];
    FILE *file;

    srand((unsigned)time(NULL));

    for (int i = 0; i < STUDENT_COUNT; i++) {
        students[i].id = 1000 + i;

        for (int j = 0; j < QUESTION_COUNT; j++) {
            students[i].answers[j] = rand() % 5;
        }
    }

    printf("Please enter the answer key for %d questions (1-4):\n", QUESTION_COUNT);
    for (int i = 0; i < QUESTION_COUNT; i++) {
        do {
            printf("Question %d: ", i + 1);
            scanf("%d", &answer_key[i]);
        } while (answer_key[i] < 1 || answer_key[i] > 4);
    }

    for (int i = 0; i < STUDENT_COUNT; i++) {
        int correct = 0, wrong = 0, blank = 0;

        for (int j = 0; j < QUESTION_COUNT; j++) {
            int answer = students[i].answers[j];
            if (answer == 0)
                blank++;
            else if (answer == answer_key[j])
                correct++;
            else
                wrong++;
        }

        students[i].results[0] = correct;
        students[i].results[1] = wrong;
        students[i].results[2] = blank;
    }

    file = fopen("results.txt", "w");

    fprintf(file, "Student ID\tCorrect\tWrong\tBlank\n");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        fprintf(file, "%d\t\t%d\t%d\t%d\n",
                students[i].id,
                students[i].results[0],
                students[i].results[1],
                students[i].results[2]);
    }

    fclose(file);

    printf("\nStudent Answers and Results:\n");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Student %d: ", students[i].id);
        for (int j = 0; j < QUESTION_COUNT; j++) {
            printf("%d ", students[i].answers[j]);
        }
        printf("| Correct: %d, Wrong: %d, Blank: %d\n",
               students[i].results[0],
               students[i].results[1],
               students[i].results[2]);
    }

    return 0;
}
