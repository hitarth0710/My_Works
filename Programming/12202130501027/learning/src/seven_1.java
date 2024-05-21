

class Bank
{
    double balance;
    Bank(double balance)
    {
        this.balance=balance;
    }
    void deposit(double amount)
    {
        System.out.println("Your current balance before Deposit is "+balance);
        balance += amount;
        System.out.println("Your current balance after Deposit is "+balance);
    }
    void withdraw()
    {

    }
}

public class seven_1
{
    public static void main(String[] args)
    {

    }
}

/*
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

public class {
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
*/