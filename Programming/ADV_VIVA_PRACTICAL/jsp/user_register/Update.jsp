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
    String fname = request.getParameter("fname");
    String mname = request.getParameter("mname");
    String lname = request.getParameter("lname");
    String email = request.getParameter("email");
    String address = request.getParameter("address");
    String gender = request.getParameter("gen");
    int id = Integer.parseInt(request.getParameter("id"));

    if (request.getParameter("Submit") != null) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/hitarth", "root", "mysql");
            PreparedStatement pst = con.prepareStatement("update jsp set first_name=?, middle_name=?, last_name=?, email=?, address=?, gender=? where id=?");
            pst.setString(1, fname);
            pst.setString(2, mname);
            pst.setString(3, lname);
            pst.setString(4, email);
            pst.setString(5, address);
            pst.setString(6, gender);
            pst.setInt(7, id);
            int x = pst.executeUpdate();
            if (x == 1) {
                %>
                <script>
                    alert("Data updated");
                </script>
                <%
                out.print("<a href='Display.jsp'>Display Page</a>");
            } else {
                out.print("not updated");
            }
        } catch (Exception e) {
            out.print(e);
        }
    }
%>
<table style="min-height: 100vh; width: 100%; display: grid; justify-content: center;">
    <form action="#" method="post">
        <%
            try {
                Class.forName("com.mysql.cj.jdbc.Driver");
                Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/hitarth", "root", "mysql");
                int id1 = Integer.parseInt(request.getParameter("id"));
                PreparedStatement pst = con.prepareStatement("select * from jsp where id=?");
                pst.setInt(1, id1);
                ResultSet rs = pst.executeQuery();
                while (rs.next()) {
        %>
        <tr>
            <td>
                <label for="">Enter FirstName: </label>
            </td>
            <td>
                <input type="text" name="fname" value="<%= rs.getString(1) %>">
            </td>
        </tr>
        <tr>
            <td>
                <label for="">Enter MiddleName: </label>
            </td>
            <td>
                <input type="text" name="mname" value="<%= rs.getString(2) %>">
            </td>
        </tr>
        <tr>
            <td>
                <label for="">Enter LastName: </label>
            </td>
            <td>
                <input type="text" name="lname" value="<%= rs.getString(3) %>">
            </td>
        </tr>
        <tr>
            <td>
                <label for="">Enter Email-id:</label>
            </td>
            <td>
                <input type="email" name="email" value="<%= rs.getString(4) %>">
            </td>
        </tr>
        <tr>
            <td>
                <label for="">Enter Address:</label>
            </td>
            <td>
                <textarea name="address" id="" cols="30" rows="10"><%= rs.getString(5) %></textarea>
            </td>
        </tr>
        <tr>
            <td>
                <label for="">Gender: </label>
            </td>
            <td>
                Male <input type="radio" name="gen" value="male" id="">
                Female <input type="radio" name="gen" value="female" id="">
            </td>
        </tr>
        <tr>
            <td>
                <button type="submit" name="Submit">Update</button>
            </td>
        </tr>
        <%
                }
            } catch (Exception e) {
                out.print(e);
            }
        %>
    </form>
</table>
</body>
</html>