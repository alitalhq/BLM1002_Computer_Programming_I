// GitHub: https://github.com/alitalhq

/*
 * Write a C program that, using pointers, prints the elements of an array such that:
 * Elements at even indices are printed from end to start.
 * Elements at odd indices are printed from start to end.
 */

#include <stdio.h>
#include <string.h>

#define SIZE 6

void printer(char *word, void (*printFunc)(char *word));
void printEven(char *word);
void printOdd(char *word);

int main(void) {
    char *words[] = {"apple", "pear", "cherry", "watermelon", "banana", "orange"};

    for(int i = 0; i < SIZE; i++) {
        if(i % 2 == 0) {
            printf("Element at index %d: ", i);
            printer(words[i], printEven);
        } else {
            printf("Element at index %d: ", i);
            printer(words[i], printOdd);
        }
    }

    return 0;
}

void printer(char *word, void (*printFunc)(char *word)) {
    printFunc(word);
}

void printEven(char *word) {
    for(int i = strlen(word) - 1; i >= 0; i--) {
        printf("%c", word[i]);
    }
    printf("\n");
}

void printOdd(char *word) {
    for(int i = 0; i < strlen(word); i++) {
        printf("%c", word[i]);
    }
    printf("\n");
}
