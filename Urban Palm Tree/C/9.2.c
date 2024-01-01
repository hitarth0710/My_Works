#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert(struct Node **head, int value, int pos) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (!*head) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node *temp = *head;
        for (int i = 1; i < pos - 1; ++i)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;

        if (pos == 1)
            *head = newNode;
    }
}

void delete(struct Node **head, int pos) {
    if (*head) {
        struct Node *temp = *head;
        for (int i = 1; i < pos; ++i)
            temp = temp->next;

        struct Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;

        if (nodeToDelete == *head)
            *head = temp->next;

        free(nodeToDelete);
    }
}

void display(struct Node *head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node *head = NULL;
    int choice, value, pos;

    do {
        printf("\nCircular Linked List Operations:\n1. Insert\n2. Delete\n");
        printf("3. Display\n0. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d %d", &value, &pos);
                insert(&head, value, pos);
                break;
            case 2:
                scanf("%d", &pos);
                delete(&head, pos);
                break;
            case 3:
                display(head);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
    