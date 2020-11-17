#ifndef DVR_TOPOLOGY_H
#define DVR_TOPOLOGY_H
#include <string>

class Topology {

public:
    Topology(std::string filename);

private:
    bool parseTopologyFile(std::string filename);
};


#endif
