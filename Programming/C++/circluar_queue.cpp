#include<iostream>
using namespace std;

#define SIZE 4
int front = -1;
int rear = -1;
int arr[SIZE];

void display();
void enqueue(int );
void dequeue();

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
                if(front == -1 && rear == -1)
                {
                    front++;
                    rear++;
                }
                if((front == 0 && rear == SIZE -1)|| front == (rear + 1) % SIZE)
                {
                    cout<<"Queue Overflow"<<endl;
                }
                else{
                    cout<<"Enter the element you want to ENQUEUE :";
                    cin>>x;
                    enqueue(x);
                }
                break;
            case 2:
                dequeue();
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
    if(front != 0 && rear == SIZE-1)
    {
        rear = 0;
        cout<<"Element "<<x<<" has been Enqueued."<<endl;
    }
    else
    {
        rear++;
        cout<<"Element "<<x<<" has been Enqueued."<<endl;
    }
    arr[rear]=x;
}

void dequeue()
{
    int element= arr[front];
    if(front == -1 && rear == -1)
    {
        cout<<"Queue Underflow"<<endl;
    }
    else if(front == rear)
    {
        front = -1;
        rear = -1;
        cout<<"Element "<<element<<" has been Dequeued."<<endl;
    }
    else if(front == SIZE-1)
    {
        front = 0;             
        cout<<"Element "<<element<<" has been Dequeued."<<endl;

    }
    else
    {
        front++;
        cout<<"Element "<<element<<" has been Dequeued."<<endl;
    }
}

void display()
{
    if(front == -1 && rear == -1) {
        cout<<"Queue is empty."<<endl;
        return;
    }
    cout<<"Elements in the queue are: ";
    int i;
    for(i=front;i != rear ; i = (i + 1) % SIZE)
    {
        cout<<arr[i]<<'\t';
    }
    cout<<arr[rear]<<endl;

}