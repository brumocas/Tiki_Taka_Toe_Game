package com.client.main;


import com.client.communication.Communication;

import java.io.IOException;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws IOException {

        // GUI remote Game
        //Gui.main(args);


        // CMD remote game
        remoteCMD();

    }

    static void remoteCMD() throws IOException {
        try {
            Communication client = new Communication();
            client.connectToServer("localhost", 8081);

            Scanner scanner = new Scanner(System.in);
            while (true) {
                System.out.print("C: ");
                String message = scanner.nextLine();
                client.sendMessage(message);
                System.out.println("S: " + client.receiveMessage());
            }

            //client.closeConnection();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
