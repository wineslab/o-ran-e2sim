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
#include "asn/per/common.hpp"

namespace asn {
namespace per {

/********************************************************************************
VisitorEncoder
*********************************************************************************/
struct VisitorEncoder
{
	explicit VisitorEncoder(EncoderCtx& ctx) : m_ctx(ctx) {}

	template <typename IE>
	bool operator() (IE const& ie) const
	{
		Element<IE, IE::ie_type>::run(ie, m_ctx);
		return static_cast<bool>(m_ctx);
	}
	EncoderCtx&		m_ctx;
};

/********************************************************************************
VisitorDecoder
*********************************************************************************/
struct VisitorDecoder
{
	VisitorDecoder(DecoderCtx& ctx) : m_ctx(ctx) {}

	template <typename IE>
	bool operator() (IE& ie) const
	{
		Element<IE, IE::ie_type>::run(ie, m_ctx);
		return static_cast<bool>(m_ctx);
	}
	DecoderCtx& m_ctx;
};

/***************************************************************************************
* Open Type Visitor // Encode Open Type (10.2)
***************************************************************************************/
struct OpenTypeVisitorEncoder
{
	explicit OpenTypeVisitorEncoder(EncoderCtx& ctx) : m_ctx(ctx) {}

	template <typename IE>
	bool operator() (IE const& ie) const
	{
		size_t reserved_size = 1; //1 byte length is most likely
		Tools::bit_accessor::padByte(m_ctx.refBuffer());

		if (m_ctx.refBuffer().getBytesLeft())
		{
			EncoderCtx::buf_type::pointer p = m_ctx.refBuffer().advance(reserved_size);
			EncoderCtx::buf_type::pointer start = p + reserved_size;

			Element<IE, IE::ie_type>::run(ie, m_ctx);

			if (m_ctx)
			{
				Tools::bit_accessor::padByte(m_ctx.refBuffer());
				EncoderCtx::buf_type::pointer p_new = m_ctx.refBuffer().begin();
				size_t size = p_new - start;
				size_t needed = LengthDeterminantDefault::bytes_needed(size) - reserved_size;
				if (needed) //1 byte is not enough for the length determinant. it is hardly possible
				{
					if (m_ctx.refBuffer().getBytesLeft() < needed) {
						m_ctx.refErrorCtx().lengthErrorBytes(m_ctx.refBuffer().getBytesLeft(), needed);
						return false;
					}
					memmove(start + needed, start, size);
					p_new += needed;
				}
				m_ctx.refBuffer().set_begin(p, 0);
				LengthDeterminantDefault::run(m_ctx, size);
				if (m_ctx) {
					m_ctx.refBuffer().set_begin(p_new, 0);
					Tools::bit_accessor::padByte(m_ctx.refBuffer());
				}
			}
		}
		else
		{
			m_ctx.refErrorCtx().lengthErrorBytes(m_ctx.refBuffer().getBytesLeft(), reserved_size);
		}
		return static_cast<bool>(m_ctx);
	}
	EncoderCtx& m_ctx;
};

/***************************************************************************************
* Open Type Visitor // Decode Open Type (10.2)
***************************************************************************************/
struct OpenTypeVisitorDecoder
{
	explicit OpenTypeVisitorDecoder(DecoderCtx& ctx) : m_ctx(ctx) {}

	template <typename IE>
	bool operator() (IE& ie) const
	{
		size_t size = LengthDeterminantDefault::run(m_ctx);
		DecoderCtx::buf_type& buffer = m_ctx.refBuffer();
		if (buffer.getBytesLeft() < size)
		{
			m_ctx.refErrorCtx().lengthErrorBytes(buffer.getBytesLeft(), size);
			return false;
		}
		DecoderCtx::buf_type::pointer end = buffer.end();
		buffer.set_end(buffer.begin() + size);
		Element<IE, IE::ie_type>::run(ie, m_ctx);
		buffer.set_end(end);

		return static_cast<bool>(m_ctx);
	}
	DecoderCtx& m_ctx;
};

} //namespace per
} //namespace asn
