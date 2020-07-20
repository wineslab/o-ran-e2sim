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

// Local Includes: Application specific classes, functions, and libraries

namespace asn {

enum class class_type_t : uint8_t
{
	 UNIVERSAL
	,APPLICATION
	,CONTEXT
	,PRIVATE
  ,UNSPECIFIED //reserved for internal use
};

enum class tag_type_t : uint8_t
{
	 EXPLICIT
	,IMPLICIT
	,AUTOMATIC
};

using tag_value_t = uint64_t;

template<class_type_t CT,  tag_value_t TAG, tag_type_t TT = tag_type_t::IMPLICIT>
struct identifier
{
	static constexpr class_type_t	class_type = CT;
	static constexpr tag_value_t	tag_value = TAG;
	static constexpr tag_type_t		tag_type = TT;
};


enum class tag_rvalue_t : tag_value_t
{
	 BOOLEAN				= 1
	,INTEGER				= 2
	,BIT_STRING				= 3
	,OCTET_STRING			= 4
	,NULL_TYPE				= 5
	,OBJECT_IDENTIFIER		= 6
	,REAL					= 9
	,ENUMERATED				= 10
	,SEQUENCE				= 16
	,SEQUENCE_OF			= 16
	,UTF8String				= 12
	,NumericString			= 18
	,IA5String				= 22
	,VisibleString			= 26
	,DATE					= 31
	,TIME_OF_DAY			= 32
	,DATE_TIME				= 33
	,DURATION				= 34
	,ObjectDescriptor		= 7
	,EXTERNAL				= 8
	,EMBEDDED_PDV			= 11
	,OID_IRI				= 35
	,RELATIVE_OID_IRI		= 36
	,SET					= 17
	,SET_OF					= 17
	,UTCTime				= 23
	,GeneralizedTime		= 24
	,PrintableString		= 19
	,T61String 				= 20
	,VideotexString			= 21
	,GraphicString			= 25
	,GeneralString			= 27
	,UniversalString		= 28
	,CHARACTER_STRING		= 29
	,BMPString				= 30
	,ISO646String			= 26
	,TeletexString			= 20
  ,CHOICE            = 99 // fake id for internal use
};

} //namespace asn
