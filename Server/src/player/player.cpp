//
// Created by fmesquita on 11/10/23.
//
#include "player.h"

#include <iostream>
#include <string>

namespace gamelogic{

    Player::Player() {
        playerName = "Unknown";
        x = -1;
        y = -1;
    }

    Player::Player(std::string playerName, char symbol){
        this->playerName = playerName;
        this->symbol = symbol;
        x = -1;
        y = -1;
    }

    std::string Player::getPlayerName() {
        return playerName;
    }

    void Player::setPlayerName(std::string PlayerName){
        this->playerName = PlayerName;
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

    void Player::increaseScore() {
        numberWins++;
    }

    int Player::getScore() {
        return numberWins;
    }

}

