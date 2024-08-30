#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int key, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    clock_t start, end;
    int n, key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }

    key = arr[n / 2];
    start = clock();
    binarySearch(arr, key, 0, n - 1);
    end = clock();
    printf("Best Case Time: %lf microseconds\n", (double)(end - start) / CLOCKS_PER_SEC * 1e6);

    key = -1;
    start = clock();
    binarySearch(arr, key, 0, n - 1);
    end = clock();
    printf("Worst Case Time: %lf microseconds\n", (double)(end - start) / CLOCKS_PER_SEC * 1e6);

    srand(time(0));
    key = arr[rand() % n];
    start = clock();
    binarySearch(arr, key, 0, n - 1);
    end = clock();
    printf("Average Case Time: %lf microseconds\n", (double)(end - start) / CLOCKS_PER_SEC * 1e6);

    free(arr);
    return 0;
}