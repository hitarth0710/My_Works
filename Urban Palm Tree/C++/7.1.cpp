#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *getnode(int data1)
{
    struct node *ptr;
    ptr = new node;
    ptr->data=data1;
    ptr->next=NULL;
    return ptr;
}

struct node *append(struct node *end, struct node *newptr)
{
    end->next=newptr;
    return (end->next);
}

void traversing(struct node *start)
{
     struct node *ptr=start;
     while(ptr!=NULL)
     {
        cout<<ptr->data<<'\t';
        ptr=ptr->next;
     }
     cout<<endl;
}

struct node *insertAtEnd(int value, struct node* end)
{
    struct node *ptr;
    ptr = new node;
    ptr->data=value;
    ptr->next=NULL;
    if(end!=NULL){
        end->next=ptr;
    }
    return ptr;
}

struct node *insertAtPosition(int value, int position, struct node *start)
{
    if(position == 1){
        struct node *ptr = new node;
        ptr->data=value;
        ptr->next=start;
        return ptr;
    }

    struct node *current = start;
    for(int i=1;i<position - 1 && current != NULL;i++){
        current = current->next;
    }

    if(current == NULL)
    {
        return start;
    }

    struct node *ptr = new node;
    ptr->data=value;
    ptr->next=current->next;
    current->next=ptr;

    return start;
}

struct node *deleteFirst(struct node *start)
{
    if(start == NULL){
        return NULL;
    }
    struct node *ptr = start;
    start = start->next;
    delete ptr;
    return start;
}

struct node *deleteEnd(struct node *start)
{
    if(start == NULL)
    {
        return NULL;
    }
    if(start->next == NULL)
    {
        delete start;
        return NULL;
    }
    
    struct node *secondlast = start;
    while(secondlast->next->next != NULL)
    {
        secondlast = secondlast->next;
    }
    struct node *last;
    last=secondlast->next;
    secondlast->next=NULL;
    delete last;
    return start;
}

struct node *deleteAtposition(int pos, struct node *start)
{
    if(start == NULL)
    {
        return NULL;
    }
    if(pos == 1)
    {
        struct node *ptr;
        ptr=deleteFirst(start);
        return ptr;
    }
    struct node *current = start;
    for(int i=1;i<pos-1 && current!=NULL;i++)
    {
        current = current->next;
    }
    if(current == NULL||current->next == NULL){
        return start;  
    }
    struct node* temp;
    temp = current->next;//Create a temporary pointer to the node at the desired position
    current->next = temp->next;//Set the next pointer of the current node to the node after the desired position
    delete temp;
    return start;
}

struct node* reverseLL(struct node* start)
{
    struct node *ptr=start;
    struct node *rlist=NULL,*next=NULL;
    while(ptr != NULL)
    {
        next = ptr->next;// Save the next node
        ptr->next = rlist;
        rlist = ptr;//one step forward
        ptr = next;
    }
    start = rlist;//Set start to rlist because the last node is now the first node
    return start;
}

int main()
{
    struct node *start,*newptr,*end;
    int x,y,c,i;
    cout<<"Creating the linked list.."<<endl;
    cout<<"Enter the No. of Nodes :";
    cin>>x;
    for(i=0;i<x;i++)
        {
            cout<<"Enter Node "<<i+1<<" :";
            cin>>y;
            newptr=getnode(y);
            if(i==0)
            {
                start=newptr;
                end=newptr;
            }
            else{
                end=append(end,newptr);
            }
        }
    while(true)
    {
        cout<<"1.Insert At End"<<endl;
        cout<<"2.Insert At Position"<<endl;
        cout<<"3.Delete At First"<<endl;
        cout<<"4.Delete At End"<<endl;
        cout<<"5.Delete At Position"<<endl;
        cout<<"6.Reversing At Linked List"<<endl;
        cout<<"7.Print Linked list"<<endl;
        cout<<"8.EXIT"<<endl;
        cout<<"Enter Your choice...:";
        cin>>c;
        cout<<endl;
        if(c==1)
        {
            int a;
            cout<<"Enter the value you want to insert at End :";
            cin>>a;
            end=insertAtEnd(a,end);
        }
        else if(c==2)
        {
            int b,pos;
            cout<<"Enter the position :";
            cin>>pos;
            cout<<"Enter the value :";
            cin>>b;
            start = insertAtPosition(b,pos,start);
        }
        else if(c==3)
        {
            start = deleteFirst(start);
        }
        else if(c==4)
        {
            start = deleteEnd(start);
        }
        else if(c==5)
        {
            int pos;
            cout<<"Enter the Position :";
            cin>>pos;
            start = deleteAtposition(pos,start);
        }
        else if(c==6)
        {
            start = reverseLL(start);
        }
        else if(c==7)
        {
            traversing(start);
        }
         else if(c==8)
        {
            break;
        }
        else{
            cout<<"Invalid choice..";
            break;
        }
    }
    return 0;
}
