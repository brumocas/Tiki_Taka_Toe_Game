//
// Created by bruno on 24-11-2023.
//

#include "server.h"


Server::Server(int port) : serverSocket(-1), port(port) {}

void Server::start() {
    try {
        if (initializeServer() && bindServer() && listenForClients()) {
            printServerInfo();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

bool Server::initializeServer() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Socket creation failed");
        return false;
    }
    return true;
}

bool Server::bindServer() {
    sockaddr_in serverAddr{};
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);


    if (bind(serverSocket, reinterpret_cast<struct sockaddr *>(&serverAddr), sizeof(serverAddr)) == -1) {
        perror("Binding failed");
        return false;
    }
    return true;
}

bool Server::listenForClients() {
    if (listen(serverSocket, MAX_CLIENTS) == -1) {
        perror("Listening failed");
        return false;
    }
    return true;
}

int Server::acceptClient() {
    sockaddr_in client1Addr{};
    socklen_t client1AddrLen = sizeof(client1Addr);

    int client1Socket = accept(serverSocket, reinterpret_cast<struct sockaddr *>(&client1Addr), &client1AddrLen);
    if (client1Socket == -1) {
        perror("Acceptance failed");
        throw std::runtime_error("Failed to accept client ");
    }
    std::cout << "Client connected from " << inet_ntoa(client1Addr.sin_addr) << ":"
              << ntohs(client1Addr.sin_port) << std::endl;

    return client1Socket;
}

void Server::printServerInfo() const {
    sockaddr_in serverAddr{};
    socklen_t addrLen = sizeof(serverAddr);
    if (getsockname(serverSocket, reinterpret_cast<struct sockaddr*>(&serverAddr), &addrLen) == 0) {
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(serverAddr.sin_addr), ip, INET_ADDRSTRLEN);
        std::cout << "Server is listening on IP: " << ip << ", Port: " << port << std::endl;
    } else {
        perror("Error getting server address");
    }
}

void Server::closeServer() {
    close(serverSocket);
}




