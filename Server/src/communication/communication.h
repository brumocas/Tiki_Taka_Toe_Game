//
// Created by bruco on 11/10/2023.
//

#ifndef SERVER_COMMUNICATION_H
#define SERVER_COMMUNICATION_H

#include <cstring>
#include <cstdlib>
#include <thread>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <stdexcept>

class Communication {
public:
    Communication(int clientSocket);
    ~Communication();
    void sendMessage(const std::string& message);
    std::string receiveMessage();
    void addHeader(std::string header ,const std::string& message);
    std::string extractHeader(const std::string& message);
    void closeConnection();
private:
    int clientSocket;
};



#endif //SERVER_COMMUNICATION_H
