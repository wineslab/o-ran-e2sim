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
*******************************************************************************/

// Standard Includes: ANSI C/C++, MSA, and Third-Party Libraries
#include <cstring>

// Local Includes: Application specific classes, functions, and libraries
#include "asn/error_context.hpp"
#include "value_traits.hpp"

//#define CODEC_BIT_TRACE_ENABLE
#ifdef CODEC_BIT_TRACE_ENABLE
	#define CODEC_BIT_TRACE(FMT, args...) printf("%s[%u]:" FMT "\n", std::strrchr(__FILE__, '/') + 1, __LINE__, ##args)
#else
	#define CODEC_BIT_TRACE(...)
#endif

namespace asn {

template <class IE, class VALUE, bool LSB>
struct bit_accessor;

template <bool LSB>
struct bit_accessor_cross_byte;

template <typename PTR>
class buffer
{
public:
	typedef PTR pointer;

	explicit buffer(error_context& err)
		: m_errCtx(err)
	{}

	void reset(pointer data, u32 size)
	{
		m_start 	= data;
		m_end   	= m_start + size;
		m_current   = m_start;
		m_shift     = 0;
	}

	u32 getOffset() const          { return begin() - m_start; }

	u32 getBytesLeft() const       { return end() - begin(); }
	u32 getBytesUsed() const       { return getOffset() + (get_shift() ? 1 : 0); }

	u8 get_shift() const           { return m_shift; }
	void reset_shift()             { m_shift = 0; }
	void byte_align()              { if (get_shift()) { m_shift = 0; ++m_current; } }

	pointer advance(u32 delta)     { pointer p = begin(); m_current += delta; return p; }

	pointer begin() const          { return m_current; }

	void set_begin(pointer ptr, u8 bit_shift)
	{
		if (m_start <= ptr && ptr <= end())
		{
			m_current = ptr;
			m_shift = bit_shift;
		}
	}

	pointer end() const            { return m_end; }
	void set_end(pointer v)        { m_end = v; }

	bool checkAlignment(char const* name, u8 const mask = 0xFF)
	{
		if (0 == (get_shift() & mask)) return true;
		m_errCtx.alignmentError(name, get_shift());
		return false;
	}

	bool checkBytesLeft(char const* name, u32 const num_bytes)
	{
		if (getBytesLeft() >= num_bytes) return true;
		m_errCtx.lengthErrorBytes(name, getBytesLeft(), num_bytes);
		return false;
	}

	bool checkBitsLeft(char const* name, u32 const num_bits)
	{
		if (getBitsLeft() >= num_bits) return true;
		m_errCtx.lengthErrorBits(name, getBitsLeft(), num_bits);
		return false;
	}

	bool checkBytesAndAlignment(char const* name, u32 const num_bytes, u8 const mask = 0xFF)
	{
		if (getBytesLeft() >= num_bytes)
		{
			if (0 == (get_shift() & mask)) return true;
			m_errCtx.alignmentError(name, get_shift());
		}
		else
		{
			m_errCtx.lengthErrorBytes(name, getBytesLeft(), num_bytes);
		}
		return false;
	}

	pointer getBytes(char const* name, u32 num_bytes)
	{
		if (checkBytesAndAlignment(name, num_bytes))
		{
			return advance(num_bytes);
		}
		return nullptr;
	}

	//NOTE! num_bytes should be set to minimal number of bytes expected
	pointer getBytes(char const* name, u32 max_requested, u32& num_bytes)
	{
		if (checkAlignment(name))
		{
			u32 const left = getBytesLeft();
			if (left >= num_bytes)
			{
				num_bytes = (left > max_requested) ? max_requested : left;
				return advance(num_bytes);
			}

			m_errCtx.lengthErrorBytes(name, getBytesLeft(), num_bytes);
		}
		return nullptr;
	}

	bool putByte(char const* name, u8 byte)
	{
		if (checkBytesAndAlignment(name, 1))
		{
			begin()[0] = byte;
			++m_current;
			return true;
		}
		return false;
	}

	bool putBytes(char const* name, void const* in, u32 num_bytes)
	{
		if (checkBytesAndAlignment(name, num_bytes))
		{
			std::memcpy(begin(), in, num_bytes);
			m_current += num_bytes;
			return true;
		}
		return false;
	}
	
	bool checkAlignment(u8 const mask = 0xFF)
	{
		if (0 == (get_shift() & mask)) return true;
		m_errCtx.alignmentError(get_shift());
		return false;
	}

