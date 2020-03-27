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
#include "asn/per/length.hpp"

namespace asn {
namespace per {

template <class Range, class Enable = void>
struct BinaryIntegerLength;

/***************************************************************************************
* Encoding of a non-negative-binary-integer (X.691 10.3)
***************************************************************************************/
template <class Range>
struct NonnegativeBinaryInteger
{
	static void inline run(u64 val, EncoderCtx& ctx)
	{
		if(val)
		{
			size_t const len = sizeof(val) - (__builtin_clzll(val) >> 3);
			
			BinaryIntegerLength< Range >::run(ctx, len);
			Tools::bit_accessor::padByte(ctx.refBuffer());
					
			u8 buff[len];
			size_t shift = (len - 1) << 3;
			for(size_t i = 0; i < len; ++i)
			{
				buff[i] = static_cast<uint8_t>(val >> shift);
				shift -= 8;
			}
			
			ctx.refBuffer().putBytes(buff, len);
		}
		else
		{
			BinaryIntegerLength< Range >::run(ctx, 1);
			Tools::bit_accessor::padByte(ctx.refBuffer());
			ctx.refBuffer().putByte(0);
		}
	}
	template<typename T>
	static void inline run(T& retval, DecoderCtx& ctx, bool extended_val)
	{
		retval = 0;
		size_t len = (size_t)BinaryIntegerLength< Range >::run(ctx, extended_val);
		Tools::bit_accessor::padByte(ctx.refBuffer());
		u8 const* data = ctx.refBuffer().getBytes(len);

		if (data)
		{
			for (size_t i = 0; i < len; ++i)
			{
				retval = retval << 8;
				retval |= data[i];
			}
		}
	}
};

/***************************************************************************************
* Encoding of a 2's-complement-binary-integer (X.691 10.4)
***************************************************************************************/

template <class IE>
struct TwosComplementBinaryInteger
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		Tools::bit_accessor::padByte(ctx.refBuffer());

		u64 val = ie.get();
		u64 tval = val;
		u64 mask = static_cast<u64>(-128);
		u8 len = 1;
		u8 i = 7;

		u8 buf[8];

		while (len < 8)
		{
			buf[i] = static_cast<u8>(tval);
			if (!(val & mask) || (val & mask) == mask)
				break;
			mask = mask << 8;
			tval = tval >> 8;
			len++;
			i--;
		}

		ctx.refBuffer().putByte(len) && ctx.refBuffer().putBytes(&buf[i], len);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		Tools::bit_accessor::padByte(ctx.refBuffer());

		u8 const* data = nullptr;
		typename IE::value_type val = 0;

		u8 const* len = ctx.refBuffer().getBytes(1);

		if (len && (*len) <= 8 && (data = ctx.refBuffer().getBytes(*len)))
		{
			for (u8 i = 0; i < *len; ++i)
			{
				val = val << 8;
				val |= data[i];
			}
		}
		ie.set(val);
	}
};

/***************************************************************************************
* Encoding of a normally small non-negativebinary integer (X.691 10.6)
***************************************************************************************/
template <class IE, typename TValue = typename IE::value_type>
struct NormallySmallNonnegativeBinaryInteger
{
	static void inline run(IE const& ie, EncoderCtx& ctx, typename IE::constraint_t::boundary_type val)
	{
		if (val <= 63)
		{
			Tools::bit_accessor::put(static_cast<u8>(val), 7, ctx.refBuffer()); //7 bits ('0' indicator + value)
		}
		else
		{
			Tools::bit_accessor::put(1, 1, ctx.refBuffer()); //1 bit ('1' indicator)
			NonnegativeBinaryInteger<typename IE::constraint_t>::run(val, ctx);
		}
	}
	static TValue inline run(DecoderCtx& ctx)
	{
		u8 ext = Tools::bit_accessor::get(1, ctx.refBuffer());
		if (ext) {
			TValue rval = 0;
			NonnegativeBinaryInteger<typename IE::constraint_t>::run(rval, ctx, true);
			return rval;
		}
		return Tools::bit_accessor::get(6, ctx.refBuffer());
	}
};

} //namespace per
} //namespace asn
