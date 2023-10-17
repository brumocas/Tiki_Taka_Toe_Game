package gui;

import java.sql.SQLOutput;
import java.util.Objects;
import java.util.Vector;

public class board {
    private final int rows = 3;
    private final int columns = 3;
    private Vector<String> upparams = new Vector<>(rows);
    private Vector<String> leftparams = new Vector<>(columns);
    private String[][] board = new String[rows][columns];

    //Constructor
    public board(){

    }

    //set Up parameters
    public void setUpparams(Vector<String> upparams){
        this.upparams.add(0, upparams.get(0));
        this.upparams.add(1, upparams.get(1));
        this.upparams.add(2, upparams.get(2));
    }
    //get Up parameters
    public String getUpparams(int pos){
        return this.upparams.get(pos);
    }

    //set Left parameters
    public void setLeftparams(Vector<String> leftparams){
        this.leftparams.add(0, leftparams.get(0));
        this.leftparams.add(1, leftparams.get(1));
        this.leftparams.add(2, leftparams.get(2));
    }
    //get Left parameters
    public String getLeftparams(int pos){
        return this.leftparams.get(pos);
    }

    //get board string element
    public String getPlayer(int x, int y){
        return this.board[x][y];
    }

    //set player in the board
    public void setPlayer(int x, int y, String name){
        if (board[x][y] == null){
            board[x][y] = name;
        }else {
            System.err.println("Invalid board access");
        }
    }

    //print board in cmd
    public void print(){
        System.out.println("Tiki Taka Board game (cmd)");
        System.out.print("\t");
        for (int i = 0; i < rows; i++) {
            System.out.print('\t' + upparams.get(i));
            System.out.print(' ');
        }
        System.out.println();
        for (int i = 0; i < rows; i++) {
            System.out.print(leftparams.get(i) + '\t');
            System.out.print(' ');
            for (int k = 0; k < columns; k++) {
                System.out.print(board[i][k] + '\t');
                System.out.print(' ');
            }
            System.out.println();
        }
    }
}
