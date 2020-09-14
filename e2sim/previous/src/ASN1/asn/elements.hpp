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
#include <boost/intrusive/list.hpp>
#include <cstring>

// Local Includes: Application specific classes, functions, and libraries
#include "asn/constraints.hpp"
#include "asn/identifier.hpp"

namespace asn {

enum class element_type : uint8_t
{
	 T_BOOLEAN
	,T_INTEGER
	,T_ENUMERATED
	,T_REAL
	,T_BITSTRING
	,T_OCTETSTRING
	,T_NULL
	,T_SEQUENCE
	,T_SEQUENCE_OF
	,T_SET
	,T_SET_OF
	,T_CHOICE
	,T_OBJECTIDENTIFIER
	,T_OBJFIELD_FTV
	,T_OBJFIELD_TF
};

/***************************************************************************************
* BASE
***************************************************************************************/

struct base
{
	static constexpr bool optional = false;
	static constexpr bool extension = false;

	static constexpr char const* name() {return "";}

	void setpresent(bool p) {is_set = p;}
	void clear() {is_set = false;}

	bool is_valid() const {return is_set;}

protected:
	base() {}
	void set() {is_set = true;}
protected:
	bool is_set {false};

	base& operator=(const base&) = delete;
	base (const base&) = delete;
};

/***************************************************************************************
* IE_NULL
***************************************************************************************/

struct nulltype : base
{
	using asn_identifier_t = identifier<class_type_t::UNIVERSAL, static_cast<tag_value_t>(tag_rvalue_t::NULL_TYPE), tag_type_t::IMPLICIT>;

	static constexpr element_type ie_type = element_type::T_NULL;
	static constexpr const char* name() {return "NULL";}

	void clear() {}
};

/***************************************************************************************
* T_BOOLEAN
***************************************************************************************/

struct boolean : base
{
	using asn_identifier_t = identifier<class_type_t::UNIVERSAL, static_cast<tag_value_t>(tag_rvalue_t::BOOLEAN), tag_type_t::IMPLICIT>;

	static constexpr element_type ie_type = element_type::T_BOOLEAN;
	static constexpr const char* name() {return "BOOLEAN";}

	using value_type = bool;

	void set(value_type vl) { m_value = vl; base::set();}
	value_type get() const { return m_value; }
	void clear() { m_value = false; base::clear();}

private:
	value_type  m_value {false};
};

/***************************************************************************************
* T_INTEGER
***************************************************************************************/
template < class Constraint = constraints<false> >
struct integer : base
{
	using asn_identifier_t = identifier<class_type_t::UNIVERSAL, static_cast<tag_value_t>(tag_rvalue_t::INTEGER), tag_type_t::IMPLICIT>;

	static constexpr element_type ie_type = element_type::T_INTEGER;
	static constexpr const char* name() {return "INTEGER";}

	using constraint_t	= Constraint;
	using value_type 	= int64_t;

	bool equal(value_type v) const {return m_value == v;}

	void set(value_type v) { m_value = v; base::set();}
	value_type get() const { return m_value; }

	void clear() { m_value = 0; base::clear();}

private:
	value_type m_value;
};

/***************************************************************************************
* T_ENUMERATED
***************************************************************************************/
template<int TotalNumEntries, int NumExtEntries, bool Extended>
struct enumerated : base
{
	using asn_identifier_t = identifier<class_type_t::UNIVERSAL, static_cast<tag_value_t>(tag_rvalue_t::ENUMERATED), tag_type_t::IMPLICIT>;

	static constexpr element_type ie_type = element_type::T_ENUMERATED;
	static constexpr const char* name() {return "ENUMERATED";}

	using constraint_t	= seq_range<TotalNumEntries, NumExtEntries, Extended>;
	using value_type	= typename constraint_t::value_type;

	bool equal(value_type v) const {return m_value == v;}
	void set(value_type vl) { m_value = vl; base::set();}
	value_type get() const { return m_value; }
	void clear() { m_value = constraint_t::default_value; base::clear();}

private:
	value_type m_value;
};

/***************************************************************************************
* T_OCTETSTRING
***************************************************************************************/
template< class Constraint = constraints<false> >
struct ostring : base
{
	using asn_identifier_t = identifier<class_type_t::UNIVERSAL, static_cast<tag_value_t>(tag_rvalue_t::OCTET_STRING), tag_type_t::IMPLICIT>;

