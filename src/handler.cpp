#include <chat/handler.h>
#include <chat/logger.h>
#include <chat/server.h>
#include <chat/client.h>
#include <chat/connector.h>

#include <iostream>
#include <chrono>
#include <thread>

Handler::Handler(ChatFacade *chat) {
    this->chat = chat;
}


void Handler::handleGetIpCommand() {
    Logger::info("Got myip command");
    std::cout << getIpAddress() << std::endl;
}


void Handler::handleGetPortCommand() {
    Logger::info("Got myport command");
    std::cout << chat->server->getListeningPort() << std::endl;
}


void Handler::handleHelpCommand() {
    Logger::info("Got help command");
    chat->shell->printHelpPage();
}


/**
 * Handler for the `connect` command. Parses user input and forms the address/port
 * combo to send to the Connector class.
 *
 * @param chat - Chat Facade including the Connector class
 * @param userInput - The full command string entered by the user
 */
void Handler::handleConnectCommand(ChatFacade * chat, std::string userInput) {
    std::vector<std::string> tokens = splitString(std::move(userInput), " ");

    if (tokens.size() != 3) {
        std::cout << "Invalid # of arguments for `connect` command. "
                  << "Usage: connect <destinaton> <port no>"
                  << std::endl;
        Logger::debug("Size of tokens: " + std::to_string(tokens.size()));
        return;
    }

    if (!chat->connector->connectToClient(tokens[1], tokens[2])) {
        Logger::error(chat->connector->getFailureReason());
        std::cout << chat->connector->getFailureReason();

        return;
    }
    std::cout << "Successfully made connection to " << tokens[1]
              << " on port " << tokens[2] << std::endl << USER_PROMPT;
}


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
/**
 * Pruning function to scan the connected client list and remove
 * clients that have disconnected.
 *
 * @param connectedClients - Client Vector pointer holding all currently
 * connected clients
 */
void Handler::maintainConnectedClientList(ClientVector * connectedClients) {
    while (true)  {
        for (auto it = connectedClients->begin(); it != connectedClients->end(); ){
            if (!(*it)->isAlive()) {
                Logger::info("Pruned client at " + (*it)->getClientIpAddress() + " on port "
                             + std::to_string((*it)->getClientBindPort()));
                it = connectedClients->erase(it);
            }
            else {
                it++;
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
#pragma clang diagnostic pop


