#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == x)
            return i;
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

    key = arr[0];
    start = clock();
    linearSearch(arr, n, key);
    end = clock();
    printf("Best Case Time: %lf microseconds\n", (double)(end - start) / CLOCKS_PER_SEC * 1e6);

    key = -1;
    start = clock();
    linearSearch(arr, n, key);
    end = clock();
    printf("Worst Case Time: %lf microseconds\n", (double)(end - start) / CLOCKS_PER_SEC * 1e6);

    srand(time(0));
    key = arr[rand() % n];
    start = clock();
    linearSearch(arr, n, key);
    end = clock();
    printf("Average Case Time: %lf microseconds\n", (double)(end - start) / CLOCKS_PER_SEC * 1e6);

    free(arr);
    return 0;
} 