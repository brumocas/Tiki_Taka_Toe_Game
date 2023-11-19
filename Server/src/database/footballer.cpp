//
// Created by bruco on 11/10/2023.
//

#include <iostream>
#include "footballer.h"

footballer::footballer() {
    // Default Constructor
    this->name = "";
    this->surname = "";
    this->birth_year = -1;
    this->birth_month = -1;
    this->nationality = "";
    this->world_cup_winner = false;
    this->champions_league_winner = false;
    this->ballon_dor_winner = false;
    this->european_winner = false;
}


footballer::footballer(std::string name, std::string surname, int birth_year, int birth_month, std::string nationality,
                       std::vector<std::string> career_teams, bool world_cup_winner, bool champions_league_winner,
                       bool ballon_dor_winner, bool european_winner) {

    this->name = name;
    this->surname = surname;
    this->birth_year = birth_year;
    this->birth_month = birth_month;
    this->nationality = nationality;
    this->career_teams = career_teams;
    this->world_cup_winner = world_cup_winner;
    this->champions_league_winner = champions_league_winner;
    this->ballon_dor_winner = ballon_dor_winner;
    this->european_winner = european_winner;
}

std::string footballer::getName() {
    return this->name;
}

std::string footballer::getSurname() {
    return this->surname;
}

int footballer::getBirthYear() const {
    return this->birth_year;
}

int footballer::getBirthMonth() const {
    return this->birth_month;
}

std::string footballer::getNationality() {
    return this->nationality;
}

std::vector<std::string> footballer::getCareerTeams() {
    return this->career_teams;
}

bool footballer::isWorldCupWinner() const {
    return world_cup_winner;
}

bool footballer::isChampionsLeagueWinner() const {
    return champions_league_winner;
}

bool footballer::isBallonDorWinner() const {
    return ballon_dor_winner;
}

bool footballer::isEuropeanWinner() const {
    return european_winner;
}

void footballer::print() {
    std::cout << "/-----------------footballer--------------/" << std::endl;
    std::cout << "Name : " + name << std::endl;
    std::cout << "Surname : " + surname << std::endl;
    std::cout << "birthYear : ";
    std::cout << birth_year << std::endl;
    std::cout << "birthMonth : ";
    std::cout << birth_month << std::endl;
    std::cout << "Nationality : " + nationality << std::endl;
    std::cout << "Teams : ";
    for (int i = 0;  i < career_teams.size(); i++) {
        std::cout << career_teams[i] + ", ";
    }
    std::cout << std::endl;
    std::cout << "World Cup Winner : " << world_cup_winner << std::endl;
    std::cout << "Champions League Winner : " << champions_league_winner << std::endl;
    std::cout << "Ballon Dor Winner : " << ballon_dor_winner << std::endl;
    std::cout << "European Winner : "  << european_winner << std::endl;

}











