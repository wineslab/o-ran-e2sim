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

#ifndef X2AP_ENB_HANDLER_H_
#define X2AP_ENB_HANDLER_H_

#include "x2ap_asn_codec.h"
#include "X2AP-PDU.h"
#include "e2sim_defs.h"
#include "x2ap_generate_messages.h"

int x2ap_eNB_handle_message(const uint8_t *const data, const int data_len, sctp_data_t* response);

#endif
