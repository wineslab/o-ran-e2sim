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
#include "asn/per/visitor.hpp"

namespace asn {
namespace per {

/******************************************************************
 * Adapter
 *****************************************************************/
template <class Container, typename IE, class Enabler = void>
struct Adapter
{
	static void inline run(IE const& ie, EncoderCtx& ctx, Container const& cont)
	{
		Element<IE, IE::ie_type>::run(ie, ctx);
	}
	
	static void inline run(IE& ie, DecoderCtx& ctx, Container const& cont)
	{
		Element<IE, IE::ie_type>::run(ie, ctx);
	}
};
template <class Container, typename IE>
struct Adapter<Container, IE, std::enable_if_t< (IE::ie_type == element_type::T_OBJFIELD_FTV) >>
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
	
	static void inline run(IE& ie, DecoderCtx& ctx, Container const& cont)
	{
		VisitorDecoder v(ctx);
		bool rv = ie.decode(v, cont);
		if(!rv && static_cast<bool>(ctx))
		{
			ctx.refErrorCtx().errorNoObject(Container::name());
		}
	}
};
template <class Container, typename IE>
struct Adapter<Container, IE, std::enable_if_t< (IE::ie_type == element_type::T_OBJFIELD_TF)> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx, Container const& cont)
	{
		OpenTypeVisitorEncoder v(ctx);
		bool rv = ie.encode(v, cont);
		if(!rv && static_cast<bool>(ctx))
		{
			ctx.refErrorCtx().errorNoObject(Container::name());
		}
	}
	
	static void inline run(IE& ie, DecoderCtx& ctx, Container const& cont)
	{
		OpenTypeVisitorDecoder v(ctx);
		bool rv = ie.decode(v, cont);
		if(!rv && static_cast<bool>(ctx))
		{
			ctx.refErrorCtx().errorNoObject(Container::name());
		}
		if(ie.is_unknown()) //skip the unknown Open Type
		{
			size_t size = LengthDeterminantDefault::run(ctx);
			DecoderCtx::buf_type& buffer = ctx.refBuffer();
			if (buffer.getBytesLeft() < size)
				ctx.refErrorCtx().lengthErrorBytes(buffer.getBytesLeft(), size);
			else
				buffer.advance(size);
		}
	}
};

/******************************************************************
 * RootEncoder
 *****************************************************************/
template <class Container>
struct RootEncoder
{
	RootEncoder(EncoderCtx& ctx, Container const& cont) : m_ctx(ctx), m_cont(cont) {}
	
	template <typename IE>
	bool operator() (IE const& ie) const
	{
		if(!IE::extension)
		{
			if(IE::optional && !ie.is_valid())
				return static_cast<bool>(m_ctx);
			Adapter<Container, IE>::run(ie, m_ctx, m_cont);
		}
		return static_cast<bool>(m_ctx);
	}
	EncoderCtx& m_ctx;
	Container const& m_cont;
};

/******************************************************************
 * RootDecoder
 *****************************************************************/
template <class Container>
struct RootDecoder
{
	RootDecoder(DecoderCtx& ctx, Container const& cont) : m_ctx(ctx), m_cont(cont) {}
	
	template <typename IE>
	bool operator() (IE& ie) const
	{
		if(!IE::extension)
		{
			if(IE::optional)
			{
				if(m_ctx.map_elm())
				{
					ie.setpresent(true);
					Adapter<Container, IE>::run(ie, m_ctx, m_cont);
				}
				else
					ie.setpresent(false);
			}
			else
			{
				Adapter<Container, IE>::run(ie, m_ctx, m_cont);
			}
		}
		return static_cast<bool>(m_ctx);
	}
	DecoderCtx& m_ctx;
	Container const& m_cont;
};

/******************************************************************
 * ExtEncoder
 *****************************************************************/
template <class Container>
struct ExtEncoder
{
	explicit ExtEncoder(EncoderCtx& ctx, Container const& cont) : m_ctx(ctx), m_cont(cont) {}

