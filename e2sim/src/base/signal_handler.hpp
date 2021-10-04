//
// Created by thecave3 on 20/09/21.
//

#ifndef E2SIM_SIGNAL_HANDLER_HPP
#define E2SIM_SIGNAL_HANDLER_HPP

#include <stdexcept>
#include <csignal>

using std::runtime_error;

class SignalException : public runtime_error {
public:
    explicit SignalException(const std::string &_message)
            : std::runtime_error(_message) {}
};

class SignalHandler {
protected:
    static bool m_running;

public:
    SignalHandler();

    ~SignalHandler();

    static bool isRunning();

    void setupSignalHandlers(int signal_code, __sighandler_t sig_function);

    static void stopRun(int _ignored);

    void setupSIGIOT();
};


#endif //E2SIM_SIGNAL_HANDLER_HPP
