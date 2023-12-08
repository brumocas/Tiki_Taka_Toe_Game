//
// Created by bruno on 18-11-2023.
//
#include "gtest/gtest.h"
#include "../src/gamelogic/game.h"

// DB used for testing
std::string dbpath = "../src/database/files/game_test_database.txt";

TEST(checkAnswer, ValidPlay) {
    gamelogic::game testGame(dbpath);
    testGame.setParams("Real_Madrid", "Barcelona", "PSG", "BD", "CL", "Portugal");
    gamelogic::Player player("Player1", 'x');
    player.setFootballerGuessName("Lionel");
    player.setFootballerGuessSurname("Messi");
    player.setPlayerGuessCords(0, 1);
    ASSERT_TRUE(testGame.checkAnswer(player));
}

TEST(checkAnswer, InvalidPlay1) {
    gamelogic::game testGame(dbpath);
    gamelogic::Player player("Player1", 'x');
    testGame.setParams("Real_Madrid", "Barcelona", "PSG", "BD", "CL", "Portugal");
    // Making an invalid play on an already occupied cell
    player.setPlayerGuessCords(0, 1);
    player.setFootballerGuessName("Lionel");
    player.setFootballerGuessSurname("Messi");
    testGame.checkAnswer(player);
    ASSERT_FALSE(testGame.checkAnswer(player));
}

TEST(checkAnswer, InvalidPlay2) {
    gamelogic::game testGame(dbpath);
    gamelogic::Player player("Player1", 'x');
    testGame.setParams("Real_Madrid", "Barcelona", "PSG", "BD", "CL", "Portugal");
    // Making an invalid play, incorrect player
    player.setPlayerGuessCords(0, 1);
    player.setFootballerGuessName("Lionel");
    player.setFootballerGuessSurname("Pessi");
    testGame.checkAnswer(player);
    ASSERT_FALSE(testGame.checkAnswer(player));
}


TEST(isGameWonByPlayer, GameNotWon) {
    gamelogic::game testGame(dbpath);
    testGame.setParams("Real_Madrid", "Barcelona", "PSG", "BD", "CL", "Portugal");
    gamelogic::Player player("Player1", 'X');
    player.setFootballerGuessName("Cristiano");
    player.setFootballerGuessSurname("Ronaldo");
    player.setPlayerGuessCords(0,0);
    testGame.checkAnswer(player);
    ASSERT_FALSE(testGame.isGameWonByPlayer(player));
}

TEST(isGameWonByPlayer, GameWon) {
    gamelogic::game testGame(dbpath);
    gamelogic::Player player("Player1", 'X');
    testGame.setParams("Real_Madrid", "Barcelona", "PSG", "BD", "CL", "Portugal");
    player.setFootballerGuessName("Cristiano");
    player.setFootballerGuessSurname("Ronaldo");
    player.setPlayerGuessCords(0,0);
    testGame.checkAnswer(player);
    player.setPlayerGuessCords(1,0);
    testGame.checkAnswer(player);
    player.setPlayerGuessCords(2,0);
    testGame.checkAnswer(player);
    if(testGame.winningCombinations(player.getSymbol()))
        testGame.setWinner(player);
    ASSERT_TRUE(testGame.isGameWonByPlayer(player));
}

TEST(isGameTied, GameNotTied) {
    gamelogic::game testGame(dbpath);
    gamelogic::Player player1("Player1", 'X');
    gamelogic::Player player2("Player2", 'O');
    testGame.setParams("Real_Madrid", "Barcelona", "PSG", "BD", "CL", "Portugal");
    player1.setFootballerGuessName("Cristiano");
    player1.setFootballerGuessSurname("Ronaldo");
    player1.setPlayerGuessCords(0,0);
    player2.setPlayerGuessCords(1,1);
    testGame.checkAnswer(player1);
    testGame.checkAnswer(player2);
    player2.setFootballerGuessName("Cristiano");
    player2.setFootballerGuessSurname("Ronaldo");
    player2.setPlayerGuessCords(1,0);
    testGame.checkAnswer(player2);
    ASSERT_FALSE(testGame.isGameTied(player1, player2));
}

