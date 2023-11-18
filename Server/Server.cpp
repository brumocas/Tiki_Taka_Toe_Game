#include <iostream>
#include "src/gamelogic/gameRunner.h"
#include "gtest/gtest.h"


int main(int argc, char **argv) {

    // Testing implementation
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    /*
    gameRunner gameRunner;
    gameRunner.run();

    while (gameRunner.isGameInProgress()){
        // Do nothing for now when game is running

    }
    std::cout << "Game Ended\n";
    */

    return 0;
}
