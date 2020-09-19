#include <chat/server.h>
#include <chat/logger.h>
#include <chat/client.h>
#include <chat/defs.h>

#include <thread>
#include <algorithm>
#include <cstring>
#include <cerrno>
#include <netinet/in.h>
#include <sys/socket.h>


/**
 * Constructor for the Server class. Serves as the connector for incoming
 * socket connections. Adds incoming clients to the provided ClientVector
 * by the caller and triggers the main send/receive loop for each Client.
 *
 * @param portArg - Port to listen on
 * @param connectedClientList - Vector of Client objects for incoming/outgoing
 * connections
 */
Server::Server(char *portArg, ClientVector * connectedClientList) {

    try {
        bindPort = std::stoi(portArg);
    }
    catch (std::exception &e) {
        Logger::fatal(e.what());
        std::exit(-1);
    }
    std::thread([&] {
        listenForClientConnections();
    }).detach();
}

/**
 * Master function to setup listener socket and accept incoming
 * client connections.
 */
void Server::listenForClientConnections() {

    int bindSocket, incomingSocket, optionValue;
    struct sockaddr_in address;

    setupSocket(&bindSocket, &optionValue, &address);

    /* On new client connection, get the socket fd, and detach a thread dedicated to communicating
     * with the client */
    while ((incomingSocket = accept(bindSocket,NULL,NULL))) {

        Logger::info("Got new connection on socket fd: " + std::to_string(incomingSocket));

        // If accept() returns negative, errno is set. Print the error
        if (incomingSocket < 0) {
            Logger::error("Socket fd returned is negative! Errno:" + std::string(strerror(errno)));
            continue;
        }
        std::thread([&] {
            // Push the client onto the connectedClientList and begin send/receive loop
            connectedClientList->emplace_back(new Client(this, incomingSocket, bindPort));
            connectedClientList->back()->mainConnectionLoop();
        }).detach();
    }
}


/**
 * Gets the socket file descriptor and calls setsockopt for
 * ipv4 options
 * @param bindSocket - Socket file descriptor
 * @param optionValue -
 */
void Server::setupSocket(int *bindSocket, int *optionValue, struct sockaddr_in *address) {

    /* Produce a file descriptor for the listener socket */
    if ((*bindSocket = socket(AF_INET, SOCK_STREAM, 0)) <= 0) {
        Logger::fatal("Could not generate socket file descriptor! "
                      + (errno ? "Errno: " + std::string(strerror(errno)) : ""));
    }

    if (setsockopt(*bindSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &(*optionValue = 1), sizeof(*optionValue))) {
        Logger::fatal("Could not set socket options on socket! "
                      + (errno ? "Errno: " + std::string(strerror(errno)) : ""));

    }
    setAddressOptions(address);
    bindAndListen(bindSocket, address);
}

/**
 * Operates on the sockaddr_in structure to set IPV4 address binding
 * and allows the call to bind to utilize all potential IP address of the host
 *
 * @param address - Pointer to structure containing address/port data
 */
void Server::setAddressOptions(struct sockaddr_in * address) {

    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(bindPort);
}

/**
 * Wrapper around bind() and listen() against the socket file descriptor
 *
 * @param bindSocket - Socket file descriptor
 * @param address - Address structure
 */
void Server::bindAndListen(int * bindSocket, struct sockaddr_in * address) {

    if (bind(*bindSocket, reinterpret_cast<struct sockaddr *>(address), sizeof(*address)) < 0) {
        Logger::fatal("Could not bind to port " + std::to_string(address->sin_port) + "! "
                      + (errno ? "Errno: " + std::string(strerror(errno)) : ""));
    }
    if (listen(*bindSocket, connectionBacklogMaxLimit) < 0) {
        Logger::fatal("Call to listen() failed! " + (errno ? "Errno: " + std::string(strerror(errno)) : ""));
    }
    else  {
        Logger::info("Binding to port " + std::to_string(bindPort) + " has been successful. ");
    }

}