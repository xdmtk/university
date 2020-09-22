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
    std::string getClientIpAddress() { return this->ipAddress;}
    int getClientBindPort() { return this->bindPort;}
    bool isAlive() {return !terminated;}
    void sendMessage(const std::string& msg);

private:
    Server * server;
    int socketFd, bindPort;
    bool terminated;
    std::string ipAddress;

    void printReceivedMessage(const std::string&);

};

#endif