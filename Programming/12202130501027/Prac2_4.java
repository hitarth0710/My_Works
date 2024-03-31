public class Prac2_4 { 
    public static void main(String[] args) { 
        String str = "Hello"; 
        System.out.println("String:"); 
        System.out.println("Initial string: " + str); 
        System.out.println("Length: " + str.length()); 
        System.out.println("Character at index 1: " + str.charAt(1)); 
        System.out.println("Concatenation with ' World': " + str.concat(" World")); 
        System.out.println("Substring from index 1 to 3: " + str.substring(1, 3)); 
        System.out.println("Index of 'e': " + str.indexOf('e')); 
        System.out.println(); 

        StringBuffer stringBuffer = new StringBuffer("Hello"); 
        System.out.println("StringBuffer:"); 
        System.out.println("Initial string: " + stringBuffer); 
        System.out.println("Length: " + stringBuffer.length()); 
        System.out.println("Character at index 1: " + stringBuffer.charAt(1)); 
        stringBuffer.append(" World"); 
        System.out.println("Appended ' World': " + stringBuffer); 
        stringBuffer.insert(5, " Java"); 
        System.out.println("Inserted ' Java' at index 5: " + stringBuffer); 
        stringBuffer.delete(5, 10); 
        System.out.println("Deleted characters from index 5 to 9: " + stringBuffer); 
        stringBuffer.reverse(); 
        System.out.println("Reversed string: " + stringBuffer); 
    } 
}
