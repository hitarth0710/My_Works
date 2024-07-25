import java.sql.*;
public class Practical1_1 {

    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/hitarth", "root","mysql");
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("select * from student");
           while (rs.next()) {
                System.out.printf("%d\t| %s\t| %s%n", rs.getInt(1), rs.getString(2), rs.getString(3));
           }
            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }

    }

}