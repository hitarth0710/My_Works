#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MergeSort(int[], int , int );
void Merge(int[], int, int, int );

int main()
{
    int SIZE;
    printf("Enter size of array: ");
    scanf("%d",&SIZE);
    int *arr = (int*)malloc(SIZE*sizeof(int));

    for(int i = 0;i<SIZE;i++)
    {
        arr[i] = rand() % SIZE;
    }

    int p = arr[0];
    int r = arr[SIZE - 1];

    clock_t start,end;
    double cpu_time;

    start = clock();

    MergeSort(arr,p,r);

    end = clock();

    for(int t = 0 ;t<SIZE;t++){
        printf("%d",arr[t]);
    }

    cpu_time = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Time taken by MergeSort is %.5f.\n",cpu_time);

    return 0;
}

void MergeSort(int* A, int p, int r)
{
    int q;
    if(p<r){
        q = (p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}

void Merge(int* A, int p, int q, int r)
{
    int* L = (int*)malloc(sizeof(int));
    int* R = (int*)malloc(sizeof(int));
    int n1,n2;
    n1 = q - p + 1;
    n2 = r - q;
    for(int i = 1;i<n1;i++)
    {
        L[i] = A[p+i-1];
    }
    for(int i = 1;i<n2;i++)
    {
        R[i] = A[q+i];
    }
    L[n1+1] = 999999;
    R[n2+1] = 999999;
    int i = 0;
    int j = 0;
    for(int k = p;k<r;k++)
    {
        if(L[i] <= R[j]){
            A[k] = L[i];
            i = i + 1;
        }else{
            A[k] = R[j];
            j = j + 1;
        }
    }
}
