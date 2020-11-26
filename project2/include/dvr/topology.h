#ifndef DVR_TOPOLOGY_H
#define DVR_TOPOLOGY_H

#include <string>
#include <vector>
#include <tuple>


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
    Topology(std::string filename);
    std::string getServerPort() {return serverPort;}
    TopologyData getTopologyData() {return topologyData;};

private:
    TopologyData topologyData;
    std::string serverPort;
    bool parseTopologyFile(std::string filename);

    ServerEntryLine parseServerEntryLine(std::string line);
    CostEntryLine parseCostEntryLine(std::string line);
};


#endif
