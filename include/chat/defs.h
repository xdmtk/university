#ifndef CHAT_DEFS_H
#define CHAT_DEFS_H
#include <chat/client.h>
#include <chat/shell.h>
#include <chat/signals.h>
#include <vector>

#define ERR_INVALID_ARGS "Invalid amount of arguments! Usage: ./chat [PORT]"

typedef Shell::ShellCommand ShellCommand;
typedef std::vector<Client *> ClientVector;

std::vector<std::string> splitString(std::string s, const std::string& delimiter);
inline void ltrim(std::string &s);
inline void rtrim(std::string &s);
inline void trim(std::string &s);

std::string getIpAddress();
void maintainConnectedClientList(ClientVector * connectedClients);
void facadeInjector(char *, Shell *, Signals *, Server *, ClientVector *);

#endif
