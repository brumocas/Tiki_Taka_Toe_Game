package com.client.main;


import com.client.Gui;
import com.client.communication.Communication;
import com.client.logic.Board;
import com.client.player.Player;

import java.io.IOException;
import java.util.Objects;
import java.util.Scanner;
import java.util.Vector;


public class Client {

    public static void main(String[] args) throws IOException {

        // GUI remote Game
        Gui.main(args);


        // CMD remote game
        //remoteCMD();

    }

    static void remoteCMD() throws IOException {
        Board board = new Board();
        Player p = new Player();
        Scanner scanner = new Scanner(System.in);
        try {
            Communication client = new Communication();
            client.connectToServer("localhost", 8081);

            // Establish pins connection and receive bool for host or hosted
            if (client.connectRemote())
                p.setSymbol('X');
            else
                p.setSymbol('O');

            String opponentName = client.exchangeNames();
            p.setName(opponentName);

            String[] params = client.getParams();
            setParams(board, params);

            System.out.println("Remote CMD game started");

            outerLoop:
            while (true){
                board.print();
                board.print_char();
                // Busy waiting for you time to play
                String message = client.receiveMessage();

                switch (message) {
                    case "YourTurn":
                        // Make your play
                        System.out.println("Your turn :");
                        System.out.print("x: ");
                        int x = scanner.nextInt();
                        System.out.print("y: ");
                        int y = scanner.nextInt();
                        p.setPosition(x, y);

                        // Consume the newline character
                        scanner.nextLine();

                        System.out.print("Name: ");
                        String name = scanner.nextLine();
                        System.out.print("Surname: ");
                        String surname = scanner.nextLine();

                        String packet = String.valueOf(x) + "-" + String.valueOf(y) + "-" +
                                name + "-" + surname;

                        p.setGuess(name + " " + surname);

                        client.sendMessage(packet);

                        // Receive Response
                        String response = client.receiveMessage();
                        if (Objects.equals(response, "Correct")){
                            board.setPlay(p.getX(), p.getY(), p.getGuess(), p.getSymbol());
                        } else if (Objects.equals(response, "Incorrect")){
                            System.err.println("Incorrect guess");
                        } else {
                            System.err.println("Error receiving type of packet");
                        }

                        break;
                    case "OpponentPlay":
                        // Receive Opponent play and place it in the board
                        String opponentPacket = client.receiveMessage();
                        String[] play = parseOpponentPacket(opponentPacket);
                        board.setPlay(Integer.parseInt(play[0]), Integer.parseInt(play[1]),
                                play[2] + ' ' +play[3], (p.getSymbol() == 'X') ? 'O' : 'X' );
                        break ;
                    case "Winner":
                        // End game as a winner
                        System.out.println("Your Win");
                        break outerLoop;
                    case "Loser":
                        // End game as a loser
                        System.out.println("Your Lose");
                        break outerLoop;
                    case "Tie":
                        // End game as a tie
                        System.out.println("Tie");
                        break outerLoop;
                }
            }

            client.closeConnection();

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static String[] parseOpponentPacket(String opponentPacket) {
        return opponentPacket.split("-");
    }


    static void setParams(Board board, String[] params){
        Vector<String> upparams = new Vector<>(3);
        for (int i = 0; i < 3; i++){
            upparams.add(i, params[i]);
        }

        Vector<String> leftparams = new Vector<>(3);
        for (int i = 0; i < 3; i++){
            leftparams.add(i, params[i + 3]);
        }
        board.setUpparams(upparams);
        board.setLeftparams(leftparams);
    }
}



