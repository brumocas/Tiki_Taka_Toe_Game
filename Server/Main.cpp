#include <iostream>
#include "src/gamelogic/gameRunner.h"
#include "src/database/database.h"
#include "gtest/gtest.h"


class gameApplication {
public:
    void run(int argc, char** argv) {

        while (true) {
            int option;
            printMenu();
            // Quit Main application
            if (option == 4)
                break;
            std::cout << "Insert option : ";
            std::cin >> option;
            std::cout << std::endl;

            switch (option) {
                case 1: {
                    // Local Game
                    localGame();
                    break;
                }
                case 2: {
                    // Remote Game
                    remoteGame(argc, argv);
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
            std::cout << std::endl;
        }
    }

private:
    static void printMenu() {
        // Print Menu options
        std::cout << "/----Main Menu----/\n";
        std::cout << "Local Game (1)\n";
        std::cout << "Remote Game (2)\n";
        std::cout << "Database (3)\n";
        std::cout << "Quit (4)\n";
        std::cout << std::endl;
    }

    static void localGame() {
        // Local Gaming Session
        std::cout << "Local game session started :)" << std::endl;
        gameRunner gameRunner;
        gameRunner.runCMD();
        std::cout << "Local Game Ended\n";
    }

    static void remoteGame(int argc, char** argv) {
        // Remote Gaming Session
        std::cout << "Remote game session started :)" << std::endl;
        gameRunner gameRunner(argc, argv);
        gameRunner.startGame();
        gameRunner.runRemote();
        std::cout << "Remote Game Ended\n";
    }

    void databaseMenu() {
        database db;
        db.load("../src/database/files/default_database.txt");
        int option;
        while (true) {
            // Print database menu
            std::cout << "/----Database Menu----/\n";
            std::cout << "Print Database (1)\n";
            std::cout << "Search Player (2)\n";
            std::cout << "Print Teams (3)\n";
            std::cout << "Print Nations (4)\n";
            std::cout << "Go Back (5)\n";
            std::cout << std::endl;
            std::cout << "Insert option : ";
            std::cin >> option;
            std::cout << std::endl;

            // Database menu Options
            switch (option) {
                case 1: {
                    db.print();
                    break;
                }
                case 2: {
                    databaseSearch(db);
                    break;
                }
                case 3: {
                    db.printTeams();
                    break;
                }
                case 4: {
                    db.printNations();
                    break;
                }
                case 5: {
                    return;
                }
                default:
                    std::cout << "Invalid option\n";
                    break;
            }
        }
    }

    static void databaseSearch(database db) {
        // Search for a specific footballer in the db
        std::string name;
        std::string surname;
        std::cout << "Footballer Search\n";
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Surname: ";
        std::cin >> surname;
        if (db.searchFootballer(name, surname)) {
            footballer f = db.getFootballer(name, surname);
            f.print();
            std::cout << std::endl;
        } else {
            std::cout << "Player not found\n\n";
        }
    }
};

int main(int argc, char **argv) {

    // Testing implementation
    if (std::strcmp(argv[1], "True") == 0){
        ::testing::InitGoogleTest(&argc, argv);
        RUN_ALL_TESTS();
        std::cout << std::endl << std::endl;
    }

    // Game Application
    gameApplication gameApp ;
    gameApp.run(argc, argv);
    return 0;
}

