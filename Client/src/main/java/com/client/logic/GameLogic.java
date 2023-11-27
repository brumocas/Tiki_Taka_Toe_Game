package com.client.logic;


import com.client.player.Player;

import java.util.Vector;

public class GameLogic {
    public Player p1 = new Player();
    public Player p2 = new Player();
    public Board board = new Board();


    public void run() {
        Vector<String> teams = new Vector<>(3);
        teams.add("PSG");
        teams.add("Barcelona");
        teams.add("Brazil");

        Vector<String> teams2 = new Vector<>(3);
        teams2.add("Arsenal");
        teams2.add("Bayern");
        teams2.add("Chile");

        p1.setSymbol('o');
        p2.setSymbol('x');

        board.setUpparams(teams);
        board.setLeftparams(teams2);

        //board.print();
        //System.out.println();
        //board.print_char();

    }


}
