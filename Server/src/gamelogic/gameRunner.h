//
// Created by bruno on 17-11-2023.
//

#ifndef SERVER_GAMERUNNER_H
#define SERVER_GAMERUNNER_H

#include "game.h"
#include "../communication/communication.h"

class gameRunner {
private:
    gamelogic::Player player1, player2;
    bool running = false;
    gamelogic::game game;
    std::string gamepin;
    int argc;
    char** argv;
    std::vector<int> prevGame;
public:
    // Default constructor
    gameRunner();
    // Constructor that gets program arguments
    gameRunner(int argc, char** argv);
    // Start current game
    void startGame();
    // Generate a Random pin for remote game
    void setGamePin();
    // Getter for gamepin
    std::string getGamePin();
    // Logic to run the TIKI TAKA TOE game in the CMD
    void runCMD();
    // Logic to run the TIKI TAKA TOE game remotely
    void runRemote();
    // Check if game is still running
    bool isGameInProgress();
    // Exchange Clients names in remote game version
    void exchangeNames(communication client1, communication client2);
    // Send game parameters to clients in remote game version
    void sendParams(communication client1, communication client2);
    // Get client play in remote game version
    std::vector<std::string> getPlay(communication client);
    // Aux function to get inputs from terminal
    int getIntCMD(std::string name);
    // Method to generate random string for the remote game version
    std::string randomString();
    // End game
    void endGame();
    // Method that executes one game logic
    void gameCycle(communication client1, communication client2);
    // Task Function to run the remote Game
    void gameThread(communication client1, communication client2);
    // Task Function to run the remote chat
    void chatThread(communication chat1, communication chat2);

};



#endif //SERVER_GAMERUNNER_H
