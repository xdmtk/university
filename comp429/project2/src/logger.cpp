#include <dvr/logger.h>

#include <csignal>
#include <fstream>
#include <ios>
#include <iostream>
#include <utility>
#include <sys/stat.h>

/**
 * Logger configuration settings
 */
bool Logger::writeToConsole = false;
bool Logger::writeToFile = true;
bool Logger::terminateOnFatal = true;

/**
 * Series of public facing, static log functions to be inserted around the
 * application for debugging.
 * @param msg
 */
void Logger::info(std::string msg) {
    log(std::move(msg), LogLevel::Info);
}

void Logger::debug(std::string msg) {
    log(std::move(msg), LogLevel::Debug);
}

void Logger::warn(std::string msg){
    log(std::move(msg), LogLevel::Warn);
}

void Logger::error(std::string msg){
    log(std::move(msg), LogLevel::Error);
}

void Logger::fatal(std::string msg){
    log(std::move(msg), LogLevel::Fatal);
}


/**
 * Master function called by public shorthand functions for Logging
 * at various levels of importance.
 * @param msg
 * @param level
 */
void Logger::log(std::string msg, Logger::LogLevel level) {

    std::ofstream logStream(getLogDirectory() + getCurrentDateString() + ".log", std::fstream::out | std::fstream::app);
    std::string levelString;

    switch (level) {
        case LogLevel::Info: levelString = "INFO"; break;
        case LogLevel::Debug: levelString = "DEBUG"; break;
        case LogLevel::Warn: levelString = "WARN"; break;
        case LogLevel::Error: levelString = "ERROR"; break;
        case LogLevel::Fatal: levelString = "FATAL"; break;
    }
    msg = "[" + getCurrentDateString() + "]-[" + getCurrentTimeString() + "]-[" + levelString
          + "] - " + msg + "\n";

    if (logStream.is_open() && logStream.good() && writeToFile) {
        logStream.write(msg.c_str(), msg.size());
        logStream.close();
    }
    if (writeToConsole) {
        std::cerr << msg;
    }
    if (terminateOnFatal && level == LogLevel::Fatal) {
        raise(SIGTERM);
    }
}


/**
 * Builds and returns a hidden directory at the running users home
 * directory for log file storage
 * @return
 */
std::string Logger::getLogDirectory() {
    std::string logDirectoryPath = getHomeDirectory() + "/.dvrlogs/";
    mkdir(logDirectoryPath.c_str(), 0777);
    return logDirectoryPath;
}



/**
 * Simple helper function to return the current year, month,
 * and date in the format MM-DD-YYYY
 * @return - Formatted string date, month, year
 */
std::string Logger::getCurrentDateString() {
    time_t currentUnixTime = time(0);
    tm * timeStructure = localtime(&currentUnixTime);

    int month = timeStructure->tm_mon+1;
    int day = timeStructure->tm_mday;
    int year = timeStructure->tm_year+1900;

    return (month < 10 ? "0" : "") + std::to_string(month)
           + "-" + (day  < 10 ? "0" : "") + std::to_string(day)
           + "-" + (year  < 10 ? "0" : "") + std::to_string(year);
}

/**
 * Simple helper function to return the current hour, minute,
 * and second in the format HH:MM:SS
 * @return - Formatted string hour, minute, second
 */
std::string Logger::getCurrentTimeString() {
    time_t currentUnixTime = time(0);
    tm * timeStructure = localtime(&currentUnixTime);

    int hour = timeStructure->tm_hour;
    int min = timeStructure->tm_min;
    int sec = timeStructure->tm_sec;

    return (hour < 10 ? "0" : "") + std::to_string(hour)
           + ":" + (min  < 10 ? "0" : "") + std::to_string(min)
           + ":" + (sec  < 10 ? "0" : "") + std::to_string(sec);
}

/**
 * Returns the executing users home directory
 * @return
 */
std::string Logger::getHomeDirectory() {
    // TODO: Implement a Windows log path
#ifdef __linux__
    return "/home/" + std::string(getenv("USER"));
#endif
}
