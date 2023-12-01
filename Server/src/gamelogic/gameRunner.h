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

public:
    gameRunner();
    gameRunner(int argc, char** argv);
    void startGame();
    void setGamePin();
    std::string getGamePin();
    void runCMD();
    void runRemote();
    bool isGameInProgress();
    void exchangeNames(communication client1, communication client2);
    void sendParams(communication client1, communication client2);
    std::vector<std::string> getPlay(communication client);
    int getIntCMD(std::string name);
    std::string randomString();
};



#endif //SERVER_GAMERUNNER_H
