import java.util.Scanner;

public class sum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a positive integer: ");
        int num = scanner.nextInt();
        int sum = sumOfNNumbers(num);
        System.out.println("Sum of first " + num + " numbers is: " + sum);
    }

    public static int sumOfNNumbers(int n) {
        return n * (n + 1) / 2;
    }
}
