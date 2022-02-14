#include "bs_connector.hpp"
#include "encode_e2apv1.hpp"

int report_data_nrt_ric = 1;

// handle timer got from RIC Subscription Request
// timer is in seconds
void handleTimer(E2Sim* e2sim, int* timer, long* ric_req_id) {

  fprintf(stderr, "Handle timer %d seconds, ricReqId %ld\n", timer[0], ric_req_id[0]);

  // // populate thread arguments
  // thread_args *t_args = (thread_args*) calloc(1, sizeof(thread_args));
  // t_args->timer = timer;
  // t_args->ric_req_id = ric_req_id;

  // start thread
  report_data_nrt_ric = 1;
  std::thread (periodicDataReport, e2sim, timer, ric_req_id).detach();

  fprintf(stderr, "periodicDataReport thread created successfully\n");
}


// function to periodically report data
void periodicDataReport(E2Sim* e2sim, int* timer, long* ric_req_id) {

  fprintf(stderr, "timer expired for ric_req_id %ld: %d s\n", ric_req_id[0], timer[0]);

  E2AP_PDU *e2ap_pdu = (E2AP_PDU*)calloc(1,sizeof(E2AP_PDU));
  
  if (DEBUG) {
    // debug
    char* payload = "0,1,2,3,4,5\n1,6,7,8,9,10\n2,11,12,13,14,15";
    fprintf(stderr, "DEBUG mode, sending\n%s\n", payload);

    // to send timer as payload
    //char *payload = NULL;
    //asprintf(&payload, "%g", timer_deref);

    // BuildAndSendRicIndicationReport(payload, strlen(payload), ric_req_id_deref);

    fprintf(stderr, "Encoding RIC Indication Report\n");
    encoding::generate_e2apv1_indication_report(e2ap_pdu, payload, strlen(payload), ric_req_id[0], 0, 0, 0);
    fprintf(stderr, "RIC Indication Report successfully encoded\n");
  }
  // TODO: read metrics, encode and send
  // else {
  //   sendMetricsXapp(ric_req_id_deref);
  // }

  // send PDU
  e2sim->encode_and_send_sctp_data(e2ap_pdu);
  
  std::chrono::seconds sleep_duration(timer[0]);
  std::this_thread::sleep_for(sleep_duration);

  if (report_data_nrt_ric) {
    periodicDataReport(e2sim, timer, ric_req_id);
  }
}
