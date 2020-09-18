#include <chat/shell.h>
#include <chat/defs.h>

#include <iostream>

/**
 * Emits a user prompts and parses user input into tokens, and returns an
 * enumeration back to the caller to determine which function to call
 *
 * @return ShellCommand - Enum to identify the specified command
 */
ShellCommand Shell::getUserCommand() {
    emitPrompt();
    auto tokens = splitString(userInput," ");

    if (tokens.empty()) {
        return ShellCommand::InvalidCommand;
    }
}


inline void Shell::emitPrompt() {
    std::cout << USER_PROMPT;
    std::getline(std::cin, userInput);
}