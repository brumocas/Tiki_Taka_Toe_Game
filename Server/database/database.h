//
// Created by bruco on 11/10/2023.
//

#ifndef SERVER_DATABASE_H
#define SERVER_DATABASE_H


#include <vector>
#include <string>
#include "footballer.h"

class database {
private:
    std::vector<footballer> db;
public:
    database();
    // Add footballer to database
    void addFootballer(footballer player);
    // Delete footballer from database
    void deleteFootballer(footballer player);
    // Search footballer by name and surname in the database
    footballer searchFootballer(std::string name, std::string surname);
    // Search if there is a footballer with the passed parameter
    footballer searchParams(std::string parameter);
};


#endif //SERVER_DATABASE_H
