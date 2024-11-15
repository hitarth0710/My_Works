import java.sql.*;
import java.util.*;

class User{
    private String username;
    private String email;
    private String password;
    public User(String username, String email, String password)
    {
        this.username = username;
        this.email = email;
        this.password = password;
    }

    public String getUsername()
    {
        return username;
    }

    public String getEmail()
    {
        return email;
    }

    public String getPassword()
    {
        return password;
    }
}


public class question4_ass1
{
    private static final String url = "jdbc:mysql://localhost:3306/hitarth";
    private static final String username = "root";
    private static final String password = "mysql";
    public static void main(String[] args)
    {
        System.out.println("Welcome to User Registration System.");
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
                System.out.println("1. Register multiple users");
                System.out.println("2. Displaying the Records of Users");
                System.out.println("3. Exit");
                System.out.print("Enter your choice: ");
                int choice = sc.nextInt();
                sc.nextLine();

                switch(choice)
                {
                    case 1:
                        multipleUserReg(con,sc);
                        break;
                    case 2:
                        viewUsers(con,sc);
                        break;
                    case 3:
                        con.close();
                        sc.close();
                        System.out.println("Exiting....");
                        return;
                    default:
                        System.out.println("Invalid choice");
                }
            }
        }catch(SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    private static void multipleUserReg(Connection con, Scanner sc) throws SQLException
    {
        List<User> usersToRegister = new ArrayList<>();
        System.out.println("Enter the number of users to register: ");
        int n = sc.nextInt();
        sc.nextLine();

        for(int i = 0 ; i < n ; i++)
        {
            System.out.println("Enter Username: ");
            String username = sc.nextLine();
            System.out.println("Enter Email: ");
            String email = sc.nextLine();
            System.out.println("Enter Password: ");
            String password = sc.nextLine();
            usersToRegister.add(new User(username,email,password));//adding it to a different class's object
        }

        String query = "insert into users (username, email, password) values (?, ?, ?);";
        try(PreparedStatement pstmt = con.prepareStatement(query)){
            for(User user : usersToRegister)
            {
                pstmt.setString(1, user.getUsername());
                pstmt.setString(2, user.getEmail());
                pstmt.setString(3, user.getPassword());
                pstmt.addBatch();//adding to a batch
            }
            pstmt.executeBatch();//execute the batch
            System.out.println("Users Registered Successfully.");
        }catch(SQLException e){
            System.out.println("Error during registration: " + e.getMessage());
        }
    }
    private static void viewUsers(Connection con, Scanner sc) throws SQLException
    {
        String query = "select * from users;";
        Statement stmt = con.createStatement();
        ResultSet rs = stmt.executeQuery(query);
           while (rs.next()) {
                System.out.printf("%d\t| %s\t| %s\t| %s%n", rs.getInt(1), rs.getString(2), rs.getString(3), rs.getString(4));
           }
    }
}

