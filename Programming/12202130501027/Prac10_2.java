import java.io.*;
import java.util.Scanner;
//Write a program to print it self.
class readingFile {
    public static void main(String[] args) throws IOException,FileNotFoundException {
        FileReader fileReader = new FileReader("C:\\STUDY\\STUDY\\Programming\\12202130501027\\Prac10_1.java");
        Scanner scan = new Scanner(fileReader);
        while(scan.hasNextLine())
        {
            System.out.println(scan.nextLine());
        }
        scan.close();
    }
}
