import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;


class UDPServer {
    private DatagramSocket serverSocket;

    public UDPServer(int port) throws Exception {
        serverSocket = new DatagramSocket(port);
    }

    public void start() throws Exception {
        byte[] receiveData = new byte[1024];
        byte[] sendData;

        while(true) {
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            serverSocket.receive(receivePacket);
            String sentence = new String(receivePacket.getData(), 0, receivePacket.getLength());
            System.out.println("RECEIVED: " + sentence);

            sendData = ("Received " + sentence).getBytes();
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, receivePacket.getAddress(), receivePacket.getPort());
            serverSocket.send(sendPacket);
        }
    }
}

class UDPClient {
    private DatagramSocket clientSocket;
    private InetAddress IPAddress;

    public UDPClient(String host) throws Exception {
        clientSocket = new DatagramSocket();
        IPAddress = InetAddress.getByName(host);
    }

    public void sendAndReceive(String sentence) throws Exception {
        byte[] sendData;
        byte[] receiveData = new byte[1024];

        sendData = sentence.getBytes();

        DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 9876);
        clientSocket.send(sendPacket);

        DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
        clientSocket.receive(receivePacket);

        String modifiedSentence = new String(receivePacket.getData(), 0, receivePacket.getLength());
        System.out.println("FROM SERVER: " + modifiedSentence);

        clientSocket.close();
    }
}

public class Prac11_2 {
    public static void main(String[] args) throws Exception {
        // Start the server in a new thread
        new Thread(() -> {
            try {
                UDPServer server = new UDPServer(9876);
                server.start();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }).start();

        // Give the server a second to start
        Thread.sleep(1000);

        // Start the client
        UDPClient client = new UDPClient("localhost");
        client.sendAndReceive("Hello from client");
    }
}
