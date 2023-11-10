//
// Created by bruco on 11/10/2023.
//

#ifndef SERVER_FOOTBALLER_H
#define SERVER_FOOTBALLER_H


#include <string>
#include <vector>

class footballer {
private:
    std::string name;
    std::string surname;
    int birth_year;
    int birth_month;
    std::string nationality;
    std::vector<std::string> career_teams;
    bool world_cup_winner;
    bool champions_league_winner;
    bool ballon_dor_winner;
    bool european_winner;

public:
    // Constructor
    footballer(std::string name, std::string surname, int birth_year, int birth_month, std::string nationality, std::vector<std::string> career_teams,
               bool world_cup_winner, bool champions_league_winner, bool ballon_dor_winner, bool european_winner);
    std::string getName();
    std::string getSurname();
    int getBirthYear() const;
    int getBirthMonth() const;
    std::string getNationality();
    std::vector<std::string> getCareerTeams();
    bool isWorldCupWinner() const;
    bool isChampionsLeagueWinner() const;
    bool isBallonDorWinner() const;
    bool isEuropeanWinner() const;
    void print();

};

#endif //SERVER_FOOTBALLER_H
