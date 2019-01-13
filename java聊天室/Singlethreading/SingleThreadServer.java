package Single;

import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class SingleThreadServer {
    public static void main(String[] args) throws Exception {
        //1.建立基站
        ServerSocket serverSocket = new ServerSocket(6666);
        //2.等待客户端连接
        System.out.println("等待客户端连接ing...");
        // 等待客户端连接，有客户端连接后返回客户端的Socket对象，否则线程将一直阻塞于此处
        Socket client = serverSocket.accept();
        //3.建立连接后，进行数据传输入输出
        Scanner clientInput = new Scanner(client.getInputStream());
        clientInput.useDelimiter("\n");
        PrintStream clientOut = new PrintStream(client.getOutputStream(),
                true, "UTF-8");
        //读取客户端输入
        if (clientInput.hasNext()) {
            System.out.println(client.getInetAddress() + "说" + clientInput.next());
        }

        //向客户端输出
        clientOut.println("Hello I am Server,Welcome!");
        //4.关闭流3关
        clientInput.close();
        clientOut.close();
        serverSocket.close();
    }
}
