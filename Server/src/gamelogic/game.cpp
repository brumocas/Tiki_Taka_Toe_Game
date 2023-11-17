//
// Created by bruco on 11/10/2023.
//

#include "game.h"

namespace gamelogic {

    game::game() {
        // Initiate game
        player1.setSymbol('x');
        player2.setSymbol('o');
    }

    bool game::checkAnswer(gamelogic::Player player) {
        // TODO : To be Completed
        std::string correctAnswer = "Footballer name";
        return player.getPlayerGuessFootballer() == correctAnswer;
    }

    void game::setWinner(gamelogic::Player player) {
        winner = player;
    }

    Player game::getWinner() {
        return winner;
    }

    bool game::isGameWonByPlayer(gamelogic::Player player) {
        if (player.playerName == winner.playerName)
            return true;
        else
            return false;
    }

    bool game::isGameTied() {
        if (player1.playerName != winner.playerName && player2.playerName != winner.playerName)
            return true;
        else
            return false;
    }

    bool game::winningCombinations(char symbol, Board board) {
        for (int i = 0; i < 3; i++) {
            if (board.getSymbol(i, 0) == symbol && board.getSymbol(i, 1) == symbol && board.getSymbol(i, 2) == symbol) {
                return true;
            }
        }

        for (int j = 0; j < 3; j++) {
            if (board.getSymbol(0, j) == symbol && board.getSymbol(1, j) == symbol && board.getSymbol(2, j) == symbol) {
                return true;
            }
        }

        if (board.getSymbol(0, 0) == symbol && board.getSymbol(1, 1) == symbol && board.getSymbol(2, 2) == symbol) {
            return true;
        }

        if (board.getSymbol(0, 2) == symbol && board.getSymbol(1, 1) == symbol && board.getSymbol(2, 0) == symbol) {
            return true;
        }

        return false;
    }

    void game::setParams(std::string param1, std::string param2, std::string param3,
                         std::string param4, std::string param5, std::string param6) {

        board.setUpParams(param1, param2, param3);
        board.setLeftParams(param4, param5, param6);
    }

    void game::print() {
        board.printFootballers();
        board.printSymbols();
    }

}