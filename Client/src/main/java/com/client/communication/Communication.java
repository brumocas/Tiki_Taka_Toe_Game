package com.client.communication;

import java.io.*;
import java.net.Socket;

public class Communication {
    private Socket socket = null;
    private PrintWriter writer = null;
    private BufferedReader reader = null;

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
