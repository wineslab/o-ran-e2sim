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

#ifndef ASN_X2AP_HPP
#define ASN_X2AP_HPP

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "e2ap_config.hpp"

typedef struct c__dummy00 x2ap_pdu_t;

/*-----------------------------------------------------------------------
                              COMMON ROUTINES
-------------------------------------------------------------------------
*/

x2ap_pdu_t* new_x2ap_pdu(void);

void x2ap_asn_print(x2ap_pdu_t* pdu, char* buf, size_t buf_size);

int x2ap_asn_per_encode(x2ap_pdu_t* pdu, unsigned char* buf, size_t buf_size,
                      char* err_buf, size_t err_buf_size);

int x2ap_asn_per_decode(x2ap_pdu_t* pdu, unsigned char const* buf, size_t buf_size,
                                          char* err_buf, size_t err_buf_size);

int x2ap_get_index(x2ap_pdu_t* pdu);

int x2ap_get_procedureCode(x2ap_pdu_t* pdu);

/*-----------------------------------------------------------------------
                              MESSAGE GENERATORS
-------------------------------------------------------------------------
*/
//X2Setup
bool x2ap_init_X2SetupRequest(x2ap_pdu_t* pdu);

bool x2ap_create_X2SetupRequest(x2ap_pdu_t* pdu, eNB_config &cfg);

bool x2ap_create_X2SetupResponse(x2ap_pdu_t* pdu, eNB_config &cfg);

bool x2ap_create_X2SetupFailure(x2ap_pdu_t* pdu);

//ENDCX2Setup
bool x2ap_create_ENDCX2SetupRequest(x2ap_pdu_t* pdu, eNB_config &cfg);

/*-----------------------------------------------------------------------
                              TESTS
-------------------------------------------------------------------------
*/
void test_X2Setup_codec(void);

#endif
