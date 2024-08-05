#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int linear_search(int[], int, int);

int main()
{
    FILE *file;
    file = fopen("numbers.txt","r");
    if(file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int n = 0;
    int temp;
    while(fscanf(file, "%d",&temp) != EOF)
    {
        n++;
    }
    rewind(file);

    int *arr = (int*)malloc(n*sizeof(int));
    for(int i = 0;i<n;i++)
    {
        fscanf(file,"%d",&arr[i]);
    }
    fclose(file);

    int search;
    printf("enter the element you want to search: ");
    scanf("%d",&search);
    clock_t start,end;
    double cpu_time;

    start = clock();
    int res = linear_search(arr,search,n);
    end = clock();
    if (res != -1) {
        printf("Your element is found at index %d.\n", res);
    } else {
        printf("Element not found.\n");
    }
    cpu_time = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Time taken by linear search to find your element is %.5f.",cpu_time);

}

int linear_search(int n[], int ele, int a)
{
    int i;
    for(i = 0;i<a;i++)
    {
        if(n[i] == ele)
        {
            return i;
        }
    }
}