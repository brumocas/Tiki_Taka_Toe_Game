//
// Created by bruco on 11/10/2023.
//

#include "game.h"

namespace gamelogic{

    void game::setWinner(gamelogic::Player player) {
        winner = player;
    }

    Player game::getWinner() {
        return winner;
    }

    bool game::isGameWonByPlayer(gamelogic::Player player) {
        if(player.playerName == winner.playerName)
            return true;
        else
            return false;
    }

}