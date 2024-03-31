import java.util.Scanner;

class Cipher { 
    String plainText; 
    int key; 

    Cipher(String plainText, int key) { 
        this.plainText = plainText; 
        this.key = key; 
    } 

    String Encryption() { 
        StringBuilder encryptedText = new StringBuilder(); 
        for (int i = 0; i < plainText.length(); i++) { 
            char currentChar = plainText.charAt(i); 
            if (Character.isLetter(currentChar)) { 
                char newChar = (char) (currentChar + key); 
                if ((Character.isLowerCase(currentChar) && newChar > 'z') || (Character.isUpperCase(currentChar) && newChar > 'Z')) 
                { 
                    newChar = (char) (currentChar - (26 - key)); 
                } 
                encryptedText.append(newChar); 
            } else { 
                encryptedText.append(currentChar); 
            } 
        } 
        return encryptedText.toString(); 
    } 

    String Decryption() { 
        StringBuilder decryptedText = new StringBuilder(); 
        for (int i = 0; i < plainText.length(); i++) { 
            char currentChar = plainText.charAt(i); 
            if (Character.isLetter(currentChar)) { 
                char newChar = (char) (currentChar - key); 
                if ((Character.isLowerCase(currentChar) && newChar < 'a') || (Character.isUpperCase(currentChar) && newChar < 'A')) 
                { 
                    newChar = (char) (currentChar + (26 - key)); 
                } 
                decryptedText.append(newChar); 
            } else { 
                decryptedText.append(currentChar); 
            } 
        } 
        return decryptedText.toString(); 
    } 

    public static void main(String[] args) { 
        Scanner scanner = new Scanner(System.in); 
        System.out.print("Enter the plaintext: "); 
        String plaintext = scanner.nextLine(); 
        System.out.print("Enter the key: "); 
        int key = scanner.nextInt(); 

        Cipher cipher = new Cipher(plaintext, key); 
        String encryptedText = cipher.Encryption(); 
        String decryptedText = cipher.Decryption(); 

        System.out.println("Encrypted text: " + encryptedText); 
        System.out.println("Decrypted text: " + decryptedText); 

        scanner.close(); // Close the scanner
    } 
}
