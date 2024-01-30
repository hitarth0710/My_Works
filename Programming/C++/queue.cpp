#include<iostream>
using namespace std;

#define SIZE 10
int front = -1;
int rear = -1;
int arr[NULL];

void display();
void enqueue(int );
int dequeue();

int main()
{
    bool running = true;
    while(running)
    {
        cout<<"1.ENQUEUE"<<endl;
        cout<<"2.DEQUEUE"<<endl;
        cout<<"3.DISPLAY"<<endl;
        cout<<"4.EXIT"<<endl;
        cout<<"Enter Your choice :";
        int c;
        cin>>c;
        cout<<endl;
        switch (c)
        {
            case 1:
                int x;
                cout<<"Enter the element you want to ENQUEUE :";
                cin>>x;
                if(front == -1 && rear == -1)
                {
                    front++;
                    rear++;
                }
                enqueue(x);
                cout<<"Element "<<x<<" has been Enqueued."<<endl;
                break;
            case 2:
                int z;
                z=dequeue();
                cout<<"Element "<<z<<" has been Dequeued."<<endl;
                break;
            case 3:
                display();
                cout<<endl;
                break;
            case 4:
                running = false;
                break;   
            default:
                cout<<"Invalid choice..."<<endl;  
                break;
        } 
    }
    return 0;
}

void enqueue(int x)
{
    if(front == 0 && rear == SIZE -1)
    {
        cout<<"Queue Overflow"<<endl;
    }
    else
    {
        arr[rear]=x;
        rear++;
    }
}

int dequeue()
{
    int element;
    if(front == -1 && rear == -1)
    {
        cout<<"Queue Underflow"<<endl;
    }
    else if(front == rear)
    {
        element = arr[front];
        front = -1;
        rear = -1;
    }
    else
    {
        element = arr[front];
        front++;
    }
    return element;
}

void display()
{
    int i;
    for(i=front;i<rear;i++)
    {
        cout<<arr[i]<<"\t";
    }
}