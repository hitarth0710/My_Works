#include <stdio.h>


int main() {
    
    int number = 0;

    
    printf("This program calculates the square of a number.\n");

    
    printf("Please enter an integer: ");
    
    scanf("%d", &number);

    
    
    int square = number * number;

    
    printf("The square of %d is %d.\n", number, square);

    
    return 0;
}