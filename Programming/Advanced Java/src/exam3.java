import java.sql.*;
import java.util.Scanner;

public class exam3
{
    private static final String url = "jdbc:mysql://localhost:3306/hitarth";
    private static final String username = "root";
    private static final String password = "mysql";
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection con = DriverManager.getConnection(url, username, password);//to hold the connection
        CallableStatement cstmt = con.prepareCall("{call gettitle(?, ?)}");
        cstmt.setInt(1,1203);
        cstmt.registerOutParameter(2,Types.VARCHAR);
        cstmt.execute();
        System.out.println(cstmt.getString(2));

        con.close();
        sc.close();
    }
}


