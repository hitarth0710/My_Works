import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class index extends HttpServlet {

    public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
        res.setContentType("text/html");
        PrintWriter out = res.getWriter();
        String name = req.getParameter("Name");
        int age = Integer.parseInt(req.getParameter("Age"));
        String email = req.getParameter("Email");
        String contact = req.getParameter("Num");

        out.println("<html>");
        out.println("<head>");
        out.println("<title>Login</title>");
        out.println("</head>");
        out.println("<body>");
        out.println("<h1>Welcome!</h1>");
        out.println("<br>");
        out.println("Name: " + name);
        out.println("<br>");
        out.println("Age: " + age);
        out.println("<br>");
        out.println("Email: " + email);
        out.println("<br>");
        out.println("Contact No.: " + contact);
        out.println("</body>");
        out.println("</html>");
    }
}