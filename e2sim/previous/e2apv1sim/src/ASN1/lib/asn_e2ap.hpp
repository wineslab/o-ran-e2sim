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

#ifndef ASN_E2AP_HPP
#define ASN_E2AP_HPP

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "e2ap_config.hpp"

typedef struct c__dummy01 e2ap_pdu_t;

/*-----------------------------------------------------------------------
                              COMMON ROUTINES
-------------------------------------------------------------------------
*/
e2ap_pdu_t* new_e2ap_pdu(void);

void e2ap_asn_print(e2ap_pdu_t* pdu, char* buf, size_t buf_size);

int e2ap_asn_per_encode(e2ap_pdu_t* pdu, unsigned char* buf, size_t buf_size,
                      char* err_buf, size_t err_buf_size);

int e2ap_asn_per_decode(e2ap_pdu_t* pdu, unsigned char const* buf, size_t buf_size,
                                          char* err_buf, size_t err_buf_size);

int e2ap_get_index(e2ap_pdu_t* pdu);

int e2ap_get_procedureCode(e2ap_pdu_t* pdu);

/*-----------------------------------------------------------------------
                              MESSAGE GENERATORS
-------------------------------------------------------------------------
*/

//X2Setup
bool e2ap_init_X2SetupRequest(e2ap_pdu_t* pdu);

bool e2ap_create_X2SetupRequest(e2ap_pdu_t* pdu, eNB_config &cfg);

bool e2ap_create_X2SetupResponse(e2ap_pdu_t* pdu, eNB_config &cfg);

bool e2ap_create_X2SetupFailure(e2ap_pdu_t* pdu);

//ENDCX2Setup
bool e2ap_create_ENDCX2SetupRequest(e2ap_pdu_t* pdu, eNB_config &cfg);

bool e2ap_create_ENDCX2SetupResponse(e2ap_pdu_t* pdu, gNB_config &cfg);

bool e2ap_create_ENDCX2SetupFailure(e2ap_pdu_t* pdu);

//RIC Subscription
bool e2ap_create_RICsubscriptionRequest(e2ap_pdu_t* pdu, RICsubscription_params_t &params);

bool e2ap_parse_RICsubscriptionRequest(e2ap_pdu_t* pdu, RICsubscription_params_t &params);

bool e2ap_create_RICsubscriptionResponse(e2ap_pdu_t* pdu, RICsubscription_params_t &params);

bool e2ap_create_RICsubscriptionFailure(e2ap_pdu_t* pdu, RICsubscription_params_t &params);

/*-----------------------------------------------------------------------
                              TESTS
-------------------------------------------------------------------------
*/
void test_E2AP_X2Setup_codec(void);

#endif
