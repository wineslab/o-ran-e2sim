#include <chrono>
#include <iostream>
#include <thread>

#include "e2sim.hpp"

// send dummy data instead of reading BS metrics
#define DEBUG 1
#define LINES_TO_READ 2

void handleTimer(E2Sim* e2sim, int* timer, long* ric_req_id);
void periodicDataReport(E2Sim* e2sim, int* timer, long* ric_req_id);
