//File: MyClient.java

import java.net.*;
import java.io.*;

class MyClient {
    public static void main(String args[]) throws Exception {
        String sockin;
        Socket csock = null;
        try {
            csock = new Socket(InetAddress.getLocalHost(), 2000);
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedReader br_sock = new BufferedReader(new InputStreamReader(csock.getInputStream()));
            PrintStream ps = new PrintStream(csock.getOutputStream());
            System.out.println("Start echoing... type 'end' to terminate");
            while ((sockin = br.readLine()) != null) {
                ps.println(sockin);
                if (sockin.equals("end"))
                    break;
                else
                    System.out.println("echoed from server:" + br_sock.readLine());

            }
        } catch (UnknownHostException e) {
            System.out.println(e.toString());
        } finally {
            if (csock != null) {
                csock.close();
            }
        }
    }
}