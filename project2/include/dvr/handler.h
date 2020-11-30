#ifndef DVR_HANDLER_H
#define DVR_HANDLER_H
class DvrFacade;
class Handler {

public:
    Handler(DvrFacade * dvr);

    void maintainConnectedClientList();
    void handleUpdateCommand();
    void handleStepCommand();
    void handlePacketCommand();
private:
    DvrFacade * dvr;
};


#endif
