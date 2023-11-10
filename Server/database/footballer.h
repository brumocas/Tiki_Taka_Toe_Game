//
// Created by bruco on 11/10/2023.
//

#ifndef SERVER_FOOTBALLER_H
#define SERVER_FOOTBALLER_H


#include <string>
#include <wsman.h>
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
    footballer(std::string name, std::string surname, int birth_year, int birth_date, std::string nationality, std::vector<std::string> career_teams,
               bool world_cup_winner, bool);




};


#endif //SERVER_FOOTBALLER_H
