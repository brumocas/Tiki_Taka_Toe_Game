//
// Created by bruco on 11/10/2023.
//

#ifndef SERVER_BOARD_H
#define SERVER_BOARD_H

#include <iostream>

namespace gamelogic {

    class Board {
    private:
        int rows;
        int columns;
        std::string upParameters[3];
        std::string leftParameters[3];
        char symbolArray[3][3];
        std::string footballerEntry[3][3]; // TODO: footballerEntry implementation

    public:
        Board();
        void setUpParams(std::string param1, std::string param2, std::string param3);
        void setLeftParams(std::string param1, std::string param2, std::string param3);
        std::string getUpParams(int x);
        std::string getLeftParams(int y);
        void setPlay(int x, int y, char symbol);
        char getPlay(int x, int y, char symbol); // TODO: getPlay implementation

    };

}
#endif //SERVER_BOARD_H
