#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Function to compare items based on value/weight ratio
int compare(const void* a, const void* b) {
    double r1 = (double)((struct Item*)a)->value / ((struct Item*)a)->weight;
    double r2 = (double)((struct Item*)b)->value / ((struct Item*)b)->weight;
    return (r1 > r2) ? -1 : 1;
}

// Function to calculate the maximum value that can be put in a knapsack of capacity W
double fractionalKnapsack(int W, struct Item arr[], int n) {
    // Sort items by value/weight ratio
    qsort(arr, n, sizeof(struct Item), compare);

    int curWeight = 0;  // Current weight in knapsack
    double finalValue = 0.0;  // Result (value in knapsack)

    // Loop through all items
    for (int i = 0; i < n; i++) {
        // If adding the item doesn't exceed capacity, add it completely
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        // If we can't add the current item, add fractional part of it
        else {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    int W = 50;  // Knapsack capacity
    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum value in Knapsack = %.2f\n", fractionalKnapsack(W, arr, n));
    return 0;
}