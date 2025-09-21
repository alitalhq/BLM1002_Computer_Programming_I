// GitHub: https://github.com/alitalhq

/*
 * Random Dice Rolls and Result Analysis (Dynamic Memory and Function Usage):
 * Your program should include a structure that calculates how many times each of the 100 rolled dice combinations
 * (1-1, 1-2, ..., 6-6) occursand stores these results in dynamic memory.
 * Additionally, as part of the program, there should be a function that, after 100 dice rolls,
 * displays how many times each dice combination occurred and identifies the most frequently rolled dice combination(s)
 * (if more than one combination shares the highest frequency, all of them should be shown).
 * This function should store the frequencies of the dice combinations in a dynamic array and return the analysis results.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLLS 100

void analyze_dice(int *counts);
void roll_dice(int *counts);

int main(void) {
    srand((unsigned)time(NULL));

    int *counts = (int *)calloc(6 * 6, sizeof(int));

    for (int i = 0; i < ROLLS; i++) {
        roll_dice(counts);
    }

    analyze_dice(counts);

    free(counts);

    return 0;
}

void roll_dice(int *counts){
    int die1, die2;
    
    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;
    counts[(die1 - 1) * 6 + (die2 - 1)]++; 
}

void analyze_dice(int *counts) {
    int max = 0;
    
    printf("\nDice roll frequencies:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            int index = i * 6 + j;
            printf("%d-%d: %d\n", i + 1, j + 1, counts[index]);
            if (counts[index] > max) {
                max = counts[index];
            }
        }
    }
    
    printf("\nMost frequent combinations (frequency: %d):\n", max);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            int index = i * 6 + j;
            if (counts[index] == max) {
                printf("%d-%d\n", i + 1, j + 1);
            }
        }
    }
}
