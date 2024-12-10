#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L = (int*)malloc((n1 + 1)*sizeof(int));
    int* R = (int*)malloc((n2 + 1)*sizeof(int));
    for(int i = 0;i<n1;i++)
    {
        L[i] = A[p+i];
    }
    for(int j = 0;j<n2;j++)
    {
        R[j] = A[q+j+1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0;
    int j = 0;
    for(int k = p;k<=r;k++)
    {
        if(L[i] <= R[j]){
            A[k] = L[i];
            i = i + 1;
        }
        else{
            A[k] = R[j];
            j = j + 1;
        }
    }

    free(L);
    free(R);
}


void mergesort(int A[], int p, int r)
{
    int q;
    if(p < r){
        q = (p+r)/2;
        mergesort(A,p,q);
        mergesort(A,q+1,r);
        merge(A,p,q,r);
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
    int q = n - 1;

    clock_t start, end;
    double cpu_time;

    start = clock();

    mergesort(arr,p,q);

    end = clock();

    cpu_time = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("time taken by merge sort : %.2f\n",cpu_time);

    // for(int i=0;i<n;i++){
    //     printf("%d\n",arr[i]);
    // }
    clock_t start2, end2;
    double cpu_time2;

    start2 = clock();

    mergesort(arr,p,q);

    end2 = clock();

    cpu_time2 = ((double)(end2 - start2))/CLOCKS_PER_SEC;

    printf("time taken by merge sort in sorted array: %.2f\n",cpu_time2);

    //reverse sorted output
    reversearray(arr,n);
    // for(int i=0;i<n;i++){
    //      printf("%d\n",arr[i]);
    // }
    clock_t start3, end3;
    double cpu_time3;

    start3 = clock();

    mergesort(arr,p,q);

    end3 = clock();

    cpu_time3 = ((double)(end3 - start3))/CLOCKS_PER_SEC;

    printf("time taken by merge sort in reverse sorted array: %.2f\n",cpu_time3);
    free(arr);
    return 0;
}