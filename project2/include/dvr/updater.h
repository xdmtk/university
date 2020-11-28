#include <string>
#include "defs.h"

class DvrFacade;
class Updater {
public:
    Updater(DvrFacade *);

    GeneralMessage generateGeneralMessageFormat();
    std::string serializeGeneralMessage(GeneralMessage gm);
private:
    DvrFacade * dvr;
};