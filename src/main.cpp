#include <chat/shell.h>
#include <chat/client.h>
#include <chat/defs.h>
#include <chat/server.h>
#include <chat/signals.h>
#include <chat/logger.h>
#include <chat/connector.h>
#include <chat/handler.h>

#include <iostream>
#include <thread>

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
                chat->handler->handleHelpCommand();
                break;
            case Shell::GetIp:
                chat->handler->handleGetIpCommand();
                break;
            case Shell::GetPort:
                chat->handler->handleGetPortCommand();
                break;
            case Shell::Connect:
                Logger::info("Got connect command");
                chat->handler->handleConnectCommand();
                break;
            case Shell::ListConnections:
                Logger::info("Got list command");
                chat->handler->handleListConnectionsCommand();
                break;
            case Shell::TerminateConnection:
                Logger::info("Got terminate command");
                chat->handler->handleTerminateConnectionCommand();
                break;
            case Shell::SendMessage:
                chat->handler->handleSendCommand();
                break;
            case Shell::InvalidCommand:
                chat->handler->handleInvalidCommand();
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
    chat->handler = new Handler(chat);

    std::thread([&] {
        chat->handler->maintainConnectedClientList(chat->clientVector);
    }).detach();
}



