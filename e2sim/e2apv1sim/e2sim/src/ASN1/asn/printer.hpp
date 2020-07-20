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
#include <iostream>
#include <iomanip>

// Local Includes: Application specific classes, functions, and libraries
#include "asn/elements.hpp"

namespace asn{

/********************************************************************************
Utility
**********************************S***********************************************/
inline void skip_row(std::ostream* str, size_t row_shift)
	//{*str << std::string(row_shift, ' ');}
{
	std::string s(row_shift, ' ');
	str->write(s.data(), s.size());
}

inline void print_hex(std::ostream* str, size_t size, const uint8_t* data, size_t row_shift)
{
	*str << std::setfill('0') << std::hex << std::noshowbase;
	for (size_t i = 0; i < size; ++i)
	{
		if (i && (0x00 == (i & 0x0f))) { skip_row(str, row_shift); }
		*str << std::setw(2) << (int)data[i] << " ";
		if (0x0f == (i & 0x0f)) { *str << '\n'; }
	}
}

/********************************************************************************

Print

*********************************************************************************/


/********************************************************************************
default implementation for IE
*********************************************************************************/
template <class IE, element_type IE_TYPE>
struct Print;

template <class IE>
void print(IE const& ie, std::ostream& out, size_t row_shift)
{
	Print<IE, IE::ie_type>::run(ie, &out, row_shift);
}

template <class IE>
std::string get_printed(IE const& ie, size_t row_shift = 0)
{
	std::stringstream out;
	print(ie, out, row_shift);
	return out.str();
}


/********************************************************************************
VisitorPrinter
*********************************************************************************/
struct VisitorPrinter
{
	VisitorPrinter(std::ostream* str, size_t row_shift) : m_pStream(str), m_RowShift(row_shift) {}

	template <typename IE>
	bool operator() (IE & ie)
	{
		Print<IE, IE::ie_type>::run(ie, m_pStream, m_RowShift);
		return true;
	}

	std::ostream*	m_pStream;
	size_t			m_RowShift;
};

/******************************************************************
 * PrinterAdapter
 *****************************************************************/
template <class Container, typename IE, class Enabler = void>
struct PrinterAdapter
{
	static void inline run(IE const& ie, std::ostream* str, size_t row_shift, Container const& cont)
	{
		Print<IE, IE::ie_type>::run(ie, str, row_shift);
	}
};
template <class Container, typename IE>
struct PrinterAdapter<Container, IE, std::enable_if_t< (IE::ie_type == element_type::T_OBJFIELD_FTV) >>
{
	static void inline run(IE const& ie, std::ostream* str, size_t row_shift, Container const& cont)
	{
		VisitorPrinter vp(str, row_shift);
		ie.encode(vp, cont);
	}
};
template <class Container, typename IE>
struct PrinterAdapter<Container, IE, std::enable_if_t< (IE::ie_type == element_type::T_OBJFIELD_TF)> >
{
	static void inline run(IE const& ie, std::ostream* str, size_t row_shift, Container const& cont)
	{
		VisitorPrinter vp(str, row_shift);
		ie.encode(vp, cont);
	}
};

/********************************************************************************
SeqVisitorPrinter
*********************************************************************************/
template <class Container>
struct SeqVisitorPrinter
{
	SeqVisitorPrinter(Container const& cont, std::ostream* str, size_t row_shift) : m_pStream(str), m_RowShift(row_shift), m_cont(cont) {}

	template <typename IE>
	bool operator() (IE & ie)
	{
		if(!IE::optional || ie.is_valid())
			PrinterAdapter<Container, IE>::run(ie, m_pStream, m_RowShift, m_cont);
		return true;
	}

