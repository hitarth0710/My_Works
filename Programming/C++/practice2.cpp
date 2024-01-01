#include<iostream>
#include<string>
using namespace std;

/*class copyt
{
    int x;
    public:
    copyt(){}
    copyt(int a)
    { 
        x=a;
    }
    copyt(copyt &y)
    {
        x = y.x;
    }
    void display()
    {
         cout<<x;
    }
};
int main()
{
    
    copyt A(100);
    copyt B(A);
    A.display();cout<<endl;
    B.display();
    return 0;
}*/

/*class complexx 
{
     float x,y;
     public:
     complexx(){}
     complexx(float real,float imag)
     {
        x=real;
        y=imag;
     }
    friend complexx add(complexx , complexx );
    friend void show(complexx );
};
complexx add(complexx c1 ,complexx c2)
{
       complexx c3;
       c3.x=c1.x+c2.x;
       c3.y=c1.y+c2.y;
       return c3;
}
void show(complexx c)
{
    cout<<c.x<<" +i"<<c.y<<endl;
}
int main()
{
    complexx c1(3.5,3.5);
    complexx c2(2.5,2.5);
    complexx c3=add(c1,c2);
    show(c1);
    show(c2);
    show(c3);
    return 0;
}*/

/*class sample
{
    char *p;int len;
    public:
    sample(){}
    sample(char *img)
    {
        len=strlen(img);
        p=new char[len+1];
        strcpy(p,img);
    }
    ~sample()
    {
        cout<<"Destructor";
        delete []p;
    }
    void display()
    {
         cout<<"Your String is "<<p;
    }
};
int main()
{
    sample s("hr");
     sample s1("soni");
     s.display();
     s1.display();
}
 */   
