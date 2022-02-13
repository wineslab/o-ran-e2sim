#include <chrono>
#include <iostream>
#include <thread>

#include "encode_e2apv1.hpp"

// send dummy data instead of reading BS metrics
#define DEBUG 1
#define LINES_TO_READ 2

void handleTimer(int* timer, long* ric_req_id);
void periodicDataReport(int* timer, long* ric_req_id);
