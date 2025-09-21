// GitHub: https://github.com/alitalhq

//Write a C function that fills an array of n elements using pointers and prints their sum on the screen.

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void create_array(int *array);
void print_array(int *array);
void sum_array(int *array, int *total);

int main(void){
    int array[SIZE];
    create_array(array);
    printf("Array: ");
    print_array(array);
    int total = 0;
    sum_array(array, &total);
    printf("Sum of array elements: %d\n", total);
    return 0;
}

void create_array(int *array){
    for(int i = 0; i < SIZE; i++){
        *(array + i) = rand() % 1000 + 1;
    }
    return;
}

void print_array(int *array){
    for(int i = 0; i < SIZE; i++){
        printf("%d ", *(array + i));
    }
    printf("\n\n");
    return;
}

void sum_array(int *array, int *total){
    for(int i = 0; i < SIZE; i++){
        *total += *(array + i);
    }
    return;
}
