#ifndef CHAT_SIGNALS_H
#define CHAT_SIGNALS_H
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

    void handleSignal();
    void handleSigAbort();
    void handleSigSegfault();
    void handleSigInterrupt();
    void handleSigKill();
    void handleSigPipe();
    void handleSigTerm();
};

#endif