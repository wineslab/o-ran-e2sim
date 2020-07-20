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

#ifndef PENDULUM_ASN_CODEC_H_
#define PENDULUM_ASN_CODEC_H_

#include "Pendulum.h"

int pendulum_asn_encode(Pendulum_t *pend, uint8_t **buffer, uint32_t *len);

int pendulum_asn_decode(Pendulum_t *pend, const uint8_t *const buffer, const int len);

int pendulum_create_asn_msg(uint8_t **buffer, long sequence,
  double angle, double torque, const char* msg);

long pendulum_get_sequence(const uint8_t *const buffer, const int len);

double pendulum_get_angle(const uint8_t *const buffer, const int len);

double pendulum_get_torque(const uint8_t *const buffer, const int len);

char*  pendulum_get_strval(const uint8_t *const buffer, const int len);

//For testing only

void test_pendulum_msg(void);

void test_pendulum_asn1(void);

#endif
