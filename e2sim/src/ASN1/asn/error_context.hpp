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
#include "type_defs.h"

namespace asn {

class error_context
{
public:
	enum error_e : u8
	{
		SUCCESS = 0
		,INCORRECT_LENGTH_BITS
		,INCORRECT_LENGTH_BYTES
		,ALIGNMENT
		,INCORRECT_VALUE
		,INCORRECT_CHOICE_TAG
		,INCORRECT_IE_TAG
		,VALUE_OUT_OF_RANGE
		,SIZE_OUT_OF_RANGE
		,ALLOC_NO_MEMORY
		,NO_OBJECT
		,NO_MANDATORY
		,WRONG_END_OF_CONTENT
		,UNSUPPORTED
		,UNSPECIFIED
	};

	explicit operator bool() const          { return SUCCESS == m_error; }

	void reset()                            { m_error = SUCCESS; }
	error_e getError() const                { return m_error; }

	char const* toString() const;

	void alignmentError(u32 shift);
	void lengthErrorBytes(u32 bytes_left, u32 requested);
	void lengthErrorBits(u32 bits_left, u32 requested);
	void valueError(u32 got, u32 expected, u32 ofs);
	void tagError(u32 tag);
	void valueRangeError(size_t value);
	void sizeRangeError(size_t size, size_t low = 0, size_t high = 0);
	void allocatorNoMem(size_t bytes_left, size_t bytes_required);
	void errorUnsupported() {setError(UNSUPPORTED);}
	void errorUnspecified() {setError(UNSPECIFIED);}
	void errorNoObject(const char* container_name_);
	void errorNoMandatory();
	void errorWrongEndOfContent() {setError(WRONG_END_OF_CONTENT);}

	//to inline in choice decoder: TODO: think of changing it!
	void choiceError(char const* name, u32 id)
	{
		m_name = name;
		m_param[0] = id;
		setError(INCORRECT_CHOICE_TAG);
	}
	//Name of the being processed IE
	void ie_name(const char* name)			{ m_ie_name = name; }
	char const* ie_name() const				{ return m_ie_name; }

	void container_name(const char* name)	{ m_container_name = name; }
	char const* container_name() const		{ return m_container_name; }


private:
	void setError(error_e n)                { m_error = n; }

