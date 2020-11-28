#include <string>
#include "defs.h"

class DvrFacade;
class Updater {
public:
    Updater(DvrFacade *);
private:
    DvrFacade * dvr;
    GeneralMessage generateGeneralMessageFormat();
};