#ifndef DVR_LOGGER_H
#define DVR_LOGGER_H

#include <string>

class Logger {
public:
    static void info(std::string);
    static void debug(std::string);
    static void warn(std::string);
    static void error(std::string);
    static void fatal(std::string);

    static std::string getCurrentTimeString();
private:
    enum LogLevel {Info, Debug, Warn, Error, Fatal};
    static bool writeToConsole;
    static bool writeToFile;
    static bool terminateOnFatal;

    static void log(std::string, LogLevel);

    static std::string getCurrentDateString();
    static std::string getLogDirectory();
    static std::string getHomeDirectory();
};


#endif
