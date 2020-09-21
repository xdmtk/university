#ifndef CHAT_CLIENT_H
#define CHAT_CLIENT_H

#include <string>
#include <utility>

class Server;
class Client {

public:
    Client(Server *server, int socketFd, int bindPort);
    void mainConnectionLoop();
    void setClientIpAddress(std::string addr) { this->ipAddress = std::move(addr);}
    bool isAlive() {return !terminated;}

private:
    Server * server;
    int socketFd, bindPort;
    bool terminated;
    std::string ipAddress;

    void printReceivedMessage(const std::string&);
};

#endif