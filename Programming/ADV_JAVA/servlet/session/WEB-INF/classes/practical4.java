import java.io.*;
import java.sql.*;
import javax.servlet.http.*;
import javax.servlet.*;

public class practical4 extends HttpServlet {

    static String url = "jdbc:mysql://localhost:3306/hitarth";

    public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
        res.setContentType("text/html");
        PrintWriter out = res.getWriter();

        int id = Integer.parseInt(req.getParameter("id"));
        String name = req.getParameter("name");

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            HttpSession session = req.getSession();
            Integer accessCount = (Integer) session.getAttribute("accessCount");
            if (accessCount == null) {
                accessCount = 0;
            }
            accessCount++;
            session.setAttribute("accessCount", accessCount);

            out.println("<br>");
            out.println("<h2>Session Access Count: " + accessCount + "</h2><br>");

            if (accessCount == 10) {
                out.println("Max sessions reached<br>");
                session.invalidate();
            }

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