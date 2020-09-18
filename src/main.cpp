#include <chat/shell.h>
#include <chat/defs.h>
#include <chat/connector.h>

#include <iostream>

int main(int argc, char ** argv) {
    ShellCommand userCommand;

    /* Parse the port parameter */
    if (argc != 2) {
        std::cout << ERR_INVALID_ARGS << std::endl;
        std::exit(-1);
    }

    /* Start a listener */
    auto connector = new Server(argv[1]);

    /* Launch the Shell UI */
    auto shellUi = new Shell();

    /* Respond to user input */
    while ((userCommand = shellUi->getUserCommand()) != ShellCommand::QuitProgram) {
    }
    return 0;
}

