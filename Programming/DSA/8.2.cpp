#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next; 
};

struct node* front=NULL;
struct node* rear=NULL;

void enqueue(int data)
{
    struct node *temp;
    temp = new node;
    if(!temp){
        cout<<"Heap Overflow"<<endl;
        exit(1);
    }
    temp->data = data;
    temp->next = nullptr;

    if(front == NULL)
    {
        front = rear = temp;
    }
    else{
        rear->next = temp;
        rear=temp;
    }
}