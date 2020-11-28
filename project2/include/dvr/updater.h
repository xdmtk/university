#include <string>

class DvrFacade;
class Updater {
public:
    Updater(DvrFacade *);
private:
    DvrFacade * dvr;
    std::string generateGeneralMessageFormat();
};