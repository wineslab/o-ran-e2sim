/*
 *
 * Copyright 2019 AT&T Intellectual Property
 * Copyright 2019 Nokia
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "x2ap_message_handler.h"

typedef int (*x2ap_message_decoded_handler)(X2AP_PDU_t *pdu, sctp_data_t *response);

static int handle_x2_setup_request(X2AP_PDU_t *pdu, sctp_data_t *response);

static int handle_x2_setup_response(X2AP_PDU_t *pdu, sctp_data_t *response);

static int handle_x2_setup_failure(X2AP_PDU_t *pdu, sctp_data_t *response);

/* Handlers matrix. Only eNB related procedure present here
/* rowID = procedureCode (start with 0)
*/
x2ap_message_decoded_handler x2ap_messages_handler[][3] = {
  { 0, 0, 0 }, /* handoverPreparation */
  { 0, 0, 0 }, /* handoverCancel */
  { 0, 0, 0 }, /* loadIndication */
  { 0, 0, 0 }, /* errorIndication */
  { 0, 0, 0 }, /* snStatusTransfer */
  { 0, 0, 0 }, /* uEContextRelease */
  { handle_x2_setup_request, handle_x2_setup_response, handle_x2_setup_failure }, /* x2Setup */
  { 0, 0, 0 }, /* reset */
  { 0, 0, 0 }, /* eNBConfigurationUpdate */
  { 0, 0, 0 }, /* resourceStatusReportingInitiation */
  { 0, 0, 0 }, /* resourceStatusReporting */
  { 0, 0, 0 }, /* privateMessage */
  { 0, 0, 0 }, /* mobilitySettingsChange */
  { 0, 0, 0 }, /* rLFIndication */
  { 0, 0, 0 }, /* handoverReport */
  { 0, 0, 0 }, /* cellActivation */
  { 0, 0, 0 }, /* x2Release */
  { 0, 0, 0 }, /* x2APMessageTransfer */
  { 0, 0, 0 }, /* x2Removal */
  { 0, 0, 0 }, /* seNBAdditionPreparation */
  { 0, 0, 0 }, /* seNBReconfigurationCompletion */
  { 0, 0, 0 }, /* meNBinitiatedSeNBModificationPreparation */
  { 0, 0, 0 }, /* seNBinitiatedSeNBModification */
  { 0, 0, 0 }, /* meNBinitiatedSeNBRelease */
  { 0, 0, 0 }, /* seNBinitiatedSeNBRelease */
  { 0, 0, 0 }, /* seNBCounterCheck */
  { 0, 0, 0 }  /* retrieveUEContext */
};

char *x2ap_direction2String(int x2ap_dir)
{
  static char *x2ap_direction_String[] = {
    "", /* Nothing */
    "Originating message", /* originating message */
    "Successfull outcome", /* successfull outcome */
    "UnSuccessfull outcome", /* successfull outcome */
  };
  return(x2ap_direction_String[x2ap_dir]);
}

int x2ap_eNB_handle_message(const uint8_t *const data, const int data_len, sctp_data_t* response)
{
  X2AP_PDU_t pdu;
  int ret;

  memset(&pdu, 0, sizeof(pdu));

  //printf("Decode the PDU \n");

  if (X2AP_ASN_decode(&pdu, data, data_len) < 0){
    return -1;
  }

  /* Checking procedure Code and direction of message */
  if (pdu.choice.initiatingMessage.procedureCode > sizeof(x2ap_messages_handler)
        / (3 * sizeof(x2ap_message_decoded_handler))
        || (pdu.present > X2AP_PDU_PR_unsuccessfulOutcome)) {

    fprintf(stderr, "Either procedureCode %ld or direction %d exceed expected\n",
         pdu.choice.initiatingMessage.procedureCode, pdu.present);
    ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_X2AP_PDU, &pdu);
    return -1;
  }

  if (x2ap_messages_handler[pdu.choice.initiatingMessage.procedureCode][pdu.present - 1] == NULL)
  {
    fprintf(stderr, "No handler for procedureCode %ld in direction %s\n",
            pdu.choice.initiatingMessage.procedureCode,
            x2ap_direction2String(pdu.present - 1));
    ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_X2AP_PDU, &pdu);
    return -1;
  }

  /*calling the appropriate handler */
  ret = (*x2ap_messages_handler[pdu.choice.initiatingMessage.procedureCode][pdu.present - 1])(&pdu, response);
  ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_X2AP_PDU, &pdu);
  return ret;
}

int handle_x2_setup_request(X2AP_PDU_t *pdu, sctp_data_t* response)
{
  fprintf(stderr, "Received X2 SETUP REQUEST\n");

  /* Todo: when to generate X2 Setup Failure???
  */

  response->len = x2ap_generate_x2_setup_response(&response->data);

  return 0;
}

int handle_x2_setup_response(X2AP_PDU_t *pdu, sctp_data_t* response)
{
  fprintf(stderr, "Received X2 SETUP RESPONSE\n");
  return 0;
}

int handle_x2_setup_failure(X2AP_PDU_t *pdu, sctp_data_t* response)
{
  fprintf(stderr, "Received X2 SETUP FAILURE\n");
  return 0;
}
