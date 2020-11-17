#include <dvr/args.h>
#include <dvr/defs.h>
#include <dvr/logger.h>
#include <iostream>

Args::Args(int argc, char **argv) {
    this->argc = argc;
    this->argv = argv;
}

bool Args::parseCliArgs() {
    if (argc != 5) {
        std::cout << ERR_INVALID_ARGS << std::endl;
        return false;
    }
    for (int i = 0; i < 5; ++i) {
        try {
            if (std::string(argv[i]) == "-t") {
                this->topologyFilePath = argv[i+1];
            }
            if (std::string(argv[i]) == "-i") {
                this->routingUpdateInterval = std::atoi(argv[i+1]);
            }
        }
        catch (std::exception &e) {
            std::cout << ERR_MALFORMED_ARGS << std::endl;
            Logger::fatal("Exception caught while parsing arguments: " + std::string(e.what()));
            return false;
        }
    }
    return true;
}

