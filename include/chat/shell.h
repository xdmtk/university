#ifndef CHAT_SHELL_H
#define CHAT_SHELL_H
#include <string>

#define USER_PROMPT ">> "

class Shell {

public:
    enum ShellCommand {
        Help, GetIp, GetPort, Connect, ListConnections,
        TerminateConnection, SendMessage, InvalidCommand, QuitProgram
    };
    ShellCommand getUserCommand();

private:
    std::string userInput;
    inline void emitPrompt();
};


#endif
