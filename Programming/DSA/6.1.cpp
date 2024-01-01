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
    ptr = (struct node *)malloc(sizeof(struct node));//using malloc
    ptr->data=data1;
    ptr->next=NULL;
    return ptr;
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

struct node* insertATfront(int value, struct node *start)
{
   struct node *ptr;
   ptr = new node;
   ptr->data=value;
   ptr->next=start;
   return ptr;
}

struct node *append(struct node *end, struct node *newptr)
{
    end->next=newptr;
    return (end->next);
}

int main()
{
    struct node *start,*newptr,*end;
    int i,data2,x,y;
   
    while(true)
    {
        int c;
        cout<<"1.Creating the list."<<endl;
        cout<<"2.Traversing."<<endl;
        cout<<"3.Insert At Front."<<endl;
        cout<<"4.EXIT"<<endl;
        cout<<"Enter Your choie...:";
        cin>>c;
        cout<<endl;
    if(c==1)
    {
        cout<<"Enter the total number of Nodes :";
        cin>>data2;
        for(i=0;i<data2;i++)
        {
            cout<<"Enter Node "<<i+1<<" :";
            cin>>x;
            newptr=getnode(x);
            if(i==0)
            {
                start=newptr;
                end=newptr;
            }
            else{
                end=append(end,newptr);
            }
        }
    }
    else if(c==2)
    {
        traversing(start);
    }
    else if(c==3)
    {
        cout<<"Enter the value of Node you want to insert :";
        cin>>y;
        start=insertATfront(y,start);
    }
    else if(c==4){
    break;
    }
    else{
        cout<<"Invalid Choice...";
    break;
    }
    }

    return 0;
}
