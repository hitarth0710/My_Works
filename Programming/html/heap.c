#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500000

void swap(long *a, long *b) {
    long temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(long arr[], long i, long n) {
    long left = 2 * i + 1;
    long right = 2 * i + 2;
    long largest;
    
    if (left < n && arr[left] > arr[i]) {
        largest = left;
    } else {
        largest = i;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, largest, n);
    }
}

void maxheap(long arr[], long n) {
    for (long i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }
}

void heapsort(long arr[], long n) {
    maxheap(arr, n);
    for (long i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, 0, i);
    }
}

void printArray(long arr[], long n) {
    for (long i = 0; i < n; i++) {
        printf("%ld ", arr[i]);
    }
    printf("\n");
}

int main() {
    long arr[N];
    clock_t start, end;
    double cpu_time_used;

    // Average Case: Random values
    srand(time(0));
    for (long i = 0; i < N; i++) {
        arr[i] = rand() % 100000;
    }

    start = clock();
    heapsort(arr, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Average Case Time: %f seconds\n", cpu_time_used);

    // Best Case: Already sorted
    start = clock();
    heapsort(arr, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Best Case Time: %f seconds\n", cpu_time_used);

    // Worst Case: Sorted in reverse order
    for (long i = 0; i < N / 2; i++) {
        swap(&arr[i], &arr[N - i - 1]);
    }

    start = clock();
    heapsort(arr, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Worst Case Time: %f seconds\n", cpu_time_used);

    return 0;
}