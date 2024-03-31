public class Calculator{ 
    public static void main(String[] args) 
    { 
    int x=Integer.parseInt(args[0]);  	int y=Integer.parseInt(args[2]); 
    char ch=args[1].charAt(0); 
    int res=0;  	
    switch(ch) 
    { 
        case 'a':  	res=x+y;  	
                    break;  	
        case 's':  	res=x-y;  	
                    break;  	
        case 'm':  	res=x*y;  	
                    break;  	 
        case 'd':  	res=x/y;  	
                    break;  	
        default: 
        System.out.println("Invalid choice:"); 
        break; 
    } 
        System.out.print(x+" "+ch+" "+y+" "+"="+" "+res); 
    } 	 
} 
   