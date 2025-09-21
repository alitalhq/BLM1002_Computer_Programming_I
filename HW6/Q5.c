// GitHub: https://github.com/alitalhq

/*
 * Calculate the similarity score between a given string and the elements of an array.
 * Define an array of 10 elements.
 * Take a string input from the user.
 * For each letter in the input string, compare it with every element in the array and calculate the similarity score according to the following rules:
 *     If the same letter is in the same position: 3 points
 *     If the letter is in the previous or next position: 2 points
 *     If the letter is in a more distant position: 1 point
 *     If the letter does not exist: 0 points
 * Find the array element with the highest similarity score and print it.
 * Calculate the similarity score for each array element with the input string.
 * Sort the array in descending order based on similarity scores.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

void calculateSimilarity(int *similarity, char **array, char *input);
void sortIndices(int *similarity, int *indices);

int main(void){
    
    char input[20];
    char *array[] = {"apple", "brick", "grape", "stone", "flame", "tiger", "plane", "music", "ocean", "drink"};
    int *similarity = (int*)calloc(SIZE, sizeof(int));
    int *indices = (int*)calloc(SIZE, sizeof(int));

    printf("Enter a word: ");
    fgets(input, sizeof(input), stdin); 
    input[strlen(input)-1] = '\0';

    calculateSimilarity(similarity, array, input);
    sortIndices(similarity, indices);

    printf("Most similar word to '%s':\n%s (score: %d)\n\n", input, array[indices[0]], similarity[indices[0]]);
    printf("Words sorted by similarity score:\n");
    for(int i=0; i<SIZE; i++){
        printf("%s - %d\n", array[indices[i]], similarity[indices[i]]);
    }
    
    free(similarity);
    free(indices);
    
    return 0;
}

void calculateSimilarity(int *similarity, char **array, char *input){
    for(int i=0; i<SIZE; i++){
        for(int j=0; input[j]!='\0' && array[i][j]!='\0'; j++){
            if(input[j] == array[i][j]){
                similarity[i] += 3;
            }
            else if(input[j] == array[i][j+1] || input[j] == array[i][j-1]){
                similarity[i] += 2;
            }
            else {
                for(int k = 0; array[i][k]!='\0'; k++){
                    if(array[i][k] == input[j]){
                        similarity[i] += 1;
                        break;
                    }
                }
            }
        }
    }
}

void sortIndices(int *similarity, int *indices){ 
    for(int i = 0; i<SIZE; i++){
        indices[i] = i;
    }
    
    for(int i = 0; i<SIZE-1; i++){
        for(int j = 0; j<SIZE-i-1; j++){
            if(similarity[indices[j]] < similarity[indices[j+1]]){
                int temp = indices[j];
                indices[j] = indices[j+1];
                indices[j+1] = temp;
            }
        }
    }
}

