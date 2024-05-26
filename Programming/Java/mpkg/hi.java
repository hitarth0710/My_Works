package mpkg;

  public class hi {
  String name;
  double bal;
  public hi(String n, double b) {
    name = n;
    bal = b;
  }
  public void show() {
    if(bal<0)
      System.out.print("--> ");
    System.out.println(name + ": $" + bal);
  }
 }