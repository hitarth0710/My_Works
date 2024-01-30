//liner and binary search
#include<iostream>
using namespace std;

#define size 5
int *arr = new int[size];

int linearsearch(int );
void binarysearch(int );

int main()
{
    cout<<"Enter the elements in the array."<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter "<<i+1<<" Element :";
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Which search type you want to apply..."<<endl;
    bool run = true;
    while(run)
    {
        cout<<"1.Linear Search"<<endl;
        cout<<"2.Binary Search"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter your choice :";
        int c;
        cin>>c;
        cout<<endl;
        switch(c)
        {
            case 1:
                int x,t;
                cout<<"Enter the element you want to search :";
                cin>>x;
                t=linearsearch(x);
                if(t)
                {
                    cout<<"Element not found"<<endl;
                }
                else{
                    cout<<"Element found at index "<<t<<"."<<endl;
                }
                break;
            case 2:
                int y;
                cout<<"Enter the element you want to search :";
                cin>>y;
                binarysearch(y);
                break;
            case 3:
                run = false;
                break;
            deafult:
                cout<<"Invalid Choice..."<<endl;
                break;
        }
    }
    delete[] arr;
    return 0;
}

int linearsearch(int data)
{
    int i;
    for(i=0;i<size;i++)
    {
       if(arr[i] == data)
       {
          return i;
       } 
    }
    if (i)
    {
        return -1;
    }
}

void binarysearch(int data)
{
    int left = 0;
    int right = size - 1;
    while(left <= right)
    {
        int mid;
        mid = left + (right - left)/2;
        if(arr[mid]==data)
        {
            cout<<"Match Found at index "<<mid +1<<"."<<endl;
            return;
        }
        else if(arr[mid] < data)
        {
            left = mid + 1;
        }
        else if(arr[mid] > data)
        {
            right = mid - 1;
        }
    }
    cout << "Element not found in the array." << endl;
}