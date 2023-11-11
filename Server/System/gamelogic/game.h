//
// Created by bruco on 11/10/2023.
//

#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#include "player.h"
#include <array>
#include <iostream>

using ThreeByThreeArray = std::array<std::array<int, 3>, 3>;

namespace gamelogic {

    class game {
    private:
        Player player1, player2, currentPlayer, winner;

    public:

        bool checkPosition(Player player);
        bool checkAnswer(Player player);
        Player getWinner();
        void setWinner(Player player);
        bool isGameWonByPlayer(Player player);
        bool isGameTied();
        std::array<ThreeByThreeArray, 8> winningCombination(char symbol);

    };
}

#endif //SERVER_GAME_H
