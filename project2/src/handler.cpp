#include <dvr/handler.h>
#include <dvr/logger.h>
#include <dvr/server.h>
#include <dvr/client.h>
#include <dvr/connector.h>
#include <dvr/topology.h>
#include <dvr/updater.h>
#include <dvr/defs.h>

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

void Handler::handleStepCommand() {
    std::string serialized = dvr->updater->serializeGeneralMessage(
            dvr->updater->generateGeneralMessageFormat()
            );
    for (auto client : *dvr->clientVector) {
        client->sendMessage(serialized);
    }
}


void Handler::handleUpdateCommand() {
    auto tokens = splitString(dvr->shell->getLastUserInput(), " ");

    // Check argument count
    if (tokens.size() != 4) {
        std::cout << ERR_INVALID_UPDATE_ARGS << std::endl;
        dvr->shell->emitPrompt();
        return;
    }

    // Validate argument format
    if (!(is_num(tokens[1]) && is_num(tokens[2])) || (
            !(is_num(tokens[3]) || tokens[3] == "inf")))  {
        std::cout << ERR_MALFORMED_UPDATE_ARGS << std::endl;
        dvr->shell->emitPrompt();
        return;
    }

    // Parse arguments
    int serverIdOne = std::atoi(tokens[1].c_str());
    int serverIdTwo = std::atoi(tokens[2].c_str());
    int cost = tokens[3] != "inf" ? std::atoi(tokens[3].c_str()) : COST_INF;

    // Find link specified by arguments and update cost
    if (!dvr->topology->updateCostEntry(serverIdOne, serverIdTwo, cost)) {

        // Print and log error if unable to find specified link
        std::string error_str = ("Could not update cost for Server ID " + std::to_string(serverIdOne) +
                     " to " + std::to_string(serverIdTwo) + " with cost " + std::to_string(cost)
                     + ". Unable to find this link the topology data struct!");
        std::cout << error_str << std::endl;
        Logger::error(error_str);
    }
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
#pragma clang diagnostic pop


