//
// Created by thecave3 on 20/09/21.
//

#include "signal_handler.hpp"
#include <csignal>
#include <cerrno>


bool SignalHandler::m_running = true;

/**
* Default Constructor.
*/
SignalHandler::SignalHandler() {
    this->setupSIGIOT();
}

/**
* Destructor.
*/
SignalHandler::~SignalHandler()
= default;

/**
* Returns the bool flag indicating if the application should continue to run
* @return Flag indicating the status of the program
*/
bool SignalHandler::isRunning() {
    return m_running;
}

/**
* Sets exit signal to true.
* @param[in] _ignored Not used but required by function prototype
*                     to match required handler.
*/
void SignalHandler::stopRun(int _ignored) {
    m_running = false;
}

/**
 * Arms the SIGIOT signal
 */
void SignalHandler::setupSIGIOT() {
    return this->setupSignalHandlers(SIGIOT, SignalHandler::stopRun);
}

/**
* Set up the signal handlers for a signal code
*/
void SignalHandler::setupSignalHandlers(int signal_code, __sighandler_t sig_function) {
    if (signal(signal_code, sig_function) == SIG_ERR) {
        throw SignalException("[SIG] Error in setting up");
    }
}