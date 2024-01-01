#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Node* top = nullptr;
struct Node* head = nullptr;

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

bool isEmpty() {
    return top == nullptr;
}

int peek() {
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

void pop() {
    Node* temp;
    if (top == nullptr) {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else {
        temp = top;
        top = top->next;
        temp->next = nullptr;
        delete temp;
    }
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
            cout << temp->data <<endl;
            temp = temp->next;
        }
    }
}

int main() {
   while(true){
        
        int c;
        cout<<"1.PUSH"<<endl;
        cout<<"2.POP"<<endl;
        cout<<"3.PEEK"<<endl;
        cout<<"4.DISPLAY"<<endl;
        cout<<"5.EXIT"<<endl;
        cout<<"Enter your choice :";
        cin>>c;
        cout<<endl;
        switch(c){
            case 1:
                int data;
                cout<<"Enter data :";
                cin>>data;
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                cout<<peek()<<endl;
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                cout<<"Invalid choice"<<endl;
        }
        cout<<endl;
   }
    return 0;
}
