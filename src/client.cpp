#include <chat/client.h>
#include <chat/logger.h>
#include <chat/server.h>
#include <chat/signals.h>

#include <csignal>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

Client::Client(Server *server, int socketFd) {
    this->socketFd = socketFd;
    this->server = server;
    Logger::info("New client established at socket file descriptor: "
        + std::to_string(socketFd));
}

void Client::mainConnectionLoop() {
    char buffer[4096] = {'\0'};

    while (recv(socketFd, buffer, sizeof(buffer), 0) != -1
           && !server->getSignalHandler()->trappedSignal(SIGPIPE) && strlen(buffer)) {

        Logger::info("Received message from client: " + std::string(buffer));
    }
    close(socketFd);
}