	enum { MAX_PARAMS = 3 };
	error_e     m_error;
	char const* m_name;
	char const* m_ie_name {""};
	char const* m_container_name {""};
	size_t      m_param[MAX_PARAMS];

};

inline
void error_context::errorNoObject(const char* c_name)
{
	container_name(c_name);
	m_name = m_ie_name;
	setError(NO_OBJECT);
}

inline
void error_context::errorNoMandatory()
{
	m_name = m_ie_name;
	setError(NO_MANDATORY);
}

inline
void error_context::alignmentError(u32 shift)
{
	m_name = m_ie_name;
	m_param[0] = shift;
	setError(ALIGNMENT);
}

inline
void error_context::lengthErrorBytes(u32 bytes_left, u32 requested)
{
	m_name = m_ie_name;
	m_param[0] = bytes_left;
	m_param[1] = requested;
	setError(INCORRECT_LENGTH_BYTES);
}

inline
void error_context::lengthErrorBits(u32 bits_left, u32 requested)
{
	m_name = m_ie_name;
	m_param[0] = bits_left;
	m_param[1] = requested;
	setError(INCORRECT_LENGTH_BITS);
}

inline
void error_context::valueError(u32 got, u32 expected, u32 ofs)
{
	m_name = m_ie_name;
	m_param[0] = got;
	m_param[1] = expected;
	m_param[2] = ofs;
	setError(INCORRECT_VALUE);
}

inline
void error_context::tagError(u32 tag)
{
	m_name = m_ie_name;
	m_param[0] = tag;
	setError(INCORRECT_IE_TAG);
}

inline
void error_context::valueRangeError(size_t value)
{
	m_name = m_ie_name;
	m_param[0] = value;
	setError(VALUE_OUT_OF_RANGE);
}

inline
void error_context::sizeRangeError(size_t size, size_t low, size_t high)
{
	m_name = m_ie_name;
	m_param[0] = size;
	m_param[1] = low;
	m_param[2] = high;
	setError(SIZE_OUT_OF_RANGE);
}

inline
void error_context::allocatorNoMem(size_t bytes_left, size_t bytes_required)
{
	m_name = m_ie_name;
	m_param[0] = bytes_left;
	m_param[1] = bytes_required;
	setError(ALLOC_NO_MEMORY);
}

inline
char const* error_context::toString() const
{
	static char sz[256];

	switch (m_error)
	{
	case SUCCESS:
		return "OK";

	case INCORRECT_LENGTH_BITS:
		snprintf(sz, sizeof(sz)-1, "%zu bits left, '%s::%s' needs %zu", m_param[0], m_container_name, m_name, m_param[1]);
		break;

	case INCORRECT_LENGTH_BYTES:
		snprintf(sz, sizeof(sz)-1, "%zu bytes left, '%s::%s' needs %zu", m_param[0], m_container_name, m_name, m_param[1]);
		break;
	case ALIGNMENT:
		snprintf(sz, sizeof(sz)-1, "misaligned '%s::%s': shift %zu bits", m_container_name, m_name, m_param[0]);
		break;

	case INCORRECT_VALUE:
		snprintf(sz, sizeof(sz)-1, "Wrong value of '%s::%s' at %zu: 0x%zX expected=0x%zX", m_container_name, m_name, m_param[2], m_param[0], m_param[1]);
		break;

	case INCORRECT_CHOICE_TAG:
		snprintf(sz, sizeof(sz)-1, "Wrong choice tag of '%s::%s': %zu (0x%zX)", m_container_name, m_name, m_param[0], m_param[0]);
		break;

	case INCORRECT_IE_TAG:
		snprintf(sz, sizeof(sz)-1, "Wrong tag of '%s::%s': %zu (0x%zX)", m_container_name, m_name, m_param[0], m_param[0]);
		break;

	case VALUE_OUT_OF_RANGE:
		snprintf(sz, sizeof(sz) - 1, "Value is out of the range '%s::%s': value: %zu", m_container_name, m_name, m_param[0]);
		break;

	case SIZE_OUT_OF_RANGE:
		if (m_param[2])
		{
			snprintf(sz, sizeof(sz) - 1, "Size=%zu bytes is out of the range [%zu, %zu] in '%s::%s'", m_param[0], m_param[1], m_param[2], m_container_name, m_name);
		}
		else
		{
			if (m_param[1])
			{
				snprintf(sz, sizeof(sz) - 1, "Size=%zu bytes is less than %zu in '%s::%s'", m_param[0], m_param[1], m_container_name, m_name);
			}
			else
			{
				snprintf(sz, sizeof(sz) - 1, "Size=%zu bytes is out of the range in '%s::%s'", m_param[0], m_container_name, m_name);
			}
		}
		break;

	case ALLOC_NO_MEMORY:
		snprintf(sz, sizeof(sz) - 1, "Allocator memory has ended '%s::%s': left bytes: %zu; required bytes: %zu", m_container_name, m_name, m_param[0], m_param[1]);
		break;
	case NO_OBJECT:
		snprintf(sz, sizeof(sz) - 1, "Component relation constraint violated '%s::%s'", m_container_name, m_name);
		break;
	case NO_MANDATORY:
		snprintf(sz, sizeof(sz) - 1, "no mandatory '%s::%s' is found", m_container_name, m_name);
		break;
	case UNSUPPORTED:
		snprintf(sz, sizeof(sz) - 1, "unsupported object '%s::%s' is found", m_container_name, m_name);
		return "unsupported";
		break;
	case UNSPECIFIED:
		snprintf(sz, sizeof(sz) - 1, "unspecified object '%s::%s' is found", m_container_name, m_name);
		return "unspecified";
		break;
	case WRONG_END_OF_CONTENT:
		snprintf(sz, sizeof(sz) - 1, "wrong end of content in object '%s::%s'", m_container_name, m_name);
		return "wrong end of content";
		break;
	}

	return sz;
}

}	//end: namespace asn
