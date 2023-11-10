//
// Created by bruco on 11/10/2023.
//

#include "database.h"

// Constructor
database::database() {
    // Do nothing
}

void database::addFootballer(footballer player) {
    this->db.push_back(player);
}

void database::deleteFootballer(footballer player) {

}

footballer database::searchFootballer(std::string name, std::string surname) {

    return footballer();
}

footballer database::searchParams(std::string parameter) {
    return footballer();
}

