#include <stdio.h>

#define P 5 // number of processes 
#define R 3 // number of resources

// Function to find the need of each process 
void calculateNeed(int need[P][R], int maxm[P][R], int allot[P][R]) { 
    for (int i = 0; i < P; i++) 
        for (int j = 0; j < R; j++) 
            need[i][j] = maxm[i][j] - allot[i][j]; 
}

// Function to find the system is in safe state or not 
int isSafe(int processes[], int avail[], int maxm[][R], int allot[][R]) { 
    int need[P][R]; 
    calculateNeed(need, maxm, allot);

    int finish[P], safeSeq[P];
    int work[R];
    int count = 0;

    for (int i = 0; i < P; i++) {
        finish[i] = 0;
    }

    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    while (count < P) {
        int found = 0;
        for (int p = 0; p < P; p++) {
            if (finish[p] == 0) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;

                if (j == R) {
                    for (int k = 0; k < R; k++)
                        work[k] += allot[p][k];

                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }

            if (found == 0) {
                printf("System is not in safe state");
                return 0;
            }
        }
    }

    printf("System is in safe state.\nSafe sequence is: ");
    for (int i = 0; i < P; i++)
        printf("%d ", safeSeq[i]);
    printf("\n");

    return 1;
}

int main() {
    int processes[] = {0, 1, 2, 3, 4};
    int avail[] = {3, 3, 2};
    int maxm[][R] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int allot[][R] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};

    isSafe(processes, avail, maxm, allot);

    return 0;
}
