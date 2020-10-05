#include <chat/defs.h>
#include <chat/connector.h>
#include <chat/client.h>
#include <chat/logger.h>

#include <arpa/inet.h>
#include <utility>

Connector::Connector(ChatFacade *chat) {
    this->chat = chat;
}


/**
 * Main outgoing client connection function. Validates address/port combo, and formats them
 * into a suitable format for the connect() function.
 *
 * @param address - IPv4 address to connect to
 * @param port - Outgoing port
 * @return
 */
bool Connector::connectToClient(const std::string& address, const std::string& port) {

    struct sockaddr_in destination;
    int outgoingSocket, outgoingPort;

    /* Get port integer from port string */
    if (!(outgoingPort = validateConnectionParameters(std::move(address), std::move(port),
            &destination))) {
        setFailureReason("Could not validate connection parameters " + address + "and " + port);
        return false;
    }

    /* Create a new socket */
    if ((outgoingSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        setFailureReason("Could not create new socket!");
        return false;
    }

    /* Assign the port integer to the destination struct used by connect() */
    destination.sin_family = AF_INET;
    destination.sin_port = htons(outgoingPort);

    /* Validate the IPv4 address and set to destination struct */
    if (inet_pton(AF_INET, address.c_str(), &destination.sin_addr)<=0) {
        setFailureReason("Invalid address: " + address);
        return false;
    }

    Logger::debug ("About to connect to address: " + address + " on port: " + port);

    /* Send connect() to destination struct using socket created above */
    if (connect(outgoingSocket, (struct sockaddr *)&destination, sizeof(destination)) < 0) {
        setFailureReason("Could not connect to destination!");
        return false;
    }

    /* On successful connection, add client to connect clients list */
    chat->clientVector->emplace_back(
            new Client(chat->server, outgoingSocket, outgoingPort));

    /* Transmit client IPv4 */
    chat->clientVector->at(chat->clientVector->size()-1)->sendMessage(std::string((char *)IP_RECV) + getIpAddress());

    return true;
}


/**
 * Validates address and port combo. Returns the port number string as an integer
 * @param address
 * @param port
 * @param s
 * @return
 */
int Connector::validateConnectionParameters(const std::string& address, const std::string& port,
        struct sockaddr_in * s) {

    if (inet_pton(AF_INET, address.c_str(), &s->sin_addr) <= 0) {
        setFailureReason("Invalid address!");
        return 0;
    }

    try {
        return std::stoi(port);
    }
    catch (std::exception &e) {
        setFailureReason("Invalid port number!");
        return 0;
    }

}
