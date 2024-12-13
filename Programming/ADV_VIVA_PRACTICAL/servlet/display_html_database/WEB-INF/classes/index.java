import java.io.*; 
import javax.servlet.*; 
import javax.servlet.http.*; 
 
public class index extends HttpServlet { 
    
    public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException,  ServletException
    { 
        String operation = req.getParameter("operation"); 
 
        switch (operation) { 
            case "add": 
                req.getRequestDispatcher("AddStudent").forward(req, res); 
                break; 
            case "edit": 
                req.getRequestDispatcher("EditStudent").forward(req, res); 
                break; 
            case "delete": 
                req.getRequestDispatcher("DeleteStudent").forward(req, res); 
                break; 
            case "search": 
                req.getRequestDispatcher("SearchStudent").forward(req, res); 
                break; 
            case "viewAll": 
                req.getRequestDispatcher("ViewAllStudents").forward(req, res); 
                break; 
             
        } 
    } 
} 
