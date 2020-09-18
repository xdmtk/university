#ifndef CHAT_CLIENT_H
#define CHAT_CLIENT_H

class Client {

public:
    Client(int socketFd);
    void mainConnectionLoop();

};

#endif