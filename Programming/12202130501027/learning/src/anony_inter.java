interface Anonymous1
{
    String CollegeName = "GCET";
    void getCollegeName();
}


public class anony_inter
{
    public static void main(String[] args)
    {
        Anonymous1 any = new Anonymous1()
        {
            @Override
            public void getCollegeName() {
                System.out.println("Your College name is "+CollegeName);
            }
        };
        any.getCollegeName();
    }
}
