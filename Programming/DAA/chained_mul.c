#include <stdio.h>
#include <limits.h>

// Function to print the optimal parenthesization of the matrix chain product
void printOptimalParens(int s[][100], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

// Function to find the minimum number of multiplications needed to multiply the chain of matrices
void matrixChainOrder(int p[], int n) {
    int m[100][100];  // m[i][j] will hold the minimum number of multiplications needed to multiply matrices from i to j
    int s[100][100];  // s[i][j] will hold the index of the matrix after which the product is split in an optimal parenthesization

    // cost is zero when multiplying one matrix
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // L is the chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                // q = cost/scalar multiplications
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications is %d\n", m[1][n - 1]);
    printf("Optimal parenthesization is: ");
    printOptimalParens(s, 1, n - 1);
    printf("\n");
}

int main() {
    int arr[] = {6, 3, 2, 4};  // Dimensions of matrices
    int size = sizeof(arr) / sizeof(arr[0]);

    matrixChainOrder(arr, size);

    return 0;
}