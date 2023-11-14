//
// Created by bruco on 11/10/2023.
//

#include "game.h"

namespace gamelogic{

    void game::startGame(){
        appRunning = true;
    }

    bool game::isGameInProgress(){
        return appRunning;
    }

    bool game::checkAnswer(gamelogic::Player player) {
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
        if(player.playerName == winner.playerName)
            return true;
        else
            return false;
    }

    bool game::isGameTied() {
        if(player1.playerName != winner.playerName && player2.playerName != winner.playerName) 
            return true;
        else  
            return false;
    }

    bool game::winningCombinations(char symbol, Board board) {
        for(int i = 0; i < 3; i++) {
            if(board.getSymbol(i, 0) == symbol && board.getSymbol(i, 1) == symbol && board.getSymbol(i, 2) == symbol) {
                return true;
            }
        }

        for(int j = 0; j < 3; j++) {
            if(board.getSymbol(0, j) == symbol && board.getSymbol(1, j) == symbol && board.getSymbol(2, j) == symbol) {
                return true;
            }
        }

        if(board.getSymbol(0, 0) == symbol && board.getSymbol(1, 1) == symbol && board.getSymbol(2, 2) == symbol) {
            return true;
        }

        if(board.getSymbol(0, 2) == symbol && board.getSymbol(1, 1) == symbol && board.getSymbol(2, 0) == symbol) {
            return true;
        }

        return false;
    }

}