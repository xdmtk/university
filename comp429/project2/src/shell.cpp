#include <dvr/shell.h>
#include <dvr/defs.h>

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
        return ShellCommand::EmptyCommand;
    }
    else if (tokens[0] == "update") {
        return ShellCommand::UpdateCommand;
    }
    else if (tokens[0] == "step") {
        return ShellCommand::StepCommand;
    }
    else if (tokens[0] == "packets") {
        return ShellCommand::PacketCommand;
    }
    else if (tokens[0] == "display") {
        return ShellCommand::DisplayCommand;
    }
    else if (tokens[0] == "crash") {
        return ShellCommand::CrashCommand;
    }
    else if (tokens[0] == "disable") {
        return ShellCommand::DisableCommand;
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
