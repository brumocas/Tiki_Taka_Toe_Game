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
    int getIntCommand();

public:
    void startGame();
    void runCMD();
    void runRemote();
    bool isGameInProgress();
    void connectRemote(Communication client1, Communication client2);
    void exchangeNames(Communication client1, Communication client2);
    void sendParams(Communication client1, Communication client2);
    std::vector<std::string> getPlay(Communication client);
    int getIntCMD(std::string name);
};



#endif //SERVER_GAMERUNNER_H
