#ifndef CHAT_DEFS_H
#define CHAT_DEFS_H
#include <vector>
#include <dvr/shell.h>

class Connector;
class Server;
class Signals;
class Client;
class Shell;
class Handler;

typedef Shell::ShellCommand ShellCommand;
typedef std::vector<Client *> ClientVector;

struct DvrFacade {
    Shell * shell;
    Signals * signals;
    Server * server;
    Connector * connector;
    Handler * handler;
    ClientVector * clientVector;
};

#define ERR_INVALID_ARGS "Invalid amount of arguments! Usage: ./dvr [PORT]"

std::vector<std::string> splitString(std::string s, const std::string& delimiter);
inline void ltrim(std::string &s);
inline void rtrim(std::string &s);
inline void trim(std::string &s);

std::string getIpAddress();
void facadeInjector(char *, DvrFacade * dvr);
std::string collapseTokens(std::vector<std::string> tokens, int begin, int end);

#endif
