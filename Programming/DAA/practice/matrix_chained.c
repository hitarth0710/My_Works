#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printoptimalparen(int s[][100], int i, int j){
    if(i==j){
        printf("A%d",i);
    }
    else{
        printf("(");
        printoptimalparen(s,i,s[i][j]);
        printoptimalparen(s,s[i][j] + 1,j);
        printf(")");
    }
}

void matrixchainorder(int arr[], int n){
    int m[100][100];
    int s[100][100];

    for(int i = 0;i<n;i++){
        m[i][i] = 0;
    }


    for(int L = 2 ; L < n ;L++){
        for (int i = 1; i < n - L + 1;i++){
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for(int k = i;k <= j - 1;k++){
                int q = m[i][k] + m[k+1][j] + (arr[i-1]*arr[k]*arr[j]);
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Min no. of multiplication required are %d\n",m[1][n-1]);
    printf("Optimal Parenthisis is :\n");
    printoptimalparen(s,1,n-1);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int* arr = (int*)malloc((n + 1) * sizeof(int));

    printf("Enter the dimensions of the matrices:\n");
    for (int i = 0; i <= n; i++) {
        printf("Dimension %d: ", i);
        scanf("%d", &arr[i]);
    }

    matrixchainorder(arr,n+1);
    free(arr);
    return 0;
}