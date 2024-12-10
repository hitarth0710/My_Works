#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to sort the array in descending order using bubble sort
void bubbleSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the minimum number of coins needed to make change using dynamic programming
void makeChange(int coins[], int n, int amount) {
    int dp[amount + 1];
    int coinUsed[amount + 1];

    // Initialize dp array
    for (int i = 0; i <= amount; i++) {
        dp[i] = INT_MAX;
        coinUsed[i] = -1;
    }
    dp[0] = 0;

    // Fill dp array
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                if (dp[i] > dp[i - coins[j]] + 1) {
                    dp[i] = dp[i - coins[j]] + 1;
                    coinUsed[i] = coins[j];  // Store the coin value instead of the index
                }
            }
        }
    }

    // Print result
    if (dp[amount] == INT_MAX) {
        printf("No solution possible\n");
        return;
    }

    printf("Minimum number of coins needed: %d\n", dp[amount]);
    printf("Coins used to make change for %d:\n", amount);

    int tempAmount = amount;
    while (tempAmount > 0) {
        int coin = coinUsed[tempAmount];
        printf("%d ", coin);
        tempAmount -= coin;
    }
    printf("\n");
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