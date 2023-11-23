//
// Created by fmesquita on 11/10/23.
//
#include "player.h"

#include <iostream>
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
        x = -1; // valid plays are 0, 1, 2, 10, 11, 12 , 20, 21, 22,
        y = -1; // when x or y = 3 it means the play is invalid or that the player didn't make a play yet
    }

    std::string Player::getPlayerName() {
        return playerName;
    }

    void Player::setPlayerName(std::string PlayerName){
        this->playerName = playerName;
    }

    int Player::getPlayerGuessX(){
        return x;
    }

    int Player::getPlayerGuessY(){
        return y;
    }

    void Player::setPlayerGuessCords(int x, int y) {
        this->x = x;
        this-> y = y;
    }


    char Player::getSymbol() {
        return symbol;
    }

    void Player::setSymbol(char symbol) {
        this->symbol = symbol;
    }

    std::string Player::getFootballerGuessName() {
        return this->FootballerGuessName;
    }

    void Player::setFootballerGuessName(std::string name) {
        FootballerGuessName = name;
    }

    std::string Player::getFootballerGuessSurname() {
        return FootballerGuessSurname;
    }

    void Player::setFootballerGuessSurname(std::string surname) {
        FootballerGuessSurname = surname;
    }

}

