import java.sql.*;
import java.util.*;


public class question5_ass {
    private static final String url = "jdbc:mysql://localhost:3306/bookstore";
    private static final String username = "root";
    private static final String password = "mysql";
    public static void main(String[] args){
        System.out.println("Welcome to Library Management System.");
        Scanner sc = new Scanner(System.in);
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
        }catch(Exception e){
            System.out.println(e.getMessage());
        }

        try(Connection con = DriverManager.getConnection(url,username,password)){
        while (true) {
            System.out.println("1. Add a new book");
            System.out.println("2. Borrow a book");
            System.out.println("3. Return a book");
            System.out.println("4. View available books");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            sc.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    System.out.print("Enter book title: ");
                    String title = sc.nextLine();
                    System.out.print("Enter book author: ");
                    String author = sc.nextLine();
                    addBook(con, title, author);
                    break;
                case 2:
                    System.out.print("Enter borrower name: ");
                    String borrowerName = sc.nextLine();
                    System.out.print("Enter book ID: ");
                    int bookId = sc.nextInt();
                    sc.nextLine(); // Consume newline
                    borrowBook(con, borrowerName, bookId);
                    break;
                case 3:
                    System.out.print("Enter book ID: ");
                    int returnBookId = sc.nextInt();
                    sc.nextLine(); // Consume newline
                    returnBook(con, returnBookId);
                    break;
                case 4:
                    getAvailableBooks(con);
                    break;
                case 5:
                    sc.close();
                    System.out.println("Exiting...");
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
        }catch(Exception e){
            System.out.println(e.getMessage());
        }
    }

    public static void addBook(Connection con, String title, String author) throws SQLException {
        String query = "{CALL addbookss(?, ?)}";
        try (CallableStatement stmt = con.prepareCall(query)) {
            stmt.setString(1, title);
            stmt.setString(2, author);
            stmt.execute();
            System.out.println("Book added successfully.");
        }
    }

    public static void borrowBook(Connection con, String borrowerName, int bookId) throws SQLException {
        String query = "{CALL borrowbookss(?, ?)}";
        try (CallableStatement stmt = con.prepareCall(query)) {
            stmt.setString(1, borrowerName);
            stmt.setInt(2, bookId);
            stmt.execute();
            System.out.println("Book borrowed successfully.");
        }
    }

    public static void returnBook(Connection con, int bookId) throws SQLException {
        String query = "{CALL returnbookss(?)}";
        try (CallableStatement stmt = con.prepareCall(query)) {
            stmt.setInt(1, bookId);
            stmt.execute();
            System.out.println("Book returned successfully.");
        }
    }

    public static void getAvailableBooks(Connection con) throws SQLException {
        String query = "{CALL getAvailableBookss()}";
        try (CallableStatement stmt = con.prepareCall(query);
             ResultSet rs = stmt.executeQuery()) {
            while (rs.next()) {
                System.out.printf("Book ID: %d, Title: %s, Author: %s%n", rs.getInt("book_id"), rs.getString("title"), rs.getString("author"));
            }
        }
    }
}
