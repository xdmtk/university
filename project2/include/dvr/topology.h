#ifndef DVR_TOPOLOGY_H
#define DVR_TOPOLOGY_H
#include <string>
#include <vector>
#include <tuple>
#include <dvr/defs.h>

class Topology {

    struct TopologyData {
        int serverCount;
        int edgeCount;
        std::vector<ServerEntry> serverList;
        std::vector<CostEntry> costList;
    };

public:
    Topology(std::string filename);
    std::string getServerPort() {return serverPort;}

private:
    std::string serverPort;
    bool parseTopologyFile(std::string filename);
};


#endif
