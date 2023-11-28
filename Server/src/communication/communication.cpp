//
// Created by bruco on 11/10/2023.
//

#include "communication.h"

Communication::Communication(int clientSocket) : clientSocket(clientSocket) {

}

void Communication::sendMessage(std::string message) {
    std::string messageWithNewline = message.append("\n");
    size_t bytes = 0;
    if ((bytes = send(clientSocket, messageWithNewline.c_str(), messageWithNewline.length(), 0)) <= 0) {
        perror("Failed to send message");
    }
}

std::string Communication::receiveMessage() {
    char buffer[1024] = {0};
    ssize_t bytes = recv(clientSocket, buffer, 1024, 0);
    if (bytes <= 0) {
        perror("Failed to read message");
        return "";
    }
    buffer[bytes - 1] = '\0';
    return std::string(buffer, bytes - 1);
}

void Communication::closeConnection() {
    close(clientSocket);
}

void Communication::addHeader(std::string header,std::string message) {
}

std::string Communication::extractHeader(std::string message) {
    return std::string();
}

// Definition of the == operator as a member function
bool Communication::operator==(const Communication& other) const {
    // Compare based on the equality of clientSocket values
    return this->clientSocket == other.clientSocket;
}