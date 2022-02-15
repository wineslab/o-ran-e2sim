#include "bs_connector.hpp"
#include "encode_e2apv1.hpp"

extern "C" {
  #include "csv_reader.h"
}

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

  char* payload = NULL;
  E2AP_PDU *e2ap_pdu = (E2AP_PDU*)calloc(1,sizeof(E2AP_PDU));
  
  if (DEBUG) {
    fprintf(stderr, "DEBUG mode\n");
    payload = (char*) "0,1,2,3,4,5\n1,6,7,8,9,10\n2,11,12,13,14,15";
  }
  else {
    get_tx_string(&payload, LINES_TO_READ);
  }

  // send PDU
  if (payload) {
    fprintf(stderr, "Sending\n%s\n", payload);
    fprintf(stderr, "Encoding RIC Indication Report\n");
    encoding::generate_e2apv1_indication_report(e2ap_pdu, payload, strlen(payload), ric_req_id[0], 0, 0, 0);
    fprintf(stderr, "RIC Indication Report successfully encoded\n");
    e2sim->encode_and_send_sctp_data(e2ap_pdu);
  }
  
  std::chrono::seconds sleep_duration(timer[0]);
  std::this_thread::sleep_for(sleep_duration);

  if (report_data_nrt_ric) {
    periodicDataReport(e2sim, timer, ric_req_id);
  }
}


// log message on file
void log_message(char* message, char* message_type, int len) {

  FILE *fp;
  char filename[100] = "/logs/du_l2.log";

  char buffer[26];
  int millisec;
  struct tm* tm_info;
  struct timeval tv;

  gettimeofday(&tv, NULL);

  millisec = lrint(tv.tv_usec/1000.0);  // Round to nearest millisec
  if (millisec>=1000) {  // Allow for rounding up to nearest second
    millisec -=1000;
    tv.tv_sec++;
  }

  tm_info = localtime(&tv.tv_sec);

  strftime(buffer, 26, "%Y:%m:%d %H:%M:%S", tm_info);

  fp = fopen(filename, "a+");

  if (fp == NULL) {
    printf("ERROR: fp is NULL\n");
    return;
  }

  const int msg_len = len;
  char msg_copy[msg_len];
  strcpy(msg_copy, message);

  for (int i = 0; i < msg_len; i++)
  {
    if (message[i] == '\n') {
       msg_copy[i] = 'n';
    }
  }

  // print to console and log on file
  printf("%s,%03d\t%s\t%d\t%s\n", buffer, millisec, message_type, len, msg_copy);
  fprintf(fp, "%s,%03d\t%s\t%d\t%s\n", buffer, millisec, message_type, len, msg_copy);

  fclose(fp);
}


// terminate periodic thread that reports data to near real-time RIC
void stop_data_reporting_nrt_ric(void) {
  printf("Terminating data reporting to non real-time RIC\n");
  report_data_nrt_ric = 0;
}
