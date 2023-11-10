//
// Created by fmesquita on 11/10/23.
//

#ifndef SERVER_PLAYER_H
#define SERVER_PLAYER_H

#include <iostream>

namespace gamelogic {

    class Player {

    private:
        char symbol;
        std::string playerGuessFootballer;
        int x;
        int y;


    public:
        std::string playerName;

        Player();
        Player(std::string playerName, char symbol);
        std::string getPlayerName();
        void setPlayerName(std:: string playerName);
        int getPlayerGuessX(int x);
        int getPlayerGuessY(int y);
        void setPlayerGuessCords(int x, int y);
        std::string getPlayerGuessFootballer(std::string playerGuessFootballer);
        void setPlayerGuessFootballer(std::string playerGuessFootballer);
        char getSymbol();
        void setSymbol(char symbol);

    };

}
#endif //SERVER_PLAYER_H
