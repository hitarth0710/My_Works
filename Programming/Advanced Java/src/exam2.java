import java.sql.*;
import java.util.Scanner;

//batch in JDBC
public class exam2 {
    private static final String url = "jdbc:mysql://localhost:3306/hitarth";
    private static final String username = "root";
    private static final String password = "mysql";
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection con = DriverManager.getConnection(url, username, password);//to hold the connection
        Statement stmt = con.createStatement();
        String query = "insert into exam2 values(?, ?, ?)";
        PreparedStatement pstmt = con.prepareStatement(query);
        while(true){
            System.out.print("Enter name: ");
            String name = sc.nextLine();
            System.out.print("Enter age: ");
            int age = sc.nextInt();
            System.out.print("Enter marks: ");
            double marks = sc.nextDouble();
            System.out.print("Enter more data(Y/N): ");
            String choice = sc.next();
            /*
            using just statement and making batch out of it
            String query = String.format("insert into exam2 values('%s', %d, %f)",name,age,marks);
            stmt.addBatch(query);
             */
            pstmt.setString(1,name);
            pstmt.setInt(2,age);
            pstmt.setDouble(3,marks);
            pstmt.addBatch();
            if(choice.toUpperCase().equals("N")){
                break;
            }
        }
        int[] afr = pstmt.executeBatch();//it is in array form
        for(int i = 0;i<afr.length;i++){
            if(afr[i] == 0){
                System.out.println("Query: "+(i)+" not executed successfully.");
            }
        }

        con.close();
        sc.close();

    }
}
