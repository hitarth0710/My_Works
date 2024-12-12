<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.sql.*,java.io.*"%>

<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>JSP Page</title>
</head>
<body>
<%
    int id = Integer.parseInt(request.getParameter("id"));
    out.print(id);
    try {
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/hitarth", "root", "mysql");
        PreparedStatement pstm = con.prepareStatement("delete from jsp where id=?");
        pstm.setInt(1, id);
        int x = pstm.executeUpdate();
        out.println("Deleted");
    } catch (Exception e) {
        out.print(e);
    }
%>
<jsp:forward page="Display.jsp"></jsp:forward>
</body>
</html>