package com.client.logic;


import com.client.player.Player;

import java.util.Vector;

public class GameLogic {
    public Player p1 = new Player();
    public Player p2 = new Player();
    public Board board = new Board();
    public boolean host = false;


    public void run() {
        Vector<String> teams = new Vector<>(3);
        teams.add("PSG");
        teams.add("Barcelona");
        teams.add("Brazil");

        Vector<String> teams2 = new Vector<>(3);
        teams2.add("Juventus");
        teams2.add("Manchester_United");
        teams2.add("Chile");

        p1.setSymbol('O');
        p2.setSymbol('X');

        board.setUpparams(teams);
        board.setLeftparams(teams2);


    }


}