	bool checkBytesLeft(u32 const num_bytes)
	{
		if (getBytesLeft() >= num_bytes) return true;
		m_errCtx.lengthErrorBytes(getBytesLeft(), num_bytes);
		return false;
	}

	bool checkBitsLeft(u32 const num_bits)
	{
		if (getBitsLeft() >= num_bits) return true;
		m_errCtx.lengthErrorBits(getBitsLeft(), num_bits);
		return false;
	}

	bool checkBytesAndAlignment(u32 const num_bytes, u8 const mask = 0xFF)
	{
		if (getBytesLeft() >= num_bytes)
		{
			if (0 == (get_shift() & mask)) return true;
			m_errCtx.alignmentError(get_shift());
		}
		else
		{
			m_errCtx.lengthErrorBytes(getBytesLeft(), num_bytes);
		}
		return false;
	}

	pointer getBytes(u32 num_bytes)
	{
		if (checkBytesAndAlignment(num_bytes))
		{
			return advance(num_bytes);
		}
		return nullptr;
	}

	//NOTE! num_bytes should be set to minimal number of bytes expected
	pointer getBytes(u32 max_requested, u32& num_bytes)
	{
		if (checkAlignment())
		{
			u32 const left = getBytesLeft();
			if (left >= num_bytes)
			{
				num_bytes = (left > max_requested) ? max_requested : left;
				return advance(num_bytes);
			}

			m_errCtx.lengthErrorBytes(getBytesLeft(), num_bytes);
		}
		return nullptr;
	}

	bool putByte(u8 byte)
	{
		if (checkBytesAndAlignment(1))
		{
			begin()[0] = byte;
			++m_current;
			return true;
		}
		return false;
	}

	bool putBytes(void const* in, u32 num_bytes)
	{
		if (num_bytes)
		{
			if(checkBytesAndAlignment(num_bytes))
			{
				std::memcpy(begin(), in, num_bytes);
				m_current += num_bytes;
			}
			else
				return false;
		}
		return true;
	}

	char const* toString() const
	{
		static char sz[64];
		u8 const* p = begin();
		snprintf(sz, sizeof(sz), "%02X %02X %02X %02X [%02X]=%p@%u..%p -%u bits: +%u bytes", p[-4], p[-3], p[-2], p[-1], p[0], p
			, getOffset(), end(), get_shift(), getBytesLeft());
		return sz;
	}

private:
	template <class IE, class VALUE, bool LSB>
	friend class bit_accessor;
	
	template <bool LSB>
	friend struct bit_accessor_cross_byte;

	template <typename U>
	void push_u8(U value)          { *m_current++ = static_cast<u8>(value); }
	template <typename U>
	void put_u8(U value)           { m_current[0] = static_cast<u8>(value); }

//khxm68: TODO: won't compile without it. WTF?!
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
	u8 get_u8() const              { return m_current[0]; }
#pragma GCC diagnostic pop
	u8 extract_u8(u8 value, u8 mask, u8 shift) const
		{ return (get_u8() & ~(mask << shift)) | ((value & mask) << shift); }

	u16 get_u16() const            { return (static_cast<u16>(m_current[0]) << 8) | m_current[1]; }
	u16 extract_u16(u16 value, u16 mask, u16 shift) const
		{ return (get_u16() & ~(mask << shift)) | ((value & mask) << shift); }

	u32 get_u24() const            { return (static_cast<u32>(m_current[0]) << 16) | (static_cast<u32>(m_current[1]) << 8) | m_current[2]; }
	u32 extract_u24(u32 value, u32 mask, u32 shift) const
		{ return (get_u24() & ~(mask << shift)) | ((value & mask) << shift); }

	u32 get_u32() const            { return (static_cast<u32>(m_current[0]) << 24) | (static_cast<u32>(m_current[1]) << 16) | (static_cast<u32>(m_current[2]) << 8) | m_current[3]; }
	u32 extract_u32(u32 value, u32 mask, u32 shift) const
		{ return (get_u32() & ~(mask << shift)) | ((value & mask) << shift); }

	u32 getBitsLeft() const        { return begin() == end() ? 0 : (getBytesLeft()*8 - get_shift()); }

	void bit_advance(u8 num_bits)
	{
		m_shift += num_bits;
		if (get_shift() > 7)
		{
			reset_shift();
			m_current++;
		}
	}

	pointer  m_current;
	pointer  m_end;
	pointer  m_start;
	u8       m_shift;
	error_context& m_errCtx;
};

template <class IE>	//LSB 1..7 bits
struct bit_accessor<IE, stdex::value::_8, true>
{
	static_assert(IE::length::value > 0 && IE::length::value < 8, "something wrong with traits!");

