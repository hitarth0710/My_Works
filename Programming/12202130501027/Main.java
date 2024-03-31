import java.util.Scanner;

class BankAccount {
    private static int nextAccountNumber = 1; // Class variable to hold the next account number
    private String depositorName;
    private int accountNumber;
    private String accountType;
    private double balance;

    public BankAccount(String depositorName, String accountType) {
        this.depositorName = depositorName;
        this.accountType = accountType;
        this.accountNumber = nextAccountNumber++;
        this.balance = 0.0;
    }

    public void createAccount(String depositorName, String accountType) {
        this.depositorName = depositorName;
        this.accountType = accountType;
        this.accountNumber = nextAccountNumber++;
        this.balance = 0.0;
    }

    public void deposit(double amount) {
        if (amount > 0) {
            this.balance += amount;
        } else {
            System.out.println("Deposit amount must be positive.");
        }
    }

    public void withdraw(double amount) {
        if (amount > 0) {
            if (amount <= this.balance) {
                this.balance -= amount;
            } else {
                System.out.println("Insufficient balance.");
            }
        } else {
            System.out.println("Withdrawal amount must be positive.");
        }
    }

    public void balanceInquiry() {
        System.out.println("The balance for account number " + this.accountNumber + " is " + this.balance);
    }

    public int getAccNo() {
        return this.accountNumber;
    }
    public void displayAccountInfo() {
        System.out.println("Account Number: " + this.accountNumber);
        System.out.println("Depositor Name: " + this.depositorName);
        System.out.println("Account Type: " + this.accountType);
        System.out.println("Balance: " + this.balance);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Creating a bank account
        System.out.println("Creating a new bank account...");
        System.out.println("Enter depositor name:");
        String depositorName = scanner.nextLine();
        System.out.println("Enter account type:");
        String accType = scanner.nextLine();

        BankAccount account = new BankAccount(depositorName, accType);

        // Operations on the account
        System.out.println("Account created successfully with account number: " + account.getAccNo());

        System.out.println("Enter deposit amount:");
        double depositAmount = scanner.nextDouble();
        account.deposit(depositAmount);

        System.out.println("Enter withdrawal amount:");
        double withdrawAmount = scanner.nextDouble();
        account.withdraw(withdrawAmount);

        account.balanceInquiry();

        scanner.close();
    }
}