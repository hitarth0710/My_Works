import java.util.Scanner;
import java.sql.*;

public class question1_ass1
{
    private static final String url = "jdbc:mysql://localhost:3306/hitarth";
    private static final String username = "root";
    private static final String password = "mysql";
    public static void main(String[] args)
    {
        System.out.println("Welcome to Library management system.");
        Scanner sc = new Scanner(System.in);
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
        }catch(Exception e){
            System.out.println(e.getMessage());
        }

        try{
            Connection con = DriverManager.getConnection(url, username, password);
            while(true){
                System.out.println("1. Add new book");
                System.out.println("2. Update book details");
                System.out.println("3. Delete book");
                System.out.println("4. View all available books");
                System.out.println("5. Check out book");
                System.out.println("6. Return book");
                System.out.println("7. Exit");
                System.out.print("Enter your choice: ");
                int choice = sc.nextInt();
                sc.nextLine();

                switch(choice){
                    case 1:
                        addBook(con,sc);
                        break;
                    case 2:
                        updateBook(con,sc);
                        break;
                    case 3:
                        deleteBook(con,sc);
                        break;
                    case 4:
                        viewBook(con,sc);
                        break;
                    case 5:
                        checkOutBook(con,sc);
                        break;
                    case 6:
                        returnBook(con,sc);
                        break;
                    case 7:
                        con.close();
                        sc.close();
                        System.out.println("Exiting....");
                        return;
                    default:
                        System.out.println("Invalid choice...");
                        break;
                }
            }
        }catch(SQLException e){
            System.out.println(e.getMessage());
        }

    }

    private static void addBook(Connection con, Scanner sc) throws SQLException
    {
        String query = "insert into books1 (title, author, genre) values (?, ?, ?);";
        PreparedStatement pstmt = con.prepareStatement(query);
        System.out.println("Enter Book Title: ");
        String title = sc.nextLine();
        System.out.println("Enter Book Author: ");
        String author = sc.nextLine();
        System.out.println("Enter Book Genre: ");
        String genre = sc.nextLine();
        pstmt.setString(1, title);
        pstmt.setString(2, author);
        pstmt.setString(3, genre);
        int rowaffected = pstmt.executeUpdate();
        System.out.println("Book added succesfully. Rows Affected are "+rowaffected);
    }

    private static void updateBook(Connection con, Scanner sc) throws SQLException
    {
        System.out.println("Enter the bookid to update:");
        int id = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter new title: ");
        String title = sc.nextLine();
        System.out.print("Enter new author: ");
        String author = sc.nextLine();
        System.out.print("Enter new genre: ");
        String genre = sc.nextLine();
        String query = "update books1 set title = ?, author = ?, genre = ? where book_id = ?;";
        PreparedStatement pstmt = con.prepareStatement(query);
        pstmt.setString(1, title);
        pstmt.setString(2, author);
        pstmt.setString(3, genre);
        pstmt.setInt(4, id);
        int rowsAffected = pstmt.executeUpdate();
        System.out.println("Book details updated successfully. Rows Affected are "+rowsAffected);
    }

    private static void deleteBook(Connection con, Scanner sc) throws SQLException
    {
        System.out.println("Enter the bookid to delete:");
        int id = sc.nextInt();
        sc.nextLine();
        String query = "delete from books1 where book_id=?;";
        PreparedStatement preparedStatement = con.prepareStatement(query);
        preparedStatement.setInt(1, id);
        int rows = preparedStatement.executeUpdate();
        System.out.println("Book deleted Successfully. Rows Affected are "+rows);
    }

    private static void viewBook(Connection con, Scanner sc) throws SQLException
    {
        String query = "select * from books1 where status = 'available';";
        Statement stmt = con.createStatement();
        ResultSet rs = stmt.executeQuery(query);
        while(rs.next())
        {
            int bookId = rs.getInt("book_id");
            String title = rs.getString("title");
            String author = rs.getString("author");
            String genre = rs.getString("genre");
            String status = rs.getString("status");
            System.out.println("ID: " + bookId + ", Title: " + title + ", Author: " + author + ", Genre: " + genre + ", Status: " + status);
        }
    }

    private static void checkOutBook(Connection con, Scanner sc) throws SQLException
    {
        System.out.print("Enter book ID to check out: ");
        int bookId = sc.nextInt();
        String query = "UPDATE books1 SET status = 'checked out' WHERE book_id = ?";
        PreparedStatement pstmt = con.prepareStatement(query);
        pstmt.setInt(1, bookId);
        int rowsAffected = pstmt.executeUpdate();
        System.out.println("Book checked out successfully. Rows affected: " + rowsAffected);
    }

    private static void returnBook(Connection con, Scanner sc) throws SQLException
    {
        System.out.print("Enter book ID to return: ");
        int bookId = sc.nextInt();
        String query = "UPDATE books1 SET status = 'available' WHERE book_id = ?";
        PreparedStatement pstmt = con.prepareStatement(query);
        pstmt.setInt(1, bookId);
        int rowsAffected = pstmt.executeUpdate();
        System.out.println("Book returned successfully. Rows affected: " + rowsAffected);
    }
}
