
public class factorial
{
    public static void main(String args[])
    {
        long n = Integer.parseInt(args[0]);
        System.out.println("Your entered number is "+n);
        long fac=1;
        while(n>0)
        {
            fac=fac*n;
            n--;
        }
        System.out.println("Your Factorial is "+fac);
    }
}
