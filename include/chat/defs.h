#ifndef CHAT_DEFS_H
#define CHAT_DEFS_H
#include <chat/shell.h>
#include <vector>

#define ERR_INVALID_ARGS "Invalid amount of arguments! Usage: ./chat [PORT]"

typedef Shell::ShellCommand ShellCommand;

std::vector<std::string> splitString(std::string s, const std::string& delimiter);
inline void ltrim(std::string &s);
inline void rtrim(std::string &s);
inline void trim(std::string &s);

#endif
