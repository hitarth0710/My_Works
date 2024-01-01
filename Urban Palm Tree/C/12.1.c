#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int len, int data) {
    for(int i=0; i<len; i++)
        if(arr[i]==data)
            return i;
    return -1;
}

int iterativeBinarySearch(int arr[], int len, int data) {
    int low, high;
    low = 0; high = len-1;
    while(low<=high) {
        int mid = low + (high-low)/2;
        if(arr[mid]==data)
            return mid;
        else if(arr[mid]<data)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    printf("Enter number of elements in the array: ");
    int len; scanf("%d", &len); int arr[len];

    printf("Enter array elements: ");
    for(int i=0; i<len;i++) {
        int num; 
        scanf("%d", &arr[i]);
    }

    printf("Enter element to be searched: ");
    int data; scanf("%d", &data);

    int res;
    printf("\nThrough Linear Search:\n");
    res = linearSearch(arr, len, data);
    if(res==-1)
        printf("%d not found.\n", data);
    else
        printf("%d found at %d index", data, res);

    printf("\n\n");
    printf("Through Iterative Binary Search:\n");
    res = iterativeBinarySearch(arr, len, data);
    if(res==-1)
        printf("%d not found.\n", data);
    else
        printf("%d found at %d index", data, res);
    return 0;
}