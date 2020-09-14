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
#include "asn/elements.hpp"
#include "asn/ber/common.hpp"
#include "asn/ber/context.hpp"
#include "asn/ber/tag.hpp"
#include "asn/ber/length.hpp"
#include "asn/ber/visitor.hpp"
#include "asn/ber/opentype.hpp"

namespace asn {
namespace ber {

/********************************************************************************
pack (X.690)
*********************************************************************************/
template <class IE>
bool pack(IE const& ie, EncoderCtx& ctx)
{
	ctx.refErrorCtx().reset();
	Element<IE>::run(ie, ctx);

	if (ctx)
		Tools::bit_accessor::padByte(ctx.refBuffer());

	return static_cast<bool>(ctx);
}
/********************************************************************************
unpack (X.690)
*********************************************************************************/
template <class IE>
bool unpack(IE& ie, DecoderCtx& ctx)
{
	Element<IE>::run(ie, ctx);

	if (ctx)
		Tools::bit_accessor::padByte(ctx.refBuffer());

	if(ctx && ctx.refBuffer().getBytesLeft())
	{
		ctx.ie_name(IE::name());
		ctx.refErrorCtx().lengthErrorBytes(ctx.refBuffer().getBytesLeft(), 0);
	}

	return static_cast<bool>(ctx);
}

/***************************************************************************************
* ElementType
***************************************************************************************/
template <class IE, class Enabler = void>
struct ElementType;

/***************************************************************************************
* ExplicitCodec: Codec for elements with EXPLICIT tag
***************************************************************************************/
template <class IE>
struct ExplicitCodec
{
	using tag_t = Tag<IE, true>;
	static bool inline is_matched(tag_value_t _tag) {return _tag == tag_t::value();}

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		auto & buffer = ctx.refBuffer();

		tag_t::encode(ctx);
    u8* len_ptr = buffer.advance(1); //reserve for the length

		Element<typename IE::parent_t>::run(static_cast<typename IE::parent_t const&>(ie), ctx);

    size_t len = buffer.begin() - len_ptr - 1;
    if(len > 127)
    {
      len_ptr[0] = 0x80; //undefinite length form per X.690 8.1.3.6
		  uint8_t buff[2] = {0}; // end-of-contents octets (X.690 8.1.5)
		  buffer.putBytes(buff, sizeof(buff));
    }
    else
    {
      len_ptr[0] = static_cast<u8>(len); //one byte form per X.690 8.1.3.4
    }
	}

	static void inline run(IE& ie, DecoderCtx& ctx, tag_value_t tag)
	{
		if(tag_t::value() != tag)
			ctx.refErrorCtx().tagError(static_cast<uint32_t>(tag));
		else
		{
			auto & buffer = ctx.refBuffer();
			size_t length = Length::decode(ctx);

      ASN_DECODER_TRACE("EX<tag=0x%x length=%zu> buffer: %s", static_cast<int>(tag), length, ctx.refBuffer().toString());

			if(length == indefinite_length)
			{
				Element<typename IE::parent_t>::run(static_cast<typename IE::parent_t&>(ie), ctx);

				if(ctx)
				{
					uint8_t const* data_in = ctx.refBuffer().getBytes(2);
					if(data_in && (data_in[0] || data_in[1]))
					{
						ctx.refErrorCtx().errorWrongEndOfContent();
					}
				}
			}
			else
			{
				if (buffer.getBytesLeft() < length)
				{
					ctx.refErrorCtx().lengthErrorBytes(buffer.getBytesLeft(), length);
				}
				else
				{
					DecoderCtx::buf_type::pointer end = buffer.end();
					buffer.set_end(buffer.begin() + length);

					Element<typename IE::parent_t>::run(static_cast<typename IE::parent_t&>(ie), ctx);

					buffer.set_end(end);
				}
			}

		}
	}
};

/***************************************************************************************
* BOOLEAN: Encoding the boolean type  (X.690 8.2)
***************************************************************************************/
template <class IE>
struct ElementType<IE, std::enable_if_t<IE::ie_type == element_type::T_BOOLEAN> >
{
	using tag_t = Tag<IE, false>;

