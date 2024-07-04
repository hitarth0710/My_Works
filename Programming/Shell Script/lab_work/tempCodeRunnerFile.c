#include <stdio.h>

#define MAX 100

void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[]) {
    wt[0] = 0;
    for (int i = 1; i < n ; i++ )
        wt[i] = bt[i-1] + wt[i-1] - at[i];
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

void findAverageTime(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt, at);
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes    Burst Time     Waiting Time     Turn-Around Time\n");

    for (int i=0; i<n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("   %d", i+1);
        printf("       %d", bt[i]);
        printf("              %d", wt[i]);
        printf("                   %d\n", tat[i]);
    }

    printf("Average waiting time = %.1f", (float)total_wt / n);
    printf("\nAverage turn around time = %.1f", (float)total_tat / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burst_time[n];
    int arrival_time[n];

    for(int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &burst_time[i]);
        printf("Enter arrival time for process %d: ", i+1);
        scanf("%d", &arrival_time[i]);
        processes[i] = i+1;
    }

    findAverageTime(processes, n, burst_time, arrival_time);

    return 0;
}