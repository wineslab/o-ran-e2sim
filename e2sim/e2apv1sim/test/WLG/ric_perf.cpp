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

  #include "ProtocolIE-Field.h"
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

void set_seqnum(E2AP_PDU_t* pdu)
{
  InitiatingMessage_t *initiatingMessage = pdu->choice.initiatingMessage;
  // xer_fprint(stdout, &asn_DEF_InitiatingMessage, (void *)initiatingMessage);

  RICsubscriptionRequest_t *request = &initiatingMessage->value.choice.RICsubscriptionRequest;
  xer_fprint(stdout, &asn_DEF_RICsubscriptionRequest, (void *)request);

  LOG_I("num of IEs = %d", request->protocolIEs.list.count);

  RICsubscriptionRequest_IEs_t *ie;

  ie = request->protocolIEs.list.array[2];

  xer_fprint(stdout, &asn_DEF_RICsubscription, (void *)ie);

  // e2ap_asn1c_print_pdu(pdu);
}

int subresponse_get_sequenceNum(E2AP_PDU_t* pdu)
{
  SuccessfulOutcome_t *responseMsg = pdu->choice.successfulOutcome;

  RICrequestID_t *requestid;

  int num_IEs = responseMsg->value.choice.RICsubscriptionResponse.protocolIEs.list.count;

  for(int edx = 0; edx < num_IEs; edx++)
  {
    RICsubscriptionResponse_IEs_t *memb_ptr =
      responseMsg->value.choice.RICsubscriptionResponse.protocolIEs.list.array[edx];

    switch(memb_ptr->id)
    {
      case (ProtocolIE_ID_id_RICrequestID):
        requestid = &memb_ptr->value.choice.RICrequestID;
        // xer_fprint(stdout, &asn_DEF_RICrequestID, (void *)requestid);
        return requestid->ricRequestSequenceNumber;
        break;
    }
  }
}

void subrequest_set_sequenceNum(E2AP_PDU_t* pdu, int seq)
{
  InitiatingMessage_t *initiatingMessage = pdu->choice.initiatingMessage;

  RICrequestID_t *requestid;

  int num_IEs = initiatingMessage->value.choice.RICsubscriptionRequest.protocolIEs.list.count;

  for(int edx = 0; edx < num_IEs; edx++)
  {
    RICsubscriptionRequest_IEs_t *memb_ptr =
      initiatingMessage->value.choice.RICsubscriptionRequest.protocolIEs.list.array[edx];

    switch(memb_ptr->id)
    {
      case (ProtocolIE_ID_id_RICrequestID):
        requestid = &memb_ptr->value.choice.RICrequestID;
        requestid->ricRequestSequenceNumber = seq;
        break;
    }
  }

}

void subscription_response_get_field(E2AP_PDU_t* pdu)
{
  SuccessfulOutcome_t *responseMsg = pdu->choice.successfulOutcome;

  RICrequestID_t *requestid;
  RANfunctionID_t * ranfunctionid;
  RICsubscription_t * ricsubscription;

  int requestID_val, sequenceNum;

  int num_IEs = responseMsg->value.choice.RICsubscriptionResponse.protocolIEs.list.count;

  LOG_I("num of IEs = %d", num_IEs);

  for(int edx = 0; edx < num_IEs; edx++)
  {
    RICsubscriptionResponse_IEs_t *memb_ptr =
      responseMsg->value.choice.RICsubscriptionResponse.protocolIEs.list.array[edx];

    switch(memb_ptr->id)
    {
      case (ProtocolIE_ID_id_RICrequestID):
      	requestid = &memb_ptr->value.choice.RICrequestID;
        xer_fprint(stdout, &asn_DEF_RICrequestID, (void *)requestid);
        requestID_val = requestid->ricRequestorID;
        sequenceNum = requestid->ricRequestSequenceNumber;
        requestid->ricRequestSequenceNumber = 202;
      	break;

      case (ProtocolIE_ID_id_RANfunctionID):
        ranfunctionid = &memb_ptr->value.choice.RANfunctionID;
        xer_fprint(stdout, &asn_DEF_RANfunctionID, (void *)ranfunctionid);
        break;

      // case (ProtocolIE_ID_id_RICsubscription):
      //   ricsubscription = &memb_ptr->value.choice.RICsubscription;
      //   xer_fprint(stdout, &asn_DEF_RICsubscription, (void *)ricsubscription);
      //   break;
    }
  }

  LOG_I("Request ID = %d, seq = %d", requestID_val, sequenceNum);
}

