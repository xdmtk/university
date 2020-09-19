#include <chat/client.h>
#include <chat/logger.h>
#include <chat/server.h>
#include <chat/signals.h>
#include <chat/shell.h>

#include <iostream>
#include <csignal>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

Client::Client(Server *server, int socketFd, int bindPort) {
    this->socketFd = socketFd;
    this->server = server;
    this->bindPort = bindPort;
    terminated = false;
    Logger::info("New client established at socket file descriptor: "
        + std::to_string(socketFd));
}

void Client::mainConnectionLoop() {
    char buffer[4096] = {'\0'};
    std::string msg;

    while (recv(socketFd, buffer, sizeof(buffer), 0) != -1
           && !server->getSignalHandler()->trappedSignal(SIGPIPE) && strlen(buffer)) {

        Logger::info("Received message from client: " + (msg = std::string(buffer)));
        printReceivedMessage(msg);
    }
    close(socketFd);
    terminated = true;
}

void Client::printReceivedMessage(const std::string& msg) {
    std::cout << std::endl
    << "Message Received from: "  << ipAddress << std::endl
    << "Senders port: " << bindPort << std::endl
    << "Message: " << msg << std::endl  << std::endl
    << USER_PROMPT;
}
