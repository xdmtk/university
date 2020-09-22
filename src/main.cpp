#include <chat/shell.h>
#include <chat/client.h>
#include <chat/defs.h>
#include <chat/server.h>
#include <chat/signals.h>
#include <chat/logger.h>
#include <chat/connector.h>

#include <iostream>
#include <chrono>
#include <thread>
#include <utility>

int main(int argc, char ** argv) {

    ShellCommand userCommand;
    auto chat = new ChatFacade();

    /* Parse the port parameter */
    if (argc != 2) {
        std::cout << ERR_INVALID_ARGS << std::endl;
        std::exit(-1);
    }

    facadeInjector(argv[1], chat);


    /* Respond to user input */
    while ((userCommand = chat->shell->getUserCommand()) != ShellCommand::QuitProgram) {
        switch (userCommand) {
            case ShellCommand::Help:
                Logger::info("Got help command");
                chat->shell->printHelpPage();
                break;
            case Shell::GetIp:
                Logger::info("Got myip command");
                std::cout << getIpAddress() << std::endl;
                break;
            case Shell::GetPort:
                Logger::info("Got myport command");
                std::cout << chat->server->getListeningPort() << std::endl;
                break;
            case Shell::Connect:
                Logger::info("Got connect command");
                handleConnectCommand(chat, chat->shell->getLastUserInput());
                break;
            case Shell::ListConnections:
                Logger::info("Got list command");
                break;
            case Shell::TerminateConnection:
                Logger::info("Got terminate command");
                break;
            case Shell::SendMessage:
                Logger::info("Got send command");
                break;
            case Shell::InvalidCommand:
                Logger::info("Got invalid command");
                std::cout << "Invalid command \"" << chat->shell->getLastUserInput() << "\"" << std::endl;
            case Shell::EmptyCommand:
            default:
                break;
        }
    }
    return 0;
}


/**
 * Helper function to manage class dependencies. Also sets in motion the client
 * list pruning function on a separate thread.
 *
 * @param p - Port number for server to listen on
 * @param s - Shell pointer
 * @param si - Signals pointer
 * @param se - Server pointer
 * @param c - Connected Client List pointer
 */
void facadeInjector(char * p, ChatFacade * chat) {

    chat->server = new Server(p, chat);
    chat->connector = new Connector(chat);
    chat->shell = new Shell();
    chat->clientVector = new ClientVector();
    std::thread([&] {
        maintainConnectedClientList(chat->clientVector);
    }).detach();
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
void maintainConnectedClientList(ClientVector * connectedClients) {
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


void handleConnectCommand(ChatFacade * chat, std::string userInput) {
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
    std::cout << "Sucessfully made connection to " << tokens[1]
        << " on port " << tokens[2];
}



