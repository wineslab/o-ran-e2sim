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
#include <assert.h>

#include "e2sim_sctp.hpp"
#include "e2ap_message_handler.hpp"

extern "C" {
  #include "e2sim_defs.h"
  #include "E2AP-PDU.h"
  #include "e2ap_asn1c_codec.h"
}

using namespace std;

void encode_and_send_sctp_data(E2AP_PDU_t* pdu, int client_fd)
{
  uint8_t       *buf;
  sctp_buffer_t data;

  data.len = e2ap_asn1c_encode_pdu(pdu, &buf);
  memcpy(data.buffer, buf, min(data.len, MAX_SCTP_BUFFER));

  sctp_send_data(client_fd, data);
}

void wait_for_sctp_data(int client_fd)
{
  sctp_buffer_t recv_buf;
  if(sctp_receive_data(client_fd, recv_buf) > 0)
  {
    LOG_I("[SCTP] Received new data of size %d", recv_buf.len);
    e2ap_handle_sctp_data(client_fd, recv_buf);
  }
}

int main(int argc, char* argv[]){
  LOG_I("Start RIC Simulator");

  options_t ops = read_input_options(argc, argv);
  int client_fd = sctp_start_client(ops.server_ip, ops.server_port);

  //1. Send ENDCX2Setup
  E2AP_PDU_t* pdu_setup = e2ap_xml_to_pdu("E2AP_ENDCX2SetupRequest.xml");
  e2ap_asn1c_print_pdu(pdu_setup);
  encode_and_send_sctp_data(pdu_setup, client_fd);
  LOG_I("[SCTP] Sent ENDC X2 SETUP REQUEST");

  //2. Receive ENDCX2SetupResponse
  wait_for_sctp_data(client_fd);

  //3. Send RICSubscriptionRequest
  E2AP_PDU_t* pdu_sub = e2ap_xml_to_pdu("E2AP_RICsubscriptionRequest_Ashwin.xml");
  e2ap_asn1c_print_pdu(pdu_sub);
  encode_and_send_sctp_data(pdu_sub, client_fd);
  LOG_I("[SCTP] Sent RIC SUBSCRIPTION REQUEST");

  //4. Receive RICSubscriptionResponse
  while(1){
    wait_for_sctp_data(client_fd);
  }


  //---------------------------------------
  close(client_fd);
  LOG_I("[SCTP] Connection closed.");

  return 0;

}
