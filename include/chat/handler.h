#ifndef CHAT_HANDLER_H
#define CHAT_HANDLER_H
#include <chat/defs.h>

class Handler {

public:
    Handler(ChatFacade * chat);
    void handleHelpCommand();
    static void handleGetIpCommand();
    void handleGetPortCommand();
    static void handleConnectCommand(ChatFacade * chat, std::string userInput);
    void maintainConnectedClientList(ClientVector * connectedClients);

private:
    ChatFacade * chat;
};


#endif //CHAT_HANDLER_H
