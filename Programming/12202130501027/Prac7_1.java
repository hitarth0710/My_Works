class NotEnoughMoneyException extends RuntimeException {
    public NotEnoughMoneyException(String message) {
        super(message);
    }
}

class Bank {
    private double balance;

    public Bank(double balance) {
        this.balance = balance;
    }

    public void deposit(double amount) {
        System.out.println("Old Balance: " + balance);
        balance += amount;
        System.out.println("New Balance: " + balance);
    }

    public void withdraw(double amount) throws ArithmeticException, NotEnoughMoneyException {
        System.out.println("Old Balance: " + balance);
        if (balance < amount) {
            throw new ArithmeticException("Not enough balance to withdraw");
        }
        balance -= amount;
        System.out.println("New Balance: " + balance);
        if (balance < 500) {
            throw new NotEnoughMoneyException("Balance is less than 500 after withdrawal");
        }
    }
}

public class Prac7_1 {
    public static void main(String[] args) {
        Bank bank = new Bank(1000);
        bank.deposit(500);
        try {
            bank.withdraw(2500);
        } catch (ArithmeticException | NotEnoughMoneyException e) {
            System.out.println(e.getMessage());
        }
    }
}