	template <typename IE>
	bool operator() (IE const& ie) const
	{
		if(!IE::extension)
			return static_cast<bool>(m_ctx);
		
		if(IE::optional && !ie.is_valid())
			return static_cast<bool>(m_ctx);
		
		size_t reserved_size = 1; //1 byte length is most likely
		Tools::bit_accessor::padByte(m_ctx.refBuffer());

		if (m_ctx.refBuffer().getBytesLeft())
		{
			EncoderCtx::buf_type::pointer p = m_ctx.refBuffer().advance(reserved_size);
			EncoderCtx::buf_type::pointer start = p + reserved_size;

			Adapter<Container, IE>::run(ie, m_ctx, m_cont);

			if (m_ctx)
			{
				Tools::bit_accessor::padByte(m_ctx.refBuffer());
				EncoderCtx::buf_type::pointer p_new = m_ctx.refBuffer().begin();
				size_t size = p_new - start;
				size_t needed = LengthDeterminantDefault::bytes_needed(size) - reserved_size;
				if (needed) //1 byte is not enough for the length determinant. it is hardly possible
				{
					if (m_ctx.refBuffer().getBytesLeft() < needed) {
						m_ctx.refErrorCtx().lengthErrorBytes(m_ctx.refBuffer().getBytesLeft(), needed);
						return false;
					}
					memmove(start + needed, start, size);
					p_new += needed;
				}
				m_ctx.refBuffer().set_begin(p, 0);
				LengthDeterminantDefault::run(m_ctx, size);
				if (m_ctx) {
					m_ctx.refBuffer().set_begin(p_new, 0);
					Tools::bit_accessor::padByte(m_ctx.refBuffer());
				}
			}
		}
		else
		{
			m_ctx.refErrorCtx().lengthErrorBytes(m_ctx.refBuffer().getBytesLeft(), reserved_size);
			return false;
		}
		return static_cast<bool>(m_ctx);
	}
	EncoderCtx& m_ctx;
	Container const& m_cont;
};

/******************************************************************
 * ExtDecoder
 *****************************************************************/
template <class Container>
struct ExtDecoder
{
	explicit ExtDecoder(DecoderCtx& ctx, Container const& cont) : m_ctx(ctx), m_cont(cont) {}

	template <typename IE>
	bool operator() (IE& ie) const
	{
		if(!IE::extension)
			return static_cast<bool>(m_ctx);

		if (m_ctx.map_elm())
		{
			ie.setpresent(true);
			size_t size = LengthDeterminantDefault::run(m_ctx);
			DecoderCtx::buf_type& buffer = m_ctx.refBuffer();
			if (buffer.getBytesLeft() < size)
			{
				m_ctx.refErrorCtx().lengthErrorBytes(buffer.getBytesLeft(), size);
				return false;
			}
			DecoderCtx::buf_type::pointer end = buffer.end();
			buffer.set_end(buffer.begin() + size);
			Adapter<Container, IE>::run(ie, m_ctx, m_cont);
			Tools::bit_accessor::padByte(m_ctx.refBuffer());
			buffer.set_end(end);
		}
		else
		{
			ie.setpresent(false);
		}

		return static_cast<bool>(m_ctx);
	}
	DecoderCtx& m_ctx;
	Container const& m_cont;
};

/******************************************************************
 * SeqMap
 *****************************************************************/
template<class IE, class Enabler = void>
struct SeqMap;

