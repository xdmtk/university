#ifndef DVR_SERVER_H
#define DVR_SERVER_H
#include <string>
#include <vector>

class DvrFacade;
class Client;
class Signals;
class Server {
public:
    Server(std::string portArg, DvrFacade * chat);
    void listenForClientConnections();
    Signals * getSignalHandler();
private:
    DvrFacade * dvr;
    int bindPort, connectionBacklogMaxLimit;

    void setupSocket(int *bindSocket, int *optionValue, struct sockaddr_in *address);
    void setAddressOptions(sockaddr_in *address);
    void bindAndListen(int *bindSocket, sockaddr_in *address);

};
#endif
