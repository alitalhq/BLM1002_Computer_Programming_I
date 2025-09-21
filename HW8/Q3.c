// GitHub: https://github.com/alitalhq

//Create an example that demonstrates the use of all bitwise operators.

#include <stdio.h>

int main(void) {
    unsigned char a = 60;  //60 = 0011 1100 in binary
    unsigned char b = 13;  //13 = 0000 1101 in binary
    unsigned char result;

    printf("a = %d, b = %d\n", a, b);

    //Bitwise AND
    result = a & b; //0011 1100 & 0000 1101 = 0000 1100 = 12
    printf("a & b  = %d (AND)\n", result);

    //Bitwise OR
    result = a | b; //0011 1100 | 0000 1101 = 0011 1101 = 61
    printf("a | b  = %d (OR)\n", result);

    //Bitwise XOR
    result = a ^ b; //0011 1100 ^ 0000 1101 = 0011 0001 = 49
    printf("a ^ b  = %d (XOR)\n", result);

    //Bitwise NOT
    result = ~a; //~0011 1100 = 1100 0011 = 195
    printf("~a     = %d (NOT)\n", result);

    //Left shift
    result = a << 2; //0011 1100 << 2 = 1111 0000 = 240
    printf("a << 2 = %d (left shift)\n", result);

    //Right shift
    result = a >> 2; //0011 1100 >> 2 = 0000 1111 = 15
    printf("a >> 2 = %d (right shift)\n", result);

    return 0;
}
