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
        // Default Constructor uses default db
        game();
        // Constructor uses given database
        game(std::string db_path);
        // Setter for board parameters
        void setParams(std::string param1, std::string param2, std::string param3,
                       std::string param4, std::string param5, std::string param6);
        // Getter for board parameters
        std::vector<std::string> getParams();
        // Check current player answer
        bool checkAnswer(gamelogic::Player player);
        // Check Footballer guess
        bool checkFootballerGuess(gamelogic::Player player);
        // Check parameters guess
        bool checkParamsGuess(gamelogic::Player player);
        // Check teams guess
        bool checkTeamGuess(std::string team, std::vector<std::string> career_teams);
        // Getter for current game winner
        gamelogic::Player getWinner();
        // Setter for current game winner
        void setWinner(gamelogic::Player player);
        // Check if given player won the game
        bool isGameWonByPlayer(gamelogic::Player player);
        // Check if the game is tied
        bool isGameTied(gamelogic::Player player1, gamelogic::Player player2);
        // Check if the given symbol corresponds to a win in the board
        bool winningCombinations(char symbol);
        // Print game
        void print();
        // Erase board for new game
        void erasePreviousGame(){
            board.eraseBoard();
        }

    };
}

#endif //SERVER_GAME_H
