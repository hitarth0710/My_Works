interface GeometricShape{
    public void describe();
}

interface TwoDshape extends GeometricShape{
    public double area();
}

interface ThreeDshape extends GeometricShape{
    public double volume();
}

class Cone implements ThreeDshape{
    private double radius;
    private double height;
    Cone(double radius, double height)
    {
        this.radius=radius;
        this.height=height;
    }
    public void describe()
    { 
        System.out.println("This shape is cone which is 3D shape.");
    }
    public double volume()
    {
        double result;
        result = (1.0/3.0)*3.14*radius*radius*height;
        return result;
    }
}

class Rectangle implements TwoDshape{
    private double radius;
    private double height;
    Rectangle(double radius, double height)
    {
        this.radius=radius;
        this.height=height;
    }
    public void describe()
    { 
        System.out.println("This shape is rectangle which is 2D shape.");
    }
    public double area()
    {
        double result;
        result = radius*height;
        return result;
    }
}


public class Prac4_4 {
    public static void main(String args[])
    {
        double result_c,result_r; 
        Cone c = new Cone(5,5);
        c.describe();
        result_c = c.volume();
        System.out.println("The volume of cone is "+result_c);

        Rectangle r = new Rectangle(5, 5);
        r.describe();
        result_r = r.area();
        System.out.println("The area of rectangle is "+result_r);
    } 
}
