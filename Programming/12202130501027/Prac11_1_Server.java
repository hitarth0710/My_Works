import java.net.*;
import java.io.*;

public class Prac11_1_Server
{
    public static void main(String[] args) throws IOException
    {
        ServerSocket sersok = new ServerSocket(6000);
        System.out.println("Server is Listening on port number 6000");

        while(true)
        {
            Socket soc = sersok.accept();
            System.out.println("New Client Accepted");
            InputStream input = soc.getInputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(input));
            OutputStream output = soc.getOutputStream();
            PrintWriter writer = new PrintWriter(output,true);
            String line;
            while((line = reader.readLine()) != null)
            {
                System.out.println("Received: " + line);
                writer.println("Server: " + line);
            }
            soc.close();
        }
    }
}



