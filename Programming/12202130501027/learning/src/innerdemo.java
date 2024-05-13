class outer2 {
    private int x = 10;
    private int Y = 20;

    private class Inner {
        public void printX() {
            System.out.println(x);
        }
        public void printY() {
            System.out.println(Y);
        }
    }

    public void createAndPrintX() {
        Inner inner = new Inner();
        inner.printX();
    }

    public void createAndPrintY() {
        Inner inner = new Inner();
        inner.printY();
    }
}

public class innerdemo {
    public static void main(String[] args) {
        outer2 outer = new outer2();
        outer.createAndPrintX(); // prints 10
        outer.createAndPrintY(); // prints 20
    }
}