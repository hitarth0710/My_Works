import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class practical5 extends HttpServlet {

    private String supportEmail;
    private static int servletHitCount = 0;

    public void init() throws ServletException {
        supportEmail = getServletConfig().getInitParameter("supportEmail");
        ServletContext context = getServletContext();
        if (context.getAttribute("appHitCount") == null) {
            context.setAttribute("appHitCount", 0);
        }
    }

    protected void doGet(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {
        res.setContentType("text/html");
        PrintWriter out = res.getWriter();

        servletHitCount++;
        ServletContext context = getServletContext();
        Integer appHitCount = (Integer) context.getAttribute("appHitCount");
        appHitCount++;
        context.setAttribute("appHitCount", appHitCount);

        String adminEmail = context.getInitParameter("adminEmail");

        out.println("<html><head><title>Simple Email Servlet</title></head><body>");
        out.println("<p>Servlet Init Param: " + supportEmail + "</p>");
        out.println("<p>Context Init Param: " + adminEmail + "</p>");
        out.println("<br>");
        out.println("<p>Servlet Hit Count: " + servletHitCount + "</p>");
        out.println("<p>Web Application Hit Count: " + appHitCount + "</p>");
        out.println("</body></html>");
    }
}