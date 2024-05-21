/* set of Problems
*
*
* Sure, here are some problem sets to help you practice exception handling in Java:

1. Basic Exception Handling: Write a program that reads an integer value from the user and prints "Even"
   if the number is even or "Odd" if it's odd. If the user enters a non-integer value, catch the
   `NumberFormatException` and print "Invalid input".
2. Custom Exception Classes: Create a custom exception class called `OutOfBoundsException`. Write a program
   that throws an instance of this exception when the user attempts to access an element in an array that is
   out of bounds. Catch the exception and print a meaningful message.
3. Multiple Exception Types: Write a program that reads two numbers from the user and prints their sum, product,
   difference, and quotient. If either number is negative or if one number is zero, catch the
   appropriate `ArithmeticException` (e.g., division by zero) and print an error message.
4. Nested Try-Catch Blocks: Write a program that reads three numbers from the user and calculates their average.
   Wrap the calculation code in a try-catch block to handle the possibility of dividing by zero.
   If any exception occurs during the calculation, catch it and print an error message.
5. Finally Blocks: Write a program that reads a file and prints its contents to the console.
   Use a finally block to close the file even if an exception occurs during reading or printing.
6. Multiple Catch Statements: Write a program that reads two numbers from the user and calculates
   their sum, product, difference, and quotient. If either number is negative or if one number is zero,
   catch the appropriate `ArithmeticException` (e.g., division by zero) and print an error message.
7. Exception Propagation: Write a program that reads a file and parses its contents as integers.
    If any exception occurs during parsing, catch it and print an error message.
8. User-Defined Exceptions: Create a custom exception class called `MyException`.
   Write a program that throws an instance of this exception when the user enters
   invalid input (e.g., non-integer value). Catch the exception and print a meaningful message.
9. Throwing and Handling Checked Exceptions: Write a program that reads two numbers from the user and calculates
   their sum, product, difference, and quotient. If any checked exception occurs during calculation
   (e.g., division by zero), catch it and print an error message.
10. Best Practices for Exception Handling: Write a program that reads three numbers from the user and
    calculates their average. Use meaningful variable names, comments, and indentation to make your code
    readable and understandable. Use try-catch blocks to handle exceptions, but also include comments explaining
    why each exception is handled in a particular way.

These problem sets should help you practice exception handling in Java at different levels of difficulty. Good luck!
*/

/*
problem 1 :-(solution)
 */
import java.util.InputMismatchException;
import java.util.Scanner;

public class Exception
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number oy your Choice :");
        try {
            int n = sc.nextInt();
            if (n % 2 == 0) {
                System.out.println("entered no is even");
            } else {
                System.out.println("entered no. is odd");
            }
        }catch(Exception e){
            System.out.println("Invalid Input");
        }finally{
            sc.close();
        }
    }
}