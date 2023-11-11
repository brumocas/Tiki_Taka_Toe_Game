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
public:
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
    // Load Database line by line
    void load();
    // Function to parse lines
    std::vector<std::string> parseLine(std::string& line);
    // Function to parse teams string
    std::vector<std::string> parseTeams(std::string &string);
};


#endif //SERVER_DATABASE_H
