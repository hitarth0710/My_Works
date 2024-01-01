#include<iostream>
#include<string>
using namespace std;
int top=-1;
char stk[20];
int push(char );
char pop();

int main()
{
    int len=0;
    int i=0;
    cout<<"Enter Your String :";
       cin>>stk[i];
    cout<<endl;
    while(stk[i]!='\0')
    {
        len++;  
        i++;
    }
    for(i=len;i>0;i--)
    {
        push(stk[i]);
    }
    cout<<stk;
    return 0;
}
int push(char ele)
{
    top++;
    stk[top]=ele;
    return 0;
}
char pop()
{
    return stk[top--];
}
