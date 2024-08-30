import java.sql.*;
import java.util.Scanner;

public class exam1 {

    private static final String url = "jdbc:mysql://localhost:3306/hitarth";
    private static final String username = "root";
    private static final String password = "mysql";
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
        }catch(Exception e){
            System.out.println("Some error occurred in the code.");
        }

        try {
            Connection con = DriverManager.getConnection(url, username, password);//to hold the connection
            Statement stmt = con.createStatement();

            while (true) {
                System.out.println("1. Creating the table");
                System.out.println("2. Inserting the values in table");
                System.out.println("3. Printing the table");
                System.out.println("4. Exit");
                System.out.print("Enter your choice: ");
                int c = sc.nextInt();
                switch (c) {
                    case 1:
                        //query to create table
                        String crt_table = "CREATE TABLE IF NOT EXISTS mytable (" +
                                "id INT PRIMARY KEY, " +
                                "name VARCHAR(255))";
                        boolean res = stmt.execute(crt_table);
                        if (res) {
                            System.out.println("Table created.");
                        } else {
                            System.out.println("Table not created.");
                        }
                        break;
                    case 2:
                        //inserting into table
                        String Query = "insert into mytable values(?, ?)";
                        PreparedStatement pstmt = con.prepareStatement(Query);
                        System.out.println("How many values you want to enter: ");
                        int n = sc.nextInt();
                        int[] id = new int[n];
                        String[] name = new String[n];
                        for (int i = 0; i < n; i++) {
                            System.out.println("Enter the id of new student: ");
                            id[i] = sc.nextInt();
                            pstmt.setInt(1, id[i]);

                            sc.nextLine();

                            System.out.println("Enter the name of new student: ");
                            name[i] = sc.nextLine();
                            pstmt.setString(2, name[i]);


                            int afr = pstmt.executeUpdate();
                            System.out.println("Rows affected: " + afr);
                        }
                        break;
                    case 3:
                        // printing the whole table
                        String print_table = "select * from mytable";
                        Statement stmt1 = con.createStatement();
                        ResultSet result = stmt1.executeQuery(print_table);
                        while(result.next()) {
                            int id2 = result.getInt("id");
                            String name2 = result.getString("name");
                            System.out.print("ID :" + id2);
                            System.out.println(" Name :" + name2);
                        }
                        break;
                    case 4:
                        con.close();
                        sc.close();
                        System.out.println("Exiting...");
                        return;
                    default:
                        System.out.println("Invalid choice...");
                        break;
                }
            }
        }catch(SQLException e){
            System.out.println(e.getMessage());
        }
    }
}