	static constexpr element_type ie_type = element_type::T_OCTETSTRING;
	static constexpr const char* name() {return "OCTET STING";}
	using constraint_t	= Constraint;

	struct value_type
	{
		value_type() {}
		value_type(size_t size, const char* data) : m_size(size), m_data(reinterpret_cast<const uint8_t*>(data)) {}

		size_t size() const                 { return m_size; }
		const uint8_t* data() const         { return m_data; }

		using const_iterator = uint8_t const*;
		const_iterator begin() const        { return data(); }
		const_iterator end() const          { return begin() + size(); }

		void assign(void const* p, size_t sz)  { m_data = static_cast<uint8_t const*>(p); m_size = sz; }

	private:
		const uint8_t*	m_data{ 0 };
		size_t			m_size{ 0 };
	};

	value_type const& get() const { return m_value; }

	//Use std::string, std::vector or IE_OSTR::value_type
	template<typename T> value_type const& set(T const& tval)
	{
		set(tval.size(), tval.data());
		base::set();
		return m_value;
	}

	void set(size_t size, void const* data)
	{
		m_value.assign(data, size);
		base::set();
	}

	template<class AT>
	ostring& emplace(AT& allocator, size_t size, uint8_t const * data_in)
	{
		if(size)
		{
			base::clear();
			uint8_t* data_out = allocator.alloc_bytes(size);
			if (data_out)
			{
				memcpy(data_out, data_in, size);
				set(size, data_out);
			}
		}
		else
			base::set();
		return *this;
	}

	template<class AT, class T>
	ostring& emplace(AT& allocator, T const& tval)
	{
		return emplace(allocator, tval.size(), reinterpret_cast<const uint8_t*>(tval.data()));
	}

	void clear() { m_value = value_type{}; base::clear();}

private:
	value_type m_value;
};

/***************************************************************************************
* T_BITSTRING
***************************************************************************************/
template<class Constraint = constraints<false> >
struct bstring : base
{
	using asn_identifier_t = identifier<class_type_t::UNIVERSAL, static_cast<tag_value_t>(tag_rvalue_t::BIT_STRING), tag_type_t::IMPLICIT>;

	static constexpr element_type ie_type = element_type::T_BITSTRING;
	static constexpr const char* name() {return "BIT STING";}
	using constraint_t	= Constraint;

	struct value_type
	{
		value_type() {}
		value_type(size_t size, const char* data, size_t bitqty) : m_size(size), m_data(reinterpret_cast<const uint8_t*>(data)), m_bitqty(bitqty){}

		size_t size() const { return m_size; }
		const uint8_t* data() const { return m_data; }
		size_t bitqty() const { return m_bitqty; }

		void assign(void const* p, size_t sz, size_t bits)  { m_data = static_cast<uint8_t const*>(p); m_size = sz; m_bitqty = bits; }

	private:
		const uint8_t*	m_data{ nullptr };
		size_t			m_size{ 0 };
		size_t			m_bitqty{ 0 };
	};

	value_type const& get_buffer() const { return m_value; }

	size_t get_bitqty()            const { return m_value.bitqty(); }

	//Use std::string, std::vector or IE_BSTR::value_type
	template<typename T> value_type const& set_buffer(T& tval, size_t bitqty)
	{
		m_value.assign(tval.data(), tval.size(), bitqty);
		base::set();
		return m_value;
	}

	void set_buffer(size_t bitqty, const uint8_t* data)
	{
		m_value.assign(data, (bitqty +7) >> 3, bitqty);
		base::set();
	}

	template<class AT>
	bstring& emplace_buffer(AT& allocator, size_t bitqty, uint8_t const * data_in)
	{
		size_t size = (bitqty +7) >> 3;
		uint8_t* data_out = allocator.alloc_bytes(size);
		if (!data_out) {
			throw std::bad_alloc();
		}
		memcpy(data_out, data_in, size);
		set_buffer(bitqty, data_out);
		return *this;
	}

	void clear() { m_value = value_type{}; base::clear();}

	uint64_t get_number() const
	{
		uint64_t retval{0};
		size_t i = 0;
		for(; i < m_value.size() - 1; ++i)
		{
			retval <<= 8;
			retval |= m_value.data()[i];
		}

		uint8_t shift = m_value.bitqty() % 8;
		if (shift)
		{
			retval <<= shift;
		}
		else
		{
			retval <<= 8;
		}

		retval |= m_value.data()[i];

		return retval;
	}