	static bool inline is_matched(tag_value_t tag) {return tag == tag_t::value();}

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		tag_t::encode(ctx);
		Length::encode(1, ctx);
		if(ie.get())
			Tools::put_bytes(0xFF, 1, ctx);
		else
			Tools::put_bytes(0, 1, ctx);
	}

	static void inline run(IE& ie, DecoderCtx& ctx, tag_value_t tag)
	{
		if(tag_t::value() != tag)
			ctx.refErrorCtx().tagError(static_cast<uint32_t>(tag));
		else
		{
			size_t length = Length::decode(ctx);
			if(length != 1)
			{
				ctx.refErrorCtx().sizeRangeError(length, 1, 1);
			}
			else
			{
        ASN_DECODER_TRACE("IE<type=%d name=%s tag=0x%x length=%zu> buffer: %s", static_cast<int>(IE::ie_type), IE::name(), static_cast<int>(tag), length, ctx.refBuffer().toString());
				uint8_t value;
				Tools::get_bytes(value, 1, ctx);
				ie.set(value > 0);
			}
		}
	}
};
/***************************************************************************************
* INTEGER: Encoding the integer type  (X.690 8.3)
***************************************************************************************/
template <class IE>
struct ElementType<IE, std::enable_if_t<IE::ie_type == element_type::T_INTEGER> >
{
	using tag_t = Tag<IE, false>;

	static bool inline is_matched(tag_value_t tag) {return tag == tag_t::value();}

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		tag_t::encode(ctx);
		size_t length = Length::get(ie.get());
		Length::encode(length, ctx);
		Tools::put_bytes(ie.get(), length, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx, tag_value_t tag)
	{
		if(tag_t::value() != tag)
    {
			ctx.refErrorCtx().tagError(static_cast<uint32_t>(tag));
    }
		else
		{
			size_t length = Length::decode(ctx);
			if(!length || length == indefinite_length)
				ctx.refErrorCtx().sizeRangeError(length);
			else
			{
        ASN_DECODER_TRACE("IE<type=%d name=%s tag=0x%x length=%zu> buffer: %s", static_cast<int>(IE::ie_type), IE::name(), static_cast<int>(tag), length, ctx.refBuffer().toString());
				typename IE::value_type value;
				Tools::get_bytes(value, length, ctx);
				ie.set(value);
			}
		}
	}
};
/***************************************************************************************
* ENUMERATED: Encoding the enumerated type  (X.690 8.4)
***************************************************************************************/
template <class IE>
struct ElementType<IE, std::enable_if_t<IE::ie_type == element_type::T_ENUMERATED> >
{
	using tag_t = Tag<IE, false>;

	static bool inline is_matched(tag_value_t tag) {return tag == tag_t::value();}

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		tag_t::encode(ctx);
		size_t length = Length::get(ie.get());
		Length::encode(length, ctx);
		Tools::put_bytes(ie.get(), length, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx, tag_value_t tag)
	{
		if(tag_t::value() != tag)
			ctx.refErrorCtx().tagError(static_cast<uint32_t>(tag));
		else
		{
			size_t length = Length::decode(ctx);
			if(!length || length == indefinite_length)
				ctx.refErrorCtx().sizeRangeError(length);
			else
			{
        ASN_DECODER_TRACE("IE<type=%d name=%s tag=0x%x length=%zu> buffer: %s", static_cast<int>(IE::ie_type), IE::name(), static_cast<int>(tag), length, ctx.refBuffer().toString());
				typename IE::value_type value;
				Tools::get_bytes(value, length, ctx);
				ie.set(value);
			}
		}
	}
};
/***************************************************************************************
* REAL: Encoding the real type  (X.690 8.5)
***************************************************************************************/
//missing...
/***************************************************************************************
* BIT STRING: Encoding the bitstring type (X.690 8.6)
***************************************************************************************/
template <class IE>
struct ElementType<IE, std::enable_if_t<(IE::ie_type == element_type::T_BITSTRING)> >
{
	using tag_t = Tag<IE, false>;
	using ctag_t = Tag<IE, true>;

