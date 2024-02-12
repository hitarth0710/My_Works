import java.util.Scanner;

public class calculator
{
    public static void main(String srgs[])
    {
        double num1,num2,r;
        boolean run = true;
        Scanner scanner = new Scanner(System.in);

        while(run)
        {
          System.out.println("*****MENU******");
           System.out.println("1.Addition(+) : ");
           System.out.println("2.Subtraction(-) : ");
           System.out.println("3.Multiplication(*) : ");
           System.out.println("4.Division(/) : ");
           System.out.println("5.Exit(.)");
           System.out.print("Enter your choice : ");
           char operator = scanner.next().charAt(0);
           switch(operator)
           {
                case '+':
                    System.out.print("Enter you Number 1 :");
                    num1 = scanner.nextDouble();
                    System.out.print("Enter you Number 2 :");
                    num2 = scanner.nextDouble();
                    r = add(num1,num2);
                    System.out.println("The Addition of "+num1+" and "+num2+" is "+r+".");
                    break;
                case '-':
                    System.out.print("Enter you Number 1 :");
                    num1 = scanner.nextDouble();
                    System.out.print("Enter you Number 2 :");
                    num2 = scanner.nextDouble();
                    r = sub(num1,num2);
                    System.out.println("The Subtration of "+num1+" and "+num2+" is "+r+".");
                    break;
                case '*':
                    System.out.print("Enter you Number 1 :");
                    num1 = scanner.nextDouble();
                    System.out.print("Enter you Number 2 :");
                    num2 = scanner.nextDouble();
                    r = mul(num1,num2);
                   System.out.println("The Multiplication of "+num1+" and "+num2+" is "+r+".");
                   break;
                case '/':
                    System.out.print("Enter you Number 1 :");
                    num1 = scanner.nextDouble();
                    System.out.print("Enter you Number 2 :");
                    num2 = scanner.nextDouble();
                    r = div(num1,num2);
                    System.out.println("The Division of "+num1+" and "+num2+" is "+r+".");
                    break;
                case '.':
                    run = false;
                    break;
                default:
                    System.out.println("Invalid Choice....");
                    break;
           }

        }
        scanner.close();
    }
    static double add(double a, double b)
    {
        double c;
        c=a+b;
        return c;
    }
    static double sub(double a, double b)
    {
        double c;
        c=a-b;
        return c;
    }
    static double mul(double a, double b)
    {
        double c;
        c=a*b;
        return c;
    }
    static double div(double a, double b)
    {
        double c;
        c=a/b;
        return c;
    }
}
