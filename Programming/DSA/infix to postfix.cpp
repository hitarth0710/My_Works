#include<iostream>
#include<string>
using namespace std;

bool isOperator(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
    return true;
    else
    return false;
}

int getPred(char x)
{
    if(x == '*' || x == '/')
    {
        return 2;
    }
    else if(x == '+' || x == '-')
    {
        return 1;
    }
    return 0;
}
string inpo(string infix)//infix to postfix converter function
{
    string postfix;
    string stack;

    for(int i=0;i!='\0';i++)
    {
        char c = infix[i];
        if(isalnum(c))
        {
             postfix += c;
        }
        else if(c == '(') {
            stack += c;
        }
        

    }
}


int main()
{
    string infix;
    cout<<"Enter your infix Expression :";
    cin>>infix;
    cout<<"Your Postfix Expression"<<inpo(infix);
    return 0;
}