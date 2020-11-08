#ifndef CHAT_SERVER_H
#define CHAT_SERVER_H
#include <dvr/defs.h>
#include <string>
#include <vector>

class Client;
class Signals;
class Server {
public:
    Server(char *portArg, DvrFacade * chat);
    void listenForClientConnections();
    int getListeningPort() {return bindPort;}
    Signals * getSignalHandler() {return dvr->signals;}

private:
    DvrFacade * dvr;
    int bindPort, connectionBacklogMaxLimit;

    void setupSocket(int *bindSocket, int *optionValue, struct sockaddr_in *address);
    void setAddressOptions(sockaddr_in *address);
    void bindAndListen(int *bindSocket, sockaddr_in *address);

};
#endif
