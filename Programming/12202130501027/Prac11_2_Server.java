import java.net.*;
import java.io.*;
import java.security.PublicKey;

public class Prac11_2_Server
{
    public static void main(String[] args) throws Exception
    {
        // Create a new DatagramSocket
        DatagramSocket socket = new DatagramSocket(1234);

        // Set up the audio file to be sent
        FileInputStream audioFileStream = new FileInputStream("C:\\Users\\rajes\\OneDrive\\Desktop\\works\\harvard.wav");        byte[] audioData = new byte[1024];
        int bytesRead = audioFileStream.read(audioData, 0, audioData.length);
        audioFileStream.close();

        // Listen for incoming UDP packets
        while (true) {
            DatagramPacket packet = new DatagramPacket(new byte[1024], 1024);
            socket.receive(packet);

            // Extract the request message from the packet
            String requestMessage = new String(packet.getData(), 0, packet.getLength());
            System.out.println("Received: " + requestMessage);

            // Send the audio file contents back to the client
            DatagramPacket responsePacket = new DatagramPacket(audioData, bytesRead, packet.getAddress(),
                    packet.getPort());
            socket.send(responsePacket);
        }
    }
}