	static bool inline is_matched(tag_value_t tag) {return tag == tag_t::value() || tag == ctag_t::value();}

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		tag_t::encode(ctx);

		uint8_t tail = ie.get_bitqty() % 8;

		size_t length = ie.get_buffer().size();
		Length::encode(length + 1, ctx);

		auto & buffer = ctx.refBuffer();
		buffer.putByte((8 - tail) & 0x7F);

		if (tail)
		{
			buffer.putBytes(ie.get_buffer().data(), length - 1);
			u8 last_byte = *(ie.get_buffer().data() + length - 1);

			last_byte <<= 8 - tail;
			buffer.putBytes(&last_byte, 1);
		}
		else
		{
			buffer.putBytes(ie.get_buffer().data(), length);
		}
	}
	static void inline run(IE& ie, DecoderCtx& ctx, tag_value_t tag)
	{
		ie.clear();
		if(tag_t::value() == tag)
		{
			size_t length = Length::decode(ctx);
			if(!length || length == indefinite_length)
			{
				ctx.refErrorCtx().sizeRangeError(length);
			}
			else
			{
				ASN_DECODER_TRACE("IE<type=%d name=%s tag=0x%x length=%zu> buffer: %s", static_cast<int>(IE::ie_type), IE::name(), static_cast<int>(tag), length, ctx.refBuffer().toString());
				uint8_t const* data_in = ctx.refBuffer().getBytes(length);
				if(data_in)
				{
					size_t len_bytes = length - 1;
					size_t bitqty    = len_bytes << 3;

					if((data_in[0] & 0x80) || (bitqty < data_in[0]))
					{
						ctx.refErrorCtx().valueRangeError(data_in[0]);
					}
					else
					{
						bitqty = bitqty - data_in[0];
						uint8_t* data_out = ctx.refAllocator().alloc_bytes(len_bytes);
						if (data_out)
						{
							memcpy(data_out, &data_in[1], len_bytes);
							const u8 shift = bitqty % 8;
							if (shift)
							{
								data_out[len_bytes - 1] >>= 8 - shift;
							}
							ie.set_buffer(bitqty, data_out);
						}
						else
						{
							ctx.refErrorCtx().allocatorNoMem(0, len_bytes);
						}
					}
				}
			}
		}
		else if(ctag_t::value() == tag)
		{
			//todo: implement the segmented data
			ctx.refErrorCtx().errorUnsupported();
		}
		else
		{
			ctx.refErrorCtx().tagError(static_cast<uint32_t>(tag));
		}
	}
};
/***************************************************************************************
* OCTET STRING: Encoding the octetstring type (X.690 8.7)
* Restricted Character string types (X.690 8.23)
***************************************************************************************/
template <class IE>
struct ElementType<IE, std::enable_if_t<IE::ie_type == element_type::T_OCTETSTRING> >
{
	using tag_t = Tag<IE, false>;
	using ctag_t = Tag<IE, true>;

	static bool inline is_matched(tag_value_t tag) {return tag == tag_t::value() || tag == ctag_t::value();}

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		tag_t::encode(ctx);
		size_t length = ie.get().size();
		Length::encode(length, ctx);
		ctx.refBuffer().putBytes(ie.get().data(), length);
	}
	static void inline run(IE& ie, DecoderCtx& ctx, tag_value_t tag)
	{
		ie.clear();
		if(tag_t::value() == tag)
		{
			size_t length = Length::decode(ctx);
			if(length == indefinite_length)
			{
				ctx.refErrorCtx().sizeRangeError(length);
			}
			else
			{
        ASN_DECODER_TRACE("IE<type=%d name=%s tag=0x%x length=%zu> buffer: %s", static_cast<int>(IE::ie_type), IE::name(), static_cast<int>(tag), length, ctx.refBuffer().toString());
				uint8_t const* data_in = ctx.refBuffer().getBytes(length);
				if(data_in)
				{
					ie.set(length, data_in);
				}
			}
		}
		else if(ctag_t::value() == tag)
		{
			//todo: implement the segmented data
			ctx.refErrorCtx().errorUnsupported();
		}
		else
		{
			ctx.refErrorCtx().tagError(static_cast<uint32_t>(tag));
		}
	}
};
/***************************************************************************************
* NULL: Encoding the null type (X.690 8.8)
***************************************************************************************/
template <class IE>
struct ElementType<IE, std::enable_if_t<IE::ie_type == element_type::T_NULL> >
{
	using tag_t = Tag<IE, false>;

