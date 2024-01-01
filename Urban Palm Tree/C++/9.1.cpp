#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head; // global variable - pointer to head node.

//Creates a new Node and returns pointer to it. 
Node* GetNewNode(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int x) {
    Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head; 
    head = newNode;
}

void InsertAtTail(int x) {
    Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next; // Go To last Node
    temp->next = newNode;
    newNode->prev = temp;
}

void DeleteAtTail() {
    if(head == NULL) {
        cout << "The list is already empty\n";
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next; // Go To last Node
    temp->prev->next = NULL;
    delete temp;
}

void DeleteBeforePos(int pos) {
    if(head == NULL || pos <= 1) {
        cout << "Invalid position\n";
        return;
    }
    Node* temp = head;
    int i = 1;
    while(i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if(temp == NULL || temp->next == NULL) {
        cout << "Invalid position\n";
        return;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    if(toDelete->next != NULL) {
        toDelete->next->prev = temp;
    }
    delete toDelete;
}

/*

*/
void Print() {
    Node* temp = head;
    cout << "Forward: ";
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    head = NULL; // empty list
    int choice, value, pos;

    do {
        cout << "\n1. Insert at head\n2. Insert at tail\n3. Delete from tail\n4. Delete before position\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: cout << "Enter value to be inserted at head: ";
                    cin >> value;
                    InsertAtHead(value);
                    break;
            case 2: cout << "Enter value to be inserted at tail: ";
                    cin >> value;
                    InsertAtTail(value);
                    break;
            case 3: DeleteAtTail();
                    break;
            case 4: cout << "Enter position before which to delete: ";
                    cin >> pos;
                    DeleteBeforePos(pos);
                    break;
            case 5: Print();
                    break;
            case 6: break;
            default: cout << "Invalid choice\n";
        }
    } while(choice != 6);

    return 0;
}