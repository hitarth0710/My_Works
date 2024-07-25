#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    
    int SIZE;
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &SIZE);

    int* arr = (int*)malloc(SIZE * sizeof(int));
    for(int i=0;i<SIZE;i++){
        arr[i] = rand() % SIZE;
    }
    
    clock_t start, end;
    double cpu_time;

    //int arr[] = {5,1,3,2,4};

    start = clock();

    int smallest;
    int n = SIZE;
    int temp;
    for(int j = 0;j<(n - 1);j++)
    {
        smallest = j;
        for(int i = (j + 1);i<n;i++)
        {
            if(arr[i] < arr[smallest])
            {
                smallest = i;
            }
        }
        temp = arr[j];
        arr[j] = arr[smallest];
        arr[smallest] = temp;
    }

    end = clock();


    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }


    cpu_time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\nTime taken by Insertion Sort is %.5f seconds.\n",cpu_time);

    return 0;
}

