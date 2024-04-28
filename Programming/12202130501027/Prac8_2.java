class Queue {
    private int[] items;
    private int front, rear, count;

    public Queue(int size) {
        items = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    public synchronized void enqueue(int item) throws InterruptedException {
        while (isFull()) {
            wait();
        }
        rear = (rear + 1) % items.length;
        items[rear] = item;
        count++;
        notifyAll();
    }

    public synchronized int dequeue() throws InterruptedException {
        while (isEmpty()) {
            wait();
        }
        int item = items[front];
        front = (front + 1) % items.length;
        count--;
        notifyAll();
        return item;
    }

    public boolean isFull() {
        return count == items.length;
    }

    public boolean isEmpty() {
        return count == 0;
    }
}

class Producer implements Runnable {
    private Queue queue;

    public Producer(Queue queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        try {
            for (int i = 0; i < 30; i++) {
                queue.enqueue(i);
                System.out.println("Produced: " + i);
                Thread.sleep(100);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

class Consumer implements Runnable {
    private Queue queue;

    public Consumer(Queue queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        try {
            while (true) {
                int item = queue.dequeue();
                System.out.println("Consumed: " + item);
                Thread.sleep(100);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

public class Prac8_2 {
    public static void main(String[] args) {
        Queue queue = new Queue(15);

        Thread producerThread = new Thread(new Producer(queue), "Producer");
        Thread consumerThread1 = new Thread(new Consumer(queue), "Consumer1");
        Thread consumerThread2 = new Thread(new Consumer(queue), "Consumer2");

        producerThread.setPriority(Thread.NORM_PRIORITY + 1);
        consumerThread1.setPriority(Thread.NORM_PRIORITY - 1);
        consumerThread2.setPriority(Thread.NORM_PRIORITY - 1);

        producerThread.start();
        consumerThread1.start();
        consumerThread2.start();
    }
}