#pragma once
/******************************************************************************
*
*   Copyright (c) 2019 AT&T Intellectual Property.
*   Copyright (c) 2018-2019 Nokia.
*
*   Licensed under the Apache License, Version 2.0 (the "License");
*   you may not use this file except in compliance with the License.
*   You may obtain a copy of the License at
*
*       http://www.apache.org/licenses/LICENSE-2.0
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.
*
******************************************************************************/

// Standard Includes: ANSI C/C++, MSA, and Third-Party Libraries
#include <cstdio>

// Local Includes: Application specific classes, functions, and libraries
#include "asn/asn.hpp"
#include "asn/buffer.hpp"
#include "asn/ber/context.hpp"
#include "asn/ber/tools.hpp"

//#define ASN_DECODER_TRACE_ENABLE
//#define ASN_ENCODER_TRACE_ENABLE

#ifdef ASN_DECODER_TRACE_ENABLE
#define ASN_DECODER_TRACE(FMT, ...) printf(FMT "\n", __VA_ARGS__)
#else
#define ASN_DECODER_TRACE(...)
#endif

#ifdef ASN_ENCODER_TRACE_ENABLE
#define ASN_ENCODER_TRACE(FMT, ...) printf(FMT "\n", __VA_ARGS__)
#else
#define ASN_ENCODER_TRACE(...)
#endif

namespace asn {
namespace ber {

template <class IE> struct Element;

} //namespace ber
} //namespace asn
