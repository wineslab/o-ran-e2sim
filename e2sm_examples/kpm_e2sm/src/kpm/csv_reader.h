#ifndef __CSV_READER_H__
#define __CSV_READER_H__

#include <stdio.h>
#include <inttypes.h>

#define DELTA_TS_S 2
#define MAX_BUF_SIZE 1024

// set to -1 to disable (it was 300 before). This check shouldn't be necessary anymore in the RIC E release
#define MAX_REPORT_PAYLOAD -1

// format report metrics as json string
#define JSON_FORMAT 1

#define METRICS_DIR "/root/radio_code/scope_config/metrics/csv/"
// #define METRICS_DIR "./test_csv/"

#define METRICS_PRESET 1
#define CSV_DEBUG 0

enum ReportMetrics {
  TS = 0,                 // timestamp
  UE_NUM = 1,             // num_ues
  IMSI = 2,               // imsi
  RNTI = 3,               // rnti
  SL_EN = 4,              // slicing_enabled
  SL_ID = 5,              // slice_id
  SL_PRB = 6,             // slice_prb
  POW_MULT = 7,           // power_multiplier
  SCHED_POL = 8,          // scheduling_policy
  DL_MCS = 9,             // dl_mcs
  DL_SAM = 10,            // dl_n_samples
  DL_BYTES = 11,          // dl_buffer_bytes
  DL_THR = 12,            // tx_brate_downlink_Mbps
  DL_PKTS = 13,           // tx_pkts_downlink
  DL_ERR = 14,            // tx_errors_downlink_perc
  DL_CQI = 15,            // dl_cqi
  UL_MCS = 16,            // ul_mcs
  UL_SAM = 17,            // ul_n_samples
  UL_BYTES = 18,              // ul_buffer_bytes
  UL_THR = 19,            // rx_brate_downlink_Mbps
  UL_PKTS = 20,           // rx_pkts_downlink
  UL_ERR = 21,            // rx_errors_downlink_perc
  UL_RSSI = 22,           // ul_rssi
  UL_SINR = 23,           // ul_sinr
  PHR = 24,               // phr
  SUM_REQ_PRB = 25,       // sum_requested_prbs
  SUM_GRA_PRB = 26,       // sum_granted_prbs
  DL_PMI = 27,            // dl_pmi
  DL_RI = 28,             // dl_ri
  UL_N = 29,              // ul_n
  UL_TURBO_IT = 30,       // ul_turbo_iters
  RATIO_REQ_GRA_PRB = 31  // sum_granted_prbs / sum_requested_prbs, in [0, 1]
};

static const char * const metric_names[] = {
  [TS] = "timestamp",
  [UE_NUM] = "num_ue",
  [IMSI] = "imsi",
  [RNTI] = "rnti",
  [SL_EN] = "slicing_enabled",
  [SL_ID] = "slice_id",
  [SL_PRB] = "slice_prb",
  [POW_MULT] = "power_multiplier",
  [SCHED_POL] = "scheduling_policies",
  [DL_MCS] = "dl_mcs",
  [DL_SAM] = "dl_samples",
  [DL_BYTES] = "dl_bytes",
  [DL_THR] = "dl_thr_mbps",
  [DL_PKTS] = "dl_pkts",
  [DL_ERR] = "dl_errors",
  [DL_CQI] = "dl_cqi",
  [UL_MCS] = "ul_mcs",
  [UL_SAM] = "ul_samples",
  [UL_BYTES] = "ul_bytes",
  [UL_THR] = "ul_thr_mbps",
  [UL_PKTS] = "ul_pkts",
  [UL_ERR] = "ul_errors",
  [UL_RSSI] = "ul_rssi",
  [UL_SINR] = "ul_sinr",
  [PHR] = "phr",
  [SUM_REQ_PRB] = "sum_requested_prbs",
  [SUM_GRA_PRB] = "sum_granted_prbs",
  [DL_PMI] = "dl_pmi",
  [DL_RI] = "dl_ri",
  [UL_N] = "ul_n",
  [UL_TURBO_IT] = "ul_turbo_iterations",
  [RATIO_REQ_GRA_PRB] = "ratio_granted_req_prb"
};

// metrics structure
typedef struct bs_metrics {
  // configuration
  long unsigned int timestamp;
  int num_ues;
  long long unsigned int imsi;
  uint16_t rnti;
  uint8_t slicing_enabled;
  uint8_t slice_id;
  uint8_t slice_prb;
  float power_multiplier;
  uint8_t scheduling_policy;

  // downlink
  float dl_mcs;
  uint8_t dl_n_samples;
  uint32_t dl_buffer_bytes;
  double tx_brate_downlink_Mbps;
  uint16_t tx_pkts_downlink;
  float tx_errors_downlink_perc;
  float dl_cqi;

  // uplink
  float ul_mcs;
  uint8_t ul_n_samples;
  uint32_t ul_buffer_bytes;
  double rx_brate_downlink_Mbps;
  uint16_t rx_pkts_downlink;
  float rx_errors_downlink_perc;
  float ul_rssi;
  float ul_sinr;
  uint8_t phr;

  // prb
  uint16_t sum_requested_prbs;
  uint16_t sum_granted_prbs;

  // other
  uint8_t dl_pmi;
  uint8_t dl_ri;
  uint8_t ul_n;
  float ul_turbo_iters;
} bs_metrics_t;


void readMetrics(FILE *fp, bs_metrics_t *metrics);
void readMetricsInteactive(FILE *fp, char (*output_string)[MAX_BUF_SIZE], int metrics_preset, int json_format);
void readLastMetricsLines(char *file_name, int to_read, char **output_string, int skip_header, int json_format);
int getDirContent(char *directory_name, char (*dir_content)[MAX_BUF_SIZE]);
void get_tx_string(char **send_metrics, int lines_to_read);
unsigned long int get_time_milliseconds(void);
void remove_substr (char *string, char *sub);


#endif
