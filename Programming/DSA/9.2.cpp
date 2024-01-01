#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

Node* GetNewNode(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = newNode; // Point next to itself to create a single node circular list
    return newNode;
}

void InsertAtEnd(int x) {
    Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while(temp->next != head) temp = temp->next; // Go to last node
        temp->next = newNode;
        newNode->next = head;
    }
}

void InsertBeforePos(int x, int pos) {
    Node* newNode = GetNewNode(x);
    if(head == NULL || pos == 1) {
        newNode->next = head;
        Node* temp = head;
        if(temp != NULL) {
            while(temp->next != head) temp = temp->next;
            temp->next = newNode;
        } else {
            newNode->next = newNode;
        }
        head = newNode;
    } else {
        Node* temp = head;
        int i = 1;
        while(i < pos-1 && temp->next != head) {
            temp = temp->next;
            i++;
        }
        if(temp->next == head && i < pos-1) {
            cout << "Invalid position\n";
            delete newNode;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void DeleteAtHead() {
    if(head == NULL) {
        cout << "The list is already empty\n";
        return;
    }
    if(head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        while(temp->next != head) temp = temp->next;
        Node* toDelete = head;
        head = head->next;
        temp->next = head;
        delete toDelete;
    }
}

void DeleteAfterPos(int pos) {
    if(head == NULL) {
        cout << "The list is already empty\n";
        return;
    }
    Node* temp = head;
    int i = 1;
    while(i < pos && temp->next != head) {
        temp = temp->next;
        i++;
    }
    if(temp->next == head) {
        cout << "Invalid position\n";
    } else {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
}

void Print() {
    if(head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);
    cout << "\n";
}

int main() {
    int choice, value, pos;
    do {
        cout << "\n1. Insert at end\n2. Insert before position\n3. Delete from head\n4. Delete after position\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: cout << "Enter value to be inserted at end: ";
                    cin >> value;
                    InsertAtEnd(value);
                    break;
            case 2: cout << "Enter value to be inserted and position: ";
                    cin >> value >> pos;
                    InsertBeforePos(value, pos);
                    break;
            case 3: DeleteAtHead();
                    break;
            case 4: cout << "Enter position after which to delete: ";
                    cin >> pos;
                    DeleteAfterPos(pos);
                    break;
            case 5: Print();
                    break;
            case 6: break;
            default: cout << "Invalid choice\n";
        }
    } while(choice != 6);

    return 0;
}