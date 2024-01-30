#include<iostream>
using namespace std;

int top = -1;
#define SIZE 10
int arr[NULL];


void push(int );
int pop();
int peek();
void display();

int main()
{
    bool running = true;
    while(running)
    {
        cout<<"1.PUSH"<<endl;
        cout<<"2.POP"<<endl;
        cout<<"3.PEEK"<<endl;
        cout<<"4.DISPLAY"<<endl;
        cout<<"5.EXIT"<<endl;
        cout<<"Enter Your choice :";
        int c;
        cin>>c;
        cout<<endl;
        switch (c)
        {
            case 1:
                int x;
                cout<<"Enter the element you want to push :";
                cin>>x;
                push(x);
                cout<<"Element "<<x<<" has been pushed."<<endl;
                break;
            case 2:
                int z;
                z=pop();
                cout<<"Element "<<z<<" has been popped."<<endl;
                break;
            case 3:
                int y;
                y=peek();
                cout<<"Topmost value of given stack is "<<y<<"."<<endl;
                break;
            case 4:
                display();
                break;
            case 5:
                running = false;
                break;   
            default:
                cout<<"Invalid choice..."<<endl;  
                break;
        } 
    }
    return 0;
}

void push(int x)
{
    if(top == SIZE-1)
    {
        cout<<"Stack Overflow"<<endl;
    }
    else{
        top++;
        arr[top]=x;
    }
}

int pop()
{
    int element;
    if(top == -1)
    {
        cout<<"Stack Undeflow"<<endl;
    }
    else{
        element = arr[top];
        top--;
    }

    return element;
}

int peek()
{
    return arr[top];
}

void display()
{
    for(int i=top;i>=0;i--)
    {
        cout<<arr[i]<<endl;
    }
    cout<<endl;
}