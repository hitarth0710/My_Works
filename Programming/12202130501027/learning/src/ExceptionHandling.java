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

import java.util.Scanner;

public class ExceptionHandling extends Throwable {
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
*/

/*
problem 2

import java.util.Scanner;

class OutofBoundsException extends Exception
{
    OutofBoundsException(String msg)
    {
        super(msg);
    }
}

public class ExceptionHandling
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int[] a = {45, 46, 23, 67, 12, 12};
        //System.out.println("The length of array is "+a.length);
        System.out.println("Enter the index you want to you want to access in array: ");
        int n = sc.nextInt();
        try
        {
            if(n<0 || n>=a.length)
            {
                throw new OutofBoundsException("Index out of Bounds");
            }
            for (int i = 0; i < a.length; i++)
            {
                if (i == n)
                {
                    System.out.println("Element found at index " + i + " is " + a[i]);
                }
            }
        }catch(OutofBoundsException e){
            System.out.println(e.getMessage());
        }finally {
            sc.close();
        }
    }
}

method 2 for problem 2
import java.util.Scanner;

public class ExceptionHandling {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] numbers;
        int targetValue;

        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();
        numbers = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.printf("Enter element %d: ", i);
            numbers[i] = sc.nextInt();
        }

        System.out.print("Enter the target value: ");
        targetValue = sc.nextInt();

        try {
            for (int i = 0; i < n; i++) {
                if (numbers[i] == targetValue) {
                    System.out.println(String.format("Target value found at index %d", i));
                }
            }
        } catch (IndexOutOfBoundsException e) {
            System.out.println("Invalid index");
        } finally {
            sc.close();
        }
    }
}
*/

/*
problem 3

import java.util.Scanner;

class ArithmeticException extends Exception
{
    ArithmeticException(String msg)
    {
        super(msg);
    }
}

public class ExceptionHandling
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a: ");
        int a = sc.nextInt();
        System.out.println("Enter b: ");
        int b = sc.nextInt();

        try{
            if(a<0 || b<0)
            {
                throw new ArithmeticException("Elements are negative numbers");
            }
            else if(b == 0)
            {
                throw new ArithmeticException("second number cannot be zero because it is division");
            }
            int res,div,mul,sub;
            res = a+b;
            System.out.println("Their sum is "+res);
            sub = a-b;
            System.out.println("Their difference is "+sub);
            mul = a*b;
            System.out.println("Their product is "+mul);
            div = a/b;
            System.out.println("Their quetioent is "+div);

        }catch(ArithmeticException e){
            System.out.println(e.getMessage());
        }finally{
            sc.close();
        }
    }
}
*/

/*
problem 4

import java.util.Scanner;

class ArithmeticException extends Exception
{
    ArithmeticException(String msg)
    {
        super(msg);
    }
}

public class ExceptionHandling
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        double[] ele;

        try{
            System.out.print("Enter the total number of element: ");
            int n = sc.nextInt();
            ele = new double[n];
            if(n==0)
            {
                throw new ArithmeticException("cannot enter negative or zero");
            }
            for(int i=0;i<n;i++)
            {
                System.out.print("Enter "+(i+1)+" element");
                ele[i] = sc.nextDouble();
            }
            try{
                double avg=0;
                for(int i=0;i<n;i++)
                {
                    if(ele[i]<0)
                    {
                        throw new ArithmeticException("Elements cannot be negative");
                    }
                    avg+=ele[i];
                }
                double res=avg/n;
                System.out.println("The average is "+res);
            }catch(ArithmeticException e){
                System.out.println(e.getMessage());
            }
        }catch(ArithmeticException e) {
            System.out.println(e.getMessage());
        }finally{
            sc.close();
        }
    }
}

 */

import java.io.BufferedReader;
import java.io.FileReader;

class IOException extends Exception
{
    IOException(String msg)
    {
        super(msg);
    }
}

public class ExceptionHandling
{
    public static void main(String[] args)
    {
        BufferedReader reader = null;
        try{
            reader = new BufferedReader(new FileReader("test.txt"));
            String line = null;
            if(reader.readLine() == null)
            {
                throw new IOException("file is empty");
            }
            while((line = reader.readLine()) != null)
            {
                System.out.println(line);
            }
        }catch(IOException e){
            System.out.println(e.getMessage());
        }finally{

        }
    }
}