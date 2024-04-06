class Cricket{
    int age;
    String name;
    void display()
    {
        System.out.println("The age of player is "+age);
        System.out.println("The Name of the player is "+name);
    }
    void setdata(int age , String name)
    {
        this.age=age;
        this.name=name;
    }
}

class Match extends Cricket{
    int no_of_odi;
    int no_of_test;

    void setdata(int age , String name , int no_of_odi, int no_of_test)
    {
        super.setdata(age,name);
        this.no_of_odi=no_of_odi;
        this.no_of_test=no_of_test;
    }

    void display()
    {
        super.display();
        System.out.println("Number of ODI Matches :"+no_of_odi);
        System.out.println("Number of TEST Matches :"+no_of_test);
    }
}

public class CricketDemo {
    public static void main(String args[])
    {
        Match mat[];
        mat = new Match[5];
        for(int i=0;i<mat.length;i++)
        {
            mat[i] = new Match();
            mat[i].setdata(Integer.parseInt(args[i*4]), args[i*4 + 1], Integer.parseInt(args[i*4 + 2]), Integer.parseInt(args[i*4 + 3]));
        }
        for(int i=0;i<mat.length;i++)
        {
            mat[i].display();
        }
        /* ALTERNATE LOGIC
         *  int count = 0;
        for (int i = 0; i < matches.length; i++) {
            matches[i] = new Match();
            matches[i].setData(Integer.parseInt(args[count]), args[count + 1], Integer.parseInt(args[count + 2]), Integer.parseInt(args[count + 3]));
            count += 4;
        }

        for (Match match : matches) {
            match.display();
            }
        }
         * 
         */

    }
}
