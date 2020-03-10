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

#include "x2ap_asn_codec.h"
#include "per_decoder.h"
#include "per_encoder.h"

/* Encode X2AP PDU ASN1 buffer*/
int X2AP_ASN_encode(X2AP_PDU_t *pdu, uint8_t **buffer, uint32_t *len)
{
  ssize_t    encoded;

  assert(pdu != NULL);
  assert(buffer != NULL);
  assert(len != NULL);

  encoded = aper_encode_to_new_buffer(&asn_DEF_X2AP_PDU, 0, pdu, (void **)buffer);

  if (encoded < 0)
  {
    return -1;
  }

  *len = encoded;

  ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_X2AP_PDU, pdu);
  return encoded;
}

/* Decode XASN1 buffer to X2AP PDU*/
int X2AP_ASN_decode(X2AP_PDU_t *pdu, const uint8_t *const buffer, const int len)
{
  asn_dec_rval_t dec_ret;

  assert(buffer != NULL);

  dec_ret = aper_decode(NULL, &asn_DEF_X2AP_PDU, (void **)&pdu, buffer,
                    len, 0, 0);

  //xer_fprint(stdout, &asn_DEF_X2AP_PDU, pdu);

  if (dec_ret.code != RC_OK) {
    fprintf(stderr, "ERROR: Failed to decode pdu\n");
    return -1;
  }

  return 0;
}
