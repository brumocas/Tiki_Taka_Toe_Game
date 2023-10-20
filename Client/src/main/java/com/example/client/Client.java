package com.example.client;
import com.example.client.logic.game;

public class Client {

    public static void main(String[] args) {
        Gui.main(args);


        game game1 = new game();
        if(game1.run())
            return;


    }
}
