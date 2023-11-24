#include <iostream>
#include "src/gamelogic/gameRunner.h"
#include "src/database/database.h"
#include "gtest/gtest.h"


void printMenu();

void runMenu();

void remoteGame();

void localGame();

void databaseSearch(database db);

void databaseMenu();

int main(int argc, char **argv) {

    // Testing implementation
    //::testing::InitGoogleTest(&argc, argv);
    //RUN_ALL_TESTS();

    // Simple Menu
    //runMenu();

    remoteGame();

    return 0;
}

void runMenu() {

    int option;
    while (true) {
        printMenu();
        std::cout << "Insert option : ";
        std::cin >> option;

        switch (option) {
            case 1: {
                // Local Game
                localGame();
                break;
            }
            case 2: {
                // Remote Game
                remoteGame();
                break;
            }
            case 3: {
                // Database search
                databaseMenu();
                break;
            }
            default:
                std::cout << "Invalid option\n";
                break;
        }

        // Quit Main application
        if (option == 4)
            break;

        std::cout << std::endl;
    }
}

void databaseMenu() {
    database db;
    db.load("../src/database/files/game_test_database.txt");
    int option;
    while (true){
        std::cout << std::endl;
        std::cout << "/----Database Menu----/\n";
        std::cout << "Print Database (1)\n";
        std::cout << "Search Player (2)\n";
        std::cout << "Go Back (3)\n";
        std::cout << "Insert option : ";
        std::cin >> option;

        switch (option) {
            case 1:{
                db.print();
                break;
            }
            case 2:{
                databaseSearch(db);
                break;
            }
            case 3:{
                return;
            }
            default:
                std::cout << "Invalid option\n";
                break;
        }
    }
}

void databaseSearch(database db) {
    std::string name;
    std::string surname;
    std::cout << "Footballer Search\n";
    std::cout << "Name:";
    std::cin >> name;
    std::cout << "Surname:";
    std::cin >> surname;
    if(db.searchFootballer(name, surname)){
        footballer f = db.getFootballer(name, surname);
        f.print();
        std::cout << std::endl;
    } else {
        std::cout << "Player not found\n";
    }
}

void localGame() {
    gameRunner gameRunner;
    gameRunner.runCMD();
    std::cout << "Local Game Ended\n";
}

void remoteGame() {
    gameRunner gameRunner;
    gameRunner.runRemote();
    std::cout << "Remote Game Ended\n";
}

void printMenu() {
    // Print Menu options
    std::cout << "/----Main Menu----/\n";
    std::cout << "Local Game (1)\n";
    std::cout << "Remote Game (2)\n";
    std::cout << "Database (3)\n";
    std::cout << "Quit (4)\n";
}