void subscription_request_get_field(E2AP_PDU_t* pdu)
{
  InitiatingMessage_t *initiatingMessage = pdu->choice.initiatingMessage;

  RICrequestID_t *requestid;
  RANfunctionID_t * ranfunctionid;
  RICsubscription_t * ricsubscription;

  int num_IEs = initiatingMessage->value.choice.RICsubscriptionRequest.protocolIEs.list.count;

  LOG_I("num of IEs = %d", num_IEs);

  for(int edx = 0; edx < num_IEs; edx++)
  {
    RICsubscriptionRequest_IEs_t *memb_ptr =
      initiatingMessage->value.choice.RICsubscriptionRequest.protocolIEs.list.array[edx];

    switch(memb_ptr->id)
    {
      case (ProtocolIE_ID_id_RICrequestID):
      	requestid = &memb_ptr->value.choice.RICrequestID;
        xer_fprint(stdout, &asn_DEF_RICrequestID, (void *)requestid);
      	break;

      case (ProtocolIE_ID_id_RANfunctionID):
        ranfunctionid = &memb_ptr->value.choice.RANfunctionID;
        xer_fprint(stdout, &asn_DEF_RANfunctionID, (void *)ranfunctionid);
        break;

      case (ProtocolIE_ID_id_RICsubscription):
        ricsubscription = &memb_ptr->value.choice.RICsubscription;
        xer_fprint(stdout, &asn_DEF_RICsubscription, (void *)ricsubscription);
        break;
    }
  }
}

int main(int argc, char* argv[]){
  LOG_I("Start RIC Simulator - Performance Test");

  options_t ops = read_input_options(argc, argv);
  int client_fd = sctp_start_client(ops.server_ip, ops.server_port);

  //1. Send ENDCX2Setup
  E2AP_PDU_t* pdu_setup = e2ap_xml_to_pdu("E2AP_ENDCX2SetupRequest.xml");
  // e2ap_asn1c_print_pdu(pdu_setup);
  encode_and_send_sctp_data(pdu_setup, client_fd);
  LOG_I("[SCTP] Sent ENDC X2 SETUP REQUEST");

  //2. Receive ENDCX2SetupResponse
  wait_for_sctp_data(client_fd);

  //3. Send RICSubscriptionRequest
  E2AP_PDU_t* pdu_sub = e2ap_xml_to_pdu("E2AP_RICsubscriptionRequest_Ashwin.xml");
  e2ap_asn1c_print_pdu(pdu_sub);
  encode_and_send_sctp_data(pdu_sub, client_fd);
  LOG_I("[SCTP] Sent RIC SUBSCRIPTION REQUEST");


  //4. Receive RIC SUBSCRIPT RESPONSE
  int count = 0;

  while(1)
  {
    usleep(1000); //sleep for one ms

    sctp_buffer_t recv_buf;

    int res_seq;

    if(sctp_receive_data(client_fd, recv_buf) > 0)
    {
      LOG_I("[SCTP] Received new data of size %d", recv_buf.len);
      // e2ap_handle_sctp_data(client_fd, recv_buf);

      E2AP_PDU_t* res_pdu = new E2AP_PDU_t();

      e2ap_asn1c_decode_pdu(res_pdu, recv_buf.buffer, recv_buf.len);

      int procedureCode = e2ap_asn1c_get_procedureCode(res_pdu);
      int index = (int)res_pdu->present;

      if(index == E2AP_PDU_PR_successfulOutcome && \
        procedureCode == ProcedureCode_id_ricSubscription)
      {
        res_seq =subresponse_get_sequenceNum(res_pdu);
        count++;

        LOG_I("Received RIC SUBSCRIPTION RESPONSE, seq = %d, totalCount = %d",\
                res_seq, count);

        //Put res_seq in new subscription request
        E2AP_PDU_t* req_pdu = e2ap_xml_to_pdu("E2AP_RICsubscriptionRequest.xml");
        subrequest_set_sequenceNum(req_pdu, res_seq);
        // e2ap_asn1c_print_pdu(req_pdu);

        encode_and_send_sctp_data(req_pdu, client_fd);
        LOG_I("Send new SUBSCRIPT REQUEST, seq = %d", res_seq);
      }

    }
  }


  // E2AP_PDU_t* res_pdu = e2ap_xml_to_pdu("E2AP_RICsubscriptionResponse.xml");
  //
  // //Extract subscription response sequence number
  // int res_seq = subresponse_get_sequenceNum(res_pdu);
  // LOG_I("Subscription Response SeqNo = %d", res_seq);
  //
  // //Put responseSeq in new subscription request
  // E2AP_PDU_t* req_pdu = e2ap_xml_to_pdu("E2AP_RICsubscriptionRequest.xml");
  //
  // subrequest_set_sequenceNum(req_pdu, res_seq);

  // e2ap_asn1c_print_pdu(req_pdu);

  return 0;
}
