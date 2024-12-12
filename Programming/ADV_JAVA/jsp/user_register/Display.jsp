<%@page import="java.sql.*,java.io.*"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>JSP Page</title>
</head>
<body>
<%
    try {
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/hitarth", "root", "mysql");

        Statement stm = con.createStatement();
        ResultSet rs = stm.executeQuery("select * from jsp");

        out.println("<table border='2'>");
        out.println("<thead><tr><th>First-Name</th><th>Middle-Name</th><th>Last-Name</th><th>Email</th><th>Address</th><th>Gender</th></tr></thead>");

        while (rs.next()) {
            out.println("<tr>");
            out.println("<td>" + rs.getString(1) + "</td>");
            out.println("<td>" + rs.getString(2) + "</td>");
            out.println("<td>" + rs.getString(3) + "</td>");
            out.println("<td>" + rs.getString(4) + "</td>");
            out.println("<td>" + rs.getString(5) + "</td>");
            out.println("<td>" + rs.getString(6) + "</td>");
            out.println("<td><a href='Update.jsp?id=" + rs.getInt(7) + "'>update</td>");
            out.println("<td><a href='Delete.jsp?id=" + rs.getInt(7) + "'>delete</td>");
            out.println("</tr>");
        }

        out.println("</table>");
        out.println("<a href='practical7.html'>Insert Data</a>");
    } catch (Exception e) {
        out.println(e);
    }
%>
</body>
</html>