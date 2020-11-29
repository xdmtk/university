#include <dvr/updater.h>
#include <dvr/client.h>
#include <dvr/server.h>
#include <dvr/topology.h>
#include <dvr/defs.h>
#include <dvr/logger.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <thread>
#include <chrono>

Updater::Updater(DvrFacade * dvr, int routingUpdateInterval) {
    this->dvr = dvr;
    this->routingUpdateInterval = routingUpdateInterval;
}


/**
 * Captures all required information specified by the General Message
 * Format, which is essentially just a snapshot of the current state of the
 * topology file, and writes it to a GeneralMessage struct which will later
 * be serialized and sent as a string to all connected clients
 */
GeneralMessage Updater::generateGeneralMessageFormat() {
    struct GeneralMessage generalMessage;
    struct in_addr addr;

    // All fields and their types are specified in the Project 2 requirements
    generalMessage.updateFields = dvr->topology->getTopologyData()->costList.size();
    generalMessage.serverPort = std::atoi(dvr->topology->getServerPort().c_str());

    // The IP address should be specified as 4 bytes (integer), so the network
    // string must be converted to binary format with inet_aton
    if (!inet_aton(dvr->topology->getServerIp().c_str(), &addr)) {
        Logger::fatal("Invalid server IP address " + dvr->topology->getServerIp() +
                      " for this instance! Cannot parse into general message format");
    }
    generalMessage.serverIp = addr.s_addr;

    // Store a vector for all neigbor servers in topology file
    generalMessage.serverUpdates = new std::vector<ServerCostMessage>();

    for (int i = 0; i < dvr->topology->getTopologyData()->costList.size(); ++i) {

        ServerCostMessage serverCostMessage;
        struct in_addr addr;

        // Index into the existing server/cost lists originally created from topology file
        ServerEntry currentServerEntry = dvr->topology->getTopologyData()->serverList.at(i+1);
        CostEntry  currentCostEntry = dvr->topology->getTopologyData()->costList.at(i);

        if (!inet_aton(std::get<1>(currentServerEntry).c_str(), &addr)) {
            Logger::fatal("Invalid server IP address " + std::get<1>(currentServerEntry) +
                          " ! Cannot parse into general message format");
        }
        serverCostMessage.serverIp = addr.s_addr;
        serverCostMessage.serverId = std::get<0>(currentServerEntry);
        serverCostMessage.serverPort = std::get<2>(currentServerEntry);
        serverCostMessage.serverCost = std::get<2>(currentCostEntry);

        generalMessage.serverUpdates->emplace_back(serverCostMessage);
    }

    return generalMessage;
}

/**
 * An honest attempt was made here to serialize the data captured in the
 * above function from the GeneralMessage struct, but the effort required to perform
 * raw serialization on a struct with pointers far outweighed the practical benefits of
 * having data serialized to the exact specification in the requirements.
 *
 * Instead, the data in the GeneralMessage struct is simply reformated back into
 * a string data type so it can be easily passed along to other servers with the existing
 * sendMessage() functions in the program infrastructure.
 *
 * Uses the pipe symbol (|) as a field delimiter
 */
std::string Updater::serializeGeneralMessage(GeneralMessage gm) {
    std::string serialized;
    struct in_addr addr;

    serialized.append(std::to_string(gm.updateFields));
    serialized.append("|");
    serialized.append(std::to_string(gm.serverPort));
    serialized.append("|");
    addr.s_addr = gm.serverIp;
    serialized.append(inet_ntoa(addr));
    serialized.append("|");

    for (ServerCostMessage serverCostMessage : *gm.serverUpdates) {
        addr.s_addr = serverCostMessage.serverIp;
        serialized.append(inet_ntoa(addr));
        serialized.append("|");
        serialized.append(std::to_string(serverCostMessage.serverPort));
        serialized.append("|");
        serialized.append(std::to_string(serverCostMessage.serverId));
        serialized.append("|");
        serialized.append(std::to_string(serverCostMessage.serverCost));
        serialized.append("|");
    }
    return serialized;
}


/**
 * Sets a thread in motion to continuously send routing updates to
 * all connected clients at an interval specified by the routingUpdateInterval
 * variable set in the arguments on startup
 */
void Updater::enableRoutingUpdates() {
    std::thread([&] {
        while (true) {

            Logger::info("Sending routing update to neighbors..");
            std::string serialized = dvr->updater->serializeGeneralMessage(
                    dvr->updater->generateGeneralMessageFormat()
            );
            for (auto client : *dvr->clientVector) {
                client->sendMessage(serialized);
            }
            std::this_thread::sleep_for(std::chrono::seconds(routingUpdateInterval));
        }
    }).detach();
}

/**
 * Called after receiving an incoming message from a Client. Updates the
 * routing table according to the data contained in the message received.
 */
void Updater::parseIncomingRoutingUpdate(std::string msg) {



}