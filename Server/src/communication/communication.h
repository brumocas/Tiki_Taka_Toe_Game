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
    void sendMessage(std::string message);
    std::string receiveMessage();
    void addHeader(std::string header ,std::string message);
    std::string extractHeader(std::string message);
    void closeConnection();
    void setPin(std::string pin);
    std::string getPin();

    // Overloading the == operator as a member function
    bool operator==(const Communication& other) const;

private:
    int clientSocket;
    std::string pin;
};



#endif //SERVER_COMMUNICATION_H
