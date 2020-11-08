#ifndef CHAT_HANDLER_H
#define CHAT_HANDLER_H
#include <dvr/defs.h>

class Handler {

public:
    Handler(DvrFacade * dvr);

    static void maintainConnectedClientList(ClientVector * connectedClients);

private:
    DvrFacade * dvr;
};


#endif //CHAT_HANDLER_H
