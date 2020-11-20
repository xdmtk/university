#ifndef DVR_ARGS_H
#define DVR_ARGS_H
#include <string>

class Args {
public:
    Args(int argc, char ** argv);
    bool parseCliArgs();

    std::string getTopologyFilepath() {return topologyFilePath;}
    int getRoutingUpdateInterval() {return routingUpdateInterval;}

private:
    int argc;
    char ** argv;

    std::string topologyFilePath;
    int routingUpdateInterval;

};

#endif
