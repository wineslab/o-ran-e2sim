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
#include "e2ap_message_handler.hpp"
#include <unistd.h>

void e2ap_handle_sctp_data(int &socket_fd, sctp_buffer_t &data)
{
  //decode the data into E2AP-PDU
  E2AP_PDU_t* pdu = new E2AP_PDU_t();

  e2ap_asn1c_decode_pdu(pdu, data.buffer, data.len);

  e2ap_asn1c_print_pdu(pdu);

  int procedureCode = e2ap_asn1c_get_procedureCode(pdu);
  int index = (int)pdu->present;

  LOG_D("[E2AP] Unpacked E2AP-PDU: index = %d, procedureCode = %d\n",
                            index, procedureCode);

  switch(procedureCode)
  {
    case ProcedureCode_id_x2Setup: //X2Setup = 6
      switch(index)
      {
        case E2AP_PDU_PR_initiatingMessage: //initiatingMessage
          LOG_I("[E2AP] Received X2-SETUP-REQUEST");
          e2ap_handle_X2SetupRequest(pdu, socket_fd);
          break;

        case E2AP_PDU_PR_successfulOutcome: //successfulOutcome
          LOG_I("[E2AP] Received X2-SETUP-RESPONSE");
          e2ap_handle_X2SetupResponse(pdu, socket_fd);
          break;

        case E2AP_PDU_PR_unsuccessfulOutcome:
          break;

        default:
          LOG_E("[E2AP] Invalid message index=%d in E2AP-PDU", index);
          break;
      }
      break;

    case ProcedureCode_id_endcX2Setup: //ENDCX2Setup = 36
      switch(index)
      {
        case E2AP_PDU_PR_initiatingMessage: //initiatingMessage
          LOG_I("[E2AP] Received ENDC-X2-SETUP-REQUEST");
          e2ap_handle_ENDCX2SetupRequest(pdu, socket_fd);
          break;

        case E2AP_PDU_PR_successfulOutcome: //successfulOutcome
          LOG_I("[E2AP] Received ENDC-X2-SETUP-RESPONSE");
          //no handler yet
          break;

        case E2AP_PDU_PR_unsuccessfulOutcome:
          LOG_I("[E2AP] Received ENDC-X2-SETUP-FAILURE");
          //no handler yet
          break;

        default:
          LOG_E("[E2AP] Invalid message index=%d in E2AP-PDU", index);
          break;
      }
      break;

    case ProcedureCode_id_reset: //reset = 7
      switch(index)
      {
        case E2AP_PDU_PR_initiatingMessage:
          LOG_I("[E2AP] Received RESET-REQUEST");
          break;

        case E2AP_PDU_PR_successfulOutcome:
          break;

        case E2AP_PDU_PR_unsuccessfulOutcome:
          break;

        default:
          LOG_E("[E2AP] Invalid message index=%d in E2AP-PDU", index);
          break;
      }
      break;

    case ProcedureCode_id_ricSubscription: //RIC SUBSCRIPTION = 201
      switch(index)
      {
        case E2AP_PDU_PR_initiatingMessage: //initiatingMessage
          LOG_I("[E2AP] Received RIC-SUBSCRIPTION-REQUEST");
          //e2ap_handle_RICSubscriptionRequest(pdu, socket_fd);
          e2ap_handle_RICSubscriptionRequest_securityDemo(pdu, socket_fd);
          break;

        case E2AP_PDU_PR_successfulOutcome:
          LOG_I("[E2AP] Received RIC-SUBSCRIPTION-RESPONSE");
          break;

        case E2AP_PDU_PR_unsuccessfulOutcome:
          LOG_I("[E2AP] Received RIC-SUBSCRIPTION-FAILURE");
          break;

        default:
          LOG_E("[E2AP] Invalid message index=%d in E2AP-PDU", index);
          break;
      }
      break;

    case ProcedureCode_id_ricIndication: // 205
      switch(index)
      {
        case E2AP_PDU_PR_initiatingMessage: //initiatingMessage
          LOG_I("[E2AP] Received RIC-INDICATION");
          // e2ap_handle_RICSubscriptionRequest(pdu, socket_fd);
          break;

        default:
          LOG_E("[E2AP] Invalid message index=%d in E2AP-PDU %d", index,
                                    (int)ProcedureCode_id_ricIndication);
          break;
      }
      break;

    case ProcedureCode_id_resourceStatusReportingInitiation: //9
      switch(index)
      {
        case E2AP_PDU_PR_initiatingMessage: //initiatingMessage
          LOG_I("[E2AP] Received RESOURCE-STATUS-REQUEST");
          e2ap_handle_ResourceStatusRequest(pdu, socket_fd);
          break;

        case E2AP_PDU_PR_successfulOutcome: //successfulOutcome
          LOG_I("[E2AP] Received RESOURCE-STATUS-RESPONSE");
          break;

        case E2AP_PDU_PR_unsuccessfulOutcome:
          LOG_I("[E2AP] Received RESOURCE-STATUS-FAILURE");
          break;

        default:
          LOG_E("[E2AP] Invalid message index=%d in E2AP-PDU %d", index,
                    (int)ProcedureCode_id_resourceStatusReportingInitiation);
          break;
      }
      break;

    case ProcedureCode_id_resourceStatusReporting: // 10
      switch(index)
      {
        case E2AP_PDU_PR_initiatingMessage: //initiatingMessage
          LOG_I("[E2AP] Received RESOURCE-STATUS-UPDATE");
          break;

        default:
          LOG_E("[E2AP] Unable to process message index=%d in E2AP-PDU %d", index,
                    (int)ProcedureCode_id_resourceStatusReporting);
          break;
      }
      break;

    default:
      LOG_E("[E2AP] No available handler for procedureCode=%d", procedureCode);
      break;
  }
}

