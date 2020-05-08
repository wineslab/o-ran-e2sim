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

template < class IE, class Enable = void>
struct Octetstring;

//16.8 Default
template <class IE, class Enabler = void>
struct OctetstringNoExt
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		bound_t size = ie.get().size();
		LengthDeterminant<typename IE::constraint_t>::run(ctx, size);
		Tools::bit_accessor::padByte(ctx.refBuffer());
		ctx.refBuffer().putBytes(ie.get().data(), size);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		size_t len = LengthDeterminant<typename IE::constraint_t>::run(ctx, false);
		Tools::bit_accessor::padByte(ctx.refBuffer());
		u8 const* data_in = ctx.refBuffer().getBytes(len);
		
		if (data_in)
		{
			ie.set(len, data_in);
		}

	}
};

//16.5 Zero length
template <class IE>
struct OctetstringNoExt<IE, std::enable_if_t< (IE::constraint_t::upper_bound == 0)> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx) {/* do nothing */ }
	static void inline run(IE& ie, DecoderCtx& ctx) { ie.setpresent(true); }
};

//16.6 Up to two octets, fixed length
template <class IE>
struct OctetstringNoExt<IE, std::enable_if_t<
	((IE::constraint_t::upper_bound == IE::constraint_t::lower_bound) && (IE::constraint_t::upper_bound == 1))
>>
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		Tools::bit_accessor::put(static_cast<u8>(ie.get().data()[0]), 8, ctx.refBuffer());
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		u8 data_in = Tools::bit_accessor::get(8, ctx.refBuffer());
		u8* data_out = ctx.refAllocator().alloc_bytes(1);
		if (data_out) {
			data_out[0] = data_in;
			ie.set(1, data_out);
		}
		else
			ctx.refErrorCtx().allocatorNoMem(0, 1);
	}
};

template <class IE>
struct OctetstringNoExt<IE, std::enable_if_t<
	((IE::constraint_t::upper_bound == IE::constraint_t::lower_bound) && (IE::constraint_t::upper_bound == 2))
>>
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		Tools::bit_accessor::put(static_cast<u8>(ie.get().data()[0]), 8, ctx.refBuffer());
		Tools::bit_accessor::put(static_cast<u8>(ie.get().data()[1]), 8, ctx.refBuffer());
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		u8 data_in[2];
		data_in[0] = Tools::bit_accessor::get(8, ctx.refBuffer());
		data_in[1] = Tools::bit_accessor::get(8, ctx.refBuffer());
		u8* data_out = ctx.refAllocator().alloc_bytes(sizeof(data_in));
		if (data_out) {
			data_out[0] = data_in[0];
			data_out[1] = data_in[1];
			ie.set(sizeof(data_in), data_out);
		}
		else
			ctx.refErrorCtx().allocatorNoMem(0, sizeof(data_in));
	}
};

//16.7 More than 2 octets, up to 64K, fixed length
template <class IE>
struct OctetstringNoExt<IE, std::enable_if_t<
	((IE::constraint_t::upper_bound == IE::constraint_t::lower_bound) && (IE::constraint_t::upper_bound < 65536) && (IE::constraint_t::upper_bound > 2))
>>
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		Tools::bit_accessor::padByte(ctx.refBuffer());
		ctx.refBuffer().putBytes(ie.get().data(), ie.get().size());
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		Tools::bit_accessor::padByte(ctx.refBuffer());
		const size_t len = (size_t)IE::constraint_t::upper_bound;
		u8 const* data_in = ctx.refBuffer().getBytes(len);
		if (data_in)
		{
			ie.set(len, data_in);
		}
	}
};

/**************************************************/

//16.3 : Extension present
template <class IE>
struct Octetstring<IE, std::enable_if_t<(IE::constraint_t::extended == true)> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		bound_t size = ie.get().size();
		if (size <= IE::constraint_t::upper_bound && size >= IE::constraint_t::lower_bound)
		{
			Tools::bit_accessor::put(0, 1, ctx.refBuffer());
			OctetstringNoExt<IE>::run(ie, ctx);
		}
		else
		{
			Tools::bit_accessor::put(1, 1, ctx.refBuffer());
			Tools::bit_accessor::padByte(ctx.refBuffer());
			LengthDeterminant<typename IE::constraint_t>::run(ctx, size);
			Tools::bit_accessor::padByte(ctx.refBuffer());
			ctx.refBuffer().putBytes(ie.get().data(), size);
		}
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		u8 ext = Tools::bit_accessor::get(1, ctx.refBuffer());
		if (ext)
		{
			Tools::bit_accessor::padByte(ctx.refBuffer());
			size_t len = LengthDeterminant<typename IE::constraint_t>::run(ctx, true);
			Tools::bit_accessor::padByte(ctx.refBuffer());
			u8 const* data_in = ctx.refBuffer().getBytes(len);
			if (data_in)
			{
				ie.set(len, data_in);
			}
		}
		else
			OctetstringNoExt<IE>::run(ie, ctx);
	}
};

//16.4 : No extension
template <class IE>
struct Octetstring<IE, std::enable_if_t<(IE::constraint_t::extended == false)> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		if ( ie.get().size() > size_t(IE::constraint_t::upper_bound) ||
			 (IE::constraint_t::lower_bound >= 0 && ie.get().size() < size_t(IE::constraint_t::lower_bound)))
		{
			ctx.refErrorCtx().sizeRangeError(ie.get().size(), size_t(IE::constraint_t::lower_bound),
											 size_t(IE::constraint_t::upper_bound));
		}
		else
		{
			OctetstringNoExt<IE>::run(ie, ctx);
		}
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		OctetstringNoExt<IE>::run(ie, ctx);
		if ( ie.get().size() > size_t(IE::constraint_t::upper_bound) ||
			 (IE::constraint_t::lower_bound >= 0 && ie.get().size() < size_t(IE::constraint_t::lower_bound)))
		{
			ctx.refErrorCtx().sizeRangeError(ie.get().size(), size_t(IE::constraint_t::lower_bound),
											 size_t(IE::constraint_t::upper_bound));
		}
	}
};

} //namespace per
} //namespace asn
