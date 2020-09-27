#include <chat/handler.h>
#include <chat/logger.h>
#include <chat/server.h>
#include <chat/client.h>
#include <chat/connector.h>

#include <iostream>
#include <chrono>
#include <thread>


/**
 * Used a helper class against the main shell loop that receives user input.
 * Switch in main.cpp calls functions from this class, and abstracts away the details
 * of each response to user entered commands
 *
 * @param chat - Facade with all class dependencies of the project
 */
Handler::Handler(ChatFacade *chat) {
    this->chat = chat;
}

/**
 * Calls utility function getIpAddress and prints IPv4
 */
void Handler::handleGetIpCommand() {
    Logger::info("Got myip command");
    std::cout << getIpAddress() << std::endl;
}

/**
 * Prints the port passed as an initial argument for server component to listen on
 */
void Handler::handleGetPortCommand() {
    Logger::info("Got myport command");
    std::cout << chat->server->getListeningPort() << std::endl;
}

/**
 * Prints the help page
 */
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
void Handler::handleConnectCommand() {
    std::vector<std::string> tokens = splitString(std::move(chat->shell->getLastUserInput()), " ");

    /* Check for connect command arguments - Needs exactly 3 */
    if (tokens.size() != 3) {
        std::cout << "Invalid # of arguments for `connect` command. "
                  << "Usage: connect <destinaton> <port no>"
                  << std::endl;
        Logger::debug("Size of tokens: " + std::to_string(tokens.size()));
        return;
    }

    /* Use the connector class to connect to the specified client */
    if (!chat->connector->connectToClient(tokens[1], tokens[2])) {
        Logger::error(chat->connector->getFailureReason());
        std::cout << chat->connector->getFailureReason();

        return;
    }

    std::cout << "Successfully made connection to " << tokens[1]
              << " on port " << tokens[2] << std::endl;
}

/**
 * Uses the client list to call on Client class functionality to send a message
 * to the client specified by the index argument.
 */
void Handler::handleSendCommand() {
    Logger::info("Got send command");
    std::vector<std::string> tokens = splitString(std::move(chat->shell->getLastUserInput()), " ");


    /* Check for send command arguments - Needs exactly 3 */
    if (tokens.size() < 3) {
        std::cout << "Invalid # of arguments for `send` command. "
                  << "Usage: send <connection id> <message>"
                  << std::endl;
        Logger::debug("Size of tokens: " + std::to_string(tokens.size()));
        return;
    }

    /* Collapse all the tokens after the 'message' parameter to be one single string message
     * to be sent to the requested client */
    std::string msg = collapseTokens(tokens, 2, tokens.size());
    try {

        /* Try to fire a message to the client at the specified index - List command
         * indexes clients starting at 1.. so subtract 1 when indexing into clientVector */
        int clientIndex = std::stoi(tokens[1]);
        if (clientIndex > 0 && clientIndex <= chat->clientVector->size()) {
            chat->clientVector->at(clientIndex-1)->sendMessage(msg);
        }
    }
    catch (std::exception &e) {
        Logger::error(msg = ("Could not send message with exception: " + std::string(e.what())));
        std::cout << msg << std::endl << USER_PROMPT;
    }

}

/**
 * Response function for invalid commands entered at the shell prompt
 */
void Handler::handleInvalidCommand() {
    Logger::info("Got invalid command");
    std::cout << "Invalid command \"" << chat->shell->getLastUserInput() << "\"" << std::endl;
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


