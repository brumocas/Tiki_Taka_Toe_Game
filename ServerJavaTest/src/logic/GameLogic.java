package logic;

import Communication.Communication;
import database.Footballer;
import database.Database;
import player.Player;
import java.util.Date;
import java.util.Scanner;
import java.util.Vector;

public class GameLogic {
    public Player p1 = new Player();
    public Player p2 = new Player();
    public Player winner = new Player();
    public Board board = new Board();
    Database db = new Database();


    public boolean run() {

        Vector<String> teams = new Vector<>(3);
        teams.add("Porto");
        teams.add("Chelsea");
        teams.add("Inter");
        Footballer f1 = new Footballer("Cris", "Ronaldo", new Date(85, 6, 15),
                "Portugal", teams, false, true, true, true);

        db.addFootballer(f1);
        db.print();

        p1.setSymbol('o');
        p2.setSymbol('x');

        board.setUpparams(teams);
        board.setLeftparams(teams);

        board.print();
        System.out.println();
        board.print_char();

        while (true) {

            Scanner scanner = new Scanner(System.in);
            System.out.println("Player 1 guess");
            String guess = scanner.next();
            System.out.println(guess);
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            System.out.print(guess);
            System.out.print(x);
            System.out.println(y);
            p1.setGuess(guess);
            p1.setPosition(x, y);
            checkAnswer(p1);
            board.print();
            System.out.println();
            board.print_char();
            if (checkWinner(p1)) {
                System.out.println("Player 1 wins");
                return true;
            }

            System.out.println("Player 2 guess");
            guess = scanner.next();
            x = scanner.nextInt();
            y = scanner.nextInt();
            p2.setGuess(guess);
            p2.setPosition(x, y);
            checkAnswer(p2);
            board.print();
            System.out.println();
            board.print_char();
            if (checkWinner(p2)) {
                System.out.println("Player 2 wins");
                return true;
            }
        }
    }

    public boolean checkAnswer(Player p) {
        // Check if the player is in the database
        if (db.searchFootballer(p.getGuess()) != null) {
            Footballer footballer = db.searchFootballer(p.getGuess());
            String paramUp = board.getUpparams(p.getX());
            String paramLeft = board.getLeftparams(p.getY());
            //Check if the team is the same as the params teams
            for (String t1 : footballer.getCareerTeams())
                if (t1 == paramUp) {
                    for (String t2 : footballer.getCareerTeams()) {
                        if (t2 == paramLeft) {
                            board.setPlay(p.getX(), p.getY(), footballer.getName(), p.getSymbol());
                            System.out.println("Hello");
                            return true;
                        }
                    }
                }
        }
        return false;
    }

    public boolean checkWinner(Player p) {
        char symbol = p.getSymbol();
        return checkRows(symbol) || checkColumns(symbol) || checkDiagonals(symbol);

    }

    private boolean checkRows(char symbol) {
        for (int row = 0; row < 3; row++) {
            if (board.getSymbol(row, 0) == symbol && board.getSymbol(row, 1) == symbol && board.getSymbol(row, 2) == symbol) {
                return true;
            }
        }
        return false;
    }

    private boolean checkColumns(char symbol) {
        for (int col = 0; col < 3; col++) {
            if (board.getSymbol(0, col) == symbol && board.getSymbol(1, col) == symbol && board.getSymbol(2, col) == symbol) {
                return true;
            }
        }
        return false;
    }

    private boolean checkDiagonals(char symbol) {
        if ((board.getSymbol(0, 0) == symbol && board.getSymbol(1, 1) == symbol && board.getSymbol(2, 2) == symbol) ||
                (board.getSymbol(0, 2) == symbol && board.getSymbol(1, 1) == symbol && board.getSymbol(2, 0) == symbol)) {
            return true;
        }
        return false;
    }


}
