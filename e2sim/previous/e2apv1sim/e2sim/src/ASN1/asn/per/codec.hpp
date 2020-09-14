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
#include "asn/elements.hpp"
#include "asn/per/context.hpp"
#include "asn/per/length.hpp"
#include "asn/per/integer.hpp"
#include "asn/per/enumerated.hpp"
#include "asn/per/ostring.hpp"
#include "asn/per/bstring.hpp"
#include "asn/per/sequence_of.hpp"
#include "asn/per/sequence.hpp"
#include "asn/per/choice.hpp"
#include "asn/per/visitor.hpp"
#include "asn/per/oid.hpp"

namespace asn {
namespace per {

/********************************************************************************
pack
*********************************************************************************/
template <class IE>
bool pack(IE const& ie, EncoderCtx& ctx)
{
	ctx.refErrorCtx().reset();
	Element<IE, IE::ie_type>::run(ie, ctx);

	if (ctx)
		Tools::bit_accessor::padByte(ctx.refBuffer());

	return static_cast<bool>(ctx);
}
/********************************************************************************
unpack
*********************************************************************************/
template <class IE>
bool unpack(IE& ie, DecoderCtx& ctx)
{
	Element<IE, IE::ie_type>::run(ie, ctx);
	
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
template <class IE, element_type IE_TYPE>
struct ElementType;

/***************************************************************************************
* BOOLEAN: Encoding the boolean type (X.691 11)
***************************************************************************************/
template <class IE>
struct ElementType<IE, element_type::T_BOOLEAN>
{
protected:
	template <class, element_type> friend struct Element;

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		Tools::bit_accessor::put(static_cast<u8>(ie.get()), 1, ctx.refBuffer());
	}

	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		ie.set(0 != Tools::bit_accessor::get(1, ctx.refBuffer()));
	}
};
/***************************************************************************************
* INTEGER: Encoding the integer type (X.691 12)
***************************************************************************************/
template <class IE>
struct ElementType<IE, element_type::T_INTEGER>
{
protected:
	template <class, element_type> friend struct Element;

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		Integer<IE>::run(ie, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		Integer<IE>::run(ie, ctx);
	}
};
/***************************************************************************************
* ENUMERATED: Encoding the enumerated type (X.691 13)
***************************************************************************************/
template <class IE>
struct ElementType<IE, element_type::T_ENUMERATED>
{
protected:
	template <class, element_type> friend struct Element;

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		Enumerated<IE>::run(ie, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		Enumerated<IE>::run(ie, ctx);
	}
};
/***************************************************************************************
* BIT STRING: Encoding the bitstring type (X.691 15)
***************************************************************************************/
template <class IE>
struct ElementType<IE, element_type::T_BITSTRING>
{
protected:
	template <class, element_type> friend struct Element;

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		Bitstring<IE>::run(ie, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		ie.clear();
		Bitstring<IE>::run(ie, ctx);
	}
};
/***************************************************************************************
* OCTET STRING: Encoding the octetstring type (X.691 16)
***************************************************************************************/
template <class IE>
struct ElementType<IE, element_type::T_OCTETSTRING>
{
protected:
	template <class, element_type> friend struct Element;

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		Octetstring<IE>::run(ie, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		ie.clear();
		Octetstring<IE>::run(ie, ctx);
	}
};
/***************************************************************************************
* NULL: Encoding the null type (X.691 17)
***************************************************************************************/
template <class IE>
struct ElementType<IE, element_type::T_NULL>
{
protected:
	template <class, element_type> friend struct Element;

	static void inline run(IE const& ie, EncoderCtx& ctx) {	/*do nothing*/ }
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		ie.setpresent(true);
	}
};
/***************************************************************************************
* SEQUENCE: Encoding the sequence type (X.691 18)
***************************************************************************************/
template <class IE>
struct ElementType<IE, element_type::T_SEQUENCE>
{
protected:
	template <class, element_type> friend struct Element;

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		ctx.container_name(IE::name());
		Seq<IE>::run(ie, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		ctx.m_container = &ie;
		Seq<IE>::run(ie, ctx);
		ctx.m_container = nullptr;
	}
};
/***************************************************************************************
* SEQUENCE OF: Encoding the sequence-of type (X.691 19)
***************************************************************************************/
template <class IE>
struct ElementType<IE, element_type::T_SEQUENCE_OF>
{
protected:
	template <class, element_type> friend struct Element;

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		ctx.container_name(IE::name());
		SequenceOf<IE>::run(ie, ctx);

		for (auto& elem : ie)
			Element<typename IE::element_t, IE::element_t::ie_type>::run(elem, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		ie.clear();
		SequenceOf<IE>::run(ie, ctx);

		for (auto & elem : ie)
			Element<typename IE::element_t, IE::element_t::ie_type>::run(elem, ctx);
	}
};
/***************************************************************************************
* SET: Encoding the set type (X.691 20)
***************************************************************************************/


/***************************************************************************************
* SET OF: Encoding the set-of type (X.691 21)
***************************************************************************************/

/***************************************************************************************
* CHOICE: Encoding the choice type (X.691 22)
***************************************************************************************/
template <class IE>
struct ElementType<IE, element_type::T_CHOICE>
{
protected:
	template <class, element_type> friend struct Element;

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		if(ie.is_valid())
		{
			ctx.container_name(IE::name());
			Choice<IE>::run(ie, ctx);
		}
		else
			ctx.refErrorCtx().tagError(ie.get_index());
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		ie.clear();
		ctx.m_container = &ie;
		Choice<IE>::run(ie, ctx);
		ctx.m_container = nullptr;
	}
};

/***************************************************************************************
* IE_OBJECT_IDENTIFIER: Encoding the object identifier type (X.691 23)
***************************************************************************************/
template <class IE>
struct ElementType<IE, element_type::T_OBJECTIDENTIFIER>
{
protected:
	template <class, element_type> friend struct Element;

	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		Oid<IE>::run(ie, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		ie.clear();
		Oid<IE>::run(ie, ctx);
	}
};

/***************************************************************************************
* COMMON: Element
***************************************************************************************/
template <class IE, element_type IE_TYPE>
struct Element
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		if (ctx)
		{
			ASN_ENCODER_TRACE("IE<type=%d name=%s> buffer: %s", static_cast<int>(IE_TYPE), IE::name(), ctx.refBuffer().toString());
			ctx.ie_name(IE::name());
			if (IE_TYPE != element_type::T_SEQUENCE && !ie.is_valid())
			{
				ctx.refErrorCtx().errorNoMandatory();
			}
			else
				ElementType<IE, IE_TYPE>::run(ie, ctx);
		}
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		if (ctx)
		{
			ASN_DECODER_TRACE("IE<type=%d name=%s> buffer: %s", static_cast<int>(IE_TYPE), IE::name(), ctx.refBuffer().toString());
			ctx.ie_name(IE::name());
			ElementType<IE, IE_TYPE>::run(ie, ctx);
		}
	}
};

} //namespace per
} //namespace asn
