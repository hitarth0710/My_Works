#include <stdio.h>
#include <stdlib.h>

struct item {
    int weight;
    int value;
};

// Comparison function for qsort
int compare(const void* a, const void* b) {
    double r1 = (double)((struct item*)a)->value / ((struct item*)a)->weight;
    double r2 = (double)((struct item*)b)->value / ((struct item*)b)->weight;
    return (r1 > r2) ? -1 : 1;
}

// Function to calculate the maximum value that can be put in a knapsack of capacity w
double fractionalknapsack(struct item arr[], int n, int w) {
    qsort(arr, n, sizeof(struct item), compare);

    int curweight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++) {
        if (curweight + arr[i].weight <= w) {
            curweight += arr[i].weight;
            finalvalue += arr[i].value;
        } else {
            int remain = w - curweight;
            finalvalue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    return finalvalue;
}

int main() {
    int W,n;
    printf("enter the capatiy of kanpsack : ");
    scanf("%d",&W);
    printf("Enter the number of items: ");
    scanf("%d",&n);
    struct item* arr = (struct item*)malloc(n*(sizeof(struct item)));
    for(int i = 0; i < n;i++){
        printf("enter weight of item %d: ",i+1);
        scanf("%d",&arr[i].weight);
        printf("enter value of item %d: ",i+1);
        scanf("%d",&arr[i].value);
    }

    double res = fractionalknapsack(arr, n, W);
    printf("The maximum value we can get is %.2f.\n", res);
    return 0;
}