#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int partition(int arr[], int p, int r){
    int x;
    x = arr[r];//pivot element
    int i = p - 1;
    int temp;
    for(int j = p ;j <= r - 1;j++){
        if(arr[j] <= x){
            i = i + 1;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[r];
    arr[r] = arr[i+1];
    arr[i+1] = temp;
    return (i+1);
}

void quicksort(int arr[], int p, int r){
    int q;
    if(p < r){
        q = partition(arr,p,r);
        quicksort(arr,p,q - 1);
        quicksort(arr,q + 1,r);
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

    int p = 0;
    int r = n - 1;
    clock_t start, end;
    double cpu_time;

    start = clock();

    quicksort(arr,p,r);

    end = clock();

    cpu_time = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("time taken by quick sort : %.2f\n",cpu_time);

    // for(int i=0;i<n;i++){
    //     printf("%d\n",arr[i]);
    // }
    clock_t start2, end2;
    double cpu_time2;

    start2 = clock();

    quicksort(arr,p,r);

    end2 = clock();

    cpu_time2 = ((double)(end2 - start2))/CLOCKS_PER_SEC;

    printf("time taken by quick sort in sorted array: %.2f\n",cpu_time2);

    //reverse sorted output
    reversearray(arr,n);
    // for(int i=0;i<n;i++){
    //      printf("%d\n",arr[i]);
    // }
    clock_t start3, end3;
    double cpu_time3;

    start3 = clock();

    quicksort(arr,p,r);

    end3 = clock();

    cpu_time3 = ((double)(end3 - start3))/CLOCKS_PER_SEC;

    printf("time taken by insertion sort in reverse sorted array: %.2f\n",cpu_time3);
    free(arr);
    return 0;
}