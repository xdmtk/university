#ifndef CHAT_CONNECTOR_H
#define CHAT_CONNECTOR_H
#include <chat/defs.h>

class Connector {
public:
    Connector(ChatFacade * chat);
    bool connectToClient(std::string address, std::string port);

private:
    ChatFacade * chat;
};


#endif
