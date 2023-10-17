import communication.communication;
import gui.board;
import player.player;

import java.util.Vector;

public class client {

    public static void main(String[] args) {
        //System.out.println("Hello Tiki Taka Toe");
        //communication.run();
        //player p1 = new player("Bruno", 'X');

        board b = new board();
        Vector<String> teams = new Vector<>(3);
        teams.add("Porto");
        teams.add("Chelsea");
        teams.add("Inter");

        b.setUpparams(teams);
        b.setLeftparams(teams);
        b.setPlayer(0,0,"Abou");

        b.print();


    }
}
