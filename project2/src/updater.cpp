#include <dvr/updater.h>
#include <dvr/server.h>
#include <dvr/topology.h>
#include <dvr/defs.h>
#include <dvr/logger.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>

Updater::Updater(DvrFacade * dvr) {
    this->dvr = dvr;
}

GeneralMessage Updater::generateGeneralMessageFormat() {
    struct GeneralMessage generalMessage;
    struct in_addr addr;

    generalMessage.updateFields = dvr->topology->getTopologyData()->costList.size();
    generalMessage.serverPort = std::atoi(dvr->topology->getServerPort().c_str());

    if (!inet_aton(dvr->topology->getServerIp().c_str(), &addr)) {
        Logger::fatal("Invalid server IP address " + dvr->topology->getServerIp() +
                      " for this instance! Cannot parse into general message format");
    }
    generalMessage.serverIp = addr.s_addr;
    generalMessage.serverUpdates = new std::vector<ServerCostMessage>();

    for (int i = 0; i < dvr->topology->getTopologyData()->costList.size(); ++i) {

        ServerCostMessage serverCostMessage;
        struct in_addr addr;
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

std::string serializeGeneralMessage(GeneralMessage gm) {
    std::string serialized;


}
