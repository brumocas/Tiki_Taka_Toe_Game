package com.example.client.player;

public class player {
     private String name;
     private String guess;
     private char symbol;
     private int x;
     private int y;

     public player(){

     }

     // Constructor
    public player(String name, char symbol) {
        this.name = name;
    }

    //Set player name
    public void setName(String name){
        this.name = name;
    }
    //Get player name
    public String getName(){
        return this.name;
    }

    //Set player symbol
    public void setSymbol(char symbol){
        this.symbol = symbol;
    }
    //Get player symbol
    public char getSymbol(){
        return this.symbol;
    }

    //set player guess
    public void setGuess(String guess){
        this.guess = guess;
    }
    //get player guess
    public String getGuess(){
        return this.guess;
    }

    //set player guess position
    public void setPosition(int x, int y){
        this.x = x;
        this.y = y;
    }
    //get player guess x position
    public int getX(){
        return this.x;
    }
    //get player guess y position
    public int getY(){
        return this.y;
    }

}
