//
// Created by bruno on 24-11-2023.
//

#include "server.h"


Server::Server(int port) : serverSocket(-1), port(port) {}

Server::~Server() {
    if (serverSocket != -1) {
        close(serverSocket);
    }
}

void Server::start() {
    try {
        if (initializeServer() && bindServer() && listenForClients()) {
            std::cout << "Server is listening on port " << port << "...\n";
            acceptClients();
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

void Server::acceptClients() {
    sockaddr_in client1Addr{};
    socklen_t client1AddrLen = sizeof(client1Addr);

    sockaddr_in client2Addr{};
    socklen_t client2AddrLen = sizeof(client2Addr);

    int client1Socket = accept(serverSocket, reinterpret_cast<struct sockaddr *>(&client1Addr), &client1AddrLen);
    if (client1Socket == -1) {
        perror("Acceptance failed");
        throw std::runtime_error("Failed to accept client 1");
    }
    std::cout << "Client 1 connected from " << inet_ntoa(client1Addr.sin_addr) << ":"
              << ntohs(client1Addr.sin_port) << std::endl;
    clientSockets[0] = client1Socket;


    int client2Socket = accept(serverSocket, reinterpret_cast<struct sockaddr *>(&client2Addr), &client2AddrLen);
    if (client2Socket == -1) {
        perror("Acceptance failed");
        throw std::runtime_error("Failed to accept client 2");
    }
    std::cout << "Client 2 connected from " << inet_ntoa(client2Addr.sin_addr) << ":"
              << ntohs(client2Addr.sin_port) << std::endl;
    clientSockets[1] = client2Socket;

}

std::array<int, MAX_CLIENTS> &Server::getClientSockets() {
    return clientSockets;
}

