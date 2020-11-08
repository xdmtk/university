#ifndef CHAT_CLIENT_H
#define CHAT_CLIENT_H

#define IP_RECV 0x5

#include <string>
#include <utility>
#include <vector>

class Server;
class Client {

public:
    Client(Server *server, int socketFd, int bindPort);
    void mainConnectionLoop();
    std::string getClientIpAddress() { return this->ipAddress;}

    int getClientBindPort() { return this->bindPort;}
    bool isAlive() {return !terminated;}
    void sendMessage(const std::string &msg);

private:
    Server * server;
    int socketFd, bindPort;
    bool terminated;
    std::string ipAddress;

};

#endif