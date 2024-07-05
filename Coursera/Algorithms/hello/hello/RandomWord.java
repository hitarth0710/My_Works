package hello;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
//C:\STUDY\STUDY\Coursera\Algorithms\programs\algs4.jar

public class RandomWord {
    public static void main(String[] args)
    {
        if (args.length < 1) {
            StdOut.println("Please provide two words as arguments.");
            return;
        }
        String champ= null;
        for (int i = 0; i < args.length; i++) {
            if (StdRandom.bernoulli(1.0 / (i + 1)))
            {
                champ = args[i];
            }
        }
        StdOut.println(champ);
    }
}

//javac -cp .;C:\STUDY\STUDY\Coursera\Algorithms\programs\algs4.jar hello\RandomWord.java
//java -cp .;C:\STUDY\STUDY\Coursera\Algorithms\programs\algs4.jar hello.RandomWord