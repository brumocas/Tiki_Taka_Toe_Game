//
// Created by bruco on 11/10/2023.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include "database.h"

// Constructor
database::database() {
    // Do nothing
}

void database::addFootballer(footballer player) {
    if (!searchFootballer(player.getName(), player.getSurname()))
        this->db.push_back(player);
}

void database::deleteFootballer(footballer player) {
    db.erase(std::remove(db.begin(), db.end(), player), db.end());
}

bool database::searchFootballer(std::string name, std::string surname) const {
    for (int i = 0; i < db.size(); i++){
        footballer f = db[i];
        if (f.getName() == name && f.getSurname() == surname)
            return true;
    }
    return false;
}

bool database::searchParams(std::string parameter) {
    // TODO: To be completed
    return false;
}

void database::print() {
    std::cout << "/-----------------Database-----------------/" << std::endl;
    for (int i = 0; i < db.size(); ++i) {
        db[i].print();
        std::cout << std::endl;
    }
}

void database::load() {
    // Open a text file for reading
    std::ifstream inputFile("database/database.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
    }

    // Read and print the contents of the file
    std::string line;
    // TODO: Line parsing
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    // Close the file
    inputFile.close();
}







