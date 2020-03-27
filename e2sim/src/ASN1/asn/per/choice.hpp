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
#include "asn/per/visitor.hpp"

namespace asn {
namespace per {

/********************************************************************************
Choice
*********************************************************************************/

/**************************************************/
//22.6-7 Default
template <class IE, class Enabler = void>
struct ChoiceNoExt
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		ConstrainedWholeNumber<typename IE::constraint_t, typename IE::index_type>::run(ctx, IE::normalize(ie.get_index()));
		VisitorEncoder ve{ ctx };
		ie.encode(ve);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		typename IE::index_type idx = ConstrainedWholeNumber<typename IE::constraint_t, typename IE::index_type>::run(ctx);
		VisitorDecoder ve{ ctx };
		ie.decode(IE::denormalize(idx), ve);
	}
};

//22.4 One alternative 
template <class IE>
struct ChoiceNoExt<IE, std::enable_if_t<(IE::constraint_t::upper_bound == 0)> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		VisitorEncoder ve{ ctx };
		ie.encode(ve);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		VisitorDecoder ve{ ctx };
		ie.decode(IE::denormalize(0), ve);
	}
};

/**************************************************/

template <class IE, class Enable = void>
struct Choice;

//22.5 Extension present
template <class IE>
struct Choice<IE, std::enable_if_t<(IE::constraint_t::extended == true)> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		auto idx = IE::normalize(ie.get_index());
		if (idx <= IE::constraint_t::upper_bound)
		{
			Tools::bit_accessor::put(0, 1, ctx.refBuffer());
			ChoiceNoExt<IE>::run(ie, ctx);
		}
		else
		{
			Tools::bit_accessor::put(1, 1, ctx.refBuffer());
			NormallySmallNonnegativeBinaryInteger<IE>::run(ie, ctx, idx - IE::constraint_t::upper_bound - 1);
			OpenTypeVisitorEncoder ve{ ctx };
			ie.encode(ve);
		}
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		u8 ext = Tools::bit_accessor::get(1, ctx.refBuffer());
		if (ext)
		{
			typename IE::index_type idx = IE::constraint_t::upper_bound + 1 + NormallySmallNonnegativeBinaryInteger<IE, typename IE::index_type>::run(ctx);
			if (idx >= IE::constraint_t::total_num_entries)
			{
				ie.set_unknown();
				size_t size = LengthDeterminantDefault::run(ctx);
				DecoderCtx::buf_type& buffer = ctx.refBuffer();
				if (buffer.getBytesLeft() < size)
					ctx.refErrorCtx().lengthErrorBytes(buffer.getBytesLeft(), size);
				else
					buffer.advance(size);
			}
			else
			{
				OpenTypeVisitorDecoder ve{ ctx };
				ie.decode(IE::denormalize(idx), ve);
			}
		}
		else
			ChoiceNoExt<IE>::run(ie, ctx);
	}
};

//22.6 No extension
template <class IE>
struct Choice<IE, std::enable_if_t<(IE::constraint_t::extended == false)> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		ChoiceNoExt<IE>::run(ie, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		ChoiceNoExt<IE>::run(ie, ctx);
	}
};

} //namespace per
} //namespace asn
