//
// Created by bruco on 11/10/2023.
//

#include "communication.h"

Communication::Communication(int clientSocket) : clientSocket(clientSocket) {

}

Communication::~Communication() {
    if (clientSocket != -1) {
        close(clientSocket);
    }
}

void Communication::sendMessage(const std::string &message) {
    if (send(clientSocket, message.c_str(), message.size(), 0) == -1) {
        perror("Failed to send message");
    }
}
std::string Communication::receiveMessage() {
    char buffer[1024] = {0};
    ssize_t valread = read(clientSocket, buffer, 1024);
    if (valread == -1) {
        perror("Failed to read message");
        return "";
    }
    return std::string(buffer, valread);
}

void Communication::closeConnection() {
    close(clientSocket);
}

void Communication::addHeader(std::string header, const std::string &message) {
}

std::string Communication::extractHeader(const std::string &message) {
    return std::string();
}
