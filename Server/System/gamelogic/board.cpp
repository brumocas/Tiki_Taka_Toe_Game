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
                footballerEntry[i][j] = '-';
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
        leftParameters[0] = param1;
        leftParameters[1] = param2;
        leftParameters[2] = param3;
    }

    std::string Board::getUpParams(int x) {
        return upParameters[x];
    }

    std::string Board::getLeftParams(int y) {
        return upParameters[y];
    }

    void Board::setPlay(Player player) {
        if (isUsed(player.getPlayerGuessX(), player.getPlayerGuessY())){
            symbolArray[player.getPlayerGuessX()][player.getPlayerGuessY()] = player.getSymbol();
            footballerEntry[player.getPlayerGuessX()][player.getPlayerGuessY()] = player.getPlayerGuessFootballer();
        } else {
            std::cerr << "Invalid behaviour" << std::endl;
        }
    }

    char Board::getSymbol(int x, int y) {
        return symbolArray[x][y];
    }

    bool Board::isUsed(int x, int y) {
        return footballerEntry[x][y] != "Unknown";
    }

}
