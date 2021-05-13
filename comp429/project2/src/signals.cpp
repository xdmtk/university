#include <dvr/signals.h>
#include <dvr/logger.h>
#include <csignal>
#include <thread>
#include <chrono>


/**
 * The SignalManager class should register and handle the most common signals
 * that could be trapped by application.
 *
 * Most importantly it should handle the kill signal, properly clean up
 * all open sockets, and gracefully exit the application.
 */
volatile int Signals::signalNumber = -1;
Signals::Signals(Server * s){

    /* SignalManager requires a pointer back to the caller to perform
     * clean-up tasks outside the scope of the class */
    server = s;
    signalPollInterval = 1;

    registerSignals();
    listenForSignals();
}


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
/**
 * Opens a listener thread that polls the current signal number every second
 * to determine if a signal has been caught. If so, handleSignal() is called
 * and dealt with
 */
void Signals::listenForSignals() {
    std::thread([&] {
        while (true) {
            if (trappedSignal()) {
                handleSignal();
            }
            std::this_thread::sleep_for(std::chrono::seconds(signalPollInterval));
        }
    }).detach();
}
#pragma clang diagnostic pop


/**
 * Registers common signals that require special handling
 */
void Signals::registerSignals() {
    std::signal(SIGKILL, &Signals::updateSignalNumber);
    std::signal(SIGINT, &Signals::updateSignalNumber);
    std::signal(SIGSEGV, &Signals::updateSignalNumber);
    std::signal(SIGABRT, &Signals::updateSignalNumber);
    std::signal(SIGTERM, &Signals::updateSignalNumber);
    std::signal(SIGPIPE, &Signals::updateSignalNumber);
}

/**
 * The signal registry callback that updates a static class
 * global with the integer representing the trapped signal
 *
 * @param sn - Signal number integer
 */
void Signals::updateSignalNumber(int sn) {
    Signals::signalNumber = sn;
}

/**
 * Returns whether the application has trapped a signal. -1
 * is the default value and represents that no signal has been caught
 * @return
 */
bool Signals::trappedSignal() {
    return Signals::signalNumber != -1;
}

/**
 * Returns whether the application has trapped the given signal
 *
 * @param signal
 * @return
 */
bool Signals::trappedSignal(int signal) {
    return Signals::signalNumber == signal;
}

/**
 * Called when the signal trap flag has been set, handles
 * the signal appropriately
 */
void Signals::handleSignal() {
    switch (Signals::signalNumber) {

        // TODO: Implement functions to handle these signals
        case SIGABRT:
            handleSigAbort(); break;
        case SIGSEGV:
            handleSigSegfault(); break;
        case SIGINT:
            handleSigInterrupt(); break;
        case SIGKILL:
            handleSigKill(); break;
        case SIGPIPE:
            handleSigPipe(); break;
        case SIGTERM:
            handleSigTerm(); break;
        default:
            // For unregistered signals, let quick_exit() deal with any clean up
            std::quick_exit(-1);
    }

    // Reset the signal flag after its been handled
    Signals::signalNumber = -1;
}

/**
 * Signal handler functions, needs implementation
 */
void Signals::handleSigAbort() {
    Logger::warn("Caught SIGABORT");
    std::exit(0);
}
void Signals::handleSigSegfault() {
    Logger::warn("Caught SIGSEGV");
    std::exit(-1);
}
void Signals::handleSigInterrupt() {
    Logger::warn("Caught SIGINT");
    std::exit(0);
}
void Signals::handleSigKill() {
    Logger::warn("Caught SIGKILL");
    std::exit(0);
}
void Signals::handleSigPipe() {
    Logger::warn("Caught SIGPIPE");
}
void Signals::handleSigTerm() {
    Logger::warn("Caught SIGTERM");
    std::exit(0);
}

