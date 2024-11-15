import java.sql.*;
import java.util.*;

class Product
{
    private int prod_id;
    private int stockQuantity;
    private String prod_name;

    public Product(int prod_id, int stockQuantity, String prod_name)
    {
        this.prod_id = prod_id;
        this. stockQuantity = stockQuantity;
        this.prod_name = prod_name;
    }
    public int getProductId(){
        return prod_id;
    }
    public int getStockQuantity(){
        return stockQuantity;
    }
    public String getProductName(){
        return prod_name;
    }
}

public class question3_ass1 {
    private static final String url = "jdbc:mysql://localhost:3306/hitarth";
    private static final String username = "root";
    private static final String password = "mysql";

    public static void main(String[] args)
    {
        System.out.println("Welcome to Product Stock Update System.");
        Scanner sc = new Scanner(System.in);
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
        }catch(Exception e){
            System.out.println(e.getMessage());
        }

        try{
            Connection con = DriverManager.getConnection(url,username,password);
            while(true){
                System.out.println("1. Insert stock quantities for multiple products.");
                System.out.println("2. Update stock quantities for multiple products");
                System.out.println("3. Printing the full Stock Entries.");
                System.out.println("4. Exit");
                System.out.print("Enter your choice: ");
                int choice = sc.nextInt();
                sc.nextLine(); // Consume newline

                switch (choice)
                {
                    case 1:
                        insertStockQuantities(con,sc);
                        break;
                    case 2:
                        updateStockQuantities(con,sc);
                        break;
                    case 3:
                        viewStock(con,sc);
                        break;
                    case 4:
                        con.close();
                        sc.close();
                        return;
                    default:
                        System.out.println("Invalid choice.");
                }
            }
        }catch(SQLException e){
            System.out.println(e.getMessage());
        }
    }

    private static void insertStockQuantities(Connection con, Scanner sc) throws SQLException
    {
        List<Product> productsToInsert = new ArrayList<>();
        System.out.print("Enter the number of products to insert: ");
        int n = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < n; i++) {
            System.out.print("Enter product ID: ");
            int prod_id = sc.nextInt();
            sc.nextLine(); // Consume newline
            System.out.print("Enter product name: ");
            String prod_name = sc.nextLine();
            System.out.print("Enter stock quantity: ");
            int stockQuantity = sc.nextInt();
            sc.nextLine(); // Consume newline
            productsToInsert.add(new Product(prod_id, stockQuantity, prod_name));
        }
        String query = "INSERT INTO products (prod_id, product_name, stock_quantity) VALUES (?, ?, ?);";
        try (PreparedStatement pstmt = con.prepareStatement(query)) {
            for (Product product : productsToInsert) {
                pstmt.setInt(1, product.getProductId());
                pstmt.setString(2, product.getProductName());
                pstmt.setInt(3, product.getStockQuantity());
                pstmt.addBatch(); // Add to batch
            }
        int[] insertCounts = pstmt.executeBatch(); // Execute the batch
        System.out.println("Products inserted successfully. Rows affected: " + insertCounts.length);
        } catch (SQLException e) {
            System.out.println("Error during insertion: " + e.getMessage());
        }
    }

    private static void updateStockQuantities(Connection con, Scanner sc) throws SQLException
    {
        List<Product> prodsToUpdate = new ArrayList<>();
        System.out.print("Enter the number of products to update: ");
        int n = sc.nextInt();
        sc.nextLine();

        for(int i = 0 ; i < n ; i++)
        {
            System.out.print("Enter product ID: ");
            int prod_id = sc.nextInt();
            sc.nextLine();
            System.out.print("Enter new Stock Quantity: ");
            int stockQuantity = sc.nextInt();
            sc.nextLine();
            System.out.print("Enter product name: ");
            String prod_name = sc.nextLine();
            prodsToUpdate.add(new Product(prod_id, stockQuantity, prod_name));
        }

        String query = "update products set stock_quantity = ? where prod_id = ?;";
        try(PreparedStatement pstmt = con.prepareStatement(query)){
            for(Product prod : prodsToUpdate){
                pstmt.setInt(1,prod.getStockQuantity());
                pstmt.setInt(2,prod.getProductId());
                pstmt.addBatch();
            }
            int[] updateCounts = pstmt.executeBatch();
            System.out.println("Products updates Successfully. Row affected: "+updateCounts.length);
        }catch(SQLException e){
            System.out.println(e.getMessage());
        }
    }

    private static void viewStock(Connection con, Scanner sc) throws SQLException
    {
        String query = "select * from products;";
        Statement stmt = con.createStatement();
        ResultSet rs = stmt.executeQuery(query);
        while (rs.next()) {
                System.out.printf("%d\t| %s\t| %d%n", rs.getInt(1), rs.getString(2), rs.getInt(3));
           }
    }
}
