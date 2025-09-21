// GitHub: https://github.com/alitalhq

/*
 * Write a C program that calculates the N-th term of the Fibonacci series using a recursive function.
 * The program should take N as input from the user and display the result.
 * Fibonacci Series:
 * F(0) = 0
 * F(1) = 1
 * F(N) = F(N-1) + F(N-2) (for N ≥ 2)
 */

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int number);

int main(void){
    
    int N;
    printf("Enter a number: ");
    scanf("%d", &N);
    printf("The %d-th term of the Fibonacci series: %d\n", N, fibonacci(N));
    return 0;
}

int fibonacci(int number){
    if (number == 0) return 0;  // F(0) = 0
    if (number == 1) return 1;  // F(1) = 1
    return fibonacci(number - 1) + fibonacci(number - 2);
}