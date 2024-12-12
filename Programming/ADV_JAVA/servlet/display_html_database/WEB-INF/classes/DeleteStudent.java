import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;


public class DeleteStudent extends HttpServlet {
    static String url = "jdbc:mysql://localhost:3306/hitarth";

    public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
        res.setContentType("text/html");
        PrintWriter out = res.getWriter();
        int id = Integer.parseInt(req.getParameter("id"));

        try {
            Connection con = DriverManager.getConnection(url, "root", "mysql");
            PreparedStatement stmt = con.prepareStatement("DELETE FROM mytable WHERE id = ?");
            stmt.setInt(1, id);
            int i = stmt.executeUpdate();
            out.println("Student deleted successfully!");
            con.close();
        } catch (Exception e) {
            out.println("Error: " + e.getMessage());
        }
    }
}