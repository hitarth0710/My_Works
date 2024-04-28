import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.Scanner;

class GenericStack<T> {
    private ArrayList<T> stack = new ArrayList<T>();

    public void push(T item) {
        stack.add(item);
    }

    public T pop() {
        if (!isEmpty()) {
            return stack.remove(stack.size() - 1);
        } else {
            throw new EmptyStackException();
        }
    }

    public T peek() {
        if (!isEmpty()) {
            return stack.get(stack.size() - 1);
        } else {
            throw new EmptyStackException();
        }
    }

    public boolean isEmpty() {
        return stack.isEmpty();
    }
}

public class Prac6_2 {
    public static void main(String[] args) {
        GenericStack<Integer> stack = new GenericStack<>();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Choose an operation:");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Peek");
            System.out.println("4. Check if the stack is empty");
            System.out.println("5. Exit");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter a number to push:");
                    int num = scanner.nextInt();
                    stack.push(num);
                    break;
                case 2:
                    if (!stack.isEmpty()) {
                        System.out.println("Popped element: " + stack.pop());
                    } else {
                        System.out.println("Stack is empty.");
                    }
                    break;
                case 3:
                    if (!stack.isEmpty()) {
                        System.out.println("Top element: " + stack.peek());
                    } else {
                        System.out.println("Stack is empty.");
                    }
                    break;
                case 4:
                    System.out.println("Is stack empty? " + stack.isEmpty());
                    break;
                case 5:
                    System.out.println("Exiting...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please choose a valid operation.");
            }
        }
    }
}