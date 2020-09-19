#ifndef CHAT_SERVER_H
#define CHAT_SERVER_H
#include <string>
#include <vector>

class Client;
class Server {
public:
    Server(char *portArg);
    void listenForClientConnections();
    int getListeningPort() {return bindPort;}

private:
    std::vector<Client *> connectedClientList;
    int bindPort, connectionBacklogMaxLimit;

    void setupSocket(int *bindSocket, int *optionValue, struct sockaddr_in *address);
    void setAddressOptions(sockaddr_in *address);
    void bindAndListen(int *bindSocket, sockaddr_in *address);

};
#endif
