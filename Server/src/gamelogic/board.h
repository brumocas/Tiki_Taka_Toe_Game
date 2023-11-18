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
        Board();
        void setUpParams(std::string param1, std::string param2, std::string param3);
        void setLeftParams(std::string param1, std::string param2, std::string param3);
        std::string getUpParams(int x);
        std::string getLeftParams(int y);
        void setPlay(Player player);
        bool isUsed(int x, int y);
        bool isFull();
        char getSymbol(int x, int y);
        void printFootballers();
        void printSymbols();
    };

}
#endif //SERVER_BOARD_H
