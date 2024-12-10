#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int partition(int arr[], int p, int r){
    int x,temp;
    x = arr[r];
    int i = p - 1;
    for(int j = p;j<=r - 1;j++){
        if(arr[j] <= x){
            i = i + 1;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[r];
    arr[r] = arr[i + 1];
    arr[i + 1] = temp;
    return (i+1);
}

void quicksort(int arr[], int p, int r)
{
    int q;
    if(p < r){
        q = partition(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
    }
}

int binarysearch(int arr[], int low, int high,int key){
    if(low <= high){
        int mid = low + (high - low)/2;
        if (arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            return binarysearch(arr,low,mid - 1,key);
        }
        else if(arr[mid] < key){
            return binarysearch(arr,mid + 1,high,key);
        }
    }
}

int main()
{
    int n;
    int res;
    clock_t start,end;
    double time;
    printf("Enter the size of space :");
    scanf("%d", &n);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        arr[i] = rand() % n;
    }
    int p = 0, r = n - 1;
    quicksort(arr,p,r);
    // for(int i=0;i<n;i++){
    //     printf("%d\n",arr[i]);
    // }
    int key;
    printf("Enter the key you want to find :");
    scanf("%d", &key);
    start = clock();
    res = binarysearch(arr,0,n-1,key);
    end = clock();
    time = ((double)(end - start))/CLOCKS_PER_SEC;
    if(res == -1){
        printf("Element not found in your space.");
    }else{
        printf("Element found at index %d\n.",res);
    }
    printf("time take to search is %.2f\n",time);
    free(arr);
    return 0;
}