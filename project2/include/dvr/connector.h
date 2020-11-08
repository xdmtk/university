#ifndef CHAT_CONNECTOR_H
#define CHAT_CONNECTOR_H
#include <netinet/in.h>
#include <dvr/defs.h>

#include <utility>

class Connector {
public:
    Connector(DvrFacade * dvr);

    bool connectToClient(const std::string& address, const std::string& port);
    std::string getFailureReason() {return reason;}

private:
    DvrFacade * dvr;
    std::string reason;

    void setFailureReason(std::string r) {reason = std::move(r);}
    int validateConnectionParameters(const std::string& address,
            const std::string& port, struct sockaddr_in * s);
};


#endif
