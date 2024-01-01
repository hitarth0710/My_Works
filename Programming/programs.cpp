#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

bool isEmpty() {
    return top == nullptr;
}

void push(int data) {
    Node* temp = new Node();
    if (!temp) {
        cout << "\nHeap Overflow";
        exit(1);
    }
    temp->data = data;
    temp->next = top;
    top = temp;
}

int pop() {
    Node* temp;
    if (top == nullptr) {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else {
        temp = top;
        top = top->next;
        temp->next = nullptr;
        int popped_value = temp->data;
        delete temp;
        return popped_value;
    }
}

int peek() {
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

void display() {
    Node* temp;
    if (top == nullptr) {
        cout << "\nStack Underflow";
        exit(1);
    }
    else {
        temp = top;
        while (temp != nullptr) {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
    }
}