	static bool inline is_matched(tag_value_t tag) {return tag == tag_t::value();}

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		tag_t::encode(ctx);
		Length::encode(0, ctx);
	}

	static void inline run(IE& ie, DecoderCtx& ctx, tag_value_t tag)
	{
		if(tag_t::value() != tag)
			ctx.refErrorCtx().tagError(static_cast<uint32_t>(tag));
		else
		{
			size_t length = Length::decode(ctx);
			if(length)
				ctx.refErrorCtx().sizeRangeError(length);
      ASN_DECODER_TRACE("IE<type=%d name=%s tag=0x%x length=%zu> buffer: %s", static_cast<int>(IE::ie_type), IE::name(), static_cast<int>(tag), length, ctx.refBuffer().toString());
		}
	}
};
/***************************************************************************************
* SEQUENCE: Encoding the sequence type (X.690 8.9)
* SET: 		Encoding the set type (X.690 8.11)
***************************************************************************************/
template <class IE>
struct ElementType<IE, std::enable_if_t<(IE::ie_type == element_type::T_SEQUENCE) || (IE::ie_type == element_type::T_SET)> >
{
	using tag_t = Tag<IE, true>;

	static bool inline is_matched(tag_value_t tag) {return tag == tag_t::value();}

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
    auto & buffer = ctx.refBuffer();

		tag_t::encode(ctx);
    u8* len_ptr = buffer.advance(1); //reserve for the length

		VisitorEncoderSeq<IE> ve(ctx, ie);
		ie.encode(ve);

    size_t len = buffer.begin() - len_ptr - 1;
    if(len > 127)
    {
      len_ptr[0] = 0x80; //undefinite length form per X.690 8.1.3.6
		  uint8_t buff[2] = {0}; // end-of-contents octets (X.690 8.1.5)
		  buffer.putBytes(buff, sizeof(buff));
    }
    else
      len_ptr[0] = static_cast<u8>(len); //one byte form per X.690 8.1.3.4
	}

	static void inline run(IE& ie, DecoderCtx& ctx, tag_value_t tag) //todo: support arbitrary order of IEs in SET
	{
		if(tag_t::value() != tag)
			ctx.refErrorCtx().tagError(static_cast<uint32_t>(tag));
		else
		{
			VisitorDecoderSeq<IE> vd(ctx, ie);
			auto & buffer = ctx.refBuffer();

			size_t length = Length::decode(ctx);

      ASN_DECODER_TRACE("IE<type=%d name=%s tag=0x%x length=%zu> buffer: %s", static_cast<int>(IE::ie_type), IE::name(), static_cast<int>(tag), length, ctx.refBuffer().toString());

			if(length == indefinite_length)
			{
				ie.decode(vd);
				if(ctx)
				{
					if(invalid_tag != vd.get_unhandled_tag())
					{
						tag_value_t _tag = vd.get_unhandled_tag();
						if(IE::constraint_t::extended) //skip the unknown extension now
						{
							tag_value_t const* tag_ptr = &_tag;
							size_t _length;
							do
							{
								_tag = OpenType::decode(ctx, _length, tag_ptr);
								tag_ptr = nullptr;

							} while(ctx && !(_tag == 0 && _length == 0));
						}
						else // it should be the end-of-contents octets (8.1.5)
						{
							uint8_t const* data_in = ctx.refBuffer().getBytes(1);
							if(data_in && (_tag || data_in[0]))
							{
								ctx.refErrorCtx().errorWrongEndOfContent();
							}
						}
					}
					else
					{
						uint8_t const* data_in = ctx.refBuffer().getBytes(2);
						if(data_in && (data_in[0] || data_in[1]))
						{
							ctx.refErrorCtx().errorWrongEndOfContent();
						}
					}
				}
			}
			else
			{
				if (buffer.getBytesLeft() < length)
				{
					ctx.refErrorCtx().lengthErrorBytes(buffer.getBytesLeft(), length);
				}
				else
				{
					DecoderCtx::buf_type::pointer end = buffer.end();
					buffer.set_end(buffer.begin() + length);
					ie.decode(vd);
					tag_value_t _tag = vd.get_unhandled_tag();
					if(invalid_tag != _tag)
					{
						if(IE::constraint_t::extended) //skip the unknown extension now
						{
							tag_value_t const* tag_ptr = &_tag;
							size_t _length;
							do
							{
								_tag = OpenType::decode(ctx, _length, tag_ptr);
								tag_ptr = nullptr;

							} while(ctx && buffer.getBytesLeft() > 0);
						}
						else
							ctx.refErrorCtx().tagError(static_cast<uint32_t>(tag)); // unexpected tag
					}
					buffer.set_end(end);
				}
			}

		}
	}
};
/***************************************************************************************
* SEQUENCE OF: 	Encoding the sequence-of type (X.690 8.10)
* SET OF: 		Encoding the set-of type (X.690 8.12)
***************************************************************************************/
template <class IE>
struct ElementType<IE, std::enable_if_t<(IE::ie_type == element_type::T_SEQUENCE_OF) || (IE::ie_type == element_type::T_SET_OF)> >
{
	using tag_t = Tag<IE, true>;

