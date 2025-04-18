import java.util.NoSuchElementException;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Permutation {

	public static void main(String[] args) {
		int k = Integer.parseInt(args[0]);
		RandomizedQueue<String> rq = new RandomizedQueue<String>();
		
		// Read input from StdIn and add to Queue
		try
        {
            String s = StdIn.readString();
            while(s != null)
            {
                rq.enqueue(s);
                s = StdIn.readString();
            }
        }
        catch(NoSuchElementException e) {}
		
		// Print 'k' items
		while (k > 0) {
			StdOut.println(rq.dequeue());
			k--;
		}
	}

}