	std::ostream*		m_pStream;
	size_t				m_RowShift;
	Container const& 	m_cont;
};


/********************************************************************************
T_NULL
*********************************************************************************/

template <class IE>
struct Print<IE, element_type::T_NULL>
{
	static void inline run(IE const& ie, std::ostream* str, size_t row_shift)
	{
		skip_row(str, row_shift);
		*str << IE::name() << std::endl;
	}
};

/********************************************************************************
T_BOOLEAN
*********************************************************************************/
template <class IE>
struct Print<IE, element_type::T_BOOLEAN>
{
	static void inline run(IE const& ie, std::ostream* str, size_t row_shift)
	{
		skip_row(str, row_shift);
		*str << IE::name() << " = " << (ie.get() ? "true" : "false")<< std::endl;
	}
};

/********************************************************************************
T_INTEGER
*********************************************************************************/
template <class IE>
struct Print<IE, element_type::T_INTEGER>
{
	static void inline run(IE const& ie, std::ostream* str, size_t row_shift)
	{
		skip_row(str, row_shift);
		*str << IE::name() << " = " << std::hex << std::showbase << (size_t)ie.get() << std::endl;
	}
};

/********************************************************************************
T_ENUMERATED
*********************************************************************************/
template <class IE>
struct Print<IE, element_type::T_ENUMERATED>
{
	static void inline run(IE const& ie, std::ostream* str, size_t row_shift)
	{
		skip_row(str, row_shift);
		*str << IE::name() << " = " << std::hex << std::showbase << (size_t)ie.get() << std::endl;
	}
};

/********************************************************************************
T_BITSTRING
*********************************************************************************/
template <class IE>
struct Print<IE, element_type::T_BITSTRING>
{
	static void inline run(IE const& ie, std::ostream* str, size_t row_shift)
	{
		skip_row(str, row_shift);
		auto& val = ie.get_buffer();
		*str << IE::name() << " = ";

		print_hex(str, val.size() - 1, val.data(), row_shift + strlen(IE::name()) + 3);

		size_t  i = val.size() - 1;
		uint8_t c = val.data()[i];
		uint8_t b = val.bitqty() % 8;
		if (b != 0) c = c << (8 - b);

		if (i && (0x00 == (i & 0x0f))) { skip_row(str, row_shift); }
		*str << std::setw(2) << (int)c;

		*str << " (" << std::dec << val.bitqty() << " bits)" << std::endl;

	}
};

/********************************************************************************
T_OCTETSTRING
*********************************************************************************/
template <class IE>
struct Print<IE, element_type::T_OCTETSTRING>
{
	static void inline run(IE const& ie, std::ostream* str, size_t row_shift)
	{
		skip_row(str, row_shift);
		*str << IE::name() << " = ";
		auto & val = ie.get();
		print_hex(str, val.size(), val.data(), row_shift + strlen(IE::name()) + 3);
		*str << std::endl;
	}
};

/********************************************************************************
T_SEQUENCE
*********************************************************************************/
template <class IE>
struct Print<IE, element_type::T_SEQUENCE>
{
	static void inline run(IE const& ie, std::ostream* str, size_t row_shift)
	{
		skip_row(str, row_shift);
		*str << IE::name() << std::endl;
		SeqVisitorPrinter<IE> vp(ie, str, row_shift + 1);
		ie.encode(vp);
	}
};

/********************************************************************************
T_SET
*********************************************************************************/
template <class IE>
struct Print<IE, element_type::T_SET>
{
	static void inline run(IE const& ie, std::ostream* str, size_t row_shift)
	{
		skip_row(str, row_shift);
		*str << IE::name() << std::endl;
		SeqVisitorPrinter<IE> vp(ie, str, row_shift + 1);
		ie.encode(vp);
	}
};


/********************************************************************************
T_CHOICE
*********************************************************************************/
template <class IE>
struct Print<IE, element_type::T_CHOICE>
{
	static void inline run(IE const& ie, std::ostream* str, size_t row_shift)
	{
		VisitorPrinter vp(str, row_shift+1);
		skip_row(str, row_shift); *str << IE::name() << ":\n";
		ie.encode(vp);
	}
};

/********************************************************************************
T_SEQUENCE_OF
*********************************************************************************/
template <class IE>
struct Print<IE, element_type::T_SEQUENCE_OF>
{
	static void inline run(IE const& ie, std::ostream* str, size_t row_shift)
	{
		skip_row(str, row_shift); *str << IE::name() << ":\n";
		++row_shift;
		for (auto& elem : ie)
		{
			Print<typename IE::element_t, IE::element_t::ie_type>::run(elem, str, row_shift);
		}
	}
};

/********************************************************************************
T_SET_OF
*********************************************************************************/
template <class IE>
struct Print<IE, element_type::T_SET_OF>
{
	static void inline run(IE const& ie, std::ostream* str, size_t row_shift)
	{
		skip_row(str, row_shift); *str << IE::name() << ":\n";
		++row_shift;
		for (auto& elem : ie)
		{
			Print<typename IE::element_t, IE::element_t::ie_type>::run(elem, str, row_shift);
		}
	}
};

/********************************************************************************
T_OBJECTIDENTIFIER
*********************************************************************************/
template <class IE>
struct Print<IE, element_type::T_OBJECTIDENTIFIER>
{
	static void inline run(IE const& ie, std::ostream* str, size_t row_shift)
	{
		skip_row(str, row_shift);
		*str << IE::name() << std::endl;
	}
};

} //namespace asn
