//
// Created by bruno on 17-11-2023.
//

#include <sstream>
#include "gameRunner.h"
#include "../communication/server.h"
#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <ctime>


void gameRunner::runCMD() {
    startGame();
    game.print();

    int x = -1;
    int y = -1;
    std::string name;
    std::string surname;
    while (running) {
        // player 1 plays
        std::cout << "Player 1 turn :\n";
        x = getIntCMD("x");
        y = getIntCMD("y");
        player1.setPlayerGuessCords(x, y);
        std::cout << "Name :";
        std::cin >> name;
        std::cout << "Surname :";
        std::cin >> surname;
        player1.setFootballerGuessName(name);
        player1.setFootballerGuessSurname(surname);

        // check player 1 answer
        if (!game.checkAnswer(player1)) {
            std::cout << "Incorrect\n";
        }
        game.print();

        // check if player 1 wins
        if (game.isGameWonByPlayer(player1)) {
            std::cout << "Player 1 wins\n";
            break;
        }

        // check if game is tied
        if (game.isGameTied(player1, player2)) {
            std::cout << "Tied\n";
            break;
        }

        // player 2 plays
        std::cout << "Player 2 turn :\n";
        x = getIntCMD("x");
        y = getIntCMD("y");
        player2.setPlayerGuessCords(x, y);
        std::cout << "Name :";
        std::cin >> name;
        std::cout << "Surname :";
        std::cin >> surname;
        player2.setFootballerGuessName(name);
        player2.setFootballerGuessSurname(surname);

        // check player 2 answer
        if (!game.checkAnswer(player2)) {
            std::cout << "Incorrect\n";
        }
        game.print();

        // check if player 2 wins
        if (game.isGameWonByPlayer(player2)) {
            std::cout << "Player 2 wins\n";
            break;
        }

        // check if game is tied
        if (game.isGameTied(player1, player2)) {
            std::cout << "Tied\n";
            break;
        }
    }
    endGame();
}

void gameRunner::startGame() {
    this->running = true;
    player1.setSymbol('o');
    player2.setSymbol('x');
    setGamePin();

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // TODO: Randomize teams and cups
    // Important to follow name struct "WC" , "CL", "BD", "E" for trophies
    // Important to follow teams and Nation struct --> example : Real_Madrid
    int caseNumber ;
    bool found = true;


    while (found){
         caseNumber = std::rand() % 10 + 1;
         found = false;

        for (int i = 0; i < prevGame.size(); ++i) {
            if (prevGame[i] == caseNumber){
                found = true;
                break;
            }
        }

        if (!found)
            prevGame.push_back(caseNumber);
    }
    
    switch(caseNumber) {
        case 1:
            game.setParams("Real_Madrid", "Manchester_City", "PSG", "Argentina", "CL", "Portugal");
            break;
        case 2:
            game.setParams("AC_Milan", "WC", "Benfica", "Brazil", "Barcelona", "Inter");
            break;
        case 3:
            game.setParams("England", "EC", "Spain", "Manchester_United", "Real_Madrid", "Chelsea");
            break;
        case 4:
            game.setParams("Sporting", "Bayern", "Dortmund", "CL", "Portugal", "Barcelona");
            break;
        case 5:
            game.setParams("Atletico_Madrid", "BD", "PSG", "France", "Chelsea", "Brazil");
            break;
        case 6:
            game.setParams("Juventus", "Tottenham", "Italy", "Inter", "WC", "AC_Milan");
            break;
        case 7:
            game.setParams("Liverpool", "France", "Bayern", "WC", "Arsenal", "Real_Madrid");
            break;
        case 8:
            game.setParams("Manchester_City", "Porto", "Chelsea", "Argentina", "CL", "Juventus");
            break;
        case 9:
            game.setParams("Belgium", "EC", "Manchester_United", "Chelsea", "Atletico_Madrid", "Inter");
            break;
        case 10:
            game.setParams("Arsenal", "Manchester_City", "CL", "Norway", "England", "Dortmund");
            break;
        default:
            std::cout << "Invalid board!";
    }

}

bool gameRunner::isGameInProgress() {
    return this->running;
}

void gameRunner::endGame(){
    running = false;
}

void gameRunner::runRemote() {
    // Create a Server
    Server gameServer(std::stoi(argv[2]));
    // Open Server and wait to connect with 2 clients
    gameServer.start();

    // Create communication paths after establishing connection
    communication client1 = gameServer.acceptClient();
    // Send Game Pin Here
    client1.sendMessage("Host");
    client1.sendMessage(gamepin);

    communication client2 = gameServer.acceptClient();

    client2.sendMessage("Hosted");
    // accept client 2 pin
    std::string message = client2.receiveMessage();
    while (message != getGamePin()) {
        std::cout << "Incorrect pin :" << message << std::endl;
        client2.sendMessage("Incorrect");
        message = client2.receiveMessage();
    }

    // Connection Established
    client2.sendMessage("Correct");
    std::cout << "Clients are both connected\n";

    // Exchange names
    exchangeNames(client1, client2);
    std::cout << "Client1 name is: " + player1.getPlayerName() << std::endl;
    std::cout << "Client2 name is: " + player2.getPlayerName() << std::endl;

    Server chatServer(std::stoi(argv[2]) + 1);
    chatServer.start();
    communication chat1 = chatServer.acceptClient();
    communication chat2 = chatServer.acceptClient();

    std::thread gameThread(&gameRunner::gameThread, this, client1, client2);
    std::thread chat1Thread(&gameRunner::chatThread, this, chat1, chat2);
    std::thread chat2Thread(&gameRunner::chatThread, this, chat2, chat1);

    gameThread.join();
    chat1Thread.join();
    chat2Thread.join();

    chat1.closeConnection();
    chat2.closeConnection();
    client1.closeConnection();
    client2.closeConnection();
    gameServer.closeServer();
    chatServer.closeServer();
}

