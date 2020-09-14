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

#define IE_CLASS_SHIFT				6
#define IE_PC_SHIFT					5
#define IE_BIG_TAG_FST_OCTET		0b011111

namespace asn {
namespace ber {

constexpr tag_value_t invalid_tag = std::numeric_limits<tag_value_t>::max();

/***************************************************************************************
* Tag
***************************************************************************************/
template <class IE, bool constructed, class Enable=void>
struct Tag;

template <class IE, bool constructed>
struct Tag<IE, constructed, std::enable_if_t< (IE::asn_identifier_t::tag_value < 31) > >
{
	static constexpr tag_value_t value()
	{
		tag_value_t v = static_cast<uint8_t>(IE::asn_identifier_t::class_type);
		v <<= IE_CLASS_SHIFT;
		v = constructed ? (v | (1u << IE_PC_SHIFT)) : v;
		v |= static_cast<uint8_t>(IE::asn_identifier_t::tag_value);
		return v;
	}
	
	static void inline encode(EncoderCtx& ctx)
	{
		ctx.refBuffer().putByte(static_cast<uint8_t>(value()));
	}
};


template <class IE, bool constructed>
struct Tag<IE, constructed, std::enable_if_t< (IE::asn_identifier_t::tag_value >= 31) > >
{
	static constexpr tag_value_t value()
	{
		static_assert(IE::asn_identifier_t::tag_value > 0, "null tag value");
		
		tag_value_t v = static_cast<uint8_t>(IE::asn_identifier_t::class_type);
		v <<= IE_CLASS_SHIFT;
		v = constructed ? (v | (1u << IE_PC_SHIFT)) : v;
		v |= IE_BIG_TAG_FST_OCTET;
		
		size_t leadbits = __builtin_clzll(IE::asn_identifier_t::tag_value);
		tag_value_t tv = IE::asn_identifier_t::tag_value << leadbits;
		size_t length = sizeof(tag_value_t)*CHAR_BIT - leadbits;
				
		size_t shift = sizeof(tag_value_t)*CHAR_BIT - 7;
			
		size_t lb = length % 7;
		if(lb)
		{
			v <<= 8;
			v |= 0x80;
			v |= static_cast<uint8_t>(tv >> (shift + 7 - lb));
			tv <<= lb;
			length -= lb;
		}
		
		while(length)
		{
			v <<= 8;
			v |= 0x80;
			v |= static_cast<uint8_t>(tv >> shift);
			tv <<= 7;
			length -= 7;
		}
		v &= ((tag_value_t)-1) & ~((tag_value_t) 0x80);
		
		return v;
	}
	
	static void inline encode(EncoderCtx& ctx)
	{
		size_t size = 0;
		tag_value_t tv = data(size);
		ctx.refBuffer().putBytes(reinterpret_cast<uint8_t*>(&tv), size);
	}
	
private:
	
	static constexpr tag_value_t data(size_t& size)
	{
		tag_value_t rv = 0;
		tag_value_t tv = value();
		size = sizeof(tag_value_t) - (__builtin_clzll(tv) >> 3);
		
		uint8_t* ptr = reinterpret_cast<uint8_t*>(&rv);
		
		size_t shift = (size - 1) * 8;
		for(size_t i = 0; i < size; ++i)
		{
			ptr[i] = static_cast<uint8_t>(tv >> shift);
			shift -= 8;
		}
		
		return rv;
	}
};

inline
tag_value_t get_tag(DecoderCtx& ctx)
{
	tag_value_t rv = 0;
	auto & buffer = ctx.refBuffer();
	uint8_t const* data = buffer.getBytes(1);
	
	if (data)
	{
		rv = data[0];
		if((data[0] & 0x1F) == IE_BIG_TAG_FST_OCTET)
		{
			size_t limit = sizeof(tag_value_t) - 1;
			while((data = buffer.getBytes(1)))
			{
				if(!limit)
				{
					ctx.refErrorCtx().sizeRangeError(0);
					break;
				}
				
				rv <<= 8;
				rv |= data[0];
				--limit;
				
				if(!(data[0] & 0x80))
					break;
			}
		}
	}
	return rv;
}

} //namespace ber
} //namespace asn

