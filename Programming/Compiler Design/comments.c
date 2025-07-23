#include <stdio.h>

// Entry point of the program
int main() {
    // Declare and initialize a variable to hold user input
    int number = 0;

    // Inform the user about the program's purpose
    printf("This program calculates the square of a number.\n");

    // Prompt user to enter a number
    printf("Please enter an integer: ");
    // Read the input and store it in the 'number' variable
    scanf("%d", &number);

    // Calculate the square of the entered number
    // Using simple arithmetic: square = number * number
    int square = number * number;

    // Display the result to the user
    printf("The square of %d is %d.\n", number, square);

    // Indicate successful program completion
    return 0;
}