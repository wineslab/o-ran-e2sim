#include <thread>
#include <time>

// send dummy data instead of reading BS metrics
#define DEBUG 1
#define LINES_TO_READ 2

void handleTimer(float timer, long ric_req_id);
void periodicDataReport(float timer, long ric_req_id);
