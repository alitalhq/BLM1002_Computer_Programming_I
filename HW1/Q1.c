// GitHub: https://github.com/alitalhq

//Write a C program that finds the largest value in an array of 10 elements with randomly assigned values.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void create_array(int array[], int element);
int find_max(int array[], int element, int max);
void print_array(int array[], int element);

int main(void){
    int max_value;
    srand((unsigned)time(NULL));
    int array[SIZE];
    create_array(array, 0);
    max_value = find_max(array, 0, array[0]);
    printf("array: ");
    print_array(array, 0);
    printf("largest value: %d\n", max_value);
    return 0;
}

void create_array(int array[], int element){
    if (element >= SIZE){
        return;
    }
    else{
        array[element] = rand() % 1000 + 1;
        create_array(array, element + 1);
    }
}

int find_max(int array[], int element, int max){
    if (element >= SIZE){
        return max;
    }
    else{
        if (array[element] > max){
            max = array[element];
        }
        return find_max(array, element + 1, max);
    }
}

void print_array(int array[], int element){
    if (element >= SIZE){
        printf("\n");
        return;
    }
    else{
        printf("%d ", array[element]);
        print_array(array, element + 1);
    }
}
