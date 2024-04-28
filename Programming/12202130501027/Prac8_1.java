import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class PrimeThread extends Thread {
    private int low;
    private int high;

    public PrimeThread(int low, int high) {
        this.low = low;
        this.high = high;
    }

    @Override
    public void run() {
        for (int i = low; i <= high; i++) {
            if (isPrime(i)) {
                System.out.println(i);
            }
        }
    }

    private boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}

class PrimeRunnable implements Runnable {
    private int low;
    private int high;

    public PrimeRunnable(int low, int high) {
        this.low = low;
        this.high = high;
    }

    @Override
    public void run() {
        for (int i = low; i <= high; i++) {
            if (isPrime(i)) {
                System.out.println(i);
            }
        }
    }

    private boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}

public class Prac8_1 {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(2);

        executor.execute(new PrimeRunnable(1, 50));
        executor.execute(new PrimeRunnable(51, 100));

        executor.shutdown();
    }
}