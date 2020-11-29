#ifndef DVR_CLIENT_H
#define DVR_CLIENT_H

#define IP_RECV 0x5

#include <string>
#include <utility>
#include <vector>
#include "defs.h"

class Server;
class DvrFacade;
class Client {

public:
    Client(Server *server, int socketFd, int bindPort, DvrFacade *dvr);
    void mainConnectionLoop();
    std::string getClientIpAddress() { return this->ipAddress;}

    int getClientBindPort() { return this->bindPort;}
    bool isAlive() {return !terminated;}
    void sendMessage(const std::string &msg);

private:
    DvrFacade * dvr;
    Server * server;
    int socketFd, bindPort;
    bool terminated;
    std::string ipAddress;

};

#endif