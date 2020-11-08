#include <dvr/shell.h>
#include <dvr/client.h>
#include <dvr/defs.h>
#include <dvr/server.h>
#include <dvr/signals.h>
#include <dvr/logger.h>
#include <dvr/connector.h>
#include <dvr/handler.h>

#include <iostream>
#include <thread>

int main(int argc, char ** argv) {

    ShellCommand userCommand;
    auto chat = new DvrFacade();

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
                chat->handler->handleListConnectionsCommand(chat->clientVector);
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
void facadeInjector(char * p, DvrFacade * chat) {

    chat->server = new Server(p, chat);
    chat->connector = new Connector(chat);
    chat->shell = new Shell();
    chat->clientVector = new ClientVector();
    chat->handler = new Handler(chat);

    std::thread([&] {
        chat->handler->maintainConnectedClientList(chat->clientVector);
    }).detach();
}



