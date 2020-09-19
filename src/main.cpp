#include <chat/shell.h>
#include <chat/defs.h>
#include <chat/server.h>

#include <iostream>

int main(int argc, char ** argv) {
    ShellCommand userCommand;

    /* Parse the port parameter */
    if (argc != 2) {
        std::cout << ERR_INVALID_ARGS << std::endl;
        std::exit(-1);
    }

    /* Start a listener */
    auto server = new Server(argv[1]);

    /* Launch the Shell UI */
    auto shellUi = new Shell();

    /* Respond to user input */
    while ((userCommand = shellUi->getUserCommand()) != ShellCommand::QuitProgram) {
        switch (userCommand) {
            case ShellCommand::Help:
                shellUi->printHelpPage();
                break;
            case Shell::GetIp:
                std::cout << getIpAddress() << std::endl;
                break;
            case Shell::GetPort:
                std::cout << server->getListeningPort() << std::endl;
                break;
            case Shell::Connect:
                break;
            case Shell::ListConnections:
                break;
            case Shell::TerminateConnection:
                break;
            case Shell::SendMessage:
                break;
            case Shell::InvalidCommand:
                std::cout << "Invalid command \"" << shellUi->getLastUserInput() << "\"" << std::endl;
            case Shell::EmptyCommand:
            default:
                break;
        }
    }
    return 0;
}

