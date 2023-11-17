//
// Created by bruno on 17-11-2023.
//

#ifndef SERVER_GAMERUNNER_H
#define SERVER_GAMERUNNER_H

#include "game.h"

class gameRunner {
private:
    bool running = false;
    gamelogic::game game;
public:
    void run();
    void startGame();
    bool isGameInProgress();
};;


#endif //SERVER_GAMERUNNER_H
