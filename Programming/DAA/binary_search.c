#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int binary_search(int arr[], int low, int high, int target);
void MergeSort(int[], int , int );
void Merge(int[], int, int, int );

int main()
{
    
    FILE *file;
    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int n = 0;
    int temp;
    while (fscanf(file, "%d", &temp) != EOF) {
        n++;
    }
    rewind(file);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        fclose(file);
        return 1;
    }
    // Read integers from the file into the array
    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            printf("Error reading file!\n");
            free(arr);
            fclose(file);
            return 1;
        }
    }
    fclose(file);

    MergeSort(arr,0,n-1);
    
    int search;
    printf("Enter the element you want to search: ");
    scanf("%d", &search);

    clock_t start, end;
    double cpu_time;

    start = clock();
    int res = binary_search(arr, 0, n - 1, search);
    end = clock();

    if (res != -1) {
        printf("Your element is found at index %d.\n", res);
    } else {
        printf("Element not found.\n");
    }

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by binary search to find your element is %.5f seconds.\n", cpu_time);

    free(arr);
    return 0;
}

int binary_search(int arr[], int low, int high, int target)
{
    //MergeSort(arr,low,high);
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            return binary_search(arr, mid + 1, high, target); // Search in the right half
        } else {
            return binary_search(arr, low, mid - 1, target); // Search in the left half
        }
    }

    return -1; // Target not found
}

void MergeSort(int A[], int p, int r)
{
    int q;
    if(p < r){
        q = (p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}

void Merge(int A[], int p, int q, int r)
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

