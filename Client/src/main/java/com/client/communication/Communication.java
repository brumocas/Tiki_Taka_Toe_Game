package com.client.communication;

import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

public class Communication {

    public static void startClient() throws IOException {
        var socket = new Socket(InetAddress.getLocalHost(), 8080);
        var in = new Scanner(socket.getInputStream());
        System.out.println("Server response: " + in.nextLine());

    }

}