/*
Simply send back X2SetupResponse
Todo: add more handling options (failure, duplicated request, etc.)
*/
void e2ap_handle_X2SetupRequest(E2AP_PDU_t* pdu, int &socket_fd)
{
  E2AP_PDU_t* res_pdu = e2ap_xml_to_pdu("E2AP_X2SetupResponse.xml");

  LOG_D("[E2AP] Created X2-SETUP-RESPONSE");

  e2ap_asn1c_print_pdu(res_pdu);

  uint8_t       *buf;
  sctp_buffer_t data;

  data.len = e2ap_asn1c_encode_pdu(res_pdu, &buf);
  memcpy(data.buffer, buf, min(data.len, MAX_SCTP_BUFFER));

  //send response data over sctp
  if(sctp_send_data(socket_fd, data) > 0) {
    LOG_I("[SCTP] Sent X2-SETUP-RESPONSE");
  } else {
    LOG_E("[SCTP] Unable to send X2-SETUP-RESPONSE to peer");
  }
}

void e2ap_handle_X2SetupResponse(E2AP_PDU_t* pdu, int &socket_fd)
{
  E2AP_PDU_t* req_pdu = e2ap_xml_to_pdu("E2AP_ResourceStatusRequest.xml");
  // E2AP_PDU_t* req_pdu = e2ap_xml_to_pdu("E2AP_ResourceStatusRequest_bad.xml");

  LOG_D("[E2AP] Created RESOURCE-STATUS-REQUEST");

  e2ap_asn1c_print_pdu(req_pdu);

  uint8_t       *buf;
  sctp_buffer_t data;

  data.len = e2ap_asn1c_encode_pdu(req_pdu, &buf);
  memcpy(data.buffer, buf, min(data.len, MAX_SCTP_BUFFER));

  //send response data over sctp
  if(sctp_send_data(socket_fd, data) > 0) {
    LOG_I("[SCTP] Sent RESOURCE-STATUS-REQUEST");
  } else {
    LOG_E("[SCTP] Unable to send RESOURCE-STATUS-REQUEST to peer");
  }

}

/*
Simply send back ENDCX2SetupResponse
Todo: add more handling options (failure, duplicated request, etc.)
*/
void e2ap_handle_ENDCX2SetupRequest(E2AP_PDU_t* pdu, int &socket_fd)
{
  E2AP_PDU_t* res_pdu = e2ap_xml_to_pdu("E2AP_ENDCX2SetupResponse.xml");

  LOG_D("[E2AP] Created ENDC-X2-SETUP-RESPONSE");

  e2ap_asn1c_print_pdu(res_pdu);

  uint8_t       *buf;
  sctp_buffer_t data;

  data.len = e2ap_asn1c_encode_pdu(res_pdu, &buf);
  memcpy(data.buffer, buf, min(data.len, MAX_SCTP_BUFFER));

  //send response data over sctp
  if(sctp_send_data(socket_fd, data) > 0) {
    LOG_I("[SCTP] Sent ENDC-X2-SETUP-RESPONSE");
  } else {
    LOG_E("[SCTP] Unable to send ENDC-X2-SETUP-RESPONSE to peer");
  }
}

/*
Simply send back hard-coded RICSubscriptionResponse
Todo: add more handling options (failure, duplicated request, etc.)
*/
void e2ap_handle_RICSubscriptionRequest(E2AP_PDU_t* pdu, int &socket_fd)
{
  E2AP_PDU_t* res_pdu = e2ap_xml_to_pdu("E2AP_RICsubscriptionResponse.xml");

  LOG_D("[E2AP] Created RIC-SUBSCRIPTION-RESPONSE");

  e2ap_asn1c_print_pdu(res_pdu);

  uint8_t       *buf;
  sctp_buffer_t data;

  data.len = e2ap_asn1c_encode_pdu(res_pdu, &buf);
  memcpy(data.buffer, buf, min(data.len, MAX_SCTP_BUFFER));

  //send response data over sctp
  if(sctp_send_data(socket_fd, data) > 0) {
    LOG_I("[SCTP] Sent RIC-SUBSCRIPTION-RESPONSE");
  } else {
    LOG_E("[SCTP] Unable to send RIC-SUBSCRIPTION-RESPONSE to peer");
  }
}