void gameRunner::exchangeNames(communication client1, communication client2) {

    //Request for names
    client2.sendMessage("Name");
    std::string client2Name = client2.receiveMessage();

    client1.sendMessage("Name");
    std::string client1Name = client1.receiveMessage();

    player1.setPlayerName(client1Name);
    player2.setPlayerName(client2Name);
    client1.sendMessage(client2Name);
    client2.sendMessage(client1Name);
}

void gameRunner::sendParams(communication client1, communication client2) {

    // Send params to the clients
    std::string packet;
    std::vector<std::string> params_vec = game.getParams();
    for (auto &p: params_vec) {
        packet.append(p + "-");
    }
    //Broadcast to clients
    client1.sendMessage(packet);
    client2.sendMessage(packet);
}

std::vector<std::string> gameRunner::getPlay(communication client) {
    // Received message contains 3 things
    // 1 - x board location
    // 2 - y board location
    // 3 - footballer guess name
    // 4 - footballer guess surname
    client.sendMessage("YourTurn");
    std::string playPacket = client.receiveMessage();
    std::istringstream ss(playPacket);
    // Vector to store the separated strings
    std::vector<std::string> tokens;
    std::string token;

    // Use getline with '-' as the delimiter
    while (std::getline(ss, token, '-')) {
        tokens.push_back(token);
    }
    return tokens;
}

int gameRunner::getIntCMD(std::string name) {
    std::cout << name + " :";
    int userInput;

    // Check if input is a valid integer within the specified range
    while (!(std::cin >> userInput) || userInput < 0 || userInput > 2) {
        // Clear input buffer in case of invalid input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Invalid input..." << std::endl<<  name + " :";
    }

    // Return the valid integer
    return userInput;
}

void gameRunner::setGamePin() {
    gamepin = randomString();
}

std::string gameRunner::getGamePin() {
    return this->gamepin;
}

std::string gameRunner::randomString() {
    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::string random_string;
    std::srand(std::time(0));

    for (int i = 0; i < 5; i++) {
        random_string += CHARACTERS[std::rand() % CHARACTERS.size()];
    }

    return random_string;
}

gameRunner::gameRunner() {

}

gameRunner::gameRunner(int argc, char **argv) {
    this->argc = argc;
    this->argv = argv;
}

void gameRunner::gameCycle(communication client1, communication client2) {

    // Generate new Params
    startGame();

    //Send board params
    sendParams(client1, client2);

    // Start Game
    while (true) {
        std::vector<std::string> packet;
        // Ask player 1 to play
        packet = getPlay(client1);
        player1.setPlayerGuessCords(std::stoi(packet[0]), std::stoi(packet[1]));
        player1.setFootballerGuessName(packet[2]);
        player1.setFootballerGuessSurname(packet[3]);
        // Check guess
        if (game.checkAnswer(player1)) {
            // Correct send response
            client1.sendMessage("Correct");
            client2.sendMessage("OpponentPlay");
            client2.sendMessage(packet[0] + "-" + packet[1] + "-" + packet[2] +
                                "-" + packet[3]);
        } else {
            // Incorrect send response
            client1.sendMessage("Incorrect");
        }

        // Check winner for player 1
        if (game.isGameWonByPlayer(player1)){
            client1.sendMessage("Winner");
            client2.sendMessage("Loser");
            std::cout << player1.getPlayerName() << " Wins round\n";
            player1.increaseScore();
            game.erasePreviousGame();
            break;
        }

        // Check tie
        if (game.isGameTied(player1, player2)){
            client1.sendMessage("Tie");
            client2.sendMessage("Tie");
            game.erasePreviousGame();
            break;
        }

        // Ask player 2 to play
        packet = getPlay(client2);
        player2.setPlayerGuessCords(std::stoi(packet[0]), std::stoi(packet[1]));
        player2.setFootballerGuessName(packet[2]);
        player2.setFootballerGuessSurname(packet[3]);

        // Check guess
        if (game.checkAnswer(player2)) {
            // Correct send response
            client2.sendMessage("Correct");
            client1.sendMessage("OpponentPlay");
            client1.sendMessage(packet[0] + "-" + packet[1] + "-" + packet[2] +
                                "-" + packet[3]);
        } else {
            // Incorrect send response
            client2.sendMessage("Incorrect");
        }

        // Check winner for player 2
        if (game.isGameWonByPlayer(player2)){
            client2.sendMessage("Winner");
            client1.sendMessage("Loser");
            std::cout << player2.getPlayerName() << " Wins round\n";
            player2.increaseScore();
            game.erasePreviousGame();
            break;
        }

        // Check tie
        if (game.isGameTied(player1, player2)){
            client1.sendMessage("Tie");
            client2.sendMessage("Tie");
            std::cout << "Tied round\n";
            game.erasePreviousGame();
            break;
        }

    }

}

void gameRunner::chatThread(communication chat1, communication chat2) {

    while (true){
        std::string message;
        message = chat1.receiveMessage();
        if (message == "Close")
            break;
        chat2.sendMessage(message);
    }
}

void gameRunner::gameThread(communication client1, communication client2) {

    while(true){
        gameCycle(client1, client2);

        // Game ended
        if(player1.getScore() == 2){
            std::cout << player1.getPlayerName() <<  " Wins the game\n";
            break;
        }

        if(player2.getScore() == 2){
            std::cout << player2.getPlayerName() <<  " Wins the game\n";
            break;
        }

    }
}




