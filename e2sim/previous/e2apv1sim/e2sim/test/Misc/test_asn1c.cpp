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
#include <string>
#include <iostream>

extern "C" {
  #include "e2sim_defs.h"
  #include "E2AP-PDU.h"
  #include "e2ap_asn1c_codec.h"
  #include "e2sm.h"

}

using namespace std;

int main(int argc, char* argv[]){

  LOG_I("Test ASN1c");

  test_eventTriggerDefinition();
  return 0;

  E2AP_PDU_t* pdu = e2ap_xml_to_pdu("E2AP_X2SetupRequest.xml");
  // E2AP_PDU_t* pdu = e2ap_xml_to_pdu("E2AP_X2SetupResponse.xml");
  // E2AP_PDU_t* pdu = e2ap_xml_to_pdu("E2AP_X2SetupFailure.xml");

  // E2AP_PDU_t* pdu = e2ap_xml_to_pdu("E2AP_ENDCX2SetupRequest.xml");
  // E2AP_PDU_t* pdu = e2ap_xml_to_pdu("E2AP_ENDCX2SetupResponse.xml");
  // E2AP_PDU_t* pdu = e2ap_xml_to_pdu("E2AP_ENDCX2SetupFailure.xml");

  // E2AP_PDU_t* pdu = e2ap_xml_to_pdu("E2AP_RICsubscriptionRequest.xml");
  // E2AP_PDU_t* pdu = e2ap_xml_to_pdu("E2AP_RICsubscriptionResponse.xml");
  // E2AP_PDU_t* pdu = e2ap_xml_to_pdu("E2AP_ErrorIndication.xml");

  e2ap_asn1c_print_pdu(pdu);

  /* Test encoding */
  uint8_t       *buf;
  sctp_buffer_t data;

  data.len = e2ap_asn1c_encode_pdu(pdu, &buf);
  memcpy(data.buffer, buf, min(data.len, MAX_SCTP_BUFFER));

  /* Test decoding */
  E2AP_PDU_t* pdu1 = new E2AP_PDU_t();

  e2ap_asn1c_decode_pdu(pdu1, data.buffer, data.len);

  e2ap_asn1c_print_pdu(pdu1);

  int index = (int)pdu1->present;

  int pCode = e2ap_asn1c_get_procedureCode(pdu1);

  LOG_I("Index = %d, procedureCode = %d", index, pCode);


  return 0;
}
