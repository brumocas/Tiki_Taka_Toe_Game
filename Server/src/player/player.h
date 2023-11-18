//
// Created by fmesquita on 11/10/23.
//

#ifndef SERVER_PLAYER_H
#define SERVER_PLAYER_H

#include <iostream>

namespace gamelogic {

    class Player {

    private:
        char symbol{};
        std::string playerName;
        std::string FootballerGuessName;
        std::string FootballerGuessSurname;
        int x;
        int y;


    public:

        Player();
        Player(std::string playerName, char symbol);
        std::string getPlayerName();
        void setPlayerName(std:: string playerName);
        int getPlayerGuessX();
        int getPlayerGuessY();
        void setPlayerGuessCords(int x, int y);
        std::string getFootballerGuessName();
        void setFootballerGuessName(std::string name);
        std::string getFootballerGuessSurname();
        void setFootballerGuessSurname(std::string surname);
        char getSymbol();
        void setSymbol(char symbol);

    };

}
#endif //SERVER_PLAYER_H
