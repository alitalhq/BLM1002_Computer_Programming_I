// GitHub: https://github.com/alitalhq

/*
 * Write a C program that checks whether a string entered by the user is a palindrome.
 * Example:
 * Input: MOM
 * Output: MOM is a palindrome.
 */

#include <stdio.h>
#include <string.h>

int isPalindrome(char *word);

int main(void) {
    char word[100];

    printf("Enter a word: ");
    scanf("%s", word);

    int result = isPalindrome(word);
    if (result == 1) {
        printf("%s is a palindrome.\n", word);
    } else {
        printf("%s is not a palindrome.\n", word);
    }

    return 0;
}

int isPalindrome(char *word) {
    int left = 0;
    int right = strlen(word) - 1;

    while (left < right) {
        if (word[left] != word[right]) {
            return 0;
        }
        left++;
        right--;
    }

    return 1;
}