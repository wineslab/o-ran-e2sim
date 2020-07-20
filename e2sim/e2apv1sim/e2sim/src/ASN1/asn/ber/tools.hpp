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

struct Tools
{
	typedef bit_accessor_cross_byte<false> bit_accessor;


	template<typename T>
	static void put_bytes(T value, size_t length, EncoderCtx& ctx)
	{
		auto & buffer = ctx.refBuffer();
		
		size_t shift = (length - 1) << 3;
		for(size_t i = 0; i < length; ++i)
		{
			buffer.putByte(static_cast<uint8_t>(value >> shift));
			shift -= 8;
		}
	}
	
	template<typename T>
	static void get_bytes(T& value, size_t length, DecoderCtx& ctx)
	{
		auto & buffer = ctx.refBuffer();
		
		value = 0;
		uint8_t const* data = buffer.getBytes(length);
		
		if(data)
		{
			value = data[0];
			for(size_t i = 1; i < length; ++i)
			{
				value <<= 8;
				value |= data[i];
			}
		}
	}

};

} //namespace ber
} //namespace asn
