#pragma once

/*******************************************************************************
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
*******************************************************************************/

// Standard Includes: ANSI C/C++, MSA, and Third-Party Libraries
#include <cstdint>
#include <new> //std::bad_alloc
#include <array>
#include <list>

// Platform Includes: Platform specific classes, functions, and libraries

// Local Includes: Application specific classes, functions, and libraries

namespace asn {

template <class ALLOC>
class chunked_allocator
{
public:
	using allocator_t = ALLOC;

	chunked_allocator()
	{
		put_chunk(new_chunk());
	}

	template<class TSEQ>
	decltype(auto) emplace_back(TSEQ& v)
	{
		try
		{
			return v.emplace_back(m_allocator);
		}
		catch (std::bad_alloc const&)
		{
			put_chunk(new_chunk());
			return v.emplace_back(m_allocator);
		}
	}

	uint8_t* alloc_bytes(std::size_t sz)
	{
		//TODO: unify allocation: now it returns nullptr instead of throw!
		auto* ret = m_allocator.alloc_bytes(sz);
		if (!ret)
		{
			put_chunk(new_chunk());
			ret = m_allocator.alloc_bytes(sz);
		}
		return ret;
	}

private:
	static constexpr std::size_t CHUNK_SIZE = 32*1024;
	using chunk_t = std::array<uint8_t, CHUNK_SIZE>;
	using chunks_t = std::list<chunk_t>;

	chunk_t& new_chunk()        { return m_chunks.emplace_back(); }
	void put_chunk(chunk_t& c)  { m_allocator.reset(c.data(), c.size()); }


	allocator_t m_allocator;
	chunks_t    m_chunks;
};

}	//end: namespace asn
