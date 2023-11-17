//
// Created by bruno on 17-11-2023.
//

#include "gameRunner.h"

void gameRunner::run() {
    // TODO : to complete
    startGame();
    game.print();

    while (running){
        // player 1 plays

        // check if player 1 wins

        // player 2 plays

        // check if player 2 wins

        // check if game is tied

    }

}

void gameRunner::startGame() {
    this->running = true;
    // TODO: Check teams and Cups
    game.setParams("Real_Madrid", "Barcelona", "PSG", "BD", "EW", "WCW");
}

bool gameRunner::isGameInProgress() {
    return this->running;
}
