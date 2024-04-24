class InvoiceDetail <N extends Number>{
    private String invoiceName; 
    private  N amount; 
    private N Discount;
    public N getAmount() {
        return amount;
    }
    public void setAmount(N amount) {
        this.amount = amount;
    }
    public N getDiscount() {
        return Discount;
    }
    public void setDiscount(N discount) {
        Discount = discount;
    }
    InvoiceDetail(String invoiceName, N amount, N Discount)
    {
        this.invoiceName = invoiceName;
        this.amount = amount;
        this.Discount = Discount;
    }
}



public class Prac6_1 {
    public static void main(String args[])
    {

    }
}
