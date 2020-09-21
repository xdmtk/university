#include <chat/client.h>
#include <chat/logger.h>
#include <chat/server.h>
#include <chat/shell.h>
#include <chat/signals.h>

#include <iostream>
#include <csignal>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>


/**
 * Constructor for the Client class. Represents a connected client and holds
 * methods to communicate with the client and update state information for
 * that client.
 *
 * @param server - Pointer to the server class
 * @param socketFd - The socket file descriptor connected on
 * @param bindPort - The port number the client is connected on
 */
Client::Client(Server *server, int socketFd, int bindPort) {
    this->socketFd = socketFd;
    this->server = server;
    this->bindPort = bindPort;
    terminated = false;
    Logger::info("New client established at socket file descriptor: "
        + std::to_string(socketFd));
}


/**
 * Main receive loop for the client. Waits for incoming data and prints it to
 * the screen when received. On termination, the `terminated` flag is set and
 * is eventually pruned from the ClientVector.
 */
void Client::mainConnectionLoop() {
    char buffer[4096] = {'\0'};
    std::string msg;

    while (recv(socketFd, buffer, sizeof(buffer), 0) != -1
           && !server->getSignalHandler()->trappedSignal(SIGPIPE) && strlen(buffer)) {

        Logger::info("Received message from client: " + (msg = std::string(buffer)));
        printReceivedMessage(msg);
        memset(buffer, '\0', 4096);
    }
    close(socketFd);
    terminated = true;
}


/**
 * Helper function to print to the console the received message from the
 * client.
 *
 * @param msg - Message received
 */
void Client::printReceivedMessage(const std::string& msg) {
    std::cout << std::endl
    << "Message Received from: "  << ipAddress << std::endl
    << "Senders port: " << bindPort << std::endl
    << "Message: " << msg << std::endl  << std::endl
    << USER_PROMPT;
}
