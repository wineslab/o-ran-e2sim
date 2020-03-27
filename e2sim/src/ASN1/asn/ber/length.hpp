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

namespace asn {
namespace ber {

constexpr size_t indefinite_length = std::numeric_limits<size_t>::max();

/***************************************************************************************
* Length
***************************************************************************************/
struct Length
{
	static size_t inline get(int64_t value)
	{
		size_t length = 1;
		
		if(value != 0)
		{
			size_t extra_sign_bits = __builtin_clrsbll(value);
			length  = sizeof(value) - (extra_sign_bits >> 3) ;
		}
		
		return length;
	}
	
	static void inline encode(size_t length, EncoderCtx& ctx)
	{
		auto & buffer = ctx.refBuffer();
		
		if(length <= 0x7F)
		{
			buffer.putByte(static_cast<uint8_t>(length));
		}
		else
		{
			size_t lenlen = get(length);
			if(lenlen > 0x7F)
			{
				ctx.refErrorCtx().sizeRangeError(length, 0, 0x7F);
			}
			else
			{
				uint8_t bt = static_cast<uint8_t>(lenlen);
				bt |= 0x80;
				buffer.putByte(bt);
				Tools::put_bytes(length, lenlen, ctx);
			}
		}

	}
	
	static size_t inline decode(DecoderCtx& ctx)
	{
		auto & buffer = ctx.refBuffer();
		size_t length = 0;
		
		uint8_t const* data = buffer.getBytes(1);
		
		if(data)
		{
			if(!(data[0] & 0x80))
			{
				length = data[0];
			}
			else
			{
				size_t lenlen = data[0] & 0x7F;
				
				if(lenlen)
					Tools::get_bytes(length, lenlen, ctx);
				else
					length = indefinite_length;
			}
		}
		
		return length;
	}
};

} //namespace ber
} //namespace asn
