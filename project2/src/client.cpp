#include <dvr/client.h>
#include <dvr/logger.h>
#include <dvr/server.h>
#include <dvr/signals.h>
#include <dvr/updater.h>

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
Client::Client(Server *server, int socketFd, int bindPort, DvrFacade *dvr) {
    this->socketFd = socketFd;
    this->server = server;
    this->bindPort = bindPort;
    this->dvr = dvr;
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
        dvr->updater->parseIncomingRoutingUpdate(std::string(buffer));
        memset(buffer, '\0', 4096);
    }
    close(socketFd);
    terminated = true;
}


/**
 * Given the socket file descriptor assigned to this Client object, use it to send
 * the given message supplied with `msg`
 *
 * @param msg - Message string to send
 */
void Client::sendMessage(const std::string& msg) {
    Logger::info("About to send message:  `" + msg + "` with size of: " +
        std::to_string(msg.size()));
    send(socketFd, msg.c_str(), msg.size(), 0);
}
