#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void traversing(struct node* );
struct node* getnode(int x);
struct node* append(struct node* , struct node* );
struct node* insertatfront(struct node* ,int );
struct node* insertatend(struct node* ,int );


int main()
{
    struct node *start, *newptr, *end;
    bool running = true;
    while(running)
    {
        cout<<"1.Create the linked list"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Insert at front"<<endl;
        cout<<"4.insert at end"<<endl;
        cout<<"5.EXIT"<<endl;
        cout<<"Enter Your choice :";
        int c;
        cin>>c;
        cout<<endl;
        switch(c)
        {
            case 1:
                int len;
                cout<<"Enter the Length of linked list :";
                cin>>len;
                for(int i=0;i<len;i++)
                {
                    int y;
                    cout<<"Enter the value of "<<i+1<<" Element :";
                    cin>>y;
                    newptr = getnode(y);
                    if(i == 0)
                    {
                        start=newptr;
                        end=newptr;
                    }
                    else{
                        end=append(newptr,end);
                    }
                }
                cout<<endl;
                break;
            case 2:
                traversing(start);
                break;
            case 3:
                int y;
                cout<<"Enter the vaule :";
                cin>>y;
                start = insertatfront(start,y);
                break;
            case 4:
                int y1;
                cout<<"Enter the vaule :";
                cin>>y1;
                end = insertatend(end,y1);
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

struct node* getnode(int x)
{
    struct node *ptr;
    ptr = new node;
    ptr->data=x;
    ptr->next=NULL;
    return ptr;
}

struct node* append(struct node* newptr, struct node* end)
{
    end->next=newptr;
    return end->next;
}

void traversing(struct node* start)
{
    struct node* ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"\t";
        ptr=ptr->next;
    }
    cout<<endl;
}

struct node* insertatfront(struct node* start, int x)
{
    struct node* ptr;
    ptr= new node;
    ptr->data=x;
    ptr->next=start;
    return ptr;
}

struct node* insertatend(struct node* end, int x)
{
    struct node* ptr;
    ptr= new node;
    ptr->data=x;
    ptr->next=NULL;
    if(end!=NULL)
    {
        end->next=ptr;
    }
    return ptr;
}