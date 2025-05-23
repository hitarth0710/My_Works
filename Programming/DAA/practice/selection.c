#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionsort(int arr[], int n){
    int minx, temp;
    for(int i = 0; i < n - 1; i++)
    {
        minx = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minx]){
                minx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minx];
        arr[minx] = temp;
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

    selectionsort(arr, n);

    end = clock();

    cpu_time = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("time taken by selection sort : %.2f seconds\n",cpu_time);

    // for(int i=0;i<n;i++){
    //     printf("%d\n",arr[i]);
    // }
    clock_t start2, end2;
    double cpu_time2;

    start2 = clock();

    selectionsort(arr, n);

    end2 = clock();

    cpu_time2 = ((double)(end2 - start2))/CLOCKS_PER_SEC;

    printf("time taken by selection sort in sorted array: %.2f seconds\n",cpu_time2);

    //reverse sorted output
    reversearray(arr,n);
    // for(int i=0;i<n;i++){
    //      printf("%d\n",arr[i]);
    // }
    clock_t start3, end3;
    double cpu_time3;

    start3 = clock();

    selectionsort(arr, n);

    end3 = clock();

    cpu_time3 = ((double)(end3 - start3))/CLOCKS_PER_SEC;

    printf("time taken by selection sort in reverse sorted array: %.2f seconds\n",cpu_time3);

    free(arr);
    return 0;
}