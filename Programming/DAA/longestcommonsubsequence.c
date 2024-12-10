#include <stdio.h>
#include <string.h>
#include <limits.h>

// Function to find the length of the longest common subsequence
int lcs(char X[], char Y[], int m, int n) {
    int L[m + 1][n + 1];
    
    // Build the L[m+1][n+1] table in bottom-up fashion
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
            }
        }
    }
    
    // L[m][n] contains the length of LCS for X[0..m-1], Y[0..n-1]
    return L[m][n];
}

// Function to print the longest common subsequence
void printLCS(char X[], char Y[], int m, int n) {
    int L[m + 1][n + 1];
    
    // Build the L[m+1][n+1] table in bottom-up fashion
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
            }
        }
    }
    
    // Following code is used to print LCS
    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0'; // Set the terminating character
    
    // Start from the right-most-bottom-most corner and one by one store characters in lcs[]
    int i = m, j = n;
    while (i > 0 && j > 0) {
        // If current character in X[] and Y[] are same, then current character is part of LCS
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1]; // Put current character in result
            i--;
            j--;
            index--; // reduce values of i, j and index
        }
        // If not same, then find the larger of two and go in the direction of larger value
        else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    // Print the lcs
    printf("LCS of %s and %s is %s\n", X, Y, lcs);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    
    printf("Length of LCS is %d\n", lcs(X, Y, m, n));
    printLCS(X, Y, m, n);
    
    return 0;
}