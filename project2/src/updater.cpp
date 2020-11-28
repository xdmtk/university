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

std::string Updater::generateGeneralMessageFormat() {
    struct GeneralMessage generalMessage;
    struct in_addr addr;

    generalMessage.updateFields = dvr->topology->getTopologyData()->costList.size();
    generalMessage.serverPort = std::atoi(dvr->topology->getServerPort().c_str());

    if (!inet_aton(dvr->topology->getServerIp().c_str(), &addr)) {
        Logger::fatal("Invalid server IP address for this instance! Cannot parse into general message"
                      "format");
    }
    generalMessage.serverIp = addr.s_addr;


}