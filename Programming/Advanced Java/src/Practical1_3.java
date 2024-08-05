import java.sql.*;
import java.util.Scanner;

public class Practical1_3 {
    public static final String URL = "jdbc:mysql://localhost:3306/hitarth";
    public static void main(String args[]) throws Exception{
        Scanner sc = new Scanner(System.in);
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection con = DriverManager.getConnection(URL,"root","mysql");

        String query = "UPDATE student SET id = ? WHERE city = ?;";
        PreparedStatement pstm = con.prepareStatement(query);

        System.out.println("How many rows you want to update: ");
        int n = sc.nextInt();
        sc.nextLine();
        int[] id = new int[n];
        String[] name = new String[n];
        //String[] city = new String[n];
        for (int i = 0;i<n;i++)
        {
            System.out.println("Enter the id: ");
            id[i] = sc.nextInt();
            pstm.setInt(1, id[i]);
            sc.nextLine();
            System.out.println("Enter the City: ");
            name[i] = sc.nextLine();
            pstm.setString(2, name[i]);

            int afr = pstm.executeUpdate();
            System.out.println("Rows Affected in updating is "+afr);
        }
    }
}
