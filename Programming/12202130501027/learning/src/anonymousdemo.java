class Polygon {
    public void display() {
        System.out.println("Inside the Polygon class");
    }
}

class Anonymous
{
    public void createClass()
    {
        //creating an anonymous class(defining and instantiating at same time
        Polygon p1 = new Polygon()
        {
            public void display()
            {
                System.out.println("Inside an anonymous class.");
            }
        };
        p1.display();
    }
}

public class anonymousdemo
{
    public static void main(String args[])
    {
        Anonymous obj = new Anonymous();
        obj.createClass();
        Polygon p = new Polygon();
        p.display();
    }
}