#include<iostream>
using namespace std;

/*program of 3.2 file
void hitarth(int &);

int main()
{
      int M;
      cout<<"Enter M :";
      cin>>M;
      cout<<endl;
      hitarth(M);
}

void hitarth(int &h)
{
    int i;
    int *s = new int[h];
    cout<<"Enter the values of vector ";cout<<endl;
    for(i=0;i<h;i++)
    {
        cin>>s[i];
    }
    cout<<endl;
    cout<<"Entered values of vector are ";cout<<endl;
    for(i=0;i<h;i++)
    {
        cout<<s[i];
        cout<<endl;
    }
    cout<<endl;
}
*/
/* logic
   value(int x, int y)
   {
    int temp=x;
    x=y;
    y=temp;
   }
   refrence(int &x, int &y)
   {
    same as above
   }
*/
/*void swap(int &x, int &y)
{
    int temp=x;
    x=y;
    y=temp;
}
int main()
{
    int a,b,c;
    cout<<"Enter a,b & c";cout<<endl;
    cin>>a>>b>>c;
    if(a<b)
    {
        swap(a,b);
    }
    else(a>c);
    {
        swap(a,c);
    }
    cout<<"Largest :"<<c;
}*/
/*
void reverse(char *str, int cnt)
{ 
    int i,j,len;
    char str1[20];

        for(i=cnt-1,j=0;i>=0;i--,j++)
        {
            str1[j]=str[i];
        }
        str[j]!='\0';
        cout<<str1;cout<<endl;
    
}

int main()
{
   int count;
   char str[20];
   cout<<"Enter string ";
   cin>>str;
   cout<<"Enter count ";
   cin>>count;
   reverse(str,count);
   return 0; 
}*/
/*
class dist
{
    float feet,inches;
    public:
       void gdata()
       {
          cout<<"Enter Feet and inches :"<<endl;
          cin>>feet>>inches;
       }
       void pdata()
       {
          cout<<feet<<"-"<<inches<<endl;
       }
       friend dist add(dist ,dist );
};

dist add(dist d1,dist d2)
{
    
    d3.feet = d1.feet + d2.feet;
    d3.inches = d1.inches + d2.inches; 
    return d3;
}
int main()
{
    dist d1,d2,d3;
    d1.gdata();
    d2.gdata();
    d3.add(d1,d2);
    d3.pdata();
    return 0;
}*/
/*
class time
{
    int hours,mins;
    public:
       void gdata()
       {
         cout<<"Enter hours and mins :"<<endl;
         cin>>hours>>mins;
       }
       void pdata()
       {
          cout<<hours<<"-"<<mins<<endl;
       }
       void sum(time ,time );
};
void time::sum(time t1,time t2)
{
     mins=t1.mins + t2.mins;
     hours=mins/60;
     mins=mins%60;
     hours = hours + t1.hours + t2.hours;
}
int main()
{
    time t1,t2,t3;
    t1.gdata();
    t2.gdata();
    t3.sum(t1,t2);
    t3.pdata();
    return 0;
}
*/
/*
class complex 
{
    float a,b;
    public:
       void gdata()
       {
           cout<<"Enter a & b:";
           cin>>a>>b;
       }
       void pdata()
       {
          cout<<a<<" + j "<<b<<endl;
       }
       friend complex sum(complex ,complex );
};
complex sum(complex c1,complex c2)
{
     complex c3;
     c3.a=c1.a + c2.a;
     c3.b=c1.b + c2.b;
     return c3;
}
int main()
{
    complex c1,c2,c3;
    c1.gdata();c1.pdata();
    c2.gdata();c2.pdata();
    c3=sum(c1,c2);
    c3.pdata();
    return 0;
}
*/
/*
class sample
{
    char *str;
    public:
      sample(){}
      sample(char n[50])
      {
        str = new char[50];
        str=n;
      }
      void display()
      {
            cout<<"Name is :"<<str<<endl;
      }
      ~sample()
      {
         delete[]str;
      };
};
int main()
{
    char name[20];
    cout<<"Enter name: ";
    cin>>name; 
    sample s1(name);   
    s1.display();
    return 0;
}
*/
/*
class complex
{
    int x,y;
    public:
       complex(){}
       complex(int a, int b)
       {
           x=a;
           y=b;
       }
       complex friend operator+(complex ,complex);
       void display()
       {
         cout<<x<<" + j"<<y;
       }
};
complex operator+(complex c1, complex c2)
{ 
     complex c3;
     c3.x=c1.x+c2.x;
     c3.y=c1.y+c2.y;
     return c3;
}
int main()
{
    complex c1(5,5);
    complex c2(5,5);
    complex c3;
    c3=c1+c2;
    c3.display();
    return 0;
}*/
/*
class complex
{
    int x,y;
    public:
       complex(){}
       complex(int a, int b)
       {
           x=a;
           y=b;
       }
       complex operator+(complex);
       void display()
       {
         cout<<x<<" + j"<<y;
       }
};
complex complex::operator+(complex c1)
{ 
     complex c2;
     c2.x=x+c1.x;
     c2.y=y+c1.y;
     return c2;
}
int main()
{
    complex c1(5,5);
    complex c2(5,5);
    complex c3;
    c3=c1+c2;
    c3.display();
    return 0;
}
*/

/*
class array
{
     int a[5];
     public:
        array(){}
        array(int *s)
        {
            for(int i=0;i<5;i++)
            {
                a[i]=s[i];
            }
        }
        int operator[](int );
};
int array::operator[](int k)
{
     return (a[k]);
}
int main()
{
    int x[5]={1,2,3,4,5};
    array A(x);
    for(int i=0;i<5;i++)
    {
        cout<<x[i];
        cout<<endl;
    }
    return 0;
}
*/
/*
class alpha
{
     int x;
     public :
        alpha(){}
        alpha(int i)
        {
            x=i;
        }
        void showx()
        {
            cout<<"X="<<x;
        }
};
class beta
{
     float y;
     public :
        beta(){}
        beta(float j)
        {
            y=j;
        }
        void showy()
        {
            cout<<"Y="<<y;
        }
};
class gamma:public alpha, public beta  
{
     int m,n;
     public:
     gamma(){}
     gamma(int a, float b, int c, int d);
     {
         alpha(a),beta(b);
         m=c;
         n=d;
     }
    void showmn()
     {
        cout<<"M="<<m<<endl<<"N="<<n;
     }
};
int main()
{
    gamma g(10,10.69,34,45);
    g.showx();
    g.showy();
    g.showmn();
    return 0;
}*/
/*
class distanc
{
    int km,m;
    public:
       void gdata()
       {
         cout<<"Enter KM and M :";
         cin>>km>>m;
       }
       void pdata()
       {
         cout<<"KM"<<km<<"m"<<m;
       }
       distanc sum(distanc d)
       {
          distanc result;
          result.km=km+d.km;
          result.m=m+d.m;
          return result;
       }

};
int main()
{
    distanc d1,d2,d3;
    d1.gdata();
    d2.gdata();
    d3=d1.sum(d2);
    d3.pdata();
    return 0;
}
*/
