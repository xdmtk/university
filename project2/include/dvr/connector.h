#ifndef DVR_CONNECTOR_H
#define DVR_CONNECTOR_H
#include <netinet/in.h>
#include <dvr/defs.h>

#include <utility>

class Connector {
public:
    Connector(DvrFacade * dvr);
    bool connectToClient(const std::string &address, const std::string &port);

private:
    DvrFacade * dvr;
    std::string reason;

    void setFailureReason(std::string r) {reason = std::move(r);}
    int validateConnectionParameters(const std::string& address,
            const std::string& port, struct sockaddr_in * s);

};


#endif
