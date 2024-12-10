#include <stdio.h>
#include <stdlib.h>

// Function to sort the array in descending order using bubble sort
void bubbleSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the minimum number of coins needed to make change
void makeChange(int coins[], int n, int amount) {
    int count = 0;
    printf("Coins used to make change for %d:\n", amount);
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            printf("%d ", coins[i]);
            count++;
        }
    }
    printf("\nTotal coins used: %d\n", count);
}

int main() {
    int n, amount;

    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    int* coins = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Enter denomination %d: ", i + 1);
        scanf("%d", &coins[i]);
    }

    printf("Enter the amount to make change for: ");
    scanf("%d", &amount);

    // Sort the coin denominations in descending order using bubble sort
    bubbleSortDescending(coins, n);

    makeChange(coins, n, amount);

    free(coins);  // Free the allocated memory
    return 0;
}