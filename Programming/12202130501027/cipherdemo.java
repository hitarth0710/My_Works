import java.nio.file.ClosedWatchServiceException;

abstract class Cipher2{
    String  plainText; 
    int  key;
    Cipher2(String plaintext , int key)
    {
        this.plainText = plaintext;
        this.key = key;
    }
    abstract String Encryption( );
    abstract String  Decryption( ); 
}

class Caesar_cipher extends Cipher2{
    Caesar_cipher(String s ,int n)
    {
        super(s,n);
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

class Substitution_Cipher extends Cipher2{
    Substitution_Cipher(String s ,int n)
    {
        super(s,n);
    }
}

public class cipherdemo {
    public static void main(String args[])
    {
        Caesar_cipher ob = new Caesar_cipher("GCET",3);
        String encrypt,decrypt;
        encrypt = ob.Encryption();
        decrypt = ob.Decryption();
        System.out.println("Your Encrypted Text is"+encrypt);
        System.out.println("Your Decrypted Text is"+decrypt);

    }
    
}
