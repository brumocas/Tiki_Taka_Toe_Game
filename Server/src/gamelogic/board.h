//
// Created by bruco on 11/10/2023.
//

#ifndef SERVER_BOARD_H
#define SERVER_BOARD_H

#include <iostream>
#include "../player/player.h"

namespace gamelogic {

    class Board {
    private:
        std::string upParameters[3];
        std::string leftParameters[3];
        char symbolArray[3][3];
        std::string footballerEntry[3][3];

    public:
        // Constructor
        Board();
        // Setter for Up parameters
        void setUpParams(std::string param1, std::string param2, std::string param3);
        // Setter for Left parameters
        void setLeftParams(std::string param1, std::string param2, std::string param3);
        // Getter for Up parameters
        std::string getUpParams(int x);
        // Getter for Left parameters
        std::string getLeftParams(int y);
        // Setter for current Player move
        void setPlay(Player player);
        // Check if board position is already used
        bool isUsed(int x, int y);
        // Check if all board positions are used
        bool isFull();
        // Getter for Symbol in the given board position
        char getSymbol(int x, int y);
        // Print Footballers board for debug
        void printFootballers();
        // Print Footballers board for debug
        void printSymbols();
        // Erase board for new game
        void eraseBoard();
    };

}
#endif //SERVER_BOARD_H
