#include <dvr/args.h>
#include <dvr/defs.h>
#include <iostream>

Args::Args(int argc, char **argv) {
    this->argc = argc;
    this->argv = argv;
}

bool Args::parseCliArgs() {
    if (argc != 5) {
        std::cout << ERR_INVALID_ARGS;
        return false;
    }
}