	static void put(u8 value, buffer<u8*>& buf)
	{
		u8 const mask = static_cast<u8>((1u << IE::length::value) - 1);
		u8 const shift = buf.get_shift();
		u8 const data = buf.extract_u8(value, mask, shift);
		buf.put_u8(data);

		CODEC_BIT_TRACE("put shift=%u(%u) data[%u]=%02X(%02X) mask=%04X: %s", shift, buf.get_shift()
			, IE::length::value, data, value, mask, buf.toString());

		buf.bit_advance(IE::length::value);
	}

	static u8 get(buffer<u8 const*>& buf)
	{
		u8 const mask = static_cast<u8>((1u << IE::length::value) - 1);
		u8 const shift = buf.get_shift();
		u8 const data = (buf.get_u8() >> shift) & mask;

		CODEC_BIT_TRACE("get shift=%u(%u) data[%u]=%02X mask=%02X: %s", shift, buf.get_shift()
			, IE::length::value, data, mask, buf.toString());

		buf.bit_advance(IE::length::value);
		return data;
	}
};

template <class IE>	//LSB 9..15 bits
struct bit_accessor<IE, stdex::value::_16, true>
{
	static_assert(IE::length::value > 8 && IE::length::value < 16, "something wrong with traits!");

	static void put(u16 value, buffer<u8*>& buf)
	{
		u16 const mask = static_cast<u16>((1u << IE::length::value) - 1);
		u16 const shift = buf.get_shift();
		u16 const data = buf.extract_u16(value, mask, shift);
		buf.push_u8(data >> 8);
		buf.put_u8(data);

		CODEC_BIT_TRACE("put shift=%u(%u) data[%u]=%04X(%04X) mask=%04X: %s", shift, buf.get_shift()
			, IE::length::value, data, value, mask, buf.toString());

		buf.bit_advance(IE::length::value - 8);
	}

	static u16 get(buffer<u8 const*>& buf)
	{
		u16 const mask = static_cast<u16>((1u << IE::length::value) - 1);
		u16 const shift = buf.get_shift();
		u16 const data = (buf.get_u16() >> shift) & mask;
		buf.m_current += 1;

		CODEC_BIT_TRACE("get shift=%u(%u) data[%u]=%04X mask=%04X: %s", shift, buf.get_shift()
			, IE::length::value, data, mask, buf.toString());

		buf.bit_advance(IE::length::value - 8);
		return data;
	}
};

template <class IE>	//LSB 17..24 bits
struct bit_accessor<IE, stdex::value::_24, true>
{
	static_assert(IE::length::value > 16 && IE::length::value <= 24, "something wrong with traits!");

	static void put(u32 value, buffer<u8*>& buf)
	{
		u32 const mask = static_cast<u32>((1u << IE::length::value) - 1);
		u32 const shift = buf.get_shift();
		u32 const data = buf.extract_u24(value, mask, shift);

		buf.push_u8(data >> 16);
		buf.push_u8(data >> 8);
		buf.put_u8(data);

		CODEC_BIT_TRACE("put shift=%u(%u) data[%u]=%06X(%06X) mask=%06X: %s", shift, buf.get_shift()
			, IE::length::value, data, value, mask, buf.toString());

		buf.bit_advance(IE::length::value - 16);
	}

	static u32 get(buffer<u8 const*>& buf)
	{
		u32 const mask = static_cast<u32>((1u << IE::length::value) - 1);
		u32 const shift = buf.get_shift();
		u32 const data = (buf.get_u24() >> shift) & mask;
		buf.m_current += 2;

		CODEC_BIT_TRACE("get shift=%u(%u) data[%u]=%06X mask=%06X: %s", shift, buf.get_shift()
			, IE::length::value, data, mask, buf.toString());

		buf.bit_advance(IE::length::value - 16);
		return data;
	}
};

template <class IE>	//LSB 25..31 bits
struct bit_accessor<IE, stdex::value::_32, true>
{
	static_assert(IE::length::value > 24 && IE::length::value < 32, "something wrong with traits!");

	static void put(u32 value, buffer<u8*>& buf)
	{
		u32 const mask = static_cast<u32>((1u << IE::length::value) - 1);
		u32 const shift = buf.get_shift();
		u32 const data = buf.extract_u32(value, mask, shift);

		buf.push_u8(data >> 24);
		buf.push_u8(data >> 16);
		buf.push_u8(data >> 8);
		buf.put_u8(data);

		CODEC_BIT_TRACE("put shift=%u(%u) data[%u]=%08X(%08X) mask=%08X: %s", shift, buf.get_shift()
			, IE::length::value, data, value, mask, buf.toString());

		buf.bit_advance(IE::length::value - 24);
	}

