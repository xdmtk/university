#ifndef DVR_SIGNALS_H
#define DVR_SIGNALS_H
#include <csignal>

class Server;
class Signals {
public:
    Signals(Server *);
    bool trappedSignal();
    bool trappedSignal(int signal);

private:
    Server * server;
    static volatile std::sig_atomic_t  signalNumber;
    int signalPollInterval;

    void registerSignals();
    void listenForSignals();
    static void updateSignalNumber(int sn);

    static void handleSignal();
    static void handleSigAbort();
    static void handleSigSegfault();
    static void handleSigInterrupt();
    static void handleSigKill();
    static void handleSigPipe();
    static void handleSigTerm();
};

#endif