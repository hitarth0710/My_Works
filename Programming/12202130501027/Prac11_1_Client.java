import java.net.*;
import java.io.*;

public class Prac11_1_Client
{
    public static void main(String[] args) throws IOException
    {
        Socket soc = new Socket("localhost",6000);
        System.out.println("Connected to the server.");

        OutputStream output = soc.getOutputStream();
        PrintWriter pw = new PrintWriter(output,true);
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        while(true)
        {
            System.out.print("Enter the Message :");
            String msg = reader.readLine();
            pw.println(msg);

            InputStream input = soc.getInputStream();
            BufferedReader response = new BufferedReader(new InputStreamReader(input));

            String serevresponse;
            if((serevresponse = response.readLine()) != null)
            {
                System.out.println(serevresponse);
            }
        }
    }
}
