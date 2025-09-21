// GitHub: https://github.com/alitalhq

/*
 * Randomly select a word from 20 five-letter names and implement a Hangman game in C,
 * giving the player twice the length of the word as guess attempts.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char* words[20] = {
    "mehmet", "furkan", "ismail", "berkay", "egemen", "mahmut",
    "serdar", "tayfun", "toprak", "volkan", "ilayda", "melisa",
    "melike", "dilara", "aleyna", "meryem", "meltem", "rukiye", "zeynep", "hatice"
};

void printWord(char word[], char guessed[], int length);
void drawHangman(int guessesLeft);
int checkGuess(char guess, char word[], char guessed[], int length);

int main(void) {
    srand((unsigned)time(NULL));
    int wordLength = 6;
    char guessed[wordLength + 1];
    int guessesLeft, correctGuesses = 0;
    char guess;
    
    int index = rand() % 20;
    const char* selectedWord = words[index];

    for (int i = 0; i < wordLength; i++) {
        guessed[i] = '_';
    }
    guessed[wordLength] = '\0';
    
    guessesLeft = wordLength * 2;
    
    while (guessesLeft > 0 && correctGuesses < wordLength) {
        drawHangman(guessesLeft);
        printf("\nWord: ");
        printWord(selectedWord, guessed, wordLength);
        printf("\nGuesses left: %d\n", guessesLeft);
        printf("Guess a letter: ");
        scanf(" %c", &guess);

        if (checkGuess(guess, selectedWord, guessed, wordLength)) {
            printf("Correct guess!\n");
            correctGuesses++;
        } else {
            printf("Wrong guess!\n");
            guessesLeft--;
        }
    }

    if (correctGuesses == wordLength) {
        printf("\nYou guessed the word: %s\n", selectedWord);
    } else {
        drawHangman(guessesLeft);
        printf("\nOut of guesses. Word was: %s\n", selectedWord);
    }

    return 0;
}

void printWord(char word[], char guessed[], int length) {
    for (int i = 0; i < length; i++) {
        if (guessed[i] == '_') {
            printf("_ ");
        } else {
            printf("%c ", guessed[i]);
        }
    }
}

void drawHangman(int guessesLeft) {
    printf("\n");
    switch (guessesLeft) {
        case 12:
        case 11:
            printf(" |--|\n |\n |\n |\n");
            break;
        case 10:
        case 9:
            printf(" |--|\n |  o\n |\n |\n");
            break;
        case 8:
        case 7:
            printf(" |--|\n |  o\n |  |\n |\n");
            break;
        case 6:
        case 5:
            printf(" |--|\n |  o\n | /|\n |\n");
            break;
        case 4:
        case 3:
            printf(" |--|\n |  o\n | /|\\\n |\n");
            break;
        case 2:
        case 1:
            printf(" |--|\n |  o\n | /|\\\n | /\n");
            break;
        case 0:
            printf(" |--|\n |  o\n | /|\\\n | / \\\n");
            break;
    }
}

int checkGuess(char guess, char word[], char guessed[], int length) {
    int correct = 0;
    
    for (int i = 0; i < length; i++) {
        if (word[i] == guess && guessed[i] == '_') {
            guessed[i] = guess;
            correct++;
        }
    }
    
    return correct;
}
