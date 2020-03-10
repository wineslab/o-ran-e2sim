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

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include "x2ap_generate_messages.h"
#include "x2ap_asn_codec.h"
#include "e2sim_defs.h"

int asn1_xer_print = 0;
int MAX_XML_BUFFER = 10000;

void x2ap_fetch_pdu_from_XML(X2AP_PDU_t **pdu, char *filename)
{

  uint8_t         buf[MAX_XML_BUFFER];

  asn_dec_rval_t  rval;
  size_t          size;
  FILE            *f;

  char XML_path[200];
  char *work_dir = getenv(WORKDIR_ENV);

  strcpy(XML_path, work_dir);
  strcat(XML_path, "/src/X2AP/MESSAGES/XML/");
  strcat(XML_path, filename);

  //printf("Generate X2AP PDU from XML file: %s\n", XML_path);

  f = fopen(XML_path, "r");
  assert(f);
  size = fread(buf, 1, sizeof(buf), f);
  if(size == 0 || size == sizeof(buf))
  {
    fprintf(stderr, "%s: Too large input\n", XML_path);
    exit(1);
  }

  fclose(f);

  //printf("Decode the XER buffer\n");
  rval = xer_decode(NULL, &asn_DEF_X2AP_PDU, (void **)pdu, buf, size);
  assert(rval.code == RC_OK);

}

uint32_t x2ap_generate_x2_setup_request(uint8_t **buffer)
{
  X2AP_PDU_t *pdu;
  pdu = (X2AP_PDU_t *)calloc(1, sizeof(X2AP_PDU_t));

  uint32_t len;

  char *XML_file = "sample_x2_setup_request.xml";

  x2ap_fetch_pdu_from_XML(&pdu, XML_file);

  if(asn1_xer_print)
    xer_fprint(stdout, &asn_DEF_X2AP_PDU, (void *)pdu);

  if(X2AP_ASN_encode(pdu, buffer, &len) < 0)
  {
    fprintf(stderr, "Failed to APER encode X2 Setup Request\n");
    return -1;
  }

  return len;

}

uint32_t x2ap_generate_x2_setup_response(uint8_t **buffer)
{
  X2AP_PDU_t *pdu;
  pdu = (X2AP_PDU_t *)calloc(1, sizeof(X2AP_PDU_t));

  uint32_t len;

  char *XML_file = "sample_x2_setup_response.xml";

  x2ap_fetch_pdu_from_XML(&pdu, XML_file);

  if(asn1_xer_print)
    xer_fprint(stdout, &asn_DEF_X2AP_PDU, (void *)pdu);

  if(X2AP_ASN_encode(pdu, buffer, &len) < 0)
  {
    fprintf(stderr, "Failed to APER encode X2 Setup Request\n");
    return -1;
  }

  return len;

}
