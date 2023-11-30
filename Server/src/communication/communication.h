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


const int MAX_MESSAGE_SIZE = 1024;

class Communication {
public:
    Communication(int clientSocket);
    void sendMessage(std::string message);
    std::string receiveMessage();
    void closeConnection();

    // Overloading the == operator as a member function
    bool operator==(const Communication& other) const;

private:
    int clientSocket;
    std::string pin;
};



#endif //SERVER_COMMUNICATION_H
