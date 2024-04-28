import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Prac10_1 {
    public static void main(String[] args) {
        // The word to count occurrences for
        String targetWord = "test"; // replace "yourWord" with the word you want to count

        // The file to read from
        File file = new File("yourFile.txt"); // replace "yourFile.txt" with your file path

        // A map to store word counts
        Map<String, Integer> wordCounts = new HashMap<>();

        try (Scanner scanner = new Scanner(file)) {
            while (scanner.hasNext()) {
                String word = scanner.next().toLowerCase(); // convert to lower case for case-insensitive matching
                wordCounts.put(word, wordCounts.getOrDefault(word, 0) + 1);
            }
        } catch (FileNotFoundException e) {
            System.out.println("File not found: " + e.getMessage());
        }

        // Print the count of the target word
        System.out.println("The word '" + targetWord + "' occurs " + wordCounts.getOrDefault(targetWord, 0) + " times.");
    }
}
