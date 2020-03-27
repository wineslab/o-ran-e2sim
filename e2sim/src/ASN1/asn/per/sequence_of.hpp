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

template <class IE, class Enable = void>
struct SequenceOf;

//19.6 Default
template <class IE, class Enabler = void>
struct SequenceOfNoExt
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		LengthDeterminant<typename IE::constraint_t>::run(ctx, ie.size());
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		size_t len = LengthDeterminant<typename IE::constraint_t>::run(ctx, false);
		for (size_t i = 0; i < len; ++i)
		{
			u8* data = ctx.refAllocator().alloc_bytes(sizeof(typename IE::value_type));
			if (data)
			{
				typename IE::value_type * v = new (data) typename IE::value_type;
				v->clear();
				ie.push_back(*v);
			}
			else
			{
				ctx.refErrorCtx().allocatorNoMem(0, sizeof(typename IE::value_type));
				break;
			}
		}
	}
};

//16.6 
template <class IE>
struct SequenceOfNoExt<IE, std::enable_if_t<
	((IE::constraint_t::upper_bound == IE::constraint_t::lower_bound) && (IE::constraint_t::upper_bound < 65536))
>>
{
	static void inline run(IE const& ie, EncoderCtx& ctx) {/*do nothing*/ }
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		for (size_t i = 0; i < IE::constraint_t::upper_bound; ++i)
		{
			u8* data = ctx.refAllocator().alloc_bytes(sizeof(typename IE::value_type));
			if (data)
			{
				typename IE::value_type * v = new (data) typename IE::value_type;
				v->clear();
				ie.push_back(*v);
			}
			else
			{
				ctx.refErrorCtx().allocatorNoMem(0, sizeof(typename IE::value_type));
				break;
			}
		}
	}
};

/**************************************************/

//19.4 Extension present
template <class IE>
struct SequenceOf<IE, std::enable_if_t<	(IE::constraint_t::extended == true)> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		if (ie.size() <= IE::constraint_t::upper_bound && ie.size() >= IE::constraint_t::lower_bound)
		{
			Tools::bit_accessor::put(0, 1, ctx.refBuffer());
			SequenceOfNoExt<IE>::run(ie, ctx);
		}
		else
		{
			Tools::bit_accessor::put(1, 1, ctx.refBuffer());
			LengthDeterminant<typename IE::constraint_t>::run(ctx, ie.size());
		}
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		u8 ext = Tools::bit_accessor::get(1, ctx.refBuffer());
		if (ext)
		{
			size_t len = LengthDeterminant<typename IE::constraint_t>::run(ctx, true);
			for (size_t i = 0; i < len; ++i)
			{
				u8* data = ctx.refAllocator().alloc_bytes(sizeof(typename IE::value_type));
				if (data)
				{
					typename IE::value_type * v = new (data) typename IE::value_type;
					//v->clear();
					ie.push_back(*v);
				}
				else
				{
					ctx.refErrorCtx().allocatorNoMem(0, sizeof(typename IE::value_type));
					break;
				}
			}
		}
		else
			SequenceOfNoExt<IE>::run(ie, ctx);
	}
};

//19.5-6 No extension
template <class IE>
struct SequenceOf<IE, std::enable_if_t<	(IE::constraint_t::extended == false)> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		if (IE::constraint_t::lower_bound >= 0 && ie.size() < size_t(IE::constraint_t::lower_bound))
		{
			ctx.refErrorCtx().sizeRangeError(ie.size(), size_t(IE::constraint_t::lower_bound));
		}
		else
		{
			SequenceOfNoExt<IE>::run(ie, ctx);
		}
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		SequenceOfNoExt<IE>::run(ie, ctx);
	}
};

} //namespace per
} //namespace asn
