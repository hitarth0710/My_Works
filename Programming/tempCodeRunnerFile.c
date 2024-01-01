#include <stdio.h>
#include <stdlib.h>
int BinarySearch(int arr[], int len, int value) {
    int first, last;
    first = 0; 
    last = len-1;
    while(first<=last) {
        int mid = first + (last-first)/2;
        if(arr[mid]==value)
            return mid;
        else if(arr[mid]<value)
            first = mid + 1;
        else
            last = mid - 1;
    }
    return -1;
}

int main() {
     int len, value, index;
    printf("Enter number of elements in the array: ");
    scanf("%d", &len); 
    int arr[len];

    printf("Enter array elements: ");
    for(int i=0; i<len;i++) {
        int num; 
        scanf("%d", &arr[i]);
    }

    printf("Enter element to be searched: ");
    scanf("%d", &value);
    printf("Through Binary Search:\n");
    index = BinarySearch(arr, len, value);
    if(index==-1)
        printf("%d not found.\n", value);
    else
        printf("%d found at %d index", value, index+1);
    return 0;
}