//
// Created by bruno on 24-11-2023.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <thread>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <stdexcept>
#include "communication.h"

const int MAX_CLIENTS = 2;
const int MAX_MESSAGE_SIZE = 1024;

class Server {
public:
    Server(int port);
    ~Server();
    void start();
    std::array<int, MAX_CLIENTS>&  getClientSockets();
private:
    int serverSocket;
    int port;
    std::array<int, MAX_CLIENTS> clientSockets;
    bool initializeServer();
    bool bindServer();
    bool listenForClients();
    void acceptClients();
};

#endif //SERVER_SERVER_H
