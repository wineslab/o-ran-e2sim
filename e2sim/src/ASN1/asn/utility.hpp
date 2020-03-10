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
#include <new>
#include <memory>

// Local Includes: Application specific classes, functions, and libraries

namespace asn
{

struct allocator
{
	allocator() = default;

	allocator(void* data, size_t size) { reset(data, size); }

	template <typename T, std::size_t SZ>
	explicit allocator(T (&buf)[SZ]) : allocator(buf, SZ * sizeof(T)) { }

	void reset(void* data, size_t size)
	{
		std::size_t space = size;
		m_begin = static_cast<uint8_t*>(std::align(alignment, size, data, space));
		m_end = m_begin ? m_begin + space : nullptr;
		m_current = m_begin;
		m_ref_counter = 0;
	}

	uint8_t* alloc_bytes(std::size_t size)
	{
		std::size_t const esize = (size + alignment - 1) & -alignment;
		if (m_current + esize > m_end) { return nullptr; } //throw std::bad_alloc();

		uint8_t* const rval = m_current;
		m_current += esize;
		return rval;
	}

	size_t add_ref() { return ++m_ref_counter; }
	size_t release()
	{
		if (m_ref_counter) --m_ref_counter;
		if (m_ref_counter == 0) reset();
		return m_ref_counter;
	}
	size_t ref_counter() const { return m_ref_counter; }
private:
	//called by last release() when m_ref_counter becomes 0
	void reset()
	{
		m_current = m_begin;
	}


	enum : std::size_t
	{
		alignment = alignof(std::size_t)
	};

	uint8_t* m_begin { nullptr };		//set in reset()
	uint8_t* m_current { nullptr };		//changed by alloc_bytes
	uint8_t* m_end { nullptr };

	size_t m_ref_counter {0};
};

} //namespace asn

