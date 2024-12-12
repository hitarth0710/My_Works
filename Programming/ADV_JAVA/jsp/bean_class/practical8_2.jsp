<%@page contentType="text/html" pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
<head>
    <title>JSP Page</title>
</head>
<body>
    <h1>Student Data</h1>
    <jsp:useBean id="student" class="com.javaBean.practical8" scope="session"></jsp:useBean>
    <table border="1">
        <tr>
            <th>Enroll</th>
            <th>Name</th>
            <th>Email</th>
        </tr>
        <tr>
            <td><jsp:getProperty name="student" property="studentId"/></td>
            <td><jsp:getProperty name="student" property="studentName"/></td>
            <td><jsp:getProperty name="student" property="studentEmail"/></td>
        </tr>
    </table>
</body>
</html>