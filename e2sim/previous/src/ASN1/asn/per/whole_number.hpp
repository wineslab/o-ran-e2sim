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
#include <boost/integer/static_log2.hpp>

// Local Includes: Application specific classes, functions, and libraries
#include "asn/per/common.hpp"
#include "asn/per/binary_integer.hpp"

namespace asn {
namespace per {

/***************************************************************************************
* Encoding of a constrained whole number (X.691 10.5)
***************************************************************************************/

template<bound_t R, class E = void>
struct length_determinant;

template<bound_t R>
struct length_determinant<R, std::enable_if_t< R == 0 > > { static constexpr bound_t value = 0; };

template<bound_t R>
struct length_determinant<R, std::enable_if_t< R == 1 > > { static constexpr bound_t value = 1; };

template<bound_t R>
struct length_determinant<R, std::enable_if_t< (R  > 1) > > { static constexpr bound_t value = boost::static_log2<(R - 1)>::value + 1; };

/***************************************************************************************
***************************************************************************************/

template <class Range, class V, class Enable = void>
struct ConstrainedWholeNumber;

//Bit-field case
template <class Range, class V>
struct ConstrainedWholeNumber<Range, V, std::enable_if_t<(Range::upper_bound < (Range::lower_bound + 255))> >
{
	//non-negative-binary-integer X.691 10.5
	static void inline run(EncoderCtx& ctx, const V& val)
	{
		Tools::bit_accessor::put(static_cast<u8>(val - Range::lower_bound),
			length_determinant<(Range::upper_bound - Range::lower_bound + 1)>::value,
			ctx.refBuffer());
	}
	static V inline run(DecoderCtx& ctx)
	{
		return Range::lower_bound + Tools::bit_accessor::get(
			length_determinant<(Range::upper_bound - Range::lower_bound + 1)>::value,
			ctx.refBuffer());
	}
};

//One octet case
template <class Range, class V>
struct ConstrainedWholeNumber<Range, V, std::enable_if_t<(Range::upper_bound == (Range::lower_bound + 255))> >
{
	//non-negative-binary-integer X.691 10.5
	static void inline run(EncoderCtx& ctx, const V& val)
	{
		Tools::bit_accessor::padByte(ctx.refBuffer());
		ctx.refBuffer().putByte(static_cast<u8>(val - Range::lower_bound));
	}
	static V inline run(DecoderCtx& ctx)
	{
		V rval = 0;
		Tools::bit_accessor::padByte(ctx.refBuffer());
		u8 const* data = ctx.refBuffer().getBytes(1);
		if (data)
			rval = Range::lower_bound + data[0];
		return rval;
	}
};

//Two octets case
template <class Range, class V>
struct ConstrainedWholeNumber<Range, V, std::enable_if_t<(Range::upper_bound > (Range::lower_bound + 255)) && (Range::upper_bound <= (Range::lower_bound + 65535))> >
{
	//non-negative-binary-integer X.691 10.5
	static void inline run(EncoderCtx& ctx, const V& v)
	{
		u64 val = static_cast<u64>(v - Range::lower_bound);
		Tools::bit_accessor::padByte(ctx.refBuffer());
		ctx.refBuffer().putByte((u8)(val >> 8));
		ctx.refBuffer().putByte((u8)val);
	}
	static V inline run(DecoderCtx& ctx)
	{
		V rval = 0;
		Tools::bit_accessor::padByte(ctx.refBuffer());
		u8 const* data = ctx.refBuffer().getBytes(2);
		if (data) {
			rval = data[0];
			rval = rval << 8;
			rval |= data[1];
			rval += Range::lower_bound;
		}
		return rval;
	}
};

//Indefinite case
template <class Range, class V>
struct ConstrainedWholeNumber<Range, V, std::enable_if_t< (Range::upper_bound > Range::lower_bound + 65535) > >
{
	struct NormalizedValueRange
	{
		using boundary_type = typename Range::boundary_type;
		static constexpr bool extended = Range::extended;
		static constexpr boundary_type lower_bound = 0;
		static constexpr boundary_type upper_bound = Range::upper_bound - Range::lower_bound;
	};
	
	//non-negative-binary-integer X.691 10.5
	static void inline run(EncoderCtx& ctx, const V& val)
	{
		NonnegativeBinaryInteger<NormalizedValueRange>::run(val - Range::lower_bound, ctx);
	}
	static V inline run(DecoderCtx& ctx)
	{
		V rval = 0;
		NonnegativeBinaryInteger<NormalizedValueRange>::run(rval, ctx, false);
		return rval + Range::lower_bound;
	}
};

} //namespace per
} //namespace asn
