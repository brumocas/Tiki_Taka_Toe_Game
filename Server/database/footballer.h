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

    // Equality operator
    bool operator==(const footballer& other) const {
        return name == other.name &&
               surname == other.surname &&
               birth_year == other.birth_year &&
               birth_month == other.birth_month &&
               nationality == other.nationality &&
               career_teams == other.career_teams &&
               world_cup_winner == other.world_cup_winner &&
               champions_league_winner == other.champions_league_winner &&
               ballon_dor_winner == other.ballon_dor_winner &&
               european_winner == other.european_winner;
    }

};

#endif //SERVER_FOOTBALLER_H
