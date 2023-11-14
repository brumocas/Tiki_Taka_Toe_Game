//
// Created by bruco on 11/10/2023.
//

#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#include "../player/player.h"
#include "board.h"
#include <array>
#include <iostream>

namespace gamelogic {

    class game {
    private:
        Player player1, player2, winner;
        Board board;
        bool appRunning;

    public:

        void startGame();
        bool isGameInProgress();
        bool checkAnswer(Player player);
        Player getWinner();
        void setWinner(Player player);
        bool isGameWonByPlayer(Player player);
        bool isGameTied();
        bool winningCombinations(char symbol, Board board);

    };
}

#endif //SERVER_GAME_H
