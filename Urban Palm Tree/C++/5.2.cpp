#include <iostream>
using namespace std;


#define size  5
int a[size];
int front = -1;
int rear = -1;

void enqueue(int );
void dequeue();
void display();

int main()
{
    int c;
    while(true)
    {
        cout<<"1.ENQUEUE"<<endl;
        cout<<"2.DEQUEUE"<<endl;
        cout<<"3.DISPLAY"<<endl;
        cout<<"4.EXIT"<<endl ;
        cout<<"Enter your choice :";
        cin>>c;
        if(c==1)
        {
            int b;
            cout<<"Enter the element you want to Enqueue :";
            cin>>b;
            enqueue(b);
            cout<<"Element "<<b<<" is Enqueued."<<endl;
        }
        else if(c==2)
        {
            dequeue();
        }
        else if(c==3)
        {
            display();
        }
        else if(c==4)
        break;
        else
        cout<<"Invalid choice..."<<endl;

    }
    return 0;
}

void enqueue(int x)
{
     if((front == 0 && rear == size-1) || (front == rear+1)) {
        cout<<"Queue is full."<<endl;
        return;
     }
     else if (front == -1 && rear == -1)
     {
         front++;
         rear++;
     }
    else if(rear == size - 1 && front != 0) { //the line that defines circular queue
        rear = 0;
    }
    else {
        rear++;
    }
    a[rear] = x;
}
void dequeue()
{
    if(front == -1 && rear == -1) {
        cout<<"Queue is empty."<<endl;
        return;
    }
    int x = a[front];
    if(front == rear) {
        front = -1;
        rear = -1;
    }
    else if(front == size - 1) {
        front = 0;
    }
    else {
        front++;
    }
    cout<<"The Element "<<x<<" is Dequeued."<<endl;
}
void display()
{
    if(front == -1 && rear == -1) {
        cout<<"Queue is empty."<<endl;
        return;
    }
    cout<<"Elements in the queue are: ";
    int i;
    for(i=front;i != rear ; i = (i + 1) % size)
    {
        cout<<a[i]<<'\t';
    }
    cout<<a[rear]<<endl;

}
