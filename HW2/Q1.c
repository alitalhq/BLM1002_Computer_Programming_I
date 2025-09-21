// GitHub: https://github.com/alitalhq

/*
 * Write a C program that, for an array of 50 elements with randomly generated values,
 * returns the following using functions and pointers:
 * the largest value,
 * the second largest value,
 * the smallest value,
 * the standard deviation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#define SIZE 50

void create_array(int *array);
void print_array(int *array);
void find_max(int *array, int *max, int *max2);
void find_min(int *array, int *min);
void calculate_std_deviation(int *array, double *std_dev);

int main(void){
    int array[SIZE];
    int max, max2, min;
    double std_dev;
    srand((unsigned)time(NULL));
    
    create_array(array);
    printf("Array:\n");
    print_array(array);
    
    find_max(array, &max, &max2);
    printf("Largest element: %d\n", max);
    printf("Second largest element: %d\n", max2);
    
    find_min(array, &min);
    printf("Smallest element: %d\n", min);

    calculate_std_deviation(array, &std_dev);
    printf("Standard deviation: %.2f\n", std_dev);
    
    return 0;
}

void create_array(int *array){
    for(int i = 0; i<SIZE; i++){
        *(array + i) = rand() % 1000 + 1;
    }
    return;
}

void print_array(int *array){
    for(int i = 0; i<SIZE; i++){
        printf("%d ",*(array + i));
    }
    printf("\n\n");
    return;
}

void find_max(int *array, int *max, int *max2){
    *max = INT_MIN;
    *max2 = INT_MIN;
    
    for (int i = 0; i<SIZE; i++){
        if(*(array+i) > *max){
            *max2 = *max;
            *max = *(array+i);
        }
        else if (*(array+i) > *max2){
            *max2 = *(array+i);
        }
    }
    return;
}

void find_min(int *array, int *min){
    *min = INT_MAX;
    for(int i = 0; i<SIZE; i++){
        if(*(array+i) < *min){
            *min = *(array+i);
        }
    }
    return;
}

void calculate_std_deviation(int *array, double *std_dev){
    double sum = 0.0, mean, diff_sum = 0.0;
    
    for(int i = 0; i < SIZE; i++){
        sum += *(array + i);
    }
    mean = sum / SIZE;
    
    for(int i = 0; i < SIZE; i++){
        diff_sum += pow(*(array + i) - mean, 2);
    }
    
    *std_dev = sqrt(diff_sum / SIZE);
    return;
}
