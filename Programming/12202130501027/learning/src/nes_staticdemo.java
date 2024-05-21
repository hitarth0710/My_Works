class OuterClass {
    private static String msg = "Hello World";

    // Static nested class
    public static class NestedStaticClass {
        // Only static members of Outer class are directly accessible in nested static class
        public void printMessage() {
            System.out.println("Message from nested static class: " + msg);
        }
    }
}

public class nes_staticdemo
{
    public static void main(String[] args) {
        // Create instance of nested Static class
        OuterClass.NestedStaticClass printer = new OuterClass.NestedStaticClass();
        // Call non-static method of nested static class
        printer.printMessage();
        //OuterClass printer1 = new OuterClass();
        //printer1.printMessage();//cannot do this
    }
}