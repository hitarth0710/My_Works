class outer {
    private int x = 10;
    private int Y = 20;

    public class Inner {
        public void printX() {
            System.out.println(x);
        }
        public void printY() {
            System.out.println(Y);
        }
    }
}

public class first
{
    public static void main(String[] args) {
        outer outer = new outer();
        outer outer2 = new outer();
        outer.Inner inner = outer.new Inner();
        outer.Inner inner2 = outer2.new Inner();
        inner.printX(); // prints 10
        inner2.printY(); // prints 20
    }
}