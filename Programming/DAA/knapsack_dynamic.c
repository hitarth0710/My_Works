#include <stdio.h>
#include <stdlib.h>

int maxx(int, int);
int knapsack(int, int[], int[], int);

int main()
{
    int cap,n;
    printf("Enter the capaticy of knapsack: ");
    scanf("%d",&cap);
    printf("Enter the number of element: ");
    scanf("%d",&n);
    int* weights = (int*)malloc(n*sizeof(int));
    int* values = (int*)malloc(n*sizeof(int));
    for(int i = 0 ;i<n;i++)
    {
        printf("Enter %d element weight:",(i+1));
        scanf("%d",&weights[i]);
        printf("Enter %d values value:",(i+1));
        scanf("%d",&values[i]);
    }

    int max_val = knapsack(cap,weights,values,n);
    printf("Maximum value of Knapsack is %d",max_val);

    free(values);
    free(weights);
    return 0;
}

int maxx(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

int knapsack(int cap, int weights[], int values[], int n)
{
    int a=n+1;
    int b=cap+1;
    int **V = (int **)malloc(a*sizeof(int *));
    for(int i =0 ;i<a;i++)
    {
        V[i] = (int *)malloc(b*sizeof(int));
    }
    //initialize the first row and first col
    for(int w = 0 ; w <= cap ;w++)
    {
        V[0][w] = 0;
    }
    for(int i = 0; i<=n;i++)
    {
        V[i][0] = 0;
    }

    //build the v array in bottom-up way
    for(int i = 1; i<=n;i++)
    {
        for(int w = 0;w<=cap;w++)
        {
            if(weights[i - 1] <= w)// item i can be in the solution
            {
                if(values[i - 1] + V[i-1][w - weights[i - 1]] > V[i-1][w])
                {
                    V[i][w] = values[i - 1] + V[i - 1][w - weights[i - 1]];
                }else{
                    V[i][w] = V[i-1][w];
                }
            }else{
                V[i][w] = V[i-1][w];
            }
        }
    }
    int result = V[n][cap];
    //print tha table
    printf("Knapsack Table\n");
    for(int i = 0; i<=n;i++)
    {
        for(int w=0;w<=cap;w++)
        {
            printf("%d\t",V[i][w]);
        }
        printf("\n");
    }
    //backtracing
    int k=cap;
    int i=n;
    printf("Items to be included in knapsack:\n");
    while(i>0 && k>0)
    {
        if(V[i][k] != V[i-1][k]){
            printf("Item %d (weight: %d and value: %d)\n",i,weights[i-1],values[i-1]);
            k = k - weights[i-1];
        }
        i--;
    }

    return result;
}