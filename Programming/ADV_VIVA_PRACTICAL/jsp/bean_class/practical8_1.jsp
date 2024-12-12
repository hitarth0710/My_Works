<%@page contentType="text/html" pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
<head>
    <title>Student Registration Form</title>
</head>
<body>
    <div class="container">
        <div class="form-container">
            <form action="practical8_1.jsp" method="post">
                <fieldset style="width:fit-content;padding:30px;">
                    <legend style="font-weight: 800;font-size: 30px;">User Details</legend>
                    <form action="AddStudent" method="get">
                        <table class="table">
                            <tr>
                                <td><span>Student Enroll: </span></td>
                                <td><input type="number" placeholder="Enter ID" name="studentId" required></td>
                            </tr>
                            <tr>
                                <td><span>Name: </span></td>
                                <td><input type="text" placeholder="Enter Name" name="studentName" required></td>
                            </tr>
                            <tr>
                                <td><span>Email:</span></td>
                                <td><input type="text" placeholder="Enter your e-mail" name="studentEmail" required></td>
                            </tr>
                        </table>
                        <button type="submit" name="submit">Submit</button>
                    </form>
                </fieldset>
            </form>
        </div>
    </div>

    <%
        if ("POST".equals(request.getMethod()) && request.getParameter("submit") != null) {
    %>
        <jsp:useBean id="student" class="com.javaBean.practical8" scope="session"></jsp:useBean>
        <jsp:setProperty name="student" property="studentId" param="studentId"></jsp:setProperty>
        <jsp:setProperty name="student" property="studentName" param="studentName"></jsp:setProperty>
        <jsp:setProperty name="student" property="studentEmail" param="studentEmail"></jsp:setProperty>
        <jsp:forward page="practical8_2.jsp"></jsp:forward>
    <%
        }
    %>
</body>
</html>