#ifndef DVR_TOPOLOGY_H
#define DVR_TOPOLOGY_H

#include <string>
#include <vector>
#include <tuple>
#include <map>


class DvrFacade;
typedef std::tuple<int, std::string, int> ServerEntry;
typedef std::tuple<int, int, int> CostEntry;
class Topology {

    struct TopologyData {
        int serverCount;
        int edgeCount;
        std::vector<ServerEntry> serverList;
        std::vector<CostEntry> costList;
    };

    struct ServerEntryLine {
        int serverId;
        std::string serverIp;
        int serverPort;
    };

    struct CostEntryLine {
        int serverId;
        int neighborId;
        int cost;
    };

public:
    Topology(DvrFacade *dvr, std::string filename);
    std::string getServerPort() {return serverPort;}
    std::string getServerIp() {return serverIp;}
    TopologyData * getTopologyData() {return &topologyData;};

    bool updateCostEntry(int serverOne, int serverTwo, int cost);
    bool closeConnection(int close_serverID);
    int lookupServerId(std::string ip, int port);

private:
    DvrFacade * dvr;
    TopologyData topologyData;
    std::string serverPort, serverIp;
    bool parseTopologyFile(std::string filename);

    ServerEntryLine parseServerEntryLine(std::string line);
    CostEntryLine parseCostEntryLine(std::string line);
    std::map<std::string, int> serverIdLookupTable;
    std::map<int, std::pair<std::string, int>> serverIpLookupTable;
};


#endif
