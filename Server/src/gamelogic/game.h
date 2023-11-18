//
// Created by bruco on 11/10/2023.
//

#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#include "../player/player.h"
#include "board.h"
#include "../database/database.h"
#include <array>
#include <iostream>


namespace gamelogic {

    class game {
    private:
        database db;
        Player winner;
        Board board;
    public:
        game();
        void setParams(std::string param1, std::string param2, std::string param3,
                       std::string param4, std::string param5, std::string param6);
        bool checkAnswer(gamelogic::Player player);
        bool checkFootballerGuess(gamelogic::Player player);
        bool checkParamsGuess(gamelogic::Player player);
        bool checkTeamGuess(std::string team, std::vector<std::string> career_teams);
        gamelogic::Player getWinner();
        void setWinner(gamelogic::Player player);
        bool isGameWonByPlayer(gamelogic::Player player);
        bool isGameTied(gamelogic::Player player1, gamelogic::Player player2);
        bool winningCombinations(char symbol);
        void print();

    };
}

#endif //SERVER_GAME_H
