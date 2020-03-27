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

/***************************************************************************************
* OpenType
***************************************************************************************/
struct OpenType
{
	static tag_value_t decode(DecoderCtx& ctx, size_t& length, tag_value_t const* tag_ptr = nullptr)
	{
		auto & buffer = ctx.refBuffer();
		tag_value_t tag = tag_ptr ? *tag_ptr : get_tag(ctx);
		length = Length::decode(ctx);
		
		if(!length)
		{
			//just return
		}
		else if(length == indefinite_length)
		{
			tag_value_t _tag;
			size_t _length;
			do
			{
				_tag = OpenType::decode(ctx, _length);

			} while(ctx && !(_tag == 0 && _length == 0));
		}
		else
		{
			if (buffer.getBytesLeft() < length)
			{
				ctx.refErrorCtx().lengthErrorBytes(buffer.getBytesLeft(), length);
			}
			else
			{
				size_t _length;
				DecoderCtx::buf_type::pointer end = buffer.end();
				buffer.set_end(buffer.begin() + length);
				decode(ctx, _length);
				buffer.set_end(end);
			}
		}
		return tag;
	}
};

} //namespace ber
} //namespace asn