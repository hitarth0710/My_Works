import java.util.Scanner;

public class Prac7_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of elements:");
        int n = sc.nextInt();

        if (n == 0) {
            throw new ArithmeticException("Number of elements cannot be zero");
        }

        int[] A = new int[n];
        int sum = 0;


        for (int i = 0; i < n; i++) {
            System.out.println("Enter element " + (i + 1) + ":");
            int value = sc.nextInt();

            if (value < 0) {
                throw new IllegalArgumentException("Element value cannot be negative");
            }

            A[i] = value;
            sum += value;
        }

        double average = (double) sum / n;
        System.out.println("The average is: " + average);

        sc.close();
    }
}

