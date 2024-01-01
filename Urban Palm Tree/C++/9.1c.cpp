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
    newNode->next = head;
    newNode->prev = NULL;
    if(head!=NULL)
        head->prev = newNode;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    if(head==NULL)
        return newNode;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void deleteLast(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* cur = head;
    if (head == NULL)
        return;
    while(cur->next) {
      temp = cur;
      cur = cur->next;
    }
    temp->next = NULL;
    free(cur);
    return;
}

struct Node* deletePosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;
    if (temp->next == NULL) {
        printf("Invalid position to delete.\n");
        return head;
    }
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    temp->next->next->prev = temp;
    free(toDelete);
    return head;
}

void traverse(struct Node* head) {
    system("cls");
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, n, data;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert At Front\n");
        printf("2. Insert At End\n");
        printf("3. Delete Last\n");
        printf("4. Delete a specified position\n");
        printf("5. Traverse.\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                head = insertAtFront(head, data);
                system("cls");
                printf("Data inserted at FRONT.\n");
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                system("cls");
                printf("Data inserted at END.\n");
                break;
            case 3:
                deleteLast(head);
                system("cls");
                printf("Last element deleted.\n");
                break;
            case 4:
                printf("Enter position you want to delete: ");
                scanf("%d", &n);
                head = deletePosition(head, n);
                printf("Element at the position is deleted.\n");
                break;
            case 5:
                traverse(head);
                break;
            case 6:
                system("cls");
                printf("Program Exitted");
                exit(1);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}