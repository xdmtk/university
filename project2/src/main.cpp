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
    auto dvr = new DvrFacade();

    /* Verify topology/update interval parameters */
    if (argc != 5) {
        std::cout << ERR_INVALID_ARGS << std::endl;
        std::exit(-1);
    }

    facadeInjector(argv[1], dvr);


    /* Respond to user input */
    while ((userCommand = dvr->shell->getUserCommand()) != ShellCommand::QuitProgram) {
        switch (userCommand) {
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
void facadeInjector(char * p, DvrFacade * dvr) {

    dvr->server = new Server(p, dvr);
    dvr->connector = new Connector(dvr);
    dvr->shell = new Shell();
    dvr->clientVector = new ClientVector();
    dvr->handler = new Handler(dvr);

    std::thread([&] {
        dvr->handler->maintainConnectedClientList(dvr->clientVector);
    }).detach();
}



