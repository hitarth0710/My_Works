import java.util.Scanner;

class BankAccount {

    private static int nextAccNo = 1;  // Class variable to track account numbers

    private String depositorName;
    private int accNo;
    private String accType;
    private double balance;

    public BankAccount(String depositorName, String accType) {
        this.depositorName = depositorName;
        this.accNo = nextAccNo++;  // Assign unique account number and increment
        this.accType = accType;
        this.balance = 0;
    }

    public void createAcc() {
        System.out.println("Account Created Successfully! Account Number: " + accNo);
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Amount Deposited: " + amount);
        } else {
            System.out.println("Invalid Deposit Amount");
        }
    }

    public void withdraw(double amount) {
        if (0 < amount && amount <= balance) {
            balance -= amount;
            System.out.println("Amount Withdrawn: " + amount);
        } else {
            System.out.println("Insufficient Funds");
        }
    }

    public void balanceInquiry() {
        System.out.println("Account Balance: " + balance);
        System.out.println("Type of account is "+accType);
        System.out.println("Account holder's name :"+depositorName);
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BankAccount account = null;  // Initialize account to null

        int choice;

        do {
            System.out.println("\nMenu:");
            System.out.println("1. Create Account");
            System.out.println("2. Deposit");
            System.out.println("3. Withdraw");
            System.out.println("4. Balance Inquiry");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    if (account == null) {
                        System.out.print("Enter Depositor Name: ");
                        String name = scanner.next();
                        System.out.print("Enter Account Type: ");
                        String type = scanner.next();
                        account = new BankAccount(name, type);
                        account.createAcc();
                    } else {
                        System.out.println("An account already exists.");
                    }
                    break;
                case 2:
                    if (account != null) {
                        System.out.print("Enter amount to deposit: ");
                        double amount = scanner.nextDouble();
                        account.deposit(amount);
                    } else {
                        System.out.println("Please create an account first.");
                    }
                    break;
                case 3:
                    if (account != null) {
                        System.out.print("Enter amount to withdraw: ");
                        double amount = scanner.nextDouble();
                        account.withdraw(amount);
                    } else {
                        System.out.println("Please create an account first.");
                    }
                    break;
                case 4:
                    if (account != null) {
                        account.balanceInquiry();
                    } else {
                        System.out.println("Please create an account first.");
                    }
                    break;
                case 5:
                    System.out.println("Exiting program.");
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        } while (choice != 5);
        scanner.close();
    }
}