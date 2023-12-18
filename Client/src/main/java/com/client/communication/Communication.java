package com.client.communication;

import java.io.*;
import java.net.Socket;
import java.util.Objects;
import java.util.Scanner;

public class Communication {
    private Socket socket = null;
    private PrintWriter writer = null;
    private BufferedReader reader = null;
    private boolean host = false;

    public void connectToServer(String address, int port) throws IOException {
        try {
            socket = new Socket(address, port);
            System.out.println("Connected to the Server " + address + ":" + port);
            writer = new PrintWriter(socket.getOutputStream(), true);
            reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        } catch (IOException e) {
            throw new IOException("Error connecting to server", e);
        }
    }

    public boolean connectRemote(int pin) throws IOException {

        // Receive information to know if you are host or hosted
        String message = receiveMessage();
        String input;
        Scanner scanner = new Scanner(System.in);

        if (Objects.equals(message, "Host")) {
            host = true;
            // You are host receive pin
            message = receiveMessage();
            System.out.println("You entered the game as host and the pin is: " + message);
        } else if (Objects.equals(message, "Hosted")) {
            host = false;
            System.out.print("Write the Pin to connect to remote game: ");
            // You are hosted send pin
            input = scanner.nextLine();
            sendMessage(input);

            // Receive Response
            message = receiveMessage();
            while (!Objects.equals(message, "Correct")) {
                System.out.print("Invalid Pin try again: ");
                // You are hosted send pin
                input = scanner.nextLine();
                sendMessage(input);
                // Receive Response
                message = receiveMessage();
            }

            System.out.println("You entered the game as hosted ");
        }
        return host;
    }

    public String exchangeNames(String Name) throws IOException {
        String opponentName;

        // Wait for name request
        String message = receiveMessage();
        while (!Objects.equals(message, "Name"))
            message = receiveMessage();

        System.out.print("Insert you Name: ");
        //name = scanner.nextLine();
        sendMessage(Name);

        // Receive Opponent Name
        opponentName = receiveMessage();
        System.out.println("Opponent Name is: " + opponentName);

        return opponentName;
    }

    public String[] getParams() throws IOException {
        // Receive board params
        String paramsPacket = receiveMessage();
        // Get String vector with params
        return paramsPacket.split("-");
    }

    public void sendMessage(String message) throws IOException {
        if (socket == null || socket.isClosed()) {
            throw new IllegalStateException("Socket is not connected. Call connectToServer first.");
        }

        try {
            writer.println(message);
        } catch (UncheckedIOException e) {
            throw new IOException("Error sending message to server", e);
        }
    }

    public String receiveMessage() throws IOException {
        if (socket == null || socket.isClosed()) {
            throw new IllegalStateException("Socket is not connected. Call connectToServer first.");
        }

        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new IOException("Error receiving message from server", e);
        }
    }

    public void closeConnection() {
        try {
            if (socket != null && !socket.isClosed()) {
                socket.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
