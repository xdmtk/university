#include <dvr/topology.h>
#include <iostream>
#include <fstream>

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
    topologyFile.close();
}