#include <dvr/topology.h>
#include <dvr/logger.h>
#include <dvr/defs.h>
#include <iostream>
#include <fstream>
#include <tuple>


/**
 * The Topology class acts as both a file parser and a representation
 * of the parsed data. The constructor takes the filepath of the topology file and
 * calls the parser, throwing an exception on failure.
 *
 * On success, the class level TopologyData struct is filled, and can be accessed
 * through its getter at any point in the program.
 *
 * @param filename - File path of the topology file
 */
Topology::Topology(std::string filename) {
    if (!parseTopologyFile(filename)) {
        throw std::runtime_error("Failed to parse topology file!");
    }
}

/**
 * Logic to open, read, and parse the data in the topology file. Since
 * the file parsing here is critical to program execution, major failures
 * result in a call to Logger::fatal (halts program execution), and minor
 * failures result in this function return false.
 *
 * @param filename - File path of the topology file
 * @return - True on success, False on failure
 */
bool Topology::parseTopologyFile(std::string filename) {

    std::ifstream topologyFile(filename);
    if (!topologyFile.is_open()) {
        return false;
    }

    for (std::pair<std::string, int> line("", 0); std::getline(topologyFile, line.first); ++line.second) {

        // Line 0 contains number of servers
        if (line.second == 0) {
            if ((topologyData.serverCount = std::atoi(line.first.c_str())) == 0) {
                Logger::fatal("Bad server count in topology file!");
            }
        }

        // Line 1 contains number of neighbors
        if (line.second == 1) {
            if ((topologyData.edgeCount = std::atoi(line.first.c_str())) == 0) {
                Logger::fatal("Bad edge count in topology file!");
            }
        }

        // Lines 2 through 2+X (specified by the server count) contains server information
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

        // All subsequent lines contain cost information
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
    serverPort = std::to_string(std::get<2>(topologyData.serverList[0]));

    topologyFile.close();
    return true;
}


/**
 * Simple parser for the Server Entry Lines
 * @param line
 * @return
 */
Topology::ServerEntryLine Topology::parseServerEntryLine(std::string line) {
    auto slices = splitString(line, " ");
    if (slices.size() != 3) {
        Logger::fatal("Malformed Server entry line!");
    }
    return ServerEntryLine {
        std::atoi(slices[0].c_str()),
        slices[1],
        std::atoi(slices[2].c_str())
    };
}

/**
 * Simple parser for the Cost Entry Lines
 * @param line
 * @return
 */
Topology::CostEntryLine Topology::parseCostEntryLine(std::string line) {
    auto slices = splitString(line, " ");
    if (slices.size() != 3) {
        Logger::fatal("Malformed Cost entry line!");
    }
    return CostEntryLine {
            std::atoi(slices[0].c_str()),
            std::atoi(slices[1].c_str()),
            std::atoi(slices[2].c_str())
    };
}