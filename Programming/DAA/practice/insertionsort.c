#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionsort(int arr[], int n){
    for(int i = 1 ; i < n;i++){
        int key = arr[i];
        int j = i - 1;
        while(arr[j] > key && j>=0){
            arr[j+1] = arr[j];
            j = j - 1; 
        }
        arr[j+1] = key;
    }
}

void reversearray(int arr[], int n){
    for(int i = 0;i < n/2; i++){
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n*sizeof(int));
    //generating random numbers
    for(int i=0; i < n;i++){
        arr[i] = rand() % n;
    }

    clock_t start, end;
    double cpu_time;

    start = clock();

    insertionsort(arr, n);

    end = clock();

    cpu_time = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("time taken by insertion sort : %.2f seconds\n",cpu_time);

    // for(int i=0;i<n;i++){
    //     printf("%d\n",arr[i]);
    // }
    clock_t start2, end2;
    double cpu_time2;

    start2 = clock();

    insertionsort(arr, n);

    end2 = clock();

    cpu_time2 = ((double)(end2 - start2))/CLOCKS_PER_SEC;

    printf("time taken by insertion sort in sorted array: %.2f seconds\n",cpu_time2);

    //reverse sorted output
    reversearray(arr,n);
    // for(int i=0;i<n;i++){
    //      printf("%d\n",arr[i]);
    // }
    clock_t start3, end3;
    double cpu_time3;

    start3 = clock();

    insertionsort(arr, n);

    end3 = clock();

    cpu_time3 = ((double)(end3 - start3))/CLOCKS_PER_SEC;

    printf("time taken by insertion sort in reverse sorted array: %.2f seconds\n",cpu_time3);
    free(arr);
    return 0;
}