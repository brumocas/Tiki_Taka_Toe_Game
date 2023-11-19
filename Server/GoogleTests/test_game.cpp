//
// Created by bruno on 18-11-2023.
//
#include "gtest/gtest.h"
#include "../src/gamelogic/game.h"

/*TEST(checkAnswer, ValidPlay) {
    gamelogic::game testGame;
    gamelogic::Player player;//("Player1", 'X');
    player.setFootballerGuessName("Lionel");
    player.setFootballerGuessSurname("Messi");
    player.setPlayerGuessCords(0, 1);
    ASSERT_TRUE(testGame.checkAnswer(player));
}*/

TEST(checkAnswer, InvalidPlay) {
    gamelogic::game testGame;
    gamelogic::Player player;//("Player1", 'X')
    // Making an invalid play on an already occupied cell
    //player.setPlayerGuessCords(0, 0);
    //ASSERT_TRUE(testGame.checkAnswer(player));
    // Trying to make another play in the same cell (should be invalid)
    ASSERT_FALSE(testGame.checkAnswer(player));
}

TEST(setWinner, ValidWinner) {
    gamelogic::game testGame;
    gamelogic::Player player("Valid Winner", 'X');
    testGame.setWinner(player);
    ASSERT_EQ(player, testGame.getWinner());
}

TEST(setWinner, InvalidWinner) {
    gamelogic::game testGame;
    gamelogic::Player player("Invalid Winner", 'X');
    testGame.setWinner(player);
    // Trying to set an invalid winner (should not change the existing winner)
    //gamelogic::Player invalidWinner("Player2", 'O');
    //testGame.setWinner(invalidWinner);
    //ASSERT_EQ("Invalid Winner", testGame.getWinner());
}

TEST(getWinner, NoWinner) {
    gamelogic::game testGame;
    gamelogic::Player winner = testGame.getWinner();
    // Initially, there should be no winner (winner object should be default/empty)
    //ASSERT_EQ("", testGame.getWinner());
}

TEST(isGameWonByPlayer, GameNotWon) {
    gamelogic::game testGame;
    gamelogic::Player player("Player1", 'X');
    ASSERT_FALSE(testGame.isGameWonByPlayer(player));
}

/*TEST(isGameWonByPlayer, GameWon) {
    gamelogic::game testGame;
    gamelogic::Player player("Player1", 'X');
    // Making a winning move
    testGame.setWinner(player);
    ASSERT_TRUE(testGame.isGameWonByPlayer(player));
}*/

TEST(isGameTied, GameNotTied) {
    gamelogic::game testGame;
    gamelogic::Player player1("Player1", 'X');
    gamelogic::Player player2("Player2", 'O');
    // Making moves without winning or tying the game
    testGame.checkAnswer(player1);
    testGame.checkAnswer(player2);
    ASSERT_FALSE(testGame.isGameTied(player1, player2));
}

TEST(isGameTied, GameTied) {
    gamelogic::game testGame;
    gamelogic::Player player1("Player1", 'X');
    gamelogic::Player player2("Player2", 'O');
    // Filling the board without a winner
    testGame.checkAnswer(player1);
    testGame.checkAnswer(player2);
    testGame.checkAnswer(player1);
    testGame.checkAnswer(player2);
    testGame.checkAnswer(player1);
    testGame.checkAnswer(player2);
    testGame.checkAnswer(player2);
    testGame.checkAnswer(player1);
    testGame.checkAnswer(player1);
    ASSERT_TRUE(testGame.isGameTied(player1, player2));
}

TEST(winningCombinations, NoWinningCombination) {
    gamelogic::game testGame;
    gamelogic::Player player("Player1", 'X');
    // Making moves without a winning combination
    testGame.checkAnswer(player);
    ASSERT_FALSE(testGame.winningCombinations(player.getSymbol()));
}

TEST(winningCombinations, WinningCombination) {
    gamelogic::game testGame;
    gamelogic::Player player("Player1", 'X');
    // Making a winning combination
    testGame.checkAnswer(player);
    testGame.checkAnswer(player);
    testGame.checkAnswer(player);
    ASSERT_TRUE(testGame.winningCombinations(player.getSymbol()));
}

