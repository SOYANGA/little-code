package client;


import java.io.PrintStream;
import java.net.Socket;

class SendMsgToServer implements  Runnable{
    private Socket client;

    public SendMsgToServer(Socket client) {
        this.client = client;
    }

    @Override
    public void run() {
        PrintStream
    }
}
class ReadFromServer implements  Runnable{
    private Socket client;

    public ReadFromServer(Socket client) {
        this.client = client;
    }

    @Override
    public void run() {

    }
}



public class ClientThread {
    public static void main(String[] args) {

    }
}
