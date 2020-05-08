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

#include "Pendulum_asn_codec.h"
#include "per_decoder.h"
#include "per_encoder.h"

#include "OCTET_STRING.h"

static int ASN_DEBUG = 0;

int pendulum_asn_encode(Pendulum_t *pend, uint8_t **buffer, uint32_t *len)
{
  ssize_t encoded;
  assert(pend != NULL);
  assert(buffer != NULL);

  encoded = aper_encode_to_new_buffer(&asn_DEF_Pendulum, 0, pend, (void **)buffer);
  if(encoded < 0){
    perror("Failed to aper encode\n");
    exit(1);
  }

  *len = encoded;
  //ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_Pendulum, pend);
  return encoded;
}

int pendulum_asn_decode(Pendulum_t *pend, const uint8_t *const buffer, const int len)
{
  asn_dec_rval_t dec_ret;

  // THIS IS IMPORTANT, otherwise: Segmentation fault
  memset(pend, 0, sizeof(*pend));

  assert(buffer != NULL);

  dec_ret = aper_decode(NULL, &asn_DEF_Pendulum, (void **)&pend, buffer, len, 0, 0);
  if (dec_ret.code != RC_OK) {
    fprintf(stderr, "ERROR: Failed to decode asn1 message\n");
    return -1;
  }

  if(ASN_DEBUG)
    xer_fprint(stdout, &asn_DEF_Pendulum, pend);

  return 0;
}

int pendulum_create_asn_msg(uint8_t **buffer, long sequence,
  double angle, double torque, const char* msg)
{
  //Create Pendulum payload struct
  Pendulum_t *pend;

  pend = calloc(1, sizeof(Pendulum_t));
  if(!pend){
    perror("calloc() failed");
    exit(1);
  }

  //convert char* to PrintableString_t*
  PrintableString_t  *payload = calloc(1, sizeof(PrintableString_t));
  payload->buf = (uint8_t *)msg;
  payload->size = strlen(msg);

  pend->strval    = payload;
  pend->sequence  = &sequence;
  pend->angle     = &angle;
  pend->torque    = &torque;

  if (ASN_DEBUG)
    xer_fprint(stdout, &asn_DEF_Pendulum, pend);

  //Encode Pendulum payload struct to asn1 buffer
  uint32_t  len;
  if(pendulum_asn_encode(pend, buffer, &len) < 0)
  {
    return -1;
  }
  //fprintf(stderr, "len = %d\n", len);

  return len;
}

long pendulum_get_sequence(const uint8_t *const buffer, const int len)
{
  Pendulum_t pend;
  pendulum_asn_decode(&pend, buffer, len);

  return *(pend.sequence);
}

double pendulum_get_angle(const uint8_t *const buffer, const int len)
{
  Pendulum_t pend;
  pendulum_asn_decode(&pend, buffer, len);

  return *(pend.angle);
}

double pendulum_get_torque(const uint8_t *const buffer, const int len)
{
  Pendulum_t pend;
  pendulum_asn_decode(&pend, buffer, len);

  return *(pend.torque);
}

char* pendulum_get_strval(const uint8_t *const buffer, const int len)
{
  Pendulum_t pend;
  char* str;

  pendulum_asn_decode(&pend, buffer, len);

  str = (char*)pend.strval->buf;

  return str;
}

void test_pendulum_msg(void)
{
  uint8_t   *buffer = NULL;
  uint32_t  len = 0;
  double    angle = 1.9;
  len = pendulum_create_asn_msg(&buffer, 0, angle, 0, NULL);

  double ex_angle = pendulum_get_angle(buffer, len);
  fprintf(stderr, "Extracted angle = %f\n", ex_angle);
}

void test_pendulum_asn1(void)
{
  fprintf(stderr, "test_pendulum_asn1\n");

  Pendulum_t *pend;

  long	sequence = 0;	/* OPTIONAL */
  double	angle = 1.5;	/* OPTIONAL */
  //double	torque = 0.7;	/* OPTIONAL */

  pend = calloc(1, sizeof(Pendulum_t));
  if(!pend){
    perror("calloc() failed");
    exit(1);
  }

  pend->sequence  = &sequence;
  pend->angle     = &angle;
  //pend->torque    = &torque;

  xer_fprint(stdout, &asn_DEF_Pendulum, pend);

  //encode
  uint8_t   *buffer = NULL;
  uint32_t  len;
  pendulum_asn_encode(pend, &buffer, &len);
  fprintf(stderr, "len = %d\n", len);

  //decode
  Pendulum_t dec_pend;
  pendulum_asn_decode(&dec_pend, buffer, len);
}
