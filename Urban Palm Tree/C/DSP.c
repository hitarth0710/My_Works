#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct AttendanceRecord {
    char date[11]; // Assuming date format "DD-MM-YYYY"
    long long enrollment;
    char status; // 'P' for Present, 'A' for Absent
    struct AttendanceRecord* next;
};

struct Node {
    long long data;
    char name[50];
    struct AttendanceRecord* attendance; // List of attendance records
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(long long value, const char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    strcpy(newNode->name, name);
    newNode->attendance = NULL;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct AttendanceRecord* addAttendance(struct AttendanceRecord* attendance, long long enrollment, char status, const char* date) {
    struct AttendanceRecord* newRecord = (struct AttendanceRecord*)malloc(sizeof(struct AttendanceRecord));
    strcpy(newRecord->date, date);
    newRecord->enrollment = enrollment;
    newRecord->status = status;
    newRecord->next = attendance;
    return newRecord;
}

struct Node* insert(struct Node* root, long long value, const char* name, char status, const char* date) {
    if (root == NULL) {
        root = createNode(value, name);
        root->attendance = addAttendance(NULL, value, status, date);
    } else if (value < root->data) {
        root->left = insert(root->left, value, name, status, date);
    } else if (value > root->data) {
        root->right = insert(root->right, value, name, status, date);
    } else {
        root->attendance = addAttendance(root->attendance, value, status, date);
    }

    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    /*This function is typically used in the process of deleting a node from a BST. 
    When the node to be deleted has two children, we can't simply remove the node. One common strategy is
    to replace the node with either the largest node from its left subtree or the smallest node from its right subtree. 
    The minValueNode function can be used to find this replacement node when we choose to use the smallest node from the right 
    subtree
    */
    return current;
}

struct Node* deleteNode(struct Node* root, long long value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        strcpy(root->name, temp->name);
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}

struct Node* search(struct Node* root, long long value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    }

    return search(root->right, value);
}

void displayAttendanceForDay(struct Node* root, const char* day) {
    if (root != NULL) {
        displayAttendanceForDay(root->left, day);
        struct AttendanceRecord* currentRecord = root->attendance;
        while (currentRecord != NULL) {
            if (strcmp(currentRecord->date, day) == 0) {
                printf("Enroll: %lld, Name: %s, Status: %c, Date: %s\n", currentRecord->enrollment, root->name, currentRecord->status, currentRecord->date);
            }
            currentRecord = currentRecord->next;
        }
        displayAttendanceForDay(root->right, day);
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Enroll: %lld, Name: %s\n", root->data, root->name);
        struct AttendanceRecord* currentRecord = root->attendance;
        while (currentRecord != NULL) {
            printf("Date: %s, Status: %c\n", currentRecord->date, currentRecord->status);
            currentRecord = currentRecord->next;
        }
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    long choice;
    long long value;
    char name[50], status;
    char date[11]; // Assuming date format "DD-MM-YYYY"

    do {
        printf("\nAttendance Management System\n");
        printf("1. Insert Attendance\n");
        printf("2. Delete Enrollment\n");
        printf("3. Search Enrollment\n");
        printf("4. Display Enrollments\n");
        printf("5. Display Attendance for a Date\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%ld", &choice);

        switch (choice) {
            case 1:
                printf("Enter Enrollment number to insert: ");
                scanf("%lld", &value);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Status (P for Present, A for Absent): ");
                scanf(" %c%*c", &status); // %*c consumes the newline character
                printf("Enter Date (DD-MM-YYYY): ");
                scanf("%s", date);
                root = insert(root, value, name, status, date);
                break;
            case 2:
                printf("Enter Enrollment number to delete: ");
                scanf("%lld", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Enter Enrollment number to search: ");
                scanf("%lld", &value);
                struct Node* searchResult = search(root, value);
                if (searchResult != NULL) {
                    printf("%lld Enrollment number found.\n", value);
                    struct AttendanceRecord* currentRecord = searchResult->attendance;
                    while (currentRecord != NULL) {
                        printf("Date: %s, Status: %c\n", currentRecord->date, currentRecord->status);
                        currentRecord = currentRecord->next;
                    }
                } else {
                    printf("%lld Enrollment number not found.\n", value);
                }
                break;
            case 4:
                printf("In-order traversal:\n");
                inorderTraversal(root);
                break;
            case 5:
                printf("Enter Date to display attendance: ");
                scanf("%s", date);
                displayAttendanceForDay(root, date);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    // Free memory if needed

    return 0;
}
