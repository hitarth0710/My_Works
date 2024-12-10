#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void selectionSort(int* arr, int size) {
    int smallest, temp;
    for (int j = 0; j < (size - 1); j++) {
        smallest = j;
        for (int i = (j + 1); i < size; i++) {
            if (arr[i] < arr[smallest]) {
                smallest = i;
            }
        }
        temp = arr[j];
        arr[j] = arr[smallest];
        arr[smallest] = temp;
    }
}

int main() {
    int SIZE;
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &SIZE);

    int* arr = (int*)malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % SIZE;
    }

    clock_t start, end;
    double cpu_time;

    // Sort the array and measure the time
    start = clock();
    selectionSort(arr, SIZE);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken by Selection Sort for random array is %.5f seconds.\n", cpu_time);

    clock_t start1, end1;
    double cpu_time1;
    start1 = clock();
    selectionSort(arr , SIZE);
    end1 = clock();
    cpu_time1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
    printf("\nTime taken by Selection Sort for sorted array is %.5f seconds.\n", cpu_time1);

    // Reverse the sorted array
    reverseArray(arr, SIZE);

    // Measure the time to sort the reverse sorted array
    clock_t start2, end2;
    double cpu_time2;
    start2 = clock();
    selectionSort(arr, SIZE);
    end2 = clock();
    cpu_time2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
    printf("\nTime taken by Selection Sort for reverse sorted array is %.5f seconds.\n", cpu_time2);

    free(arr);
    return 0;
}
