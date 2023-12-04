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
        int numberWins = 0;
        int x;
        int y;


    public:
        // Constructor
        Player();
        // Constructor
        Player(std::string playerName, char symbol);
        // Getter for player name
        std::string getPlayerName();
        // Setter for player
        void setPlayerName(std:: string playerName);
        // Getter for player x coordinate guess
        int getPlayerGuessX();
        // Getter for player y coordinate guess
        int getPlayerGuessY();
        // Setter for player x and y coordinates
        void setPlayerGuessCords(int x, int y);
        // Getter for footballer guess Name
        std::string getFootballerGuessName();
        // Setter for footballer guess Name
        void setFootballerGuessName(std::string name);
        // Getter for footballer guess Surname
        std::string getFootballerGuessSurname();
        // Setter for footballer guess Surname
        void setFootballerGuessSurname(std::string surname);

        char getSymbol();

        void setSymbol(char symbol);
        // Increase Player number of Wins
        void increaseScore();
        // Get player number of wins
        int getScore();

        // Equality operator
        bool operator==(const Player& other) const {
            return  x == other.x &&
                    y == other.y &&
                    symbol == other.symbol &&
                    playerName == other.playerName &&
                    FootballerGuessName == other.FootballerGuessName &&
                    FootballerGuessSurname == other.FootballerGuessSurname;
        }

    };

}
#endif //SERVER_PLAYER_H
