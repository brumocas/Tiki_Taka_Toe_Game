//
// Created by bruco on 11/10/2023.
//

#include <iostream>
#include "database.h"

// Constructor
database::database() {
    // Do nothing
}

void database::addFootballer(footballer player) {
    this->db.push_back(player);
}

void database::deleteFootballer(std::string name, std::string surname) {

}

void database::searchFootballer(std::string name, std::string surname) {
}

void database::searchParams(std::string parameter) {

}

void database::print() {
    std::cout << "/-----------------Database-----------------/" << std::endl;
    for (int i = 0; i < db.size(); ++i) {
        db[i].print();
        std::cout << std::endl;
    }
}





