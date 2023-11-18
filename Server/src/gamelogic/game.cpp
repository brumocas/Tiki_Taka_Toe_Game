//
// Created by bruco on 11/10/2023.
//

#include "game.h"
#include "iostream"

namespace gamelogic {

    game::game() {
        // Initiate game and load DB
        db.load("../src/database/files/light_database.txt");
        // TODO: randomize teams and cups

    }

    bool game::checkAnswer(gamelogic::Player player) {
        // Check if cell is free first
        if (board.isUsed(player.getPlayerGuessX(), player.getPlayerGuessY()))
            return false;
        else {
            // Check footballer guess
            if (checkFootballerGuess(player)){
                board.setPlay(player);
                return true;
            }
        }
        return false;
    }

    void game::setWinner(gamelogic::Player player) {
        winner = player;
    }

    Player game::getWinner() {
        return winner;
    }

    bool game::isGameWonByPlayer(gamelogic::Player player) {
        if (winningCombinations(player.getSymbol()))
            return true;
        else
            return false;
    }

    bool game::isGameTied(gamelogic::Player player1, gamelogic::Player player2) {
        if (board.isFull() && !winningCombinations(player1.getSymbol()) &&
            !winningCombinations(player2.getSymbol()))
            return true;
        else
            return false;
    }

    bool game::winningCombinations(char symbol) {
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

    bool game::checkFootballerGuess(gamelogic::Player player) {
        // Check if Footballer exists
        if (db.searchFootballer(player.getFootballerGuessName(), player.getFootballerGuessSurname())) {
            // Check adjacent params
            if (checkParamsGuess(player))
                return true;
        }
        return false;
    }

    bool game::checkParamsGuess(gamelogic::Player player) {
        footballer f = db.getFootballer(player.getFootballerGuessName(), player.getFootballerGuessSurname());

        std::string paramUp = board.getUpParams(player.getPlayerGuessY());
        if (paramUp == "WC") {
            // Check if player won the WORLD CUP
            if (!f.isWorldCupWinner())
                return false;
        } else if (paramUp == "CL") {
            // Check if player won the WORLD CUP
            if (!f.isChampionsLeagueWinner())
                return false;
        } else if (paramUp == "CL") {
            // Check if player won the BALLON DOR
            if (!f.isBallonDorWinner())
                return false;
        } else if (paramUp == "E") {
            // Check if player won the EURO CUP
            if (!f.isEuropeanWinner())
                return false;
        } else {
            // Check if player played in the corresponding team
            if (!checkTeamGuess(paramUp, f.getCareerTeams()))
                return false;
        }

        std::string paramLeft = board.getLeftParams((player.getPlayerGuessX()));
        if (paramUp == "WC") {
            // Check if player won the WORLD CUP
            if (!f.isWorldCupWinner())
                return false;
        } else if (paramUp == "CL") {
            // Check if player won the WORLD CUP
            if (!f.isChampionsLeagueWinner())
                return false;
        } else if (paramUp == "CL") {
            // Check if player won the BALLON DOR
            if (!f.isBallonDorWinner())
                return false;
        } else if (paramUp == "E") {
            // Check if player won the EURO CUP
            if (!f.isEuropeanWinner())
                return false;
        } else {
            // Check if player played in the corresponding team
            if (!checkTeamGuess(paramUp, f.getCareerTeams()))
                return false;
        }

        return true;
    }

    bool game::checkTeamGuess(std::string team, std::vector<std::string> career_teams) {
        for (auto &t: career_teams) {
            if (t == team)
                return true;
        }
        return false;
    }

}