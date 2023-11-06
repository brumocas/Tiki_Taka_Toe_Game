package Communication;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.util.Date;

public class Communication {

    public static void startServer(){
        try (var listener = new ServerSocket(8080)) {
            System.out.println("The date server is running...");
            while (true) {
                try (var socket = listener.accept()) {
                    var out = new PrintWriter(socket.getOutputStream(), true);
                    out.println(new Date().toString());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
