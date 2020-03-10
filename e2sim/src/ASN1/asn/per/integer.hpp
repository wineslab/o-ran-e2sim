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
#include "asn/elements.hpp"
#include "asn/per/common.hpp"
#include "asn/per/binary_integer.hpp"
#include "asn/per/whole_number.hpp"

namespace asn {
namespace per {

template<class IE, class Enable = void>
struct Integer;

template<class IE>
struct Integer<IE, std::enable_if_t<IE::constraint_t::type == constraint_type::CONSTRAINED> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		if(IE::constraint_t::is_extended(ie.get()))
		{
			ctx.refErrorCtx().valueRangeError(static_cast<size_t>(ie.get()));
			return;
		}
		ConstrainedWholeNumber<typename IE::constraint_t, typename IE::value_type>::run(ctx, ie.get());
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		ie.set(ConstrainedWholeNumber<typename IE::constraint_t, typename IE::value_type>::run(ctx));
	}
};

template<class IE>
struct Integer<IE, std::enable_if_t<IE::constraint_t::type == constraint_type::CONSTRAINED_EXTENDED> >
{
	//X.691 12.1
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		if (!IE::constraint_t::is_extended(ie.get()))
		{
			Tools::bit_accessor::put(0, 1, ctx.refBuffer());
			//X.691 12.2
			ConstrainedWholeNumber<typename IE::constraint_t, typename IE::value_type>::run(ctx, ie.get());
		}
		else
		{
			Tools::bit_accessor::put(1, 1, ctx.refBuffer());
			//X.691 12.2.4, 12.2.6, 10.8s
			TwosComplementBinaryInteger<IE>::run(ie, ctx);
		}
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{

		u8 ext = Tools::bit_accessor::get(1, ctx.refBuffer());
		if (ext)
			TwosComplementBinaryInteger<IE>::run(ie, ctx);
		else
			ie.set(ConstrainedWholeNumber<typename IE::constraint_t, typename IE::value_type>::run(ctx));
	}
};

// (X.691 10.7)
template<class IE>
struct Integer<IE, std::enable_if_t<IE::constraint_t::type == constraint_type::SEMICONSTRAINED> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		if(IE::constraint_t::is_extended(ie.get()))
		{
			ctx.refErrorCtx().valueRangeError(static_cast<size_t>(ie.get()));
			return;
		}
		NonnegativeBinaryInteger<typename IE::constraint_t>::run(ie.get() - IE::constraint_t::lower_bound, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		typename IE::value_type val = 0;
		NonnegativeBinaryInteger<typename IE::constraint_t>::run(val, ctx, false);
		ie.set(IE::constraint_t::lower_bound + val);
	}
};

template<class IE>
struct Integer<IE, std::enable_if_t<IE::constraint_t::type == constraint_type::SEMICONSTRAINED_EXTENDED> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		if (!IE::constraint_t::is_extended(ie.get()))
		{
			Tools::bit_accessor::put(0, 1, ctx.refBuffer());
			NonnegativeBinaryInteger<typename IE::constraint_t>::run(ie.get() - IE::constraint_t::lower_bound, ctx);
		}
		else
		{
			Tools::bit_accessor::put(1, 1, ctx.refBuffer());
			TwosComplementBinaryInteger<IE>::run(ie, ctx);
		}
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		u8 ext = Tools::bit_accessor::get(1, ctx.refBuffer());

		if (ext)
			TwosComplementBinaryInteger<IE>::run(ie, ctx);
		else
		{
			typename IE::value_type val = 0;
			NonnegativeBinaryInteger<typename IE::constraint_t>::run(val, ctx, false);
			ie.set(val + IE::constraint_t::lower_bound);
		}
	}
};

/***************************************************************************************
* Encoding of an unconstrained whole number (X.691 10.8)
***************************************************************************************/

template<class IE>
struct Integer<IE, std::enable_if_t<IE::constraint_t::type == constraint_type::UNCONSTRAINED> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		TwosComplementBinaryInteger<IE>::run(ie, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		TwosComplementBinaryInteger<IE>::run(ie, ctx);
	}
};

} //namespace per
} //namespace asn

