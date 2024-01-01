#include<iostream>
using namespace std;
class complex
{
     float a,b;
     public:
        complex(){}
        complex(float real,float imag);
        complex operator+(complex);
        void display();
};
complex::complex(float real,float imag)
{
    a=real;
    b=imag;
}
complex complex::operator+(complex c)
{
    complex temp;
    temp.a = a + c.a;
    temp.b = b + c.b;
    return temp;
}
void complex::display()
{
    cout<<a<<"+i"<<b<<endl;
}

int main()
{
    complex c1,c2,c3,c4;
    c1=complex(2.5,3.5);
    c2=complex(3.5,2.5);
    c3=complex(2.5,5.6);
    c4= c1 + c2 + c3 ;
    //c1.display();
    //c2.display();
   // c3.display();
   // c4.display();
    int a=1;
    double b=2.55;
    a=b;
    cout<<a<<endl;
    cout<<b;

    return 0;
}
