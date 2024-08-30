import java.sql.*;
public class Practical1_1 {

    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/hitarth", "root","mysql");
            Statement stmt = con.createStatement(ResultSet.TYPE_FORWARD_ONLY,ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = stmt.executeQuery("select * from student");
           while (rs.next()) {
                System.out.printf("%d\t| %s\t| %s%n", rs.getInt(1), rs.getString(2), rs.getString(3));
           }
            System.out.println("Printing the metadata for the given data.");
           ResultSetMetaData rsmd = rs.getMetaData();
           System.out.println("Total columns: "+rsmd.getColumnCount());
           System.out.println("Column Name of 1st column: "+rsmd.getColumnName(1));
           System.out.println("Column Type of 1st column: "+rsmd.getColumnTypeName(1));
            stmt.close();
            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }

    }

}