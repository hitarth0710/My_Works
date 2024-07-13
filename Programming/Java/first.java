import java.sql.*;

        public class first{
        public static void main(String []args)
        {
                try {
                        Class.forName("com.mysql.jdbc.Driver");
                        Connection con=DriverManager.getConnection("jdbc:mysql//localhost:3306/test","root","mysql");
                        Statement stmt=con.createStatement();
                        ResultSet rs=stmt.executeQuery("SELECT * from ");
                }
                catch(Exception e){

        }
        }
}