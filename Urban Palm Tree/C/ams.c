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

void loadDataFromFile(const char* filename, struct Node** root) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        long long enrollment;
        char name[50];
        char date[11];
        char status;

        sscanf(line, "%lld %s %s %c", &enrollment, name, date, &status);

        *root = insert(*root, enrollment, name, status, date);
    }

    fclose(file);
}

void writeNode(FILE* stream, struct Node* node1) {
    if (node1 == NULL) {
        return;
    }

    // Write the node's data and its linked list
    fprintf(stream, "    \"%lld\" [label=\"Enrollment: %lld\\nName: %s\\n", node1->data, node1->data, node1->name);
    struct AttendanceRecord* record = node1->attendance;
    while (record != NULL) {
        fprintf(stream, "Date: %s, Status: %c\\n", record->date, record->status);
        record = record->next;
    }
    fprintf(stream, "\"];\n");

    // Write the edges to the child nodes
    if (node1->left != NULL) {
        fprintf(stream, "    \"%lld\" -> \"%lld\";\n", node1->data, node1->left->data);
        writeNode(stream, node1->left);
    }

    if (node1->right != NULL) {
        fprintf(stream, "    \"%lld\" -> \"%lld\";\n", node1->data, node1->right->data);
        writeNode(stream, node1->right);
    }
}

void writeDot(struct Node* tree, const char* filename) {
    FILE* stream = fopen(filename, "w");

    fprintf(stream, "digraph Tree {\n");
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    if (!tree) {
        fprintf(stream, "\n");
    } else if (!tree->right && !tree->left) {
        fprintf(stream, "    \"%lld\";\n", tree->data);
    } else {
        writeNode(stream, tree);
    }

    fprintf(stream, "}\n");
    fclose(stream);
}


int main() {
    struct Node* root = NULL;
    long choice;
    long long value;
    char name[50], status;
    char date[11]; // Assuming date format "DD-MM-YYYY"
    char c;


        do {
        printf("\nAttendance Management System\n");
        printf("1. Insert Attendance\n");
        printf("2. Delete Enrollment\n");
        printf("3. Search Enrollment\n");
        printf("4. Display Enrollments\n");
        printf("5. Display Attendance for a Date\n");
        printf("6. Generate .dot file\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%ld", &choice);

        switch (choice) {
            case 1:
                printf("Do you want to load data from file? (Y/N): ");
                scanf(" %c%*c", &c); // %*c consumes the newline character
            if(c == 'Y' || c == 'y') {
                loadDataFromFile("data.txt", &root);
            } else {
               printf("Enter Enrollment number to insert: ");
                scanf("%lld", &value);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Status (P for Present, A for Absent): ");
                scanf(" %c%*c", &status); // %*c consumes the newline character
                printf("Enter Date (DD-MM-YYYY): ");
                scanf("%s", date);
                root = insert(root, value, name, status, date);
            }
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
                writeDot(root, "bst.dot");
                printf("Generated bst.dot file.\n");
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);
    

    // Free memory if needed

    return 0;
}
