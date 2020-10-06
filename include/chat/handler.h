#ifndef CHAT_HANDLER_H
#define CHAT_HANDLER_H
#include <chat/defs.h>

class Handler {

public:
    Handler(ChatFacade * chat);

    void handleHelpCommand();
    static void handleGetIpCommand();
    void handleGetPortCommand();
    void handleConnectCommand();
    static void maintainConnectedClientList(ClientVector * connectedClients);
    void handleInvalidCommand();
    void handleSendCommand();
    void handleListConnectionsCommand();
    void handleTerminateConnectionCommand();

private:
    ChatFacade * chat;
};


#endif //CHAT_HANDLER_H
