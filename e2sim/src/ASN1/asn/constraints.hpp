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
*
******************************************************************************/

// Standard Includes: ANSI C/C++, MSA, and Third-Party Libraries
#include <limits>
#include <type_traits>
#include <algorithm>
#include <array>

// Local Includes: Application specific classes, functions, and libraries

namespace asn {

using bound_t = int64_t;

enum class constraint_type : uint8_t
{
	UNCONSTRAINED,
	CONSTRAINED,
	SEMICONSTRAINED,
	CONSTRAINED_EXTENDED,
	SEMICONSTRAINED_EXTENDED
};

template <bound_t LB, bound_t UB>
struct span
{
	static_assert(UB >= LB, "UPPER >= LOWER");
	static constexpr bound_t lower_bound = LB;
	static constexpr bound_t upper_bound = UB;
};

template <typename T>
struct pair
{
	T const lower_bound;
	T const upper_bound;
};

template <bound_t VALUE>
struct one : span<VALUE, VALUE> {};

struct max : one<std::numeric_limits<bound_t>::max()> {};
struct min : one<std::numeric_limits<bound_t>::min()> {};

static constexpr bound_t MAX = std::numeric_limits<bound_t>::max();
static constexpr bound_t MIN = std::numeric_limits<bound_t>::min();

template <bool Extended, class... RANGE>
struct constraints
{
	static constexpr bool extended = Extended;
	static constexpr bound_t lower_bound = std::min({RANGE::lower_bound...});
	static constexpr bound_t upper_bound = std::max({RANGE::upper_bound...});

	static constexpr constraint_type type =
			(Extended && lower_bound > min::lower_bound && upper_bound < max::upper_bound) ? constraint_type::CONSTRAINED_EXTENDED :
				(!Extended && lower_bound > min::lower_bound && upper_bound < max::upper_bound) ? constraint_type::CONSTRAINED :
					(Extended && lower_bound > min::lower_bound && upper_bound == max::upper_bound) ? constraint_type::SEMICONSTRAINED_EXTENDED :
						(!Extended && lower_bound == min::lower_bound && upper_bound < max::upper_bound) ? constraint_type::SEMICONSTRAINED : 
							(Extended && lower_bound == min::lower_bound && upper_bound < max::upper_bound) ? constraint_type::SEMICONSTRAINED_EXTENDED :
								(!Extended && lower_bound > min::lower_bound && upper_bound == max::upper_bound) ? constraint_type::SEMICONSTRAINED : constraint_type::UNCONSTRAINED;
	
	static constexpr bool is_signed = lower_bound < 0;

	static constexpr bound_t num_spans = static_cast<bound_t>(sizeof...(RANGE));
	static constexpr pair<bound_t> bounds[] = {{RANGE::lower_bound, RANGE::upper_bound}...};
	
	using boundary_type = bound_t;

	static constexpr bool is_extended(bound_t val)
	{
		for (bound_t i = 0; i < num_spans; ++i)
		{
			auto const& p = bounds[i];
			if (val <= p.upper_bound)
			{
				if(val < p.lower_bound)
					return true;
				return false;
			}
		}
		return true;
	}
};

template <bool Extended, class... RANGE>
constexpr pair<bound_t> constraints<Extended, RANGE...>::bounds[];

template <bool Extended>
struct constraints<Extended>
{
	static constexpr bool extended = Extended;
	static constexpr constraint_type type = constraint_type::UNCONSTRAINED;
	static constexpr bound_t lower_bound = std::numeric_limits<bound_t>::min();
	static constexpr bound_t upper_bound = std::numeric_limits<bound_t>::max();
	
	static constexpr bool is_extended(bound_t val) {return true;}
};

/***************************************************************************************
* RANGE for sequences
***************************************************************************************/
template<int TotalNumEntries, int NumExtEntries, bool Extended>
struct seq_range
{
	static_assert(Extended || TotalNumEntries > 0, "TotalNumEntries must be > 0");
	static_assert(NumExtEntries <= TotalNumEntries, "NumExtEntries must be <= TotalNumEntries");
	
	static constexpr constraint_type type 		= Extended ? constraint_type::CONSTRAINED_EXTENDED : constraint_type::CONSTRAINED;
	static constexpr bool extended 				= Extended;
	static constexpr bound_t lower_bound 		= 0;
	static constexpr bound_t upper_bound 		= TotalNumEntries - NumExtEntries - 1;
	static constexpr bound_t default_value 		= lower_bound;
	static constexpr bound_t total_num_entries 	= TotalNumEntries;
	
	using boundary_type = bound_t;
	using value_type 	= uint32_t;
};

} // namespace asn
