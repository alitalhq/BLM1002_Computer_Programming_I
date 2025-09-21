// GitHub: https://github.com/alitalhq

/*
 * Write a C program that prints all permutations of a string entered by the user using pointers.
 * Example:
 * Input: dog
 * Output: dog dgo odg ogd god gdo
 */

#include <stdio.h>
#include <string.h>

void permutation(char *word, int start, int end);

int main(void) {
    char word[100];

    printf("Please enter a short word: ");
    scanf("%s", word);

    int length = strlen(word);
    permutation(word, 0, length - 1);

    return 0;
}

void permutation(char *word, int start, int end) {
    
    if (start == end) {
        printf("%s ", word);
    } else {
        for (int i = start; i <= end; i++) {
            char temp = word[start];
            word[start] = word[i];
            word[i] = temp;

            permutation(word, start + 1, end);

            temp = word[start];
            word[start] = word[i];
            word[i] = temp;
        }
    }
}
