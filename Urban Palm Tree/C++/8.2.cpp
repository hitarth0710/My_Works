#include<iostream>
#include<cstdlib>

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void dequeue() {
    Node* temp = front;
    if(front == NULL) {
        std::cout << "Queue is Empty\n";
        return;
    }
    if(front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
    }
    delete temp;
}

void display() {
    Node* temp = front;
    while(temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

int main() {
    int choice, value;
    do {
        std::cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        std::cin >> choice;
        switch(choice) {
            case 1: std::cout << "Enter value to be enqueued: ";
                    std::cin >> value;
                    enqueue(value);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: break;
            default: std::cout << "Invalid choice\n";
        }
    } while(choice != 4);
    return 0;
}