	static bool inline is_matched(tag_value_t tag) {return tag == tag_t::value();}

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
    auto & buffer = ctx.refBuffer();

		tag_t::encode(ctx);
    u8* len_ptr = buffer.advance(1); //reserve for the length

		for (auto& elem : ie)
		{
			Element<typename IE::element_t>::run(elem, ctx);
		}

    size_t len = buffer.begin() - len_ptr - 1;
    if(len > 127)
    {
      len_ptr[0] = 0x80; //undefinite length form per X.690 8.1.3.6
		  uint8_t buff[2] = {0}; // end-of-contents octets (X.690 8.1.5)
		  buffer.putBytes(buff, sizeof(buff));
    }
    else
      len_ptr[0] = static_cast<u8>(len); //one byte form per X.690 8.1.3.4
	}
	static void inline run(IE& ie, DecoderCtx& ctx, tag_value_t tag)
	{
		ie.clear();

		if(tag_t::value() != tag)
			ctx.refErrorCtx().tagError(static_cast<uint32_t>(tag));
		else
		{
			auto & buffer = ctx.refBuffer();

			size_t length = Length::decode(ctx);

      ASN_DECODER_TRACE("IE<type=%d name=%s tag=0x%x length=%zu> buffer: %s", static_cast<int>(IE::ie_type), IE::name(), static_cast<int>(tag), length, ctx.refBuffer().toString());

			if(length == indefinite_length)
			{
				tag_value_t elm_tag = get_tag(ctx);

				while(ctx && Element<typename IE::element_t>::is_matched(elm_tag))
				{
					add_element(ie, ctx, &elm_tag);
					elm_tag = get_tag(ctx);
				}

				if(ctx)
				{
					uint8_t const* data_in = ctx.refBuffer().getBytes(1);
					if(data_in && (elm_tag || data_in[0]))
					{
						ctx.refErrorCtx().errorWrongEndOfContent();
					}
				}
			}
			else
			{
				if (buffer.getBytesLeft() < length)
				{
					ctx.refErrorCtx().lengthErrorBytes(buffer.getBytesLeft(), length);
				}
				else
				{
					DecoderCtx::buf_type::pointer end = buffer.end();
					buffer.set_end(buffer.begin() + length);

					while(ctx && buffer.getBytesLeft() > 0)
						add_element(ie, ctx);

					buffer.set_end(end);
				}
			}
		}
	}

