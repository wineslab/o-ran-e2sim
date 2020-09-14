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
* VisitorEncoder
***************************************************************************************/
struct VisitorEncoder
{
	VisitorEncoder(EncoderCtx& ctx) : m_ctx(ctx){}
	
	template<typename ELM> bool operator() (ELM const& elm) 
	{
		if(m_ctx)
			Element<ELM>::run(elm, m_ctx);
		return static_cast<bool>(m_ctx);
	}
private:
	EncoderCtx& 	m_ctx;
};

/***************************************************************************************
* VisitorDecoder
***************************************************************************************/
struct VisitorDecoder
{
	VisitorDecoder(DecoderCtx& ctx, tag_value_t tag) : m_ctx(ctx), m_tag(tag){}
	
	template<typename ELM> bool operator() (ELM& elm) 
	{
		if(m_ctx)
			Element<ELM>::run(elm, m_ctx, &m_tag);
		return static_cast<bool>(m_ctx);
	}

private:
	DecoderCtx& 	m_ctx;
	tag_value_t 	m_tag;
};

/***************************************************************************************
* VisitorAdapter
***************************************************************************************/
template <class Container, class IE, class Enabler = void>
struct VisitorAdapter //default
{
	static void inline run(IE const& ie, EncoderCtx& ctx, Container const& cont)
	{
		Element<IE>::run(ie, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx, Container const& cont, tag_value_t tag)
	{
		Element<IE>::run(ie, ctx, &tag);
	}
};

template <class Container, class IE>
struct VisitorAdapter<Container, IE, std::enable_if_t<
					(IE::ie_type == element_type::T_OBJFIELD_FTV)
					|| (IE::ie_type == element_type::T_OBJFIELD_TF)
					> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx, Container const& cont)
	{
		VisitorEncoder v(ctx);
		bool rv = ie.encode(v, cont);
		if(!rv && static_cast<bool>(ctx))
		{
			ctx.refErrorCtx().errorNoObject(Container::name());
		}
	}
	static void inline run(IE& ie, DecoderCtx& ctx, Container const& cont, tag_value_t tag)
	{
		VisitorDecoder v(ctx, tag);
		bool rv = ie.decode(v, cont);
		if(!rv && static_cast<bool>(ctx))
		{
			ctx.refErrorCtx().errorNoObject(Container::name());
		}
	}
};

/***************************************************************************************
* VisitorEncoderSeq
***************************************************************************************/
template<typename CONT>
struct VisitorEncoderSeq
{
	VisitorEncoderSeq(EncoderCtx& ctx, CONT const& cont) : m_ctx(ctx), m_cont(cont){}
	
	template<typename ELM> void operator() (ELM const& elm) 
	{
		if(ELM::optional)
		{
			if(elm.is_valid())
				VisitorAdapter<CONT, ELM>::run(elm, m_ctx, m_cont);
		}
		else
			VisitorAdapter<CONT, ELM>::run(elm, m_ctx, m_cont);
	}
	
	EncoderCtx& 	m_ctx;
	CONT const&		m_cont;
};


/***************************************************************************************
* VisitorDecoderSeq
***************************************************************************************/
template<typename CONT>
struct VisitorDecoderSeq
{
	VisitorDecoderSeq(DecoderCtx& ctx, CONT const& cont) : m_ctx(ctx), m_cont(cont){}
	
	template<typename ELM> void operator() (ELM& elm) 
	{
		if(m_ctx)
		{
			tag_value_t tag;
			
			if(invalid_tag == m_tag && m_ctx.refBuffer().getBytesLeft())
			{
				m_tag = get_tag(m_ctx);
			}
			tag = m_tag;

			if(m_ctx)
			{
				if (!Element<ELM>::is_matched(tag))
				{
					if(!ELM::optional)
					{
						m_ctx.refErrorCtx().tagError(static_cast<uint32_t>(tag));
					}
				}
				else
				{
					m_tag = invalid_tag;
					VisitorAdapter<CONT, ELM>::run(elm, m_ctx, m_cont, tag);
          elm.setpresent(true);
				}
			}
		}
	}
	
	tag_value_t get_unhandled_tag() const {return m_tag;}
	
	DecoderCtx& 	m_ctx;
	tag_value_t 	m_tag {invalid_tag};
	CONT const&		m_cont;
};

} //namespace ber
} //namespace asn
