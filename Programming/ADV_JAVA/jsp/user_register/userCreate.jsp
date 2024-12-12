<%@page import="java.sql.*,java.io.*"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<head>
    <title>JSP Page</title>
</head>
<body>
<!-- CREATE TABLE <your_table_name> (
    first_name VARCHAR(50),
    middle_name VARCHAR(50),
    last_name VARCHAR(50),
    email VARCHAR(100),
    address TEXT,
    gender VARCHAR(10),
    id INT AUTO_INCREMENT PRIMARY KEY
); -->
<%
    String fname = request.getParameter("fname");
    String mname = request.getParameter("mname");
    String lname = request.getParameter("lname");
    String email = request.getParameter("email");
    String address = request.getParameter("address");
    String gender = request.getParameter("gen");

    try {
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/hitarth", "root", "mysql");

        if (request.getParameter("register") != null) {
            PreparedStatement pst = con.prepareStatement("insert into jsp values(?,?,?,?,?,?,?);");
            pst.setString(1, fname);
            pst.setString(2, mname);
            pst.setString(3, lname);
            pst.setString(4, email);
            pst.setString(5, address);
            pst.setString(6, gender);
            pst.setInt(7, 0);
            int x = pst.executeUpdate();
            out.println("<h3>Data inserted successfully</h3>");
            out.println("<a href='display.jsp'>Display</a>");
        } else {
            %>
            <jsp:forward page="Display.jsp"></jsp:forward>
            <%
        }
    } catch (Exception e) {
        out.print(e);
    }
%>
</body>
</html>