import java.io.File;

public class Prac10_3 {
    public static void main(String[] args) {
        // The directory to list files for
        String directoryPath = "C:\\Users\\rajes\\OneDrive\\Desktop\\java files";

        File directory = new File(directoryPath);

        // Check if the directory exists and is indeed a directory
        if (directory.exists() && directory.isDirectory()) {
            // List all files in the directory
            String[] files = directory.list();
            if (files != null) {
                for (String file : files) {
                    System.out.println(file);
                }
            } else {
                System.out.println("The directory is empty.");
            }
        } else {
            System.out.println("The provided path does not point to a directory.");
        }
    }
}