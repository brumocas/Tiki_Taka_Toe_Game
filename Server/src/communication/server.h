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

class Server {
public:
    Server(int port);
    void start();
    int acceptClient();
private:
    int serverSocket;
    int port;
    bool initializeServer();
    bool bindServer();
    bool listenForClients();
    void printServerInfo() const;
};

#endif //SERVER_SERVER_H
