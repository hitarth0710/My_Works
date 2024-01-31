#include<iostream>
#include<string>
using namespace std;

int top = -1;
char stack[1000];

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

bool isPalindrome(string str)
{
    int len = str.length();
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }
    for (int i = 0; i < len; i++) {
        if (str[i] != pop()) {
            return false;
        }
    }

    return true;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    if (isPalindrome(s) == true) {
        cout << "String is a palindrome." << endl;
    } else {
        cout << "String is not a palindrome." << endl;
    }
    return 0;
}