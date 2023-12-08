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

class communication {
public:
    // Constructor
    communication(int clientSocket);
    // Method to send messages
    void sendMessage(std::string message);
    // Method to receive messages
    std::string receiveMessage();
    // Method to close connection
    void closeConnection();

    // Overloading the == operator as a member function
    bool operator==(const communication& other) const;

private:
    int clientSocket;
};



#endif //SERVER_COMMUNICATION_H
