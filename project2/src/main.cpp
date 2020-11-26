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
#include <chrono>

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

    /* Block here until all specified neighbors are connected */
    // connectAndWaitForNeighbors(dvr);

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

}


/**
 * Implements functionality to attempt connections to the
 * neighbors specified in the topology file every 3 seconds. This allows the
 * program to make sure all neighbors are connected before starting
 * the distance vector routing protocol routines
 */
void connectAndWaitForNeighbors(DvrFacade *dvr) {

    std::cout << "Waiting for connection to specified neighbors" << std::endl;

    std::vector<std::thread *> connectorThreads;
    for (ServerEntry serverEntry : dvr->topology->getTopologyData().serverList) {

        // Skip connecting the running instance (this/itself)
        if (std::get<0>(serverEntry) == 1) continue;

        /* Generate a new thread that attempts to connect to the given neighbor every
        3 seconds */
        auto connectorWait = new std::thread([serverEntry, &dvr] {

            const std::string& address = std::get<1>(serverEntry);
            std::string port = std::to_string(std::get<2>(serverEntry));
            std::string serverId = std::to_string(std::get<0>(serverEntry));

            while (!dvr->connector->connectToClient(address, port)) {
                Logger::info("Waiting for neighbor ID " + serverId
                    + " at address " + address + " on port " + port
                    + " to come online");
                std::this_thread::sleep_for(std::chrono::seconds(3));
            }
            Logger::info("Neighbor ID " + serverId + " has connected");
        });
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Save these threads and join them at the end of the function
        connectorThreads.emplace_back(connectorWait);
    }
    for (std::thread * connectorWait : connectorThreads) {
        connectorWait->join();
    }

    std::cout << "All clients connected - Ready for distance vector routing updates"
        << std::endl;
}

