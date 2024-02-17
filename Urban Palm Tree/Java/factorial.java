import java.util.Scanner;

public class factorial {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a positive integer: ");
        long num = scanner.nextLong();
        System.out.println("Factorial of " + num + " = " + factorial1(num));
        scanner.close();
    }

    public static long factorial1(long n) {
        if (n == 0) {
            return 1;
        } else {
            return n * factorial1(n - 1);
        }
    }
}
