#include <stdio.h>

void quicksort(int n[], int p, int r);
int partition(int n[], int p, int r);
void swaping(int n[], int i, int j);

int main() {
    // Example usage
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void quicksort(int n[], int p, int r) {
    int q;
    if (p < r) {
        q = partition(n, p, r);
        quicksort(n, p, q - 1);
        quicksort(n, q + 1, r);
    }
}

int partition(int n[], int p, int r) {
    int x = n[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (n[j] <= x) {
            i = i + 1;
            swaping(n, i, j);
        }
    }
    swaping(n, i + 1, r);
    return (i + 1);
}

void swaping(int n[], int i, int j) {
    int temp = n[i];
    n[i] = n[j];
    n[j] = temp;
}