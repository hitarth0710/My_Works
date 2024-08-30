import java.sql.*;
import java.util.Scanner;

public class Practical1_2 {
    public static final String URL = "jdbc:mysql://localhost:3306/hitarth";
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection con = DriverManager.getConnection(URL,"root","mysql");

        String Query = "insert into students values(?, ?, ?)";
        PreparedStatement pstmt = con.prepareStatement(Query);

        System.out.println("How many student's information you want to enter: ");
        int n = sc.nextInt();
        int [] id = new int[n];
        String[] name = new String[n];
        String[] city = new String[n];
        for(int i=0;i<n;i++){
              System.out.println("Enter the id of new student: ");
              id[i] = sc.nextInt();
              pstmt.setInt(1,id[i]);

              sc.nextLine();

              System.out.println("Enter the name of new student: ");
              name[i] = sc.nextLine();
              pstmt.setString(2,name[i]);
              System.out.println("Enter the city of new student: ");
              city[i] = sc.nextLine();
              pstmt.setString(3,city[i]);
              int afr = pstmt.executeUpdate();
              System.out.println("Rows affected: "+afr);
        }
        sc.close();
    }
}
