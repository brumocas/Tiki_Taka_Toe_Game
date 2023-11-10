//
// Created by fmesquita on 11/10/23.
//
#include "player.h"

#include <iostream>
#include <vector>
#include <string>

namespace gamelogic{

    Player::Player() {
        playerName = "Unknown";
        x = -1; // valid plays are 0, 1, 2, 10, 11, 12 , 20, 21, 22,
        y = -1; // when x or y = 3 it means the play is invalid or that the player didn't make a play yet
    }

    Player::Player(std::string playerName, char symbol){
        this->playerName = playerName;
        this->symbol = symbol;
    }

    std::string Player::getPlayerName() {
        return playerName;
    }

    void Player::setPlayerName(std::string PlayerName){
        this->playerName = playerName;
    }

    int Player::getPlayerGuessX(int x){
        return x;
    }

    int Player::getPlayerGuessY(int y){
        return y;
    }

    void Player::setPlayerGuessCords(int x, int y) {
        this->x = x;
        this-> y = y;
    }

    std::string Player::getPlayerGuessFootballer(std::string playerGuessFootballer){
        return playerGuessFootballer;
    };

    void Player::setPlayerGuessFootballer(std::string playerGuessFootballer) {
        this->playerGuessFootballer = playerGuessFootballer;
    }

    char Player::getSymbol() {
        return symbol;
    }

    void Player::setSymbol(char symbol) {
        this->symbol = symbol;
    }


}

