public class Fibonacci 
{  	public static void main(String[] args) 
 	{ 
 	int n1=0,n2=1,n3,n=5,i; 
 	System.out.println("Fibonacci series till "+n+" terms:"); 
 	System.out.print(n1+" "+n2+" "); 
 	for(i=2;i<n;i++) 
 	{ 
 n3=n1+n2; 
 	System.out.print(" "+n3+" "); 
 	n1=n2; 
 	n2=n3;       
 	} 
    }
}