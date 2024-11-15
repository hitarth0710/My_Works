import java.util.Scanner;
import java.sql.*;

public class question2_ass1
{
    private static final String url = "jdbc:mysql://localhost:3306/hitarth";
    private static final String username = "root";
    private static final String password = "mysql";
    public static void main(String[] args){
        System.out.println("Welcome to Attendance Tracker.");
        Scanner sc = new Scanner(System.in);
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
        }catch(Exception e){
            System.out.println(e.getMessage());
        }

        try{
            Connection con = DriverManager.getConnection(url,username,password);
            while(true)
            {
                System.out.println("1. Add attendance record");
                System.out.println("2. Retrieve and display attendance records");
                System.out.println("3. Provide summary report");
                System.out.println("4. Exit");
                System.out.print("Enter your choice: ");
                int choice = sc.nextInt();
                sc.nextLine();// Consume newline
                switch(choice)
                {
                    case 1:
                        addAttendanceRecord(con,sc);
                        break;
                    case 2:
                        reviweAttendance(con,sc);
                        break;
                    case 3:
                        provideSumRep(con,sc);
                        break;
                    case 4:
                        con.close();
                        sc.close();
                        System.out.println("Exiting...");
                        return;
                    default:
                        System.out.println("Invalid choice");
                        break;
                }
            }
        }catch(SQLException e){
            System.out.println(e.getMessage());
        }
    }

    private static void addAttendanceRecord(Connection con, Scanner sc) throws SQLException
    {
        String query = "insert into attendance (emp_id, date, status) values (?, ?, ?);";
        PreparedStatement pstmt = con.prepareStatement(query);
        System.out.print("Enter Employee ID: ");
        int empid = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter date (YYYY-MM-DD): ");
        String date = sc.nextLine();
        System.out.print("Enter Status (present/absent/leave): ");
        String status = sc.nextLine();
        pstmt.setInt(1,empid);
        pstmt.setDate(2, Date.valueOf(date));
        pstmt.setString(3, status);
        int rowsaff = pstmt.executeUpdate();
        System.out.println("Attendance record added. Rows affected are "+rowsaff);;
    }

    private static void reviweAttendance(Connection con, Scanner sc) throws SQLException
    {
        String query = "select * from attendance where emp_id = ?;";
        System.out.print("Enter employee Id to retrieve records: ");
        int id = sc.nextInt();
        PreparedStatement pstm = con.prepareStatement(query);
        pstm.setInt(1,id);
        ResultSet rs = pstm.executeQuery();
        while(rs.next())
        {
            int attendance = rs.getInt("att_id");
            Date date = rs.getDate("date");
            String status = rs.getString("status");
            System.out.println("ID: "+attendance+", Date: "+date+", Status: "+status);
        }
    }

    private static void provideSumRep(Connection con, Scanner sc) throws SQLException
    {
        System.out.print("Enter Employee id: ");
        int empid = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter start date (YYYY-MM-DD): ");
        String startdate = sc.nextLine();
        System.out.print("Enter end date (YYYY-MM-DD): ");
        String enddate = sc.nextLine();
        String query = "select status, count(*) as count from attendance where emp_id = ? and date between ? and ? group by status;";
        PreparedStatement pstmt = con.prepareStatement(query);
        pstmt.setInt(1, empid);
        pstmt.setDate(2,Date.valueOf(startdate));
        pstmt.setDate(3,Date.valueOf(enddate));
        ResultSet rs = pstmt.executeQuery();
        System.out.println("Summary Report for employee ID: "+empid);
        while(rs.next())
        {
            String status = rs.getString("status");
            int count = rs.getInt("count");
            System.out.println("Status: "+status+", Count: "+count);
        }
    }
}