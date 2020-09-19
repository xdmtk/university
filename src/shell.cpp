#include <chat/shell.h>
#include <chat/defs.h>

#include <iostream>
#include <utility>

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
    else if (tokens[0] == "help") {
        return ShellCommand::Help;
    }
}


inline void Shell::emitPrompt() {
    std::cout << USER_PROMPT;
    std::getline(std::cin, userInput);
}

void Shell::printHelpPage() {
    std::string commands[] = {
        "help", "myip", "myport", "connect",
        "list" , "terminate", "send", "exit"
    };
    std::string arguments[] = {
        "", "", "", "destination, port no",
        "", "connection id", "connection id", ""
    };
    std::string descriptions[] = {
            DESCRIPTION_HELP, DESCRIPTION_MYIP, DESCRIPTION_MYPORT, DESCRIPTION_CONNECT,
            DESCRIPTION_LIST, DESCRIPTION_TERMINATE, DESCRIPTION_SEND, DESCRIPTION_EXIT
    };

    for (int i = 0; i < 8; ++i) {
       std::cout << commands[i] << " " <<
       (arguments[i].length() ? formatHelpPageArguments(arguments[i]) : "") <<  " - " <<
       descriptions[i] << std::endl << std::endl;
    }
}

std::string Shell::formatHelpPageArguments(std::string args) {
    std::string out;
    auto argTokens = splitString(std::move(args), ",");

    for (const std::string& token : argTokens) {
        out += "<" + token + "> ";
    }
    return out;
}