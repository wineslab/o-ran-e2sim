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

//15.11 Default
template <class IE, class Enabler = void>
struct BitstringNoExt
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		LengthDeterminant<typename IE::constraint_t>::run(ctx, ie.get_bitqty());
		Tools::bit_accessor::padByte(ctx.refBuffer());

		const u8 tail = ie.get_bitqty() % 8;
		if (tail)
		{
			ctx.refBuffer().putBytes(ie.get_buffer().data(), ie.get_buffer().size() - 1);
			u8 last_byte = *(ie.get_buffer().data() + ie.get_buffer().size() - 1);

			last_byte <<= 8 - tail;
			ctx.refBuffer().putBytes(&last_byte, 1);
			ctx.refBuffer().set_begin(ctx.refBuffer().begin() - 1, tail);
		}
		else
		{
			ctx.refBuffer().putBytes(ie.get_buffer().data(), ie.get_buffer().size());
		}
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		size_t len = LengthDeterminant<typename IE::constraint_t>::run(ctx, false);
		size_t len_bytes = (len + 7) >> 3;
		Tools::bit_accessor::padByte(ctx.refBuffer());
		u8 const* data_in = ctx.refBuffer().getBytes(len_bytes);
		if (data_in)
		{
			u8* data_out = ctx.refAllocator().alloc_bytes(len_bytes);
			if (data_out)
			{
				memcpy(data_out, data_in, len_bytes);
				const u8 shift = len % 8;
				if (shift)
				{
					ctx.refBuffer().set_begin(ctx.refBuffer().begin() - 1, shift);
					data_out[len_bytes - 1] >>= 8 - shift;
				}
				ie.set_buffer(len, data_out);
			}
			else
				ctx.refErrorCtx().allocatorNoMem(0, len_bytes);
		}
	}
};

//15.8 Zero length
template <class IE>
struct BitstringNoExt<IE, std::enable_if_t<	(IE::constraint_t::upper_bound == 0)> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx) {/* do nothing */ }
	static void inline run(IE& ie, DecoderCtx& ctx) { ie.setpresent(true); }
};

//15.9 Up to 6 bits, fixed length
template <class IE>
struct BitstringNoExt<IE, std::enable_if_t<
	((IE::constraint_t::upper_bound == IE::constraint_t::lower_bound) && (IE::constraint_t::upper_bound <= 8) && (IE::constraint_t::upper_bound > 0))
>>
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		Tools::bit_accessor::put((static_cast<u8>(ie.get_buffer().data()[0])) & (0xFF >> (8 - IE::constraint_t::upper_bound)),
			IE::constraint_t::upper_bound, ctx.refBuffer());
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		u8 * data = ctx.refAllocator().alloc_bytes(1);
		if (data)
		{
			data[0] = Tools::bit_accessor::get(IE::constraint_t::upper_bound, ctx.refBuffer());
			ie.set_buffer(IE::constraint_t::upper_bound, data);
		}
		else
			ctx.refErrorCtx().allocatorNoMem(0, 1);
	}
};
template <class IE>
struct BitstringNoExt<IE, std::enable_if_t<
	((IE::constraint_t::upper_bound == IE::constraint_t::lower_bound) && (IE::constraint_t::upper_bound <= 16) && (IE::constraint_t::upper_bound > 8))
>>
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		Tools::bit_accessor::put(ie.get_buffer().data()[0], 8, ctx.refBuffer());
		Tools::bit_accessor::put((static_cast<u8>(ie.get_buffer().data()[1])) & (0xFF >> (16 - IE::constraint_t::upper_bound)),
			IE::constraint_t::upper_bound - 8, ctx.refBuffer());
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		u8 * data = ctx.refAllocator().alloc_bytes(2);
		if (data)
		{
			data[0] = Tools::bit_accessor::get(8, ctx.refBuffer());
			data[1] = Tools::bit_accessor::get(IE::constraint_t::upper_bound - 8, ctx.refBuffer());
			ie.set_buffer(IE::constraint_t::upper_bound, data);
		}
		else
			ctx.refErrorCtx().allocatorNoMem(0, 2);
	}
};

//15.10 More than 6 bits, up to 64K bits, fixed length
template <class IE>
struct BitstringNoExt<IE, std::enable_if_t<
	((IE::constraint_t::upper_bound == IE::constraint_t::lower_bound) && (IE::constraint_t::upper_bound < 65536) && (IE::constraint_t::upper_bound > 16))
