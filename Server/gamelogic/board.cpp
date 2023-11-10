//
// Created by bruco on 11/10/2023.
//

#include "board.h"
#include <iostream>

namespace gamelogic{

    Board::Board() {
        //Initialize all the board parameters
        for(int i=0; i <3 ; i++){
            upParameters[i] = "Unknown";
            leftParameters[i] = "Unknown";
        }
        //Initialize the symbol array
        for(int i=0; i < 3; i++){
            for(int j=0; j < 3; j++) {
                symbolArray[i][j] = '-';
            }
        }

        rows = 3;
        columns = 3;
    }

    void Board::setUpParams(std::string param1, std::string param2, std::string param3) {
        upParameters[0] = param1;
        upParameters[1] = param2;
        upParameters[2] = param3;
    }

    void Board::setLeftParams(std::string param1, std::string param2, std::string param3) {
        upParameters[0] = param1;
        upParameters[1] = param2;
        upParameters[2] = param3;
    }

    std::string Board::getUpParams(int x) {
        return upParameters[x];
    }

    std::string Board::getLeftParams(int y) {
        return upParameters[y];
    }

    void Board::setPlay(int x, int y, char symbol) {
        symbolArray[x][y]=symbol;
    }

    char Board::getPlay(int x, int y, char symbol) { // TODO: getPlay implementation

    }


}
