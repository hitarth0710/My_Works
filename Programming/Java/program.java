public class program {
    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5};
        int index = 2; // position where new element should be inserted
        int element = 6; // new element to be inserted

        System.out.println("Original array:");
        for (int i : array) {
            System.out.print(i + " ");
        }

        // create a new array of size n+1
        int[] newArray = new int[array.length + 1];

        for (int i = 0; i < newArray.length; i++) {
            if (i < index) {
                newArray[i] = array[i];
            } else if (i == index) {
                newArray[i] = element;
            } else {
                newArray[i] = array[i - 1];
            }
        }

        System.out.println("\nArray after insertion:");
        for (int i : newArray) {
            System.out.print(i + " ");
        }
    }
}