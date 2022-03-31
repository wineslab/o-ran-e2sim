#include "bs_connector.hpp"
#include "encode_e2apv1.hpp"
#include "encode_kpm.hpp"
#include "kpm_callbacks.hpp"

extern "C" {
  #include "csv_reader.h"
  #include "E2SM-KPM-IndicationMessage.h"
  #include "E2SM-KPM-RANfunction-Description.h"
  #include "E2SM-KPM-IndicationHeader-Format1.h"
  #include "E2SM-KPM-IndicationHeader.h"
  #include "Timestamp.h"
  #include "E2AP-PDU.h"
}

int report_data_nrt_ric = 1;

// handle timer got from RIC Subscription Request
// timer is in seconds
void handleTimer(E2Sim* e2sim, int* timer, long* ric_req_id, long* ric_instance_id,
  long* ran_function_id, long* action_id) {

  int seq_num = 1;

  fprintf(stderr, "Handle timer %d seconds, ricReqId %ld\n", timer[0], ric_req_id[0]);

  // // populate thread arguments
  // thread_args *t_args = (thread_args*) calloc(1, sizeof(thread_args));
  // t_args->timer = timer;
  // t_args->ric_req_id = ric_req_id;

  // start thread
  report_data_nrt_ric = 1;
  std::thread(periodicDataReport, e2sim, timer, seq_num, ric_req_id, ric_instance_id,
    ran_function_id, action_id).detach();

  fprintf(stderr, "periodicDataReport thread created successfully\n");
}


// function to periodically report data
void periodicDataReport(E2Sim* e2sim, int* timer, long seqNum, long* ric_req_id, long* ric_instance_id,
  long* ran_function_id, long* action_id) {

  long requestorId = ric_req_id[0];
  long instanceId = ric_instance_id[0];
  long ranFunctionId = ran_function_id[0];
  long actionId = action_id[0];

  fprintf(stderr, "timer expired for requestorId %ld, instanceId %ld, ranFunctionId %ld, actionId %ld: %d s\n",
    requestorId, instanceId, ranFunctionId, actionId, timer[0]);

  char* payload = NULL;
  // E2AP_PDU *e2ap_pdu = (E2AP_PDU*)calloc(1,sizeof(E2AP_PDU));
  
  if (DEBUG) {
    fprintf(stderr, "DEBUG mode\n");
    payload = (char*) "{\"timestamp\":1602706183796,\"slice_id\":0,\"dl_bytes\":53431,\"dl_thr_mbps\":2.39,\"ratio_granted_req_prb\":0.02,\"slice_prb\":6,\"dl_pkts\":200}";
  }
  else {
    get_tx_string(&payload, LINES_TO_READ);
  }

  // send PDU
  if (payload) {
    fprintf(stderr, "Sending\n%s\n", payload);
    fprintf(stderr, "Encoding RIC Indication Report\n");
    // encoding::generate_e2apv1_indication_report(e2ap_pdu, payload, strlen(payload), ric_req_id[0], 0, 0, 0);
    // fprintf(stderr, "RIC Indication Report successfully encoded\n");
    // e2sim->encode_and_send_sctp_data(e2ap_pdu);

    // ASN.1 encode payload and header
    encode_and_send_ric_indication_report_metrics_buffer(payload, seqNum, requestorId, instanceId, ranFunctionId, actionId);
    seqNum++;
  }
  
  std::chrono::seconds sleep_duration(timer[0]);
  std::this_thread::sleep_for(sleep_duration);

  // loop thread
  if (report_data_nrt_ric) {
    periodicDataReport(e2sim, timer, seqNum, ric_req_id, ric_instance_id, ran_function_id, action_id);
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
  printf("Terminating data reporting to near-real-time RIC\n");
  report_data_nrt_ric = 0;
}
