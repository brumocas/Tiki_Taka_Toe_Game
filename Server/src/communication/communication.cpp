//
// Created by bruco on 11/10/2023.
//

#include "communication.h"

communication::communication(int clientSocket) : clientSocket(clientSocket) {

}

void communication::sendMessage(std::string message) {
    std::string messageWithNewline = message.append("\n");
    size_t bytes = 0;
    if ((bytes = send(clientSocket, messageWithNewline.c_str(), messageWithNewline.length(), 0)) <= 0) {
        perror("Failed to send message");
    }
    std::cout << messageWithNewline;
}

std::string communication::receiveMessage() {
    char buffer[MAX_MESSAGE_SIZE] = {0};
    ssize_t bytes = recv(clientSocket, buffer, 1024, 0);
    if (bytes <= 0) {
        perror("Failed to read message");
        return "";
    }
    buffer[bytes - 1] = '\0';
    std::cout << std::string(buffer, bytes - 1) << std::endl;
    return std::string(buffer, bytes - 1);
}

void communication::closeConnection() {
    close(clientSocket);
}


// Definition of the == operator as a member function
bool communication::operator==(const communication& other) const {
    // Compare based on the equality of clientSocket values
    return this->clientSocket == other.clientSocket;
}