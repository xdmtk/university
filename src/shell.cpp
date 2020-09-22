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
        return ShellCommand::EmptyCommand;
    }
    else if (tokens[0] == "help") {
        return ShellCommand::Help;
    }
    else if (tokens[0] == "exit") {
        return ShellCommand::QuitProgram;
    }
    else if (tokens[0] == "myport") {
        return ShellCommand::GetPort;
    }
    else if (tokens[0] == "myip") {
        return ShellCommand::GetIp;
    }
    else if (tokens[0] == "connect") {
        return ShellCommand::Connect;
    }
    else if (tokens[0] == "send") {
        return ShellCommand::SendMessage;
    }
    else {
        return ShellCommand::InvalidCommand;
    }
}

/**
 * Helper function to output the user prompt and receive
 * user input
 */
inline void Shell::emitPrompt() {
    std::cout << USER_PROMPT;
    std::getline(std::cin, userInput);
}


/**
 * Formats and prints the help page, listing all available commands, their
 * required arguments, and their descriptions
 */
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


/**
 * Helper function when formatting the help page. Given a comma delimited
 * list of arguments, returns a < arg > formatted string with each specified
 * argument
 *
 * @param args - Comma delimited argument list
 * @return - string - Formatted argument string
 */
std::string Shell::formatHelpPageArguments(std::string args) {
    std::string out;
    auto argTokens = splitString(std::move(args), ",");

    for (const std::string& token : argTokens) {
        out += "<" + token + "> ";
    }
    return out;
}