package Single;

import java.io.PrintStream;
import java.net.Socket;
import java.sql.SQLOutput;
import java.util.Scanner;

public class SingleThreadClient {
    public static void main(String[] args) throws Exception {
        //1.建立连接
        String serverName = "127.0.0.1";
        Integer port = 6666;
        Socket client = new Socket(serverName, port);
        System.out.println("连接上服务器，服务器地址为：" + client.getInetAddress());
        //2.进行数据的输入输出
        //获取输入输出流
        PrintStream out = new PrintStream(client.getOutputStream(),
                true, "UTF-8");
        Scanner in = new Scanner(client.getInputStream());
        in.useDelimiter("\n");
        //向服务器输出内容
        out.println("Hi I am Client!!");

        Scanner in2 = new Scanner(System.in );
        String str= " ";
        if(in2.hasNext()){
            str = in2.nextLine();
        }
        //读取服务器输入
        if (in.hasNext()) {
            System.out.println("服务发送消息为：" + in.next());
        }
        //3.关闭流3关
        in.close();
        out.close();
        client.close();
        //"127.0.0.1"
    }
}
