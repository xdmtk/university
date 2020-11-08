#ifndef DVR_SHELL_H
#define DVR_SHELL_H
#include <string>

#define USER_PROMPT ">> "
class Shell {

public:
    enum ShellCommand {
        InvalidCommand, EmptyCommand, QuitProgram
    };
    ShellCommand getUserCommand();
    std::string getLastUserInput() {return userInput;}

private:
    std::string userInput;
    inline void emitPrompt();
};


#endif
