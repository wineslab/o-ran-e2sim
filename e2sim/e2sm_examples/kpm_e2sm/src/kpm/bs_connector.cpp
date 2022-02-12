#include "bs_connector.hpp"

int report_data_nrt_ric = 1;

// handle timer got from RIC Subscription Request
// timer is in seconds
void handleTimer(int timer, long ric_req_id) {

  fprintf(stderr, "Handle timer %f seconds, ricReqId %ld\n", timer, ric_req_id);

  // // populate thread arguments
  // thread_args *t_args = (thread_args*) calloc(1, sizeof(thread_args));
  // t_args->timer = timer;
  // t_args->ric_req_id = ric_req_id;

  // start thread
  report_data_nrt_ric = 1;
  std::thread t1(periodicDataReport, timer, ric_req_id);

  fprintf(stderr, "periodicDataReport thread created successfully\n");
}


// function to periodically report data
void periodicDataReport(int timer, long ric_req_id) {

  fprintf(stderr, "timer expired, timer_deref %f\n", timer);
  fprintf(stderr, "ricReqId %ld\n", ric_req_id);
  
  if (DEBUG) {
    // debug
    std::string payload = "0,1,2,3,4,5\n1,6,7,8,9,10\n2,11,12,13,14,15";
    fprintf(stderr, "Debug mode, sending %s\n", payload);

    // to send timer as payload
    //char *payload = NULL;
    //asprintf(&payload, "%g", timer_deref);

    // BuildAndSendRicIndicationReport(payload, strlen(payload), ric_req_id_deref);
  }
  // else {
  //   sendMetricsXapp(ric_req_id_deref);
  // }

  std::chrono::seconds sleep_duration(timer);
  std::this_thread::sleep_for(sleep_duration);

  if (report_data_nrt_ric) {
    periodicDataReport(timer, ric_req_id);
  }
}
