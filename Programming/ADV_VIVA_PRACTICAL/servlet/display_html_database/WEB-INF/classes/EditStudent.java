import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class EditStudent extends HttpServlet {
    static String url = "jdbc:mysql://localhost:3306/hitarth";

    public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
        res.setContentType("text/html");
        PrintWriter out = res.getWriter();
        int id = Integer.parseInt(req.getParameter("id"));
        String name = req.getParameter("name");

        Connection con = null;
        PreparedStatement stmt = null;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            con = DriverManager.getConnection(url, "root", "mysql");
            stmt = con.prepareStatement("UPDATE mytable SET name = ? WHERE id = ?");
            stmt.setString(1, name);
            stmt.setInt(2, id);
            int i = stmt.executeUpdate();
            out.println("Student updated successfully!");
        } catch (ClassNotFoundException e) {
            out.println("Error: MySQL JDBC Driver not found.");
        } catch (SQLException e) {
            out.println("Error: " + e.getMessage());
        } finally {
            try {
                if (stmt != null) stmt.close();
                if (con != null) con.close();
            } catch (SQLException e) {
                out.println("Error closing resources: " + e.getMessage());
            }
        }
    }
}