/*
template <class IE>
struct SeqMap<IE, std::enable_if_t< (IE::num_opt_entries > 8) > >
{
	static void inline run(EncoderCtx& ctx, size_t val)
	{
		u8 k       = IE::num_opt_entries / 8; // num of full bytes in a seq map mask
		u8 fb_bits = IE::num_opt_entries % 8; // num of first byte bits (without padding)

		if (fb_bits) {
			// Put a part of a first byte (without padding, only seq map own bits)
			Tools::bit_accessor::put((u8)(val >> 8*k), fb_bits, ctx.refBuffer());
		}

		// Put other bytes (full bytes)
		for (int i = (k-1); i >= 0; i--) {
			Tools::bit_accessor::put((u8)(val >> 8*i), 8, ctx.refBuffer());
		}
	}

	static DecoderCtx::map_type inline run(DecoderCtx& ctx)
	{
		uint num_opts = IE::num_opt_entries;
		u64 res = 0;
		u8  k   = 1;
		u8  lb_bits  = IE::num_opt_entries % 8; // num of last byte bits (without padding)

		while (num_opts >= 8) {
			size_t shift = sizeof(DecoderCtx::map_type) * CHAR_BIT - 8*k;

			DecoderCtx::map_type rval = Tools::bit_accessor::get(8, ctx.refBuffer());

			rval = rval << shift;
			res |= rval;

			k++;
			num_opts -= 8;
		}

		if (lb_bits > 0) {
			// (8 - lb_bits) - padding in a last byte
			size_t shift = sizeof(DecoderCtx::map_type) * CHAR_BIT - 8*k + 8 - lb_bits;

			DecoderCtx::map_type rval = Tools::bit_accessor::get(lb_bits, ctx.refBuffer());

			rval  = rval << shift;
			res |= rval;
		}

		return res;
	}
}
;
*/

template<class IE>
struct SeqMap<IE, std::enable_if_t< (IE::num_opt_entries <= 8)> > //todo: to add code for more than 8 optional elements
{
	static void inline run(EncoderCtx& ctx, size_t val)
	{
		Tools::bit_accessor::put((u8)val, IE::num_opt_entries, ctx.refBuffer());
	}
	static DecoderCtx::map_type inline run(DecoderCtx& ctx)
	{
		size_t shift = sizeof(DecoderCtx::map_type) * CHAR_BIT - IE::num_opt_entries;
		DecoderCtx::map_type rval = Tools::bit_accessor::get(IE::num_opt_entries, ctx.refBuffer());
		rval = rval << shift;
		return rval;
	}
};

/******************************************************************
 * SeqExtMap
 *****************************************************************/
template<class IE, bound_t NumExtEntries, class Enabler = void>
struct SeqExtMap
{
	static void inline run(EncoderCtx& ctx, size_t val) {}
	static DecoderCtx::map_type inline run(DecoderCtx& ctx)
	{
		size_t len = NormallySmallLength<1>::run(ctx);
		size_t shift = sizeof(DecoderCtx::map_type) * CHAR_BIT - len;
		u8 tmp;
		DecoderCtx::map_type rval{ 0 };
		u8 val;

		while (len) {
			tmp = len > 8 ? 8 : (u8)len;
			val = Tools::bit_accessor::get(tmp, ctx.refBuffer());
			rval = rval << tmp;
			rval |= val;
			len -= tmp;
		}
		rval = rval << shift;
		return rval;
	}
};

template<class IE, bound_t NumExtEntries>
struct SeqExtMap<IE, NumExtEntries, std::enable_if_t< ((NumExtEntries <= 8) && (NumExtEntries > 0)) > >
{
	static void inline run(EncoderCtx& ctx, size_t val)
	{
		NormallySmallLength<NumExtEntries>::run(ctx);
		Tools::bit_accessor::put((u8)val, NumExtEntries, ctx.refBuffer());
	}
};

template<class IE, bound_t NumExtEntries>
struct SeqExtMap<IE, NumExtEntries, std::enable_if_t< (NumExtEntries > 8) > >
{
	static void inline run(EncoderCtx& ctx, size_t val)
	{
		NormallySmallLength<NumExtEntries>::run(ctx);

		size_t len = NumExtEntries;
		size_t tmp;

		while (len) {
			tmp = len > 8 ? 8 : len;
			Tools::bit_accessor::put((u8)val, tmp, ctx.refBuffer());
			val = val >> tmp;
			len -= tmp;
		}
	}
};

/******************************************************************
 * SeqMapBuilder
 *****************************************************************/
struct SeqMapBuilder
{
	SeqMapBuilder(uint64_t& map) : m_map(map) {}

	template<typename IE>
	bool operator()(IE const& ie)
	{
		if(!IE::extension && IE::optional)
		{
			m_map = m_map << 1;
			if(ie.is_valid())
				m_map |= 1;
		}
		return true;
	}
	uint64_t&	m_map;
};

