#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void heapify(int arr[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to reverse an array
void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
   
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }

    clock_t start, end;
    double cpu_time;

    // Normal input
    start = clock();
    heapSort(arr, n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by heap sort on normal input: %.2f seconds\n", cpu_time);

    // Sorted input
    start = clock();
    heapSort(arr, n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by heap sort on sorted input: %.2f seconds\n", cpu_time);

    // Reverse sorted input
    reverseArray(arr, n);
    start = clock();
    heapSort(arr, n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by heap sort on reverse sorted input: %.2f seconds\n", cpu_time);

    free(arr);
    return 0;
}