private:
	static void inline add_element(IE& ie, DecoderCtx& ctx, tag_value_t const* elm_tag = nullptr)
	{
		uint8_t* data = ctx.refAllocator().alloc_bytes(sizeof(typename IE::value_type));
		if (data)
		{
			typename IE::value_type * v = new (data) typename IE::value_type;
			v->clear();
			ie.push_back(*v);
			Element<typename IE::element_t>::run(*v, ctx, elm_tag);
		}
		else
		{
			ctx.refErrorCtx().allocatorNoMem(0, sizeof(typename IE::value_type));
		}
	}
};

/***************************************************************************************
* CHOICE: Encoding the choice type
***************************************************************************************/
struct ChoiceVisitorEncoder
{
	ChoiceVisitorEncoder(EncoderCtx& ctx) : m_ctx(ctx) {}

	template<typename IE>
	bool operator()(IE const& ie)
	{
		Element<IE>::run(ie, m_ctx);
		return static_cast<bool>(m_ctx);
	}

	EncoderCtx&		m_ctx;
};

struct ChoiceVisitorDecoder
{
	ChoiceVisitorDecoder(DecoderCtx& ctx, tag_value_t tag) : m_ctx(ctx), m_tag(tag) {}

	template<typename IE> bool operator()(IE& ie)
	{
		Element<IE>::run(ie, m_ctx, &m_tag);
		return static_cast<bool>(m_ctx);
	}

	DecoderCtx&		m_ctx;
	tag_value_t 	m_tag;
};

template <class IE>
struct ElementType<IE, std::enable_if_t<IE::ie_type == element_type::T_CHOICE && IE::asn_identifier_t::class_type == class_type_t::UNSPECIFIED> >
{
	struct Selector
	{
		Selector(tag_value_t tag) : m_tag(tag) {}

		template<typename ELM> void operator()(size_t idx)
		{
 			if(!m_valid && Element<ELM>::is_matched(m_tag))
			{
				m_index = idx;
				m_valid = true;
			}
		}

		size_t get_idx() const {return m_index;}
		bool is_valid() const {return m_valid;}

	private:
		tag_value_t m_tag;
		size_t		m_index {0};
		bool		m_valid {false};
	};

  static bool inline is_matched(tag_value_t tag)
	{
    Selector selector {tag};
  	IE::enumerate(selector);
  	return selector.is_valid();
	}

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		ChoiceVisitorEncoder ve(ctx);

		if(ctx && !ie.encode(ve))
			ctx.refErrorCtx().tagError(ie.get_index());
	}
	static void inline run(IE& ie, DecoderCtx& ctx, tag_value_t tag)
	{
		ie.clear();

		Selector selector {tag};
		IE::enumerate(selector);

		if(!selector.is_valid())
			ctx.refErrorCtx().tagError(static_cast<uint32_t>(tag));
		else
		{
			ChoiceVisitorDecoder vd {ctx, tag};
			if(ctx && !ie.decode(selector.get_idx(), vd))
				ctx.refErrorCtx().tagError(ie.get_index());
		}
	}
};

template <class IE>
struct ElementType<IE, std::enable_if_t<IE::ie_type == element_type::T_CHOICE && IE::asn_identifier_t::class_type != class_type_t::UNSPECIFIED> >
{
	static bool inline is_matched(tag_value_t _tag) {return ExplicitCodec<IE>::is_matched(_tag);}

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
    ExplicitCodec<IE>::run(ie, ctx);
	}

	static void inline run(IE& ie, DecoderCtx& ctx, tag_value_t tag)
	{
    ExplicitCodec<IE>::run(ie, ctx, tag);
	}
};

/***************************************************************************************
* IE_OBJECT_IDENTIFIER: Encoding the object identifier type
***************************************************************************************/
template <class IE>
struct ElementType<IE, std::enable_if_t<IE::ie_type == element_type::T_OBJECTIDENTIFIER> >
{
	using tag_t = Tag<IE, false>;

