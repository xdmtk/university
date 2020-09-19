#ifndef CHAT_CLIENT_H
#define CHAT_CLIENT_H

class Server;
class Client {

public:
    Client(Server *server, int socketFd);
    void mainConnectionLoop();

private:
    int socketFd;
    Server * server;
};

#endif