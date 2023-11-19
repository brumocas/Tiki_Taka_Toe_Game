//
// Created by bruno on 17-11-2023.
//

#include "gtest/gtest.h"
#include "../src/gamelogic/board.h"

TEST(setUpParams_getUpParams, Normal){

    gamelogic::Board testBoard;
    std::string param1,param2,param3;

    param1 = "test1";
    param2 = "test2";
    param3 = "test3";
    testBoard.setUpParams(param1, param2, param3);

    ASSERT_EQ(testBoard.getUpParams(0), param1);
    ASSERT_EQ(testBoard.getUpParams(1), param2);
    ASSERT_EQ(testBoard.getUpParams(2), param3);

}

TEST(setLeftParams_getLeftParams, Normal){

    gamelogic::Board testBoard;
    std::string param1,param2,param3;

    param1 = "test1";
    param2 = "test2";
    param3 = "test3";
    testBoard.setLeftParams(param1, param2, param3);

    ASSERT_EQ(testBoard.getLeftParams(0), param1);
    ASSERT_EQ(testBoard.getLeftParams(1), param2);
    ASSERT_EQ(testBoard.getLeftParams(2), param3);

}
TEST(Constructor_getParams_getSymbol, Normal){

    gamelogic::Board testBoard;
    std::string param1Up, param2Up, param3Up, param1Left, param2Left, param3Left;

    param1Up = testBoard.getUpParams(0);
    param2Up = testBoard.getUpParams(1);
    param3Up = testBoard.getUpParams(2);

    param1Left = testBoard.getUpParams(0);
    param2Left = testBoard.getUpParams(1);
    param3Left = testBoard.getUpParams(2);

    ASSERT_EQ("Unknown", param1Up);
    ASSERT_EQ("Unknown", param2Up);
    ASSERT_EQ("Unknown", param3Up);
    ASSERT_EQ("Unknown", param1Left);
    ASSERT_EQ("Unknown", param2Left);
    ASSERT_EQ("Unknown", param3Left);

    char Symbol;
    Symbol = testBoard.getSymbol(0, 0);
    ASSERT_EQ('-', Symbol);
    Symbol = testBoard.getSymbol(0, 1);
    ASSERT_EQ('-', Symbol);
    Symbol = testBoard.getSymbol(0, 2);
    ASSERT_EQ('-', Symbol);
    Symbol = testBoard.getSymbol(1, 0);
    ASSERT_EQ('-', Symbol);
    Symbol = testBoard.getSymbol(1, 1);
    ASSERT_EQ('-', Symbol);
    Symbol = testBoard.getSymbol(1, 2);
    ASSERT_EQ('-', Symbol);
    Symbol = testBoard.getSymbol(2, 0);
    ASSERT_EQ('-', Symbol);
    Symbol = testBoard.getSymbol(2, 1);
    ASSERT_EQ('-', Symbol);
    Symbol = testBoard.getSymbol(2, 2);
    ASSERT_EQ('-', Symbol);

}

TEST(isFull, Normal){

    gamelogic::Board testBoard;
    ASSERT_EQ(testBoard.isFull(),0);

}






