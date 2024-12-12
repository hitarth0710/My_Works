import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class ViewAllStudents extends HttpServlet {
    static String url = "jdbc:mysql://localhost:3306/hitarth";

    public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
        res.setContentType("text/html");
        PrintWriter out = res.getWriter();

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(url, "root", "mysql");
            PreparedStatement stmt = con.prepareStatement("SELECT * FROM mytable");
            ResultSet rs = stmt.executeQuery();

            while (rs.next()) {
                out.println("ID: " + rs.getInt(1) + " Name: " + rs.getString(2) + "<br>");
            }

            con.close();
        } catch (Exception e) {
            out.println("Error: " + e.getMessage());
        }
    }
}