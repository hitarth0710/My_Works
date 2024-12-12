import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class practical6 extends HttpServlet {

    // Inner Student class
    public static class Student {
        private String[] rollNumbers;

        // Constructor to initialize roll numbers
        public Student() {
            this.rollNumbers = new String[]{"1001", "1002", "1003", "1004", "1005"};
        }

        // Method to get the roll numbers
        public String[] getRollNumbers() {
            return rollNumbers;
        }
    }

    // Servlet1 inner class
    public static class Servlet1 extends HttpServlet {
        protected void doGet(HttpServletRequest request, HttpServletResponse response)
                throws ServletException, IOException {
            // Create a new Student object
            Student student = new Student();
            // Get roll numbers
            String[] rollNumbers = student.getRollNumbers();
            // Set response content type
            response.setContentType("text/html");
            PrintWriter out = response.getWriter();
            out.println("<h1>Roll Numbers from Servlet 1</h1>");
            for (String rollNo : rollNumbers) {
                out.println("<p>" + rollNo + "</p>");
            }
        }
    }

    // Servlet2 inner class
    public static class Servlet2 extends HttpServlet {
        protected void doGet(HttpServletRequest request, HttpServletResponse response)
                throws ServletException, IOException {
            // Create a new Student object
            Student student = new Student();
            // Get roll numbers
            String[] rollNumbers = student.getRollNumbers();
            // Set response content type
            response.setContentType("text/html");
            PrintWriter out = response.getWriter();
            out.println("<h1>Roll Numbers from Servlet 2</h1>");
            for (String rollNo : rollNumbers) {
                out.println("<p>" + rollNo + "</p>");
            }
        }
    }
}