#include <dvr/shell.h>
#include <dvr/client.h>
#include <dvr/defs.h>
#include <dvr/server.h>
#include <dvr/signals.h>
#include <dvr/logger.h>
#include <dvr/connector.h>
#include <dvr/handler.h>
#include <dvr/topology.h>
#include <dvr/args.h>

#include <iostream>
#include <thread>

int main(int argc, char ** argv) {

    ShellCommand userCommand;
    auto dvr = new DvrFacade();
    auto args = new Args(argc, argv);

    /* Parse and validate command line arguments -t and -i */
    if (!args->parseCliArgs()) {
        Logger::error("Failed to parse CLI args");
        return -1;
    }

    /* Inject class dependencies in DvrFacade object */
    facadeInjector(dvr, args);

    /* Respond to user input */
    while ((userCommand = dvr->shell->getUserCommand()) != ShellCommand::QuitProgram) {

        // TODO: Implement DVR spec commands
        switch (userCommand) {
            case ShellCommand::EmptyCommand:
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
void facadeInjector(DvrFacade *dvr, Args * args) {

    dvr->topology = new Topology(args->getTopologyFilepath());
    dvr->server = new Server(dvr->topology->getServerPort(), dvr);
    dvr->connector = new Connector(dvr);
    dvr->shell = new Shell();
    dvr->clientVector = new ClientVector();
    dvr->handler = new Handler(dvr);

    std::thread([&] {
        dvr->handler->maintainConnectedClientList(dvr->clientVector);
    }).detach();
}



