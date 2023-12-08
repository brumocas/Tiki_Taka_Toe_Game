//
// Created by bruco on 11/10/2023.
//

#include "game.h"
#include "iostream"

namespace gamelogic {

    game::game() {
        // Initiate game and load DB
        db.load("../src/database/files/default_database.txt");
    }

    game::game(std::string db_path) {
        // Initiate game and load DB
        db.load(db_path);
    }



    bool game::checkAnswer(gamelogic::Player player) {
        // Check if cell is free first
        if (board.isUsed(player.getPlayerGuessX(), player.getPlayerGuessY()))
            return false;
        else {
            // Check footballer guess
            if (checkFootballerGuess(player)) {
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

        // TODO: Randomize params available in the DB


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
        } else if (paramUp == "BD") {
            // Check if player won the BALLON DOR
            if (!f.isBallonDorWinner())
                return false;
        } else if (paramUp == "EC") {
            // Check if player won the EURO CUP
            if (!f.isEuropeanWinner())
                return false;
        } else {

            if (db.isNation(paramUp)) {
                // Check if the Nation is the same as the footballer guessed
                if (paramUp != f.getNationality())
                    return false;
            } else if (db.isTeam(paramUp)) {
                // Check if footballer played in the corresponding team
                if (!checkTeamGuess(paramUp, f.getCareerTeams()))
                    return false;
            } else {
                // Never enters here
                std::cerr << "Error1\n";
            }

        }

        std::string paramLeft = board.getLeftParams((player.getPlayerGuessX()));
        if (paramLeft == "WC") {
            // Check if player won the WORLD CUP
            if (!f.isWorldCupWinner())
                return false;
        } else if (paramLeft == "CL") {
            // Check if player won the WORLD CUP
            if (!f.isChampionsLeagueWinner())
                return false;
        } else if (paramLeft == "BD") {
            // Check if player won the BALLON DOR
            if (!f.isBallonDorWinner())
                return false;
        } else if (paramLeft == "EC") {
            // Check if player won the EURO CUP
            if (!f.isEuropeanWinner())
                return false;
        } else {

            if (db.isNation(paramLeft)) {
                // Check if the Nation is the same as the footballer guessed
                if (paramLeft != f.getNationality())
                    return false;
            } else if (db.isTeam(paramLeft)) {
                // Check if footballer played in the corresponding team
                if (!checkTeamGuess(paramLeft, f.getCareerTeams()))
                    return false;
            } else {
                // Never enters here
                std::cerr << "Error2\n";
            }
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

    std::vector<std::string> game::getParams() {
        std::vector<std::string> params;

        for (int i = 0; i < 3; ++i) {
            params.push_back(board.getUpParams(i));
        }

        for (int i = 0; i < 3; ++i) {
            params.push_back(board.getLeftParams(i));
        }

        return params;
    }

}