void e2ap_handle_RICSubscriptionRequest_securityDemo(E2AP_PDU_t* pdu, int &socket_fd)
{
  E2AP_PDU_t* res_pdu = e2ap_xml_to_pdu("E2AP_RICsubscriptionResponse.xml");

  LOG_D("[E2AP] Created RIC-SUBSCRIPTION-RESPONSE");

  e2ap_asn1c_print_pdu(res_pdu);

  uint8_t       *buf;
  sctp_buffer_t data;

  data.len = e2ap_asn1c_encode_pdu(res_pdu, &buf);
  memcpy(data.buffer, buf, min(data.len, MAX_SCTP_BUFFER));

  //send response data over sctp
  if(sctp_send_data(socket_fd, data) > 0) {
    LOG_I("[SCTP] Sent RIC-SUBSCRIPTION-RESPONSE");
  } else {
    LOG_E("[SCTP] Unable to send RIC-SUBSCRIPTION-RESPONSE to peer");
  }

  //Start sending RIC Indication
  int count1 = 0, count2 = 0;

  E2AP_PDU_t* indication_type1 = e2ap_xml_to_pdu("E2AP_RICindication_type1.xml");
  E2AP_PDU_t* indication_type2 = e2ap_xml_to_pdu("E2AP_RICindication_type2.xml");

  uint8_t *buf1, *buf2;
  sctp_buffer_t data1, data2;
  data1.len = e2ap_asn1c_encode_pdu(indication_type1, &buf1);
  memcpy(data1.buffer, buf1, min(data1.len, MAX_SCTP_BUFFER));

  data2.len = e2ap_asn1c_encode_pdu(indication_type2, &buf2);
  memcpy(data2.buffer, buf2, min(data2.len, MAX_SCTP_BUFFER));

  while(1){
    sleep(1);
    //type1
    if(sctp_send_data(socket_fd, data1) > 0) {
      count1++;
      LOG_I("[SCTP] Sent RIC-INDICATION SgNBAdditionRequest Type 1, count1 = %d", count1);
    } else {
      LOG_E("[SCTP] Unable to send RIC-INDICATION to peer");
    }

    sleep(1);
    //type2
    if(sctp_send_data(socket_fd, data2) > 0) {
      count2++;
      LOG_I("[SCTP] Sent RIC-INDICATION SgNBAdditionRequest Type 2, count2 = %d", count2);
    } else {
      LOG_E("[SCTP] Unable to send RIC-INDICATION to peer");
    }
  } //end while

}

void e2ap_handle_ResourceStatusRequest(E2AP_PDU_t* pdu, int &socket_fd)
{
  //send back ResourceStatusResponse, followed by resource status update
  E2AP_PDU_t* res_pdu = e2ap_xml_to_pdu("E2AP_ResourceStatusResponse.xml");

  LOG_D("[E2AP] Created RESOURCE-STATUS-RESPONSE");

  e2ap_asn1c_print_pdu(res_pdu);

  uint8_t       *buf;
  sctp_buffer_t data;

  data.len = e2ap_asn1c_encode_pdu(res_pdu, &buf);
  memcpy(data.buffer, buf, min(data.len, MAX_SCTP_BUFFER));

  //send response data over sctp
  if(sctp_send_data(socket_fd, data) > 0) {
    LOG_I("[SCTP] Sent RESOURCE-STATUS-RESPONSE");
  } else {
    LOG_E("[SCTP] Unable to send RESOURCE-STATUS-RESPONSE to peer");
  }


  //send ResourceStatusUpdate periodically
  E2AP_PDU_t* update_pdu = e2ap_xml_to_pdu("E2AP_ResourceStatusUpdate.xml");

  uint8_t       *update_buf;
  sctp_buffer_t update_data;

  update_data.len = e2ap_asn1c_encode_pdu(update_pdu, &update_buf);
  memcpy(update_data.buffer, update_buf, min(update_data.len, MAX_SCTP_BUFFER));

  while(1) {
    // e2ap_asn1c_print_pdu(update_pdu);

    if(sctp_send_data(socket_fd, update_data) > 0) {
      LOG_I("[SCTP] Sent RESOURCE-STATUS-UPDATE");
    } else {
      LOG_E("[SCTP] Unable to send RESOURCE-STATUS-UPDATE to peer");
    }

    sleep(1);

  }
}
