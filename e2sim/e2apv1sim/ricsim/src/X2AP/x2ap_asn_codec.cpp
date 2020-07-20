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

#include "x2ap_asn_codec.hpp"

void x2ap_encode_pdu(x2ap_pdu_t* pdu, unsigned char* buf, int buf_size, int &encoded_size)
{
  char err_buf[X2AP_ERROR_MESSAGE_BUFFER];

  encoded_size = x2ap_asn_per_encode(pdu, buf, buf_size, err_buf, sizeof(err_buf));

  if(encoded_size != -1)
  {
    LOG_D("[X2AP] ASN Encode successful, encoded_size = %d", encoded_size);
  }
  else
  {
    LOG_E("[X2AP] Encode error: %s", err_buf);
    exit(1);
  }

}

void x2ap_decode_pdu(x2ap_pdu_t* pdu, unsigned char* buf, int &encoded_size)
{
  char err_buf[X2AP_ERROR_MESSAGE_BUFFER];

  int rc = x2ap_asn_per_decode(pdu, buf, encoded_size, err_buf, sizeof(err_buf));
  if(rc == -1) {
    LOG_E("[X2AP] Decode error: %s", err_buf);
  } else {
    LOG_D("[X2AP] ASN decode successful");
  }
}

void x2ap_print_pdu(x2ap_pdu_t* pdu)
{
  char pdu_str[X2AP_PDU_PRINT_BUFFER];

  x2ap_asn_print(pdu, pdu_str, sizeof(pdu_str));

  LOG_D("[X2AP] %s", pdu_str);
}
