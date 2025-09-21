// GitHub: https://github.com/alitalhq

/*
 * Write a C program that takes a text input from the user and saves it to a file named text.txt
 * Then, read all the characters from this file, reverse them, and write them to another file named reversed.txt
 * 
 * Requirements:
 * The user can input multiple lines of text.
 * Save the input to text.txt
 * Read the contents of text.txt, reverse all characters (both letter order and line order), and write the result to reversed.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 20
#define MAX_LENGTH 1024

int main(void) {
    FILE *file;
    char *lines[MAX_LINES];
    char temp[MAX_LENGTH];
    int line_count = 0;

    printf("Enter text (press empty line to finish):\n");

    while (fgets(temp, MAX_LENGTH, stdin) != NULL) {
        if (strcmp(temp, "\n") == 0) break;

        lines[line_count] = malloc(strlen(temp) + 1);
        strcpy(lines[line_count], temp);
        line_count++;
    }

    file = fopen("text.txt", "w");
    for (int i = 0; i < line_count; i++) {
        fputs(lines[i], file);
    }
    fclose(file);

    file = fopen("reversed.txt", "w");
    for (int i = line_count - 1; i >= 0; i--) {
        int length = strlen(lines[i]);
        if (lines[i][length - 1] == '\n') length--;
        for (int j = length - 1; j >= 0; j--) {
            fputc(lines[i][j], file);
        }
        fputc('\n', file);
        free(lines[i]);
    }
    fclose(file);

    return 0;
}
