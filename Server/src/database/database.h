//
// Created by bruco on 11/10/2023.
//

#ifndef SERVER_DATABASE_H
#define SERVER_DATABASE_H


#include <vector>
#include <string>
#include "footballer.h"
#include "parameters.h"

class param;

class database {
private:
    std::vector<footballer> db;
    std::vector<std::string> teams;
    std::vector<std::string> nations;
public:
    // Constructor
    database();
    // Add footballer to database
    void addFootballer(footballer player);
    // Delete footballer from database
    void deleteFootballer(footballer player);
    // Search if footballer by name and surname in the database is true
    bool searchFootballer(std::string name, std::string surname) const;
    // Search footballer by name and surname in the database
    footballer getFootballer(std::string name, std::string surname);
    // Search if there is a footballer with the passed parameter as string
    bool searchParams(parameters parameter, std::string param);
    // Search if there is a footballer with the passed parameter as int
    bool searchParams(parameters parameter, int param);
    // Search if there is a footballer with the passed parameter as bool
    bool searchParams(parameters parameter, bool param);
    // Print Database for debug
    void print();
    // Print Teams for debug
    void printTeams();
    // Print Teams for debug
    void printNations();
    // Load Database line by line
    void load(std::string path);
    // Function to parse lines
    std::vector<std::string> parseLine(std::string& line);
    // Function to parse teams string
    std::vector<std::string> parseTeams(std::string &string);
    // Number of footballers in the database
    int size();
    // Store all Teams available in the DB
    void loadTeams();
    // Get all Teams available in the DB
    std::vector<std::string> getTeams();
    // Store all Nations available in the DB
    void loadNations();
    // Get all Teams available in the DB
    std::vector<std::string> getNations();
    // Check if the param is Team
    bool isTeam(std::string string);
    // Check if the param is Nation
    bool isNation(std::string string);
};


#endif //SERVER_DATABASE_H
