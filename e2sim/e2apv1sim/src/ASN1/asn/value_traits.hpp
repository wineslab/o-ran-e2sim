#ifndef _STDEX_VALUE_TRAITS_HPP_INCLUDED_
#define _STDEX_VALUE_TRAITS_HPP_INCLUDED_

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

#include <boost/utility.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/less_equal.hpp>
#include <boost/mpl/greater.hpp>
#include <boost/mpl/and.hpp>

#include "type_defs.h"

namespace stdex {
namespace value {

namespace mpl = boost::mpl;

//NOTE! length is in bits
typedef mpl::int_<8>	_8;
typedef mpl::int_<16>	_16;
typedef mpl::int_<24>	_24;
typedef mpl::int_<32>	_32;
typedef mpl::int_<40>	_40;
typedef mpl::int_<48>	_48;
typedef mpl::int_<56>	_56;
typedef mpl::int_<64>	_64;

template<int num_bits>
struct bits_to_bytes : mpl::int_< (num_bits + 7) / 8 > {};

/******************************************************************************
* Class:		value::traits<LEN>
* Description:	select min integer type to fit LEN bits
* Notes:		LEN is positive integer type (mpl::int_) = number of bits
******************************************************************************/
template <class LEN, typename Enabler = void> struct traits;

template <class LEN>
struct traits<LEN, typename boost::enable_if<
		mpl::less_equal<LEN, _8>
	>::type
>
{
	typedef _8            value_length;
	typedef u8            value_type;
	typedef value_type    param_type;
};

template <class LEN>
struct traits<LEN, typename boost::enable_if<
		mpl::and_<mpl::greater<LEN, _8>, mpl::less_equal<LEN, _16> >
	>::type
>
{
	typedef _16           value_length;
	typedef u16           value_type;
	typedef value_type    param_type;
};

template <class LEN>
struct traits<LEN, typename boost::enable_if<
		mpl::and_<mpl::greater<LEN, _16>, mpl::less_equal<LEN, _24> >
	>::type
>
{
	typedef _24           value_length;
	typedef u32           value_type;
	typedef value_type    param_type;
};

template <class LEN>
struct traits<LEN, typename boost::enable_if<
		mpl::and_<mpl::greater<LEN, _24>, mpl::less_equal<LEN, _32> >
	>::type
>
{
	typedef _32           value_length;
	typedef u32           value_type;
	typedef value_type    param_type;
};

template <class LEN>
struct traits<LEN, typename boost::enable_if<
		mpl::and_<mpl::greater<LEN, _32>, mpl::less_equal<LEN, _40> >
	>::type
>
{
	typedef _40           value_length;
	typedef u64           value_type;
	typedef value_type    param_type;
};

template <class LEN>
struct traits<LEN, typename boost::enable_if<
		mpl::and_<mpl::greater<LEN, _40>, mpl::less_equal<LEN, _48> >
	>::type
>
{
	typedef _48           value_length;
	typedef u64           value_type;
	typedef value_type    param_type;
};

template <class LEN>
struct traits<LEN, typename boost::enable_if<
		mpl::and_<mpl::greater<LEN, _48>, mpl::less_equal<LEN, _56> >
	>::type
>
{
	typedef _56           value_length;
	typedef u64           value_type;
	typedef value_type    param_type;
};

template <class LEN>
struct traits<LEN, typename boost::enable_if<
		mpl::and_<mpl::greater<LEN, _56>, mpl::less_equal<LEN, _64> >
	>::type
>
{
	typedef _64           value_length;
	typedef u64           value_type;
	typedef value_type    param_type;
};

template <class LEN>
struct traits<LEN, typename boost::enable_if<
		mpl::greater<LEN, _64>
	>::type
>
{
	typedef LEN                         value_length;
	struct value_type {u8 value[bits_to_bytes<LEN::value>::value];};
	typedef value_type const&           param_type;
};


//template <class LEN>
//struct traits<LEN,
//	typename boost::enable_if<
//		mpl::greater<LEN, _32>
//	>::type
//>
//{
//	typedef LEN					value_length;
//	struct value_type {unsigned char value[LEN::value/8];};
//	typedef value_type const&	param_type;
//
//};

/******************************************************************************
* Class:		value::traits_c<BITS>
* Description:	select min integer type to fit BITS bits
* Notes:		N is positive integer value = number of bits
******************************************************************************/
template <size_t BITS>
struct traits_c : traits<boost::mpl::int_<BITS> >
{
};

}	//end:	namespace value

}	//end:	namespace stdex

#ifdef _MSC_VER
#pragma component( mintypeinfo, off )
#endif

#endif	//_STDEX_VALUE_TRAITS_HPP_INCLUDED_
