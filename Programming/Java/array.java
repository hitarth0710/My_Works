import java.util.*;

class Arrex
{
    int n,max=0,size;
    int data[] = new int[1000];
    float sum=0,avg=0;
    Arrex()
    {
        n=10;
        for(int i=0;i<n;i++)
        {
          data[i] = 0;
        }
    }
    Arrex(int size)
    {
      for(int i=0;i<size;i++)
      {
          data[i] = 0;
      }
    }
    Arrex(int a[])
    {
       int n=a.length;
       for(int i=0;i<n;i++)
       {
           data[i] = a[i];
       }
    }
    void sum()
    {
      for(int i=0;i<n;i++)
      {
          sum = sum + data[i];
      }
      System.out.println("The sum of elemets of array : "+sum);

    }
    void avg_of_array()
    {
       avg=sum/n;
       System.out.println("The average of elemets of array : "+avg);
    }
    void display()
    {
       for(int i=0;i<n;i++)
       {
         System.out.println(data[i]);
       }
       System.out.println(" ");
    }
    void reverse()
    {
      for(int i=n-1;i>=0;i--)
      {
        System.out.println(data[i]);
      }
      System.out.println(" ");
    }
    void Search(int num)
    {
      int flag=0;
      for(int i=0;i<n;i++)
      {
        if(data[i] == num)
        {
          flag=1;
          System.out.println("Entered element "+num+" was found at index "+i+".");
          break;
        }
      }
      if(flag == 0)
      {
        System.out.println("Entered element was not found");
      }

    }
    void max()
    {
      int max=data[0];
      for(int i=0;i<n;i++)
      {
        if(data[i] > max)
        {
          max = data[i];
        }
      }
      System.out.println("Largest number in the array is "+max+".");
    }
    void Sorted()
    {
      int temp;
      for(int i=0;i<n;i++)
      {
        for(int j=i+1;j<n;j++)
        {
          if(data[i]>data[j])
          {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
          }
        }
      }
      System.out.println("Elements in the array after sorting are ");
      for(int i=0;i<n;i++)
      {
        System.out.println(data[i]);
      }
      System.out.println(" ");
    }

}


public class array
{
    public static void main(String args[])
    {
         Scanner s = new Scanner(System.in);//System.in is for to get input form console
         Arrex a1 = new Arrex();
          // a1.display();
         Arrex a2 = new Arrex(9);
        // a2.display();
         int a[] = {12,23,43,54,65,76,34,76,27,45,76,45};
         Arrex a3 = new Arrex(a);
         a3.sum();

    }

}
