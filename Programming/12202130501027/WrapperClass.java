public class WrapperClass { 
    public static void main(String[] args) { 
        // Integer wrapper class 
        Integer intWrapper = 10; 
        System.out.println("Integer Wrapper Class:"); 
        System.out.println("Value: " + intWrapper); 
        System.out.println("Max value: " + Integer.MAX_VALUE); 
        System.out.println("Min value: " + Integer.MIN_VALUE); 
        System.out.println("Size in bytes: " + Integer.BYTES); 
        System.out.println("Size in bits: " + Integer.SIZE); 
        System.out.println(); 

        // Double wrapper class 
        Double doubleWrapper = 3.14; 
        System.out.println("Double Wrapper Class:"); 
        System.out.println("Value: " + doubleWrapper); 
        System.out.println("Max value: " + Double.MAX_VALUE); 
        System.out.println("Min value: " + Double.MIN_VALUE); 
        System.out.println("Positive infinity: " + Double.POSITIVE_INFINITY); 
        System.out.println("Negative infinity: " + Double.NEGATIVE_INFINITY); 
        System.out.println("NaN: " + Double.NaN); 
        System.out.println("Size in bytes: " + Double.BYTES); 
        System.out.println("Size in bits: " + Double.SIZE); 
        System.out.println(); 

        // Character wrapper class 
        Character charWrapper = 'A'; 
        System.out.println("Character Wrapper Class:"); 
        System.out.println("Value: " + charWrapper); 
        System.out.println("Size in bytes: " + Character.BYTES); 
        System.out.println("Size in bits: " + Character.SIZE); 
        System.out.println(); 

        // Boolean wrapper class 
        Boolean boolWrapper = true; 
        System.out.println("Boolean Wrapper Class:"); 
        System.out.println("Value: " + boolWrapper); 
    } 
}
