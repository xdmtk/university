#ifndef CHAT_HANDLER_H
#define CHAT_HANDLER_H
#include <dvr/defs.h>

class Handler {

public:
    Handler(DvrFacade * chat);

    void handleHelpCommand();
    static void handleGetIpCommand();
    void handleGetPortCommand();
    void handleConnectCommand();
    static void maintainConnectedClientList(ClientVector * connectedClients);
    void handleInvalidCommand();
    void handleSendCommand();
    void handleListConnectionsCommand(ClientVector* connectedList);
    void handleTerminateConnectionCommand();

private:
    DvrFacade * chat;
};


#endif //CHAT_HANDLER_H