/******************************************************************
 * SeqExtMapBuilder
 *****************************************************************/
struct SeqExtMapBuilder
{
	SeqExtMapBuilder(uint64_t& map) : m_map(map) {}

	template<typename IE>
	bool operator()(IE const& ie)
	{
		if(IE::extension)
		{
			m_map = m_map << 1;
			if(!IE::optional || (IE::optional &&  ie.is_valid()))
				m_map |= 1;
		}
		return true;
	}
	uint64_t& 	m_map;
};

/******************************************************************
 * SeqNoExtDefault
 *****************************************************************/
// Default (No OPT/DEF present within the extension root)
template <class IE>
struct SeqNoExtDefault
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		RootEncoder<IE> ve(ctx, ie);
		ie.encode(ve);
	}
	static void inline run(IE& ie, DecoderCtx& ctx, DecoderCtx::map_type map = 0)
	{
		RootDecoder<IE> ve(ctx, ie);
		
		DecoderCtx::map_type old_map = ctx.set_map(map);
		ie.decode(ve);
		ctx.set_map(old_map);
	}
};

/******************************************************************
 * SeqNoExt
 *****************************************************************/
// Default (No OPT/DEF present within the extension root)
template <class IE, class Enabler = void>
struct SeqNoExt
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		SeqNoExtDefault<IE>::run(ie, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		SeqNoExtDefault<IE>::run(ie, ctx);
	}
};

//18.2 OPT/DEF present within the extension root 
template <class IE>
struct SeqNoExt<IE, std::enable_if_t< (IE::num_opt_entries > 0) > >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		uint64_t map = 0;
		SeqMapBuilder mb(map);
		ie.encode(mb);
		SeqMap<IE>::run(ctx, map);
		SeqNoExtDefault<IE>::run(ie, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		SeqNoExtDefault<IE>::run(ie, ctx, SeqMap<IE>::run(ctx));
	}
};

/******************************************************************
 * Seq
 *****************************************************************/
template <class IE, class Enable = void>
struct Seq;

template <class IE>
struct Seq<IE, std::enable_if_t< (IE::constraint_t::extended == true)> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		uint64_t map = 0;
		SeqExtMapBuilder emb(map);
		ie.encode(emb);
		
		if (map) {
			Tools::bit_accessor::put(1, 1, ctx.refBuffer());
			SeqNoExt<IE>::run(ie, ctx);
			SeqExtMap<IE, IE::num_ext_entries>::run(ctx, map);
			ExtEncoder<IE> ove(ctx, ie);
			ie.encode(ove);
		}
		else {
			Tools::bit_accessor::put(0, 1, ctx.refBuffer());
			SeqNoExt<IE>::run(ie, ctx);
		}
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		u8 ext = Tools::bit_accessor::get(1, ctx.refBuffer());
		if (ext)
		{
			SeqNoExt<IE>::run(ie, ctx);
			
			auto old_map = ctx.set_map(SeqExtMap<IE, 0>::run(ctx)); // we do not know how many exts can be received
			{
				ExtDecoder<IE> ove(ctx, ie);
				ie.decode(ove);
				
				auto& buffer = ctx.refBuffer();
				while(ctx.get_map())
				{
					if(ctx.map_elm()) //skip unknown extensions
					{
						size_t size = LengthDeterminantDefault::run(ctx);
						if (buffer.getBytesLeft() < size)
						{
							ctx.refErrorCtx().lengthErrorBytes(buffer.getBytesLeft(), size);
							break;
						}
						buffer.advance(size);
					}
				}
			}
			ctx.set_map(old_map);
		}
		else
			SeqNoExt<IE>::run(ie, ctx);
	}
};

template <class IE>
struct Seq<IE, std::enable_if_t< (IE::constraint_t::extended == false)> >
{
	static void inline run(IE const& ie, EncoderCtx& ctx)
	{
		SeqNoExt<IE>::run(ie, ctx);
	}
	static void inline run(IE& ie, DecoderCtx& ctx)
	{
		SeqNoExt<IE>::run(ie, ctx);
	}
};

} //namespace per
} //namespace asn