	template<class AT>
	void set_number(AT& allocator, size_t bitqty, uint64_t data)
	{
		size_t size = (bitqty +7) >> 3;
		uint8_t* data_out = allocator.alloc_bytes(size);
		if (!data_out) {
			throw std::bad_alloc();
		}

		const uint8_t shift = bitqty % 8;
		if (shift)
		{
			data_out[size-1] = data & (0xFF >> (8 - shift));
			data >>= shift;
		}
		else
		{
			data_out[size-1] = data & (0xFF);
			data >>= 8;
		}

		for (size_t i = 1; i <= size - 1; i++)
		{
			data_out[size-1-i] = data & (0xFF);
			data >>= 8;
		}

		m_value.assign(data_out, size, bitqty);
		base::set();
	}

private:
	value_type m_value;
};

/***************************************************************************************
* T_CHOICE
***************************************************************************************/
template<int TotalNumEntries, int NumExtEntries, bool Extended>
struct choice : base
{
  using asn_identifier_t = identifier<class_type_t::UNSPECIFIED, static_cast<tag_value_t>(tag_rvalue_t::CHOICE), tag_type_t::IMPLICIT>;

	static constexpr element_type ie_type = element_type::T_CHOICE;
	static constexpr const char* name() {return "CHOICE";}

	using constraint_t	= seq_range<TotalNumEntries, NumExtEntries, Extended>;
	using index_type	= size_t;
	using value_type	= size_t;

	static constexpr index_type fst_index = 1;
	static constexpr index_type ext_index = fst_index + TotalNumEntries;

	static index_type normalize(index_type idx) 	{return idx - fst_index;}
	static index_type denormalize(index_type idx) 	{return idx + fst_index;}
};

/***************************************************************************************
* T_SEQUENCE
***************************************************************************************/
template<int TotalNumEntries, int NumExtEntries, bool Extended, int NumOptEntries = 0>
struct sequence : base
{
	using asn_identifier_t = identifier<class_type_t::UNIVERSAL, static_cast<tag_value_t>(tag_rvalue_t::SEQUENCE), tag_type_t::IMPLICIT>;

	static constexpr element_type ie_type = element_type::T_SEQUENCE;
	static constexpr const char* name() {return "SEQUENCE";}

	static constexpr bound_t num_total_entries 	= TotalNumEntries;
	static constexpr bound_t num_opt_entries 	= NumOptEntries;
	static constexpr bound_t num_ext_entries 	= NumExtEntries;

	using constraint_t	= seq_range<TotalNumEntries, NumExtEntries, Extended>;

};

/***************************************************************************************
* T_SEQUENCE_OF
***************************************************************************************/
template<typename T, class Constraint = constraints<false> >
struct sequenceof : base
{
	using asn_identifier_t = identifier<class_type_t::UNIVERSAL, static_cast<tag_value_t>(tag_rvalue_t::SEQUENCE_OF), tag_type_t::IMPLICIT>;

	static constexpr element_type ie_type = element_type::T_SEQUENCE_OF;
	static constexpr const char* name() {return "SEQUENCE OF";}

	struct value_type : T, boost::intrusive::list_base_hook< boost::intrusive::link_mode<boost::intrusive::auto_unlink> >
	{
		value_type(){}
	private:
		value_type& operator=(const value_type&) = delete;
		value_type (const value_type&) = delete;
	};

	using values_t 		= boost::intrusive::list<value_type, boost::intrusive::constant_time_size<false>>;
	using constraint_t	= Constraint;
	using element_t		= T;

	void clear()                        { m_list.clear(); base::clear();}
	size_t size() const                 { return m_list.size(); }
	template<class Predicate>
	void sort(Predicate const& p)       { m_list.sort(p); }

	template<class V>
	void set(V& v)                      {for(auto & e : v) {m_list.push_back(e);} base::set();}

	void push_back(value_type& v)       { m_list.push_back(v); base::set();}

	template<class AT> //Note: Allocator must return word alligned buffer!
	T& emplace_back(AT& allocator)
	{
		uint8_t* data = allocator.alloc_bytes(sizeof(value_type));
		if(!data)
			throw std::bad_alloc();
		value_type* v = new (data) value_type;
		push_back(*v);
		return *v;
	};

	using iterator = typename values_t::iterator;
	iterator begin()                    { return m_list.begin(); }
	iterator end()                      { return m_list.end(); }

