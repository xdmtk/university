#ifndef CHAT_SERVER_H
#define CHAT_SERVER_H
#include <chat/defs.h>
#include <string>
#include <vector>

class Client;
class Signals;
class Server {
public:
    Server(char *portArg, ChatFacade * chat);
    void listenForClientConnections();
    int getListeningPort() {return bindPort;}
    Signals * getSignalHandler() {return chat->signals;}

private:
    ChatFacade * chat;
    int bindPort, connectionBacklogMaxLimit;

    void setupSocket(int *bindSocket, int *optionValue, struct sockaddr_in *address);
    void setAddressOptions(sockaddr_in *address);
    void bindAndListen(int *bindSocket, sockaddr_in *address);

};
#endif
