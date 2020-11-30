#ifndef DVR_DEFS_H
#define DVR_DEFS_H
#include <vector>
#include <dvr/shell.h>
#include <dvr/args.h>

#define COST_INF -1

class Connector;
class Server;
class Signals;
class Client;
class Shell;
class Handler;
class Topology;
class Updater;

typedef Shell::ShellCommand ShellCommand;
typedef std::vector<Client *> ClientVector;

struct DvrFacade {
    Shell * shell;
    Signals * signals;
    Server * server;
    Connector * connector;
    Handler * handler;
    ClientVector * clientVector;
    Topology * topology;
    Updater * updater;
};

struct ServerCostMessage {
    unsigned int serverIp;
    unsigned short serverPort;
    unsigned short serverId;
    unsigned short serverCost;
};

struct GeneralMessage {
    unsigned short updateFields;
    unsigned short serverPort;
    unsigned int serverIp;
    std::vector<ServerCostMessage> * serverUpdates;
};

#define ERR_INVALID_ARGS "Invalid amount of arguments! Usage: ./dvr -t <topology-file-name> -i <routing-update-interval>"
#define ERR_MALFORMED_ARGS "Invalid argument structure! Usage: ./dvr -t <topology-file-name> -i <routing-update-interval>"

#define ERR_INVALID_UPDATE_ARGS "Invalid amount of arguments! Usage: update <server id 1> <server id 2> <link cost>"
#define ERR_MALFORMED_UPDATE_ARGS "Invalid argument structure! Usage: update <int> <int> <int/inf>"

std::vector<std::string> splitString(std::string s, const std::string& delimiter);
inline void ltrim(std::string &s);
inline void rtrim(std::string &s);
inline void trim(std::string &s);
bool is_num(std::string s);

void facadeInjector(DvrFacade *dvr, Args * args);
void connectAndWaitForNeighbors(DvrFacade *dvr);

#endif
