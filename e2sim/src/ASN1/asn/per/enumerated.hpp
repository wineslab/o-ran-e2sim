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
#include "asn/per/whole_number.hpp"
#include "asn/per/binary_integer.hpp"

namespace asn {
namespace per {

template<class IE, class Enable = void>
struct Enumerated;

template<class IE>
struct Enumerated<IE, std::enable_if_t<(IE::constraint_t::type == constraint_type::CONSTRAINED)> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		if (ie.get() > IE::constraint_t::upper_bound)
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
struct Enumerated<IE, std::enable_if_t<(IE::constraint_t::type == constraint_type::CONSTRAINED_EXTENDED)> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		if (ie.get() <= IE::constraint_t::upper_bound)
		{
			Tools::bit_accessor::put(0, 1, ctx.refBuffer());
			ConstrainedWholeNumber<typename IE::constraint_t, typename IE::value_type>::run(ctx, ie.get());
		}
		else
		{
			Tools::bit_accessor::put(1, 1, ctx.refBuffer());
			NormallySmallNonnegativeBinaryInteger<IE>::run(ie, ctx, ie.get() - IE::constraint_t::upper_bound - 1);
		}
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		u8 ext = Tools::bit_accessor::get(1, ctx.refBuffer());
		if (ext)
			ie.set(IE::constraint_t::upper_bound + 1 + NormallySmallNonnegativeBinaryInteger<IE>::run(ctx));
		else
			ie.set(ConstrainedWholeNumber<typename IE::constraint_t, typename IE::value_type>::run(ctx));
	}
};

} //namespace per
} //namespace asn
