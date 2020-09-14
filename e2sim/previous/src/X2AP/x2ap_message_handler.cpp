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
#include "x2ap_message_handler.hpp"


void x2ap_handle_sctp_data(int &socket_fd, sctp_buffer_t &data)
{
  //decode the data into X2AP-PDU
  x2ap_pdu_t* pdu = new_x2ap_pdu();

  x2ap_decode_pdu(pdu, data.buffer, data.len);

  x2ap_print_pdu(pdu);

  int index = x2ap_get_index(pdu);
  int procedureCode = x2ap_get_procedureCode(pdu);

  switch(procedureCode)
  {
    case 6: //X2Setup
      switch(index)
      {
        case 1: //initiatingMessage
          LOG_D("[X2AP] Received X2 SETUP REQUEST");
          x2ap_handle_X2SetupRequest(pdu, socket_fd);
          break;

        case 2: //successfulOutcome
          LOG_D("[X2AP] Received X2 SETUP RESPONSE");
          //x2ap_handle_X2SetupResponse(pdu, socket_fd);
          break;

        case 3:
          LOG_D("[X2AP] Received X2 SETUP FAILURE");
          break;

        default:
          LOG_E("[X2AP] Invalid message index=%d in X2AP-PDU", index);
          break;
      }
      break;

    case 36: //ENDCX2Setup
      switch(index)
      {
        case 1: //initiatingMessage
          LOG_D("[X2AP] Received ENDC X2 SETUP REQUEST");
          x2ap_handle_ENDCX2SetupRequest(pdu, socket_fd);
          break;

        case 2: //successfulOutcome
          LOG_D("[X2AP] Received ENDC X2 SETUP RESPONSE");
          //x2ap_handle_X2SetupResponse(pdu, socket_fd);
          break;

        case 3:
          LOG_D("[X2AP] Received ENDC X2 SETUP FAILURE");
          break;

        default:
          LOG_E("[X2AP] Invalid message index=%d in X2AP-PDU", index);
          break;
      }
      break;

    default:
      LOG_E("[X2AP] No available handler for procedureCode=%d", procedureCode);
      break;
  }
}

void x2ap_handle_X2SetupRequest(x2ap_pdu_t* pdu, int &socket_fd)
{
  /*
  Simply send back X2SetupResponse
  Todo: add more handling options (failure, duplicated request, etc.)
  */

  x2ap_pdu_t* res_pdu = new_x2ap_pdu();
  eNB_config cfg;

  x2ap_create_X2SetupResponse(res_pdu, cfg);
  LOG_D("[X2AP] Created X2 SETUP RESPONSE")

  x2ap_print_pdu(res_pdu);

  //encode response pdu into buffer
  sctp_buffer_t res_data;
  x2ap_encode_pdu(res_pdu, res_data.buffer, sizeof(res_data.buffer), res_data.len);

  //send response data over sctp
  if(sctp_send_data(socket_fd, res_data) > 0) {
    LOG_D("[SCTP] Sent X2 SETUP RESPONSE");
  } else {
    LOG_D("[SCTP] Unable to send X2 SETUP RESPONSE to peer");
  }
}

void x2ap_handle_X2SetupResponse(x2ap_pdu_t* pdu, int &socket_fd)
{
  ;
}


void x2ap_handle_ENDCX2SetupRequest(x2ap_pdu_t* pdu, int &socket_fd)
{
  /*
  Simply send back ENDCX2SetupResponse
  Todo: add more handling options (failure, duplicated request, etc.)
  */
  ;
}
