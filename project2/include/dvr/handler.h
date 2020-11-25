#ifndef DVR_HANDLER_H
#define DVR_HANDLER_H
#include <dvr/defs.h>

class Handler {

public:
    Handler(DvrFacade * dvr);

    void maintainConnectedClientList();
    void handleDisplayCommand();
    void handleCrashCommand();
    void handleInvalidCommand();

private:
    DvrFacade * dvr;
};


#endif
