#include <dvr/topology.h>
#include <dvr/logger.h>
#include <iostream>
#include <fstream>
#include <tuple>

Topology::Topology(std::string filename) {
    if (!parseTopologyFile(filename)) {
        throw std::runtime_error("Failed to parse topology file!");
    }
}

bool Topology::parseTopologyFile(std::string filename) {

    std::ifstream topologyFile(filename);
    if (!topologyFile.is_open()) {
        return false;
    }

    for (std::pair<std::string, int> line("", 0); std::getline(topologyFile, line.first); ++line.second) {
        if (line.second == 0) {
            if ((topologyData.serverCount = std::atoi(line.first.c_str())) == 0) {
                Logger::fatal("Bad server count in topology file!");
            }
        }
        if (line.second == 1) {
            if ((topologyData.edgeCount = std::atoi(line.first.c_str())) == 0) {
                Logger::fatal("Bad edge count in topology file!");
            }
        }
        if (line.second > 1 && line.second < (topologyData.serverCount + 2)) {
            auto sel = parseServerEntryLine(line.first);
            topologyData.serverList.emplace_back(
                    std::make_tuple(
                            sel.serverId,
                            sel.serverIp,
                            sel.serverPort
                    )
            );
        }
        if (line.second > (topologyData.serverCount + 1)) {
            auto cel = parseCostEntryLine(line.first);
            topologyData.costList.emplace_back(
                    std::make_tuple(
                            cel.serverId,
                            cel.neighborId,
                            cel.cost
                    )
            );
        }
    }

    topologyFile.close();
    return true;
}

Topology::ServerEntryLine Topology::parseServerEntryLine(std::string line) {


}

Topology::CostEntryLine Topology::parseCostEntryLine(std::string line) {


}