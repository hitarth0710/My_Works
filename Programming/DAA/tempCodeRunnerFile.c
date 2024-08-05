#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    FILE *fi;
    fi = fopen("numbers.txt","w");
    if(fi == NULL)
    {
        printf("NO file.");
        return 1;
    }

    int limit = 300000;
    int *arr = (int*)malloc(limit * sizeof(int));
    if(arr == NULL)
    {
        printf("memoryy allocation failed");
        return 1;
    }
    for (int  i= 0;i<limit;i++)
    {
        arr[i] = i;
    }
    srand(time(0));
    for(int i = limit - 1;i>0;i--)
    {
        int j = rand()%(i+1);
        int temp = arr[i];
        arr[i]  = arr[j];
        arr[j] = temp;
    }
    for(int i = 0;i<limit;i++)
    {
        fprintf(fi,"%d\n",arr[i]);
    }
    fclose(fi);
    free(arr);
    printf("file created");
    return 0;
}