TEST(isGameTied, GameTied) {
    gamelogic::game testGame(dbpath);
    gamelogic::Player player1("Player1", 'X');
    gamelogic::Player player2("Player2", 'O');
    testGame.setParams("Real_Madrid", "Barcelona", "PSG", "BD", "CL", "CL");
    // Filling the board without a winner
    player1.setFootballerGuessName("Cristiano");
    player1.setFootballerGuessSurname("Ronaldo");
    player1.setPlayerGuessCords(0,0);
    testGame.checkAnswer(player1);
    player2.setFootballerGuessName("Cristiano");
    player2.setFootballerGuessSurname("Ronaldo");
    player2.setPlayerGuessCords(1,0);
    testGame.checkAnswer(player2);
    player1.setFootballerGuessName("Cristiano");
    player1.setFootballerGuessSurname("Ronaldo");
    player1.setPlayerGuessCords(2,0);
    testGame.checkAnswer(player1);
    player1.setFootballerGuessName("Lionel");
    player1.setFootballerGuessSurname("Messi");
    player1.setPlayerGuessCords(0,1);
    testGame.checkAnswer(player1);
    player1.setFootballerGuessName("Lionel");
    player1.setFootballerGuessSurname("Messi");
    player1.setPlayerGuessCords(1,1);
    testGame.checkAnswer(player1);
    testGame.checkAnswer(player2);
    player2.setFootballerGuessName("Sergio");
    player2.setFootballerGuessSurname("Ramos");
    player2.setPlayerGuessCords(2,2);
    testGame.checkAnswer(player2);
    player2.setFootballerGuessName("Lionel");
    player2.setFootballerGuessSurname("Messi");
    player2.setPlayerGuessCords(2,1);
    testGame.checkAnswer(player2);
    player2.setFootballerGuessName("Lionel");
    player2.setFootballerGuessSurname("Messi");
    testGame.checkAnswer(player2);
    player2.setPlayerGuessCords(0,2);
    player1.setFootballerGuessName("Lionel");
    player1.setFootballerGuessSurname("Messi");
    player1.setPlayerGuessCords(2,1);
    testGame.checkAnswer(player1);
    player2.setFootballerGuessName("Lionel");
    player2.setFootballerGuessSurname("Messi");
    player2.setPlayerGuessCords(0,2);
    testGame.checkAnswer(player2);
    player1.setFootballerGuessName("Lionel");
    player1.setFootballerGuessSurname("Messi");
    player1.setPlayerGuessCords(1,2);
    testGame.checkAnswer(player1);
    ASSERT_TRUE(testGame.isGameTied(player1, player2));
}

TEST(winningCombinations, NoWinningCombination) {
    gamelogic::game testGame(dbpath);
    gamelogic::Player player("Player1", 'X');
    testGame.setParams("Real_Madrid", "Barcelona", "PSG", "BD", "CL", "Portugal");
    // Making moves without a winning combination
    player.setFootballerGuessName("Cristiano");
    player.setFootballerGuessSurname("Ronaldo");
    player.setPlayerGuessCords(0,0);
    testGame.checkAnswer(player);
    testGame.checkAnswer(player);
    ASSERT_FALSE(testGame.winningCombinations(player.getSymbol()));
}

TEST(winningCombinations, WinningCombination) {
    gamelogic::game testGame(dbpath);
    gamelogic::Player player("Player1", 'X');
    testGame.setParams("Real_Madrid", "Barcelona", "PSG", "BD", "CL", "Portugal");
    // Making moves with a winning combination
    player.setFootballerGuessName("Cristiano");
    player.setFootballerGuessSurname("Ronaldo");
    player.setPlayerGuessCords(0,0);
    testGame.checkAnswer(player);
    player.setPlayerGuessCords(1,0);
    testGame.checkAnswer(player);
    player.setPlayerGuessCords(2,0);
    testGame.checkAnswer(player);
    ASSERT_TRUE(testGame.winningCombinations(player.getSymbol()));
}

