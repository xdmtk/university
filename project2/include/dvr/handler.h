#ifndef DVR_HANDLER_H
#define DVR_HANDLER_H
#include <dvr/defs.h>

class Handler {

public:
    Handler(DvrFacade * dvr);

    void maintainConnectedClientList();

private:
    DvrFacade * dvr;
};


#endif
