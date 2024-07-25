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

    start = clock();

    int key,j;
    for(int i = 1;i<SIZE;i++)
    {
        key = arr[i];
        j = i - 1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j + 1]=key;
    }

    end = clock();

/*
    for(int i=0;i<SIZE;i++){
        printf("%d ",arr[i]);
    }
*/

    cpu_time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\nTime taken by Insertion Sort is %.5f seconds.\n",cpu_time);

    return 0;
}

