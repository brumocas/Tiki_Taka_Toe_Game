//
// Created by bruno on 17-11-2023.
//

#include "gameRunner.h"
#include "../communication/communication.h"
#include "../communication/server.h"

void gameRunner::runCMD() {
    startGame();
    game.print();

    int x = -1;
    int y = -1;
    std::string name;
    std::string surname;
    while (running){
        // player 1 plays
        std::cout << "Player 1 turn :\n";
        std::cout << "x :";
        std::cin >> x;
        std::cout << "y :";
        std::cin >> y;
        player1.setPlayerGuessCords(x , y);
        std::cout << "Name :";
        std::cin >> name;
        std::cout << "Surname :";
        std::cin >> surname;
        player1.setFootballerGuessName(name);
        player1.setFootballerGuessSurname(surname);

        // check player 1 answer
        if(!game.checkAnswer(player1)){
            std::cout << "Incorrect\n";
        }
        game.print();

        // check if player 1 wins
        if (game.isGameWonByPlayer(player1)) {
            std::cout << "Player 1 wins\n";
            break;
        }

        // check if game is tied
        if (game.isGameTied(player1,player2)){
            std::cout << "Tied\n";
            break;
        }

        // player 2 plays
        std::cout << "Player 2 turn :\n";
        std::cout << "x :";
        std::cin >> x;
        std::cout << "y :";
        std::cin >> y;
        player2.setPlayerGuessCords(x , y);
        std::cout << "Name :";
        std::cin >> name;
        std::cout << "Surname :";
        std::cin >> surname;
        player2.setFootballerGuessName(name);
        player2.setFootballerGuessSurname(surname);

        // check player 2 answer
        if(!game.checkAnswer(player2)){
            std::cout << "Incorrect\n";
        }
        game.print();

        // check if player 2 wins
        if (game.isGameWonByPlayer(player2)) {
            std::cout << "Player 2 wins\n";
            break;
        }

        // check if game is tied
        if (game.isGameTied(player1,player2)){
            std::cout << "Tied\n";
            break;
        }
    }
    running = false;
}

void gameRunner::startGame() {
    this->running = true;
    player1.setSymbol('x');
    player2.setSymbol('o');

    // TODO: Randomize teams and cups
    game.setParams("Real_Madrid", "Barcelona", "PSG", "BD", "CL", "Portugal");
}

bool gameRunner::isGameInProgress() {
    return this->running;
}

void gameRunner::runRemote() {
    // Create a Server
    std::cout << "Remote game session started :)" << std::endl;
    Server gameServer(8080);
    // Open Server and wait to connect with 2 clients
    gameServer.start();

    // Create Communication paths after establishing connection
    std::array<int, MAX_CLIENTS> sockets = gameServer.getClientSockets();
    Communication client1 = sockets[0];
    Communication client2 = sockets[1];

    std::string string;

    while (true){
        // Get Client 1 name
        string = client1.receiveMessage();
        std::cout << string << std::endl;
        // Get Client 2 name

    }


    client1.sendMessage("Hello c1");
    client2.sendMessage("Hello c2");


    client1.closeConnection();
    client2.closeConnection();

}


