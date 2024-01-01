#include<iostream>
using namespace std;
//implement stack using linked list

struct node{
    int data;
    struct node *next;
};

struct node* top = NULL;

int isEmpty(struct node* top){
    if (top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct node* top){
    struct node* p = new node;
    if(p == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct node* push(struct node* top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct node* n = new node;
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        struct node* n = *top;
        *top = (*top)->next;
        int x = n->data;
        delete n;
        return x; 
    }
}

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout<<"Element: " <<ptr->data<<endl;
        ptr = ptr->next; 
    }
}

int stackTop(){
    return top->data;
}

int main()
{
    struct node *top;
    int element;
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
        if(c == 1)
        {
            int a;
            cout<<"Enter the element you want to PUSH :";
            cin>>a;
            top = push(top,a);
            cout<<"Your element was pushed..."<<endl;
            
        }
        else if(c == 2)
        {
            element=pop(&top);
            cout<<"Popped Element is "<<element<<endl;
        }
        else if(c == 3)
        {
            element=stackTop();
            cout<<"Top Element is "<<element<<endl;
        }
        else if(c == 4)
        {
            display(top);
            //continue;
        }
        else{
            break;
        }

    }
    return 0;
}