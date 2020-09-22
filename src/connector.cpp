#include <chat/defs.h>
#include <chat/connector.h>
#include <chat/client.h>
#include <chat/logger.h>

#include <arpa/inet.h>
#include <utility>

Connector::Connector(ChatFacade *chat) {
    this->chat = chat;
}

bool Connector::connectToClient(const std::string& address, const std::string& port) {

    struct sockaddr_in destination;
    int outgoingSocket, outgoingPort;

    if (!(outgoingPort = validateConnectionParameters(std::move(address), std::move(port),
            &destination))) {
        setFailureReason("Could not validate connection parameters " + address + "and " + port);
        return false;
    }

    if ((outgoingSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        setFailureReason("Could not create new socket!");
        return false;
    }

    destination.sin_family = AF_INET;
    destination.sin_port = htons(outgoingPort);

    if (inet_pton(AF_INET, address.c_str(), &destination.sin_addr)<=0) {
        setFailureReason("Invalid address: " + address);
        return false;
    }

    Logger::debug ("About to connect to address: " + address + " on port: " + port);

    if (connect(outgoingSocket, (struct sockaddr *)&destination, sizeof(destination)) < 0) {
        setFailureReason("Could not connect to destination!");
        return false;
    }

    chat->clientVector->emplace_back(
            new Client(chat->server, outgoingSocket, outgoingPort));

    return true;
}


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
