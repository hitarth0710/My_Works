/*
 * This is a multi-line comment at the beginning of the file
 * This program demonstrates various types of comments in C
 * Author: Test Author
 * Date: July 8, 2025
 * Purpose: Testing comment removal functionality
 */

#include<stdio.h>  // Include standard input/output library
#include<stdlib.h> /* Include standard library for general functions */

// Function prototypes section
// These are just dummy function declarations

/*
 * Global variable declarations
 * These variables don't actually do anything useful
 */
int globalVar = 42;    // A meaningless global variable
float pi = 3.14159;    /* Approximation of pi */

// Single line comment before function
/*
 * Multi-line comment before function
 * This function doesn't do anything meaningful
 */
void dummyFunction() {
    // This function is empty
    /* 
     * Just some comments inside
     * Nothing useful here
     */
    return; // Return nothing
}

/*
 * Another useless function
 * with multiple comment styles
 */
int anotherFunction(int x /* parameter comment */) {
    // Local variable with comment
    int result = 0;  /* Initialize to zero */
    
    /*
     * Some meaningless operations
     * Just to have some code
     */
    result = x + 1;  // Add one to parameter
    result = result * 2; /* Multiply by two */
    
    // Return the result
    return result; /* End of function */
}

// Main function starts here
/*
 * The main function
 * Entry point of the program
 */
int main() {
    /* 
     * Variable declarations with comments
     */
    int num1 = 10;     // First number
    int num2 = 20;     /* Second number */
    int sum;           // Sum of the numbers
    
    /*
     * Print some messages
     * These are just for demonstration
     */
    printf("Hello World!\n");  // Classic hello world
    
    // Calculate sum
    sum = num1 + num2;  /* Add the two numbers */
    
    /*
     * Print the result
     */
    printf("Sum is: %d\n", sum);  // Display the sum
    
    // Call the dummy functions
    dummyFunction();  /* Call first function */
    int result = anotherFunction(5);  // Call second function with parameter 5
    
    /*
     * Print the result from function
     */
    printf("Function result: %d\n", result);  // Show function result
    
    // Some nested comments demonstration
    /*
     * This is a multi-line comment
     * // This single-line comment is inside multi-line comment
     * This won't cause issues because it's inside a comment
     * More comment text here
     */
    // Another single line comment
    printf("Program ending...\n");  /* Final message */
    
    /*
     * End of main function
     * Return success code
     */
    return 0;  // Exit successfully
}

/*
 * End of file comment
 * This program demonstrated various comment styles:
 * 1. Single line comments with //
 * 2. Multi-line comments with /* */
  /* 3. Inline comments
  4. Comments at different positions
  5. Nested comment scenarios
  */

// Final single line comment at end of file
