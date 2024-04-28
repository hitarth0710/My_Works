import java.util.*;

public class Prac9_2 {
    public static void main(String[] args) {
        // Array
        int[] array = {5, 2, 8, 9, 1};
        Arrays.sort(array);
        System.out.println("Sorted Array: " + Arrays.toString(array));

        // ArrayList
        ArrayList<Integer> arrayList = new ArrayList<>(Arrays.asList(5, 2, 8, 9, 1));
        Collections.sort(arrayList);
        System.out.println("Sorted ArrayList: " + arrayList);

        // String
        String str = "dcba";
        char[] charArray = str.toCharArray();
        Arrays.sort(charArray);
        String sortedStr = new String(charArray);
        System.out.println("Sorted String: " + sortedStr);

        // List
        List<String> list = Arrays.asList("Dog", "Cat", "Elephant", "Ant");
        Collections.sort(list);
        System.out.println("Sorted List: " + list);

        // Map
        Map<Integer, String> map = new HashMap<>();
        map.put(3, "Three");
        map.put(1, "One");
        map.put(2, "Two");
        Map<Integer, String> sortedMap = new TreeMap<>(map);
        System.out.println("Sorted Map: " + sortedMap);

        // Set
        Set<Integer> set = new HashSet<>(Arrays.asList(5, 2, 8, 9, 1));
        Set<Integer> sortedSet = new TreeSet<>(set);
        System.out.println("Sorted Set: " + sortedSet);
    }
}