>>
{
	constexpr static size_t len_bytes = (IE::constraint_t::upper_bound + 7) >> 3;

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		Tools::bit_accessor::padByte(ctx.refBuffer());
		if (ie.get_buffer().size() != len_bytes)
		{
			ctx.refErrorCtx().sizeRangeError(ie.get_buffer().size(), len_bytes, len_bytes);
		}
		else
		{
			const u8 tail = ie.get_bitqty() % 8;
			if (tail)
			{
				ctx.refBuffer().putBytes(ie.get_buffer().data(), ie.get_buffer().size() - 1);
				u8 last_byte = *(ie.get_buffer().data() + ie.get_buffer().size() - 1);
				last_byte <<= 8 - tail;
				ctx.refBuffer().putBytes(&last_byte, 1);
				ctx.refBuffer().set_begin(ctx.refBuffer().begin() - 1, tail);
			}
			else
			{
				ctx.refBuffer().putBytes(ie.get_buffer().data(), ie.get_buffer().size());
			}
		}
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		Tools::bit_accessor::padByte(ctx.refBuffer());
		u8 const* data_in = ctx.refBuffer().getBytes(len_bytes);
		if (data_in)
		{
			u8* data_out = ctx.refAllocator().alloc_bytes(len_bytes);
			if (data_out)
			{
				memcpy(data_out, data_in, len_bytes);
				const u8 shift = IE::constraint_t::upper_bound % 8;
				if (shift)
				{
					ctx.refBuffer().set_begin(ctx.refBuffer().begin() - 1, shift);
					data_out[len_bytes - 1] >>= 8 - shift;
				}
				ie.set_buffer(IE::constraint_t::upper_bound, data_out);
			}
			else
				ctx.refErrorCtx().allocatorNoMem(0, len_bytes);
		}
	}
};

/**************************************************/

template <class IE, class Enabler = void>
struct Bitstring;

//15.6 : Extension present
template <class IE>
struct Bitstring<IE, std::enable_if_t< (IE::constraint_t::extended == true)> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{

		if (ie.get_bitqty() <= IE::constraint_t::upper_bound && ie.get_bitqty() >= IE::constraint_t::lower_bound)
		{
			Tools::bit_accessor::put(0, 1, ctx.refBuffer());
			BitstringNoExt<IE>::run(ie, ctx);
		}
		else
		{
			Tools::bit_accessor::put(1, 1, ctx.refBuffer());
			Tools::bit_accessor::padByte(ctx.refBuffer());
			LengthDeterminant<typename IE::constraint_t>::run(ctx, ie.get_bitqty());
			Tools::bit_accessor::padByte(ctx.refBuffer());
			const u8 tail = ie.get_bitqty() % 8;
			if (tail)
			{
				ctx.refBuffer().putBytes(ie.get_buffer().data(), ie.get_buffer().size() - 1);
				u8 last_byte = *(ie.get_buffer().data() + ie.get_buffer().size() - 1);

				last_byte <<= 8 - tail;

				ctx.refBuffer().putBytes(&last_byte, 1);
				ctx.refBuffer().set_begin(ctx.refBuffer().begin() - 1, tail);
			}
			else
			{
				ctx.refBuffer().putBytes(ie.get_buffer().data(), ie.get_buffer().size());
			}
		}
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		u8 ext = Tools::bit_accessor::get(1, ctx.refBuffer());
		if (ext)
		{
			Tools::bit_accessor::padByte(ctx.refBuffer());
			const size_t len = LengthDeterminant<typename IE::constraint_t>::run(ctx, true);
			const size_t len_bytes = (len + 7) >> 3;
			Tools::bit_accessor::padByte(ctx.refBuffer());
			u8 const* data_in = ctx.refBuffer().getBytes(len_bytes);
			if (data_in)
			{
				u8* data_out = ctx.refAllocator().alloc_bytes(len_bytes);
				if (data_out)
				{
					memcpy(data_out, data_in, len_bytes);
					const u8 shift = len % 8;
					if (shift)
					{
						ctx.refBuffer().set_begin(ctx.refBuffer().begin() - 1, shift);
						data_out[len_bytes - 1] >>= 8 - shift;
					}
					ie.set_buffer(len, data_out);
				}
				else
					ctx.refErrorCtx().allocatorNoMem(0, len_bytes);
			}
		}
		else
			BitstringNoExt<IE>::run(ie, ctx);
	}
};

//15.7 : No extension
template <class IE>
struct Bitstring<IE, std::enable_if_t< (IE::constraint_t::extended == false)> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		BitstringNoExt<IE>::run(ie, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		BitstringNoExt<IE>::run(ie, ctx);
	}
};

} //namespace per
} //namespace asn
