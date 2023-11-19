//
// Created by bruno on 17-11-2023.
//

#ifndef SERVER_GAMERUNNER_H
#define SERVER_GAMERUNNER_H

#include "game.h"

class gameRunner {
private:
    gamelogic::Player player1, player2;
    bool running = false;
    gamelogic::game game;
public:
    void runCMD();
    void runRemote();
    void startGame();
    bool isGameInProgress();
};;

#endif //SERVER_GAMERUNNER_H
