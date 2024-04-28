import java.util.*;

public class Prac9_1 {
    public static void main(String[] args) {
        // ArrayList
        List<String> arrayList = new ArrayList<>();
        arrayList.add("Apple"); // Create
        arrayList.add("Banana");
        arrayList.add("Cherry");
        System.out.println("ArrayList: " + arrayList); // Read
        arrayList.set(1, "Blueberry"); // Update
        System.out.println("ArrayList after update: " + arrayList);
        arrayList.remove("Cherry"); // Delete
        System.out.println("ArrayList after delete: " + arrayList);

        // LinkedList
        List<String> linkedList = new LinkedList<>();
        linkedList.add("Dog"); // Create
        linkedList.add("Elephant");
        linkedList.add("Frog");
        System.out.println("\nLinkedList: " + linkedList); // Read
        linkedList.set(1, "Eagle"); // Update
        System.out.println("LinkedList after update: " + linkedList);
        linkedList.remove("Frog"); // Delete
        System.out.println("LinkedList after delete: " + linkedList);

        // LinkedHashMap
        Map<String, Integer> linkedHashMap = new LinkedHashMap<>();
        linkedHashMap.put("One", 1); // Create
        linkedHashMap.put("Two", 2);
        linkedHashMap.put("Three", 3);
        System.out.println("\nLinkedHashMap: " + linkedHashMap); // Read
        linkedHashMap.put("Two", 22); // Update
        System.out.println("LinkedHashMap after update: " + linkedHashMap);
        linkedHashMap.remove("Three"); // Delete
        System.out.println("LinkedHashMap after delete: " + linkedHashMap);

        // TreeMap
        Map<String, Integer> treeMap = new TreeMap<>();
        treeMap.put("One", 1); // Create
        treeMap.put("Two", 2);
        treeMap.put("Three", 3);
        System.out.println("\nTreeMap: " + treeMap); // Read
        treeMap.put("Two", 22); // Update
        System.out.println("TreeMap after update: " + treeMap);
        treeMap.remove("Three"); // Delete
        System.out.println("TreeMap after delete: " + treeMap);

        // HashSet
        Set<String> hashSet = new HashSet<>();
        hashSet.add("Red"); // Create
        hashSet.add("Green");
        hashSet.add("Blue");
        System.out.println("\nHashSet: " + hashSet); // Read
        hashSet.remove("Blue"); // Delete
        System.out.println("HashSet after delete: " + hashSet);
    }
}