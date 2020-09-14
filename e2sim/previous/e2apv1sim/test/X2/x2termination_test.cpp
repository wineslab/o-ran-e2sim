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
#include <string>
#include <iostream>

#include "e2sim_defs.h"
#include "asn_x2ap.hpp"
#include "e2sim_sctp.hpp"
#include "x2ap_message_handler.hpp"
#include "x2ap_asn_codec.hpp"

using namespace std;

void test_X2Setup(int &client_fd)
{
  //Create X2SetupRequest message
  x2ap_pdu_t* pdu = new_x2ap_pdu();
  eNB_config cfg;

  x2ap_create_X2SetupRequest(pdu, cfg);
  x2ap_print_pdu(pdu);

  //Encode into buffer
  sctp_buffer_t data;
  x2ap_encode_pdu(pdu, data.buffer, sizeof(data.buffer), data.len);

  //Send to sctp
  sctp_send_data(client_fd, data);
  LOG_I("[SCTP] Sent X2 SETUP REQUEST");

  //expect X2 SETUP RESPONSE
  sctp_buffer_t recv_buf;
  if(sctp_receive_data(client_fd, recv_buf) > 0)
  {
    LOG_I("[SCTP] Received new data of size %d", recv_buf.len);
    x2ap_handle_sctp_data(client_fd, recv_buf);
  }

  //Send again, expect X2 SETUP FAILURE
  sctp_send_data(client_fd, data);
  LOG_I("[SCTP] Sent X2 SETUP REQUEST");

  if(sctp_receive_data(client_fd, recv_buf) > 0)
  {
    LOG_I("[SCTP] Received new data of size %d", recv_buf.len);
    x2ap_handle_sctp_data(client_fd, recv_buf);
  }

}

void test_ENDCX2Setup(int &client_fd)
{
  //Create ENDCX2SetupRequest message
  x2ap_pdu_t* pdu = new_x2ap_pdu();
  eNB_config cfg;

  x2ap_create_ENDCX2SetupRequest(pdu, cfg);
  x2ap_print_pdu(pdu);

  //Encode into buffer
  sctp_buffer_t data;
  x2ap_encode_pdu(pdu, data.buffer, sizeof(data.buffer), data.len);

  //Send to sctp
  sctp_send_data(client_fd, data);
  LOG_I("[SCTP] Sent ENDC X2 SETUP REQUEST");

  //expect ENDC X2 SETUP RESPONSE
  sctp_buffer_t recv_buf;
  if(sctp_receive_data(client_fd, recv_buf) > 0)
  {
    LOG_I("[SCTP] Received new data of size %d", recv_buf.len);
    x2ap_handle_sctp_data(client_fd, recv_buf);
  }

  //Send again, expect ENDC X2 SETUP FAILURE
  sctp_send_data(client_fd, data);
  LOG_I("[SCTP] Sent ENDC X2 SETUP REQUEST");

  if(sctp_receive_data(client_fd, recv_buf) > 0)
  {
    LOG_I("[SCTP] Received new data of size %d", recv_buf.len);
    x2ap_handle_sctp_data(client_fd, recv_buf);
  }

}

int main(int argc, char* argv[]){

  LOG_I("X2 Termination Test");

  options_t ops = read_input_options(argc, argv);

  int client_fd = sctp_start_client(ops.server_ip, ops.server_port);

  test_X2Setup(client_fd);
  // test_ENDCX2Setup(client_fd);


  return 0;
}