	using const_iterator = typename values_t::const_iterator;
	const_iterator begin() const        { return m_list.begin(); }
	const_iterator end() const          { return m_list.end(); }

	sequenceof(){}

private:
	values_t m_list;
};

/***************************************************************************************
* T_OBJFIELD_FTV
***************************************************************************************/
template<typename T, bool>
struct fixedtypefield : T
{
	static constexpr element_type ie_type = element_type::T_OBJFIELD_FTV;

	T& ref_nested() {return *this;}
	T const & ref_nested() const {return *this;}
};

/***************************************************************************************
* T_OBJFIELD_TF
***************************************************************************************/
template<bool>
struct typefield : base
{
	static constexpr element_type ie_type = element_type::T_OBJFIELD_TF;
	static constexpr const char* name() {return "type-field";}

	typefield& ref_nested() {return *this;}
	typefield const& ref_nested() const {return *this;}

	bool is_unknown() const {return false;}
};

/***************************************************************************************
* T_OBJECTIDENTIFIER
***************************************************************************************/
struct oid : ostring<>
{
	using asn_identifier_t = identifier<class_type_t::UNIVERSAL, static_cast<tag_value_t>(tag_rvalue_t::OBJECT_IDENTIFIER), tag_type_t::IMPLICIT>;

	static constexpr element_type ie_type = element_type::T_OBJECTIDENTIFIER;
	static constexpr const char* name() {return "OBJECT IDENTIFIER";}
};

/***************************************************************************************
* T_PRINTABLESTRING
***************************************************************************************/
template<class Constraint = constraints<false> >
struct printable_string : ostring<Constraint>
{
	using asn_identifier_t = identifier<class_type_t::UNIVERSAL, static_cast<tag_value_t>(tag_rvalue_t::PrintableString), tag_type_t::IMPLICIT>;
	static constexpr const char* name() {return "PrintableString";}
};

/***************************************************************************************
* T_IA5_STRING
***************************************************************************************/
template<class Constraint = constraints<false> >
struct ia5_string : ostring<Constraint>
{
	using asn_identifier_t = identifier<class_type_t::UNIVERSAL, static_cast<tag_value_t>(tag_rvalue_t::IA5String), tag_type_t::IMPLICIT>;
	static constexpr const char* name() {return "IA5String";}
};

/***************************************************************************************
* T_GRAPHIC_STRING
***************************************************************************************/
template<class Constraint = asn::constraints<false> >
struct graphic_string : ostring<Constraint>
{
	using asn_identifier_t = identifier<class_type_t::UNIVERSAL, static_cast<tag_value_t>(tag_rvalue_t::GraphicString), tag_type_t::IMPLICIT>;
	static constexpr const char* name() {return "IA5String";}
};

/***************************************************************************************
* T_UTF8_STRING
***************************************************************************************/
template<class Constraint = asn::constraints<false> >
struct utf8_string : ostring<Constraint>
{
	using asn_identifier_t = identifier<class_type_t::UNIVERSAL, static_cast<tag_value_t>(tag_rvalue_t::UTF8String), tag_type_t::IMPLICIT>;
	static constexpr const char* name() {return "UTF8String";}
};

/***************************************************************************************
* T_SET
***************************************************************************************/
template<int TotalNumEntries, int NumExtEntries, bool Extended, int NumOptEntries = 0>
struct set : base
{
	using asn_identifier_t = identifier<class_type_t::UNIVERSAL, static_cast<tag_value_t>(tag_rvalue_t::SET), tag_type_t::IMPLICIT>;

	static constexpr element_type ie_type = element_type::T_SET;
	static constexpr const char* name() {return "SET";}

	static constexpr bound_t num_total_entries 	= TotalNumEntries;
	static constexpr bound_t num_opt_entries 	= NumOptEntries;
	static constexpr bound_t num_ext_entries 	= NumExtEntries;

	using constraint_t	= seq_range<TotalNumEntries, NumExtEntries, Extended>;
};

/***************************************************************************************
* T_SET_OF
***************************************************************************************/
template<typename T, class Constraint = constraints<false> >
struct setof : sequenceof<T, Constraint>
{
	using asn_identifier_t = identifier<class_type_t::UNIVERSAL, static_cast<tag_value_t>(tag_rvalue_t::SET_OF), tag_type_t::IMPLICIT>;

	static constexpr element_type ie_type = element_type::T_SET_OF;
	static constexpr const char* name() {return "SET OF";}
};
} //namespace asn
