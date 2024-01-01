#include<iostream>
using namespace std;

int main()
{
    int x;
    int c;
    int front=-1;
    int rear=-1;
    int n;
    cout<<"enter the size of Queue :";
    cin>>n;
    int *a=new int[n];
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
             if(front==-1 && rear==-1)
             {
                front++;
                rear++;
                cout<<"Enter the element you want to enter: ";
                cin>>x;
                a[rear]=x;
                rear++;
                cout<<"Element is enqueded"<<endl;
             }
             else if(rear>0 && rear<n)
             {
                cout<<"Enter the element you want to enter: ";
                cin>>x; 
                a[rear]=x;
                rear++; 
                cout<<"Element is enqueded"<<endl;
 
             }
             else if(rear == n-1)
             {
                cout<<"Queue is full."<<endl;
             }


        }
        else if(c==2)
        {
              if(front==-1)
              {
                cout<<"Queue is empty."<<endl;  
              }
              else if(front==rear)
              {
                 int el = a[front] ;

                  front=-1;
                  rear=-1;
                    cout<<"The element is DEqueued"<<endl;
              }
              else 
              {
                 int y;
                 y=a[front];
                 front++;
                 cout<<"The element is DEqueued"<<endl;
              }
        }
        else if(c==3)
        {
            if(front==-1)
              {
                cout<<"Queue is empty."<<endl;  
              }
             else{
            for(int i=front;i<rear;i++)
            {
                cout<<a[i]<<endl;
            }
            }
        }
        else if(c==4)
            break ;
        else
        {
            cout<<"Entered choice is invalid..."<<endl;
        }
        
    }
    return 0;
}