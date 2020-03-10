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


#include "e2sim_defs.h"
#include "asn_e2ap.hpp"
#include "e2sim_sctp.hpp"
#include "e2ap_message_handler.hpp"
#include "e2ap_asn_codec.hpp"

using namespace std;

void test_send_X2Setup(int &client_fd)
{
    //Create X2SetupRequest message
    e2ap_pdu_t* pdu = new_e2ap_pdu();
    eNB_config cfg;

    e2ap_create_X2SetupRequest(pdu, cfg);
    e2ap_print_pdu(pdu);

    //Encode into buffer
    sctp_buffer_t data;
    e2ap_encode_pdu(pdu, data.buffer, sizeof(data.buffer), data.len);

    //Send to sctp
    sctp_send_data(client_fd, data);
    LOG_I("[SCTP] Sent X2 SETUP REQUEST");

    //wait to receive response
    sctp_buffer_t recv_buf;
    if(sctp_receive_data(client_fd, recv_buf) > 0)
    {
      LOG_I("[SCTP] Received new data of size %d", recv_buf.len);
      e2ap_handle_sctp_data(client_fd, recv_buf);
    }

  }

void test_send_ENDCX2Setup(int &client_fd)
{
  //Create ENDCX2SetupRequest message
  e2ap_pdu_t* pdu = new_e2ap_pdu();
  eNB_config cfg;

  e2ap_create_ENDCX2SetupRequest(pdu, cfg);
  e2ap_print_pdu(pdu);

  //Encode into buffer
  sctp_buffer_t data;
  e2ap_encode_pdu(pdu, data.buffer, sizeof(data.buffer), data.len);

  //Send to sctp
  sctp_send_data(client_fd, data);
  LOG_I("[SCTP] Sent ENDC X2 SETUP REQUEST");

  //wait to receive response
  sctp_buffer_t recv_buf;
  if(sctp_receive_data(client_fd, recv_buf) > 0)
  {
    LOG_I("[SCTP] Received new data of size %d", recv_buf.len);
    e2ap_handle_sctp_data(client_fd, recv_buf);
  }

}

void test_send_RICSubscriptionRequest(int &client_fd)
{
  LOG_I("Test RIC SUBSCRIPTION");

  /* Create RIC SUBSCRITION REQUEST */
  e2ap_pdu_t* pdu = new_e2ap_pdu();

  RICsubscription_params_t params;
  params.request_id = 2;
  params.seq_number = 200;
  params.ran_func_id = 0;
  params.event_trigger_def = "hello world";

  RIC_action_t action1(1, RICactionType_report);
  // RIC_action_t action2(3, RICactionType_insert);
  // RIC_action_t action3(5, RICactionType_insert);
  // RIC_action_t action4(7, RICactionType_insert);
  params.actionList.push_back(action1);
  // params.actionList.push_back(action2);
  // params.actionList.push_back(action3);
  // params.actionList.push_back(action4);

  e2ap_create_RICsubscriptionRequest(pdu, params);
  e2ap_print_pdu(pdu);

  //Encode into buffer
  sctp_buffer_t data;
  e2ap_encode_pdu(pdu, data.buffer, sizeof(data.buffer), data.len);

  //Send to sctp
  sctp_send_data(client_fd, data);
  LOG_I("[SCTP] Sent RIC SUBSCRIPTION REQUEST");

  //wait to receive response and indication (if any)
  sctp_buffer_t recv_buf;
  LOG_I("[SCTP] Waiting for SCTP data");
  while(1)
  {
    if(sctp_receive_data(client_fd, recv_buf) > 0)
    {
      LOG_I("[SCTP] Received new data of size %d", recv_buf.len);
      e2ap_handle_sctp_data(client_fd, recv_buf);
    }
    else
      break;

  }


  return;
  //==========================================================================

  //decode
  e2ap_pdu_t* pdu2 = new_e2ap_pdu();

  e2ap_decode_pdu(pdu2, data.buffer, data.len);

  RICsubscription_params_t params2;
  e2ap_parse_RICsubscriptionRequest(pdu2, params2);
  printf("request_id = %d\n", params2.request_id);
  printf("seq_number = %d\n", params2.seq_number);
  printf("ran_func_id = %d\n", params2.ran_func_id);
  printf("event = %s\n", &params2.event_trigger_def[0]);

  for( auto const  &a : params.actionList)
  {
    printf("action id = %d, action type = %d\n", (int)a.action_id, (int)a.action_type);
  }


  LOG_I("================= RESPONSE ===========================");
  for(size_t i = 0; i < params2.actionList.size(); i++)
  {
    //example logic: admit every other action
    if(i%2 == 0) {
      params2.actionList[i].isAdmitted = true;
    } else {
      params2.actionList[i].isAdmitted = false;
      params2.actionList[i].notAdmitted_cause = RICcause_radioNetwork;
      params2.actionList[i].notAdmitted_subCause = 5;
    }
  }

  e2ap_pdu_t* res_pdu = new_e2ap_pdu();
  e2ap_create_RICsubscriptionResponse(res_pdu, params2);

  e2ap_print_pdu(res_pdu);

  //Encode into buffer
  sctp_buffer_t data_resp;
  e2ap_encode_pdu(res_pdu, data_resp.buffer, sizeof(data_resp.buffer), data_resp.len);

  LOG_I("================= FAILURE ===========================");
  e2ap_pdu_t* fail_pdu = new_e2ap_pdu();

  RICsubscription_params_t params3;
  e2ap_parse_RICsubscriptionRequest(pdu2, params3);

  for(size_t i = 0; i < params3.actionList.size(); i++)
  {
    params3.actionList[i].isAdmitted = false;
    params3.actionList[i].notAdmitted_cause = RICcause_radioNetwork;
    params3.actionList[i].notAdmitted_subCause = 5;
  }

  e2ap_create_RICsubscriptionFailure(fail_pdu, params3);
  e2ap_print_pdu(fail_pdu);

  //Encode into buffer
  sctp_buffer_t data_fail;
  e2ap_encode_pdu(fail_pdu, data_fail.buffer, sizeof(data_fail.buffer), data_fail.len);

}

int main(int argc, char* argv[]){

  LOG_I("E2 Termination Test");

  // test_send_RICSubscriptionRequest();
  // return 0;

  options_t ops = read_input_options(argc, argv);
  int client_fd = sctp_start_client(ops.server_ip, ops.server_port);

  //---------------------------------------------------
  // test_send_X2Setup(client_fd);
  test_send_ENDCX2Setup(client_fd);
  test_send_RICSubscriptionRequest(client_fd);

  //---------------------------------------------------

  close(client_fd);
  LOG_I("[SCTP] Connection closed.");

  return 0;
}
