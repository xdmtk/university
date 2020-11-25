#include <dvr/handler.h>
#include <dvr/logger.h>
#include <dvr/server.h>
#include <dvr/client.h>
#include <dvr/connector.h>
#include <dvr/topology.h>

#include <iostream>
#include <chrono>
#include <thread>


/**
 * Used a helper class against the main shell loop that receives user input.
 * Switch in main.cpp calls functions from this class, and abstracts away the details
 * of each response to user entered commands
 *
 * @param dvr - Facade with all class dependencies of the project
 */
Handler::Handler(DvrFacade *dvr) {
    this->dvr = dvr;
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
void Handler::maintainConnectedClientList() {
    while (true)  {
        for (auto it = dvr->clientVector->begin(); it != dvr->clientVector->end(); ){
            if (!(*it)->isAlive()) {
                Logger::info("Pruned client at " + (*it)->getClientIpAddress() + " on port "
                             + std::to_string((*it)->getClientBindPort()));
                it = dvr->clientVector->erase(it);
            }
            else {
                it++;
            }
        }
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
}


/**
 *
 * Response function for invalid commands entered at the shell prompt
 */
void Handler::handleInvalidCommand() {
    Logger::info("Got invalid command");
    std::cout << "Invalid Command \"" << dvr->shell->getLastUserInput() << "\"" << std::endl;
}


/**
 * Kills each connection on the clientVector list
 * For: Crash functionality in doc
 */
void Handler::handleCrashCommand() {
    Logger::info("Got crash command");

    for (auto it = dvr->clientVector->begin(); it != dvr->clientVector->end(); ) {
        Logger::info("Pruned client at " + (*it)->getClientIpAddress() + " on port "
             + std::to_string((*it)->getClientBindPort()));
        it = dvr->clientVector->erase(it);
    }
}

/**
 * Displays the costList of each costEntry
 * For: Display functionality in doc
 */
void Handler::handleDisplayCommand() {
    Logger::info("Got display command");

    for (CostEntry costEntry : dvr->topology->getTopologyData().costList) {
        std::string serverId = std::to_string(std::get<0>(costEntry));
        std::string neighborId = std::to_string(std::get<1>(costEntry));
        std::string cost = std::to_string(std::get<2>(costEntry));
        Logger::info("Server ID: " + serverId + "\tNeighbor ID: " + neighborId + "\tCost: " + cost);
    }
}

#pragma clang diagnostic pop


