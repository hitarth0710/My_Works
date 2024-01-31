#include<iostream>
using namespace std;

struct node* top=NULL;

struct node{
    int data;
    struct node* next; 
};

struct node* getnode(int );
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
                cout<<endl;
                break;
            case 5:
                running = false;
                break;   
            default:
                cout<<"Invalid choice..."<<endl;  
                break;
        }
    }
}

struct node* getnode(int x)
{
    struct node* ptr;
    ptr = new node;
    ptr->data=x;
    ptr->next=nullptr;
    return ptr;
}

void push(int x)
{
    struct node* ptr;
    ptr = getnode(x);
    if(!ptr)
    {
        cout<<"Stack Overflow"<<endl;
        exit(1);
    }
    else{
        ptr->next=top;
        top=ptr;
    }
}

int pop()
{
    struct node* ptr;
    if(top == NULL)
    {
        cout<<"Stack underflow"<<endl;
        exit(1);
    }
    else{
        ptr=top;
        top=top->next;
        ptr->next=NULL;
        delete ptr;
    }
}

int peek()
{
    if(top!=nullptr){
        return top->data;
    }
    else
        exit(1);
}

void display()
{
    struct node* ptr;
    if(top == NULL)
    {
        cout<<"Stack underflow"<<endl;
        exit(1);
    }
    else{
        ptr=top;
        while(ptr != NULL)
        {
            cout<<ptr->data<<"\t";
            ptr=ptr->next;
        }
    }
}