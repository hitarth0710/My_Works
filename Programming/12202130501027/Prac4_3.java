interface property{
    public double computePrice();
}

class Bunglows implements property{
    String name;
    double constructionArea;
    double landArea;
    
    Bunglows(String name , double constructionArea, double landArea)
    {
        this.name=name;
        this.constructionArea=constructionArea;
        this.landArea=landArea;
    }

    public double computePrice()
    {
        double constructionCost = this.constructionArea * 500;
        double additionalCost = this.landArea * 200;
        double landCost = this.landArea * 400;
        return constructionCost + additionalCost + landCost;
    }
}

class Flats implements property{
    String name;
    double constructionArea;

    Flats(String name, double constructionArea)
    {
        this.name=name;
        this.constructionArea=constructionArea;
    }

    public double computePrice()
    {
        double constructionCost = this.constructionArea * 500;
        double additionalCost = 200000;
        return constructionCost + additionalCost;
    }
}


public class Prac4_3{
    public static void main(String args[])
    {
        Bunglows bunglow = new Bunglows("bunglow 1", 2000,1000);
        double result_b = bunglow.computePrice();
        System.out.println("Total price for the Bunglow is "+result_b);

        Flats flat = new Flats("flat 1",400);
        double result_f = flat.computePrice();
        System.out.println("Total proce for Flat is "+result_f);
    }

}