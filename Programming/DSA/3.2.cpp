#include<iostream>
#include<string>
using namespace std;


int main()
{
    int opstk[20];
    int top=-1;
    string a;
    int i=0;
    cout<<"Enter your Expression :";
    cin>>a;
    cout<<endl;
    while(a[i] != '\0')
    {
        if(top==-1 && a[i]==')')
        cout<<"";
        else if(a[i]=='(')
        {
            top++;
            opstk[top]=a[i];
        }
        else
        {
            int x=opstk[top];
            top--;
        }
        i++;
    }
    if(top==-1)
        cout<<"Balanced";
    else
        cout<<"Not balanced";
    return 0;
}
