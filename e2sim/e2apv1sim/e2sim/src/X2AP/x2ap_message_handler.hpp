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
#ifndef X2AP_MESSAGE_HANDLER_HPP
#define X2AP_MESSAGE_HANDLER_HPP

#include "e2sim_defs.h"
#include "e2sim_sctp.hpp"
#include "asn_x2ap.hpp"
#include "x2ap_asn_codec.hpp"

void x2ap_handle_sctp_data(int &socket_fd, sctp_buffer_t &data);

void x2ap_handle_X2SetupRequest(x2ap_pdu_t* pdu, int &socket_fd);

void x2ap_handle_X2SetupResponse(x2ap_pdu_t* pdu, int &socket_fd);

void x2ap_handle_ENDCX2SetupRequest(x2ap_pdu_t* pdu, int &socket_fd);

#endif
