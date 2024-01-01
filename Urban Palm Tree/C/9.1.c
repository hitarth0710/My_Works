#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtFront(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head) {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head) {
        struct Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    } else {
        head = newNode;
    }
    return head;
}

void deleteLast(struct Node* head) {
    if (head) {
        struct Node* temp = head;
        while (temp->next) temp = temp->next;
        if (temp->prev) temp->prev->next = NULL;
        free(temp);
    }
}

struct Node* deletePosition(struct Node* head, int pos) {
    if (!head) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node* temp = head;
        for (int i = 1; i < pos && temp; i++) temp = temp->next;
        if (temp) {
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            free(temp);
        } else {
            printf("Invalid position to delete.\n");
        }
    }
    return head;
}

void traverse(struct Node* head) {
    system("cls");
    printf("Linked List: ");
    while (head) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\nMenu:\n1. Insert At Front\n2. Insert At End\n3. Delete Last\n");
        printf("4. Delete a specified position\n5. Traverse\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: scanf("%d", &data); head = insertAtFront(head, data); break;
            case 2: scanf("%d", &data); head = insertAtEnd(head, data); break;
            case 3: deleteLast(head); break;
            case 4: scanf("%d", &pos); head = deletePosition(head, pos); break;
            case 5: traverse(head); break;
            case 6: printf("Program Exitted\n"); exit(1);
            default: printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
