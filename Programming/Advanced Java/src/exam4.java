import java.sql.*;
import java.util.Scanner;


public class exam4 {
    private static final String url = "jdbc:mysql://localhost:3306/transaction";
    private static final String username = "root";
    private static final String password = "mysql";
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection con = DriverManager.getConnection(url, username, password);
        con.setAutoCommit(false);
        String debit_query = "update accounts set balance = balance - ? where acc_no = ?";
        String credit_query = "update accounts set balance = balance + ? where acc_no = ?";
        PreparedStatement dpstm = con.prepareStatement(debit_query);
        PreparedStatement cpstm = con.prepareStatement(credit_query);
        System.out.print("Enter the amount of transaction: ");
        double amount = sc.nextDouble();
        System.out.print("Enter the debiting account number : ");
        int dacc_no = sc.nextInt();
        System.out.print("Enter the crediting account number : ");
        int cacc_no = sc.nextInt();
        dpstm.setDouble(1,amount);
        dpstm.setInt(2,dacc_no);
        cpstm.setDouble(1,amount);
        cpstm.setInt(2,cacc_no);
        dpstm.executeUpdate();
        cpstm.executeUpdate();
        if(issufficient(con,dacc_no,amount)){
            con.commit();
            System.out.println("Transaction Successful");
        }else{
            con.rollback();
            System.out.println("Transaction Failed.");
        }


        con.close();
        sc.close();
    }
    static boolean issufficient(Connection con, int acc_number, double amount)
    {
        try{
            String query = "select balance from accounts where acc_no = ?";
            PreparedStatement pstmt = con.prepareStatement(query);
            pstmt.setInt(1,acc_number);
            ResultSet res = pstmt.executeQuery();
            if(res.next()){
                double cur_bal = res.getDouble("balance");
                if(amount > cur_bal){
                    return false;
                }else{
                    return true;
                }
            }
        }catch(SQLException e){
            System.out.println(e.getMessage());
        }
        return false;
    }


}
