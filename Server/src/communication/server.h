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
    // Constructor
    Server(int port);
    // Start Server
    void start();
    // Accept Clients connections
    int acceptClient();
    // Close Server Socket
    void closeServer();

private:
    int serverSocket;
    int port;
    // Initialize Server
    bool initializeServer();
    // Bind Server to the given port
    bool bindServer();
    // Listen for clients connection
    bool listenForClients();
    // Print Server information
    void printServerInfo() const;


};

#endif //SERVER_SERVER_H
