import java.util.Scanner;

abstract class Cipher2{
    String  plainText; 
    int  key;
    Cipher2(String plaintext)
    {
        this.plainText = plaintext;
    }
    abstract String Encryption( );
    abstract String  Decryption( ); 
}

class Caesar_cipher extends Cipher2{
    Caesar_cipher(String s ,int n)
    {
        super(s);
        key=n;
    }
    String Encryption()
    {
        char arr[] = plainText.toCharArray();

        for(int i=0; i<arr.length;i++)
        {
            arr[i] = (char) (arr[i] + key) ;
        }
        plainText = new String(arr);
        return plainText;
    }
    String Decryption()
    {
        char arr[] = plainText.toCharArray();

        for(int i=0; i<arr.length;i++)
        {
            arr[i] = (char) (arr[i] - key) ;
        }
        plainText = new String(arr);
        return plainText;
    }
}

class Substitution_Cipher extends Cipher2 {
    Substitution_Cipher(String a) {
        super(a);
    }

    public String Encryption() {
        char a[] = plainText.toCharArray();
        int i;
        for (i = 0; i < a.length; i++) {
            String plain = "a b c d e f g h i j k l m n o p q r s t u v w x y z A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
            String encrypt = "q a z w s x e d c r f v t g b y h n u j m i k o l p Q A Z W X E D C R F V T G B Y H N U J M I K O L P";
            int d = plain.indexOf(a[i]);
            char ch = encrypt.charAt(d);
            a[i] = ch;
        }
        this.plainText = new String(a);
        return new String(a);
    }

    public String Decryption() {
        char a[] = plainText.toCharArray();
        int i;
        for (i = 0; i < a.length; i++) {
            String encrypt = "q a z w s x e d c r f v t g b y h n u j m i k o l p Q A Z W X E D C R F V T G B Y H N U J M I K O L P";
            String plain = "a b c d e f g h i j k l m n o p q r s t u v w x y z A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
            int d = encrypt.indexOf(a[i]);
            char ch = plain.charAt(d);
            a[i] = ch;
        }
        this.plainText = new String(a);
        return new String(a);
    }
}

public class cipherdemo {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        String name;
        System.out.println("Enter a text that is to be encrypted");
        name = sc.next();
        Substitution_Cipher s = new Substitution_Cipher(name);
        System.out.println("Your encrypted text is: " + s.Encryption());
        System.out.println("Your decrypted text is: " + s.Decryption());
        int a;
        System.out.println("Enter a key for encryption");
        a = sc.nextInt();
        Caesar_cipher csd = new Caesar_cipher(name, a);
        System.out.println("Your encrypted text is: " + csd.Encryption());
        System.out.println("Your decrypted text is: " + csd.Decryption());
        sc.close();
    }   
}
