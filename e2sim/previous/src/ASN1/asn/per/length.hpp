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
#include <cmath>

// Local Includes: Application specific classes, functions, and libraries
#include "asn/per/common.hpp"
#include "asn/per/whole_number.hpp"

namespace asn {
namespace per {

/********************************************************************************
* Encoding of a length determinant (X.691 10.9)
*********************************************************************************/

template <class Range, class Enable = void>
struct LengthDeterminant;

struct LengthDeterminantDefault //Unconstrained length
{
	static u8 bytes_needed(size_t len)
	{
		if (len <= 127)
			return 1;
		return 2;
	}

	static void run(EncoderCtx& ctx, size_t len)
	{
		if (len <= 127)
		{
			Tools::bit_accessor::padByte(ctx.refBuffer());
			ctx.refBuffer().putByte(static_cast<u8>(len));
		}
		else if (len < 16384)
		{
			Tools::bit_accessor::padByte(ctx.refBuffer());
			len += 0x8000;
			ctx.refBuffer().putByte(static_cast<u8>(len >> 8));
			ctx.refBuffer().putByte(static_cast<u8>(len));
		}
		else
		{
			//todo: 10.9.3.8.1 for len >= 16K
		}
	}
	static size_t run(DecoderCtx& ctx)
	{
		size_t rval = 0;
		Tools::bit_accessor::padByte(ctx.refBuffer());

		u8 const* data = ctx.refBuffer().getBytes(1);
		if (data)
		{
			if (*data & 0x80)
			{
				rval = (*data & 0x7F) << 8;
				data = ctx.refBuffer().getBytes(1);
				if (data)
					rval |= *data;
			}
			else
				rval = *data;
		}
		return rval;
	}
};

//10.9.3.3
template <class Range>
struct LengthDeterminant<Range, std::enable_if_t<
	((Range::upper_bound < 65536) && (Range::extended == false))
>>
{
	static void run(EncoderCtx& ctx, size_t len)
	{
		ConstrainedWholeNumber<Range, size_t>::run(ctx, len);
	}
	static size_t inline run(DecoderCtx& ctx, bool extended_len)
	{
		return ConstrainedWholeNumber<Range, size_t>::run(ctx);
	}
};
template <class Range>
struct LengthDeterminant<Range, std::enable_if_t<
	((Range::upper_bound < 65536) && (Range::extended == true))
>>
{
	static void run(EncoderCtx& ctx, size_t len)
	{
		if (len > Range::upper_bound || len < Range::lower_bound)
			LengthDeterminantDefault::run(ctx, len);
		else
			ConstrainedWholeNumber<Range, size_t>::run(ctx, len);
	}
	static size_t inline run(DecoderCtx& ctx, bool extended_len)
	{
		if (extended_len)
			return LengthDeterminantDefault::run(ctx);

		return ConstrainedWholeNumber<Range, size_t>::run(ctx);
	}
};

template <class Range>
struct LengthDeterminant<Range, std::enable_if_t< (Range::upper_bound >= 65536) > >
{
	static void run(EncoderCtx& ctx, size_t len)
	{
		LengthDeterminantDefault::run(ctx, len);
	}
	static size_t inline run(DecoderCtx& ctx, bool extended_len)
	{
		return LengthDeterminantDefault::run(ctx);
	}
};

//10.9.3.4 : for "normally small length". bitmaps, sequence types
template <bound_t Length, class Enable = void>
struct NormallySmallLength;

template <bound_t Length>
struct NormallySmallLength<Length, std::enable_if_t<(Length <= 64)> >
{
	static_assert(Length > 0, "NormallySmallLength must be > 0");

	static void run(EncoderCtx& ctx)
	{
		Tools::bit_accessor::put((u8)(Length - 1), 7, ctx.refBuffer());
	}
	static size_t run(DecoderCtx& ctx)
	{
		u8 ext = Tools::bit_accessor::get(1, ctx.refBuffer());
		if (ext)
			return LengthDeterminantDefault::run(ctx);
		return Tools::bit_accessor::get(6, ctx.refBuffer()) + 1;
	}
};

template <bound_t Length>
struct NormallySmallLength<Length, std::enable_if_t<(Length > 64)> >
{
	static void run(EncoderCtx& ctx)
	{
		Tools::bit_accessor::put(1, 1, ctx.refBuffer());
		LengthDeterminantDefault::run(ctx, Length);
	}
};

/*
* BinaryIntegerLength
*/

template<bound_t N, class Enable = void>
struct NBytes
{
	static constexpr bound_t value = std::log2( N ) / 8 + 1;
};

template<bound_t N>
struct NBytes<N, std::enable_if_t< (N ==  0) > >
{
	static constexpr bound_t value = 1;
};

template<bound_t B1, bound_t B2, class Enable = void>
struct NRange
{
	static constexpr bound_t lower_bound = B1;
	static constexpr bound_t upper_bound = B2;
};

template<bound_t B1, bound_t B2>
struct NRange<B1, B2, std::enable_if_t<(B2 < B1)> >
{
	static constexpr bound_t lower_bound = B2;
	static constexpr bound_t upper_bound = B1;
};

template <class Range, class Enable>
struct BinaryIntegerLength
{
	typedef NRange<
		NBytes<Range::lower_bound>::value,
		NBytes<Range::upper_bound>::value
	> nrange;
	
	using boundary_type = typename Range::boundary_type;
	static constexpr bool extended = Range::extended;
	static constexpr bound_t lower_bound = nrange::lower_bound;
	static constexpr bound_t upper_bound = nrange::upper_bound;
	
	static void run(EncoderCtx& ctx, size_t len)
	{
		LengthDeterminant<BinaryIntegerLength>::run(ctx, len);
	}
	static size_t inline run(DecoderCtx& ctx, bool extended_len)
	{
		return LengthDeterminant<BinaryIntegerLength>::run(ctx, extended_len);
	}
};

template <class Range>
struct BinaryIntegerLength<Range, std::enable_if_t<
	(Range::type == constraint_type::SEMICONSTRAINED) || (Range::type == constraint_type::SEMICONSTRAINED_EXTENDED)
>>
{
	static void run(EncoderCtx& ctx, size_t len)
	{
		LengthDeterminantDefault::run(ctx, len);
	}
	static size_t inline run(DecoderCtx& ctx, bool extended_len)
	{
		return LengthDeterminantDefault::run(ctx);
	}
};

} //namespace per
} //namespace asn