	static u32 get(buffer<u8 const*>& buf)
	{
		u32 const mask = static_cast<u32>((1u << IE::length::value) - 1);
		u32 const shift = buf.get_shift();
		u32 const data = (buf.get_u32() >> shift) & mask;
		buf.m_current += 3;

		CODEC_BIT_TRACE("get shift=%u(%u) data[%u]=%08X mask=%08X: %s", shift, buf.get_shift()
			, IE::length::value, data, mask, buf.toString());

		buf.bit_advance(IE::length::value - 24);
		return data;
	}
};


template <class IE>	//MSB 1..7 bits
struct bit_accessor<IE, stdex::value::_8, false>
{
	static_assert(IE::length::value > 0 && IE::length::value < 8, "something wrong with traits!");

	static void put(u8 value, buffer<u8*>& buf)
	{
		u8 const mask = static_cast<u8>((1u << IE::length::value) - 1);
		u8 const shift = 8 - buf.get_shift() - IE::length::value;
		u8 const data = buf.extract_u8(value, mask, shift);
		buf.put_u8(data);

		CODEC_BIT_TRACE("put shift=%u(%u) data[%u]=%02X(%02X) mask=%04X: %s", shift, buf.get_shift()
			, IE::length::value, data, value, mask, buf.toString());

		buf.bit_advance(IE::length::value);
	}

	static u8 get(buffer<u8 const*>& buf)
	{
		u8 const mask = static_cast<u8>((1u << IE::length::value) - 1);
		u8 const shift = 8 - buf.get_shift() - IE::length::value;
		u8 const data = (buf.get_u8() >> shift) & mask;

		CODEC_BIT_TRACE("get shift=%u(%u) data[%u]=%02X mask=%02X: %s", shift, buf.get_shift()
			, IE::length::value, data, mask, buf.toString());

		buf.bit_advance(IE::length::value);
		return data;
	}
};

template <class IE>	//MSB 9..15 bits
struct bit_accessor<IE, stdex::value::_16, false>
{
	static_assert(IE::length::value > 8 && IE::length::value < 16, "something wrong with traits!");

	static void put(u16 value, buffer<u8*>& buf)
	{
		u16 const mask = static_cast<u16>((1u << IE::length::value) - 1);
		u16 const shift = 16 - buf.get_shift() - IE::length::value;
		u16 const data = buf.extract_u16(value, mask, shift);

		buf.push_u8(data >> 8);
		buf.put_u8(data);

		CODEC_BIT_TRACE("put shift=%u(%u) data[%u]=%04X(%04X) mask=%04X: %s", shift, buf.get_shift()
			, IE::length::value, data, value, mask, buf.toString());

		buf.bit_advance(IE::length::value - 8);
	}

	static u16 get(buffer<u8 const*>& buf)
	{
		u16 const mask = static_cast<u16>((1u << IE::length::value) - 1);
		u16 const shift = 16 - buf.get_shift() - IE::length::value;
		u16 const data = (buf.get_u16() >> shift) & mask;
		buf.m_current += 1;

		CODEC_BIT_TRACE("get shift=%u(%u) data[%u]=%04X mask=%04X: %s", shift, buf.get_shift()
			, IE::length::value, data, mask, buf.toString());

		buf.bit_advance(IE::length::value - 8);
		return data;
	}
};


template <class IE>	//MSB 17..24 bits
struct bit_accessor<IE, stdex::value::_24, false>
{
	static_assert(IE::length::value > 16 && IE::length::value <= 24, "something wrong with traits!");

	static void put(u32 value, buffer<u8*>& buf)
	{
		u32 const mask = static_cast<u32>((1u << IE::length::value) - 1);
		u32 const shift = 24 - buf.get_shift() - IE::length::value;
		u32 const data = buf.extract_u24(value, mask, shift);

		buf.push_u8(data >> 16);
		buf.push_u8(data >> 8);
		buf.put_u8(data);

		CODEC_BIT_TRACE("put shift=%u(%u) data[%u]=%06X(%06X) mask=%06X: %s", shift, buf.get_shift()
			, IE::length::value, data, value, mask, buf.toString());

		buf.bit_advance(IE::length::value - 16);
	}

