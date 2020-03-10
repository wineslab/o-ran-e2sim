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

template <class IE>
struct Oid
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		size_t len = ie.get().size();
		
		if (len > 255)
		{
			ctx.refErrorCtx().valueError(len, 0, 0);
		}
		else
		{
			Tools::bit_accessor::padByte(ctx.refBuffer());
			ctx.refBuffer().putBytes(reinterpret_cast<uint8_t*>(&len), 1);
			ctx.refBuffer().putBytes(ie.get().data(), len);
		}
	}
	
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		Tools::bit_accessor::padByte(ctx.refBuffer());
		
		uint8_t const* data_in = ctx.refBuffer().getBytes(1); // length
		
		if(data_in)
		{
			size_t len = *data_in;
			data_in = ctx.refBuffer().getBytes(len);
			
			if (data_in)
			{
				ie.set(len, data_in);
			}
		}
	}
};

} //namespace per
} //namespace asn
