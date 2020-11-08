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

    /* Inject class dependencies in DvrFacade object - Easier to pass around
     * the program structure */
    facadeInjector(dvr);


    /* Respond to user input */
    while ((userCommand = dvr->shell->getUserCommand()) != ShellCommand::QuitProgram) {

        // TODO: Implement DVR spec commands
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
 */
void facadeInjector(DvrFacade *dvr) {

    dvr->server = new Server("6666" ,dvr); // TODO: Specs indicate port # should be assigned from topology file
    dvr->connector = new Connector(dvr);
    dvr->shell = new Shell();
    dvr->clientVector = new ClientVector();
    dvr->handler = new Handler(dvr);

    std::thread([&] {
        dvr->handler->maintainConnectedClientList(dvr->clientVector);
    }).detach();
}



