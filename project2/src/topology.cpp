#include <dvr/topology.h>
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

        }
    }

    topologyFile.close();
    return true;
}