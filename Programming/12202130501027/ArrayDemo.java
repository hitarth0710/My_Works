class Array {

    int data[] = new int[10]; 
    float sum = 0; 
    float avg = 0; 
    int n = 10; 
    Array() 
    { 
        for (int i = 0; i < n; i++) 
        { 
            data[i] = 0; 
        } 
    } 
    Array(int size)
    { 
        n = size; 
        for (int i = 0; i < n; i++) 
        { 
            data[i] = 0; 
        } 
    } 
    Array(int a[])  
    { 
        n = a.length; 
        for (int i = 0; i < n; i++) 
        { 
            data[i] = a[i]; 
        } 
    } 
    void sum() 
    { 
        for (int i = 0; i < n; i++) 
        { 
            sum = sum + data[i]; 
        } 
        System.out.println("Sum of Elements are:" + sum); 
    } 
    void average()
    { 
        avg = sum/n; 
    System.out.println("Average of elements are: " + avg);
    }

    void display() {
        System.out.println("Elements Are:");
        for (int i = 0; i < n; i++) {
            System.out.print(data[i] + " ");
        }
        System.out.println(" ");
        System.out.println("Sum of Elements are:" + sum);
        System.out.println("Average of elements are: " + avg);
    }

    void search_data(int num) {
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (data[i] == num) {
                flag = 1;
                System.out.println("Found element " + num + " at " + i + " index");
                break;
            }
        }
        if (flag == 0) {
            System.out.println("Element not Found");
        }
    }

    void reverse_an_array() {
        System.out.println("Reverse Of An Array:");
        for (int i = n - 1; i >= 0; i--) {
            System.out.print(data[i] + " ");
        }
        System.out.println("  ");
    }

    void maximum_of_array() {
        int max = data[0];
        for (int i = 0; i < n; i++) {
            if (data[i] > max) {
                max = data[i];
            }
        }
        System.out.println("Maximum element in the array is: " + max);
    }

    void sorted_data() {
        int temp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (data[i] > data[j]) {
                    temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
        System.out.println("Elements after Array is Sorted are");
        for (int i = 0; i < n; i++) {
            System.out.print(data[i] + " ");
        }
        System.out.println(" ");
    }
    }
    
class ArrayDemo { 
    public static void main(String[] args) 
    { 
        int a[] = {4,3,2,1,5,6,8,7,9}; 
        Array a1 = new Array(); 
        Array a2 = new Array(9);  
        Array a3 = new Array(a); 
        a1.display();
        a2.display();
        a3.sum(); 
        a3.average(); 
        a3.search_data(1); 
        a3.maximum_of_array(); 
        a3.display(); 
        a3.reverse_an_array(); 
        a3.sorted_data(); 
    } 
} 
    