/*****************************************************************************
#                                                                            *
# Copyright 2019 AT&T Intellectual Property                                  *
# Copyright 2019 Nokia                                                       *
#                                                                            *
# Licensed under the Apache License, Version 2.0 (the "License");            *
# you may not use this file except in compliance with the License.           *
# You may obtain a copy of the License at                                    *
#                                                                            *
#      http://www.apache.org/licenses/LICENSE-2.0                            *
#                                                                            *
# Unless required by applicable law or agreed to in writing, software        *
# distributed under the License is distributed on an "AS IS" BASIS,          *
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
# See the License for the specific language governing permissions and        *
# limitations under the License.                                             *
#                                                                            *
******************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>


#include "e2sim_defs.h"
#include "e2sim_sctp.hpp"
#include "e2ap_message_handler.hpp"
#include "encode_e2apv1.hpp"

using namespace std;

int client_fd = 0;

void encode_and_send_sctp_data(E2AP_PDU_t* pdu)
{
  uint8_t       *buf;
  sctp_buffer_t data;

  data.len = e2ap_asn1c_encode_pdu(pdu, &buf);
  memcpy(data.buffer, buf, min(data.len, MAX_SCTP_BUFFER));

  sctp_send_data(client_fd, data);
}

void encode_and_send_sctp_data(E2AP_PDU_t* pdu, int client_fd)
{
  uint8_t       *buf;
  sctp_buffer_t data;

  printf("Calling encode_and_send_sctp_data\n");

  printf("client_fd is %d\n", client_fd);

  data.len = e2ap_asn1c_encode_pdu(pdu, &buf);

  printf("after encoding pdu\n");

  memcpy(data.buffer, buf, min(data.len, MAX_SCTP_BUFFER));

  printf("calling sctp_send_data\n");

  sctp_send_data(client_fd, data);
}

void wait_for_sctp_data()
{
  sctp_buffer_t recv_buf;
  if(sctp_receive_data(client_fd, recv_buf) > 0)
  {
    LOG_I("[SCTP] Received new data of size %d", recv_buf.len);
    e2ap_handle_sctp_data(client_fd, recv_buf, false);
  }
}


int main(int argc, char* argv[]){

  printf("Start E2 Agent (E2 Simulator\n");

  ifstream simfile;
  string line;

  simfile.open("simulation.txt", ios::in);

  if (simfile.is_open()) {

    while (getline(simfile, line)) {
      cout << line << "\n";
    }

    simfile.close();

  }
  

  printf("encoding now the user level - DU\n");

  E2SM_KPM_IndicationMessage_t *indMsg =
    (E2SM_KPM_IndicationMessage_t*)calloc(1,sizeof(E2SM_KPM_IndicationMessage_t));

  //encode_kpm_report_rancontainer_du(indMsg);
  encode_kpm_report_style1(indMsg);

  

  bool xmlenc = false;

  options_t ops = read_input_options(argc, argv);

  printf("After reading input options\n");

  //E2 Agent will automatically restart upon sctp disconnection
  //  int server_fd = sctp_start_server(ops.server_ip, ops.server_port);

  client_fd = sctp_start_client(ops.server_ip, ops.server_port);
  E2AP_PDU_t* pdu_setup = (E2AP_PDU_t*)calloc(1,sizeof(E2AP_PDU));

  printf("After starting client\n");
  printf("client_fd value is %d\n", client_fd);
  
  //  generate_e2apv1_subscription_request(pdu_setup);
  generate_e2apv1_setup_request(pdu_setup);

  printf("After generating e2setup req\n");  

  xer_fprint(stderr, &asn_DEF_E2AP_PDU, pdu_setup);

  printf("After XER Encoding\n");

  auto buffer_size = MAX_SCTP_BUFFER;
  unsigned char buffer[MAX_SCTP_BUFFER];
  
  sctp_buffer_t data;

  char *error_buf = (char*)calloc(300, sizeof(char));
  size_t errlen;

  asn_check_constraints(&asn_DEF_E2AP_PDU, pdu_setup, error_buf, &errlen);
  printf("error length %d\n", errlen);
  printf("error buf %s\n", error_buf);

  auto er = asn_encode_to_buffer(nullptr, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2AP_PDU, pdu_setup, buffer, buffer_size);
  //auto er = asn_encode_to_buffer(nullptr, ATS_BASIC_XER, &asn_DEF_E2AP_PDU, pdu_setup, buffer, buffer_size);
  data.len = er.encoded;

  fprintf(stderr, "er encded is %d\n", er.encoded);

  memcpy(data.buffer, buffer, er.encoded);

  if(sctp_send_data(client_fd, data) > 0) {
    LOG_I("[SCTP] Sent E2-SETUP-REQUEST");
  } else {
    LOG_E("[SCTP] Unable to send E2-SETUP-REQUEST to peer");
  }

  sctp_buffer_t recv_buf;

  LOG_I("[SCTP] Waiting for SCTP data");

  while(1) //constantly looking for data on SCTP interface
  {
    if(sctp_receive_data(client_fd, recv_buf) <= 0)
      break;

    LOG_I("[SCTP] Received new data of size %d", recv_buf.len);

    e2ap_handle_sctp_data(client_fd, recv_buf, xmlenc);
    if (xmlenc) xmlenc = false;
  }

  return 0;
}
