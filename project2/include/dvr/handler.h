#ifndef DVR_HANDLER_H
#define DVR_HANDLER_H
class DvrFacade;
class Handler {

public:
    Handler(DvrFacade * dvr);

    void maintainConnectedClientList();
    void handleDisplayCommand();
    void handleCrashCommand();
    void handleInvalidCommand();
    void handleUpdateCommand();
    void handleStepCommand();
    void handleDisableCommand();
    void handlePacketCommand();
  
private:
    DvrFacade * dvr;
};


#endif
