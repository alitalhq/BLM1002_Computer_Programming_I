// GitHub: https://github.com/alitalhq

//Using a recursive function, reverse the entered multi-digit number. Example: 12345 -> 54321

#include <stdio.h>
#include <stdlib.h>

int reverse(int number, int reversed_number);

int main(void){
    int number, reversed_number;
    printf("Enter the multi-digit number you want to reverse: ");
    scanf("%d",&number);
    reversed_number = reverse(number,0);
    printf("Reversed form: %d\n",reversed_number);
    
    return 0;
}

int reverse(int number, int reversed_number){
    int ones, remaining;
    ones = number % 10;
    remaining = number/10;
    reversed_number = reversed_number * 10 + ones;
    
    if(remaining == 0){
        return reversed_number;
    }
    else {
        return reverse(remaining, reversed_number);
    }
}
