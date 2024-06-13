#include<iostream>
using namespace std;

int main()
{
    int n,i;
    cout<<"Enter the Size of array :"<<endl;
    cin>>n;
    int *p = new int[n];
    cout<<"Enter the Elements:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>p[i];
    }
    int *temp = new int[n];
    int j=0;
    for(i=0;i<n-1;i++)
    {
        if(p[i]!=p[i+1])
        {
            temp[j]=p[i];
            j++;
        }
    }
        temp[j]=p[n-1];
        j++;
        for(int k=0;k<j;k++)
        {
            cout<<temp[k]<<'\t';
        }
    
    return 0;
}