	static bool inline is_matched(tag_value_t _tag) {return _tag == tag_t::value();}

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		tag_t::encode(ctx);
		size_t length = ie.get().size();
		Length::encode(length, ctx);
		ctx.refBuffer().putBytes(ie.get().data(), length);
	}
	static void inline run(IE& ie, DecoderCtx& ctx, tag_value_t tag)
	{
		ie.clear();
		if(tag_t::value() == tag)
		{
			size_t length = Length::decode(ctx);
			if(!length || length == indefinite_length)
			{
				ctx.refErrorCtx().sizeRangeError(length);
			}
			else
			{
        ASN_DECODER_TRACE("IE<type=%d name=%s tag=0x%x length=%zu> buffer: %s", static_cast<int>(IE::ie_type), IE::name(), static_cast<int>(tag), length, ctx.refBuffer().toString());
				uint8_t const* data_in = ctx.refBuffer().getBytes(length);
				if(data_in)
				{
					ie.set(length, data_in);
				}
			}
		}
		else
		{
			ctx.refErrorCtx().tagError(static_cast<uint32_t>(tag));
		}
	}
};

/***************************************************************************************
* T_OBJFIELD_FTV
***************************************************************************************/
template <class IE>
struct ElementType<IE, std::enable_if_t<IE::ie_type == element_type::T_OBJFIELD_FTV> >
{
	using tag_t = Tag<IE, false>;

	static bool inline is_matched(tag_value_t _tag) {return _tag == tag_t::value();}
};

/***************************************************************************************
* T_OBJFIELD_TF
***************************************************************************************/
template <class IE>
struct ElementType<IE, std::enable_if_t<IE::ie_type == element_type::T_OBJFIELD_TF> >
{
	struct Selector
	{
		Selector(tag_value_t tag) : m_tag(tag) {}

		template<typename ELM> void operator()(size_t idx)
		{
			if(Element<ELM>::is_matched(m_tag))
			{
				m_index = idx;
				m_valid = true;
			}
		}

		size_t get_idx() const {return m_index;}
		bool is_valid() const {return m_valid;}

	private:
		tag_value_t m_tag;
		size_t		m_index {0};
		bool		m_valid {false};
	};

	static bool inline is_matched(tag_value_t tag)
	{
		Selector selector(tag);
		IE::enumerate(selector);

		return selector.is_valid();
	}
};

/***************************************************************************************
* Identifier
***************************************************************************************/
template <class IE, class Enabler = void>
struct Identifier
{
	static bool inline is_matched(tag_value_t _tag)
	{
		return ElementType<IE>::is_matched(_tag);
	}

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		ElementType<IE>::run(ie, ctx);
	}

	static void inline run(IE& ie, DecoderCtx& ctx, tag_value_t tag)
	{
		ElementType<IE>::run(ie, ctx, tag);
	}
};

template <class IE>
struct Identifier<IE, std::enable_if_t<IE::asn_identifier_t::tag_type == tag_type_t::EXPLICIT> >
{
	static bool inline is_matched(tag_value_t _tag) {return ExplicitCodec<IE>::is_matched(_tag);}

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
    ExplicitCodec<IE>::run(ie, ctx);
	}

	static void inline run(IE& ie, DecoderCtx& ctx, tag_value_t tag)
	{
    ExplicitCodec<IE>::run(ie, ctx, tag);
	}
};

/***************************************************************************************
* COMMON: Element
***************************************************************************************/
template <class IE>
struct Element
{
	static bool inline is_matched(tag_value_t _tag)
	{
		return Identifier<IE>::is_matched(_tag);
	}

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		if (ctx)
		{
			ASN_ENCODER_TRACE("IE<type=%d name=%s> buffer: %s", static_cast<int>(IE::ie_type), IE::name(), ctx.refBuffer().toString());
			ctx.ie_name(IE::name());
			Identifier<IE>::run(ie, ctx);
		}
	}
	static void inline run(IE& ie, DecoderCtx& ctx, tag_value_t const* tag_ptr = nullptr)
	{
		if (ctx)
		{
			ctx.ie_name(IE::name());

			tag_value_t tag = tag_ptr ? *tag_ptr : get_tag(ctx);
			if(ctx)
				Identifier<IE>::run(ie, ctx, tag);
		}
	}
};

} //namespace ber
} //namespace asn
