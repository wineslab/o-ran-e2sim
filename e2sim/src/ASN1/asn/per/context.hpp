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
#include <climits>

// Local Includes: Application specific classes, functions, and libraries
#include "asn/utility.hpp"
#include "asn/buffer.hpp"
#include "asn/error_context.hpp"

namespace asn {
namespace per {

/********************************************************************************
EncoderCtx
*********************************************************************************/
class EncoderCtx : boost::noncopyable
{
public:
	typedef buffer<u8*> buf_type;

	EncoderCtx(u8* data, size_t size)
		: m_buffer{ m_errCtx }
	{
		Reset(data, size);
	}

	template <size_t SIZE>
	explicit EncoderCtx(u8(&buff)[SIZE])
		: EncoderCtx(buff, SIZE)
	{
	}

	explicit EncoderCtx()
		: EncoderCtx(nullptr, 0)
	{
	}

	buf_type& refBuffer() { return m_buffer; }
	error_context& refErrorCtx() { return m_errCtx; }
	explicit operator bool() const { return static_cast<bool>(m_errCtx); }

	void Reset(void* data = nullptr, size_t size = 0)
	{
		m_buffer.reset(static_cast<u8*>(data), size);
		m_errCtx.reset();
	}

	//Name of the being processed IE
	void ie_name(const char* name) { m_errCtx.ie_name(name); }
	char const* ie_name() const { return m_errCtx.ie_name(); }

	void container_name(const char* name) { m_errCtx.container_name(name); }
	char const* container_name() const { return m_errCtx.container_name(); }

private:
	template <class IE, int IE_TYPE>
	friend struct Encode;

	error_context			m_errCtx;
	buf_type				m_buffer;
};


/********************************************************************************
DecoderCtx
*********************************************************************************/
class DecoderCtx : boost::noncopyable
{
public:
	typedef buffer<u8 const*>	buf_type;
	typedef allocator			alloc_type;
	typedef u64					map_type;

	DecoderCtx(const void* data = nullptr, size_t size = 0, void* alloc_buffer = nullptr, size_t alloc_buffer_size = 0)
		: m_buffer{ m_errCtx }
	{
		reset(data, size, alloc_buffer, alloc_buffer_size);
	}

	buf_type& refBuffer() { return m_buffer; }
	alloc_type& refAllocator() { return m_allocator; }
	error_context& refErrorCtx() { return m_errCtx; }
	explicit operator bool() const { return static_cast<bool>(m_errCtx); }

	void reset(const void* data = nullptr, size_t size = 0, void* alloc_buffer = nullptr, size_t alloc_buffer_size = 0)
	{
		m_allocator.reset(alloc_buffer, alloc_buffer_size);
		m_buffer.reset(static_cast<u8 const*>(data), size);
		m_errCtx.reset();
		m_map = 0;
		m_container = nullptr;
	}

	bool map_elm()
	{
		//m_map = (m_map << 1) | (m_map >> (sizeof(m_map)*CHAR_BIT - 1));
		//return m_map & 1u;

		constexpr map_type mask = ((map_type)1) << (sizeof(map_type)*CHAR_BIT - 1);

		bool rv = m_map & mask;
		m_map = m_map << 1;

		return rv;
	}

	map_type set_map(map_type map)
	{
		map_type rval = m_map;
		m_map = map;
		return rval;
	}

	map_type get_map() const {return m_map;}

	//Pointer to container (SEQ | CHO)
	void*					m_container{ nullptr };

	//Name of the being processed IE
	void ie_name(const char* name) { m_errCtx.ie_name(name); }
	char const* ie_name() const { return m_errCtx.ie_name(); }

	void container_name(const char* name) { m_errCtx.container_name(name); }
	char const* container_name() const { return m_errCtx.container_name(); }

private:
	//Optional or Extension elements' presence bitmap. Used in sequences
	map_type				m_map{ 0 };
	error_context			m_errCtx;
	buf_type				m_buffer;
	alloc_type				m_allocator;
};

} //namespace per
} //namespace asn
