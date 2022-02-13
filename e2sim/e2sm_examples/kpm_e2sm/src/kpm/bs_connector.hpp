#include <chrono>
#include <iostream>
#include <thread>

// send dummy data instead of reading BS metrics
#define DEBUG 1
#define LINES_TO_READ 2

void handleTimer(int* timer, long* ric_req_id);
void periodicDataReport(int* timer, long* ric_req_id);