	static u32 get(buffer<u8 const*>& buf)
	{
		u32 const mask = static_cast<u32>((1u << IE::length::value) - 1);
		u32 const shift = 24 - buf.get_shift() - IE::length::value;
		u32 const data = (buf.get_u24() >> shift) & mask;
		buf.m_current += 2;

		CODEC_BIT_TRACE("get shift=%u(%u) data[%u]=%06X mask=%06X: %s", shift, buf.get_shift()
			, IE::length::value, data, mask, buf.toString());

		buf.bit_advance(IE::length::value - 16);
		return data;
	}
};

template <class IE>	//MSB 25..31 bits
struct bit_accessor<IE, stdex::value::_32, false>
{
	static_assert(IE::length::value > 24 && IE::length::value < 32, "something wrong with traits!");

	static void put(u32 value, buffer<u8*>& buf)
	{
		u32 const mask = static_cast<u32>((1u << IE::length::value) - 1);
		u32 const shift = 32 - buf.get_shift() - IE::length::value;
		u32 const data = buf.extract_u32(value, mask, shift);

		buf.push_u8(data >> 24);
		buf.push_u8(data >> 16);
		buf.push_u8(data >> 8);
		buf.put_u8(data);

		CODEC_BIT_TRACE("put shift=%u(%u) data[%u]=%08X(%08X) mask=%08X: %s", shift, buf.get_shift()
			, IE::length::value, data, value, mask, buf.toString());

		buf.bit_advance(IE::length::value - 24);
	}

	static u32 get(buffer<u8 const*>& buf)
	{
		u32 const mask = static_cast<u32>((1u << IE::length::value) - 1);
		u32 const shift = 32 - buf.get_shift() - IE::length::value;
		u32 const data = (buf.get_u32() >> shift) & mask;
		buf.m_current += 3;

		CODEC_BIT_TRACE("get shift=%u(%u) data[%u]=%08X mask=%08X: %s", shift, buf.get_shift()
			, IE::length::value, data, mask, buf.toString());

		buf.bit_advance(IE::length::value - 24);
		return data;
	}
};

/********************************************************************************
bit_accessor_cross_byte
*********************************************************************************/
template<>
struct bit_accessor_cross_byte<false> //MSB
{
	static bool put(u8 value, u8 length, buffer<u8*>& buf)
	{
		u8 spare = 8 - buf.get_shift();

		if (spare < length)
		{
			length -= spare;
			u8 chunk = value >> length;
			u8 const mask = static_cast<u8>((1u << spare) - 1);
			u8 data = buf.extract_u8(chunk, mask, 0);
			buf.put_u8(data);

			buf.bit_advance(spare);
		}
		if (buf.checkBytesLeft(1))
		{
			u8 const mask = static_cast<u8>((1u << length) - 1);
			u8 const shift = 8 - buf.get_shift() - length;
			u8 data = buf.extract_u8(value, mask, shift);
			buf.put_u8(data);

			buf.bit_advance(length);

			return true;
		}
		return false;
	}

	static u8 get(u8 length, buffer<u8 const*>& buf)
	{
		u8 rval {0};
		u8 const mask = static_cast<u8>((1u << length) - 1);
		u8 const spare = 8 - buf.get_shift();
		if (spare < length)
		{
			length -= spare;
			rval = buf.get_u8() << length;
			buf.bit_advance(spare);
		}
		if (length && buf.checkBytesLeft(1))
		{
			u8 val = buf.get_u8();
			val = val >> (8 - length - buf.get_shift());
			rval |= val;
			rval &= mask;
			buf.bit_advance(length);
		}
		return rval;
	}

	static void padByte(buffer<u8*>& buf)
	{
		if (buf.get_shift())
		{
			u8 mask = static_cast<u8>((1u << buf.get_shift()) - 1);
			mask = mask << (8 - buf.get_shift());
			buf.begin()[0] &= mask;
			buf.bit_advance(8 - buf.get_shift());
		}
	}

	static void padByte(buffer<u8 const*>& buf)
	{
		if(buf.get_shift())
			buf.bit_advance(8 - buf.get_shift());
	}

	static bool put(const u8* in, size_t len, buffer<u8*>& buf, u8 trail_bitsqty)
	{
		if (len)
		{
			if (trail_bitsqty)
			{
				buf.putBytes(in, len - 1);
				u8 last_byte = in[len - 1];
				last_byte = last_byte >> (8 - trail_bitsqty);
				return put(last_byte, trail_bitsqty, buf);
			}
			buf.putBytes(in, len);
		}
		return true;
	}
};

}	//end: namespace asn


