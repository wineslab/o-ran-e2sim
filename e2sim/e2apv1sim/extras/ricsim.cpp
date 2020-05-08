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
  #include "GlobalE2node-ID.h"
  #include "GlobalE2node-gNB-ID.h"
  #include "GlobalgNB-ID.h"
  #include "OCTET_STRING.h"
  #include "asn_application.h"
  #include "GNB-ID-Choice.h"
  #include "ProtocolIE-Field.h"
  #include "E2setupRequest.h"
}

using namespace std;

/*
struct {
  type **array;
  int count;
  int size;
  void (*free)(decltype(*array));
} 
*/

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
  //  E2AP_PDU_t* pdu_setup = e2ap_xml_to_pdu("E2AP_ENDCX2SetupRequest.xml");

  printf("out0\n");

  uint8_t *buf = (uint8_t *)"gnb1";

  BIT_STRING_t gnb_bstring;
  gnb_bstring.buf = buf;
  gnb_bstring.size = 4;
  gnb_bstring.bits_unused = 0;

  printf("out1\n");
  

  uint8_t *buf2 = (uint8_t *)"plmn3";
  OCTET_STRING_t plmn;
  plmn.buf = buf2;
  plmn.size = 5;

  GNB_ID_Choice_t gnbchoice;
  GNB_ID_Choice_PR pres2 = GNB_ID_Choice_PR_gnb_ID;
  gnbchoice.present = pres2;
  gnbchoice.choice.gnb_ID = gnb_bstring;

  GlobalgNB_ID_t gnb;
  gnb.plmn_id = plmn;
  gnb.gnb_id = gnbchoice;



  GlobalE2node_gNB_ID_t *e2gnb = (GlobalE2node_gNB_ID_t*)calloc(1, sizeof(GlobalE2node_gNB_ID_t));
  e2gnb->global_gNB_ID = gnb;

  /*
  GlobalE2node_ID_t *globale2nodeid = (GlobalE2node_ID_t*)calloc(1, sizeof(GlobalE2node_ID_t));
  GlobalE2node_ID_PR pres;
  pres = GlobalE2node_ID_PR_gNB;
  globale2nodeid->present = pres;
  globale2nodeid->choice.gNB = e2gnb;
  */

  GlobalE2node_ID_t globale2nodeid;
  GlobalE2node_ID_PR pres;
  pres = GlobalE2node_ID_PR_gNB;
  globale2nodeid.present = pres;
  globale2nodeid.choice.gNB = e2gnb;  
  
  E2setupRequestIEs_t *e2setuprid = (E2setupRequestIEs_t*)calloc(1, sizeof(E2setupRequest_t));;
  E2setupRequestIEs__value_PR pres3;
  pres3 = E2setupRequestIEs__value_PR_GlobalE2node_ID;
  e2setuprid->id = 4;
  e2setuprid->criticality = 0;
  e2setuprid->value.choice.GlobalE2node_ID = globale2nodeid;
  e2setuprid->value.present = pres3;


  E2setupRequest_t e2setupreq;
  e2setupreq.protocolIEs.list.size = sizeof(E2setupRequestIEs);
  e2setupreq.protocolIEs.list.count = 1;
  e2setupreq.protocolIEs.list.array = &e2setuprid;

  InitiatingMessage__value_PR pres4;
  pres4 = InitiatingMessage__value_PR_E2setupRequest;
  InitiatingMessage_t *initmsg = (InitiatingMessage_t*)calloc(1, sizeof(InitiatingMessage_t));
  initmsg->procedureCode = 1;
  initmsg->criticality = 0;
  initmsg->value.present = pres4;
  initmsg->value.choice.E2setupRequest = e2setupreq;

  E2AP_PDU_PR pres5;
  pres5 = E2AP_PDU_PR_initiatingMessage;
  
  E2AP_PDU_t *e2ap_pdu = (E2AP_PDU_t*)calloc(1, sizeof(E2AP_PDU_t));
  e2ap_pdu->present = pres5;
  e2ap_pdu->choice.initiatingMessage = initmsg;
  
  printf("over here\n");

  asn_fprint(stdout, &asn_DEF_E2AP_PDU, e2ap_pdu);


  printf("over here 2\n");
  
  xer_fprint(stdout, &asn_DEF_E2AP_PDU, e2ap_pdu);

  printf("over here 55\n");

  E2AP_PDU_t* pdu_setup = e2ap_xml_to_pdu("E2AP_SetupRequest2.xml");
  e2ap_asn1c_print_pdu(pdu_setup);
  encode_and_send_sctp_data(pdu_setup, client_fd);
  LOG_I("[SCTP] Sent ENDC X2 SETUP REQUEST");


  //  E2setupRequest_t* pdu_setup = smaller_e2ap_xml_to_pdu("E2AP_PartSetupRequest.xml");
  //  e2ap_asn1c_print_pdu(pdu_setup);
  //  encode_and_send_sctp_data(pdu_setup, client_fd);
  LOG_I("[SCTP] Sent ENDC X2 SETUP REQUEST");

  /*
  GlobalE2node_ID_t* pdu_setup = smaller_e2ap_xml_to_pdu("GlobalE2node-ID.xml");

  asn_fprint(stdout, &asn_DEF_GlobalE2node_ID, pdu_setup);

  printf("over here 2\n");
  
  xer_fprint(stdout, &asn_DEF_GlobalE2node_ID, pdu_setup);  
  */
  /*
  e2ap_asn1c_print_pdu(pdu_setup);
  encode_and_send_sctp_data(pdu_setup, client_fd);
  */
  LOG_I("[SCTP] Sent ENDC X2 SETUP REQUEST");  

  
  //2. Receive ENDCX2SetupResponse
  wait_for_sctp_data(client_fd);

  //3. Send RICSubscriptionRequest
  /*
  E2AP_PDU_t* pdu_sub = e2ap_xml_to_pdu("E2AP_RICsubscriptionRequest_Ashwin.xml");
  e2ap_asn1c_print_pdu(pdu_sub);
  encode_and_send_sctp_data(pdu_sub, client_fd);
  LOG_I("[SCTP] Sent RIC SUBSCRIPTION REQUEST");
  */
  //4. Receive RICSubscriptionResponse
  while(1){
    wait_for_sctp_data(client_fd);
  }


  //---------------------------------------
  close(client_fd);
  LOG_I("[SCTP] Connection closed.");

  return 0;

}
