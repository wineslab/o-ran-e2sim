/*****************************************************************************
# Copyright 2019 AT&T Intellectual Property                                  *
#                                                                            *
# Licensed under the Apache License, Version 2.0 (the "License");            *
# you may not use this file except in compliance with the License.           *
# You may obtain a copy of the License at                                    *
#                                                                            *
#      http://www.apache.org/licenses/LICENSE-2.0                            *
#                                                                            *
# Unless required by applicable law or agreed to in writing, software        *
# distributed under the License is distributed on an "AS IS" BASIS,          *
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
# See the License for the specific language governing permissions and        *
# limitations under the License.                                             *
#                                                                            *
******************************************************************************/

#pragma once

#include "asn/asn.hpp"
static_assert(ASN_API_VERSION_MAJOR == 5, "re-generate the ASN parser's code using 'make regen-asn' (do not use -j option)");


/*
Criticality		::= ENUMERATED { reject, ignore, notify }
*/

struct Criticality : asn::enumerated<3, 0, false>
{
	static constexpr const char* name() {return "Criticality";}
	using parent_t = asn::enumerated<3, 0, false>;
	typedef enum {
		reject
		,ignore
		,notify
	} index_t;

};

/*
Presence		::= ENUMERATED { optional, conditional, mandatory }
*/

struct Presence : asn::enumerated<3, 0, false>
{
	static constexpr const char* name() {return "Presence";}
	using parent_t = asn::enumerated<3, 0, false>;
	typedef enum {
		optional
		,conditional
		,mandatory
	} index_t;

};

/*
maxPrivateIEs 									INTEGER ::= 65535
*/

constexpr int64_t maxPrivateIEs = 65535;
/*
PrivateIE-ID	::= CHOICE {
	local				INTEGER (0.. maxPrivateIEs),
	global				OBJECT IDENTIFIER
}
*/

struct PrivateIE_ID : asn::choice<2, 0, false>
{
	static constexpr const char* name() {return "PrivateIE-ID";}
	using parent_t = asn::choice<2, 0, false>;
	index_type get_index() const {return index;}
	~PrivateIE_ID() {clear();}
	struct local_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0,  maxPrivateIEs >>;
		static constexpr const char* name() {return "local_t";}
		using parent_t = asn::integer<>;

	};

	struct global_t : asn::oid
	{
		static constexpr const char* name() {return "global_t";}
		using parent_t = asn::oid;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<local_t>(); break;
		case 2: var.destroy<global_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<local_t>());
		case 2: set_index(2); return v(var.build<global_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<local_t>());
		case 2: return v(var.as<global_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<local_t>(1);
		v.template operator()<global_t>(2);

	}
	local_t& select_local() { if(get_index() != 1) { clear(); set_index(1); return var.build<local_t>();} return var.as<local_t>();}
	local_t const* get_local() const { if(get_index() == 1) { return &var.as<local_t>();} return nullptr; }
	global_t& select_global() { if(get_index() != 2) { clear(); set_index(2); return var.build<global_t>();} return var.as<global_t>();}
	global_t const* get_global() const { if(get_index() == 2) { return &var.as<global_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(local_t)];
		char dummy2[sizeof(global_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
ProcedureCode		::= INTEGER (0..255)
*/

struct ProcedureCode : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 255>>;
	static constexpr const char* name() {return "ProcedureCode";}
	using parent_t = asn::integer<>;

};

/*
maxProtocolIEs									INTEGER ::= 65535
*/

constexpr int64_t maxProtocolIEs = 65535;
/*
ProtocolIE-ID		::= INTEGER (0..maxProtocolIEs)
*/

struct ProtocolIE_ID : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0,  maxProtocolIEs >>;
	static constexpr const char* name() {return "ProtocolIE-ID";}
	using parent_t = asn::integer<>;

};

/*
TriggeringMessage	::= ENUMERATED { initiating-message, successful-outcome, unsuccessful-outcome}
*/

struct TriggeringMessage : asn::enumerated<3, 0, false>
{
	static constexpr const char* name() {return "TriggeringMessage";}
	using parent_t = asn::enumerated<3, 0, false>;
	typedef enum {
		initiating_message
		,successful_outcome
		,unsuccessful_outcome
	} index_t;

};

/*
maxProtocolExtensions 							INTEGER ::= 65535
*/

constexpr int64_t maxProtocolExtensions = 65535;
