

/*****************************************************************************
#                                                                            *
# Copyright 2020 AT&T Intellectual Property                                  *
# Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved.      *
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

#include <iostream>
#include <vector>

#include "encode_e2apv1.hpp"


#include <unistd.h>
#include <ProtocolIE-Field.h>


void e2ap_handle_sctp_data(int &socket_fd, sctp_buffer_t &data, E2Sim *e2sim) {
    LOG_D("in e2ap_handle_sctp_data()");
    //decode the data into E2AP-PDU
    auto *pdu = (E2AP_PDU_t *) calloc(1, sizeof(E2AP_PDU));
    ASN_STRUCT_RESET(asn_DEF_E2AP_PDU, pdu);
    asn_transfer_syntax syntax = ATS_ALIGNED_BASIC_PER;

    e2ap_asn1c_decode_pdu(pdu, syntax, data.buffer, data.len);
    E2AP_PDU_PR pr_type_of_message = pdu->present;

    e2ap_asn1c_print_pdu(pdu);

    long procedureCode = e2ap_asn1c_get_procedureCode(pdu);

    switch (procedureCode) {

        case ProcedureCode_id_E2setup: // Procedure code: 1
            switch (pr_type_of_message) {
                case E2AP_PDU_PR_initiatingMessage:
                    e2ap_handle_E2SetupRequest(pdu, socket_fd);
                    LOG_I("[E2AP] Received SETUP-REQUEST");
                    break;

                case E2AP_PDU_PR_successfulOutcome: LOG_I("[E2AP] Received SETUP-RESPONSE-SUCCESS");
                    break;

                case E2AP_PDU_PR_unsuccessfulOutcome: LOG_I("[E2AP] Received SETUP-RESPONSE-FAILURE");
                    break;

                default: LOG_E("[E2AP] Invalid message index=%d in E2AP-PDU", pr_type_of_message);
                    break;
            }
            break;

        case ProcedureCode_id_ErrorIndication: // Procedure code: 2
            switch (pr_type_of_message) {
                case E2AP_PDU_PR_initiatingMessage:
                    e2ap_handle_E2SetupRequest(pdu, socket_fd);
                    LOG_I("[E2AP] Received ERROR-INDICATION");
                    break;

                case E2AP_PDU_PR_successfulOutcome: LOG_I("[E2AP] Received ERROR-INDICATION SUCCESS");
                    break;

                case E2AP_PDU_PR_unsuccessfulOutcome: LOG_I("[E2AP] Received ERROR-INDICATION FAILURE");
                    break;

                default: LOG_E("[E2AP] Invalid message index=%d in E2AP-PDU", pr_type_of_message);
                    break;
            }
            break;

        case ProcedureCode_id_Reset: // RESET = 3
            switch (pr_type_of_message) {
                case E2AP_PDU_PR_initiatingMessage:
                    LOG_I("[E2AP] Received RESET-REQUEST");
                    break;

                case E2AP_PDU_PR_successfulOutcome:
                case E2AP_PDU_PR_unsuccessfulOutcome:
                    break;

                default: LOG_E("[E2AP] Invalid message index=%d in E2AP-PDU", pr_type_of_message);
                    break;
            }
            break;

        case ProcedureCode_id_RICcontrol: // Procedure code = 4
            switch (pr_type_of_message) {
                case E2AP_PDU_PR_initiatingMessage: {
                    LOG_I("[E2AP] Received RIC-CONTROL-REQUEST");
                    e2ap_handle_RICControlRequest(pdu, socket_fd, e2sim);
                    break;
                }
                case E2AP_PDU_PR_successfulOutcome: LOG_I("[E2SM] Received RIC-CONTROL-RESPONSE");
                    break;

                case E2AP_PDU_PR_unsuccessfulOutcome: LOG_I("[E2SM] Received RIC-CONTROL-FAILURE");
                    break;

                default: LOG_E("[E2SM] Invalid message index=%d in PDU %ld", pr_type_of_message,
                               ProcedureCode_id_RICcontrol);
                    break;
            }
            break;

        case ProcedureCode_id_RICindication: // 5
            switch (pr_type_of_message) {
                case E2AP_PDU_PR_initiatingMessage: //initiatingMessage
                    LOG_I("[E2AP] Received RIC-INDICATION-REQUEST");
                    // e2ap_handle_RICSubscriptionRequest(pdu, socket_fd);
                    break;
                case E2AP_PDU_PR_successfulOutcome: LOG_I("[E2AP] Received RIC-INDICATION-RESPONSE");
                    break;

                case E2AP_PDU_PR_unsuccessfulOutcome: LOG_I("[E2AP] Received RIC-INDICATION-FAILURE");
                    break;

                default: LOG_E("[E2AP] Invalid message index=%d in E2AP-PDU %ld", pr_type_of_message,
                               ProcedureCode_id_RICindication);
                    break;
            }
            break;

        case ProcedureCode_id_RICserviceQuery: // 6
            switch (pr_type_of_message) {
                case E2AP_PDU_PR_initiatingMessage: LOG_I("[E2AP] Received RIC-Service-Query")
                    e2ap_handle_E2SeviceRequest(pdu, socket_fd, e2sim);
                    break;
                    break;
                case E2AP_PDU_PR_NOTHING:
                case E2AP_PDU_PR_successfulOutcome:
                case E2AP_PDU_PR_unsuccessfulOutcome:
                    break;
                default: LOG_E("[E2AP] Invalid message index=%d in E2AP-PDU %d", pr_type_of_message,
                               (int) ProcedureCode_id_RICserviceQuery);
            }
            break;

        case ProcedureCode_id_RICserviceUpdate: // 7
            switch (pr_type_of_message) {
                case E2AP_PDU_PR_successfulOutcome: LOG_I("[E2AP] Received RIC-SERVICE-UPDATE-SUCCESS")
                    break;

                case E2AP_PDU_PR_unsuccessfulOutcome: LOG_I("[E2AP] Received RIC-SERVICE-UPDATE-FAILURE")
                    break;

                default: LOG_E("[E2AP] Invalid message index=%d in E2AP-PDU %ld", pr_type_of_message,
                               ProcedureCode_id_RICserviceUpdate);
                    break;
            }
            break;

        case ProcedureCode_id_RICsubscription: // RIC SUBSCRIPTION = 8
            switch (pr_type_of_message) {
                case E2AP_PDU_PR_initiatingMessage: { //initiatingMessage
                    LOG_I("[E2AP] Received RIC-SUBSCRIPTION-REQUEST");
                    //          e2ap_handle_RICSubscriptionRequest(pdu, socket_fd);
                    long func_id = encoding::get_function_id_from_subscription(pdu);
                    LOG_D("Function Id of message is %ld\n", func_id);
                    SubscriptionCallback cb;

                    bool func_exists = true;

                    try {
                        cb = e2sim->get_subscription_callback(func_id);
                    } catch (const std::out_of_range &e) {
                        func_exists = false;
                    }

                    if (func_exists) {
                        LOG_D("Calling callback function\n");
                        cb(pdu);
                    } else {
                        LOG_E("Error: No RAN Function with this ID exists\n");
                    }
                    //	  callback_kpm_subscription_request(pdu, socket_fd);

                }
                    break;

                case E2AP_PDU_PR_successfulOutcome: LOG_I("[E2AP] Received RIC-SUBSCRIPTION-RESPONSE");
                    break;

                case E2AP_PDU_PR_unsuccessfulOutcome: LOG_I("[E2AP] Received RIC-SUBSCRIPTION-FAILURE");
                    break;

                default: LOG_E("[E2AP] Invalid message index=%d in E2AP-PDU", pr_type_of_message);
                    break;
            }
            break;
        case ProcedureCode_id_RICsubscriptionDelete: // Procedure code: 9
            switch (pr_type_of_message) {
                case E2AP_PDU_PR_initiatingMessage:
                    LOG_I("[E2AP] Received RIC-SUBSCRIPTION-DELETE");
                    break;

                case E2AP_PDU_PR_successfulOutcome: LOG_I("[E2AP] Received SUBSCRIPTION-DELETE SUCCESS");
                    break;

                case E2AP_PDU_PR_unsuccessfulOutcome: LOG_I("[E2AP] Received SUBSCRIPTION-DELETE FAILURE");
                    break;

                default: LOG_E("[E2AP] Invalid message index=%d in E2AP-PDU", pr_type_of_message);
                    break;
            }
            break;

        default: LOG_E("[E2AP] No available handler for procedureCode=%ld", procedureCode);

            break;
    }
}

void e2ap_handle_RICControlRequest(E2AP_PDU_t *pdu, int &socket_fd, E2Sim *e2sim) {
    long func_id = 300;
    SmCallback cb;

    bool func_exists = true;
    try {
        cb = e2sim->get_sm_callback(func_id);
    } catch (const std::out_of_range &e) {
        func_exists = false;
    }

    if (func_exists) {
        LOG_D("Calling callback function");
        cb(pdu);
    } else {
        LOG_E("Error: No RAN Function with this ID exists");
    }

    auto* res_pdu = (E2AP_PDU_t*)calloc(1, sizeof(E2AP_PDU));
    encoding::generate_e2apv1_ric_control_acknowledge(res_pdu);

    LOG_D("[E2AP] Created E2-RIC-CONTROL-ACKNOWLEDGE");

    e2ap_asn1c_print_pdu(res_pdu);

    auto buffer_size = MAX_SCTP_BUFFER;
    unsigned char buffer[MAX_SCTP_BUFFER];

    sctp_buffer_t data;
    auto er = asn_encode_to_buffer(nullptr, ATS_BASIC_XER, &asn_DEF_E2AP_PDU, res_pdu, buffer, buffer_size);

    LOG_D("er encoded is %zd\n", er.encoded);
    data.len = (int) er.encoded;

    memcpy(data.buffer, buffer, er.encoded);

    //send response data over sctp
    if (sctp_send_data(socket_fd, data) > 0) {
        LOG_I("[SCTP] Sent E2-SERVICE-UPDATE");
    } else {
        LOG_E("[SCTP] Unable to send E2-SERVICE-UPDATE to peer");
    }

}

void e2ap_handle_E2SeviceRequest(E2AP_PDU_t* pdu, int &socket_fd, E2Sim *e2sim) {

  auto buffer_size = MAX_SCTP_BUFFER;
  unsigned char buffer[MAX_SCTP_BUFFER];
  auto* res_pdu = (E2AP_PDU_t*)calloc(1,sizeof(E2AP_PDU));

  // prepare ran function defination
  std::vector<encoding::ran_func_info> all_funcs;

  //Loop through RAN function definitions that are registered

  for (std::pair<long, OCTET_STRING_t*> elem : e2sim->getRegistered_ran_functions()) {
    LOG_D("looping through ran func\n");
    encoding::ran_func_info next_func{};

    next_func.ranFunctionId = elem.first;
    next_func.ranFunctionDesc = elem.second;
    next_func.ranFunctionRev = (long)3;
    all_funcs.push_back(next_func);
  }

  LOG_D("about to call service update encode\n");

  encoding::generate_e2apv1_service_update(res_pdu, all_funcs);

  LOG_D("[E2AP] Created E2-SERVICE-UPDATE");

  e2ap_asn1c_print_pdu(res_pdu);

  sctp_buffer_t data;

  char *error_buf = (char*)calloc(300, sizeof(char));
  size_t errlen;

  asn_check_constraints(&asn_DEF_E2AP_PDU, res_pdu, error_buf, &errlen);

  auto er = asn_encode_to_buffer(nullptr, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2AP_PDU, res_pdu, buffer, buffer_size);

  data.len = (int) er.encoded;
  LOG_D( "er encoded is %zd\n", er.encoded);

  memcpy(data.buffer, buffer, er.encoded);

  //send response data over sctp
  if(sctp_send_data(socket_fd, data) > 0) {
    LOG_I("[SCTP] Sent E2-SERVICE-UPDATE");
  } else {
    LOG_E("[SCTP] Unable to send E2-SERVICE-UPDATE to peer");
  }
}

void e2ap_handle_E2SetupRequest(E2AP_PDU_t* pdu, int &socket_fd) {

  auto* res_pdu = (E2AP_PDU_t*)calloc(1, sizeof(E2AP_PDU));
  encoding::generate_e2apv1_setup_response(res_pdu);


  LOG_D("[E2AP] Created E2-SETUP-RESPONSE");

  e2ap_asn1c_print_pdu(res_pdu);

  auto buffer_size = MAX_SCTP_BUFFER;
  unsigned char buffer[MAX_SCTP_BUFFER];

  sctp_buffer_t data;
  auto er = asn_encode_to_buffer(nullptr, ATS_BASIC_XER, &asn_DEF_E2AP_PDU, res_pdu, buffer, buffer_size);

//  LOG_D("er encoded is %zd\n", er.encoded);
  data.len = er.encoded;

  //data.len = e2ap_asn1c_encode_pdu(res_pdu, &buf);
  memcpy(data.buffer, buffer, er.encoded);

  //send response data over sctp
  if(sctp_send_data(socket_fd, data) > 0) {
    LOG_I("[SCTP] Sent E2-SETUP-RESPONSE");
  } else {
    LOG_E("[SCTP] Unable to send E2-SETUP-RESPONSE to peer");
  }

  sleep(3);

  // Sending Subscription Request

  auto* pdu_sub = (E2AP_PDU_t*)calloc(1,sizeof(E2AP_PDU));

  encoding::generate_e2apv1_subscription_request(pdu_sub);

  e2ap_asn1c_print_pdu(pdu_sub);

  auto buffer_size2 = MAX_SCTP_BUFFER;
  unsigned char buffer2[MAX_SCTP_BUFFER];

  sctp_buffer_t data2;

  auto er2 = asn_encode_to_buffer(nullptr, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2AP_PDU, pdu_sub, buffer2, buffer_size2);

  data2.len = (int) er2.encoded;
  memcpy(data2.buffer, buffer2, er2.encoded);

  LOG_D( "er encded is %zd\n", er2.encoded);

  if(sctp_send_data(socket_fd, data2) > 0) {
    LOG_I("[SCTP] Sent E2-SUBSCRIPTION-REQUEST");
  } else {
    LOG_E("[SCTP] Unable to send E2-SUBSCRIPTION-REQUEST to peer");
  }
}

/*
void e2ap_handle_RICSubscriptionRequest(E2AP_PDU_t* pdu, int &socket_fd)
{

  //Send back Subscription Success Response

  E2AP_PDU_t* pdu_resp = (E2AP_PDU_t*)calloc(1,sizeof(E2AP_PDU));

  generate_e2apv1_subscription_response(pdu_resp, pdu);

  LOG_D( "Subscription Response\n");

  xer_fprint(stderr, &asn_DEF_E2AP_PDU, pdu_resp);

  auto buffer_size2 = MAX_SCTP_BUFFER;
  unsigned char buffer2[MAX_SCTP_BUFFER];
  
  sctp_buffer_t data2;

  auto er2 = asn_encode_to_buffer(nullptr, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2AP_PDU, pdu_resp, buffer2, buffer_size2);
  data2.len = er2.encoded;

  LOG_D( "er encded is %d\n", er2.encoded);

  memcpy(data2.buffer, buffer2, er2.encoded);

  if(sctp_send_data(socket_fd, data2) > 0) {
    LOG_I("[SCTP] Sent RIC-SUBSCRIPTION-RESPONSE");
  } else {
    LOG_E("[SCTP] Unable to send RIC-SUBSCRIPTION-RESPONSE to peer");
  }
  
  
  //Send back an Indication

  E2AP_PDU_t* pdu_ind = (E2AP_PDU_t*)calloc(1,sizeof(E2AP_PDU));

  generate_e2apv1_indication_request(pdu_ind);

  xer_fprint(stderr, &asn_DEF_E2AP_PDU, pdu_ind);

  auto buffer_size = MAX_SCTP_BUFFER;
  unsigned char buffer[MAX_SCTP_BUFFER];
  
  sctp_buffer_t data;

  auto er = asn_encode_to_buffer(nullptr, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2AP_PDU, pdu_ind, buffer, buffer_size);
  data.len = er.encoded;

  LOG_D( "er encded is %d\n", er.encoded);

  memcpy(data.buffer, buffer, er.encoded);

  if(sctp_send_data(socket_fd, data) > 0) {
    LOG_I("[SCTP] Sent RIC-INDICATION-REQUEST");
  } else {
    LOG_E("[SCTP] Unable to send RIC-INDICATION-REQUEST to peer");
  }  

}
*/
