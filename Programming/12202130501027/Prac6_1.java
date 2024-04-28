class InvoiceDetail<N extends Number> {
    private String invoiceName;
    private N amount;
    private N discount;

    // Constructor
    public InvoiceDetail(String invoiceName, N amount, N discount) {
        this.invoiceName = invoiceName;
        this.amount = amount;
        this.discount = discount;
    }

    // Getters
    public String getInvoiceName() {
        return invoiceName;
    }

    public N getAmount() {
        return amount;
    }

    public N getDiscount() {
        return discount;
    }

    // Setters
    public void setInvoiceName(String invoiceName) {
        this.invoiceName = invoiceName;
    }

    public void setAmount(N amount) {
        this.amount = amount;
    }

    public void setDiscount(N discount) {
        this.discount = discount;
    }
}

public class Prac6_1 {
    public static void main(String[] args) {
        InvoiceDetail<Double> invoiceDetail = new InvoiceDetail<>("Invoice1", 100.0, 10.0);

        System.out.println("Invoice Name: " + invoiceDetail.getInvoiceName());
        System.out.println("Amount: " + invoiceDetail.getAmount());
        System.out.println("Discount: " + invoiceDetail.getDiscount());

        invoiceDetail.setInvoiceName("Invoice2");
        invoiceDetail.setAmount(200.0);
        invoiceDetail.setDiscount(20.0);

        System.out.println("Updated Invoice Name: " + invoiceDetail.getInvoiceName());
        System.out.println("Updated Amount: " + invoiceDetail.getAmount());
        System.out.println("Updated Discount: " + invoiceDetail.getDiscount());
    }
}