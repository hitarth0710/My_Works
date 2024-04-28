public class Prac5_2 {

    // Static Inner Class
    static class StaticInnerClass {
        void display() {
            System.out.println("This is a static inner class");
        }
    }

    // Local Inner Class
    class LocalInnerClass {
        void display() {
            System.out.println("This is a local inner class");
        }
    }

    // Anonymous Inner Class as a Runnable
    class AnonymousInnerClass implements Runnable {
        public void run() {
            System.out.println("This is an anonymous inner class");
        }
    }

    public static void main(String[] args) {
        Prac5_2 outerClass = new Prac5_2();

        // Display Static Inner Class
        StaticInnerClass staticInnerClass = new StaticInnerClass();
        staticInnerClass.display();

        // Display Local Inner Class
        LocalInnerClass localInnerClass = outerClass.new LocalInnerClass();
        localInnerClass.display();

        // Display Anonymous Inner Class
        AnonymousInnerClass anonymousInnerClass = outerClass.new AnonymousInnerClass();
        anonymousInnerClass.run();
    }
}