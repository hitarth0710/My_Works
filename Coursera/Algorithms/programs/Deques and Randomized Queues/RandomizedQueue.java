import java.util.Iterator;
import java.util.NoSuchElementException;
import edu.princeton.cs.algs4.StdRandom;

public class RandomizedQueue<Item> implements Iterable<Item> {
	
	private class Node {
		private Item item;
		Node next;
		
		private Node(Item item, Node next) {
			this.item = item;
			this.next = next;
		}
	}
	
	private Node sentinel;
	private int size;
	
	 // construct an empty randomized queue
    public RandomizedQueue() {
    	sentinel = new Node(null, null);
    	// Due to the sentinel node, start at size 1
    	size = 1;
    }

    // is the randomized queue empty?
    public boolean isEmpty() {
    	return size() == 0;
    }

    // return the number of items on the randomized queue
    public int size() {
    	return size - 1;
    }

    // add the item
    public void enqueue(Item item) {
    	if (item == null) {
    		throw new IllegalArgumentException("Item cannot be null!");
    	}
    	
    	Node added = new Node(item, null);
    	
    	// If first item, simply make sentinel point to it
    	if (size == 1) { 
    		sentinel.next = added;
    	} else {
    		// Generate random position from 0 to N items, then travel to that node and add it
    		int i = StdRandom.uniformInt(0, size);
    		Node p = randomNode(i);
    		added.next = p.next;
    		p.next = added;
    	}
    	this.size++;
    }

    // remove and return a random item
    public Item dequeue() {
    	if (size == 1) {
    		throw new NoSuchElementException("Deque Empty!");
    	}
    	this.size--;
    	// Generate random position from 0 to N items, then travel to that node and remove it
    	int i = StdRandom.uniformInt(0, size);
    	Node p = randomNode(i);
    	Item toRemove = p.next.item;
    	p.next = p.next.next;
    	return toRemove;
    }

    // return a random item (but do not remove it)
    public Item sample() {
    	if (size == 1) {
    		throw new NoSuchElementException("Deque Empty!");
    	}
    	// start at 1 due to sentinel node
    	int i = StdRandom.uniformInt(1, size);
    	return randomNode(i).item;
    }
    
    // Loop 'i' times (random number from 0 to size N) and returns the node at that position
    private Node randomNode(int i) {
    	int pos = 0;
    	Node p = sentinel;
    	while (pos < i) {
    		p = p.next;
    		pos++;
    	}
    	return p;
    }

    // return an independent iterator over items in random order
	@Override
	public Iterator<Item> iterator() {
		return new RandomizedQueueIterator();
	}
	
	// Iterator Class with implemented methods
	private class RandomizedQueueIterator implements Iterator<Item> {
		private Node p = sentinel.next;
		
		@Override
		public boolean hasNext() {
			return p != null;
		}
		
		@Override
		public Item next() {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
			Item item = p.item;
			p = p.next;
			return item;
		}
		
		public void remove() {
			throw new UnsupportedOperationException();
		}
		
	}
	
	public static void main(String[] args) {
		RandomizedQueue<Integer> rq = new RandomizedQueue<Integer>();
		rq.enqueue(1);
		rq.enqueue(2);
		rq.enqueue(4);
		rq.enqueue(5);
		rq.enqueue(1);
		rq.enqueue(2);
		rq.enqueue(4);
		rq.enqueue(5);
		System.out.println("size: " + rq.size());
		System.out.println(rq.dequeue());
		System.out.println("size: " + rq.size());
		System.out.println(rq.dequeue());
		System.out.println("size: " + rq.size());
		System.out.println(rq.dequeue());
		System.out.println(rq.sample());
		System.out.println("--");
		//System.out.println(rq.sample());
		Iterator<Integer> rq1 = rq.iterator();
		while (rq1.hasNext()) {
			System.out.println(rq1.next());
		}

	}

}
