#include <string>
#include "defs.h"

class DvrFacade;
class Updater {
public:
    Updater(DvrFacade *, int routingUpdateInterval);

    GeneralMessage generateGeneralMessageFormat();
    std::string serializeGeneralMessage(GeneralMessage gm);
    void enableRoutingUpdates();
    void parseIncomingRoutingUpdate(std::string msg);
private:
    int routingUpdateInterval;
    DvrFacade * dvr;

};