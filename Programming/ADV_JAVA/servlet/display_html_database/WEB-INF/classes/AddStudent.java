import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

//table with first column id and second column name (in all the files)
public class AddStudent extends HttpServlet {
    static String url = "jdbc:mysql://localhost:3306/hitarth";

    public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
        res.setContentType("text/html");
        PrintWriter out = res.getWriter();
        int id = Integer.parseInt(req.getParameter("id"));
        String name = req.getParameter("name");

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(url, "root", "mysql");
            PreparedStatement stmt = con.prepareStatement("INSERT INTO mytable VALUES (?, ?)");
            stmt.setInt(1, id);
            stmt.setString(2, name);
            int i = stmt.executeUpdate();
            out.println("Student added successfully!");
            con.close();
        } catch (Exception e) {
            out.println("Error: " + e.getMessage());
        }
    }
}