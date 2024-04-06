#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Add missing import

#define MAX_PROCS 5
#define MAX_RESOURCES 3

int matrix[MAX_PROCS][MAX_RESOURCES]; // Resource Requirements and Allocation Matrix
int need[MAX_PROCS][MAX_RESOURCES]; // Need Matrix
int available[MAX_RESOURCES]; // Available resources

void print_state(char state[]) {
    printf("\nState: %s\n", state);
}

int can_grant_resources(int pid, int resources[]); // Forward declaration

int grantResources(int pid, int resources[]) {
    int sum = 0;
    for (int i = 0; i < MAX_RESOURCES; i++) {
        sum += fabs(matrix[pid][i] - resources[i]);
    }

    if (sum <= available[0]) {
        for (int i = 0; i < MAX_RESOURCES; i++) {
            available[i] -= resources[i];
            matrix[pid][i] += resources[i];
            need[pid][i] -= resources[i];
        }
        return 1;
    }
    return 0;
}

int check_deadlock() {
    int need_matrix[MAX_PROCS][MAX_RESOURCES]; // Need Matrix for all processes

    // Fill Need Matrix with current resource needs
    for (int i = 0; i < MAX_PROCS; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need_matrix[i][j] = matrix[i][j] - available[j];
        }
    }

    // Check for deadlock using the Need Matrix and Available resources
    int resources_requested[MAX_PROCS][MAX_RESOURCES];
    for (int i = 0; i < MAX_PROCS; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            resources_requested[i][j] = need_matrix[i][j];
        }
    }

    int can_grant[MAX_PROCS]; // Indicates if a process can be granted resources or not

    for (int i = 0; i < MAX_PROCS; i++) {
        if (!can_grant_resources(i, resources_requested[i])) {
            print_state("Deadlock detected\n");
            return 1; // Deadlock detected
        }
    }

    print_state("No deadlock present.\n"); // No deadlock present
    return 0; // Add return statement
}

int can_grant_resources(int pid, int resources[]) {
    for (int i = 0; i < MAX_RESOURCES; i++) {
        if (resources[i] < 0 && available[i] < 0) {
            return 0; // Insufficient resources to grant the request
        } else if (resources[i] > 0 && available[i] < resources[i]) {
            return 0; // Insufficient resources available to grant the request
        }
    }

    return 1; // Resources can be granted
}

int main() 
{
    int choice;
    printf("Banker's Algorithm\n");
    printf("Choose The state :\n");
    printf("1. Deadlock\n");
    printf("2. No Deadlock\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch(choice) 
    {
                    case 1:
                        //print_state("Deadlock");
                        // Initialize Resource Requirements and Allocation Matrix
                        matrix[0][0] = 2; matrix[0][1] = 1; matrix[0][2] = 3;
                        matrix[1][0] = 1; matrix[1][1] = 2; matrix[1][2] = 3;
                        matrix[2][0] = 3; matrix[2][1] = 3; matrix[2][2] = 1;
                        matrix[3][0] = 2; matrix[3][1] = 1; matrix[3][2] = 2;
                        matrix[4][0] = 1; matrix[4][1] = 2; matrix[4][2] = 1;

                        // Initialize Available resources
                        available[0] = 3; available[1] = 2; available[2] = 1;

                        // Call the function to check for deadlock
                        check_deadlock();

                        break;
                    case 2:
                        //print_state("No Deadlock");
                        // Initialize Resource Requirements and Allocation Matrix
                        matrix[0][0] = 2; matrix[0][1] = 1;
                        matrix[1][0] = 1; matrix[1][1] = 2;
                        matrix[2][0] = 3; matrix[2][1] = 3;
                        matrix[3][0] = 2; matrix[3][1] = 1;
                        matrix[4][0] = 1; matrix[4][1] = 2;

                        // Initialize Available resources
                        available[0] = 3; available[1] = 2;

                        // Call the function to check for deadlock
                        check_deadlock();
                        break;
                    default:
                        print_state("Invalid choice");
                        break;
    }
    return 0;
}
