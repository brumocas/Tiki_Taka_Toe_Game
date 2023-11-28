//
// Created by bruco on 11/10/2023.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <algorithm>
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
    for (auto f : db){
        if (f.getName() == name && f.getSurname() == surname)
            return true;
    }
    return false;
}

footballer database::getFootballer(std::string name, std::string  surname){
    footballer null;
    for (auto f : db) {
        if (f.getName() == name && f.getSurname() == surname)
            return f;
    }
    return null;
}

bool database::searchParams(parameters parameter, std::string param) {

    switch(parameter) {
        case parameters::Name:
            for(auto & f : db){
                if (f.getName() == param)
                    return true;
            }
            break;
        case parameters::Surname:
            for(auto & f : db){
                if (f.getSurname() == param)
                    return true;
            }
            break;
        case parameters::Nationality:
            for(auto & f : db){
                if (f.getNationality() == param)
                    return true;
            }
            break;
        case parameters::CareerTeams:
            for(auto & f : db){
                std::vector<std::string> teams = f.getCareerTeams();
                for(auto & t : teams){
                    if (t == param)
                        return true;
                }
            }
            break;
        default:
            std::cerr << "Invalid choice\n";
    }
    return false;
}

bool database::searchParams(parameters parameter, int param) {
    switch(parameter) {
        case parameters::BirthYear:
            for(auto & f : db){
                if (f.getBirthYear() == param)
                    return true;
            }
            break;
        case parameters::BirthMonth:
            for(auto & f : db){
                if (f.getBirthMonth() == param)
                    return true;
            }
            break;
        default:
            std::cerr << "Invalid choice\n";
    }
    return false;
}

bool database::searchParams(parameters parameter, bool param) {
    switch(parameter) {
        case parameters::WorldCupWinner:
            for(auto & f : db){
                if (f.isWorldCupWinner() == param)
                    return true;
            }
            break;
        case parameters::ChampionsLeagueWinner:
            for(auto & f : db){
                if (f.isChampionsLeagueWinner() == param)
                    return true;
            }
            break;
        case parameters::BallonDorWinner:
            for(auto & f : db){
                if (f.isBallonDorWinner() == param)
                    return true;
            }
            break;
        case parameters::EuropeanWinner:
            for(auto & f : db){
                if (f.isEuropeanWinner() == param)
                    return true;
            }
            break;
        default:
            std::cerr << "Invalid choice\n";
    }
    return false;
}


void database::print() {
    std::cout << "/-----------------Database-----------------/" << std::endl;
    for (auto & i : db) {
        i.print();
        std::cout << std::endl;
    }
    std::cout << "/-----------------Database-End-------------/" << std::endl << std::endl;
}

void database::load(std::string path) {
    // Open a text file for reading
    std::ifstream inputFile(path);

    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
    }

    // Read the contents of the file
    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<std::string> parsed = parseLine(line);

        // Ignore first line of database txt
        if (parsed[0] == "Name")
            continue;

        // create a vector with the player previous teams
        std::vector<std::string> career_teams = parseTeams(parsed[9]);

        // Create an object of the new player
        footballer player(parsed[0], parsed[1], std::stoi(parsed[2]), std::stoi(parsed[3]), parsed[4],
                              career_teams, std::stoi(parsed[5]), std::stoi(parsed[6]),
                              std::stoi(parsed[7]), std::stoi(parsed[8]));

        // add new player to database
        addFootballer(player);
    }

    // Close the file
        inputFile.close();
    // Load all DB Teams
    loadTeams();
    // Load all DB Nations
    loadNations();
}

std::vector<std::string> database::parseLine(std::string& line) {
    std::vector<std::string> parsed;

    std::istringstream lineStream(line);
    std::string attribute;


    while (std::getline(lineStream, attribute, ',')) {
        // Remove leading whitespace
        if (!attribute.empty() && attribute[0] == ' ') {
            attribute = attribute.substr(1);
        }

        parsed.push_back(attribute);
    }

    return parsed;
}

std::vector<std::string> database::parseTeams(std::string& string) {
    std::vector<std::string> teams;

    std::istringstream iss(string);
    std::string word;

    while (iss >> word) {
        teams.push_back(word);
    }

    return teams;
}

int database::size() {
    return db.size();
}

void database::loadTeams() {


    for (auto & f : db) {
        std::vector<std::string> career_teams = f.getCareerTeams();
        for (auto & t : career_teams) {
            // Check if the vector does not contain the string
            auto it = std::find(teams.begin(), teams.end(), t);
            if (it == teams.end())
            teams.push_back(t);
        }
    }
}

void database::loadNations() {
    for (auto & f : db) {
        // Check if the vector does not contain the string
        auto it = std::find(nations.begin(), nations.end(), f.getNationality());
        if (it == nations.end())
        nations.push_back(f.getNationality());
    }
}

bool database::isTeam(std::string string) {
    loadTeams();
    std::vector<std::string> teams = getTeams();
    for (auto & t : teams) {
        if (t == string)
            return true;
    }
    return false;
}

bool database::isNation(std::string string) {
    loadNations();
    std::vector<std::string> nations = getNations();
    for (auto & n : nations) {
        if (n == string)
            return true;
    }
    return false;
}

std::vector<std::string> database::getTeams() {
    return teams;
}

std::vector<std::string> database::getNations() {
    return nations;
}

void database::printTeams() {
    std::cout << std::endl;
    std::cout << "DB Teams: " << std::endl;
    for (int i = 0; i < teams.size(); ++i) {
        std::cout << teams[i] << std::endl;
    }
    std::cout << std::endl;
}

void database::printNations() {
    std::cout << std::endl;
    std::cout << "DB Nations: " << std::endl;
    for (int i = 0; i < nations.size(); ++i) {
        std::cout << nations[i] << std::endl;
    }
    std::cout << std::endl;
}














