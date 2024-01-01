//program to demonstrate random function and file in same program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int l, int r, int key) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == key) {
            return m;
        }
        if (arr[m] < key) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int main() {
    srand(time(0)); // Use current time as seed for random generator

     FILE *file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Could not open file numbers.txt");
        return 1;
    }

    int arr[1000000], key, n = 0;
    for (int i = 0; i < 1000000; i++) {
        arr[i] = rand() % 1000000 + 1; // Generate a random number between 1 and 1000000
        fprintf(file, "%d ", arr[i]); // Write the number to the file
        n++;
    }
    fclose(file);

    //key = rand() % 1000000 + 1; // Generate a random key to search
    printf("Enter the element to search: ");
    scanf("%d", &key);
    printf("Searching for the element: %d\n", key);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int result = linearSearch(arr, n, key);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for linear search: %f seconds\n", cpu_time_used);
    if (result != -1) {
        printf("Element %d found at index %d using linear search\n", key, result);
    } else {
        printf("Element %d not found in the array using linear search\n", key);
    }

    start = clock();
    result = binarySearch(arr, 0, n - 1, key);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for binary search: %f seconds\n", cpu_time_used);
    if (result != -1) {
        printf("Element %d found at index %d using binary search\n", key, result);
    } else {
        printf("Element %d not found in the array using binary search\n", key);
    }

    return 0;
}