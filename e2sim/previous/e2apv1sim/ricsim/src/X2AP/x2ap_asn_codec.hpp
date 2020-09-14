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
#ifndef X2AP_ASN_CODEC_HPP
#define X2AP_ASN_CODEC_HPP

#include "e2sim_defs.h"
#include "asn_x2ap.hpp"

#define X2AP_ERROR_MESSAGE_BUFFER       1024
#define X2AP_PDU_PRINT_BUFFER           4096

void x2ap_encode_pdu(x2ap_pdu_t* pdu, unsigned char* buf, int buf_size, int &encoded_size);

void x2ap_decode_pdu(x2ap_pdu_t* pdu, unsigned char* buf, int &encoded_size);

void x2ap_print_pdu(x2ap_pdu_t* pdu);

#endif
