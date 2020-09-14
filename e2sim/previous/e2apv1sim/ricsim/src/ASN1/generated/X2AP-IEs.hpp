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

#include "X2AP-Constants.hpp"
#include "X2AP-CommonDataTypes.hpp"
#include "X2AP-Containers.hpp"

/*
DL-ABS-status::= INTEGER (0..100)
*/

struct DL_ABS_status : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 100>>;
	static constexpr const char* name() {return "DL-ABS-status";}
	using parent_t = asn::integer<>;

};

/*
UsableABSInformationFDD-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct UsableABSInformationFDD_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
UsableABSInformationFDD ::= SEQUENCE {
	usable-abs-pattern-info				BIT STRING (SIZE(40)),
	iE-Extensions						ProtocolExtensionContainer { {UsableABSInformationFDD-ExtIEs} } OPTIONAL,
	...
}
*/

struct UsableABSInformationFDD : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "UsableABSInformationFDD";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct usable_abs_pattern_info_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<40>>;
		static constexpr const char* name() {return "usable_abs_pattern_info_t";}
		using parent_t = asn::bstring<>;

	};

	usable_abs_pattern_info_t& ref_usable_abs_pattern_info() {return usable_abs_pattern_info;}
	usable_abs_pattern_info_t const& ref_usable_abs_pattern_info() const {return usable_abs_pattern_info;}
	struct iE_Extensions_t : ProtocolExtensionContainer<UsableABSInformationFDD_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<UsableABSInformationFDD_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(usable_abs_pattern_info);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(usable_abs_pattern_info);
		v(iE_Extensions);

	};
	void clear()
	{
		usable_abs_pattern_info.clear();
		iE_Extensions.clear();

	};
	private:
	usable_abs_pattern_info_t	usable_abs_pattern_info;
	iE_Extensions_t	iE_Extensions;

};
/*
UsableABSInformationTDD-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct UsableABSInformationTDD_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
UsableABSInformationTDD ::= SEQUENCE {
	usaable-abs-pattern-info			BIT STRING (SIZE(1..70, ...)),
	iE-Extensions						ProtocolExtensionContainer { {UsableABSInformationTDD-ExtIEs} } OPTIONAL,
	...
}
*/

struct UsableABSInformationTDD : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "UsableABSInformationTDD";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct usaable_abs_pattern_info_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 70>>;
		static constexpr const char* name() {return "usaable_abs_pattern_info_t";}
		using parent_t = asn::bstring<>;

	};

	usaable_abs_pattern_info_t& ref_usaable_abs_pattern_info() {return usaable_abs_pattern_info;}
	usaable_abs_pattern_info_t const& ref_usaable_abs_pattern_info() const {return usaable_abs_pattern_info;}
	struct iE_Extensions_t : ProtocolExtensionContainer<UsableABSInformationTDD_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<UsableABSInformationTDD_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(usaable_abs_pattern_info);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(usaable_abs_pattern_info);
		v(iE_Extensions);

	};
	void clear()
	{
		usaable_abs_pattern_info.clear();
		iE_Extensions.clear();

	};
	private:
	usaable_abs_pattern_info_t	usaable_abs_pattern_info;
	iE_Extensions_t	iE_Extensions;

};
/*
UsableABSInformation ::= CHOICE {
	fdd					UsableABSInformationFDD,
	tdd					UsableABSInformationTDD,
	...
}
*/

struct UsableABSInformation : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "UsableABSInformation";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~UsableABSInformation() {clear();}
	struct fdd_t : UsableABSInformationFDD
	{
		static constexpr const char* name() {return "fdd_t";}
		using parent_t = UsableABSInformationFDD;

	};
	struct tdd_t : UsableABSInformationTDD
	{
		static constexpr const char* name() {return "tdd_t";}
		using parent_t = UsableABSInformationTDD;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<fdd_t>(); break;
		case 2: var.destroy<tdd_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<fdd_t>());
		case 2: set_index(2); return v(var.build<tdd_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<fdd_t>());
		case 2: return v(var.as<tdd_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<fdd_t>(1);
		v.template operator()<tdd_t>(2);

	}
	fdd_t& select_fdd() { if(get_index() != 1) { clear(); set_index(1); return var.build<fdd_t>();} return var.as<fdd_t>();}
	fdd_t const* get_fdd() const { if(get_index() == 1) { return &var.as<fdd_t>();} return nullptr; }
	tdd_t& select_tdd() { if(get_index() != 2) { clear(); set_index(2); return var.build<tdd_t>();} return var.as<tdd_t>();}
	tdd_t const* get_tdd() const { if(get_index() == 2) { return &var.as<tdd_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(fdd_t)];
		char dummy2[sizeof(tdd_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
ABS-Status-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ABS_Status_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ABS-Status ::= SEQUENCE {
	dL-ABS-status								DL-ABS-status,
	usableABSInformation						UsableABSInformation,
	iE-Extensions								ProtocolExtensionContainer { {ABS-Status-ExtIEs} } OPTIONAL,
	...
}
*/

struct ABS_Status : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "ABS-Status";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct dL_ABS_status_t : DL_ABS_status
	{
		static constexpr const char* name() {return "dL_ABS_status_t";}
		using parent_t = DL_ABS_status;

	};
	dL_ABS_status_t& ref_dL_ABS_status() {return dL_ABS_status;}
	dL_ABS_status_t const& ref_dL_ABS_status() const {return dL_ABS_status;}
	struct usableABSInformation_t : UsableABSInformation
	{
		static constexpr const char* name() {return "usableABSInformation_t";}
		using parent_t = UsableABSInformation;

	};
	usableABSInformation_t& ref_usableABSInformation() {return usableABSInformation;}
	usableABSInformation_t const& ref_usableABSInformation() const {return usableABSInformation;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ABS_Status_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ABS_Status_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(dL_ABS_status);
		v(usableABSInformation);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(dL_ABS_status);
		v(usableABSInformation);
		v(iE_Extensions);

	};
	void clear()
	{
		dL_ABS_status.clear();
		usableABSInformation.clear();
		iE_Extensions.clear();

	};
	private:
	dL_ABS_status_t	dL_ABS_status;
	usableABSInformation_t	usableABSInformation;
	iE_Extensions_t	iE_Extensions;

};
/*
ABSInformationFDD-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ABSInformationFDD_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ABSInformationFDD ::= SEQUENCE {
	abs-pattern-info					BIT STRING (SIZE(40)),
	numberOfCellSpecificAntennaPorts	ENUMERATED {one, two, four, ...},
	measurement-subset					BIT STRING (SIZE(40)),
	iE-Extensions						ProtocolExtensionContainer { {ABSInformationFDD-ExtIEs} } OPTIONAL,
	...
}
*/

struct ABSInformationFDD : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "ABSInformationFDD";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct abs_pattern_info_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<40>>;
		static constexpr const char* name() {return "abs_pattern_info_t";}
		using parent_t = asn::bstring<>;

	};

	abs_pattern_info_t& ref_abs_pattern_info() {return abs_pattern_info;}
	abs_pattern_info_t const& ref_abs_pattern_info() const {return abs_pattern_info;}
	struct numberOfCellSpecificAntennaPorts_t : asn::enumerated<3, 0, true>
	{
		static constexpr const char* name() {return "numberOfCellSpecificAntennaPorts_t";}
		using parent_t = asn::enumerated<3, 0, true>;
		typedef enum {
			one
			,two
			,four
		} index_t;

	};

	numberOfCellSpecificAntennaPorts_t& ref_numberOfCellSpecificAntennaPorts() {return numberOfCellSpecificAntennaPorts;}
	numberOfCellSpecificAntennaPorts_t const& ref_numberOfCellSpecificAntennaPorts() const {return numberOfCellSpecificAntennaPorts;}
	struct measurement_subset_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<40>>;
		static constexpr const char* name() {return "measurement_subset_t";}
		using parent_t = asn::bstring<>;

	};

	measurement_subset_t& ref_measurement_subset() {return measurement_subset;}
	measurement_subset_t const& ref_measurement_subset() const {return measurement_subset;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ABSInformationFDD_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ABSInformationFDD_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(abs_pattern_info);
		v(numberOfCellSpecificAntennaPorts);
		v(measurement_subset);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(abs_pattern_info);
		v(numberOfCellSpecificAntennaPorts);
		v(measurement_subset);
		v(iE_Extensions);

	};
	void clear()
	{
		abs_pattern_info.clear();
		numberOfCellSpecificAntennaPorts.clear();
		measurement_subset.clear();
		iE_Extensions.clear();

	};
	private:
	abs_pattern_info_t	abs_pattern_info;
	numberOfCellSpecificAntennaPorts_t	numberOfCellSpecificAntennaPorts;
	measurement_subset_t	measurement_subset;
	iE_Extensions_t	iE_Extensions;

};
/*
ABSInformationTDD-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ABSInformationTDD_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ABSInformationTDD ::= SEQUENCE {
	abs-pattern-info					BIT STRING (SIZE(1..70, ...)),
	numberOfCellSpecificAntennaPorts	ENUMERATED {one, two, four, ...},
	measurement-subset					BIT STRING (SIZE(1..70, ...)),
	iE-Extensions						ProtocolExtensionContainer { {ABSInformationTDD-ExtIEs} } OPTIONAL,
	...
}
*/

struct ABSInformationTDD : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "ABSInformationTDD";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct abs_pattern_info_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 70>>;
		static constexpr const char* name() {return "abs_pattern_info_t";}
		using parent_t = asn::bstring<>;

	};

	abs_pattern_info_t& ref_abs_pattern_info() {return abs_pattern_info;}
	abs_pattern_info_t const& ref_abs_pattern_info() const {return abs_pattern_info;}
	struct numberOfCellSpecificAntennaPorts_t : asn::enumerated<3, 0, true>
	{
		static constexpr const char* name() {return "numberOfCellSpecificAntennaPorts_t";}
		using parent_t = asn::enumerated<3, 0, true>;
		typedef enum {
			one
			,two
			,four
		} index_t;

	};

	numberOfCellSpecificAntennaPorts_t& ref_numberOfCellSpecificAntennaPorts() {return numberOfCellSpecificAntennaPorts;}
	numberOfCellSpecificAntennaPorts_t const& ref_numberOfCellSpecificAntennaPorts() const {return numberOfCellSpecificAntennaPorts;}
	struct measurement_subset_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 70>>;
		static constexpr const char* name() {return "measurement_subset_t";}
		using parent_t = asn::bstring<>;

	};

	measurement_subset_t& ref_measurement_subset() {return measurement_subset;}
	measurement_subset_t const& ref_measurement_subset() const {return measurement_subset;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ABSInformationTDD_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ABSInformationTDD_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(abs_pattern_info);
		v(numberOfCellSpecificAntennaPorts);
		v(measurement_subset);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(abs_pattern_info);
		v(numberOfCellSpecificAntennaPorts);
		v(measurement_subset);
		v(iE_Extensions);

	};
	void clear()
	{
		abs_pattern_info.clear();
		numberOfCellSpecificAntennaPorts.clear();
		measurement_subset.clear();
		iE_Extensions.clear();

	};
	private:
	abs_pattern_info_t	abs_pattern_info;
	numberOfCellSpecificAntennaPorts_t	numberOfCellSpecificAntennaPorts;
	measurement_subset_t	measurement_subset;
	iE_Extensions_t	iE_Extensions;

};
/*
ABSInformation ::= CHOICE {
	fdd					ABSInformationFDD,
	tdd					ABSInformationTDD,
	abs-inactive		NULL,
	...
}
*/

struct ABSInformation : asn::choice<3, 0, true>
{
	static constexpr const char* name() {return "ABSInformation";}
	using parent_t = asn::choice<3, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 4;}
	void set_unknown() { set_index(4);  }
	~ABSInformation() {clear();}
	struct fdd_t : ABSInformationFDD
	{
		static constexpr const char* name() {return "fdd_t";}
		using parent_t = ABSInformationFDD;

	};
	struct tdd_t : ABSInformationTDD
	{
		static constexpr const char* name() {return "tdd_t";}
		using parent_t = ABSInformationTDD;

	};
	struct abs_inactive_t : asn::nulltype
	{
		static constexpr const char* name() {return "abs_inactive_t";}
		using parent_t = asn::nulltype;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<fdd_t>(); break;
		case 2: var.destroy<tdd_t>(); break;
		case 3: var.destroy<abs_inactive_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<fdd_t>());
		case 2: set_index(2); return v(var.build<tdd_t>());
		case 3: set_index(3); return v(var.build<abs_inactive_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<fdd_t>());
		case 2: return v(var.as<tdd_t>());
		case 3: return v(var.as<abs_inactive_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<fdd_t>(1);
		v.template operator()<tdd_t>(2);
		v.template operator()<abs_inactive_t>(3);

	}
	fdd_t& select_fdd() { if(get_index() != 1) { clear(); set_index(1); return var.build<fdd_t>();} return var.as<fdd_t>();}
	fdd_t const* get_fdd() const { if(get_index() == 1) { return &var.as<fdd_t>();} return nullptr; }
	tdd_t& select_tdd() { if(get_index() != 2) { clear(); set_index(2); return var.build<tdd_t>();} return var.as<tdd_t>();}
	tdd_t const* get_tdd() const { if(get_index() == 2) { return &var.as<tdd_t>();} return nullptr; }
	abs_inactive_t& select_abs_inactive() { if(get_index() != 3) { clear(); set_index(3); return var.build<abs_inactive_t>();} return var.as<abs_inactive_t>();}
	abs_inactive_t const* get_abs_inactive() const { if(get_index() == 3) { return &var.as<abs_inactive_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(fdd_t)];
		char dummy2[sizeof(tdd_t)];
		char dummy3[sizeof(abs_inactive_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
Key-eNodeB-Star ::= BIT STRING (SIZE(256))
*/

struct Key_eNodeB_Star : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<256>>;
	static constexpr const char* name() {return "Key-eNodeB-Star";}
	using parent_t = asn::bstring<>;

};

/*
NextHopChainingCount ::= INTEGER (0..7)
*/

struct NextHopChainingCount : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 7>>;
	static constexpr const char* name() {return "NextHopChainingCount";}
	using parent_t = asn::integer<>;

};

/*
AS-SecurityInformation-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct AS_SecurityInformation_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
AS-SecurityInformation ::= SEQUENCE {
	key-eNodeB-star		Key-eNodeB-Star,
	nextHopChainingCount			NextHopChainingCount,
	iE-Extensions						ProtocolExtensionContainer { {AS-SecurityInformation-ExtIEs} } OPTIONAL,
	...
}
*/

struct AS_SecurityInformation : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "AS-SecurityInformation";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct key_eNodeB_star_t : Key_eNodeB_Star
	{
		static constexpr const char* name() {return "key_eNodeB_star_t";}
		using parent_t = Key_eNodeB_Star;

	};
	key_eNodeB_star_t& ref_key_eNodeB_star() {return key_eNodeB_star;}
	key_eNodeB_star_t const& ref_key_eNodeB_star() const {return key_eNodeB_star;}
	struct nextHopChainingCount_t : NextHopChainingCount
	{
		static constexpr const char* name() {return "nextHopChainingCount_t";}
		using parent_t = NextHopChainingCount;

	};
	nextHopChainingCount_t& ref_nextHopChainingCount() {return nextHopChainingCount;}
	nextHopChainingCount_t const& ref_nextHopChainingCount() const {return nextHopChainingCount;}
	struct iE_Extensions_t : ProtocolExtensionContainer<AS_SecurityInformation_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<AS_SecurityInformation_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(key_eNodeB_star);
		v(nextHopChainingCount);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(key_eNodeB_star);
		v(nextHopChainingCount);
		v(iE_Extensions);

	};
	void clear()
	{
		key_eNodeB_star.clear();
		nextHopChainingCount.clear();
		iE_Extensions.clear();

	};
	private:
	key_eNodeB_star_t	key_eNodeB_star;
	nextHopChainingCount_t	nextHopChainingCount;
	iE_Extensions_t	iE_Extensions;

};
/*
ActivationID ::= INTEGER (0..255)
*/

struct ActivationID : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 255>>;
	static constexpr const char* name() {return "ActivationID";}
	using parent_t = asn::integer<>;

};

/*
AdditionalSpecialSubframePatterns ::= ENUMERATED {
	ssp0,
	ssp1,
	ssp2,
	ssp3,
	ssp4,
	ssp5,
	ssp6,
	ssp7,
	ssp8,
	ssp9,
	...
}
*/

struct AdditionalSpecialSubframePatterns : asn::enumerated<10, 0, true>
{
	static constexpr const char* name() {return "AdditionalSpecialSubframePatterns";}
	using parent_t = asn::enumerated<10, 0, true>;
	typedef enum {
		ssp0
		,ssp1
		,ssp2
		,ssp3
		,ssp4
		,ssp5
		,ssp6
		,ssp7
		,ssp8
		,ssp9
	} index_t;

};

/*
CyclicPrefixDL ::= ENUMERATED {
	normal,
	extended,
	...
}
*/

struct CyclicPrefixDL : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "CyclicPrefixDL";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		normal
		,extended
	} index_t;

};

/*
CyclicPrefixUL ::= ENUMERATED {
	normal,
	extended,
	...
}
*/

struct CyclicPrefixUL : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "CyclicPrefixUL";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		normal
		,extended
	} index_t;

};

/*
AdditionalSpecialSubframe-Info-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct AdditionalSpecialSubframe_Info_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
AdditionalSpecialSubframe-Info ::=		SEQUENCE {
	additionalspecialSubframePatterns		AdditionalSpecialSubframePatterns,
	cyclicPrefixDL							CyclicPrefixDL,
	cyclicPrefixUL							CyclicPrefixUL,
	iE-Extensions							ProtocolExtensionContainer { {AdditionalSpecialSubframe-Info-ExtIEs} } OPTIONAL,
	...
}
*/

struct AdditionalSpecialSubframe_Info : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "AdditionalSpecialSubframe-Info";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct additionalspecialSubframePatterns_t : AdditionalSpecialSubframePatterns
	{
		static constexpr const char* name() {return "additionalspecialSubframePatterns_t";}
		using parent_t = AdditionalSpecialSubframePatterns;

	};
	additionalspecialSubframePatterns_t& ref_additionalspecialSubframePatterns() {return additionalspecialSubframePatterns;}
	additionalspecialSubframePatterns_t const& ref_additionalspecialSubframePatterns() const {return additionalspecialSubframePatterns;}
	struct cyclicPrefixDL_t : CyclicPrefixDL
	{
		static constexpr const char* name() {return "cyclicPrefixDL_t";}
		using parent_t = CyclicPrefixDL;

	};
	cyclicPrefixDL_t& ref_cyclicPrefixDL() {return cyclicPrefixDL;}
	cyclicPrefixDL_t const& ref_cyclicPrefixDL() const {return cyclicPrefixDL;}
	struct cyclicPrefixUL_t : CyclicPrefixUL
	{
		static constexpr const char* name() {return "cyclicPrefixUL_t";}
		using parent_t = CyclicPrefixUL;

	};
	cyclicPrefixUL_t& ref_cyclicPrefixUL() {return cyclicPrefixUL;}
	cyclicPrefixUL_t const& ref_cyclicPrefixUL() const {return cyclicPrefixUL;}
	struct iE_Extensions_t : ProtocolExtensionContainer<AdditionalSpecialSubframe_Info_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<AdditionalSpecialSubframe_Info_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(additionalspecialSubframePatterns);
		v(cyclicPrefixDL);
		v(cyclicPrefixUL);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(additionalspecialSubframePatterns);
		v(cyclicPrefixDL);
		v(cyclicPrefixUL);
		v(iE_Extensions);

	};
	void clear()
	{
		additionalspecialSubframePatterns.clear();
		cyclicPrefixDL.clear();
		cyclicPrefixUL.clear();
		iE_Extensions.clear();

	};
	private:
	additionalspecialSubframePatterns_t	additionalspecialSubframePatterns;
	cyclicPrefixDL_t	cyclicPrefixDL;
	cyclicPrefixUL_t	cyclicPrefixUL;
	iE_Extensions_t	iE_Extensions;

};
/*
AdditionalSpecialSubframePatternsExtension ::= ENUMERATED {
	ssp10,
	...
}
*/

struct AdditionalSpecialSubframePatternsExtension : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "AdditionalSpecialSubframePatternsExtension";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		ssp10
	} index_t;

};

/*
AdditionalSpecialSubframeExtension-Info-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct AdditionalSpecialSubframeExtension_Info_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
AdditionalSpecialSubframeExtension-Info ::=		SEQUENCE {
	additionalspecialSubframePatternsExtension	AdditionalSpecialSubframePatternsExtension,
	cyclicPrefixDL								CyclicPrefixDL,
	cyclicPrefixUL								CyclicPrefixUL,
	iE-Extensions								ProtocolExtensionContainer { {AdditionalSpecialSubframeExtension-Info-ExtIEs} } OPTIONAL,
	...
}
*/

struct AdditionalSpecialSubframeExtension_Info : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "AdditionalSpecialSubframeExtension-Info";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct additionalspecialSubframePatternsExtension_t : AdditionalSpecialSubframePatternsExtension
	{
		static constexpr const char* name() {return "additionalspecialSubframePatternsExtension_t";}
		using parent_t = AdditionalSpecialSubframePatternsExtension;

	};
	additionalspecialSubframePatternsExtension_t& ref_additionalspecialSubframePatternsExtension() {return additionalspecialSubframePatternsExtension;}
	additionalspecialSubframePatternsExtension_t const& ref_additionalspecialSubframePatternsExtension() const {return additionalspecialSubframePatternsExtension;}
	struct cyclicPrefixDL_t : CyclicPrefixDL
	{
		static constexpr const char* name() {return "cyclicPrefixDL_t";}
		using parent_t = CyclicPrefixDL;

	};
	cyclicPrefixDL_t& ref_cyclicPrefixDL() {return cyclicPrefixDL;}
	cyclicPrefixDL_t const& ref_cyclicPrefixDL() const {return cyclicPrefixDL;}
	struct cyclicPrefixUL_t : CyclicPrefixUL
	{
		static constexpr const char* name() {return "cyclicPrefixUL_t";}
		using parent_t = CyclicPrefixUL;

	};
	cyclicPrefixUL_t& ref_cyclicPrefixUL() {return cyclicPrefixUL;}
	cyclicPrefixUL_t const& ref_cyclicPrefixUL() const {return cyclicPrefixUL;}
	struct iE_Extensions_t : ProtocolExtensionContainer<AdditionalSpecialSubframeExtension_Info_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<AdditionalSpecialSubframeExtension_Info_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(additionalspecialSubframePatternsExtension);
		v(cyclicPrefixDL);
		v(cyclicPrefixUL);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(additionalspecialSubframePatternsExtension);
		v(cyclicPrefixDL);
		v(cyclicPrefixUL);
		v(iE_Extensions);

	};
	void clear()
	{
		additionalspecialSubframePatternsExtension.clear();
		cyclicPrefixDL.clear();
		cyclicPrefixUL.clear();
		iE_Extensions.clear();

	};
	private:
	additionalspecialSubframePatternsExtension_t	additionalspecialSubframePatternsExtension;
	cyclicPrefixDL_t	cyclicPrefixDL;
	cyclicPrefixUL_t	cyclicPrefixUL;
	iE_Extensions_t	iE_Extensions;

};
/*
AerialUEsubscriptionInformation ::= ENUMERATED {
	allowed,
	not-allowed,
	...
}
*/

struct AerialUEsubscriptionInformation : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "AerialUEsubscriptionInformation";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		allowed
		,not_allowed
	} index_t;

};

/*
PriorityLevel				::= INTEGER { spare (0), highest (1), lowest (14), no-priority (15) } (0..15)
*/

struct PriorityLevel : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 15>>;
	static constexpr const char* name() {return "PriorityLevel";}
	using parent_t = asn::integer<>;
	enum {spare = 0, highest = 1, lowest = 14, no_priority = 15};

};

/*
Pre-emptionCapability ::= ENUMERATED {
	shall-not-trigger-pre-emption,
	may-trigger-pre-emption
}
*/

struct Pre_emptionCapability : asn::enumerated<2, 0, false>
{
	static constexpr const char* name() {return "Pre-emptionCapability";}
	using parent_t = asn::enumerated<2, 0, false>;
	typedef enum {
		shall_not_trigger_pre_emption
		,may_trigger_pre_emption
	} index_t;

};

/*
Pre-emptionVulnerability ::= ENUMERATED {
	not-pre-emptable,
	pre-emptable
}
*/

struct Pre_emptionVulnerability : asn::enumerated<2, 0, false>
{
	static constexpr const char* name() {return "Pre-emptionVulnerability";}
	using parent_t = asn::enumerated<2, 0, false>;
	typedef enum {
		not_pre_emptable
		,pre_emptable
	} index_t;

};

/*
AllocationAndRetentionPriority-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct AllocationAndRetentionPriority_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
AllocationAndRetentionPriority ::= SEQUENCE {
	priorityLevel				PriorityLevel,
	pre-emptionCapability		Pre-emptionCapability,
	pre-emptionVulnerability	Pre-emptionVulnerability,
	iE-Extensions				ProtocolExtensionContainer { {AllocationAndRetentionPriority-ExtIEs} } OPTIONAL,
	...
}
*/

struct AllocationAndRetentionPriority : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "AllocationAndRetentionPriority";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct priorityLevel_t : PriorityLevel
	{
		static constexpr const char* name() {return "priorityLevel_t";}
		using parent_t = PriorityLevel;

	};
	priorityLevel_t& ref_priorityLevel() {return priorityLevel;}
	priorityLevel_t const& ref_priorityLevel() const {return priorityLevel;}
	struct pre_emptionCapability_t : Pre_emptionCapability
	{
		static constexpr const char* name() {return "pre_emptionCapability_t";}
		using parent_t = Pre_emptionCapability;

	};
	pre_emptionCapability_t& ref_pre_emptionCapability() {return pre_emptionCapability;}
	pre_emptionCapability_t const& ref_pre_emptionCapability() const {return pre_emptionCapability;}
	struct pre_emptionVulnerability_t : Pre_emptionVulnerability
	{
		static constexpr const char* name() {return "pre_emptionVulnerability_t";}
		using parent_t = Pre_emptionVulnerability;

	};
	pre_emptionVulnerability_t& ref_pre_emptionVulnerability() {return pre_emptionVulnerability;}
	pre_emptionVulnerability_t const& ref_pre_emptionVulnerability() const {return pre_emptionVulnerability;}
	struct iE_Extensions_t : ProtocolExtensionContainer<AllocationAndRetentionPriority_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<AllocationAndRetentionPriority_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(priorityLevel);
		v(pre_emptionCapability);
		v(pre_emptionVulnerability);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(priorityLevel);
		v(pre_emptionCapability);
		v(pre_emptionVulnerability);
		v(iE_Extensions);

	};
	void clear()
	{
		priorityLevel.clear();
		pre_emptionCapability.clear();
		pre_emptionVulnerability.clear();
		iE_Extensions.clear();

	};
	private:
	priorityLevel_t	priorityLevel;
	pre_emptionCapability_t	pre_emptionCapability;
	pre_emptionVulnerability_t	pre_emptionVulnerability;
	iE_Extensions_t	iE_Extensions;

};
/*
PLMN-Identity ::= OCTET STRING (SIZE(3))
*/

struct PLMN_Identity : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<3>>;
	static constexpr const char* name() {return "PLMN-Identity";}
	using parent_t = asn::ostring<>;

};

/*
EUTRANCellIdentifier ::= BIT STRING (SIZE (28))
*/

struct EUTRANCellIdentifier : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<28>>;
	static constexpr const char* name() {return "EUTRANCellIdentifier";}
	using parent_t = asn::bstring<>;

};

/*
ECGI-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ECGI_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ECGI ::= SEQUENCE {
	pLMN-Identity				PLMN-Identity,
	eUTRANcellIdentifier		EUTRANCellIdentifier,
	iE-Extensions				ProtocolExtensionContainer { {ECGI-ExtIEs} } OPTIONAL,
	...
}
*/

struct ECGI : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "ECGI";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pLMN_Identity_t : PLMN_Identity
	{
		static constexpr const char* name() {return "pLMN_Identity_t";}
		using parent_t = PLMN_Identity;

	};
	pLMN_Identity_t& ref_pLMN_Identity() {return pLMN_Identity;}
	pLMN_Identity_t const& ref_pLMN_Identity() const {return pLMN_Identity;}
	struct eUTRANcellIdentifier_t : EUTRANCellIdentifier
	{
		static constexpr const char* name() {return "eUTRANcellIdentifier_t";}
		using parent_t = EUTRANCellIdentifier;

	};
	eUTRANcellIdentifier_t& ref_eUTRANcellIdentifier() {return eUTRANcellIdentifier;}
	eUTRANcellIdentifier_t const& ref_eUTRANcellIdentifier() const {return eUTRANcellIdentifier;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ECGI_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ECGI_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pLMN_Identity);
		v(eUTRANcellIdentifier);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pLMN_Identity);
		v(eUTRANcellIdentifier);
		v(iE_Extensions);

	};
	void clear()
	{
		pLMN_Identity.clear();
		eUTRANcellIdentifier.clear();
		iE_Extensions.clear();

	};
	private:
	pLMN_Identity_t	pLMN_Identity;
	eUTRANcellIdentifier_t	eUTRANcellIdentifier;
	iE_Extensions_t	iE_Extensions;

};
/*
CellIdListforMDT ::= SEQUENCE (SIZE(1..maxnoofCellIDforMDT)) OF ECGI
*/

struct CellIdListforMDT_elm : ECGI
{
	static constexpr const char* name() {return "CellIdListforMDT_elm";}
	using parent_t = ECGI;

};
struct CellIdListforMDT : asn::sequenceof<CellIdListforMDT_elm>
{
	static constexpr const char* name() {return "CellIdListforMDT";}
	using parent_t = asn::sequenceof<CellIdListforMDT_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofCellIDforMDT >>;

};
/*
CellBasedMDT-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CellBasedMDT_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CellBasedMDT::= SEQUENCE {
	cellIdListforMDT	CellIdListforMDT,
	iE-Extensions		ProtocolExtensionContainer { {CellBasedMDT-ExtIEs} } OPTIONAL,
	...
}
*/

struct CellBasedMDT : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "CellBasedMDT";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct cellIdListforMDT_t : CellIdListforMDT
	{
		static constexpr const char* name() {return "cellIdListforMDT_t";}
		using parent_t = CellIdListforMDT;

	};
	cellIdListforMDT_t& ref_cellIdListforMDT() {return cellIdListforMDT;}
	cellIdListforMDT_t const& ref_cellIdListforMDT() const {return cellIdListforMDT;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CellBasedMDT_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CellBasedMDT_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(cellIdListforMDT);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(cellIdListforMDT);
		v(iE_Extensions);

	};
	void clear()
	{
		cellIdListforMDT.clear();
		iE_Extensions.clear();

	};
	private:
	cellIdListforMDT_t	cellIdListforMDT;
	iE_Extensions_t	iE_Extensions;

};
/*
TAC ::= OCTET STRING (SIZE (2))
*/

struct TAC : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<2>>;
	static constexpr const char* name() {return "TAC";}
	using parent_t = asn::ostring<>;

};

/*
TAListforMDT ::= SEQUENCE (SIZE(1..maxnoofTAforMDT)) OF TAC
*/

struct TAListforMDT_elm : TAC
{
	static constexpr const char* name() {return "TAListforMDT_elm";}
	using parent_t = TAC;

};
struct TAListforMDT : asn::sequenceof<TAListforMDT_elm>
{
	static constexpr const char* name() {return "TAListforMDT";}
	using parent_t = asn::sequenceof<TAListforMDT_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofTAforMDT >>;

};
/*
TABasedMDT-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct TABasedMDT_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
TABasedMDT::= SEQUENCE {
	tAListforMDT		TAListforMDT,
	iE-Extensions		ProtocolExtensionContainer { {TABasedMDT-ExtIEs} } OPTIONAL,
	...
}
*/

struct TABasedMDT : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "TABasedMDT";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct tAListforMDT_t : TAListforMDT
	{
		static constexpr const char* name() {return "tAListforMDT_t";}
		using parent_t = TAListforMDT;

	};
	tAListforMDT_t& ref_tAListforMDT() {return tAListforMDT;}
	tAListforMDT_t const& ref_tAListforMDT() const {return tAListforMDT;}
	struct iE_Extensions_t : ProtocolExtensionContainer<TABasedMDT_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<TABasedMDT_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(tAListforMDT);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(tAListforMDT);
		v(iE_Extensions);

	};
	void clear()
	{
		tAListforMDT.clear();
		iE_Extensions.clear();

	};
	private:
	tAListforMDT_t	tAListforMDT;
	iE_Extensions_t	iE_Extensions;

};
/*
TAI-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct TAI_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
TAI-Item ::= SEQUENCE {
	tAC					TAC,
	pLMN-Identity		PLMN-Identity,
	iE-Extensions		ProtocolExtensionContainer { {TAI-Item-ExtIEs} } OPTIONAL,
	...
}
*/

struct TAI_Item : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "TAI-Item";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct tAC_t : TAC
	{
		static constexpr const char* name() {return "tAC_t";}
		using parent_t = TAC;

	};
	tAC_t& ref_tAC() {return tAC;}
	tAC_t const& ref_tAC() const {return tAC;}
	struct pLMN_Identity_t : PLMN_Identity
	{
		static constexpr const char* name() {return "pLMN_Identity_t";}
		using parent_t = PLMN_Identity;

	};
	pLMN_Identity_t& ref_pLMN_Identity() {return pLMN_Identity;}
	pLMN_Identity_t const& ref_pLMN_Identity() const {return pLMN_Identity;}
	struct iE_Extensions_t : ProtocolExtensionContainer<TAI_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<TAI_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(tAC);
		v(pLMN_Identity);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(tAC);
		v(pLMN_Identity);
		v(iE_Extensions);

	};
	void clear()
	{
		tAC.clear();
		pLMN_Identity.clear();
		iE_Extensions.clear();

	};
	private:
	tAC_t	tAC;
	pLMN_Identity_t	pLMN_Identity;
	iE_Extensions_t	iE_Extensions;

};
/*
TAIListforMDT ::= SEQUENCE (SIZE(1..maxnoofTAforMDT)) OF TAI-Item
*/

struct TAIListforMDT_elm : TAI_Item
{
	static constexpr const char* name() {return "TAIListforMDT_elm";}
	using parent_t = TAI_Item;

};
struct TAIListforMDT : asn::sequenceof<TAIListforMDT_elm>
{
	static constexpr const char* name() {return "TAIListforMDT";}
	using parent_t = asn::sequenceof<TAIListforMDT_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofTAforMDT >>;

};
/*
TAIBasedMDT-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct TAIBasedMDT_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
TAIBasedMDT ::= SEQUENCE {
	tAIListforMDT			TAIListforMDT,
	iE-Extensions			ProtocolExtensionContainer { {TAIBasedMDT-ExtIEs} } OPTIONAL,
	...
}
*/

struct TAIBasedMDT : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "TAIBasedMDT";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct tAIListforMDT_t : TAIListforMDT
	{
		static constexpr const char* name() {return "tAIListforMDT_t";}
		using parent_t = TAIListforMDT;

	};
	tAIListforMDT_t& ref_tAIListforMDT() {return tAIListforMDT;}
	tAIListforMDT_t const& ref_tAIListforMDT() const {return tAIListforMDT;}
	struct iE_Extensions_t : ProtocolExtensionContainer<TAIBasedMDT_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<TAIBasedMDT_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(tAIListforMDT);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(tAIListforMDT);
		v(iE_Extensions);

	};
	void clear()
	{
		tAIListforMDT.clear();
		iE_Extensions.clear();

	};
	private:
	tAIListforMDT_t	tAIListforMDT;
	iE_Extensions_t	iE_Extensions;

};
/*
AreaScopeOfMDT ::= CHOICE {
	cellBased					CellBasedMDT,
	tABased						TABasedMDT,
	pLMNWide					NULL,
	...,
	tAIBased					TAIBasedMDT
}
*/

struct AreaScopeOfMDT : asn::choice<4, 1, true>
{
	static constexpr const char* name() {return "AreaScopeOfMDT";}
	using parent_t = asn::choice<4, 1, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 5;}
	void set_unknown() { set_index(5);  }
	~AreaScopeOfMDT() {clear();}
	struct cellBased_t : CellBasedMDT
	{
		static constexpr const char* name() {return "cellBased_t";}
		using parent_t = CellBasedMDT;

	};
	struct tABased_t : TABasedMDT
	{
		static constexpr const char* name() {return "tABased_t";}
		using parent_t = TABasedMDT;

	};
	struct pLMNWide_t : asn::nulltype
	{
		static constexpr const char* name() {return "pLMNWide_t";}
		using parent_t = asn::nulltype;

	};
	struct tAIBased_t : TAIBasedMDT
	{
		static constexpr const char* name() {return "tAIBased_t";}
		using parent_t = TAIBasedMDT;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<cellBased_t>(); break;
		case 2: var.destroy<tABased_t>(); break;
		case 3: var.destroy<pLMNWide_t>(); break;
		case 4: var.destroy<tAIBased_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<cellBased_t>());
		case 2: set_index(2); return v(var.build<tABased_t>());
		case 3: set_index(3); return v(var.build<pLMNWide_t>());
		case 4: set_index(4); return v(var.build<tAIBased_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<cellBased_t>());
		case 2: return v(var.as<tABased_t>());
		case 3: return v(var.as<pLMNWide_t>());
		case 4: return v(var.as<tAIBased_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<cellBased_t>(1);
		v.template operator()<tABased_t>(2);
		v.template operator()<pLMNWide_t>(3);
		v.template operator()<tAIBased_t>(4);

	}
	cellBased_t& select_cellBased() { if(get_index() != 1) { clear(); set_index(1); return var.build<cellBased_t>();} return var.as<cellBased_t>();}
	cellBased_t const* get_cellBased() const { if(get_index() == 1) { return &var.as<cellBased_t>();} return nullptr; }
	tABased_t& select_tABased() { if(get_index() != 2) { clear(); set_index(2); return var.build<tABased_t>();} return var.as<tABased_t>();}
	tABased_t const* get_tABased() const { if(get_index() == 2) { return &var.as<tABased_t>();} return nullptr; }
	pLMNWide_t& select_pLMNWide() { if(get_index() != 3) { clear(); set_index(3); return var.build<pLMNWide_t>();} return var.as<pLMNWide_t>();}
	pLMNWide_t const* get_pLMNWide() const { if(get_index() == 3) { return &var.as<pLMNWide_t>();} return nullptr; }
	tAIBased_t& select_tAIBased() { if(get_index() != 4) { clear(); set_index(4); return var.build<tAIBased_t>();} return var.as<tAIBased_t>();}
	tAIBased_t const* get_tAIBased() const { if(get_index() == 4) { return &var.as<tAIBased_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(cellBased_t)];
		char dummy2[sizeof(tABased_t)];
		char dummy3[sizeof(pLMNWide_t)];
		char dummy4[sizeof(tAIBased_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
CellIdListforQMC ::= SEQUENCE (SIZE(1..maxnoofCellIDforQMC)) OF ECGI
*/

struct CellIdListforQMC_elm : ECGI
{
	static constexpr const char* name() {return "CellIdListforQMC_elm";}
	using parent_t = ECGI;

};
struct CellIdListforQMC : asn::sequenceof<CellIdListforQMC_elm>
{
	static constexpr const char* name() {return "CellIdListforQMC";}
	using parent_t = asn::sequenceof<CellIdListforQMC_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofCellIDforQMC >>;

};
/*
CellBasedQMC-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CellBasedQMC_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CellBasedQMC::= SEQUENCE {
	cellIdListforQMC		CellIdListforQMC,
	iE-Extensions		ProtocolExtensionContainer { {CellBasedQMC-ExtIEs} } OPTIONAL,
	...
}
*/

struct CellBasedQMC : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "CellBasedQMC";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct cellIdListforQMC_t : CellIdListforQMC
	{
		static constexpr const char* name() {return "cellIdListforQMC_t";}
		using parent_t = CellIdListforQMC;

	};
	cellIdListforQMC_t& ref_cellIdListforQMC() {return cellIdListforQMC;}
	cellIdListforQMC_t const& ref_cellIdListforQMC() const {return cellIdListforQMC;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CellBasedQMC_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CellBasedQMC_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(cellIdListforQMC);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(cellIdListforQMC);
		v(iE_Extensions);

	};
	void clear()
	{
		cellIdListforQMC.clear();
		iE_Extensions.clear();

	};
	private:
	cellIdListforQMC_t	cellIdListforQMC;
	iE_Extensions_t	iE_Extensions;

};
/*
TAListforQMC ::= SEQUENCE (SIZE(1..maxnoofTAforQMC)) OF TAC
*/

struct TAListforQMC_elm : TAC
{
	static constexpr const char* name() {return "TAListforQMC_elm";}
	using parent_t = TAC;

};
struct TAListforQMC : asn::sequenceof<TAListforQMC_elm>
{
	static constexpr const char* name() {return "TAListforQMC";}
	using parent_t = asn::sequenceof<TAListforQMC_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofTAforQMC >>;

};
/*
TABasedQMC-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct TABasedQMC_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
TABasedQMC ::= SEQUENCE {
	tAListforQMC		TAListforQMC,
	iE-Extensions		ProtocolExtensionContainer { {TABasedQMC-ExtIEs} } OPTIONAL,
	...
}
*/

struct TABasedQMC : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "TABasedQMC";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct tAListforQMC_t : TAListforQMC
	{
		static constexpr const char* name() {return "tAListforQMC_t";}
		using parent_t = TAListforQMC;

	};
	tAListforQMC_t& ref_tAListforQMC() {return tAListforQMC;}
	tAListforQMC_t const& ref_tAListforQMC() const {return tAListforQMC;}
	struct iE_Extensions_t : ProtocolExtensionContainer<TABasedQMC_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<TABasedQMC_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(tAListforQMC);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(tAListforQMC);
		v(iE_Extensions);

	};
	void clear()
	{
		tAListforQMC.clear();
		iE_Extensions.clear();

	};
	private:
	tAListforQMC_t	tAListforQMC;
	iE_Extensions_t	iE_Extensions;

};
/*
TAIListforQMC ::= SEQUENCE (SIZE(1..maxnoofTAforQMC)) OF TAI-Item
*/

struct TAIListforQMC_elm : TAI_Item
{
	static constexpr const char* name() {return "TAIListforQMC_elm";}
	using parent_t = TAI_Item;

};
struct TAIListforQMC : asn::sequenceof<TAIListforQMC_elm>
{
	static constexpr const char* name() {return "TAIListforQMC";}
	using parent_t = asn::sequenceof<TAIListforQMC_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofTAforQMC >>;

};
/*
TAIBasedQMC-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct TAIBasedQMC_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
TAIBasedQMC ::= SEQUENCE {
	tAIListforQMC		TAIListforQMC,
	iE-Extensions		ProtocolExtensionContainer { {TAIBasedQMC-ExtIEs} } OPTIONAL,
	...
}
*/

struct TAIBasedQMC : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "TAIBasedQMC";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct tAIListforQMC_t : TAIListforQMC
	{
		static constexpr const char* name() {return "tAIListforQMC_t";}
		using parent_t = TAIListforQMC;

	};
	tAIListforQMC_t& ref_tAIListforQMC() {return tAIListforQMC;}
	tAIListforQMC_t const& ref_tAIListforQMC() const {return tAIListforQMC;}
	struct iE_Extensions_t : ProtocolExtensionContainer<TAIBasedQMC_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<TAIBasedQMC_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(tAIListforQMC);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(tAIListforQMC);
		v(iE_Extensions);

	};
	void clear()
	{
		tAIListforQMC.clear();
		iE_Extensions.clear();

	};
	private:
	tAIListforQMC_t	tAIListforQMC;
	iE_Extensions_t	iE_Extensions;

};
/*
PLMNListforQMC ::= SEQUENCE (SIZE(1..maxnoofPLMNforQMC)) OF PLMN-Identity
*/

struct PLMNListforQMC_elm : PLMN_Identity
{
	static constexpr const char* name() {return "PLMNListforQMC_elm";}
	using parent_t = PLMN_Identity;

};
struct PLMNListforQMC : asn::sequenceof<PLMNListforQMC_elm>
{
	static constexpr const char* name() {return "PLMNListforQMC";}
	using parent_t = asn::sequenceof<PLMNListforQMC_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofPLMNforQMC >>;

};
/*
PLMNAreaBasedQMC-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct PLMNAreaBasedQMC_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
PLMNAreaBasedQMC ::= SEQUENCE {
	plmnListforQMC		PLMNListforQMC,
	iE-Extensions		ProtocolExtensionContainer { {PLMNAreaBasedQMC-ExtIEs} } OPTIONAL,
	...
}
*/

struct PLMNAreaBasedQMC : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "PLMNAreaBasedQMC";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct plmnListforQMC_t : PLMNListforQMC
	{
		static constexpr const char* name() {return "plmnListforQMC_t";}
		using parent_t = PLMNListforQMC;

	};
	plmnListforQMC_t& ref_plmnListforQMC() {return plmnListforQMC;}
	plmnListforQMC_t const& ref_plmnListforQMC() const {return plmnListforQMC;}
	struct iE_Extensions_t : ProtocolExtensionContainer<PLMNAreaBasedQMC_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<PLMNAreaBasedQMC_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(plmnListforQMC);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(plmnListforQMC);
		v(iE_Extensions);

	};
	void clear()
	{
		plmnListforQMC.clear();
		iE_Extensions.clear();

	};
	private:
	plmnListforQMC_t	plmnListforQMC;
	iE_Extensions_t	iE_Extensions;

};
/*
AreaScopeOfQMC ::= CHOICE {
	cellBased					CellBasedQMC,
	tABased						TABasedQMC,
	tAIBased					TAIBasedQMC,
	pLMNAreaBased				PLMNAreaBasedQMC,
	...
}
*/

struct AreaScopeOfQMC : asn::choice<4, 0, true>
{
	static constexpr const char* name() {return "AreaScopeOfQMC";}
	using parent_t = asn::choice<4, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 5;}
	void set_unknown() { set_index(5);  }
	~AreaScopeOfQMC() {clear();}
	struct cellBased_t : CellBasedQMC
	{
		static constexpr const char* name() {return "cellBased_t";}
		using parent_t = CellBasedQMC;

	};
	struct tABased_t : TABasedQMC
	{
		static constexpr const char* name() {return "tABased_t";}
		using parent_t = TABasedQMC;

	};
	struct tAIBased_t : TAIBasedQMC
	{
		static constexpr const char* name() {return "tAIBased_t";}
		using parent_t = TAIBasedQMC;

	};
	struct pLMNAreaBased_t : PLMNAreaBasedQMC
	{
		static constexpr const char* name() {return "pLMNAreaBased_t";}
		using parent_t = PLMNAreaBasedQMC;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<cellBased_t>(); break;
		case 2: var.destroy<tABased_t>(); break;
		case 3: var.destroy<tAIBased_t>(); break;
		case 4: var.destroy<pLMNAreaBased_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<cellBased_t>());
		case 2: set_index(2); return v(var.build<tABased_t>());
		case 3: set_index(3); return v(var.build<tAIBased_t>());
		case 4: set_index(4); return v(var.build<pLMNAreaBased_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<cellBased_t>());
		case 2: return v(var.as<tABased_t>());
		case 3: return v(var.as<tAIBased_t>());
		case 4: return v(var.as<pLMNAreaBased_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<cellBased_t>(1);
		v.template operator()<tABased_t>(2);
		v.template operator()<tAIBased_t>(3);
		v.template operator()<pLMNAreaBased_t>(4);

	}
	cellBased_t& select_cellBased() { if(get_index() != 1) { clear(); set_index(1); return var.build<cellBased_t>();} return var.as<cellBased_t>();}
	cellBased_t const* get_cellBased() const { if(get_index() == 1) { return &var.as<cellBased_t>();} return nullptr; }
	tABased_t& select_tABased() { if(get_index() != 2) { clear(); set_index(2); return var.build<tABased_t>();} return var.as<tABased_t>();}
	tABased_t const* get_tABased() const { if(get_index() == 2) { return &var.as<tABased_t>();} return nullptr; }
	tAIBased_t& select_tAIBased() { if(get_index() != 3) { clear(); set_index(3); return var.build<tAIBased_t>();} return var.as<tAIBased_t>();}
	tAIBased_t const* get_tAIBased() const { if(get_index() == 3) { return &var.as<tAIBased_t>();} return nullptr; }
	pLMNAreaBased_t& select_pLMNAreaBased() { if(get_index() != 4) { clear(); set_index(4); return var.build<pLMNAreaBased_t>();} return var.as<pLMNAreaBased_t>();}
	pLMNAreaBased_t const* get_pLMNAreaBased() const { if(get_index() == 4) { return &var.as<pLMNAreaBased_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(cellBased_t)];
		char dummy2[sizeof(tABased_t)];
		char dummy3[sizeof(tAIBased_t)];
		char dummy4[sizeof(pLMNAreaBased_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
FreqBandIndicator ::= INTEGER (1..256, ...)
*/

struct FreqBandIndicator : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<1, 256>>;
	static constexpr const char* name() {return "FreqBandIndicator";}
	using parent_t = asn::integer<>;

};

/*
BandInfo-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct BandInfo_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
BandInfo	::= SEQUENCE {
	freqBandIndicator		FreqBandIndicator,
	iE-Extensions			ProtocolExtensionContainer { {BandInfo-ExtIEs} } 	OPTIONAL,
	...
}
*/

struct BandInfo : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "BandInfo";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct freqBandIndicator_t : FreqBandIndicator
	{
		static constexpr const char* name() {return "freqBandIndicator_t";}
		using parent_t = FreqBandIndicator;

	};
	freqBandIndicator_t& ref_freqBandIndicator() {return freqBandIndicator;}
	freqBandIndicator_t const& ref_freqBandIndicator() const {return freqBandIndicator;}
	struct iE_Extensions_t : ProtocolExtensionContainer<BandInfo_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<BandInfo_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(freqBandIndicator);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(freqBandIndicator);
		v(iE_Extensions);

	};
	void clear()
	{
		freqBandIndicator.clear();
		iE_Extensions.clear();

	};
	private:
	freqBandIndicator_t	freqBandIndicator;
	iE_Extensions_t	iE_Extensions;

};
/*
BandwidthReducedSI::= ENUMERATED {
	scheduled,
	...
}
*/

struct BandwidthReducedSI : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "BandwidthReducedSI";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		scheduled
	} index_t;

};

/*
BearerType ::= ENUMERATED {
	non-IP,
	...
}
*/

struct BearerType : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "BearerType";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		non_IP
	} index_t;

};

/*
BenefitMetric ::= INTEGER (-101..100, ...)
*/

struct BenefitMetric : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<-101, 100>>;
	static constexpr const char* name() {return "BenefitMetric";}
	using parent_t = asn::integer<>;

};

/*
BitRate ::= INTEGER (0..10000000000)
*/

struct BitRate : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 10000000000>>;
	static constexpr const char* name() {return "BitRate";}
	using parent_t = asn::integer<>;

};

/*
BluetoothMeasConfig::= ENUMERATED {setup,...}
*/

struct BluetoothMeasConfig : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "BluetoothMeasConfig";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		setup
	} index_t;

};

/*
BluetoothName ::= OCTET STRING (SIZE (1..248))
*/

struct BluetoothName : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::span<1, 248>>;
	static constexpr const char* name() {return "BluetoothName";}
	using parent_t = asn::ostring<>;

};

/*
BluetoothMeasConfigNameList ::= SEQUENCE (SIZE(1..maxnoofBluetoothName)) OF BluetoothName
*/

struct BluetoothMeasConfigNameList_elm : BluetoothName
{
	static constexpr const char* name() {return "BluetoothMeasConfigNameList_elm";}
	using parent_t = BluetoothName;

};
struct BluetoothMeasConfigNameList : asn::sequenceof<BluetoothMeasConfigNameList_elm>
{
	static constexpr const char* name() {return "BluetoothMeasConfigNameList";}
	using parent_t = asn::sequenceof<BluetoothMeasConfigNameList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBluetoothName >>;

};
/*
BluetoothMeasurementConfiguration-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct BluetoothMeasurementConfiguration_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
BluetoothMeasurementConfiguration ::= SEQUENCE {
	bluetoothMeasConfig				BluetoothMeasConfig,
	bluetoothMeasConfigNameList		BluetoothMeasConfigNameList			OPTIONAL,
	bt-rssi							ENUMERATED {true, ...}				OPTIONAL,
	iE-Extensions		ProtocolExtensionContainer { {BluetoothMeasurementConfiguration-ExtIEs} } OPTIONAL,
	...
}
*/

struct BluetoothMeasurementConfiguration : asn::sequence<4, 0, true, 3>
{
	static constexpr const char* name() {return "BluetoothMeasurementConfiguration";}
	using parent_t = asn::sequence<4, 0, true, 3>;
	struct bluetoothMeasConfig_t : BluetoothMeasConfig
	{
		static constexpr const char* name() {return "bluetoothMeasConfig_t";}
		using parent_t = BluetoothMeasConfig;

	};
	bluetoothMeasConfig_t& ref_bluetoothMeasConfig() {return bluetoothMeasConfig;}
	bluetoothMeasConfig_t const& ref_bluetoothMeasConfig() const {return bluetoothMeasConfig;}
	struct bluetoothMeasConfigNameList_t : BluetoothMeasConfigNameList
	{
		static constexpr const char* name() {return "bluetoothMeasConfigNameList_t";}
		using parent_t = BluetoothMeasConfigNameList;
		static constexpr bool optional = true;

	};
	bluetoothMeasConfigNameList_t& set_bluetoothMeasConfigNameList() { bluetoothMeasConfigNameList.setpresent(true); return bluetoothMeasConfigNameList;}
	bluetoothMeasConfigNameList_t const* get_bluetoothMeasConfigNameList() const {return bluetoothMeasConfigNameList.is_valid() ? &bluetoothMeasConfigNameList : nullptr;}
	struct bt_rssi_t : asn::enumerated<1, 0, true>
	{
		static constexpr const char* name() {return "bt_rssi_t";}
		using parent_t = asn::enumerated<1, 0, true>;
		static constexpr bool optional = true;
		typedef enum {
			True
		} index_t;

	};

	bt_rssi_t& set_bt_rssi() { bt_rssi.setpresent(true); return bt_rssi;}
	bt_rssi_t const* get_bt_rssi() const {return bt_rssi.is_valid() ? &bt_rssi : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<BluetoothMeasurementConfiguration_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<BluetoothMeasurementConfiguration_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(bluetoothMeasConfig);
		v(bluetoothMeasConfigNameList);
		v(bt_rssi);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(bluetoothMeasConfig);
		v(bluetoothMeasConfigNameList);
		v(bt_rssi);
		v(iE_Extensions);

	};
	void clear()
	{
		bluetoothMeasConfig.clear();
		bluetoothMeasConfigNameList.clear();
		bt_rssi.clear();
		iE_Extensions.clear();

	};
	private:
	bluetoothMeasConfig_t	bluetoothMeasConfig;
	bluetoothMeasConfigNameList_t	bluetoothMeasConfigNameList;
	bt_rssi_t	bt_rssi;
	iE_Extensions_t	iE_Extensions;

};
/*
BroadcastPLMNs-Item ::= SEQUENCE (SIZE(1..maxnoofBPLMNs)) OF PLMN-Identity
*/

struct BroadcastPLMNs_Item_elm : PLMN_Identity
{
	static constexpr const char* name() {return "BroadcastPLMNs_Item_elm";}
	using parent_t = PLMN_Identity;

};
struct BroadcastPLMNs_Item : asn::sequenceof<BroadcastPLMNs_Item_elm>
{
	static constexpr const char* name() {return "BroadcastPLMNs-Item";}
	using parent_t = asn::sequenceof<BroadcastPLMNs_Item_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBPLMNs >>;

};
/*
CNTypeRestrictionsItem-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CNTypeRestrictionsItem_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CNTypeRestrictionsItem ::= SEQUENCE {
	plmn-Id				PLMN-Identity,
	cn-type				ENUMERATED {fiveGC-forbidden, ...},
	iE-Extensions		ProtocolExtensionContainer { {CNTypeRestrictionsItem-ExtIEs} } OPTIONAL,
	...
}
*/

struct CNTypeRestrictionsItem : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CNTypeRestrictionsItem";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct plmn_Id_t : PLMN_Identity
	{
		static constexpr const char* name() {return "plmn_Id_t";}
		using parent_t = PLMN_Identity;

	};
	plmn_Id_t& ref_plmn_Id() {return plmn_Id;}
	plmn_Id_t const& ref_plmn_Id() const {return plmn_Id;}
	struct cn_type_t : asn::enumerated<1, 0, true>
	{
		static constexpr const char* name() {return "cn_type_t";}
		using parent_t = asn::enumerated<1, 0, true>;
		typedef enum {
			fiveGC_forbidden
		} index_t;

	};

	cn_type_t& ref_cn_type() {return cn_type;}
	cn_type_t const& ref_cn_type() const {return cn_type;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CNTypeRestrictionsItem_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CNTypeRestrictionsItem_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(plmn_Id);
		v(cn_type);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(plmn_Id);
		v(cn_type);
		v(iE_Extensions);

	};
	void clear()
	{
		plmn_Id.clear();
		cn_type.clear();
		iE_Extensions.clear();

	};
	private:
	plmn_Id_t	plmn_Id;
	cn_type_t	cn_type;
	iE_Extensions_t	iE_Extensions;

};
/*
CNTypeRestrictions ::= SEQUENCE (SIZE(1.. maxnoofEPLMNsPlusOne)) OF CNTypeRestrictionsItem
*/

struct CNTypeRestrictions_elm : CNTypeRestrictionsItem
{
	static constexpr const char* name() {return "CNTypeRestrictions_elm";}
	using parent_t = CNTypeRestrictionsItem;

};
struct CNTypeRestrictions : asn::sequenceof<CNTypeRestrictions_elm>
{
	static constexpr const char* name() {return "CNTypeRestrictions";}
	using parent_t = asn::sequenceof<CNTypeRestrictions_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofEPLMNsPlusOne >>;

};
/*
PDCP-SNExtended ::= INTEGER (0..32767)
*/

struct PDCP_SNExtended : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 32767>>;
	static constexpr const char* name() {return "PDCP-SNExtended";}
	using parent_t = asn::integer<>;

};

/*
HFNModified ::= INTEGER (0..131071)
*/

struct HFNModified : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 131071>>;
	static constexpr const char* name() {return "HFNModified";}
	using parent_t = asn::integer<>;

};

/*
COUNTValueExtended-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct COUNTValueExtended_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
COUNTValueExtended ::= SEQUENCE {
	pDCP-SNExtended			PDCP-SNExtended,
	hFNModified				HFNModified,
	iE-Extensions			ProtocolExtensionContainer { {COUNTValueExtended-ExtIEs} } OPTIONAL,
	...
}
*/

struct COUNTValueExtended : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "COUNTValueExtended";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pDCP_SNExtended_t : PDCP_SNExtended
	{
		static constexpr const char* name() {return "pDCP_SNExtended_t";}
		using parent_t = PDCP_SNExtended;

	};
	pDCP_SNExtended_t& ref_pDCP_SNExtended() {return pDCP_SNExtended;}
	pDCP_SNExtended_t const& ref_pDCP_SNExtended() const {return pDCP_SNExtended;}
	struct hFNModified_t : HFNModified
	{
		static constexpr const char* name() {return "hFNModified_t";}
		using parent_t = HFNModified;

	};
	hFNModified_t& ref_hFNModified() {return hFNModified;}
	hFNModified_t const& ref_hFNModified() const {return hFNModified;}
	struct iE_Extensions_t : ProtocolExtensionContainer<COUNTValueExtended_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<COUNTValueExtended_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pDCP_SNExtended);
		v(hFNModified);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pDCP_SNExtended);
		v(hFNModified);
		v(iE_Extensions);

	};
	void clear()
	{
		pDCP_SNExtended.clear();
		hFNModified.clear();
		iE_Extensions.clear();

	};
	private:
	pDCP_SNExtended_t	pDCP_SNExtended;
	hFNModified_t	hFNModified;
	iE_Extensions_t	iE_Extensions;

};
/*
PDCP-SN ::= INTEGER (0..4095)
*/

struct PDCP_SN : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 4095>>;
	static constexpr const char* name() {return "PDCP-SN";}
	using parent_t = asn::integer<>;

};

/*
HFN ::= INTEGER (0..1048575)
*/

struct HFN : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 1048575>>;
	static constexpr const char* name() {return "HFN";}
	using parent_t = asn::integer<>;

};

/*
COUNTvalue-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct COUNTvalue_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
COUNTvalue ::= SEQUENCE {
	pDCP-SN					PDCP-SN,
	hFN						HFN,
	iE-Extensions			ProtocolExtensionContainer { {COUNTvalue-ExtIEs} } OPTIONAL,
	...
}
*/

struct COUNTvalue : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "COUNTvalue";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pDCP_SN_t : PDCP_SN
	{
		static constexpr const char* name() {return "pDCP_SN_t";}
		using parent_t = PDCP_SN;

	};
	pDCP_SN_t& ref_pDCP_SN() {return pDCP_SN;}
	pDCP_SN_t const& ref_pDCP_SN() const {return pDCP_SN;}
	struct hFN_t : HFN
	{
		static constexpr const char* name() {return "hFN_t";}
		using parent_t = HFN;

	};
	hFN_t& ref_hFN() {return hFN;}
	hFN_t const& ref_hFN() const {return hFN;}
	struct iE_Extensions_t : ProtocolExtensionContainer<COUNTvalue_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<COUNTvalue_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pDCP_SN);
		v(hFN);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pDCP_SN);
		v(hFN);
		v(iE_Extensions);

	};
	void clear()
	{
		pDCP_SN.clear();
		hFN.clear();
		iE_Extensions.clear();

	};
	private:
	pDCP_SN_t	pDCP_SN;
	hFN_t	hFN;
	iE_Extensions_t	iE_Extensions;

};
/*
PDCP-SNlength18 ::= INTEGER (0..262143)
*/

struct PDCP_SNlength18 : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 262143>>;
	static constexpr const char* name() {return "PDCP-SNlength18";}
	using parent_t = asn::integer<>;

};

/*
HFNforPDCP-SNlength18 ::= INTEGER (0..16383)
*/

struct HFNforPDCP_SNlength18 : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 16383>>;
	static constexpr const char* name() {return "HFNforPDCP-SNlength18";}
	using parent_t = asn::integer<>;

};

/*
COUNTvaluePDCP-SNlength18-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct COUNTvaluePDCP_SNlength18_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
COUNTvaluePDCP-SNlength18 ::= SEQUENCE {
	pDCP-SNlength18			PDCP-SNlength18,
	hFNforPDCP-SNlength18	HFNforPDCP-SNlength18,
	iE-Extensions			ProtocolExtensionContainer { {COUNTvaluePDCP-SNlength18-ExtIEs} } OPTIONAL,
	...
}
*/

struct COUNTvaluePDCP_SNlength18 : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "COUNTvaluePDCP-SNlength18";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pDCP_SNlength18_t : PDCP_SNlength18
	{
		static constexpr const char* name() {return "pDCP_SNlength18_t";}
		using parent_t = PDCP_SNlength18;

	};
	pDCP_SNlength18_t& ref_pDCP_SNlength18() {return pDCP_SNlength18;}
	pDCP_SNlength18_t const& ref_pDCP_SNlength18() const {return pDCP_SNlength18;}
	struct hFNforPDCP_SNlength18_t : HFNforPDCP_SNlength18
	{
		static constexpr const char* name() {return "hFNforPDCP_SNlength18_t";}
		using parent_t = HFNforPDCP_SNlength18;

	};
	hFNforPDCP_SNlength18_t& ref_hFNforPDCP_SNlength18() {return hFNforPDCP_SNlength18;}
	hFNforPDCP_SNlength18_t const& ref_hFNforPDCP_SNlength18() const {return hFNforPDCP_SNlength18;}
	struct iE_Extensions_t : ProtocolExtensionContainer<COUNTvaluePDCP_SNlength18_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<COUNTvaluePDCP_SNlength18_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pDCP_SNlength18);
		v(hFNforPDCP_SNlength18);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pDCP_SNlength18);
		v(hFNforPDCP_SNlength18);
		v(iE_Extensions);

	};
	void clear()
	{
		pDCP_SNlength18.clear();
		hFNforPDCP_SNlength18.clear();
		iE_Extensions.clear();

	};
	private:
	pDCP_SNlength18_t	pDCP_SNlength18;
	hFNforPDCP_SNlength18_t	hFNforPDCP_SNlength18;
	iE_Extensions_t	iE_Extensions;

};
/*
CRNTI ::= BIT STRING (SIZE (16))
*/

struct CRNTI : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<16>>;
	static constexpr const char* name() {return "CRNTI";}
	using parent_t = asn::bstring<>;

};

/*
CSG-Id ::= BIT STRING (SIZE (27))
*/

struct CSG_Id : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<27>>;
	static constexpr const char* name() {return "CSG-Id";}
	using parent_t = asn::bstring<>;

};

/*
CSGMembershipStatus ::= ENUMERATED {
	member,
	not-member
}
*/

struct CSGMembershipStatus : asn::enumerated<2, 0, false>
{
	static constexpr const char* name() {return "CSGMembershipStatus";}
	using parent_t = asn::enumerated<2, 0, false>;
	typedef enum {
		member
		,not_member
	} index_t;

};

/*
UEID ::= BIT STRING (SIZE (16))
*/

struct UEID : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<16>>;
	static constexpr const char* name() {return "UEID";}
	using parent_t = asn::bstring<>;

};

/*
WidebandCQICodeword1::= CHOICE {
	four-bitCQI								INTEGER (0..15, ...),
	three-bitSpatialDifferentialCQI			INTEGER (0..7, ...),
	...
}
*/

struct WidebandCQICodeword1 : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "WidebandCQICodeword1";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~WidebandCQICodeword1() {clear();}
	struct four_bitCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 15>>;
		static constexpr const char* name() {return "four_bitCQI_t";}
		using parent_t = asn::integer<>;

	};

	struct three_bitSpatialDifferentialCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 7>>;
		static constexpr const char* name() {return "three_bitSpatialDifferentialCQI_t";}
		using parent_t = asn::integer<>;

	};

	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<four_bitCQI_t>(); break;
		case 2: var.destroy<three_bitSpatialDifferentialCQI_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<four_bitCQI_t>());
		case 2: set_index(2); return v(var.build<three_bitSpatialDifferentialCQI_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<four_bitCQI_t>());
		case 2: return v(var.as<three_bitSpatialDifferentialCQI_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<four_bitCQI_t>(1);
		v.template operator()<three_bitSpatialDifferentialCQI_t>(2);

	}
	four_bitCQI_t& select_four_bitCQI() { if(get_index() != 1) { clear(); set_index(1); return var.build<four_bitCQI_t>();} return var.as<four_bitCQI_t>();}
	four_bitCQI_t const* get_four_bitCQI() const { if(get_index() == 1) { return &var.as<four_bitCQI_t>();} return nullptr; }
	three_bitSpatialDifferentialCQI_t& select_three_bitSpatialDifferentialCQI() { if(get_index() != 2) { clear(); set_index(2); return var.build<three_bitSpatialDifferentialCQI_t>();} return var.as<three_bitSpatialDifferentialCQI_t>();}
	three_bitSpatialDifferentialCQI_t const* get_three_bitSpatialDifferentialCQI() const { if(get_index() == 2) { return &var.as<three_bitSpatialDifferentialCQI_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(four_bitCQI_t)];
		char dummy2[sizeof(three_bitSpatialDifferentialCQI_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
WidebandCQI-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct WidebandCQI_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
WidebandCQI ::= SEQUENCE {
	widebandCQICodeword0		INTEGER (0..15, ...),
	widebandCQICodeword1		WidebandCQICodeword1		OPTIONAL,
	iE-Extensions				ProtocolExtensionContainer { {WidebandCQI-ExtIEs} } OPTIONAL,
	...
}
*/

struct WidebandCQI : asn::sequence<3, 0, true, 2>
{
	static constexpr const char* name() {return "WidebandCQI";}
	using parent_t = asn::sequence<3, 0, true, 2>;
	struct widebandCQICodeword0_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 15>>;
		static constexpr const char* name() {return "widebandCQICodeword0_t";}
		using parent_t = asn::integer<>;

	};

	widebandCQICodeword0_t& ref_widebandCQICodeword0() {return widebandCQICodeword0;}
	widebandCQICodeword0_t const& ref_widebandCQICodeword0() const {return widebandCQICodeword0;}
	struct widebandCQICodeword1_t : WidebandCQICodeword1
	{
		static constexpr const char* name() {return "widebandCQICodeword1_t";}
		using parent_t = WidebandCQICodeword1;
		static constexpr bool optional = true;

	};
	widebandCQICodeword1_t& set_widebandCQICodeword1() { widebandCQICodeword1.setpresent(true); return widebandCQICodeword1;}
	widebandCQICodeword1_t const* get_widebandCQICodeword1() const {return widebandCQICodeword1.is_valid() ? &widebandCQICodeword1 : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<WidebandCQI_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<WidebandCQI_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(widebandCQICodeword0);
		v(widebandCQICodeword1);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(widebandCQICodeword0);
		v(widebandCQICodeword1);
		v(iE_Extensions);

	};
	void clear()
	{
		widebandCQICodeword0.clear();
		widebandCQICodeword1.clear();
		iE_Extensions.clear();

	};
	private:
	widebandCQICodeword0_t	widebandCQICodeword0;
	widebandCQICodeword1_t	widebandCQICodeword1;
	iE_Extensions_t	iE_Extensions;

};
/*
SubbandSize ::= ENUMERATED {
	size2,
	size3,
	size4,
	size6,
	size8,
	...
}
*/

struct SubbandSize : asn::enumerated<5, 0, true>
{
	static constexpr const char* name() {return "SubbandSize";}
	using parent_t = asn::enumerated<5, 0, true>;
	typedef enum {
		size2
		,size3
		,size4
		,size6
		,size8
	} index_t;

};

/*
SubbandCQICodeword0 ::= CHOICE {
	four-bitCQI						INTEGER (0..15, ...),
	two-bitSubbandDifferentialCQI	INTEGER (0..3, ...),
	two-bitDifferentialCQI			INTEGER (0..3, ...),
	...
}
*/

struct SubbandCQICodeword0 : asn::choice<3, 0, true>
{
	static constexpr const char* name() {return "SubbandCQICodeword0";}
	using parent_t = asn::choice<3, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 4;}
	void set_unknown() { set_index(4);  }
	~SubbandCQICodeword0() {clear();}
	struct four_bitCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 15>>;
		static constexpr const char* name() {return "four_bitCQI_t";}
		using parent_t = asn::integer<>;

	};

	struct two_bitSubbandDifferentialCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 3>>;
		static constexpr const char* name() {return "two_bitSubbandDifferentialCQI_t";}
		using parent_t = asn::integer<>;

	};

	struct two_bitDifferentialCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 3>>;
		static constexpr const char* name() {return "two_bitDifferentialCQI_t";}
		using parent_t = asn::integer<>;

	};

	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<four_bitCQI_t>(); break;
		case 2: var.destroy<two_bitSubbandDifferentialCQI_t>(); break;
		case 3: var.destroy<two_bitDifferentialCQI_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<four_bitCQI_t>());
		case 2: set_index(2); return v(var.build<two_bitSubbandDifferentialCQI_t>());
		case 3: set_index(3); return v(var.build<two_bitDifferentialCQI_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<four_bitCQI_t>());
		case 2: return v(var.as<two_bitSubbandDifferentialCQI_t>());
		case 3: return v(var.as<two_bitDifferentialCQI_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<four_bitCQI_t>(1);
		v.template operator()<two_bitSubbandDifferentialCQI_t>(2);
		v.template operator()<two_bitDifferentialCQI_t>(3);

	}
	four_bitCQI_t& select_four_bitCQI() { if(get_index() != 1) { clear(); set_index(1); return var.build<four_bitCQI_t>();} return var.as<four_bitCQI_t>();}
	four_bitCQI_t const* get_four_bitCQI() const { if(get_index() == 1) { return &var.as<four_bitCQI_t>();} return nullptr; }
	two_bitSubbandDifferentialCQI_t& select_two_bitSubbandDifferentialCQI() { if(get_index() != 2) { clear(); set_index(2); return var.build<two_bitSubbandDifferentialCQI_t>();} return var.as<two_bitSubbandDifferentialCQI_t>();}
	two_bitSubbandDifferentialCQI_t const* get_two_bitSubbandDifferentialCQI() const { if(get_index() == 2) { return &var.as<two_bitSubbandDifferentialCQI_t>();} return nullptr; }
	two_bitDifferentialCQI_t& select_two_bitDifferentialCQI() { if(get_index() != 3) { clear(); set_index(3); return var.build<two_bitDifferentialCQI_t>();} return var.as<two_bitDifferentialCQI_t>();}
	two_bitDifferentialCQI_t const* get_two_bitDifferentialCQI() const { if(get_index() == 3) { return &var.as<two_bitDifferentialCQI_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(four_bitCQI_t)];
		char dummy2[sizeof(two_bitSubbandDifferentialCQI_t)];
		char dummy3[sizeof(two_bitDifferentialCQI_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
SubbandCQICodeword1 ::= CHOICE {
	four-bitCQI							INTEGER (0..15, ...),
	three-bitSpatialDifferentialCQI		INTEGER (0..7, ...),
	two-bitSubbandDifferentialCQI		INTEGER (0..3, ...),
	two-bitDifferentialCQI				INTEGER (0..3, ...),
	...
}
*/

struct SubbandCQICodeword1 : asn::choice<4, 0, true>
{
	static constexpr const char* name() {return "SubbandCQICodeword1";}
	using parent_t = asn::choice<4, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 5;}
	void set_unknown() { set_index(5);  }
	~SubbandCQICodeword1() {clear();}
	struct four_bitCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 15>>;
		static constexpr const char* name() {return "four_bitCQI_t";}
		using parent_t = asn::integer<>;

	};

	struct three_bitSpatialDifferentialCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 7>>;
		static constexpr const char* name() {return "three_bitSpatialDifferentialCQI_t";}
		using parent_t = asn::integer<>;

	};

	struct two_bitSubbandDifferentialCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 3>>;
		static constexpr const char* name() {return "two_bitSubbandDifferentialCQI_t";}
		using parent_t = asn::integer<>;

	};

	struct two_bitDifferentialCQI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 3>>;
		static constexpr const char* name() {return "two_bitDifferentialCQI_t";}
		using parent_t = asn::integer<>;

	};

	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<four_bitCQI_t>(); break;
		case 2: var.destroy<three_bitSpatialDifferentialCQI_t>(); break;
		case 3: var.destroy<two_bitSubbandDifferentialCQI_t>(); break;
		case 4: var.destroy<two_bitDifferentialCQI_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<four_bitCQI_t>());
		case 2: set_index(2); return v(var.build<three_bitSpatialDifferentialCQI_t>());
		case 3: set_index(3); return v(var.build<two_bitSubbandDifferentialCQI_t>());
		case 4: set_index(4); return v(var.build<two_bitDifferentialCQI_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<four_bitCQI_t>());
		case 2: return v(var.as<three_bitSpatialDifferentialCQI_t>());
		case 3: return v(var.as<two_bitSubbandDifferentialCQI_t>());
		case 4: return v(var.as<two_bitDifferentialCQI_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<four_bitCQI_t>(1);
		v.template operator()<three_bitSpatialDifferentialCQI_t>(2);
		v.template operator()<two_bitSubbandDifferentialCQI_t>(3);
		v.template operator()<two_bitDifferentialCQI_t>(4);

	}
	four_bitCQI_t& select_four_bitCQI() { if(get_index() != 1) { clear(); set_index(1); return var.build<four_bitCQI_t>();} return var.as<four_bitCQI_t>();}
	four_bitCQI_t const* get_four_bitCQI() const { if(get_index() == 1) { return &var.as<four_bitCQI_t>();} return nullptr; }
	three_bitSpatialDifferentialCQI_t& select_three_bitSpatialDifferentialCQI() { if(get_index() != 2) { clear(); set_index(2); return var.build<three_bitSpatialDifferentialCQI_t>();} return var.as<three_bitSpatialDifferentialCQI_t>();}
	three_bitSpatialDifferentialCQI_t const* get_three_bitSpatialDifferentialCQI() const { if(get_index() == 2) { return &var.as<three_bitSpatialDifferentialCQI_t>();} return nullptr; }
	two_bitSubbandDifferentialCQI_t& select_two_bitSubbandDifferentialCQI() { if(get_index() != 3) { clear(); set_index(3); return var.build<two_bitSubbandDifferentialCQI_t>();} return var.as<two_bitSubbandDifferentialCQI_t>();}
	two_bitSubbandDifferentialCQI_t const* get_two_bitSubbandDifferentialCQI() const { if(get_index() == 3) { return &var.as<two_bitSubbandDifferentialCQI_t>();} return nullptr; }
	two_bitDifferentialCQI_t& select_two_bitDifferentialCQI() { if(get_index() != 4) { clear(); set_index(4); return var.build<two_bitDifferentialCQI_t>();} return var.as<two_bitDifferentialCQI_t>();}
	two_bitDifferentialCQI_t const* get_two_bitDifferentialCQI() const { if(get_index() == 4) { return &var.as<two_bitDifferentialCQI_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(four_bitCQI_t)];
		char dummy2[sizeof(three_bitSpatialDifferentialCQI_t)];
		char dummy3[sizeof(two_bitSubbandDifferentialCQI_t)];
		char dummy4[sizeof(two_bitDifferentialCQI_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
SubbandCQI-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct SubbandCQI_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
SubbandCQI ::= SEQUENCE {
	subbandCQICodeword0			SubbandCQICodeword0,
	subbandCQICodeword1			SubbandCQICodeword1		OPTIONAL,
	iE-Extensions				ProtocolExtensionContainer { {SubbandCQI-ExtIEs} } OPTIONAL,
	...
}
*/

struct SubbandCQI : asn::sequence<3, 0, true, 2>
{
	static constexpr const char* name() {return "SubbandCQI";}
	using parent_t = asn::sequence<3, 0, true, 2>;
	struct subbandCQICodeword0_t : SubbandCQICodeword0
	{
		static constexpr const char* name() {return "subbandCQICodeword0_t";}
		using parent_t = SubbandCQICodeword0;

	};
	subbandCQICodeword0_t& ref_subbandCQICodeword0() {return subbandCQICodeword0;}
	subbandCQICodeword0_t const& ref_subbandCQICodeword0() const {return subbandCQICodeword0;}
	struct subbandCQICodeword1_t : SubbandCQICodeword1
	{
		static constexpr const char* name() {return "subbandCQICodeword1_t";}
		using parent_t = SubbandCQICodeword1;
		static constexpr bool optional = true;

	};
	subbandCQICodeword1_t& set_subbandCQICodeword1() { subbandCQICodeword1.setpresent(true); return subbandCQICodeword1;}
	subbandCQICodeword1_t const* get_subbandCQICodeword1() const {return subbandCQICodeword1.is_valid() ? &subbandCQICodeword1 : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<SubbandCQI_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<SubbandCQI_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(subbandCQICodeword0);
		v(subbandCQICodeword1);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(subbandCQICodeword0);
		v(subbandCQICodeword1);
		v(iE_Extensions);

	};
	void clear()
	{
		subbandCQICodeword0.clear();
		subbandCQICodeword1.clear();
		iE_Extensions.clear();

	};
	private:
	subbandCQICodeword0_t	subbandCQICodeword0;
	subbandCQICodeword1_t	subbandCQICodeword1;
	iE_Extensions_t	iE_Extensions;

};
/*
SubbandCQIItem-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct SubbandCQIItem_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
SubbandCQIItem ::= SEQUENCE {
	subbandCQI			SubbandCQI,
	subbandIndex		INTEGER (0..27,...),
	iE-Extensions		ProtocolExtensionContainer { {SubbandCQIItem-ExtIEs} } OPTIONAL,
	...
}
*/

struct SubbandCQIItem : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "SubbandCQIItem";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct subbandCQI_t : SubbandCQI
	{
		static constexpr const char* name() {return "subbandCQI_t";}
		using parent_t = SubbandCQI;

	};
	subbandCQI_t& ref_subbandCQI() {return subbandCQI;}
	subbandCQI_t const& ref_subbandCQI() const {return subbandCQI;}
	struct subbandIndex_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 27>>;
		static constexpr const char* name() {return "subbandIndex_t";}
		using parent_t = asn::integer<>;

	};

	subbandIndex_t& ref_subbandIndex() {return subbandIndex;}
	subbandIndex_t const& ref_subbandIndex() const {return subbandIndex;}
	struct iE_Extensions_t : ProtocolExtensionContainer<SubbandCQIItem_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<SubbandCQIItem_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(subbandCQI);
		v(subbandIndex);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(subbandCQI);
		v(subbandIndex);
		v(iE_Extensions);

	};
	void clear()
	{
		subbandCQI.clear();
		subbandIndex.clear();
		iE_Extensions.clear();

	};
	private:
	subbandCQI_t	subbandCQI;
	subbandIndex_t	subbandIndex;
	iE_Extensions_t	iE_Extensions;

};
/*
SubbandCQIList ::= SEQUENCE (SIZE(1.. maxSubband)) OF SubbandCQIItem
*/

struct SubbandCQIList_elm : SubbandCQIItem
{
	static constexpr const char* name() {return "SubbandCQIList_elm";}
	using parent_t = SubbandCQIItem;

};
struct SubbandCQIList : asn::sequenceof<SubbandCQIList_elm>
{
	static constexpr const char* name() {return "SubbandCQIList";}
	using parent_t = asn::sequenceof<SubbandCQIList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxSubband >>;

};
/*
CSIReportPerCSIProcessItem-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CSIReportPerCSIProcessItem_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CSIReportPerCSIProcessItem ::= SEQUENCE (SIZE(1.. maxCSIReport)) OF
	SEQUENCE {
		rI								INTEGER (1..8, ...),
		widebandCQI						WidebandCQI,
		subbandSize						SubbandSize,
		subbandCQIList					SubbandCQIList	OPTIONAL,
		iE-Extensions					ProtocolExtensionContainer { {CSIReportPerCSIProcessItem-ExtIEs} } OPTIONAL,
		...
	}
*/

struct CSIReportPerCSIProcessItem_elm : asn::sequence<5, 0, true, 2>
{
	static constexpr const char* name() {return "CSIReportPerCSIProcessItem_elm";}
	using parent_t = asn::sequence<5, 0, true, 2>;
	struct rI_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 8>>;
		static constexpr const char* name() {return "rI_t";}
		using parent_t = asn::integer<>;

	};

	rI_t& ref_rI() {return rI;}
	rI_t const& ref_rI() const {return rI;}
	struct widebandCQI_t : WidebandCQI
	{
		static constexpr const char* name() {return "widebandCQI_t";}
		using parent_t = WidebandCQI;

	};
	widebandCQI_t& ref_widebandCQI() {return widebandCQI;}
	widebandCQI_t const& ref_widebandCQI() const {return widebandCQI;}
	struct subbandSize_t : SubbandSize
	{
		static constexpr const char* name() {return "subbandSize_t";}
		using parent_t = SubbandSize;

	};
	subbandSize_t& ref_subbandSize() {return subbandSize;}
	subbandSize_t const& ref_subbandSize() const {return subbandSize;}
	struct subbandCQIList_t : SubbandCQIList
	{
		static constexpr const char* name() {return "subbandCQIList_t";}
		using parent_t = SubbandCQIList;
		static constexpr bool optional = true;

	};
	subbandCQIList_t& set_subbandCQIList() { subbandCQIList.setpresent(true); return subbandCQIList;}
	subbandCQIList_t const* get_subbandCQIList() const {return subbandCQIList.is_valid() ? &subbandCQIList : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CSIReportPerCSIProcessItem_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CSIReportPerCSIProcessItem_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(rI);
		v(widebandCQI);
		v(subbandSize);
		v(subbandCQIList);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(rI);
		v(widebandCQI);
		v(subbandSize);
		v(subbandCQIList);
		v(iE_Extensions);

	};
	void clear()
	{
		rI.clear();
		widebandCQI.clear();
		subbandSize.clear();
		subbandCQIList.clear();
		iE_Extensions.clear();

	};
	private:
	rI_t	rI;
	widebandCQI_t	widebandCQI;
	subbandSize_t	subbandSize;
	subbandCQIList_t	subbandCQIList;
	iE_Extensions_t	iE_Extensions;

};
struct CSIReportPerCSIProcessItem : asn::sequenceof<CSIReportPerCSIProcessItem_elm>
{
	static constexpr const char* name() {return "CSIReportPerCSIProcessItem";}
	using parent_t = asn::sequenceof<CSIReportPerCSIProcessItem_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCSIReport >>;

};
/*
CSIReportPerCSIProcess-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CSIReportPerCSIProcess_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CSIReportPerCSIProcess ::= SEQUENCE (SIZE(1.. maxCSIProcess)) OF
	SEQUENCE {
		cSIProcessConfigurationIndex	INTEGER (1..7, ...),
		cSIReportPerCSIProcessItem		CSIReportPerCSIProcessItem,
		iE-Extensions					ProtocolExtensionContainer { {CSIReportPerCSIProcess-ExtIEs} } OPTIONAL,
		...
	}
*/

struct CSIReportPerCSIProcess_elm : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CSIReportPerCSIProcess_elm";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct cSIProcessConfigurationIndex_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 7>>;
		static constexpr const char* name() {return "cSIProcessConfigurationIndex_t";}
		using parent_t = asn::integer<>;

	};

	cSIProcessConfigurationIndex_t& ref_cSIProcessConfigurationIndex() {return cSIProcessConfigurationIndex;}
	cSIProcessConfigurationIndex_t const& ref_cSIProcessConfigurationIndex() const {return cSIProcessConfigurationIndex;}
	struct cSIReportPerCSIProcessItem_t : CSIReportPerCSIProcessItem
	{
		static constexpr const char* name() {return "cSIReportPerCSIProcessItem_t";}
		using parent_t = CSIReportPerCSIProcessItem;

	};
	cSIReportPerCSIProcessItem_t& ref_cSIReportPerCSIProcessItem() {return cSIReportPerCSIProcessItem;}
	cSIReportPerCSIProcessItem_t const& ref_cSIReportPerCSIProcessItem() const {return cSIReportPerCSIProcessItem;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CSIReportPerCSIProcess_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CSIReportPerCSIProcess_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(cSIProcessConfigurationIndex);
		v(cSIReportPerCSIProcessItem);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(cSIProcessConfigurationIndex);
		v(cSIReportPerCSIProcessItem);
		v(iE_Extensions);

	};
	void clear()
	{
		cSIProcessConfigurationIndex.clear();
		cSIReportPerCSIProcessItem.clear();
		iE_Extensions.clear();

	};
	private:
	cSIProcessConfigurationIndex_t	cSIProcessConfigurationIndex;
	cSIReportPerCSIProcessItem_t	cSIReportPerCSIProcessItem;
	iE_Extensions_t	iE_Extensions;

};
struct CSIReportPerCSIProcess : asn::sequenceof<CSIReportPerCSIProcess_elm>
{
	static constexpr const char* name() {return "CSIReportPerCSIProcess";}
	using parent_t = asn::sequenceof<CSIReportPerCSIProcess_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCSIProcess >>;

};
/*
CSIReportList-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CSIReportList_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CSIReportList ::= SEQUENCE (SIZE(1..maxUEReport)) OF
	SEQUENCE {
		uEID							UEID,
		cSIReportPerCSIProcess			CSIReportPerCSIProcess,
		iE-Extensions					ProtocolExtensionContainer { {CSIReportList-ExtIEs} } OPTIONAL,
		...
	}
*/

struct CSIReportList_elm : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CSIReportList_elm";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct uEID_t : UEID
	{
		static constexpr const char* name() {return "uEID_t";}
		using parent_t = UEID;

	};
	uEID_t& ref_uEID() {return uEID;}
	uEID_t const& ref_uEID() const {return uEID;}
	struct cSIReportPerCSIProcess_t : CSIReportPerCSIProcess
	{
		static constexpr const char* name() {return "cSIReportPerCSIProcess_t";}
		using parent_t = CSIReportPerCSIProcess;

	};
	cSIReportPerCSIProcess_t& ref_cSIReportPerCSIProcess() {return cSIReportPerCSIProcess;}
	cSIReportPerCSIProcess_t const& ref_cSIReportPerCSIProcess() const {return cSIReportPerCSIProcess;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CSIReportList_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CSIReportList_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(uEID);
		v(cSIReportPerCSIProcess);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(uEID);
		v(cSIReportPerCSIProcess);
		v(iE_Extensions);

	};
	void clear()
	{
		uEID.clear();
		cSIReportPerCSIProcess.clear();
		iE_Extensions.clear();

	};
	private:
	uEID_t	uEID;
	cSIReportPerCSIProcess_t	cSIReportPerCSIProcess;
	iE_Extensions_t	iE_Extensions;

};
struct CSIReportList : asn::sequenceof<CSIReportList_elm>
{
	static constexpr const char* name() {return "CSIReportList";}
	using parent_t = asn::sequenceof<CSIReportList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxUEReport >>;

};
/*
CapacityValue ::= INTEGER (0..100)
*/

struct CapacityValue : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 100>>;
	static constexpr const char* name() {return "CapacityValue";}
	using parent_t = asn::integer<>;

};

/*
CauseRadioNetwork ::= ENUMERATED {
	handover-desirable-for-radio-reasons,
	time-critical-handover,
	resource-optimisation-handover,
	reduce-load-in-serving-cell,
	partial-handover,
	unknown-new-eNB-UE-X2AP-ID,
	unknown-old-eNB-UE-X2AP-ID,
	unknown-pair-of-UE-X2AP-ID,
	ho-target-not-allowed,
	tx2relocoverall-expiry,
	trelocprep-expiry,
	cell-not-available,
	no-radio-resources-available-in-target-cell,
	invalid-MME-GroupID,
	unknown-MME-Code,
	encryption-and-or-integrity-protection-algorithms-not-supported,
	reportCharacteristicsEmpty,
	noReportPeriodicity,
	existingMeasurementID,
	unknown-eNB-Measurement-ID,
	measurement-temporarily-not-available,
	unspecified,
	...,
	load-balancing,
	handover-optimisation,
	value-out-of-allowed-range,
	multiple-E-RAB-ID-instances,
	switch-off-ongoing,
	not-supported-QCI-value,
	measurement-not-supported-for-the-object,
	tDCoverall-expiry,
	tDCprep-expiry,
	action-desirable-for-radio-reasons,
	reduce-load,
	resource-optimisation,
	time-critical-action,
	target-not-allowed,
	no-radio-resources-available,
	invalid-QoS-combination,
	encryption-algorithms-not-aupported,
	procedure-cancelled,
	rRM-purpose,
	improve-user-bit-rate,
	user-inactivity,
	radio-connection-with-UE-lost,
	failure-in-the-radio-interface-procedure,
	bearer-option-not-supported,
	mCG-Mobility,
	sCG-Mobility,
	count-reaches-max-value,
	unknown-old-en-gNB-UE-X2AP-ID,
	pDCP-Overload

}
*/

struct CauseRadioNetwork : asn::enumerated<51, 29, true>
{
	static constexpr const char* name() {return "CauseRadioNetwork";}
	using parent_t = asn::enumerated<51, 29, true>;
	typedef enum {
		handover_desirable_for_radio_reasons
		,time_critical_handover
		,resource_optimisation_handover
		,reduce_load_in_serving_cell
		,partial_handover
		,unknown_new_eNB_UE_X2AP_ID
		,unknown_old_eNB_UE_X2AP_ID
		,unknown_pair_of_UE_X2AP_ID
		,ho_target_not_allowed
		,tx2relocoverall_expiry
		,trelocprep_expiry
		,cell_not_available
		,no_radio_resources_available_in_target_cell
		,invalid_MME_GroupID
		,unknown_MME_Code
		,encryption_and_or_integrity_protection_algorithms_not_supported
		,reportCharacteristicsEmpty
		,noReportPeriodicity
		,existingMeasurementID
		,unknown_eNB_Measurement_ID
		,measurement_temporarily_not_available
		,unspecified
		,load_balancing
		,handover_optimisation
		,value_out_of_allowed_range
		,multiple_E_RAB_ID_instances
		,switch_off_ongoing
		,not_supported_QCI_value
		,measurement_not_supported_for_the_object
		,tDCoverall_expiry
		,tDCprep_expiry
		,action_desirable_for_radio_reasons
		,reduce_load
		,resource_optimisation
		,time_critical_action
		,target_not_allowed
		,no_radio_resources_available
		,invalid_QoS_combination
		,encryption_algorithms_not_aupported
		,procedure_cancelled
		,rRM_purpose
		,improve_user_bit_rate
		,user_inactivity
		,radio_connection_with_UE_lost
		,failure_in_the_radio_interface_procedure
		,bearer_option_not_supported
		,mCG_Mobility
		,sCG_Mobility
		,count_reaches_max_value
		,unknown_old_en_gNB_UE_X2AP_ID
		,pDCP_Overload
	} index_t;

};

/*
CauseTransport ::= ENUMERATED {
	transport-resource-unavailable,
	unspecified,
	...
}
*/

struct CauseTransport : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "CauseTransport";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		transport_resource_unavailable
		,unspecified
	} index_t;

};

/*
CauseProtocol ::= ENUMERATED {
	transfer-syntax-error,
	abstract-syntax-error-reject,
	abstract-syntax-error-ignore-and-notify,
	message-not-compatible-with-receiver-state,
	semantic-error,
	unspecified,
	abstract-syntax-error-falsely-constructed-message,
	...
}
*/

struct CauseProtocol : asn::enumerated<7, 0, true>
{
	static constexpr const char* name() {return "CauseProtocol";}
	using parent_t = asn::enumerated<7, 0, true>;
	typedef enum {
		transfer_syntax_error
		,abstract_syntax_error_reject
		,abstract_syntax_error_ignore_and_notify
		,message_not_compatible_with_receiver_state
		,semantic_error
		,unspecified
		,abstract_syntax_error_falsely_constructed_message
	} index_t;

};

/*
CauseMisc ::= ENUMERATED {
	control-processing-overload,
	hardware-failure,
	om-intervention,
	not-enough-user-plane-processing-resources,
	unspecified,
	...
}
*/

struct CauseMisc : asn::enumerated<5, 0, true>
{
	static constexpr const char* name() {return "CauseMisc";}
	using parent_t = asn::enumerated<5, 0, true>;
	typedef enum {
		control_processing_overload
		,hardware_failure
		,om_intervention
		,not_enough_user_plane_processing_resources
		,unspecified
	} index_t;

};

/*
Cause ::= CHOICE {
	radioNetwork		CauseRadioNetwork,
	transport			CauseTransport,
	protocol			CauseProtocol,
	misc				CauseMisc,
	...
}
*/

struct Cause : asn::choice<4, 0, true>
{
	static constexpr const char* name() {return "Cause";}
	using parent_t = asn::choice<4, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 5;}
	void set_unknown() { set_index(5);  }
	~Cause() {clear();}
	struct radioNetwork_t : CauseRadioNetwork
	{
		static constexpr const char* name() {return "radioNetwork_t";}
		using parent_t = CauseRadioNetwork;

	};
	struct transport_t : CauseTransport
	{
		static constexpr const char* name() {return "transport_t";}
		using parent_t = CauseTransport;

	};
	struct protocol_t : CauseProtocol
	{
		static constexpr const char* name() {return "protocol_t";}
		using parent_t = CauseProtocol;

	};
	struct misc_t : CauseMisc
	{
		static constexpr const char* name() {return "misc_t";}
		using parent_t = CauseMisc;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<radioNetwork_t>(); break;
		case 2: var.destroy<transport_t>(); break;
		case 3: var.destroy<protocol_t>(); break;
		case 4: var.destroy<misc_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<radioNetwork_t>());
		case 2: set_index(2); return v(var.build<transport_t>());
		case 3: set_index(3); return v(var.build<protocol_t>());
		case 4: set_index(4); return v(var.build<misc_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<radioNetwork_t>());
		case 2: return v(var.as<transport_t>());
		case 3: return v(var.as<protocol_t>());
		case 4: return v(var.as<misc_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<radioNetwork_t>(1);
		v.template operator()<transport_t>(2);
		v.template operator()<protocol_t>(3);
		v.template operator()<misc_t>(4);

	}
	radioNetwork_t& select_radioNetwork() { if(get_index() != 1) { clear(); set_index(1); return var.build<radioNetwork_t>();} return var.as<radioNetwork_t>();}
	radioNetwork_t const* get_radioNetwork() const { if(get_index() == 1) { return &var.as<radioNetwork_t>();} return nullptr; }
	transport_t& select_transport() { if(get_index() != 2) { clear(); set_index(2); return var.build<transport_t>();} return var.as<transport_t>();}
	transport_t const* get_transport() const { if(get_index() == 2) { return &var.as<transport_t>();} return nullptr; }
	protocol_t& select_protocol() { if(get_index() != 3) { clear(); set_index(3); return var.build<protocol_t>();} return var.as<protocol_t>();}
	protocol_t const* get_protocol() const { if(get_index() == 3) { return &var.as<protocol_t>();} return nullptr; }
	misc_t& select_misc() { if(get_index() != 4) { clear(); set_index(4); return var.build<misc_t>();} return var.as<misc_t>();}
	misc_t const* get_misc() const { if(get_index() == 4) { return &var.as<misc_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(radioNetwork_t)];
		char dummy2[sizeof(transport_t)];
		char dummy3[sizeof(protocol_t)];
		char dummy4[sizeof(misc_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
Cell-Size ::= ENUMERATED {verysmall, small, medium, large, ... }
*/

struct Cell_Size : asn::enumerated<4, 0, true>
{
	static constexpr const char* name() {return "Cell-Size";}
	using parent_t = asn::enumerated<4, 0, true>;
	typedef enum {
		verysmall
		,small
		,medium
		,large
	} index_t;

};

/*
CellCapacityClassValue ::= INTEGER (1..100, ...)
*/

struct CellCapacityClassValue : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<1, 100>>;
	static constexpr const char* name() {return "CellCapacityClassValue";}
	using parent_t = asn::integer<>;

};

/*
CellDeploymentStatusIndicator ::= ENUMERATED {pre-change-notification, ...}
*/

struct CellDeploymentStatusIndicator : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "CellDeploymentStatusIndicator";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		pre_change_notification
	} index_t;

};

/*
ReplacingCellsList-Item ::= SEQUENCE {
	eCGI			ECGI,
	...
}
*/

struct ReplacingCellsList_Item : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "ReplacingCellsList-Item";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct eCGI_t : ECGI
	{
		static constexpr const char* name() {return "eCGI_t";}
		using parent_t = ECGI;

	};
	eCGI_t& ref_eCGI() {return eCGI;}
	eCGI_t const& ref_eCGI() const {return eCGI;}
	template<typename V> void decode(V& v)
	{
		v(eCGI);

	};
	template<typename V> void encode(V& v) const
	{
		v(eCGI);

	};
	void clear()
	{
		eCGI.clear();

	};
	private:
	eCGI_t	eCGI;

};
/*
ReplacingCellsList ::= SEQUENCE (SIZE(0.. maxCellineNB)) OF ReplacingCellsList-Item
*/

struct ReplacingCellsList_elm : ReplacingCellsList_Item
{
	static constexpr const char* name() {return "ReplacingCellsList_elm";}
	using parent_t = ReplacingCellsList_Item;

};
struct ReplacingCellsList : asn::sequenceof<ReplacingCellsList_elm>
{
	static constexpr const char* name() {return "ReplacingCellsList";}
	using parent_t = asn::sequenceof<ReplacingCellsList_elm>;
	using constraint_t = asn::constraints<false,asn::span<0,  maxCellineNB >>;

};
/*
CellReplacingInfo-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CellReplacingInfo_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CellReplacingInfo ::= SEQUENCE {
	replacingCellsList				ReplacingCellsList,
	iE-Extensions					ProtocolExtensionContainer { {CellReplacingInfo-ExtIEs}}	OPTIONAL,
	...
}
*/

struct CellReplacingInfo : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "CellReplacingInfo";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct replacingCellsList_t : ReplacingCellsList
	{
		static constexpr const char* name() {return "replacingCellsList_t";}
		using parent_t = ReplacingCellsList;

	};
	replacingCellsList_t& ref_replacingCellsList() {return replacingCellsList;}
	replacingCellsList_t const& ref_replacingCellsList() const {return replacingCellsList;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CellReplacingInfo_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CellReplacingInfo_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(replacingCellsList);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(replacingCellsList);
		v(iE_Extensions);

	};
	void clear()
	{
		replacingCellsList.clear();
		iE_Extensions.clear();

	};
	private:
	replacingCellsList_t	replacingCellsList;
	iE_Extensions_t	iE_Extensions;

};
/*
CellReportingIndicator ::= ENUMERATED {stop-request, ... }
*/

struct CellReportingIndicator : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "CellReportingIndicator";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		stop_request
	} index_t;

};

/*
CellType-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CellType_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CellType ::= SEQUENCE {
	cell-Size						Cell-Size,
	iE-Extensions					ProtocolExtensionContainer { {CellType-ExtIEs}}	OPTIONAL,
	...
}
*/

struct CellType : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "CellType";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct cell_Size_t : Cell_Size
	{
		static constexpr const char* name() {return "cell_Size_t";}
		using parent_t = Cell_Size;

	};
	cell_Size_t& ref_cell_Size() {return cell_Size;}
	cell_Size_t const& ref_cell_Size() const {return cell_Size;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CellType_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CellType_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(cell_Size);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(cell_Size);
		v(iE_Extensions);

	};
	void clear()
	{
		cell_Size.clear();
		iE_Extensions.clear();

	};
	private:
	cell_Size_t	cell_Size;
	iE_Extensions_t	iE_Extensions;

};
/*
CoMPHypothesisSetItem-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CoMPHypothesisSetItem_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CoMPHypothesisSetItem ::= SEQUENCE {
	coMPCellID						ECGI,
	coMPHypothesis					BIT STRING (SIZE(6..4400, ...)),
	iE-Extensions					ProtocolExtensionContainer { {CoMPHypothesisSetItem-ExtIEs} } OPTIONAL,
	...
}
*/

struct CoMPHypothesisSetItem : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CoMPHypothesisSetItem";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct coMPCellID_t : ECGI
	{
		static constexpr const char* name() {return "coMPCellID_t";}
		using parent_t = ECGI;

	};
	coMPCellID_t& ref_coMPCellID() {return coMPCellID;}
	coMPCellID_t const& ref_coMPCellID() const {return coMPCellID;}
	struct coMPHypothesis_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::span<6, 4400>>;
		static constexpr const char* name() {return "coMPHypothesis_t";}
		using parent_t = asn::bstring<>;

	};

	coMPHypothesis_t& ref_coMPHypothesis() {return coMPHypothesis;}
	coMPHypothesis_t const& ref_coMPHypothesis() const {return coMPHypothesis;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CoMPHypothesisSetItem_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CoMPHypothesisSetItem_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(coMPCellID);
		v(coMPHypothesis);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(coMPCellID);
		v(coMPHypothesis);
		v(iE_Extensions);

	};
	void clear()
	{
		coMPCellID.clear();
		coMPHypothesis.clear();
		iE_Extensions.clear();

	};
	private:
	coMPCellID_t	coMPCellID;
	coMPHypothesis_t	coMPHypothesis;
	iE_Extensions_t	iE_Extensions;

};
/*
CoMPHypothesisSet ::= SEQUENCE (SIZE(1..maxnoofCoMPCells)) OF CoMPHypothesisSetItem
*/

struct CoMPHypothesisSet_elm : CoMPHypothesisSetItem
{
	static constexpr const char* name() {return "CoMPHypothesisSet_elm";}
	using parent_t = CoMPHypothesisSetItem;

};
struct CoMPHypothesisSet : asn::sequenceof<CoMPHypothesisSet_elm>
{
	static constexpr const char* name() {return "CoMPHypothesisSet";}
	using parent_t = asn::sequenceof<CoMPHypothesisSet_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofCoMPCells >>;

};
/*
CoMPInformationItem-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CoMPInformationItem_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CoMPInformationItem ::= SEQUENCE (SIZE(1..maxnoofCoMPHypothesisSet)) OF
	SEQUENCE {
		coMPHypothesisSet					CoMPHypothesisSet,
		benefitMetric						BenefitMetric,
		iE-Extensions						ProtocolExtensionContainer { {CoMPInformationItem-ExtIEs} } OPTIONAL,
		...
	}
*/

struct CoMPInformationItem_elm : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CoMPInformationItem_elm";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct coMPHypothesisSet_t : CoMPHypothesisSet
	{
		static constexpr const char* name() {return "coMPHypothesisSet_t";}
		using parent_t = CoMPHypothesisSet;

	};
	coMPHypothesisSet_t& ref_coMPHypothesisSet() {return coMPHypothesisSet;}
	coMPHypothesisSet_t const& ref_coMPHypothesisSet() const {return coMPHypothesisSet;}
	struct benefitMetric_t : BenefitMetric
	{
		static constexpr const char* name() {return "benefitMetric_t";}
		using parent_t = BenefitMetric;

	};
	benefitMetric_t& ref_benefitMetric() {return benefitMetric;}
	benefitMetric_t const& ref_benefitMetric() const {return benefitMetric;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CoMPInformationItem_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CoMPInformationItem_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(coMPHypothesisSet);
		v(benefitMetric);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(coMPHypothesisSet);
		v(benefitMetric);
		v(iE_Extensions);

	};
	void clear()
	{
		coMPHypothesisSet.clear();
		benefitMetric.clear();
		iE_Extensions.clear();

	};
	private:
	coMPHypothesisSet_t	coMPHypothesisSet;
	benefitMetric_t	benefitMetric;
	iE_Extensions_t	iE_Extensions;

};
struct CoMPInformationItem : asn::sequenceof<CoMPInformationItem_elm>
{
	static constexpr const char* name() {return "CoMPInformationItem";}
	using parent_t = asn::sequenceof<CoMPInformationItem_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofCoMPHypothesisSet >>;

};
/*
CoMPInformationStartTime-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CoMPInformationStartTime_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CoMPInformationStartTime ::= SEQUENCE (SIZE(0..1)) OF
	SEQUENCE {
		startSFN							INTEGER (0..1023, ...),
		startSubframeNumber					INTEGER (0..9, ...),
		iE-Extensions						ProtocolExtensionContainer { {CoMPInformationStartTime-ExtIEs} } OPTIONAL,
		...
	}
*/

struct CoMPInformationStartTime_elm : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CoMPInformationStartTime_elm";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct startSFN_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 1023>>;
		static constexpr const char* name() {return "startSFN_t";}
		using parent_t = asn::integer<>;

	};

	startSFN_t& ref_startSFN() {return startSFN;}
	startSFN_t const& ref_startSFN() const {return startSFN;}
	struct startSubframeNumber_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 9>>;
		static constexpr const char* name() {return "startSubframeNumber_t";}
		using parent_t = asn::integer<>;

	};

	startSubframeNumber_t& ref_startSubframeNumber() {return startSubframeNumber;}
	startSubframeNumber_t const& ref_startSubframeNumber() const {return startSubframeNumber;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CoMPInformationStartTime_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CoMPInformationStartTime_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(startSFN);
		v(startSubframeNumber);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(startSFN);
		v(startSubframeNumber);
		v(iE_Extensions);

	};
	void clear()
	{
		startSFN.clear();
		startSubframeNumber.clear();
		iE_Extensions.clear();

	};
	private:
	startSFN_t	startSFN;
	startSubframeNumber_t	startSubframeNumber;
	iE_Extensions_t	iE_Extensions;

};
struct CoMPInformationStartTime : asn::sequenceof<CoMPInformationStartTime_elm>
{
	static constexpr const char* name() {return "CoMPInformationStartTime";}
	using parent_t = asn::sequenceof<CoMPInformationStartTime_elm>;
	using constraint_t = asn::constraints<false,asn::span<0, 1>>;

};
/*
CoMPInformation-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CoMPInformation_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CoMPInformation ::= SEQUENCE {
	coMPInformationItem						CoMPInformationItem,
	coMPInformationStartTime				CoMPInformationStartTime,
	iE-Extensions							ProtocolExtensionContainer { {CoMPInformation-ExtIEs} } OPTIONAL,
	...
}
*/

struct CoMPInformation : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CoMPInformation";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct coMPInformationItem_t : CoMPInformationItem
	{
		static constexpr const char* name() {return "coMPInformationItem_t";}
		using parent_t = CoMPInformationItem;

	};
	coMPInformationItem_t& ref_coMPInformationItem() {return coMPInformationItem;}
	coMPInformationItem_t const& ref_coMPInformationItem() const {return coMPInformationItem;}
	struct coMPInformationStartTime_t : CoMPInformationStartTime
	{
		static constexpr const char* name() {return "coMPInformationStartTime_t";}
		using parent_t = CoMPInformationStartTime;

	};
	coMPInformationStartTime_t& ref_coMPInformationStartTime() {return coMPInformationStartTime;}
	coMPInformationStartTime_t const& ref_coMPInformationStartTime() const {return coMPInformationStartTime;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CoMPInformation_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CoMPInformation_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(coMPInformationItem);
		v(coMPInformationStartTime);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(coMPInformationItem);
		v(coMPInformationStartTime);
		v(iE_Extensions);

	};
	void clear()
	{
		coMPInformationItem.clear();
		coMPInformationStartTime.clear();
		iE_Extensions.clear();

	};
	private:
	coMPInformationItem_t	coMPInformationItem;
	coMPInformationStartTime_t	coMPInformationStartTime;
	iE_Extensions_t	iE_Extensions;

};
/*
CompositeAvailableCapacity-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CompositeAvailableCapacity_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CompositeAvailableCapacity ::= SEQUENCE {
	cellCapacityClassValue							CellCapacityClassValue				OPTIONAL,
	capacityValue									CapacityValue,
	iE-Extensions									ProtocolExtensionContainer { {CompositeAvailableCapacity-ExtIEs} } OPTIONAL,
	...
}
*/

struct CompositeAvailableCapacity : asn::sequence<3, 0, true, 2>
{
	static constexpr const char* name() {return "CompositeAvailableCapacity";}
	using parent_t = asn::sequence<3, 0, true, 2>;
	struct cellCapacityClassValue_t : CellCapacityClassValue
	{
		static constexpr const char* name() {return "cellCapacityClassValue_t";}
		using parent_t = CellCapacityClassValue;
		static constexpr bool optional = true;

	};
	cellCapacityClassValue_t& set_cellCapacityClassValue() { cellCapacityClassValue.setpresent(true); return cellCapacityClassValue;}
	cellCapacityClassValue_t const* get_cellCapacityClassValue() const {return cellCapacityClassValue.is_valid() ? &cellCapacityClassValue : nullptr;}
	struct capacityValue_t : CapacityValue
	{
		static constexpr const char* name() {return "capacityValue_t";}
		using parent_t = CapacityValue;

	};
	capacityValue_t& ref_capacityValue() {return capacityValue;}
	capacityValue_t const& ref_capacityValue() const {return capacityValue;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CompositeAvailableCapacity_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CompositeAvailableCapacity_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(cellCapacityClassValue);
		v(capacityValue);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(cellCapacityClassValue);
		v(capacityValue);
		v(iE_Extensions);

	};
	void clear()
	{
		cellCapacityClassValue.clear();
		capacityValue.clear();
		iE_Extensions.clear();

	};
	private:
	cellCapacityClassValue_t	cellCapacityClassValue;
	capacityValue_t	capacityValue;
	iE_Extensions_t	iE_Extensions;

};
/*
CompositeAvailableCapacityGroup-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CompositeAvailableCapacityGroup_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CompositeAvailableCapacityGroup	::= SEQUENCE {
	dL-CompositeAvailableCapacity					CompositeAvailableCapacity,
	uL-CompositeAvailableCapacity					CompositeAvailableCapacity,
	iE-Extensions									ProtocolExtensionContainer { {CompositeAvailableCapacityGroup-ExtIEs} } OPTIONAL,
	...
}
*/

struct CompositeAvailableCapacityGroup : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "CompositeAvailableCapacityGroup";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct dL_CompositeAvailableCapacity_t : CompositeAvailableCapacity
	{
		static constexpr const char* name() {return "dL_CompositeAvailableCapacity_t";}
		using parent_t = CompositeAvailableCapacity;

	};
	dL_CompositeAvailableCapacity_t& ref_dL_CompositeAvailableCapacity() {return dL_CompositeAvailableCapacity;}
	dL_CompositeAvailableCapacity_t const& ref_dL_CompositeAvailableCapacity() const {return dL_CompositeAvailableCapacity;}
	struct uL_CompositeAvailableCapacity_t : CompositeAvailableCapacity
	{
		static constexpr const char* name() {return "uL_CompositeAvailableCapacity_t";}
		using parent_t = CompositeAvailableCapacity;

	};
	uL_CompositeAvailableCapacity_t& ref_uL_CompositeAvailableCapacity() {return uL_CompositeAvailableCapacity;}
	uL_CompositeAvailableCapacity_t const& ref_uL_CompositeAvailableCapacity() const {return uL_CompositeAvailableCapacity;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CompositeAvailableCapacityGroup_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CompositeAvailableCapacityGroup_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(dL_CompositeAvailableCapacity);
		v(uL_CompositeAvailableCapacity);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(dL_CompositeAvailableCapacity);
		v(uL_CompositeAvailableCapacity);
		v(iE_Extensions);

	};
	void clear()
	{
		dL_CompositeAvailableCapacity.clear();
		uL_CompositeAvailableCapacity.clear();
		iE_Extensions.clear();

	};
	private:
	dL_CompositeAvailableCapacity_t	dL_CompositeAvailableCapacity;
	uL_CompositeAvailableCapacity_t	uL_CompositeAvailableCapacity;
	iE_Extensions_t	iE_Extensions;

};
/*
Correlation-ID ::= OCTET STRING (SIZE (4))
*/

struct Correlation_ID : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<4>>;
	static constexpr const char* name() {return "Correlation-ID";}
	using parent_t = asn::ostring<>;

};

/*
CoverageModification-Item ::= SEQUENCE {
	eCGI							ECGI,
	coverageState					INTEGER (0..15, ...),
	cellDeploymentStatusIndicator	CellDeploymentStatusIndicator			OPTIONAL,
	cellReplacingInfo				CellReplacingInfo						OPTIONAL,
-- Included in case the Cell Deployment Status Indicator IE is present
	...
}
*/

struct CoverageModification_Item : asn::sequence<4, 0, true, 2>
{
	static constexpr const char* name() {return "CoverageModification-Item";}
	using parent_t = asn::sequence<4, 0, true, 2>;
	struct eCGI_t : ECGI
	{
		static constexpr const char* name() {return "eCGI_t";}
		using parent_t = ECGI;

	};
	eCGI_t& ref_eCGI() {return eCGI;}
	eCGI_t const& ref_eCGI() const {return eCGI;}
	struct coverageState_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 15>>;
		static constexpr const char* name() {return "coverageState_t";}
		using parent_t = asn::integer<>;

	};

	coverageState_t& ref_coverageState() {return coverageState;}
	coverageState_t const& ref_coverageState() const {return coverageState;}
	struct cellDeploymentStatusIndicator_t : CellDeploymentStatusIndicator
	{
		static constexpr const char* name() {return "cellDeploymentStatusIndicator_t";}
		using parent_t = CellDeploymentStatusIndicator;
		static constexpr bool optional = true;

	};
	cellDeploymentStatusIndicator_t& set_cellDeploymentStatusIndicator() { cellDeploymentStatusIndicator.setpresent(true); return cellDeploymentStatusIndicator;}
	cellDeploymentStatusIndicator_t const* get_cellDeploymentStatusIndicator() const {return cellDeploymentStatusIndicator.is_valid() ? &cellDeploymentStatusIndicator : nullptr;}
	struct cellReplacingInfo_t : CellReplacingInfo
	{
		static constexpr const char* name() {return "cellReplacingInfo_t";}
		using parent_t = CellReplacingInfo;
		static constexpr bool optional = true;

	};
	cellReplacingInfo_t& set_cellReplacingInfo() { cellReplacingInfo.setpresent(true); return cellReplacingInfo;}
	cellReplacingInfo_t const* get_cellReplacingInfo() const {return cellReplacingInfo.is_valid() ? &cellReplacingInfo : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(eCGI);
		v(coverageState);
		v(cellDeploymentStatusIndicator);
		v(cellReplacingInfo);

	};
	template<typename V> void encode(V& v) const
	{
		v(eCGI);
		v(coverageState);
		v(cellDeploymentStatusIndicator);
		v(cellReplacingInfo);

	};
	void clear()
	{
		eCGI.clear();
		coverageState.clear();
		cellDeploymentStatusIndicator.clear();
		cellReplacingInfo.clear();

	};
	private:
	eCGI_t	eCGI;
	coverageState_t	coverageState;
	cellDeploymentStatusIndicator_t	cellDeploymentStatusIndicator;
	cellReplacingInfo_t	cellReplacingInfo;

};
/*
CoverageModificationList ::= SEQUENCE (SIZE (1..maxCellineNB)) OF CoverageModification-Item
*/

struct CoverageModificationList_elm : CoverageModification_Item
{
	static constexpr const char* name() {return "CoverageModificationList_elm";}
	using parent_t = CoverageModification_Item;

};
struct CoverageModificationList : asn::sequenceof<CoverageModificationList_elm>
{
	static constexpr const char* name() {return "CoverageModificationList";}
	using parent_t = asn::sequenceof<CoverageModificationList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCellineNB >>;

};
/*
TypeOfError ::= ENUMERATED {
	not-understood,
	missing,
	...
}
*/

struct TypeOfError : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "TypeOfError";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		not_understood
		,missing
	} index_t;

};

/*
CriticalityDiagnostics-IE-List-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CriticalityDiagnostics_IE_List_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CriticalityDiagnostics-IE-List ::= SEQUENCE (SIZE (1..maxNrOfErrors)) OF
	SEQUENCE {
		iECriticality			Criticality,
		iE-ID					ProtocolIE-ID,
		typeOfError				TypeOfError,
		iE-Extensions			ProtocolExtensionContainer { {CriticalityDiagnostics-IE-List-ExtIEs} } OPTIONAL,
		...
}
*/

struct CriticalityDiagnostics_IE_List_elm : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "CriticalityDiagnostics_IE_List_elm";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct iECriticality_t : Criticality
	{
		static constexpr const char* name() {return "iECriticality_t";}
		using parent_t = Criticality;

	};
	iECriticality_t& ref_iECriticality() {return iECriticality;}
	iECriticality_t const& ref_iECriticality() const {return iECriticality;}
	struct iE_ID_t : ProtocolIE_ID
	{
		static constexpr const char* name() {return "iE_ID_t";}
		using parent_t = ProtocolIE_ID;

	};
	iE_ID_t& ref_iE_ID() {return iE_ID;}
	iE_ID_t const& ref_iE_ID() const {return iE_ID;}
	struct typeOfError_t : TypeOfError
	{
		static constexpr const char* name() {return "typeOfError_t";}
		using parent_t = TypeOfError;

	};
	typeOfError_t& ref_typeOfError() {return typeOfError;}
	typeOfError_t const& ref_typeOfError() const {return typeOfError;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CriticalityDiagnostics_IE_List_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CriticalityDiagnostics_IE_List_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(iECriticality);
		v(iE_ID);
		v(typeOfError);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(iECriticality);
		v(iE_ID);
		v(typeOfError);
		v(iE_Extensions);

	};
	void clear()
	{
		iECriticality.clear();
		iE_ID.clear();
		typeOfError.clear();
		iE_Extensions.clear();

	};
	private:
	iECriticality_t	iECriticality;
	iE_ID_t	iE_ID;
	typeOfError_t	typeOfError;
	iE_Extensions_t	iE_Extensions;

};
struct CriticalityDiagnostics_IE_List : asn::sequenceof<CriticalityDiagnostics_IE_List_elm>
{
	static constexpr const char* name() {return "CriticalityDiagnostics-IE-List";}
	using parent_t = asn::sequenceof<CriticalityDiagnostics_IE_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxNrOfErrors >>;

};
/*
CriticalityDiagnostics-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct CriticalityDiagnostics_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
CriticalityDiagnostics ::= SEQUENCE {
	procedureCode					ProcedureCode					OPTIONAL,
	triggeringMessage				TriggeringMessage				OPTIONAL,
	procedureCriticality			Criticality						OPTIONAL,
	iEsCriticalityDiagnostics		CriticalityDiagnostics-IE-List	OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {CriticalityDiagnostics-ExtIEs} }	OPTIONAL,
	...
}
*/

struct CriticalityDiagnostics : asn::sequence<5, 0, true, 5>
{
	static constexpr const char* name() {return "CriticalityDiagnostics";}
	using parent_t = asn::sequence<5, 0, true, 5>;
	struct procedureCode_t : ProcedureCode
	{
		static constexpr const char* name() {return "procedureCode_t";}
		using parent_t = ProcedureCode;
		static constexpr bool optional = true;

	};
	procedureCode_t& set_procedureCode() { procedureCode.setpresent(true); return procedureCode;}
	procedureCode_t const* get_procedureCode() const {return procedureCode.is_valid() ? &procedureCode : nullptr;}
	struct triggeringMessage_t : TriggeringMessage
	{
		static constexpr const char* name() {return "triggeringMessage_t";}
		using parent_t = TriggeringMessage;
		static constexpr bool optional = true;

	};
	triggeringMessage_t& set_triggeringMessage() { triggeringMessage.setpresent(true); return triggeringMessage;}
	triggeringMessage_t const* get_triggeringMessage() const {return triggeringMessage.is_valid() ? &triggeringMessage : nullptr;}
	struct procedureCriticality_t : Criticality
	{
		static constexpr const char* name() {return "procedureCriticality_t";}
		using parent_t = Criticality;
		static constexpr bool optional = true;

	};
	procedureCriticality_t& set_procedureCriticality() { procedureCriticality.setpresent(true); return procedureCriticality;}
	procedureCriticality_t const* get_procedureCriticality() const {return procedureCriticality.is_valid() ? &procedureCriticality : nullptr;}
	struct iEsCriticalityDiagnostics_t : CriticalityDiagnostics_IE_List
	{
		static constexpr const char* name() {return "iEsCriticalityDiagnostics_t";}
		using parent_t = CriticalityDiagnostics_IE_List;
		static constexpr bool optional = true;

	};
	iEsCriticalityDiagnostics_t& set_iEsCriticalityDiagnostics() { iEsCriticalityDiagnostics.setpresent(true); return iEsCriticalityDiagnostics;}
	iEsCriticalityDiagnostics_t const* get_iEsCriticalityDiagnostics() const {return iEsCriticalityDiagnostics.is_valid() ? &iEsCriticalityDiagnostics : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<CriticalityDiagnostics_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<CriticalityDiagnostics_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(procedureCode);
		v(triggeringMessage);
		v(procedureCriticality);
		v(iEsCriticalityDiagnostics);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(procedureCode);
		v(triggeringMessage);
		v(procedureCriticality);
		v(iEsCriticalityDiagnostics);
		v(iE_Extensions);

	};
	void clear()
	{
		procedureCode.clear();
		triggeringMessage.clear();
		procedureCriticality.clear();
		iEsCriticalityDiagnostics.clear();
		iE_Extensions.clear();

	};
	private:
	procedureCode_t	procedureCode;
	triggeringMessage_t	triggeringMessage;
	procedureCriticality_t	procedureCriticality;
	iEsCriticalityDiagnostics_t	iEsCriticalityDiagnostics;
	iE_Extensions_t	iE_Extensions;

};
/*
DL-Forwarding ::= ENUMERATED {
	dL-forwardingProposed,
	...
}
*/

struct DL_Forwarding : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "DL-Forwarding";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		dL_forwardingProposed
	} index_t;

};

/*
DL-GBR-PRB-usage::= INTEGER (0..100)
*/

struct DL_GBR_PRB_usage : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 100>>;
	static constexpr const char* name() {return "DL-GBR-PRB-usage";}
	using parent_t = asn::integer<>;

};

/*
DL-Total-PRB-usage::= INTEGER (0..100)
*/

struct DL_Total_PRB_usage : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 100>>;
	static constexpr const char* name() {return "DL-Total-PRB-usage";}
	using parent_t = asn::integer<>;

};

/*
DL-non-GBR-PRB-usage::= INTEGER (0..100)
*/

struct DL_non_GBR_PRB_usage : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 100>>;
	static constexpr const char* name() {return "DL-non-GBR-PRB-usage";}
	using parent_t = asn::integer<>;

};

/*
DL-scheduling-PDCCH-CCE-usage::= INTEGER (0..100)
*/

struct DL_scheduling_PDCCH_CCE_usage : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 100>>;
	static constexpr const char* name() {return "DL-scheduling-PDCCH-CCE-usage";}
	using parent_t = asn::integer<>;

};

/*
DataTrafficResources ::= BIT STRING (SIZE(6..17600))
*/

struct DataTrafficResources : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::span<6, 17600>>;
	static constexpr const char* name() {return "DataTrafficResources";}
	using parent_t = asn::bstring<>;

};

/*
DLResourceBitmapULandDLSharing ::= DataTrafficResources
*/

struct DLResourceBitmapULandDLSharing : DataTrafficResources
{
	static constexpr const char* name() {return "DLResourceBitmapULandDLSharing";}
	using parent_t = DataTrafficResources;

};
/*
DLResourcesULandDLSharing ::= CHOICE {
unchanged			NULL,
	changed				DLResourceBitmapULandDLSharing,
	...
}
*/

struct DLResourcesULandDLSharing : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "DLResourcesULandDLSharing";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~DLResourcesULandDLSharing() {clear();}
	struct unchanged_t : asn::nulltype
	{
		static constexpr const char* name() {return "unchanged_t";}
		using parent_t = asn::nulltype;

	};
	struct changed_t : DLResourceBitmapULandDLSharing
	{
		static constexpr const char* name() {return "changed_t";}
		using parent_t = DLResourceBitmapULandDLSharing;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<unchanged_t>(); break;
		case 2: var.destroy<changed_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<unchanged_t>());
		case 2: set_index(2); return v(var.build<changed_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<unchanged_t>());
		case 2: return v(var.as<changed_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<unchanged_t>(1);
		v.template operator()<changed_t>(2);

	}
	unchanged_t& select_unchanged() { if(get_index() != 1) { clear(); set_index(1); return var.build<unchanged_t>();} return var.as<unchanged_t>();}
	unchanged_t const* get_unchanged() const { if(get_index() == 1) { return &var.as<unchanged_t>();} return nullptr; }
	changed_t& select_changed() { if(get_index() != 2) { clear(); set_index(2); return var.build<changed_t>();} return var.as<changed_t>();}
	changed_t const* get_changed() const { if(get_index() == 2) { return &var.as<changed_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(unchanged_t)];
		char dummy2[sizeof(changed_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
DRB-ID ::= INTEGER (1..32)
*/

struct DRB_ID : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<1, 32>>;
	static constexpr const char* name() {return "DRB-ID";}
	using parent_t = asn::integer<>;

};

/*
ULOnlySharing-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ULOnlySharing_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ULOnlySharing ::= SEQUENCE{
	uLResourceBitmapULOnlySharing	DataTrafficResources,
	iE-Extensions					ProtocolExtensionContainer { {ULOnlySharing-ExtIEs} }				OPTIONAL,
	...
}
*/

struct ULOnlySharing : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "ULOnlySharing";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct uLResourceBitmapULOnlySharing_t : DataTrafficResources
	{
		static constexpr const char* name() {return "uLResourceBitmapULOnlySharing_t";}
		using parent_t = DataTrafficResources;

	};
	uLResourceBitmapULOnlySharing_t& ref_uLResourceBitmapULOnlySharing() {return uLResourceBitmapULOnlySharing;}
	uLResourceBitmapULOnlySharing_t const& ref_uLResourceBitmapULOnlySharing() const {return uLResourceBitmapULOnlySharing;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ULOnlySharing_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ULOnlySharing_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(uLResourceBitmapULOnlySharing);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(uLResourceBitmapULOnlySharing);
		v(iE_Extensions);

	};
	void clear()
	{
		uLResourceBitmapULOnlySharing.clear();
		iE_Extensions.clear();

	};
	private:
	uLResourceBitmapULOnlySharing_t	uLResourceBitmapULOnlySharing;
	iE_Extensions_t	iE_Extensions;

};
/*
ULResourceBitmapULandDLSharing ::= DataTrafficResources
*/

struct ULResourceBitmapULandDLSharing : DataTrafficResources
{
	static constexpr const char* name() {return "ULResourceBitmapULandDLSharing";}
	using parent_t = DataTrafficResources;

};
/*
ULResourcesULandDLSharing ::= CHOICE {
	unchanged			NULL,
	changed				ULResourceBitmapULandDLSharing,
	...
}
*/

struct ULResourcesULandDLSharing : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "ULResourcesULandDLSharing";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~ULResourcesULandDLSharing() {clear();}
	struct unchanged_t : asn::nulltype
	{
		static constexpr const char* name() {return "unchanged_t";}
		using parent_t = asn::nulltype;

	};
	struct changed_t : ULResourceBitmapULandDLSharing
	{
		static constexpr const char* name() {return "changed_t";}
		using parent_t = ULResourceBitmapULandDLSharing;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<unchanged_t>(); break;
		case 2: var.destroy<changed_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<unchanged_t>());
		case 2: set_index(2); return v(var.build<changed_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<unchanged_t>());
		case 2: return v(var.as<changed_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<unchanged_t>(1);
		v.template operator()<changed_t>(2);

	}
	unchanged_t& select_unchanged() { if(get_index() != 1) { clear(); set_index(1); return var.build<unchanged_t>();} return var.as<unchanged_t>();}
	unchanged_t const* get_unchanged() const { if(get_index() == 1) { return &var.as<unchanged_t>();} return nullptr; }
	changed_t& select_changed() { if(get_index() != 2) { clear(); set_index(2); return var.build<changed_t>();} return var.as<changed_t>();}
	changed_t const* get_changed() const { if(get_index() == 2) { return &var.as<changed_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(unchanged_t)];
		char dummy2[sizeof(changed_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
ULandDLSharing-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ULandDLSharing_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ULandDLSharing ::= SEQUENCE{
	uLResourcesULandDLSharing				ULResourcesULandDLSharing,
	dLResourcesULandDLSharing				DLResourcesULandDLSharing,
	iE-Extensions			ProtocolExtensionContainer { {ULandDLSharing-ExtIEs} }				OPTIONAL,
	...
}
*/

struct ULandDLSharing : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "ULandDLSharing";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct uLResourcesULandDLSharing_t : ULResourcesULandDLSharing
	{
		static constexpr const char* name() {return "uLResourcesULandDLSharing_t";}
		using parent_t = ULResourcesULandDLSharing;

	};
	uLResourcesULandDLSharing_t& ref_uLResourcesULandDLSharing() {return uLResourcesULandDLSharing;}
	uLResourcesULandDLSharing_t const& ref_uLResourcesULandDLSharing() const {return uLResourcesULandDLSharing;}
	struct dLResourcesULandDLSharing_t : DLResourcesULandDLSharing
	{
		static constexpr const char* name() {return "dLResourcesULandDLSharing_t";}
		using parent_t = DLResourcesULandDLSharing;

	};
	dLResourcesULandDLSharing_t& ref_dLResourcesULandDLSharing() {return dLResourcesULandDLSharing;}
	dLResourcesULandDLSharing_t const& ref_dLResourcesULandDLSharing() const {return dLResourcesULandDLSharing;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ULandDLSharing_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ULandDLSharing_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(uLResourcesULandDLSharing);
		v(dLResourcesULandDLSharing);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(uLResourcesULandDLSharing);
		v(dLResourcesULandDLSharing);
		v(iE_Extensions);

	};
	void clear()
	{
		uLResourcesULandDLSharing.clear();
		dLResourcesULandDLSharing.clear();
		iE_Extensions.clear();

	};
	private:
	uLResourcesULandDLSharing_t	uLResourcesULandDLSharing;
	dLResourcesULandDLSharing_t	dLResourcesULandDLSharing;
	iE_Extensions_t	iE_Extensions;

};
/*
SharedResourceType ::= CHOICE{
	uLOnlySharing		ULOnlySharing,
	uLandDLSharing		ULandDLSharing,
	...
}
*/

struct SharedResourceType : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "SharedResourceType";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~SharedResourceType() {clear();}
	struct uLOnlySharing_t : ULOnlySharing
	{
		static constexpr const char* name() {return "uLOnlySharing_t";}
		using parent_t = ULOnlySharing;

	};
	struct uLandDLSharing_t : ULandDLSharing
	{
		static constexpr const char* name() {return "uLandDLSharing_t";}
		using parent_t = ULandDLSharing;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<uLOnlySharing_t>(); break;
		case 2: var.destroy<uLandDLSharing_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<uLOnlySharing_t>());
		case 2: set_index(2); return v(var.build<uLandDLSharing_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<uLOnlySharing_t>());
		case 2: return v(var.as<uLandDLSharing_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<uLOnlySharing_t>(1);
		v.template operator()<uLandDLSharing_t>(2);

	}
	uLOnlySharing_t& select_uLOnlySharing() { if(get_index() != 1) { clear(); set_index(1); return var.build<uLOnlySharing_t>();} return var.as<uLOnlySharing_t>();}
	uLOnlySharing_t const* get_uLOnlySharing() const { if(get_index() == 1) { return &var.as<uLOnlySharing_t>();} return nullptr; }
	uLandDLSharing_t& select_uLandDLSharing() { if(get_index() != 2) { clear(); set_index(2); return var.build<uLandDLSharing_t>();} return var.as<uLandDLSharing_t>();}
	uLandDLSharing_t const* get_uLandDLSharing() const { if(get_index() == 2) { return &var.as<uLandDLSharing_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(uLOnlySharing_t)];
		char dummy2[sizeof(uLandDLSharing_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
SubframeType ::= ENUMERATED{mbsfn,nonmbsfn,...}
*/

struct SubframeType : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "SubframeType";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		mbsfn
		,nonmbsfn
	} index_t;

};

/*
ReservedSubframePattern-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ReservedSubframePattern_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ReservedSubframePattern ::= SEQUENCE{
	subframeType					SubframeType,
	reservedSubframePattern			BIT STRING (SIZE(10..160)),
	mBSFNControlRegionLength		INTEGER (0..3),
	iE-Extensions					ProtocolExtensionContainer { {ReservedSubframePattern-ExtIEs} }	OPTIONAL,
	...
}
*/

struct ReservedSubframePattern : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "ReservedSubframePattern";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct subframeType_t : SubframeType
	{
		static constexpr const char* name() {return "subframeType_t";}
		using parent_t = SubframeType;

	};
	subframeType_t& ref_subframeType() {return subframeType;}
	subframeType_t const& ref_subframeType() const {return subframeType;}
	struct reservedSubframePattern_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::span<10, 160>>;
		static constexpr const char* name() {return "reservedSubframePattern_t";}
		using parent_t = asn::bstring<>;

	};

	reservedSubframePattern_t& ref_reservedSubframePattern() {return reservedSubframePattern;}
	reservedSubframePattern_t const& ref_reservedSubframePattern() const {return reservedSubframePattern;}
	struct mBSFNControlRegionLength_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 3>>;
		static constexpr const char* name() {return "mBSFNControlRegionLength_t";}
		using parent_t = asn::integer<>;

	};

	mBSFNControlRegionLength_t& ref_mBSFNControlRegionLength() {return mBSFNControlRegionLength;}
	mBSFNControlRegionLength_t const& ref_mBSFNControlRegionLength() const {return mBSFNControlRegionLength;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ReservedSubframePattern_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ReservedSubframePattern_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(subframeType);
		v(reservedSubframePattern);
		v(mBSFNControlRegionLength);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(subframeType);
		v(reservedSubframePattern);
		v(mBSFNControlRegionLength);
		v(iE_Extensions);

	};
	void clear()
	{
		subframeType.clear();
		reservedSubframePattern.clear();
		mBSFNControlRegionLength.clear();
		iE_Extensions.clear();

	};
	private:
	subframeType_t	subframeType;
	reservedSubframePattern_t	reservedSubframePattern;
	mBSFNControlRegionLength_t	mBSFNControlRegionLength;
	iE_Extensions_t	iE_Extensions;

};
/*
DataTrafficResourceIndication-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct DataTrafficResourceIndication_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
DataTrafficResourceIndication ::= SEQUENCE {
	activationSFN					INTEGER (0..1023),
	sharedResourceType				SharedResourceType,
	reservedSubframePattern 		ReservedSubframePattern OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {DataTrafficResourceIndication-ExtIEs} } OPTIONAL,
...
}
*/

struct DataTrafficResourceIndication : asn::sequence<4, 0, true, 2>
{
	static constexpr const char* name() {return "DataTrafficResourceIndication";}
	using parent_t = asn::sequence<4, 0, true, 2>;
	struct activationSFN_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 1023>>;
		static constexpr const char* name() {return "activationSFN_t";}
		using parent_t = asn::integer<>;

	};

	activationSFN_t& ref_activationSFN() {return activationSFN;}
	activationSFN_t const& ref_activationSFN() const {return activationSFN;}
	struct sharedResourceType_t : SharedResourceType
	{
		static constexpr const char* name() {return "sharedResourceType_t";}
		using parent_t = SharedResourceType;

	};
	sharedResourceType_t& ref_sharedResourceType() {return sharedResourceType;}
	sharedResourceType_t const& ref_sharedResourceType() const {return sharedResourceType;}
	struct reservedSubframePattern_t : ReservedSubframePattern
	{
		static constexpr const char* name() {return "reservedSubframePattern_t";}
		using parent_t = ReservedSubframePattern;
		static constexpr bool optional = true;

	};
	reservedSubframePattern_t& set_reservedSubframePattern() { reservedSubframePattern.setpresent(true); return reservedSubframePattern;}
	reservedSubframePattern_t const* get_reservedSubframePattern() const {return reservedSubframePattern.is_valid() ? &reservedSubframePattern : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<DataTrafficResourceIndication_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<DataTrafficResourceIndication_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(activationSFN);
		v(sharedResourceType);
		v(reservedSubframePattern);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(activationSFN);
		v(sharedResourceType);
		v(reservedSubframePattern);
		v(iE_Extensions);

	};
	void clear()
	{
		activationSFN.clear();
		sharedResourceType.clear();
		reservedSubframePattern.clear();
		iE_Extensions.clear();

	};
	private:
	activationSFN_t	activationSFN;
	sharedResourceType_t	sharedResourceType;
	reservedSubframePattern_t	reservedSubframePattern;
	iE_Extensions_t	iE_Extensions;

};
/*
DeactivationIndication::= ENUMERATED {
	deactivated,
	...
}
*/

struct DeactivationIndication : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "DeactivationIndication";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		deactivated
	} index_t;

};

/*
DeliveryStatus-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct DeliveryStatus_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
DeliveryStatus ::= SEQUENCE {
	highestSuccessDeliveredPDCPSN		INTEGER (0..4095),
	iE-Extensions		ProtocolExtensionContainer { {DeliveryStatus-ExtIEs} } OPTIONAL,
	...
}
*/

struct DeliveryStatus : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "DeliveryStatus";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct highestSuccessDeliveredPDCPSN_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 4095>>;
		static constexpr const char* name() {return "highestSuccessDeliveredPDCPSN_t";}
		using parent_t = asn::integer<>;

	};

	highestSuccessDeliveredPDCPSN_t& ref_highestSuccessDeliveredPDCPSN() {return highestSuccessDeliveredPDCPSN;}
	highestSuccessDeliveredPDCPSN_t const& ref_highestSuccessDeliveredPDCPSN() const {return highestSuccessDeliveredPDCPSN;}
	struct iE_Extensions_t : ProtocolExtensionContainer<DeliveryStatus_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<DeliveryStatus_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(highestSuccessDeliveredPDCPSN);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(highestSuccessDeliveredPDCPSN);
		v(iE_Extensions);

	};
	void clear()
	{
		highestSuccessDeliveredPDCPSN.clear();
		iE_Extensions.clear();

	};
	private:
	highestSuccessDeliveredPDCPSN_t	highestSuccessDeliveredPDCPSN;
	iE_Extensions_t	iE_Extensions;

};
/*
DuplicationActivation::= ENUMERATED {active, inactive, ...}
*/

struct DuplicationActivation : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "DuplicationActivation";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		active
		,inactive
	} index_t;

};

/*
PA-Values ::= ENUMERATED {
	dB-6,
	dB-4dot77,
	dB-3,
	dB-1dot77,
	dB0,
	dB1,
	dB2,
	dB3,
	...
}
*/

struct PA_Values : asn::enumerated<8, 0, true>
{
	static constexpr const char* name() {return "PA-Values";}
	using parent_t = asn::enumerated<8, 0, true>;
	typedef enum {
		dB_6
		,dB_4dot77
		,dB_3
		,dB_1dot77
		,dB0
		,dB1
		,dB2
		,dB3
	} index_t;

};

/*
DynamicNAICSInformation-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct DynamicNAICSInformation_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
DynamicNAICSInformation ::= SEQUENCE {
	transmissionModes					BIT STRING (SIZE(8))												OPTIONAL,
	pB-information						INTEGER(0..3)														OPTIONAL,
	pA-list								SEQUENCE (SIZE(0..maxnoofPA)) OF PA-Values,
	iE-Extensions						ProtocolExtensionContainer { {DynamicNAICSInformation-ExtIEs} } OPTIONAL,
	...
}
*/

struct DynamicNAICSInformation : asn::sequence<4, 0, true, 3>
{
	static constexpr const char* name() {return "DynamicNAICSInformation";}
	using parent_t = asn::sequence<4, 0, true, 3>;
	struct transmissionModes_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<8>>;
		static constexpr const char* name() {return "transmissionModes_t";}
		using parent_t = asn::bstring<>;
		static constexpr bool optional = true;

	};

	transmissionModes_t& set_transmissionModes() { transmissionModes.setpresent(true); return transmissionModes;}
	transmissionModes_t const* get_transmissionModes() const {return transmissionModes.is_valid() ? &transmissionModes : nullptr;}
	struct pB_information_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 3>>;
		static constexpr const char* name() {return "pB_information_t";}
		using parent_t = asn::integer<>;
		static constexpr bool optional = true;

	};

	pB_information_t& set_pB_information() { pB_information.setpresent(true); return pB_information;}
	pB_information_t const* get_pB_information() const {return pB_information.is_valid() ? &pB_information : nullptr;}
	struct pA_list_t_elm : PA_Values
	{
		static constexpr const char* name() {return "pA_list_t_elm";}
		using parent_t = PA_Values;

	};
	struct pA_list_t : asn::sequenceof<pA_list_t_elm>
	{
		static constexpr const char* name() {return "pA_list_t";}
		using parent_t = asn::sequenceof<pA_list_t_elm>;
		using constraint_t = asn::constraints<false,asn::span<0,  maxnoofPA >>;

	};
	pA_list_t& ref_pA_list() {return pA_list;}
	pA_list_t const& ref_pA_list() const {return pA_list;}
	struct iE_Extensions_t : ProtocolExtensionContainer<DynamicNAICSInformation_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<DynamicNAICSInformation_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(transmissionModes);
		v(pB_information);
		v(pA_list);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(transmissionModes);
		v(pB_information);
		v(pA_list);
		v(iE_Extensions);

	};
	void clear()
	{
		transmissionModes.clear();
		pB_information.clear();
		pA_list.clear();
		iE_Extensions.clear();

	};
	private:
	transmissionModes_t	transmissionModes;
	pB_information_t	pB_information;
	pA_list_t	pA_list;
	iE_Extensions_t	iE_Extensions;

};
/*
DynamicDLTransmissionInformation ::= CHOICE {
	naics-active			DynamicNAICSInformation,
	naics-inactive			NULL,
	...
}
*/

struct DynamicDLTransmissionInformation : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "DynamicDLTransmissionInformation";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~DynamicDLTransmissionInformation() {clear();}
	struct naics_active_t : DynamicNAICSInformation
	{
		static constexpr const char* name() {return "naics_active_t";}
		using parent_t = DynamicNAICSInformation;

	};
	struct naics_inactive_t : asn::nulltype
	{
		static constexpr const char* name() {return "naics_inactive_t";}
		using parent_t = asn::nulltype;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<naics_active_t>(); break;
		case 2: var.destroy<naics_inactive_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<naics_active_t>());
		case 2: set_index(2); return v(var.build<naics_inactive_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<naics_active_t>());
		case 2: return v(var.as<naics_inactive_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<naics_active_t>(1);
		v.template operator()<naics_inactive_t>(2);

	}
	naics_active_t& select_naics_active() { if(get_index() != 1) { clear(); set_index(1); return var.build<naics_active_t>();} return var.as<naics_active_t>();}
	naics_active_t const* get_naics_active() const { if(get_index() == 1) { return &var.as<naics_active_t>();} return nullptr; }
	naics_inactive_t& select_naics_inactive() { if(get_index() != 2) { clear(); set_index(2); return var.build<naics_inactive_t>();} return var.as<naics_inactive_t>();}
	naics_inactive_t const* get_naics_inactive() const { if(get_index() == 2) { return &var.as<naics_inactive_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(naics_active_t)];
		char dummy2[sizeof(naics_inactive_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
E-RAB-ID ::= INTEGER (0..15, ...)
*/

struct E_RAB_ID : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<0, 15>>;
	static constexpr const char* name() {return "E-RAB-ID";}
	using parent_t = asn::integer<>;

};

/*
E-RAB-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RAB_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RAB-Item ::= SEQUENCE {
	e-RAB-ID				E-RAB-ID,
	cause						Cause,
	iE-Extensions				ProtocolExtensionContainer { {E-RAB-Item-ExtIEs} } OPTIONAL,
	...
}
*/

struct E_RAB_Item : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "E-RAB-Item";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct cause_t : Cause
	{
		static constexpr const char* name() {return "cause_t";}
		using parent_t = Cause;

	};
	cause_t& ref_cause() {return cause;}
	cause_t const& ref_cause() const {return cause;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RAB_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RAB_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(cause);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(cause);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		cause.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	cause_t	cause;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RAB-ItemIEs 	X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RAB-Item	 CRITICALITY ignore 	TYPE E-RAB-Item 	PRESENCE mandatory },
	...
}
*/

struct E_RAB_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RAB_Item() { set(id_E_RAB_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RAB_Item)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RAB_Item);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RAB_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RAB_Item& select_id_E_RAB_Item() { return set<E_RAB_Item>(1); }
		E_RAB_Item const* get_id_E_RAB_Item() const { return get<E_RAB_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RAB_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RAB_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RAB_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RAB_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RAB_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RAB_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
QCI ::= INTEGER (0..255)
*/

struct QCI : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 255>>;
	static constexpr const char* name() {return "QCI";}
	using parent_t = asn::integer<>;

};

/*
ExtendedBitRate	::= INTEGER (10000000001..4000000000000,...)
*/

struct ExtendedBitRate : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<10000000001, 4000000000000>>;
	static constexpr const char* name() {return "ExtendedBitRate";}
	using parent_t = asn::integer<>;

};

/*
GBR-QosInformation-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
-- Extension for maximum bitrate > 10Gbps --
	{ ID id-extended-e-RAB-MaximumBitrateDL		CRITICALITY ignore	EXTENSION ExtendedBitRate	PRESENCE optional}|
	{ ID id-extended-e-RAB-MaximumBitrateUL		CRITICALITY ignore	EXTENSION ExtendedBitRate	PRESENCE optional}|
	{ ID id-extended-e-RAB-GuaranteedBitrateDL	CRITICALITY ignore	EXTENSION ExtendedBitRate	PRESENCE optional}|
	{ ID id-extended-e-RAB-GuaranteedBitrateUL	CRITICALITY ignore	EXTENSION ExtendedBitRate	PRESENCE optional},
	...
}
*/

struct GBR_QosInformation_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_extended_e_RAB_MaximumBitrateDL() { set(id_extended_e_RAB_MaximumBitrateDL); type=1;}
		void select_id_extended_e_RAB_MaximumBitrateUL() { set(id_extended_e_RAB_MaximumBitrateUL); type=2;}
		void select_id_extended_e_RAB_GuaranteedBitrateDL() { set(id_extended_e_RAB_GuaranteedBitrateDL); type=3;}
		void select_id_extended_e_RAB_GuaranteedBitrateUL() { set(id_extended_e_RAB_GuaranteedBitrateUL); type=4;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_extended_e_RAB_MaximumBitrateDL)) { type = 1; return true; }
			else if(equal(id_extended_e_RAB_MaximumBitrateUL)) { type = 2; return true; }
			else if(equal(id_extended_e_RAB_GuaranteedBitrateDL)) { type = 3; return true; }
			else if(equal(id_extended_e_RAB_GuaranteedBitrateUL)) { type = 4; return true; }
			else { type = 5; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_extended_e_RAB_MaximumBitrateDL);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_extended_e_RAB_MaximumBitrateUL);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_extended_e_RAB_GuaranteedBitrateDL);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_extended_e_RAB_GuaranteedBitrateUL);} return false;
			case 5: type = 5; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_extended_e_RAB_MaximumBitrateDL() { set(ignore); type=1;}
		void select_id_extended_e_RAB_MaximumBitrateUL() { set(ignore); type=2;}
		void select_id_extended_e_RAB_GuaranteedBitrateDL() { set(ignore); type=3;}
		void select_id_extended_e_RAB_GuaranteedBitrateUL() { set(ignore); type=4;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else if(equal(ignore)) { type = 3; return true; }
			else if(equal(ignore)) { type = 4; return true; }
			else { type = 5; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(ignore);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(ignore);} return false;
			case 5: type = 5; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		ExtendedBitRate& select_id_extended_e_RAB_MaximumBitrateDL() { return set<ExtendedBitRate>(1); }
		ExtendedBitRate const* get_id_extended_e_RAB_MaximumBitrateDL() const { return get<ExtendedBitRate>(1); }
		ExtendedBitRate& select_id_extended_e_RAB_MaximumBitrateUL() { return set<ExtendedBitRate>(2); }
		ExtendedBitRate const* get_id_extended_e_RAB_MaximumBitrateUL() const { return get<ExtendedBitRate>(2); }
		ExtendedBitRate& select_id_extended_e_RAB_GuaranteedBitrateDL() { return set<ExtendedBitRate>(3); }
		ExtendedBitRate const* get_id_extended_e_RAB_GuaranteedBitrateDL() const { return get<ExtendedBitRate>(3); }
		ExtendedBitRate& select_id_extended_e_RAB_GuaranteedBitrateUL() { return set<ExtendedBitRate>(4); }
		ExtendedBitRate const* get_id_extended_e_RAB_GuaranteedBitrateUL() const { return get<ExtendedBitRate>(4); }
		bool is_unknown() const { return type == 5; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<ExtendedBitRate>(); break;
			case 2: var.destroy<ExtendedBitRate>(); break;
			case 3: var.destroy<ExtendedBitRate>(); break;
			case 4: var.destroy<ExtendedBitRate>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<ExtendedBitRate>(1);
			v.template operator()<ExtendedBitRate>(2);
			v.template operator()<ExtendedBitRate>(3);
			v.template operator()<ExtendedBitRate>(4);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_extended_e_RAB_MaximumBitrateDL()); return true;
			case 2: v(select_id_extended_e_RAB_MaximumBitrateUL()); return true;
			case 3: v(select_id_extended_e_RAB_GuaranteedBitrateDL()); return true;
			case 4: v(select_id_extended_e_RAB_GuaranteedBitrateUL()); return true;
			case 5: if(type != 5) {clear(); asn::base::set();} type = 5; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<ExtendedBitRate>()); return true;
			case 2: v(var.as<ExtendedBitRate>()); return true;
			case 3: v(var.as<ExtendedBitRate>()); return true;
			case 4: v(var.as<ExtendedBitRate>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(ExtendedBitRate)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_extended_e_RAB_MaximumBitrateDL() { set(optional); type=1;}
		void select_id_extended_e_RAB_MaximumBitrateUL() { set(optional); type=2;}
		void select_id_extended_e_RAB_GuaranteedBitrateDL() { set(optional); type=3;}
		void select_id_extended_e_RAB_GuaranteedBitrateUL() { set(optional); type=4;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else if(equal(optional)) { type = 3; return true; }
			else if(equal(optional)) { type = 4; return true; }
			else { type = 5; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(optional);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(optional);} return false;
			case 5: type = 5; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
GBR-QosInformation ::= SEQUENCE {
	e-RAB-MaximumBitrateDL			BitRate,
	e-RAB-MaximumBitrateUL			BitRate,
	e-RAB-GuaranteedBitrateDL		BitRate,
	e-RAB-GuaranteedBitrateUL		BitRate,
	iE-Extensions					ProtocolExtensionContainer { {GBR-QosInformation-ExtIEs} } OPTIONAL,
	...
}
*/

struct GBR_QosInformation : asn::sequence<5, 0, true, 1>
{
	static constexpr const char* name() {return "GBR-QosInformation";}
	using parent_t = asn::sequence<5, 0, true, 1>;
	struct e_RAB_MaximumBitrateDL_t : BitRate
	{
		static constexpr const char* name() {return "e_RAB_MaximumBitrateDL_t";}
		using parent_t = BitRate;

	};
	e_RAB_MaximumBitrateDL_t& ref_e_RAB_MaximumBitrateDL() {return e_RAB_MaximumBitrateDL;}
	e_RAB_MaximumBitrateDL_t const& ref_e_RAB_MaximumBitrateDL() const {return e_RAB_MaximumBitrateDL;}
	struct e_RAB_MaximumBitrateUL_t : BitRate
	{
		static constexpr const char* name() {return "e_RAB_MaximumBitrateUL_t";}
		using parent_t = BitRate;

	};
	e_RAB_MaximumBitrateUL_t& ref_e_RAB_MaximumBitrateUL() {return e_RAB_MaximumBitrateUL;}
	e_RAB_MaximumBitrateUL_t const& ref_e_RAB_MaximumBitrateUL() const {return e_RAB_MaximumBitrateUL;}
	struct e_RAB_GuaranteedBitrateDL_t : BitRate
	{
		static constexpr const char* name() {return "e_RAB_GuaranteedBitrateDL_t";}
		using parent_t = BitRate;

	};
	e_RAB_GuaranteedBitrateDL_t& ref_e_RAB_GuaranteedBitrateDL() {return e_RAB_GuaranteedBitrateDL;}
	e_RAB_GuaranteedBitrateDL_t const& ref_e_RAB_GuaranteedBitrateDL() const {return e_RAB_GuaranteedBitrateDL;}
	struct e_RAB_GuaranteedBitrateUL_t : BitRate
	{
		static constexpr const char* name() {return "e_RAB_GuaranteedBitrateUL_t";}
		using parent_t = BitRate;

	};
	e_RAB_GuaranteedBitrateUL_t& ref_e_RAB_GuaranteedBitrateUL() {return e_RAB_GuaranteedBitrateUL;}
	e_RAB_GuaranteedBitrateUL_t const& ref_e_RAB_GuaranteedBitrateUL() const {return e_RAB_GuaranteedBitrateUL;}
	struct iE_Extensions_t : ProtocolExtensionContainer<GBR_QosInformation_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<GBR_QosInformation_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_MaximumBitrateDL);
		v(e_RAB_MaximumBitrateUL);
		v(e_RAB_GuaranteedBitrateDL);
		v(e_RAB_GuaranteedBitrateUL);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_MaximumBitrateDL);
		v(e_RAB_MaximumBitrateUL);
		v(e_RAB_GuaranteedBitrateDL);
		v(e_RAB_GuaranteedBitrateUL);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_MaximumBitrateDL.clear();
		e_RAB_MaximumBitrateUL.clear();
		e_RAB_GuaranteedBitrateDL.clear();
		e_RAB_GuaranteedBitrateUL.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_MaximumBitrateDL_t	e_RAB_MaximumBitrateDL;
	e_RAB_MaximumBitrateUL_t	e_RAB_MaximumBitrateUL;
	e_RAB_GuaranteedBitrateDL_t	e_RAB_GuaranteedBitrateDL;
	e_RAB_GuaranteedBitrateUL_t	e_RAB_GuaranteedBitrateUL;
	iE_Extensions_t	iE_Extensions;

};
/*
Packet-LossRate	::= INTEGER(0..1000)
*/

struct Packet_LossRate : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 1000>>;
	static constexpr const char* name() {return "Packet-LossRate";}
	using parent_t = asn::integer<>;

};

/*
E-RAB-Level-QoS-Parameters-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
-- Extended for introduction of downlink and uplink packet loss rate for enhanced Voice performance –
	{ ID id-DownlinkPacketLossRate			CRITICALITY ignore	EXTENSION Packet-LossRate		PRESENCE optional}|
	{ ID id-UplinkPacketLossRate			CRITICALITY ignore	EXTENSION Packet-LossRate		PRESENCE optional},
	...
}
*/

struct E_RAB_Level_QoS_Parameters_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_DownlinkPacketLossRate() { set(id_DownlinkPacketLossRate); type=1;}
		void select_id_UplinkPacketLossRate() { set(id_UplinkPacketLossRate); type=2;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_DownlinkPacketLossRate)) { type = 1; return true; }
			else if(equal(id_UplinkPacketLossRate)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_DownlinkPacketLossRate);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_UplinkPacketLossRate);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_DownlinkPacketLossRate() { set(ignore); type=1;}
		void select_id_UplinkPacketLossRate() { set(ignore); type=2;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		Packet_LossRate& select_id_DownlinkPacketLossRate() { return set<Packet_LossRate>(1); }
		Packet_LossRate const* get_id_DownlinkPacketLossRate() const { return get<Packet_LossRate>(1); }
		Packet_LossRate& select_id_UplinkPacketLossRate() { return set<Packet_LossRate>(2); }
		Packet_LossRate const* get_id_UplinkPacketLossRate() const { return get<Packet_LossRate>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<Packet_LossRate>(); break;
			case 2: var.destroy<Packet_LossRate>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<Packet_LossRate>(1);
			v.template operator()<Packet_LossRate>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_DownlinkPacketLossRate()); return true;
			case 2: v(select_id_UplinkPacketLossRate()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<Packet_LossRate>()); return true;
			case 2: v(var.as<Packet_LossRate>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(Packet_LossRate)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_DownlinkPacketLossRate() { set(optional); type=1;}
		void select_id_UplinkPacketLossRate() { set(optional); type=2;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RAB-Level-QoS-Parameters ::= SEQUENCE {
	qCI								QCI,
	allocationAndRetentionPriority	AllocationAndRetentionPriority,
	gbrQosInformation				GBR-QosInformation													OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {E-RAB-Level-QoS-Parameters-ExtIEs} }	OPTIONAL,
	...
}
*/

struct E_RAB_Level_QoS_Parameters : asn::sequence<4, 0, true, 2>
{
	static constexpr const char* name() {return "E-RAB-Level-QoS-Parameters";}
	using parent_t = asn::sequence<4, 0, true, 2>;
	struct qCI_t : QCI
	{
		static constexpr const char* name() {return "qCI_t";}
		using parent_t = QCI;

	};
	qCI_t& ref_qCI() {return qCI;}
	qCI_t const& ref_qCI() const {return qCI;}
	struct allocationAndRetentionPriority_t : AllocationAndRetentionPriority
	{
		static constexpr const char* name() {return "allocationAndRetentionPriority_t";}
		using parent_t = AllocationAndRetentionPriority;

	};
	allocationAndRetentionPriority_t& ref_allocationAndRetentionPriority() {return allocationAndRetentionPriority;}
	allocationAndRetentionPriority_t const& ref_allocationAndRetentionPriority() const {return allocationAndRetentionPriority;}
	struct gbrQosInformation_t : GBR_QosInformation
	{
		static constexpr const char* name() {return "gbrQosInformation_t";}
		using parent_t = GBR_QosInformation;
		static constexpr bool optional = true;

	};
	gbrQosInformation_t& set_gbrQosInformation() { gbrQosInformation.setpresent(true); return gbrQosInformation;}
	gbrQosInformation_t const* get_gbrQosInformation() const {return gbrQosInformation.is_valid() ? &gbrQosInformation : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RAB_Level_QoS_Parameters_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RAB_Level_QoS_Parameters_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(qCI);
		v(allocationAndRetentionPriority);
		v(gbrQosInformation);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(qCI);
		v(allocationAndRetentionPriority);
		v(gbrQosInformation);
		v(iE_Extensions);

	};
	void clear()
	{
		qCI.clear();
		allocationAndRetentionPriority.clear();
		gbrQosInformation.clear();
		iE_Extensions.clear();

	};
	private:
	qCI_t	qCI;
	allocationAndRetentionPriority_t	allocationAndRetentionPriority;
	gbrQosInformation_t	gbrQosInformation;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RAB-List ::= SEQUENCE (SIZE(1.. maxnoofBearers)) OF ProtocolIE-Single-Container { {E-RAB-ItemIEs} }
*/

struct E_RAB_List_elm : ProtocolIE_Single_Container<E_RAB_ItemIEs>
{
	static constexpr const char* name() {return "E_RAB_List_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RAB_ItemIEs>;

};
struct E_RAB_List : asn::sequenceof<E_RAB_List_elm>
{
	static constexpr const char* name() {return "E-RAB-List";}
	using parent_t = asn::sequenceof<E_RAB_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
E-RABUsageReport-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct E_RABUsageReport_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABUsageReport-Item ::= SEQUENCE {
	startTimeStamp				OCTET STRING (SIZE(4)),
	endTimeStamp					OCTET STRING (SIZE(4)),
	usageCountUL					INTEGER (0..4294967295),
	usageCountDL					INTEGER (0..4294967295),
	iE-Extensions				ProtocolExtensionContainer { {E-RABUsageReport-Item-ExtIEs} } OPTIONAL,
...
}
*/

struct E_RABUsageReport_Item : asn::sequence<5, 0, true, 1>
{
	static constexpr const char* name() {return "E-RABUsageReport-Item";}
	using parent_t = asn::sequence<5, 0, true, 1>;
	struct startTimeStamp_t : asn::ostring<>
	{
		using constraint_t = asn::constraints<false,asn::one<4>>;
		static constexpr const char* name() {return "startTimeStamp_t";}
		using parent_t = asn::ostring<>;

	};

	startTimeStamp_t& ref_startTimeStamp() {return startTimeStamp;}
	startTimeStamp_t const& ref_startTimeStamp() const {return startTimeStamp;}
	struct endTimeStamp_t : asn::ostring<>
	{
		using constraint_t = asn::constraints<false,asn::one<4>>;
		static constexpr const char* name() {return "endTimeStamp_t";}
		using parent_t = asn::ostring<>;

	};

	endTimeStamp_t& ref_endTimeStamp() {return endTimeStamp;}
	endTimeStamp_t const& ref_endTimeStamp() const {return endTimeStamp;}
	struct usageCountUL_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 4294967295>>;
		static constexpr const char* name() {return "usageCountUL_t";}
		using parent_t = asn::integer<>;

	};

	usageCountUL_t& ref_usageCountUL() {return usageCountUL;}
	usageCountUL_t const& ref_usageCountUL() const {return usageCountUL;}
	struct usageCountDL_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 4294967295>>;
		static constexpr const char* name() {return "usageCountDL_t";}
		using parent_t = asn::integer<>;

	};

	usageCountDL_t& ref_usageCountDL() {return usageCountDL;}
	usageCountDL_t const& ref_usageCountDL() const {return usageCountDL;}
	struct iE_Extensions_t : ProtocolExtensionContainer<E_RABUsageReport_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<E_RABUsageReport_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(startTimeStamp);
		v(endTimeStamp);
		v(usageCountUL);
		v(usageCountDL);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(startTimeStamp);
		v(endTimeStamp);
		v(usageCountUL);
		v(usageCountDL);
		v(iE_Extensions);

	};
	void clear()
	{
		startTimeStamp.clear();
		endTimeStamp.clear();
		usageCountUL.clear();
		usageCountDL.clear();
		iE_Extensions.clear();

	};
	private:
	startTimeStamp_t	startTimeStamp;
	endTimeStamp_t	endTimeStamp;
	usageCountUL_t	usageCountUL;
	usageCountDL_t	usageCountDL;
	iE_Extensions_t	iE_Extensions;

};
/*
E-RABUsageReport-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-E-RABUsageReport-Item	 CRITICALITY ignore 	TYPE E-RABUsageReport-Item 	PRESENCE mandatory },
	...
}
*/

struct E_RABUsageReport_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABUsageReport_Item() { set(id_E_RABUsageReport_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_E_RABUsageReport_Item)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_E_RABUsageReport_Item);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABUsageReport_Item() { set(ignore); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		E_RABUsageReport_Item& select_id_E_RABUsageReport_Item() { return set<E_RABUsageReport_Item>(1); }
		E_RABUsageReport_Item const* get_id_E_RABUsageReport_Item() const { return get<E_RABUsageReport_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<E_RABUsageReport_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<E_RABUsageReport_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_E_RABUsageReport_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<E_RABUsageReport_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(E_RABUsageReport_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_E_RABUsageReport_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
E-RABUsageReportList ::= SEQUENCE (SIZE(1..maxnooftimeperiods)) OF ProtocolIE-Single-Container { {E-RABUsageReport-ItemIEs} }
*/

struct E_RABUsageReportList_elm : ProtocolIE_Single_Container<E_RABUsageReport_ItemIEs>
{
	static constexpr const char* name() {return "E_RABUsageReportList_elm";}
	using parent_t = ProtocolIE_Single_Container<E_RABUsageReport_ItemIEs>;

};
struct E_RABUsageReportList : asn::sequenceof<E_RABUsageReportList_elm>
{
	static constexpr const char* name() {return "E-RABUsageReportList";}
	using parent_t = asn::sequenceof<E_RABUsageReportList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnooftimeperiods >>;

};
/*
EARFCN ::= INTEGER (0..maxEARFCN)
*/

struct EARFCN : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0,  maxEARFCN >>;
	static constexpr const char* name() {return "EARFCN";}
	using parent_t = asn::integer<>;

};

/*
EARFCNExtension ::= INTEGER(maxEARFCNPlusOne..newmaxEARFCN, ...)
*/

struct EARFCNExtension : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span< maxEARFCNPlusOne ,  newmaxEARFCN >>;
	static constexpr const char* name() {return "EARFCNExtension";}
	using parent_t = asn::integer<>;

};

/*
EN-DC-ResourceConfigurationExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct EN_DC_ResourceConfigurationExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
EN-DC-ResourceConfiguration ::= SEQUENCE {
	pDCPatSgNB		ENUMERATED {present, not-present, ...},
	mCGresources	ENUMERATED {present, not-present, ...},
	sCGresources	ENUMERATED {present, not-present, ...},
	iE-Extensions					ProtocolExtensionContainer { {EN-DC-ResourceConfigurationExtIEs} }	OPTIONAL,
	...
}
*/

struct EN_DC_ResourceConfiguration : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "EN-DC-ResourceConfiguration";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct pDCPatSgNB_t : asn::enumerated<2, 0, true>
	{
		static constexpr const char* name() {return "pDCPatSgNB_t";}
		using parent_t = asn::enumerated<2, 0, true>;
		typedef enum {
			present
			,not_present
		} index_t;

	};

	pDCPatSgNB_t& ref_pDCPatSgNB() {return pDCPatSgNB;}
	pDCPatSgNB_t const& ref_pDCPatSgNB() const {return pDCPatSgNB;}
	struct mCGresources_t : asn::enumerated<2, 0, true>
	{
		static constexpr const char* name() {return "mCGresources_t";}
		using parent_t = asn::enumerated<2, 0, true>;
		typedef enum {
			present
			,not_present
		} index_t;

	};

	mCGresources_t& ref_mCGresources() {return mCGresources;}
	mCGresources_t const& ref_mCGresources() const {return mCGresources;}
	struct sCGresources_t : asn::enumerated<2, 0, true>
	{
		static constexpr const char* name() {return "sCGresources_t";}
		using parent_t = asn::enumerated<2, 0, true>;
		typedef enum {
			present
			,not_present
		} index_t;

	};

	sCGresources_t& ref_sCGresources() {return sCGresources;}
	sCGresources_t const& ref_sCGresources() const {return sCGresources;}
	struct iE_Extensions_t : ProtocolExtensionContainer<EN_DC_ResourceConfigurationExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<EN_DC_ResourceConfigurationExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pDCPatSgNB);
		v(mCGresources);
		v(sCGresources);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pDCPatSgNB);
		v(mCGresources);
		v(sCGresources);
		v(iE_Extensions);

	};
	void clear()
	{
		pDCPatSgNB.clear();
		mCGresources.clear();
		sCGresources.clear();
		iE_Extensions.clear();

	};
	private:
	pDCPatSgNB_t	pDCPatSgNB;
	mCGresources_t	mCGresources;
	sCGresources_t	sCGresources;
	iE_Extensions_t	iE_Extensions;

};
/*
ENB-ID ::= CHOICE {
	macro-eNB-ID	BIT STRING (SIZE (20)),
	home-eNB-ID		BIT STRING (SIZE (28)),
	... ,
	short-Macro-eNB-ID		BIT STRING (SIZE(18)),
	long-Macro-eNB-ID		BIT STRING (SIZE(21))
}
*/

struct ENB_ID : asn::choice<4, 2, true>
{
	static constexpr const char* name() {return "ENB-ID";}
	using parent_t = asn::choice<4, 2, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 5;}
	void set_unknown() { set_index(5);  }
	~ENB_ID() {clear();}
	struct macro_eNB_ID_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<20>>;
		static constexpr const char* name() {return "macro_eNB_ID_t";}
		using parent_t = asn::bstring<>;

	};

	struct home_eNB_ID_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<28>>;
		static constexpr const char* name() {return "home_eNB_ID_t";}
		using parent_t = asn::bstring<>;

	};

	struct short_Macro_eNB_ID_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<18>>;
		static constexpr const char* name() {return "short_Macro_eNB_ID_t";}
		using parent_t = asn::bstring<>;

	};

	struct long_Macro_eNB_ID_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<21>>;
		static constexpr const char* name() {return "long_Macro_eNB_ID_t";}
		using parent_t = asn::bstring<>;

	};

	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<macro_eNB_ID_t>(); break;
		case 2: var.destroy<home_eNB_ID_t>(); break;
		case 3: var.destroy<short_Macro_eNB_ID_t>(); break;
		case 4: var.destroy<long_Macro_eNB_ID_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<macro_eNB_ID_t>());
		case 2: set_index(2); return v(var.build<home_eNB_ID_t>());
		case 3: set_index(3); return v(var.build<short_Macro_eNB_ID_t>());
		case 4: set_index(4); return v(var.build<long_Macro_eNB_ID_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<macro_eNB_ID_t>());
		case 2: return v(var.as<home_eNB_ID_t>());
		case 3: return v(var.as<short_Macro_eNB_ID_t>());
		case 4: return v(var.as<long_Macro_eNB_ID_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<macro_eNB_ID_t>(1);
		v.template operator()<home_eNB_ID_t>(2);
		v.template operator()<short_Macro_eNB_ID_t>(3);
		v.template operator()<long_Macro_eNB_ID_t>(4);

	}
	macro_eNB_ID_t& select_macro_eNB_ID() { if(get_index() != 1) { clear(); set_index(1); return var.build<macro_eNB_ID_t>();} return var.as<macro_eNB_ID_t>();}
	macro_eNB_ID_t const* get_macro_eNB_ID() const { if(get_index() == 1) { return &var.as<macro_eNB_ID_t>();} return nullptr; }
	home_eNB_ID_t& select_home_eNB_ID() { if(get_index() != 2) { clear(); set_index(2); return var.build<home_eNB_ID_t>();} return var.as<home_eNB_ID_t>();}
	home_eNB_ID_t const* get_home_eNB_ID() const { if(get_index() == 2) { return &var.as<home_eNB_ID_t>();} return nullptr; }
	short_Macro_eNB_ID_t& select_short_Macro_eNB_ID() { if(get_index() != 3) { clear(); set_index(3); return var.build<short_Macro_eNB_ID_t>();} return var.as<short_Macro_eNB_ID_t>();}
	short_Macro_eNB_ID_t const* get_short_Macro_eNB_ID() const { if(get_index() == 3) { return &var.as<short_Macro_eNB_ID_t>();} return nullptr; }
	long_Macro_eNB_ID_t& select_long_Macro_eNB_ID() { if(get_index() != 4) { clear(); set_index(4); return var.build<long_Macro_eNB_ID_t>();} return var.as<long_Macro_eNB_ID_t>();}
	long_Macro_eNB_ID_t const* get_long_Macro_eNB_ID() const { if(get_index() == 4) { return &var.as<long_Macro_eNB_ID_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(macro_eNB_ID_t)];
		char dummy2[sizeof(home_eNB_ID_t)];
		char dummy3[sizeof(short_Macro_eNB_ID_t)];
		char dummy4[sizeof(long_Macro_eNB_ID_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
EPLMNs ::= SEQUENCE (SIZE(1..maxnoofEPLMNs)) OF PLMN-Identity
*/

struct EPLMNs_elm : PLMN_Identity
{
	static constexpr const char* name() {return "EPLMNs_elm";}
	using parent_t = PLMN_Identity;

};
struct EPLMNs : asn::sequenceof<EPLMNs_elm>
{
	static constexpr const char* name() {return "EPLMNs";}
	using parent_t = asn::sequenceof<EPLMNs_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofEPLMNs >>;

};
/*
UserPlaneTrafficActivityReport ::= ENUMERATED {inactive, re-activated, ...}
*/

struct UserPlaneTrafficActivityReport : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "UserPlaneTrafficActivityReport";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		inactive
		,re_activated
	} index_t;

};

/*
ERABActivityNotifyItem-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ERABActivityNotifyItem_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ERABActivityNotifyItem ::= SEQUENCE {
	e-RAB-ID						E-RAB-ID,
	activityReport					UserPlaneTrafficActivityReport,
	iE-Extensions					ProtocolExtensionContainer { {ERABActivityNotifyItem-ExtIEs} }	OPTIONAL,
	...
}
*/

struct ERABActivityNotifyItem : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "ERABActivityNotifyItem";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct activityReport_t : UserPlaneTrafficActivityReport
	{
		static constexpr const char* name() {return "activityReport_t";}
		using parent_t = UserPlaneTrafficActivityReport;

	};
	activityReport_t& ref_activityReport() {return activityReport;}
	activityReport_t const& ref_activityReport() const {return activityReport;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ERABActivityNotifyItem_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ERABActivityNotifyItem_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(activityReport);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(activityReport);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		activityReport.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	activityReport_t	activityReport;
	iE_Extensions_t	iE_Extensions;

};
/*
ERABActivityNotifyItemList ::= SEQUENCE (SIZE (0..maxnoofBearers)) OF ERABActivityNotifyItem
*/

struct ERABActivityNotifyItemList_elm : ERABActivityNotifyItem
{
	static constexpr const char* name() {return "ERABActivityNotifyItemList_elm";}
	using parent_t = ERABActivityNotifyItem;

};
struct ERABActivityNotifyItemList : asn::sequenceof<ERABActivityNotifyItemList_elm>
{
	static constexpr const char* name() {return "ERABActivityNotifyItemList";}
	using parent_t = asn::sequenceof<ERABActivityNotifyItemList_elm>;
	using constraint_t = asn::constraints<false,asn::span<0,  maxnoofBearers >>;

};
/*
Transmission-Bandwidth ::= ENUMERATED {
		bw6,
	 	bw15,
		bw25,
	 	bw50,
		bw75,
		bw100,
		...,
		bw1
}
*/

struct Transmission_Bandwidth : asn::enumerated<7, 1, true>
{
	static constexpr const char* name() {return "Transmission-Bandwidth";}
	using parent_t = asn::enumerated<7, 1, true>;
	typedef enum {
		bw6
		,bw15
		,bw25
		,bw50
		,bw75
		,bw100
		,bw1
	} index_t;

};

/*
OffsetOfNbiotChannelNumberToEARFCN ::= ENUMERATED {
		minusTen,
		minusNine,
		minusEight,
		minusSeven,
		minusSix,
		minusFive,
		minusFour,
		minusThree,
		minusTwo,
		minusOne,
		minusZeroDotFive,
		zero,
		one,
		two,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		...
}
*/

struct OffsetOfNbiotChannelNumberToEARFCN : asn::enumerated<21, 0, true>
{
	static constexpr const char* name() {return "OffsetOfNbiotChannelNumberToEARFCN";}
	using parent_t = asn::enumerated<21, 0, true>;
	typedef enum {
		minusTen
		,minusNine
		,minusEight
		,minusSeven
		,minusSix
		,minusFive
		,minusFour
		,minusThree
		,minusTwo
		,minusOne
		,minusZeroDotFive
		,zero
		,one
		,two
		,three
		,four
		,five
		,six
		,seven
		,eight
		,nine
	} index_t;

};

/*
NRS-NSSS-PowerOffset ::= ENUMERATED { minusThree, zero, three, ...}
*/

struct NRS_NSSS_PowerOffset : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "NRS-NSSS-PowerOffset";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		minusThree
		,zero
		,three
	} index_t;

};

/*
NSSS-NumOccasionDifferentPrecoder ::= ENUMERATED { two, four, eight, ...}
*/

struct NSSS_NumOccasionDifferentPrecoder : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "NSSS-NumOccasionDifferentPrecoder";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		two
		,four
		,eight
	} index_t;

};

/*
FDD-Info-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-UL-EARFCNExtension						CRITICALITY reject	EXTENSION EARFCNExtension									PRESENCE optional}|
	{ ID id-DL-EARFCNExtension						CRITICALITY reject	EXTENSION EARFCNExtension									PRESENCE optional}|
	{ ID id-OffsetOfNbiotChannelNumberToDL-EARFCN	CRITICALITY reject	EXTENSION OffsetOfNbiotChannelNumberToEARFCN		PRESENCE optional}|
	{ ID id-OffsetOfNbiotChannelNumberToUL-EARFCN	CRITICALITY reject	EXTENSION OffsetOfNbiotChannelNumberToEARFCN		PRESENCE optional}|
	{ ID id-NRS-NSSS-PowerOffset					CRITICALITY ignore	EXTENSION NRS-NSSS-PowerOffset							PRESENCE optional}|
	{ ID id-NSSS-NumOccasionDifferentPrecoder		CRITICALITY ignore	EXTENSION NSSS-NumOccasionDifferentPrecoder			PRESENCE optional},
	...
}
*/

struct FDD_Info_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 7; }
		void clear() {type = 0;}
		void select_id_UL_EARFCNExtension() { set(id_UL_EARFCNExtension); type=1;}
		void select_id_DL_EARFCNExtension() { set(id_DL_EARFCNExtension); type=2;}
		void select_id_OffsetOfNbiotChannelNumberToDL_EARFCN() { set(id_OffsetOfNbiotChannelNumberToDL_EARFCN); type=3;}
		void select_id_OffsetOfNbiotChannelNumberToUL_EARFCN() { set(id_OffsetOfNbiotChannelNumberToUL_EARFCN); type=4;}
		void select_id_NRS_NSSS_PowerOffset() { set(id_NRS_NSSS_PowerOffset); type=5;}
		void select_id_NSSS_NumOccasionDifferentPrecoder() { set(id_NSSS_NumOccasionDifferentPrecoder); type=6;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_UL_EARFCNExtension)) { type = 1; return true; }
			else if(equal(id_DL_EARFCNExtension)) { type = 2; return true; }
			else if(equal(id_OffsetOfNbiotChannelNumberToDL_EARFCN)) { type = 3; return true; }
			else if(equal(id_OffsetOfNbiotChannelNumberToUL_EARFCN)) { type = 4; return true; }
			else if(equal(id_NRS_NSSS_PowerOffset)) { type = 5; return true; }
			else if(equal(id_NSSS_NumOccasionDifferentPrecoder)) { type = 6; return true; }
			else { type = 7; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_UL_EARFCNExtension);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_DL_EARFCNExtension);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_OffsetOfNbiotChannelNumberToDL_EARFCN);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_OffsetOfNbiotChannelNumberToUL_EARFCN);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(id_NRS_NSSS_PowerOffset);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(id_NSSS_NumOccasionDifferentPrecoder);} return false;
			case 7: type = 7; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 7; }
		void clear() {type = 0;}
		void select_id_UL_EARFCNExtension() { set(reject); type=1;}
		void select_id_DL_EARFCNExtension() { set(reject); type=2;}
		void select_id_OffsetOfNbiotChannelNumberToDL_EARFCN() { set(reject); type=3;}
		void select_id_OffsetOfNbiotChannelNumberToUL_EARFCN() { set(reject); type=4;}
		void select_id_NRS_NSSS_PowerOffset() { set(ignore); type=5;}
		void select_id_NSSS_NumOccasionDifferentPrecoder() { set(ignore); type=6;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
			else if(equal(reject)) { type = 2; return true; }
			else if(equal(reject)) { type = 3; return true; }
			else if(equal(reject)) { type = 4; return true; }
			else if(equal(ignore)) { type = 5; return true; }
			else if(equal(ignore)) { type = 6; return true; }
			else { type = 7; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(reject);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(reject);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(reject);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(ignore);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(ignore);} return false;
			case 7: type = 7; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		EARFCNExtension& select_id_UL_EARFCNExtension() { return set<EARFCNExtension>(1); }
		EARFCNExtension const* get_id_UL_EARFCNExtension() const { return get<EARFCNExtension>(1); }
		EARFCNExtension& select_id_DL_EARFCNExtension() { return set<EARFCNExtension>(2); }
		EARFCNExtension const* get_id_DL_EARFCNExtension() const { return get<EARFCNExtension>(2); }
		OffsetOfNbiotChannelNumberToEARFCN& select_id_OffsetOfNbiotChannelNumberToDL_EARFCN() { return set<OffsetOfNbiotChannelNumberToEARFCN>(3); }
		OffsetOfNbiotChannelNumberToEARFCN const* get_id_OffsetOfNbiotChannelNumberToDL_EARFCN() const { return get<OffsetOfNbiotChannelNumberToEARFCN>(3); }
		OffsetOfNbiotChannelNumberToEARFCN& select_id_OffsetOfNbiotChannelNumberToUL_EARFCN() { return set<OffsetOfNbiotChannelNumberToEARFCN>(4); }
		OffsetOfNbiotChannelNumberToEARFCN const* get_id_OffsetOfNbiotChannelNumberToUL_EARFCN() const { return get<OffsetOfNbiotChannelNumberToEARFCN>(4); }
		NRS_NSSS_PowerOffset& select_id_NRS_NSSS_PowerOffset() { return set<NRS_NSSS_PowerOffset>(5); }
		NRS_NSSS_PowerOffset const* get_id_NRS_NSSS_PowerOffset() const { return get<NRS_NSSS_PowerOffset>(5); }
		NSSS_NumOccasionDifferentPrecoder& select_id_NSSS_NumOccasionDifferentPrecoder() { return set<NSSS_NumOccasionDifferentPrecoder>(6); }
		NSSS_NumOccasionDifferentPrecoder const* get_id_NSSS_NumOccasionDifferentPrecoder() const { return get<NSSS_NumOccasionDifferentPrecoder>(6); }
		bool is_unknown() const { return type == 7; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<EARFCNExtension>(); break;
			case 2: var.destroy<EARFCNExtension>(); break;
			case 3: var.destroy<OffsetOfNbiotChannelNumberToEARFCN>(); break;
			case 4: var.destroy<OffsetOfNbiotChannelNumberToEARFCN>(); break;
			case 5: var.destroy<NRS_NSSS_PowerOffset>(); break;
			case 6: var.destroy<NSSS_NumOccasionDifferentPrecoder>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<EARFCNExtension>(1);
			v.template operator()<EARFCNExtension>(2);
			v.template operator()<OffsetOfNbiotChannelNumberToEARFCN>(3);
			v.template operator()<OffsetOfNbiotChannelNumberToEARFCN>(4);
			v.template operator()<NRS_NSSS_PowerOffset>(5);
			v.template operator()<NSSS_NumOccasionDifferentPrecoder>(6);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_UL_EARFCNExtension()); return true;
			case 2: v(select_id_DL_EARFCNExtension()); return true;
			case 3: v(select_id_OffsetOfNbiotChannelNumberToDL_EARFCN()); return true;
			case 4: v(select_id_OffsetOfNbiotChannelNumberToUL_EARFCN()); return true;
			case 5: v(select_id_NRS_NSSS_PowerOffset()); return true;
			case 6: v(select_id_NSSS_NumOccasionDifferentPrecoder()); return true;
			case 7: if(type != 7) {clear(); asn::base::set();} type = 7; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<EARFCNExtension>()); return true;
			case 2: v(var.as<EARFCNExtension>()); return true;
			case 3: v(var.as<OffsetOfNbiotChannelNumberToEARFCN>()); return true;
			case 4: v(var.as<OffsetOfNbiotChannelNumberToEARFCN>()); return true;
			case 5: v(var.as<NRS_NSSS_PowerOffset>()); return true;
			case 6: v(var.as<NSSS_NumOccasionDifferentPrecoder>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(EARFCNExtension)];
			char dummy2[sizeof(NRS_NSSS_PowerOffset)];
			char dummy3[sizeof(NSSS_NumOccasionDifferentPrecoder)];
			char dummy4[sizeof(OffsetOfNbiotChannelNumberToEARFCN)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 7; }
		void clear() {type = 0;}
		void select_id_UL_EARFCNExtension() { set(optional); type=1;}
		void select_id_DL_EARFCNExtension() { set(optional); type=2;}
		void select_id_OffsetOfNbiotChannelNumberToDL_EARFCN() { set(optional); type=3;}
		void select_id_OffsetOfNbiotChannelNumberToUL_EARFCN() { set(optional); type=4;}
		void select_id_NRS_NSSS_PowerOffset() { set(optional); type=5;}
		void select_id_NSSS_NumOccasionDifferentPrecoder() { set(optional); type=6;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else if(equal(optional)) { type = 3; return true; }
			else if(equal(optional)) { type = 4; return true; }
			else if(equal(optional)) { type = 5; return true; }
			else if(equal(optional)) { type = 6; return true; }
			else { type = 7; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(optional);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(optional);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(optional);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(optional);} return false;
			case 7: type = 7; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
FDD-Info ::= SEQUENCE {
	uL-EARFCN						EARFCN,
	dL-EARFCN						EARFCN,
	uL-Transmission-Bandwidth		Transmission-Bandwidth,
	dL-Transmission-Bandwidth		Transmission-Bandwidth,
	iE-Extensions				ProtocolExtensionContainer { {FDD-Info-ExtIEs} } OPTIONAL,
	...
}
*/

struct FDD_Info : asn::sequence<5, 0, true, 1>
{
	static constexpr const char* name() {return "FDD-Info";}
	using parent_t = asn::sequence<5, 0, true, 1>;
	struct uL_EARFCN_t : EARFCN
	{
		static constexpr const char* name() {return "uL_EARFCN_t";}
		using parent_t = EARFCN;

	};
	uL_EARFCN_t& ref_uL_EARFCN() {return uL_EARFCN;}
	uL_EARFCN_t const& ref_uL_EARFCN() const {return uL_EARFCN;}
	struct dL_EARFCN_t : EARFCN
	{
		static constexpr const char* name() {return "dL_EARFCN_t";}
		using parent_t = EARFCN;

	};
	dL_EARFCN_t& ref_dL_EARFCN() {return dL_EARFCN;}
	dL_EARFCN_t const& ref_dL_EARFCN() const {return dL_EARFCN;}
	struct uL_Transmission_Bandwidth_t : Transmission_Bandwidth
	{
		static constexpr const char* name() {return "uL_Transmission_Bandwidth_t";}
		using parent_t = Transmission_Bandwidth;

	};
	uL_Transmission_Bandwidth_t& ref_uL_Transmission_Bandwidth() {return uL_Transmission_Bandwidth;}
	uL_Transmission_Bandwidth_t const& ref_uL_Transmission_Bandwidth() const {return uL_Transmission_Bandwidth;}
	struct dL_Transmission_Bandwidth_t : Transmission_Bandwidth
	{
		static constexpr const char* name() {return "dL_Transmission_Bandwidth_t";}
		using parent_t = Transmission_Bandwidth;

	};
	dL_Transmission_Bandwidth_t& ref_dL_Transmission_Bandwidth() {return dL_Transmission_Bandwidth;}
	dL_Transmission_Bandwidth_t const& ref_dL_Transmission_Bandwidth() const {return dL_Transmission_Bandwidth;}
	struct iE_Extensions_t : ProtocolExtensionContainer<FDD_Info_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<FDD_Info_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(uL_EARFCN);
		v(dL_EARFCN);
		v(uL_Transmission_Bandwidth);
		v(dL_Transmission_Bandwidth);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(uL_EARFCN);
		v(dL_EARFCN);
		v(uL_Transmission_Bandwidth);
		v(dL_Transmission_Bandwidth);
		v(iE_Extensions);

	};
	void clear()
	{
		uL_EARFCN.clear();
		dL_EARFCN.clear();
		uL_Transmission_Bandwidth.clear();
		dL_Transmission_Bandwidth.clear();
		iE_Extensions.clear();

	};
	private:
	uL_EARFCN_t	uL_EARFCN;
	dL_EARFCN_t	dL_EARFCN;
	uL_Transmission_Bandwidth_t	uL_Transmission_Bandwidth;
	dL_Transmission_Bandwidth_t	dL_Transmission_Bandwidth;
	iE_Extensions_t	iE_Extensions;

};
/*
SubframeAssignment ::= ENUMERATED {
	sa0,
	sa1,
	sa2,
	sa3,
	sa4,
	sa5,
	sa6,
	...
}
*/

struct SubframeAssignment : asn::enumerated<7, 0, true>
{
	static constexpr const char* name() {return "SubframeAssignment";}
	using parent_t = asn::enumerated<7, 0, true>;
	typedef enum {
		sa0
		,sa1
		,sa2
		,sa3
		,sa4
		,sa5
		,sa6
	} index_t;

};

/*
SpecialSubframePatterns ::= ENUMERATED {
	ssp0,
	ssp1,
	ssp2,
	ssp3,
	ssp4,
	ssp5,
	ssp6,
	ssp7,
	ssp8,
	...
}
*/

struct SpecialSubframePatterns : asn::enumerated<9, 0, true>
{
	static constexpr const char* name() {return "SpecialSubframePatterns";}
	using parent_t = asn::enumerated<9, 0, true>;
	typedef enum {
		ssp0
		,ssp1
		,ssp2
		,ssp3
		,ssp4
		,ssp5
		,ssp6
		,ssp7
		,ssp8
	} index_t;

};

/*
SpecialSubframe-Info-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct SpecialSubframe_Info_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
SpecialSubframe-Info ::= SEQUENCE {
	specialSubframePatterns		SpecialSubframePatterns,
	cyclicPrefixDL				CyclicPrefixDL,
	cyclicPrefixUL				CyclicPrefixUL,
	iE-Extensions				ProtocolExtensionContainer { {SpecialSubframe-Info-ExtIEs} } OPTIONAL,
	...
}
*/

struct SpecialSubframe_Info : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "SpecialSubframe-Info";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct specialSubframePatterns_t : SpecialSubframePatterns
	{
		static constexpr const char* name() {return "specialSubframePatterns_t";}
		using parent_t = SpecialSubframePatterns;

	};
	specialSubframePatterns_t& ref_specialSubframePatterns() {return specialSubframePatterns;}
	specialSubframePatterns_t const& ref_specialSubframePatterns() const {return specialSubframePatterns;}
	struct cyclicPrefixDL_t : CyclicPrefixDL
	{
		static constexpr const char* name() {return "cyclicPrefixDL_t";}
		using parent_t = CyclicPrefixDL;

	};
	cyclicPrefixDL_t& ref_cyclicPrefixDL() {return cyclicPrefixDL;}
	cyclicPrefixDL_t const& ref_cyclicPrefixDL() const {return cyclicPrefixDL;}
	struct cyclicPrefixUL_t : CyclicPrefixUL
	{
		static constexpr const char* name() {return "cyclicPrefixUL_t";}
		using parent_t = CyclicPrefixUL;

	};
	cyclicPrefixUL_t& ref_cyclicPrefixUL() {return cyclicPrefixUL;}
	cyclicPrefixUL_t const& ref_cyclicPrefixUL() const {return cyclicPrefixUL;}
	struct iE_Extensions_t : ProtocolExtensionContainer<SpecialSubframe_Info_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<SpecialSubframe_Info_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(specialSubframePatterns);
		v(cyclicPrefixDL);
		v(cyclicPrefixUL);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(specialSubframePatterns);
		v(cyclicPrefixDL);
		v(cyclicPrefixUL);
		v(iE_Extensions);

	};
	void clear()
	{
		specialSubframePatterns.clear();
		cyclicPrefixDL.clear();
		cyclicPrefixUL.clear();
		iE_Extensions.clear();

	};
	private:
	specialSubframePatterns_t	specialSubframePatterns;
	cyclicPrefixDL_t	cyclicPrefixDL;
	cyclicPrefixUL_t	cyclicPrefixUL;
	iE_Extensions_t	iE_Extensions;

};
/*
TDD-Info-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-AdditionalSpecialSubframe-Info	CRITICALITY ignore	EXTENSION AdditionalSpecialSubframe-Info	PRESENCE optional}|
	{ ID id-eARFCNExtension					CRITICALITY reject	EXTENSION EARFCNExtension						PRESENCE optional}|
	{ ID id-AdditionalSpecialSubframeExtension-Info	CRITICALITY ignore	EXTENSION AdditionalSpecialSubframeExtension-Info	PRESENCE optional},
	...
}
*/

struct TDD_Info_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_AdditionalSpecialSubframe_Info() { set(id_AdditionalSpecialSubframe_Info); type=1;}
		void select_id_eARFCNExtension() { set(id_eARFCNExtension); type=2;}
		void select_id_AdditionalSpecialSubframeExtension_Info() { set(id_AdditionalSpecialSubframeExtension_Info); type=3;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_AdditionalSpecialSubframe_Info)) { type = 1; return true; }
			else if(equal(id_eARFCNExtension)) { type = 2; return true; }
			else if(equal(id_AdditionalSpecialSubframeExtension_Info)) { type = 3; return true; }
			else { type = 4; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_AdditionalSpecialSubframe_Info);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_eARFCNExtension);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_AdditionalSpecialSubframeExtension_Info);} return false;
			case 4: type = 4; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_AdditionalSpecialSubframe_Info() { set(ignore); type=1;}
		void select_id_eARFCNExtension() { set(reject); type=2;}
		void select_id_AdditionalSpecialSubframeExtension_Info() { set(ignore); type=3;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(reject)) { type = 2; return true; }
			else if(equal(ignore)) { type = 3; return true; }
			else { type = 4; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(reject);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(ignore);} return false;
			case 4: type = 4; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		AdditionalSpecialSubframe_Info& select_id_AdditionalSpecialSubframe_Info() { return set<AdditionalSpecialSubframe_Info>(1); }
		AdditionalSpecialSubframe_Info const* get_id_AdditionalSpecialSubframe_Info() const { return get<AdditionalSpecialSubframe_Info>(1); }
		EARFCNExtension& select_id_eARFCNExtension() { return set<EARFCNExtension>(2); }
		EARFCNExtension const* get_id_eARFCNExtension() const { return get<EARFCNExtension>(2); }
		AdditionalSpecialSubframeExtension_Info& select_id_AdditionalSpecialSubframeExtension_Info() { return set<AdditionalSpecialSubframeExtension_Info>(3); }
		AdditionalSpecialSubframeExtension_Info const* get_id_AdditionalSpecialSubframeExtension_Info() const { return get<AdditionalSpecialSubframeExtension_Info>(3); }
		bool is_unknown() const { return type == 4; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<AdditionalSpecialSubframe_Info>(); break;
			case 2: var.destroy<EARFCNExtension>(); break;
			case 3: var.destroy<AdditionalSpecialSubframeExtension_Info>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<AdditionalSpecialSubframe_Info>(1);
			v.template operator()<EARFCNExtension>(2);
			v.template operator()<AdditionalSpecialSubframeExtension_Info>(3);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_AdditionalSpecialSubframe_Info()); return true;
			case 2: v(select_id_eARFCNExtension()); return true;
			case 3: v(select_id_AdditionalSpecialSubframeExtension_Info()); return true;
			case 4: if(type != 4) {clear(); asn::base::set();} type = 4; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<AdditionalSpecialSubframe_Info>()); return true;
			case 2: v(var.as<EARFCNExtension>()); return true;
			case 3: v(var.as<AdditionalSpecialSubframeExtension_Info>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(AdditionalSpecialSubframeExtension_Info)];
			char dummy2[sizeof(AdditionalSpecialSubframe_Info)];
			char dummy3[sizeof(EARFCNExtension)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_AdditionalSpecialSubframe_Info() { set(optional); type=1;}
		void select_id_eARFCNExtension() { set(optional); type=2;}
		void select_id_AdditionalSpecialSubframeExtension_Info() { set(optional); type=3;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else if(equal(optional)) { type = 3; return true; }
			else { type = 4; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(optional);} return false;
			case 4: type = 4; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
TDD-Info ::= SEQUENCE {
	eARFCN							EARFCN,
	transmission-Bandwidth			Transmission-Bandwidth,
	subframeAssignment				SubframeAssignment,
	specialSubframe-Info			SpecialSubframe-Info,
	iE-Extensions					ProtocolExtensionContainer { {TDD-Info-ExtIEs} } OPTIONAL,
	...
}
*/

struct TDD_Info : asn::sequence<5, 0, true, 1>
{
	static constexpr const char* name() {return "TDD-Info";}
	using parent_t = asn::sequence<5, 0, true, 1>;
	struct eARFCN_t : EARFCN
	{
		static constexpr const char* name() {return "eARFCN_t";}
		using parent_t = EARFCN;

	};
	eARFCN_t& ref_eARFCN() {return eARFCN;}
	eARFCN_t const& ref_eARFCN() const {return eARFCN;}
	struct transmission_Bandwidth_t : Transmission_Bandwidth
	{
		static constexpr const char* name() {return "transmission_Bandwidth_t";}
		using parent_t = Transmission_Bandwidth;

	};
	transmission_Bandwidth_t& ref_transmission_Bandwidth() {return transmission_Bandwidth;}
	transmission_Bandwidth_t const& ref_transmission_Bandwidth() const {return transmission_Bandwidth;}
	struct subframeAssignment_t : SubframeAssignment
	{
		static constexpr const char* name() {return "subframeAssignment_t";}
		using parent_t = SubframeAssignment;

	};
	subframeAssignment_t& ref_subframeAssignment() {return subframeAssignment;}
	subframeAssignment_t const& ref_subframeAssignment() const {return subframeAssignment;}
	struct specialSubframe_Info_t : SpecialSubframe_Info
	{
		static constexpr const char* name() {return "specialSubframe_Info_t";}
		using parent_t = SpecialSubframe_Info;

	};
	specialSubframe_Info_t& ref_specialSubframe_Info() {return specialSubframe_Info;}
	specialSubframe_Info_t const& ref_specialSubframe_Info() const {return specialSubframe_Info;}
	struct iE_Extensions_t : ProtocolExtensionContainer<TDD_Info_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<TDD_Info_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(eARFCN);
		v(transmission_Bandwidth);
		v(subframeAssignment);
		v(specialSubframe_Info);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(eARFCN);
		v(transmission_Bandwidth);
		v(subframeAssignment);
		v(specialSubframe_Info);
		v(iE_Extensions);

	};
	void clear()
	{
		eARFCN.clear();
		transmission_Bandwidth.clear();
		subframeAssignment.clear();
		specialSubframe_Info.clear();
		iE_Extensions.clear();

	};
	private:
	eARFCN_t	eARFCN;
	transmission_Bandwidth_t	transmission_Bandwidth;
	subframeAssignment_t	subframeAssignment;
	specialSubframe_Info_t	specialSubframe_Info;
	iE_Extensions_t	iE_Extensions;

};
/*
EUTRA-Mode-Info ::= CHOICE {
	fDD		FDD-Info,
	tDD		TDD-Info,
	...
}
*/

struct EUTRA_Mode_Info : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "EUTRA-Mode-Info";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~EUTRA_Mode_Info() {clear();}
	struct fDD_t : FDD_Info
	{
		static constexpr const char* name() {return "fDD_t";}
		using parent_t = FDD_Info;

	};
	struct tDD_t : TDD_Info
	{
		static constexpr const char* name() {return "tDD_t";}
		using parent_t = TDD_Info;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<fDD_t>(); break;
		case 2: var.destroy<tDD_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<fDD_t>());
		case 2: set_index(2); return v(var.build<tDD_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<fDD_t>());
		case 2: return v(var.as<tDD_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<fDD_t>(1);
		v.template operator()<tDD_t>(2);

	}
	fDD_t& select_fDD() { if(get_index() != 1) { clear(); set_index(1); return var.build<fDD_t>();} return var.as<fDD_t>();}
	fDD_t const* get_fDD() const { if(get_index() == 1) { return &var.as<fDD_t>();} return nullptr; }
	tDD_t& select_tDD() { if(get_index() != 2) { clear(); set_index(2); return var.build<tDD_t>();} return var.as<tDD_t>();}
	tDD_t const* get_tDD() const { if(get_index() == 2) { return &var.as<tDD_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(fDD_t)];
		char dummy2[sizeof(tDD_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
EUTRANTraceID		::= OCTET STRING (SIZE (8))
*/

struct EUTRANTraceID : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<8>>;
	static constexpr const char* name() {return "EUTRANTraceID";}
	using parent_t = asn::ostring<>;

};

/*
EncryptionAlgorithms ::= BIT STRING (SIZE (16, ...))
*/

struct EncryptionAlgorithms : asn::bstring<>
{
	using constraint_t = asn::constraints<true,asn::one<16>>;
	static constexpr const char* name() {return "EncryptionAlgorithms";}
	using parent_t = asn::bstring<>;

};

/*
RNTP-Threshold ::= ENUMERATED {
	minusInfinity,
	minusEleven,
	minusTen,
	minusNine,
	minusEight,
	minusSeven,
	minusSix,
	minusFive,
	minusFour,
	minusThree,
	minusTwo,
	minusOne,
	zero,
	one,
	two,
	three,
	...
}
*/

struct RNTP_Threshold : asn::enumerated<16, 0, true>
{
	static constexpr const char* name() {return "RNTP-Threshold";}
	using parent_t = asn::enumerated<16, 0, true>;
	typedef enum {
		minusInfinity
		,minusEleven
		,minusTen
		,minusNine
		,minusEight
		,minusSeven
		,minusSix
		,minusFive
		,minusFour
		,minusThree
		,minusTwo
		,minusOne
		,zero
		,one
		,two
		,three
	} index_t;

};

/*
EnhancedRNTPStartTime-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct EnhancedRNTPStartTime_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
EnhancedRNTPStartTime ::= SEQUENCE {
		startSFN				INTEGER (0..1023, ...),
		startSubframeNumber		INTEGER (0..9, ...),
		iE-Extensions			ProtocolExtensionContainer { {EnhancedRNTPStartTime-ExtIEs} } OPTIONAL,
		...
	}
*/

struct EnhancedRNTPStartTime : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "EnhancedRNTPStartTime";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct startSFN_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 1023>>;
		static constexpr const char* name() {return "startSFN_t";}
		using parent_t = asn::integer<>;

	};

	startSFN_t& ref_startSFN() {return startSFN;}
	startSFN_t const& ref_startSFN() const {return startSFN;}
	struct startSubframeNumber_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 9>>;
		static constexpr const char* name() {return "startSubframeNumber_t";}
		using parent_t = asn::integer<>;

	};

	startSubframeNumber_t& ref_startSubframeNumber() {return startSubframeNumber;}
	startSubframeNumber_t const& ref_startSubframeNumber() const {return startSubframeNumber;}
	struct iE_Extensions_t : ProtocolExtensionContainer<EnhancedRNTPStartTime_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<EnhancedRNTPStartTime_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(startSFN);
		v(startSubframeNumber);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(startSFN);
		v(startSubframeNumber);
		v(iE_Extensions);

	};
	void clear()
	{
		startSFN.clear();
		startSubframeNumber.clear();
		iE_Extensions.clear();

	};
	private:
	startSFN_t	startSFN;
	startSubframeNumber_t	startSubframeNumber;
	iE_Extensions_t	iE_Extensions;

};
/*
EnhancedRNTP-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct EnhancedRNTP_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
EnhancedRNTP ::= SEQUENCE {
	enhancedRNTPBitmap			BIT STRING (SIZE(12..8800, ...)),
	rNTP-High-Power-Threshold	RNTP-Threshold,
	enhancedRNTPStartTime		EnhancedRNTPStartTime OPTIONAL,
	iE-Extensions				ProtocolExtensionContainer { {EnhancedRNTP-ExtIEs} } OPTIONAL,
	...
}
*/

struct EnhancedRNTP : asn::sequence<4, 0, true, 2>
{
	static constexpr const char* name() {return "EnhancedRNTP";}
	using parent_t = asn::sequence<4, 0, true, 2>;
	struct enhancedRNTPBitmap_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::span<12, 8800>>;
		static constexpr const char* name() {return "enhancedRNTPBitmap_t";}
		using parent_t = asn::bstring<>;

	};

	enhancedRNTPBitmap_t& ref_enhancedRNTPBitmap() {return enhancedRNTPBitmap;}
	enhancedRNTPBitmap_t const& ref_enhancedRNTPBitmap() const {return enhancedRNTPBitmap;}
	struct rNTP_High_Power_Threshold_t : RNTP_Threshold
	{
		static constexpr const char* name() {return "rNTP_High_Power_Threshold_t";}
		using parent_t = RNTP_Threshold;

	};
	rNTP_High_Power_Threshold_t& ref_rNTP_High_Power_Threshold() {return rNTP_High_Power_Threshold;}
	rNTP_High_Power_Threshold_t const& ref_rNTP_High_Power_Threshold() const {return rNTP_High_Power_Threshold;}
	struct enhancedRNTPStartTime_t : EnhancedRNTPStartTime
	{
		static constexpr const char* name() {return "enhancedRNTPStartTime_t";}
		using parent_t = EnhancedRNTPStartTime;
		static constexpr bool optional = true;

	};
	enhancedRNTPStartTime_t& set_enhancedRNTPStartTime() { enhancedRNTPStartTime.setpresent(true); return enhancedRNTPStartTime;}
	enhancedRNTPStartTime_t const* get_enhancedRNTPStartTime() const {return enhancedRNTPStartTime.is_valid() ? &enhancedRNTPStartTime : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<EnhancedRNTP_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<EnhancedRNTP_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(enhancedRNTPBitmap);
		v(rNTP_High_Power_Threshold);
		v(enhancedRNTPStartTime);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(enhancedRNTPBitmap);
		v(rNTP_High_Power_Threshold);
		v(enhancedRNTPStartTime);
		v(iE_Extensions);

	};
	void clear()
	{
		enhancedRNTPBitmap.clear();
		rNTP_High_Power_Threshold.clear();
		enhancedRNTPStartTime.clear();
		iE_Extensions.clear();

	};
	private:
	enhancedRNTPBitmap_t	enhancedRNTPBitmap;
	rNTP_High_Power_Threshold_t	rNTP_High_Power_Threshold;
	enhancedRNTPStartTime_t	enhancedRNTPStartTime;
	iE_Extensions_t	iE_Extensions;

};
/*
EventType ::= ENUMERATED{
	change-of-serving-cell,
	...
}
*/

struct EventType : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "EventType";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		change_of_serving_cell
	} index_t;

};

/*
ExpectedActivityPeriod ::= INTEGER (1..30|40|50|60|80|100|120|150|180|181,...)
*/

struct ExpectedActivityPeriod : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<1, 30>,asn::one<40>,asn::one<50>,asn::one<60>,asn::one<80>,asn::one<100>,asn::one<120>,asn::one<150>,asn::one<180>,asn::one<181>>;
	static constexpr const char* name() {return "ExpectedActivityPeriod";}
	using parent_t = asn::integer<>;

};

/*
ExpectedHOInterval ::= ENUMERATED {
	sec15, sec30, sec60, sec90, sec120, sec180, long-time,
	...
}
*/

struct ExpectedHOInterval : asn::enumerated<7, 0, true>
{
	static constexpr const char* name() {return "ExpectedHOInterval";}
	using parent_t = asn::enumerated<7, 0, true>;
	typedef enum {
		sec15
		,sec30
		,sec60
		,sec90
		,sec120
		,sec180
		,long_time
	} index_t;

};

/*
ExpectedIdlePeriod ::= INTEGER (1..30|40|50|60|80|100|120|150|180|181,...)
*/

struct ExpectedIdlePeriod : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<1, 30>,asn::one<40>,asn::one<50>,asn::one<60>,asn::one<80>,asn::one<100>,asn::one<120>,asn::one<150>,asn::one<180>,asn::one<181>>;
	static constexpr const char* name() {return "ExpectedIdlePeriod";}
	using parent_t = asn::integer<>;

};

/*
SourceOfUEActivityBehaviourInformation ::= ENUMERATED {
	subscription-information,
	statistics,
	...
}
*/

struct SourceOfUEActivityBehaviourInformation : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "SourceOfUEActivityBehaviourInformation";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		subscription_information
		,statistics
	} index_t;

};

/*
ExpectedUEActivityBehaviour-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ExpectedUEActivityBehaviour_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ExpectedUEActivityBehaviour ::= SEQUENCE {
	expectedActivityPeriod					ExpectedActivityPeriod					OPTIONAL,
	expectedIdlePeriod						ExpectedIdlePeriod						OPTIONAL,
	sourceofUEActivityBehaviourInformation	SourceOfUEActivityBehaviourInformation	OPTIONAL,
	iE-Extensions		ProtocolExtensionContainer { {ExpectedUEActivityBehaviour-ExtIEs} } OPTIONAL,
	...
}
*/

struct ExpectedUEActivityBehaviour : asn::sequence<4, 0, true, 4>
{
	static constexpr const char* name() {return "ExpectedUEActivityBehaviour";}
	using parent_t = asn::sequence<4, 0, true, 4>;
	struct expectedActivityPeriod_t : ExpectedActivityPeriod
	{
		static constexpr const char* name() {return "expectedActivityPeriod_t";}
		using parent_t = ExpectedActivityPeriod;
		static constexpr bool optional = true;

	};
	expectedActivityPeriod_t& set_expectedActivityPeriod() { expectedActivityPeriod.setpresent(true); return expectedActivityPeriod;}
	expectedActivityPeriod_t const* get_expectedActivityPeriod() const {return expectedActivityPeriod.is_valid() ? &expectedActivityPeriod : nullptr;}
	struct expectedIdlePeriod_t : ExpectedIdlePeriod
	{
		static constexpr const char* name() {return "expectedIdlePeriod_t";}
		using parent_t = ExpectedIdlePeriod;
		static constexpr bool optional = true;

	};
	expectedIdlePeriod_t& set_expectedIdlePeriod() { expectedIdlePeriod.setpresent(true); return expectedIdlePeriod;}
	expectedIdlePeriod_t const* get_expectedIdlePeriod() const {return expectedIdlePeriod.is_valid() ? &expectedIdlePeriod : nullptr;}
	struct sourceofUEActivityBehaviourInformation_t : SourceOfUEActivityBehaviourInformation
	{
		static constexpr const char* name() {return "sourceofUEActivityBehaviourInformation_t";}
		using parent_t = SourceOfUEActivityBehaviourInformation;
		static constexpr bool optional = true;

	};
	sourceofUEActivityBehaviourInformation_t& set_sourceofUEActivityBehaviourInformation() { sourceofUEActivityBehaviourInformation.setpresent(true); return sourceofUEActivityBehaviourInformation;}
	sourceofUEActivityBehaviourInformation_t const* get_sourceofUEActivityBehaviourInformation() const {return sourceofUEActivityBehaviourInformation.is_valid() ? &sourceofUEActivityBehaviourInformation : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ExpectedUEActivityBehaviour_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ExpectedUEActivityBehaviour_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(expectedActivityPeriod);
		v(expectedIdlePeriod);
		v(sourceofUEActivityBehaviourInformation);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(expectedActivityPeriod);
		v(expectedIdlePeriod);
		v(sourceofUEActivityBehaviourInformation);
		v(iE_Extensions);

	};
	void clear()
	{
		expectedActivityPeriod.clear();
		expectedIdlePeriod.clear();
		sourceofUEActivityBehaviourInformation.clear();
		iE_Extensions.clear();

	};
	private:
	expectedActivityPeriod_t	expectedActivityPeriod;
	expectedIdlePeriod_t	expectedIdlePeriod;
	sourceofUEActivityBehaviourInformation_t	sourceofUEActivityBehaviourInformation;
	iE_Extensions_t	iE_Extensions;

};
/*
ExpectedUEBehaviour-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ExpectedUEBehaviour_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ExpectedUEBehaviour ::= SEQUENCE {
	expectedActivity		ExpectedUEActivityBehaviour OPTIONAL,
	expectedHOInterval		ExpectedHOInterval			OPTIONAL,
	iE-Extensions			ProtocolExtensionContainer { {ExpectedUEBehaviour-ExtIEs} } OPTIONAL,
	...
}
*/

struct ExpectedUEBehaviour : asn::sequence<3, 0, true, 3>
{
	static constexpr const char* name() {return "ExpectedUEBehaviour";}
	using parent_t = asn::sequence<3, 0, true, 3>;
	struct expectedActivity_t : ExpectedUEActivityBehaviour
	{
		static constexpr const char* name() {return "expectedActivity_t";}
		using parent_t = ExpectedUEActivityBehaviour;
		static constexpr bool optional = true;

	};
	expectedActivity_t& set_expectedActivity() { expectedActivity.setpresent(true); return expectedActivity;}
	expectedActivity_t const* get_expectedActivity() const {return expectedActivity.is_valid() ? &expectedActivity : nullptr;}
	struct expectedHOInterval_t : ExpectedHOInterval
	{
		static constexpr const char* name() {return "expectedHOInterval_t";}
		using parent_t = ExpectedHOInterval;
		static constexpr bool optional = true;

	};
	expectedHOInterval_t& set_expectedHOInterval() { expectedHOInterval.setpresent(true); return expectedHOInterval;}
	expectedHOInterval_t const* get_expectedHOInterval() const {return expectedHOInterval.is_valid() ? &expectedHOInterval : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ExpectedUEBehaviour_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ExpectedUEBehaviour_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(expectedActivity);
		v(expectedHOInterval);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(expectedActivity);
		v(expectedHOInterval);
		v(iE_Extensions);

	};
	void clear()
	{
		expectedActivity.clear();
		expectedHOInterval.clear();
		iE_Extensions.clear();

	};
	private:
	expectedActivity_t	expectedActivity;
	expectedHOInterval_t	expectedHOInterval;
	iE_Extensions_t	iE_Extensions;

};
/*
UL-InterferenceOverloadIndication-Item ::= ENUMERATED {
	high-interference,
	medium-interference,
	low-interference,
	...
}
*/

struct UL_InterferenceOverloadIndication_Item : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "UL-InterferenceOverloadIndication-Item";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		high_interference
		,medium_interference
		,low_interference
	} index_t;

};

/*
UL-InterferenceOverloadIndication ::= SEQUENCE (SIZE(1..maxnoofPRBs)) OF UL-InterferenceOverloadIndication-Item
*/

struct UL_InterferenceOverloadIndication_elm : UL_InterferenceOverloadIndication_Item
{
	static constexpr const char* name() {return "UL_InterferenceOverloadIndication_elm";}
	using parent_t = UL_InterferenceOverloadIndication_Item;

};
struct UL_InterferenceOverloadIndication : asn::sequenceof<UL_InterferenceOverloadIndication_elm>
{
	static constexpr const char* name() {return "UL-InterferenceOverloadIndication";}
	using parent_t = asn::sequenceof<UL_InterferenceOverloadIndication_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofPRBs >>;

};
/*
ExtendedULInterferenceOverloadInfo-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ExtendedULInterferenceOverloadInfo_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ExtendedULInterferenceOverloadInfo ::= SEQUENCE {
	associatedSubframes							BIT STRING (SIZE (5)),
	extended-ul-InterferenceOverloadIndication	UL-InterferenceOverloadIndication,
	iE-Extensions								ProtocolExtensionContainer { {ExtendedULInterferenceOverloadInfo-ExtIEs} } OPTIONAL,
	...
}
*/

struct ExtendedULInterferenceOverloadInfo : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "ExtendedULInterferenceOverloadInfo";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct associatedSubframes_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<5>>;
		static constexpr const char* name() {return "associatedSubframes_t";}
		using parent_t = asn::bstring<>;

	};

	associatedSubframes_t& ref_associatedSubframes() {return associatedSubframes;}
	associatedSubframes_t const& ref_associatedSubframes() const {return associatedSubframes;}
	struct extended_ul_InterferenceOverloadIndication_t : UL_InterferenceOverloadIndication
	{
		static constexpr const char* name() {return "extended_ul_InterferenceOverloadIndication_t";}
		using parent_t = UL_InterferenceOverloadIndication;

	};
	extended_ul_InterferenceOverloadIndication_t& ref_extended_ul_InterferenceOverloadIndication() {return extended_ul_InterferenceOverloadIndication;}
	extended_ul_InterferenceOverloadIndication_t const& ref_extended_ul_InterferenceOverloadIndication() const {return extended_ul_InterferenceOverloadIndication;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ExtendedULInterferenceOverloadInfo_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ExtendedULInterferenceOverloadInfo_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(associatedSubframes);
		v(extended_ul_InterferenceOverloadIndication);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(associatedSubframes);
		v(extended_ul_InterferenceOverloadIndication);
		v(iE_Extensions);

	};
	void clear()
	{
		associatedSubframes.clear();
		extended_ul_InterferenceOverloadIndication.clear();
		iE_Extensions.clear();

	};
	private:
	associatedSubframes_t	associatedSubframes;
	extended_ul_InterferenceOverloadIndication_t	extended_ul_InterferenceOverloadIndication;
	iE_Extensions_t	iE_Extensions;

};
/*
FiveGS-TAC ::= OCTET STRING (SIZE (3))
*/

struct FiveGS_TAC : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<3>>;
	static constexpr const char* name() {return "FiveGS-TAC";}
	using parent_t = asn::ostring<>;

};

/*
ForbiddenInterRATs ::= ENUMERATED {
	all,
	geran,
	utran,
	cdma2000,
	...,
	geranandutran,
	cdma2000andutran

}
*/

struct ForbiddenInterRATs : asn::enumerated<6, 2, true>
{
	static constexpr const char* name() {return "ForbiddenInterRATs";}
	using parent_t = asn::enumerated<6, 2, true>;
	typedef enum {
		all
		,geran
		,utran
		,cdma2000
		,geranandutran
		,cdma2000andutran
	} index_t;

};

/*
LAC					::= OCTET STRING (SIZE (2)) --(EXCEPT ('0000'H|'FFFE'H))
*/

struct LAC : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<2>>;
	static constexpr const char* name() {return "LAC";}
	using parent_t = asn::ostring<>;

};

/*
ForbiddenLACs ::= SEQUENCE (SIZE(1..maxnoofForbLACs)) OF LAC
*/

struct ForbiddenLACs_elm : LAC
{
	static constexpr const char* name() {return "ForbiddenLACs_elm";}
	using parent_t = LAC;

};
struct ForbiddenLACs : asn::sequenceof<ForbiddenLACs_elm>
{
	static constexpr const char* name() {return "ForbiddenLACs";}
	using parent_t = asn::sequenceof<ForbiddenLACs_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofForbLACs >>;

};
/*
ForbiddenLAs-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ForbiddenLAs_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ForbiddenLAs-Item ::= SEQUENCE {
	pLMN-Identity		PLMN-Identity,
	forbiddenLACs		ForbiddenLACs,
	iE-Extensions		ProtocolExtensionContainer { {ForbiddenLAs-Item-ExtIEs} } OPTIONAL,
	...
}
*/

struct ForbiddenLAs_Item : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "ForbiddenLAs-Item";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pLMN_Identity_t : PLMN_Identity
	{
		static constexpr const char* name() {return "pLMN_Identity_t";}
		using parent_t = PLMN_Identity;

	};
	pLMN_Identity_t& ref_pLMN_Identity() {return pLMN_Identity;}
	pLMN_Identity_t const& ref_pLMN_Identity() const {return pLMN_Identity;}
	struct forbiddenLACs_t : ForbiddenLACs
	{
		static constexpr const char* name() {return "forbiddenLACs_t";}
		using parent_t = ForbiddenLACs;

	};
	forbiddenLACs_t& ref_forbiddenLACs() {return forbiddenLACs;}
	forbiddenLACs_t const& ref_forbiddenLACs() const {return forbiddenLACs;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ForbiddenLAs_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ForbiddenLAs_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pLMN_Identity);
		v(forbiddenLACs);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pLMN_Identity);
		v(forbiddenLACs);
		v(iE_Extensions);

	};
	void clear()
	{
		pLMN_Identity.clear();
		forbiddenLACs.clear();
		iE_Extensions.clear();

	};
	private:
	pLMN_Identity_t	pLMN_Identity;
	forbiddenLACs_t	forbiddenLACs;
	iE_Extensions_t	iE_Extensions;

};
/*
ForbiddenLAs ::= SEQUENCE (SIZE(1..maxnoofEPLMNsPlusOne)) OF ForbiddenLAs-Item
*/

struct ForbiddenLAs_elm : ForbiddenLAs_Item
{
	static constexpr const char* name() {return "ForbiddenLAs_elm";}
	using parent_t = ForbiddenLAs_Item;

};
struct ForbiddenLAs : asn::sequenceof<ForbiddenLAs_elm>
{
	static constexpr const char* name() {return "ForbiddenLAs";}
	using parent_t = asn::sequenceof<ForbiddenLAs_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofEPLMNsPlusOne >>;

};
/*
ForbiddenTACs ::= SEQUENCE (SIZE(1..maxnoofForbTACs)) OF TAC
*/

struct ForbiddenTACs_elm : TAC
{
	static constexpr const char* name() {return "ForbiddenTACs_elm";}
	using parent_t = TAC;

};
struct ForbiddenTACs : asn::sequenceof<ForbiddenTACs_elm>
{
	static constexpr const char* name() {return "ForbiddenTACs";}
	using parent_t = asn::sequenceof<ForbiddenTACs_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofForbTACs >>;

};
/*
ForbiddenTAs-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ForbiddenTAs_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ForbiddenTAs-Item ::= SEQUENCE {
	pLMN-Identity		PLMN-Identity,
	forbiddenTACs		ForbiddenTACs,
	iE-Extensions		ProtocolExtensionContainer { {ForbiddenTAs-Item-ExtIEs} } OPTIONAL,
	...
}
*/

struct ForbiddenTAs_Item : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "ForbiddenTAs-Item";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pLMN_Identity_t : PLMN_Identity
	{
		static constexpr const char* name() {return "pLMN_Identity_t";}
		using parent_t = PLMN_Identity;

	};
	pLMN_Identity_t& ref_pLMN_Identity() {return pLMN_Identity;}
	pLMN_Identity_t const& ref_pLMN_Identity() const {return pLMN_Identity;}
	struct forbiddenTACs_t : ForbiddenTACs
	{
		static constexpr const char* name() {return "forbiddenTACs_t";}
		using parent_t = ForbiddenTACs;

	};
	forbiddenTACs_t& ref_forbiddenTACs() {return forbiddenTACs;}
	forbiddenTACs_t const& ref_forbiddenTACs() const {return forbiddenTACs;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ForbiddenTAs_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ForbiddenTAs_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pLMN_Identity);
		v(forbiddenTACs);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pLMN_Identity);
		v(forbiddenTACs);
		v(iE_Extensions);

	};
	void clear()
	{
		pLMN_Identity.clear();
		forbiddenTACs.clear();
		iE_Extensions.clear();

	};
	private:
	pLMN_Identity_t	pLMN_Identity;
	forbiddenTACs_t	forbiddenTACs;
	iE_Extensions_t	iE_Extensions;

};
/*
ForbiddenTAs ::= SEQUENCE (SIZE(1.. maxnoofEPLMNsPlusOne)) OF ForbiddenTAs-Item
*/

struct ForbiddenTAs_elm : ForbiddenTAs_Item
{
	static constexpr const char* name() {return "ForbiddenTAs_elm";}
	using parent_t = ForbiddenTAs_Item;

};
struct ForbiddenTAs : asn::sequenceof<ForbiddenTAs_elm>
{
	static constexpr const char* name() {return "ForbiddenTAs";}
	using parent_t = asn::sequenceof<ForbiddenTAs_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofEPLMNsPlusOne >>;

};
/*
Fourframes ::= BIT STRING (SIZE (24))
*/

struct Fourframes : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<24>>;
	static constexpr const char* name() {return "Fourframes";}
	using parent_t = asn::bstring<>;

};

/*
FreqBandIndicatorPriority ::= ENUMERATED {
	not-broadcasted,
	broadcasted,
	...
}
*/

struct FreqBandIndicatorPriority : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "FreqBandIndicatorPriority";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		not_broadcasted
		,broadcasted
	} index_t;

};

/*
SupportedSULFreqBandItem-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct SupportedSULFreqBandItem_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
SupportedSULFreqBandItem ::= SEQUENCE {
	freqBandIndicatorNr 			INTEGER (1..1024,...),
	iE-Extensions			ProtocolExtensionContainer { {SupportedSULFreqBandItem-ExtIEs} }		OPTIONAL,
	...
}
*/

struct SupportedSULFreqBandItem : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "SupportedSULFreqBandItem";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct freqBandIndicatorNr_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 1024>>;
		static constexpr const char* name() {return "freqBandIndicatorNr_t";}
		using parent_t = asn::integer<>;

	};

	freqBandIndicatorNr_t& ref_freqBandIndicatorNr() {return freqBandIndicatorNr;}
	freqBandIndicatorNr_t const& ref_freqBandIndicatorNr() const {return freqBandIndicatorNr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<SupportedSULFreqBandItem_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<SupportedSULFreqBandItem_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(freqBandIndicatorNr);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(freqBandIndicatorNr);
		v(iE_Extensions);

	};
	void clear()
	{
		freqBandIndicatorNr.clear();
		iE_Extensions.clear();

	};
	private:
	freqBandIndicatorNr_t	freqBandIndicatorNr;
	iE_Extensions_t	iE_Extensions;

};
/*
FreqBandNrItem-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct FreqBandNrItem_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
FreqBandNrItem ::= SEQUENCE {
	freqBandIndicatorNr 			INTEGER (1..1024,...),
	supportedSULBandList	SEQUENCE (SIZE(0..maxnoofNrCellBands)) OF SupportedSULFreqBandItem,
	iE-Extensions				ProtocolExtensionContainer { {FreqBandNrItem-ExtIEs} } OPTIONAL,
	...
}
*/

struct FreqBandNrItem : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "FreqBandNrItem";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct freqBandIndicatorNr_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 1024>>;
		static constexpr const char* name() {return "freqBandIndicatorNr_t";}
		using parent_t = asn::integer<>;

	};

	freqBandIndicatorNr_t& ref_freqBandIndicatorNr() {return freqBandIndicatorNr;}
	freqBandIndicatorNr_t const& ref_freqBandIndicatorNr() const {return freqBandIndicatorNr;}
	struct supportedSULBandList_t_elm : SupportedSULFreqBandItem
	{
		static constexpr const char* name() {return "supportedSULBandList_t_elm";}
		using parent_t = SupportedSULFreqBandItem;

	};
	struct supportedSULBandList_t : asn::sequenceof<supportedSULBandList_t_elm>
	{
		static constexpr const char* name() {return "supportedSULBandList_t";}
		using parent_t = asn::sequenceof<supportedSULBandList_t_elm>;
		using constraint_t = asn::constraints<false,asn::span<0,  maxnoofNrCellBands >>;

	};
	supportedSULBandList_t& ref_supportedSULBandList() {return supportedSULBandList;}
	supportedSULBandList_t const& ref_supportedSULBandList() const {return supportedSULBandList;}
	struct iE_Extensions_t : ProtocolExtensionContainer<FreqBandNrItem_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<FreqBandNrItem_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(freqBandIndicatorNr);
		v(supportedSULBandList);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(freqBandIndicatorNr);
		v(supportedSULBandList);
		v(iE_Extensions);

	};
	void clear()
	{
		freqBandIndicatorNr.clear();
		supportedSULBandList.clear();
		iE_Extensions.clear();

	};
	private:
	freqBandIndicatorNr_t	freqBandIndicatorNr;
	supportedSULBandList_t	supportedSULBandList;
	iE_Extensions_t	iE_Extensions;

};
/*
GNB-ID ::= CHOICE {
	gNB-ID	BIT STRING (SIZE (22..32)),
	...
}
*/

struct GNB_ID : asn::choice<1, 0, true>
{
	static constexpr const char* name() {return "GNB-ID";}
	using parent_t = asn::choice<1, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 2;}
	void set_unknown() { set_index(2);  }
	~GNB_ID() {clear();}
	struct gNB_ID_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::span<22, 32>>;
		static constexpr const char* name() {return "gNB_ID_t";}
		using parent_t = asn::bstring<>;

	};

	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<gNB_ID_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<gNB_ID_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<gNB_ID_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<gNB_ID_t>(1);

	}
	gNB_ID_t& select_gNB_ID() { if(get_index() != 1) { clear(); set_index(1); return var.build<gNB_ID_t>();} return var.as<gNB_ID_t>();}
	gNB_ID_t const* get_gNB_ID() const { if(get_index() == 1) { return &var.as<gNB_ID_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(gNB_ID_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
GNBOverloadInformation ::= ENUMERATED {overloaded, not-overloaded, ...}
*/

struct GNBOverloadInformation : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "GNBOverloadInformation";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		overloaded
		,not_overloaded
	} index_t;

};

/*
GTP-TEI					::= OCTET STRING (SIZE (4))
*/

struct GTP_TEI : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<4>>;
	static constexpr const char* name() {return "GTP-TEI";}
	using parent_t = asn::ostring<>;

};

/*
TransportLayerAddress			::= BIT STRING (SIZE(1..160, ...))
*/

struct TransportLayerAddress : asn::bstring<>
{
	using constraint_t = asn::constraints<true,asn::span<1, 160>>;
	static constexpr const char* name() {return "TransportLayerAddress";}
	using parent_t = asn::bstring<>;

};

/*
GTPtunnelEndpoint-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct GTPtunnelEndpoint_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
GTPtunnelEndpoint ::= SEQUENCE {
	transportLayerAddress			TransportLayerAddress,
	gTP-TEID						GTP-TEI,
	iE-Extensions					ProtocolExtensionContainer { {GTPtunnelEndpoint-ExtIEs} } OPTIONAL,
	...
}
*/

struct GTPtunnelEndpoint : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "GTPtunnelEndpoint";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct transportLayerAddress_t : TransportLayerAddress
	{
		static constexpr const char* name() {return "transportLayerAddress_t";}
		using parent_t = TransportLayerAddress;

	};
	transportLayerAddress_t& ref_transportLayerAddress() {return transportLayerAddress;}
	transportLayerAddress_t const& ref_transportLayerAddress() const {return transportLayerAddress;}
	struct gTP_TEID_t : GTP_TEI
	{
		static constexpr const char* name() {return "gTP_TEID_t";}
		using parent_t = GTP_TEI;

	};
	gTP_TEID_t& ref_gTP_TEID() {return gTP_TEID;}
	gTP_TEID_t const& ref_gTP_TEID() const {return gTP_TEID;}
	struct iE_Extensions_t : ProtocolExtensionContainer<GTPtunnelEndpoint_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<GTPtunnelEndpoint_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(transportLayerAddress);
		v(gTP_TEID);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(transportLayerAddress);
		v(gTP_TEID);
		v(iE_Extensions);

	};
	void clear()
	{
		transportLayerAddress.clear();
		gTP_TEID.clear();
		iE_Extensions.clear();

	};
	private:
	transportLayerAddress_t	transportLayerAddress;
	gTP_TEID_t	gTP_TEID;
	iE_Extensions_t	iE_Extensions;

};
/*
MME-Group-ID	::= OCTET STRING (SIZE (2))
*/

struct MME_Group_ID : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<2>>;
	static constexpr const char* name() {return "MME-Group-ID";}
	using parent_t = asn::ostring<>;

};

/*
GU-Group-ID-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct GU_Group_ID_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
GU-Group-ID			::= SEQUENCE {
	pLMN-Identity		PLMN-Identity,
	mME-Group-ID		MME-Group-ID,
	iE-Extensions		ProtocolExtensionContainer { {GU-Group-ID-ExtIEs} } OPTIONAL,
	...
}
*/

struct GU_Group_ID : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "GU-Group-ID";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pLMN_Identity_t : PLMN_Identity
	{
		static constexpr const char* name() {return "pLMN_Identity_t";}
		using parent_t = PLMN_Identity;

	};
	pLMN_Identity_t& ref_pLMN_Identity() {return pLMN_Identity;}
	pLMN_Identity_t const& ref_pLMN_Identity() const {return pLMN_Identity;}
	struct mME_Group_ID_t : MME_Group_ID
	{
		static constexpr const char* name() {return "mME_Group_ID_t";}
		using parent_t = MME_Group_ID;

	};
	mME_Group_ID_t& ref_mME_Group_ID() {return mME_Group_ID;}
	mME_Group_ID_t const& ref_mME_Group_ID() const {return mME_Group_ID;}
	struct iE_Extensions_t : ProtocolExtensionContainer<GU_Group_ID_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<GU_Group_ID_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pLMN_Identity);
		v(mME_Group_ID);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pLMN_Identity);
		v(mME_Group_ID);
		v(iE_Extensions);

	};
	void clear()
	{
		pLMN_Identity.clear();
		mME_Group_ID.clear();
		iE_Extensions.clear();

	};
	private:
	pLMN_Identity_t	pLMN_Identity;
	mME_Group_ID_t	mME_Group_ID;
	iE_Extensions_t	iE_Extensions;

};
/*
GUGroupIDList		::= SEQUENCE (SIZE (1..maxPools)) OF GU-Group-ID
*/

struct GUGroupIDList_elm : GU_Group_ID
{
	static constexpr const char* name() {return "GUGroupIDList_elm";}
	using parent_t = GU_Group_ID;

};
struct GUGroupIDList : asn::sequenceof<GUGroupIDList_elm>
{
	static constexpr const char* name() {return "GUGroupIDList";}
	using parent_t = asn::sequenceof<GUGroupIDList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxPools >>;

};
/*
MME-Code		::= OCTET STRING (SIZE (1))
*/

struct MME_Code : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<1>>;
	static constexpr const char* name() {return "MME-Code";}
	using parent_t = asn::ostring<>;

};

/*
GUMMEI-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct GUMMEI_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
GUMMEI			::= SEQUENCE {

	gU-Group-ID		GU-Group-ID,
	mME-Code			MME-Code,
	iE-Extensions					ProtocolExtensionContainer { {GUMMEI-ExtIEs} } OPTIONAL,
	...
}
*/

struct GUMMEI : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "GUMMEI";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct gU_Group_ID_t : GU_Group_ID
	{
		static constexpr const char* name() {return "gU_Group_ID_t";}
		using parent_t = GU_Group_ID;

	};
	gU_Group_ID_t& ref_gU_Group_ID() {return gU_Group_ID;}
	gU_Group_ID_t const& ref_gU_Group_ID() const {return gU_Group_ID;}
	struct mME_Code_t : MME_Code
	{
		static constexpr const char* name() {return "mME_Code_t";}
		using parent_t = MME_Code;

	};
	mME_Code_t& ref_mME_Code() {return mME_Code;}
	mME_Code_t const& ref_mME_Code() const {return mME_Code;}
	struct iE_Extensions_t : ProtocolExtensionContainer<GUMMEI_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<GUMMEI_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(gU_Group_ID);
		v(mME_Code);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(gU_Group_ID);
		v(mME_Code);
		v(iE_Extensions);

	};
	void clear()
	{
		gU_Group_ID.clear();
		mME_Code.clear();
		iE_Extensions.clear();

	};
	private:
	gU_Group_ID_t	gU_Group_ID;
	mME_Code_t	mME_Code;
	iE_Extensions_t	iE_Extensions;

};
/*
GlobalENB-ID-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct GlobalENB_ID_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
GlobalENB-ID ::= SEQUENCE {
	pLMN-Identity			PLMN-Identity,
	eNB-ID					ENB-ID,
	iE-Extensions			ProtocolExtensionContainer { {GlobalENB-ID-ExtIEs} } OPTIONAL,
	...
}
*/

struct GlobalENB_ID : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "GlobalENB-ID";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pLMN_Identity_t : PLMN_Identity
	{
		static constexpr const char* name() {return "pLMN_Identity_t";}
		using parent_t = PLMN_Identity;

	};
	pLMN_Identity_t& ref_pLMN_Identity() {return pLMN_Identity;}
	pLMN_Identity_t const& ref_pLMN_Identity() const {return pLMN_Identity;}
	struct eNB_ID_t : ENB_ID
	{
		static constexpr const char* name() {return "eNB_ID_t";}
		using parent_t = ENB_ID;

	};
	eNB_ID_t& ref_eNB_ID() {return eNB_ID;}
	eNB_ID_t const& ref_eNB_ID() const {return eNB_ID;}
	struct iE_Extensions_t : ProtocolExtensionContainer<GlobalENB_ID_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<GlobalENB_ID_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pLMN_Identity);
		v(eNB_ID);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pLMN_Identity);
		v(eNB_ID);
		v(iE_Extensions);

	};
	void clear()
	{
		pLMN_Identity.clear();
		eNB_ID.clear();
		iE_Extensions.clear();

	};
	private:
	pLMN_Identity_t	pLMN_Identity;
	eNB_ID_t	eNB_ID;
	iE_Extensions_t	iE_Extensions;

};
/*
GlobalGNB-ID-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct GlobalGNB_ID_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
GlobalGNB-ID ::= SEQUENCE {
	pLMN-Identity			PLMN-Identity,
	gNB-ID					GNB-ID,
	iE-Extensions			ProtocolExtensionContainer { {GlobalGNB-ID-ExtIEs} } OPTIONAL,
	...
}
*/

struct GlobalGNB_ID : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "GlobalGNB-ID";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pLMN_Identity_t : PLMN_Identity
	{
		static constexpr const char* name() {return "pLMN_Identity_t";}
		using parent_t = PLMN_Identity;

	};
	pLMN_Identity_t& ref_pLMN_Identity() {return pLMN_Identity;}
	pLMN_Identity_t const& ref_pLMN_Identity() const {return pLMN_Identity;}
	struct gNB_ID_t : GNB_ID
	{
		static constexpr const char* name() {return "gNB_ID_t";}
		using parent_t = GNB_ID;

	};
	gNB_ID_t& ref_gNB_ID() {return gNB_ID;}
	gNB_ID_t const& ref_gNB_ID() const {return gNB_ID;}
	struct iE_Extensions_t : ProtocolExtensionContainer<GlobalGNB_ID_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<GlobalGNB_ID_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pLMN_Identity);
		v(gNB_ID);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pLMN_Identity);
		v(gNB_ID);
		v(iE_Extensions);

	};
	void clear()
	{
		pLMN_Identity.clear();
		gNB_ID.clear();
		iE_Extensions.clear();

	};
	private:
	pLMN_Identity_t	pLMN_Identity;
	gNB_ID_t	gNB_ID;
	iE_Extensions_t	iE_Extensions;

};
/*
LoadIndicator ::= ENUMERATED {
	lowLoad,
	mediumLoad,
	highLoad,
	overLoad,
	...
}
*/

struct LoadIndicator : asn::enumerated<4, 0, true>
{
	static constexpr const char* name() {return "LoadIndicator";}
	using parent_t = asn::enumerated<4, 0, true>;
	typedef enum {
		lowLoad
		,mediumLoad
		,highLoad
		,overLoad
	} index_t;

};

/*
HWLoadIndicator-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct HWLoadIndicator_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
HWLoadIndicator ::= SEQUENCE {
	dLHWLoadIndicator			LoadIndicator,
	uLHWLoadIndicator			LoadIndicator,
	iE-Extensions				ProtocolExtensionContainer { {HWLoadIndicator-ExtIEs} } OPTIONAL,
	...
}
*/

struct HWLoadIndicator : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "HWLoadIndicator";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct dLHWLoadIndicator_t : LoadIndicator
	{
		static constexpr const char* name() {return "dLHWLoadIndicator_t";}
		using parent_t = LoadIndicator;

	};
	dLHWLoadIndicator_t& ref_dLHWLoadIndicator() {return dLHWLoadIndicator;}
	dLHWLoadIndicator_t const& ref_dLHWLoadIndicator() const {return dLHWLoadIndicator;}
	struct uLHWLoadIndicator_t : LoadIndicator
	{
		static constexpr const char* name() {return "uLHWLoadIndicator_t";}
		using parent_t = LoadIndicator;

	};
	uLHWLoadIndicator_t& ref_uLHWLoadIndicator() {return uLHWLoadIndicator;}
	uLHWLoadIndicator_t const& ref_uLHWLoadIndicator() const {return uLHWLoadIndicator;}
	struct iE_Extensions_t : ProtocolExtensionContainer<HWLoadIndicator_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<HWLoadIndicator_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(dLHWLoadIndicator);
		v(uLHWLoadIndicator);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(dLHWLoadIndicator);
		v(uLHWLoadIndicator);
		v(iE_Extensions);

	};
	void clear()
	{
		dLHWLoadIndicator.clear();
		uLHWLoadIndicator.clear();
		iE_Extensions.clear();

	};
	private:
	dLHWLoadIndicator_t	dLHWLoadIndicator;
	uLHWLoadIndicator_t	uLHWLoadIndicator;
	iE_Extensions_t	iE_Extensions;

};
/*
HandoverReportType ::= ENUMERATED {
	hoTooEarly,
	hoToWrongCell,
	...,
	interRATpingpong
}
*/

struct HandoverReportType : asn::enumerated<3, 1, true>
{
	static constexpr const char* name() {return "HandoverReportType";}
	using parent_t = asn::enumerated<3, 1, true>;
	typedef enum {
		hoTooEarly
		,hoToWrongCell
		,interRATpingpong
	} index_t;

};

/*
NRrestrictioninEPSasSecondaryRAT ::= ENUMERATED {
	nRrestrictedinEPSasSecondaryRAT,
	...
}
*/

struct NRrestrictioninEPSasSecondaryRAT : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "NRrestrictioninEPSasSecondaryRAT";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		nRrestrictedinEPSasSecondaryRAT
	} index_t;

};

/*
NRrestrictionin5GS ::= ENUMERATED {
	nRrestrictedin5GS,
	...
}
*/

struct NRrestrictionin5GS : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "NRrestrictionin5GS";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		nRrestrictedin5GS
	} index_t;

};

/*
HandoverRestrictionList-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-NRrestrictioninEPSasSecondaryRAT			CRITICALITY ignore	EXTENSION NRrestrictioninEPSasSecondaryRAT			PRESENCE optional}|
	{ ID id-CNTypeRestrictions						CRITICALITY ignore	EXTENSION CNTypeRestrictions								PRESENCE optional}|
	{ ID id-NRrestrictionin5GS						CRITICALITY ignore	EXTENSION NRrestrictionin5GS								PRESENCE optional},
	...
}
*/

struct HandoverRestrictionList_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_NRrestrictioninEPSasSecondaryRAT() { set(id_NRrestrictioninEPSasSecondaryRAT); type=1;}
		void select_id_CNTypeRestrictions() { set(id_CNTypeRestrictions); type=2;}
		void select_id_NRrestrictionin5GS() { set(id_NRrestrictionin5GS); type=3;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_NRrestrictioninEPSasSecondaryRAT)) { type = 1; return true; }
			else if(equal(id_CNTypeRestrictions)) { type = 2; return true; }
			else if(equal(id_NRrestrictionin5GS)) { type = 3; return true; }
			else { type = 4; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_NRrestrictioninEPSasSecondaryRAT);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_CNTypeRestrictions);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_NRrestrictionin5GS);} return false;
			case 4: type = 4; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_NRrestrictioninEPSasSecondaryRAT() { set(ignore); type=1;}
		void select_id_CNTypeRestrictions() { set(ignore); type=2;}
		void select_id_NRrestrictionin5GS() { set(ignore); type=3;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else if(equal(ignore)) { type = 3; return true; }
			else { type = 4; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(ignore);} return false;
			case 4: type = 4; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		NRrestrictioninEPSasSecondaryRAT& select_id_NRrestrictioninEPSasSecondaryRAT() { return set<NRrestrictioninEPSasSecondaryRAT>(1); }
		NRrestrictioninEPSasSecondaryRAT const* get_id_NRrestrictioninEPSasSecondaryRAT() const { return get<NRrestrictioninEPSasSecondaryRAT>(1); }
		CNTypeRestrictions& select_id_CNTypeRestrictions() { return set<CNTypeRestrictions>(2); }
		CNTypeRestrictions const* get_id_CNTypeRestrictions() const { return get<CNTypeRestrictions>(2); }
		NRrestrictionin5GS& select_id_NRrestrictionin5GS() { return set<NRrestrictionin5GS>(3); }
		NRrestrictionin5GS const* get_id_NRrestrictionin5GS() const { return get<NRrestrictionin5GS>(3); }
		bool is_unknown() const { return type == 4; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<NRrestrictioninEPSasSecondaryRAT>(); break;
			case 2: var.destroy<CNTypeRestrictions>(); break;
			case 3: var.destroy<NRrestrictionin5GS>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<NRrestrictioninEPSasSecondaryRAT>(1);
			v.template operator()<CNTypeRestrictions>(2);
			v.template operator()<NRrestrictionin5GS>(3);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_NRrestrictioninEPSasSecondaryRAT()); return true;
			case 2: v(select_id_CNTypeRestrictions()); return true;
			case 3: v(select_id_NRrestrictionin5GS()); return true;
			case 4: if(type != 4) {clear(); asn::base::set();} type = 4; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<NRrestrictioninEPSasSecondaryRAT>()); return true;
			case 2: v(var.as<CNTypeRestrictions>()); return true;
			case 3: v(var.as<NRrestrictionin5GS>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(CNTypeRestrictions)];
			char dummy2[sizeof(NRrestrictionin5GS)];
			char dummy3[sizeof(NRrestrictioninEPSasSecondaryRAT)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_NRrestrictioninEPSasSecondaryRAT() { set(optional); type=1;}
		void select_id_CNTypeRestrictions() { set(optional); type=2;}
		void select_id_NRrestrictionin5GS() { set(optional); type=3;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else if(equal(optional)) { type = 3; return true; }
			else { type = 4; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(optional);} return false;
			case 4: type = 4; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
HandoverRestrictionList ::= SEQUENCE {
	servingPLMN					PLMN-Identity,
	equivalentPLMNs				EPLMNs					OPTIONAL,
	forbiddenTAs				ForbiddenTAs			OPTIONAL,
	forbiddenLAs				ForbiddenLAs			OPTIONAL,
	forbiddenInterRATs			ForbiddenInterRATs		OPTIONAL,
	iE-Extensions				ProtocolExtensionContainer { {HandoverRestrictionList-ExtIEs} }	OPTIONAL,
	...
}
*/

struct HandoverRestrictionList : asn::sequence<6, 0, true, 5>
{
	static constexpr const char* name() {return "HandoverRestrictionList";}
	using parent_t = asn::sequence<6, 0, true, 5>;
	struct servingPLMN_t : PLMN_Identity
	{
		static constexpr const char* name() {return "servingPLMN_t";}
		using parent_t = PLMN_Identity;

	};
	servingPLMN_t& ref_servingPLMN() {return servingPLMN;}
	servingPLMN_t const& ref_servingPLMN() const {return servingPLMN;}
	struct equivalentPLMNs_t : EPLMNs
	{
		static constexpr const char* name() {return "equivalentPLMNs_t";}
		using parent_t = EPLMNs;
		static constexpr bool optional = true;

	};
	equivalentPLMNs_t& set_equivalentPLMNs() { equivalentPLMNs.setpresent(true); return equivalentPLMNs;}
	equivalentPLMNs_t const* get_equivalentPLMNs() const {return equivalentPLMNs.is_valid() ? &equivalentPLMNs : nullptr;}
	struct forbiddenTAs_t : ForbiddenTAs
	{
		static constexpr const char* name() {return "forbiddenTAs_t";}
		using parent_t = ForbiddenTAs;
		static constexpr bool optional = true;

	};
	forbiddenTAs_t& set_forbiddenTAs() { forbiddenTAs.setpresent(true); return forbiddenTAs;}
	forbiddenTAs_t const* get_forbiddenTAs() const {return forbiddenTAs.is_valid() ? &forbiddenTAs : nullptr;}
	struct forbiddenLAs_t : ForbiddenLAs
	{
		static constexpr const char* name() {return "forbiddenLAs_t";}
		using parent_t = ForbiddenLAs;
		static constexpr bool optional = true;

	};
	forbiddenLAs_t& set_forbiddenLAs() { forbiddenLAs.setpresent(true); return forbiddenLAs;}
	forbiddenLAs_t const* get_forbiddenLAs() const {return forbiddenLAs.is_valid() ? &forbiddenLAs : nullptr;}
	struct forbiddenInterRATs_t : ForbiddenInterRATs
	{
		static constexpr const char* name() {return "forbiddenInterRATs_t";}
		using parent_t = ForbiddenInterRATs;
		static constexpr bool optional = true;

	};
	forbiddenInterRATs_t& set_forbiddenInterRATs() { forbiddenInterRATs.setpresent(true); return forbiddenInterRATs;}
	forbiddenInterRATs_t const* get_forbiddenInterRATs() const {return forbiddenInterRATs.is_valid() ? &forbiddenInterRATs : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<HandoverRestrictionList_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<HandoverRestrictionList_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(servingPLMN);
		v(equivalentPLMNs);
		v(forbiddenTAs);
		v(forbiddenLAs);
		v(forbiddenInterRATs);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(servingPLMN);
		v(equivalentPLMNs);
		v(forbiddenTAs);
		v(forbiddenLAs);
		v(forbiddenInterRATs);
		v(iE_Extensions);

	};
	void clear()
	{
		servingPLMN.clear();
		equivalentPLMNs.clear();
		forbiddenTAs.clear();
		forbiddenLAs.clear();
		forbiddenInterRATs.clear();
		iE_Extensions.clear();

	};
	private:
	servingPLMN_t	servingPLMN;
	equivalentPLMNs_t	equivalentPLMNs;
	forbiddenTAs_t	forbiddenTAs;
	forbiddenLAs_t	forbiddenLAs;
	forbiddenInterRATs_t	forbiddenInterRATs;
	iE_Extensions_t	iE_Extensions;

};
/*
IntegrityProtectionAlgorithms ::= BIT STRING (SIZE (16, ...))
*/

struct IntegrityProtectionAlgorithms : asn::bstring<>
{
	using constraint_t = asn::constraints<true,asn::one<16>>;
	static constexpr const char* name() {return "IntegrityProtectionAlgorithms";}
	using parent_t = asn::bstring<>;

};

/*
InterfacesToTrace ::= BIT STRING (SIZE (8))
*/

struct InterfacesToTrace : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<8>>;
	static constexpr const char* name() {return "InterfacesToTrace";}
	using parent_t = asn::bstring<>;

};

/*
InvokeIndication ::= ENUMERATED{
	abs-information,
	...,
	naics-information-start,
	naics-information-stop
}
*/

struct InvokeIndication : asn::enumerated<3, 2, true>
{
	static constexpr const char* name() {return "InvokeIndication";}
	using parent_t = asn::enumerated<3, 2, true>;
	typedef enum {
		abs_information
		,naics_information_start
		,naics_information_stop
	} index_t;

};

/*
LCID ::= INTEGER(1..32, ...)
*/

struct LCID : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<1, 32>>;
	static constexpr const char* name() {return "LCID";}
	using parent_t = asn::integer<>;

};

/*
LHN-ID ::= OCTET STRING(SIZE (32..256))
*/

struct LHN_ID : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::span<32, 256>>;
	static constexpr const char* name() {return "LHN-ID";}
	using parent_t = asn::ostring<>;

};

/*
Time-UE-StayedInCell ::= INTEGER (0..4095)
*/

struct Time_UE_StayedInCell : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 4095>>;
	static constexpr const char* name() {return "Time-UE-StayedInCell";}
	using parent_t = asn::integer<>;

};

/*
Time-UE-StayedInCell-EnhancedGranularity ::= INTEGER (0..40950)
*/

struct Time_UE_StayedInCell_EnhancedGranularity : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 40950>>;
	static constexpr const char* name() {return "Time-UE-StayedInCell-EnhancedGranularity";}
	using parent_t = asn::integer<>;

};

/*
LastVisitedEUTRANCellInformation-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
-- Extension for Rel-11 to support enhanced granularity for time UE stayed in cell --
	{ ID id-Time-UE-StayedInCell-EnhancedGranularity	CRITICALITY ignore	EXTENSION Time-UE-StayedInCell-EnhancedGranularity	PRESENCE optional}|
	{ ID id-HO-cause									CRITICALITY ignore	EXTENSION Cause													PRESENCE optional},
	...
}
*/

struct LastVisitedEUTRANCellInformation_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_Time_UE_StayedInCell_EnhancedGranularity() { set(id_Time_UE_StayedInCell_EnhancedGranularity); type=1;}
		void select_id_HO_cause() { set(id_HO_cause); type=2;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_Time_UE_StayedInCell_EnhancedGranularity)) { type = 1; return true; }
			else if(equal(id_HO_cause)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_Time_UE_StayedInCell_EnhancedGranularity);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_HO_cause);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_Time_UE_StayedInCell_EnhancedGranularity() { set(ignore); type=1;}
		void select_id_HO_cause() { set(ignore); type=2;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		Time_UE_StayedInCell_EnhancedGranularity& select_id_Time_UE_StayedInCell_EnhancedGranularity() { return set<Time_UE_StayedInCell_EnhancedGranularity>(1); }
		Time_UE_StayedInCell_EnhancedGranularity const* get_id_Time_UE_StayedInCell_EnhancedGranularity() const { return get<Time_UE_StayedInCell_EnhancedGranularity>(1); }
		Cause& select_id_HO_cause() { return set<Cause>(2); }
		Cause const* get_id_HO_cause() const { return get<Cause>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<Time_UE_StayedInCell_EnhancedGranularity>(); break;
			case 2: var.destroy<Cause>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<Time_UE_StayedInCell_EnhancedGranularity>(1);
			v.template operator()<Cause>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_Time_UE_StayedInCell_EnhancedGranularity()); return true;
			case 2: v(select_id_HO_cause()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<Time_UE_StayedInCell_EnhancedGranularity>()); return true;
			case 2: v(var.as<Cause>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(Cause)];
			char dummy2[sizeof(Time_UE_StayedInCell_EnhancedGranularity)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_Time_UE_StayedInCell_EnhancedGranularity() { set(optional); type=1;}
		void select_id_HO_cause() { set(optional); type=2;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
LastVisitedEUTRANCellInformation ::= SEQUENCE {
	global-Cell-ID					ECGI,
	cellType						CellType,
	time-UE-StayedInCell			Time-UE-StayedInCell,
	iE-Extensions					ProtocolExtensionContainer { {LastVisitedEUTRANCellInformation-ExtIEs} } OPTIONAL,
	...
}
*/

struct LastVisitedEUTRANCellInformation : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "LastVisitedEUTRANCellInformation";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct global_Cell_ID_t : ECGI
	{
		static constexpr const char* name() {return "global_Cell_ID_t";}
		using parent_t = ECGI;

	};
	global_Cell_ID_t& ref_global_Cell_ID() {return global_Cell_ID;}
	global_Cell_ID_t const& ref_global_Cell_ID() const {return global_Cell_ID;}
	struct cellType_t : CellType
	{
		static constexpr const char* name() {return "cellType_t";}
		using parent_t = CellType;

	};
	cellType_t& ref_cellType() {return cellType;}
	cellType_t const& ref_cellType() const {return cellType;}
	struct time_UE_StayedInCell_t : Time_UE_StayedInCell
	{
		static constexpr const char* name() {return "time_UE_StayedInCell_t";}
		using parent_t = Time_UE_StayedInCell;

	};
	time_UE_StayedInCell_t& ref_time_UE_StayedInCell() {return time_UE_StayedInCell;}
	time_UE_StayedInCell_t const& ref_time_UE_StayedInCell() const {return time_UE_StayedInCell;}
	struct iE_Extensions_t : ProtocolExtensionContainer<LastVisitedEUTRANCellInformation_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<LastVisitedEUTRANCellInformation_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(global_Cell_ID);
		v(cellType);
		v(time_UE_StayedInCell);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(global_Cell_ID);
		v(cellType);
		v(time_UE_StayedInCell);
		v(iE_Extensions);

	};
	void clear()
	{
		global_Cell_ID.clear();
		cellType.clear();
		time_UE_StayedInCell.clear();
		iE_Extensions.clear();

	};
	private:
	global_Cell_ID_t	global_Cell_ID;
	cellType_t	cellType;
	time_UE_StayedInCell_t	time_UE_StayedInCell;
	iE_Extensions_t	iE_Extensions;

};
/*
LastVisitedUTRANCellInformation	::= OCTET STRING
*/

struct LastVisitedUTRANCellInformation : asn::ostring<>
{
	static constexpr const char* name() {return "LastVisitedUTRANCellInformation";}
	using parent_t = asn::ostring<>;

};

/*
LastVisitedGERANCellInformation ::= CHOICE {
	undefined						NULL,
	...
}
*/

struct LastVisitedGERANCellInformation : asn::choice<1, 0, true>
{
	static constexpr const char* name() {return "LastVisitedGERANCellInformation";}
	using parent_t = asn::choice<1, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 2;}
	void set_unknown() { set_index(2);  }
	~LastVisitedGERANCellInformation() {clear();}
	struct undefined_t : asn::nulltype
	{
		static constexpr const char* name() {return "undefined_t";}
		using parent_t = asn::nulltype;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<undefined_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<undefined_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<undefined_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<undefined_t>(1);

	}
	undefined_t& select_undefined() { if(get_index() != 1) { clear(); set_index(1); return var.build<undefined_t>();} return var.as<undefined_t>();}
	undefined_t const* get_undefined() const { if(get_index() == 1) { return &var.as<undefined_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(undefined_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
LastVisitedNGRANCellInformation	::= OCTET STRING
*/

struct LastVisitedNGRANCellInformation : asn::ostring<>
{
	static constexpr const char* name() {return "LastVisitedNGRANCellInformation";}
	using parent_t = asn::ostring<>;

};

/*
LastVisitedCell-Item ::= CHOICE {
	e-UTRAN-Cell					LastVisitedEUTRANCellInformation,
	uTRAN-Cell						LastVisitedUTRANCellInformation,
	gERAN-Cell						LastVisitedGERANCellInformation,
	...,
	nG-RAN-Cell						LastVisitedNGRANCellInformation
}
*/

struct LastVisitedCell_Item : asn::choice<4, 1, true>
{
	static constexpr const char* name() {return "LastVisitedCell-Item";}
	using parent_t = asn::choice<4, 1, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 5;}
	void set_unknown() { set_index(5);  }
	~LastVisitedCell_Item() {clear();}
	struct e_UTRAN_Cell_t : LastVisitedEUTRANCellInformation
	{
		static constexpr const char* name() {return "e_UTRAN_Cell_t";}
		using parent_t = LastVisitedEUTRANCellInformation;

	};
	struct uTRAN_Cell_t : LastVisitedUTRANCellInformation
	{
		static constexpr const char* name() {return "uTRAN_Cell_t";}
		using parent_t = LastVisitedUTRANCellInformation;

	};
	struct gERAN_Cell_t : LastVisitedGERANCellInformation
	{
		static constexpr const char* name() {return "gERAN_Cell_t";}
		using parent_t = LastVisitedGERANCellInformation;

	};
	struct nG_RAN_Cell_t : LastVisitedNGRANCellInformation
	{
		static constexpr const char* name() {return "nG_RAN_Cell_t";}
		using parent_t = LastVisitedNGRANCellInformation;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<e_UTRAN_Cell_t>(); break;
		case 2: var.destroy<uTRAN_Cell_t>(); break;
		case 3: var.destroy<gERAN_Cell_t>(); break;
		case 4: var.destroy<nG_RAN_Cell_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<e_UTRAN_Cell_t>());
		case 2: set_index(2); return v(var.build<uTRAN_Cell_t>());
		case 3: set_index(3); return v(var.build<gERAN_Cell_t>());
		case 4: set_index(4); return v(var.build<nG_RAN_Cell_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<e_UTRAN_Cell_t>());
		case 2: return v(var.as<uTRAN_Cell_t>());
		case 3: return v(var.as<gERAN_Cell_t>());
		case 4: return v(var.as<nG_RAN_Cell_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<e_UTRAN_Cell_t>(1);
		v.template operator()<uTRAN_Cell_t>(2);
		v.template operator()<gERAN_Cell_t>(3);
		v.template operator()<nG_RAN_Cell_t>(4);

	}
	e_UTRAN_Cell_t& select_e_UTRAN_Cell() { if(get_index() != 1) { clear(); set_index(1); return var.build<e_UTRAN_Cell_t>();} return var.as<e_UTRAN_Cell_t>();}
	e_UTRAN_Cell_t const* get_e_UTRAN_Cell() const { if(get_index() == 1) { return &var.as<e_UTRAN_Cell_t>();} return nullptr; }
	uTRAN_Cell_t& select_uTRAN_Cell() { if(get_index() != 2) { clear(); set_index(2); return var.build<uTRAN_Cell_t>();} return var.as<uTRAN_Cell_t>();}
	uTRAN_Cell_t const* get_uTRAN_Cell() const { if(get_index() == 2) { return &var.as<uTRAN_Cell_t>();} return nullptr; }
	gERAN_Cell_t& select_gERAN_Cell() { if(get_index() != 3) { clear(); set_index(3); return var.build<gERAN_Cell_t>();} return var.as<gERAN_Cell_t>();}
	gERAN_Cell_t const* get_gERAN_Cell() const { if(get_index() == 3) { return &var.as<gERAN_Cell_t>();} return nullptr; }
	nG_RAN_Cell_t& select_nG_RAN_Cell() { if(get_index() != 4) { clear(); set_index(4); return var.build<nG_RAN_Cell_t>();} return var.as<nG_RAN_Cell_t>();}
	nG_RAN_Cell_t const* get_nG_RAN_Cell() const { if(get_index() == 4) { return &var.as<nG_RAN_Cell_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(e_UTRAN_Cell_t)];
		char dummy2[sizeof(uTRAN_Cell_t)];
		char dummy3[sizeof(gERAN_Cell_t)];
		char dummy4[sizeof(nG_RAN_Cell_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
Links-to-log ::= ENUMERATED {uplink, downlink, both-uplink-and-downlink, ...}
*/

struct Links_to_log : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "Links-to-log";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		uplink
		,downlink
		,both_uplink_and_downlink
	} index_t;

};

/*
ReportArea ::= ENUMERATED{
	ecgi,
	...
}
*/

struct ReportArea : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "ReportArea";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		ecgi
	} index_t;

};

/*
LocationReportingInformation-ExtIEs X2AP-PROTOCOL-EXTENSION ::={
	...
}
*/

struct LocationReportingInformation_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
LocationReportingInformation ::= SEQUENCE {
	eventType		EventType,
	reportArea		ReportArea,
	iE-Extensions		ProtocolExtensionContainer { {LocationReportingInformation-ExtIEs} } OPTIONAL,
	...
}
*/

struct LocationReportingInformation : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "LocationReportingInformation";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct eventType_t : EventType
	{
		static constexpr const char* name() {return "eventType_t";}
		using parent_t = EventType;

	};
	eventType_t& ref_eventType() {return eventType;}
	eventType_t const& ref_eventType() const {return eventType;}
	struct reportArea_t : ReportArea
	{
		static constexpr const char* name() {return "reportArea_t";}
		using parent_t = ReportArea;

	};
	reportArea_t& ref_reportArea() {return reportArea;}
	reportArea_t const& ref_reportArea() const {return reportArea;}
	struct iE_Extensions_t : ProtocolExtensionContainer<LocationReportingInformation_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<LocationReportingInformation_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(eventType);
		v(reportArea);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(eventType);
		v(reportArea);
		v(iE_Extensions);

	};
	void clear()
	{
		eventType.clear();
		reportArea.clear();
		iE_Extensions.clear();

	};
	private:
	eventType_t	eventType;
	reportArea_t	reportArea;
	iE_Extensions_t	iE_Extensions;

};
/*
ReportIntervalMDT ::= ENUMERATED {ms120, ms240, ms480, ms640, ms1024, ms2048, ms5120, ms10240, min1, min6, min12, min30, min60}
*/

struct ReportIntervalMDT : asn::enumerated<13, 0, false>
{
	static constexpr const char* name() {return "ReportIntervalMDT";}
	using parent_t = asn::enumerated<13, 0, false>;
	typedef enum {
		ms120
		,ms240
		,ms480
		,ms640
		,ms1024
		,ms2048
		,ms5120
		,ms10240
		,min1
		,min6
		,min12
		,min30
		,min60
	} index_t;

};

/*
ReportAmountMDT ::= ENUMERATED{r1, r2, r4, r8, r16, r32, r64, rinfinity}
*/

struct ReportAmountMDT : asn::enumerated<8, 0, false>
{
	static constexpr const char* name() {return "ReportAmountMDT";}
	using parent_t = asn::enumerated<8, 0, false>;
	typedef enum {
		r1
		,r2
		,r4
		,r8
		,r16
		,r32
		,r64
		,rinfinity
	} index_t;

};

/*
M1PeriodicReporting-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct M1PeriodicReporting_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
M1PeriodicReporting ::= SEQUENCE {
	reportInterval				ReportIntervalMDT,
	reportAmount				ReportAmountMDT,
	iE-Extensions				ProtocolExtensionContainer { {M1PeriodicReporting-ExtIEs} } OPTIONAL,
	...
}
*/

struct M1PeriodicReporting : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "M1PeriodicReporting";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct reportInterval_t : ReportIntervalMDT
	{
		static constexpr const char* name() {return "reportInterval_t";}
		using parent_t = ReportIntervalMDT;

	};
	reportInterval_t& ref_reportInterval() {return reportInterval;}
	reportInterval_t const& ref_reportInterval() const {return reportInterval;}
	struct reportAmount_t : ReportAmountMDT
	{
		static constexpr const char* name() {return "reportAmount_t";}
		using parent_t = ReportAmountMDT;

	};
	reportAmount_t& ref_reportAmount() {return reportAmount;}
	reportAmount_t const& ref_reportAmount() const {return reportAmount;}
	struct iE_Extensions_t : ProtocolExtensionContainer<M1PeriodicReporting_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<M1PeriodicReporting_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(reportInterval);
		v(reportAmount);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(reportInterval);
		v(reportAmount);
		v(iE_Extensions);

	};
	void clear()
	{
		reportInterval.clear();
		reportAmount.clear();
		iE_Extensions.clear();

	};
	private:
	reportInterval_t	reportInterval;
	reportAmount_t	reportAmount;
	iE_Extensions_t	iE_Extensions;

};
/*
M1ReportingTrigger::= ENUMERATED{
	periodic,
	a2eventtriggered,
	...,
	a2eventtriggered-periodic
}
*/

struct M1ReportingTrigger : asn::enumerated<3, 1, true>
{
	static constexpr const char* name() {return "M1ReportingTrigger";}
	using parent_t = asn::enumerated<3, 1, true>;
	typedef enum {
		periodic
		,a2eventtriggered
		,a2eventtriggered_periodic
	} index_t;

};

/*
Threshold-RSRP ::= INTEGER(0..97)
*/

struct Threshold_RSRP : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 97>>;
	static constexpr const char* name() {return "Threshold-RSRP";}
	using parent_t = asn::integer<>;

};

/*
Threshold-RSRQ ::= INTEGER(0..34)
*/

struct Threshold_RSRQ : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 34>>;
	static constexpr const char* name() {return "Threshold-RSRQ";}
	using parent_t = asn::integer<>;

};

/*
MeasurementThresholdA2 ::= CHOICE {
	threshold-RSRP				Threshold-RSRP,
	threshold-RSRQ				Threshold-RSRQ,
	...
}
*/

struct MeasurementThresholdA2 : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "MeasurementThresholdA2";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~MeasurementThresholdA2() {clear();}
	struct threshold_RSRP_t : Threshold_RSRP
	{
		static constexpr const char* name() {return "threshold_RSRP_t";}
		using parent_t = Threshold_RSRP;

	};
	struct threshold_RSRQ_t : Threshold_RSRQ
	{
		static constexpr const char* name() {return "threshold_RSRQ_t";}
		using parent_t = Threshold_RSRQ;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<threshold_RSRP_t>(); break;
		case 2: var.destroy<threshold_RSRQ_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<threshold_RSRP_t>());
		case 2: set_index(2); return v(var.build<threshold_RSRQ_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<threshold_RSRP_t>());
		case 2: return v(var.as<threshold_RSRQ_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<threshold_RSRP_t>(1);
		v.template operator()<threshold_RSRQ_t>(2);

	}
	threshold_RSRP_t& select_threshold_RSRP() { if(get_index() != 1) { clear(); set_index(1); return var.build<threshold_RSRP_t>();} return var.as<threshold_RSRP_t>();}
	threshold_RSRP_t const* get_threshold_RSRP() const { if(get_index() == 1) { return &var.as<threshold_RSRP_t>();} return nullptr; }
	threshold_RSRQ_t& select_threshold_RSRQ() { if(get_index() != 2) { clear(); set_index(2); return var.build<threshold_RSRQ_t>();} return var.as<threshold_RSRQ_t>();}
	threshold_RSRQ_t const* get_threshold_RSRQ() const { if(get_index() == 2) { return &var.as<threshold_RSRQ_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(threshold_RSRP_t)];
		char dummy2[sizeof(threshold_RSRQ_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
M1ThresholdEventA2-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct M1ThresholdEventA2_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
M1ThresholdEventA2 ::= SEQUENCE {
	measurementThreshold		MeasurementThresholdA2,
	iE-Extensions				ProtocolExtensionContainer { {M1ThresholdEventA2-ExtIEs} } OPTIONAL,
	...
}
*/

struct M1ThresholdEventA2 : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "M1ThresholdEventA2";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct measurementThreshold_t : MeasurementThresholdA2
	{
		static constexpr const char* name() {return "measurementThreshold_t";}
		using parent_t = MeasurementThresholdA2;

	};
	measurementThreshold_t& ref_measurementThreshold() {return measurementThreshold;}
	measurementThreshold_t const& ref_measurementThreshold() const {return measurementThreshold;}
	struct iE_Extensions_t : ProtocolExtensionContainer<M1ThresholdEventA2_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<M1ThresholdEventA2_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(measurementThreshold);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(measurementThreshold);
		v(iE_Extensions);

	};
	void clear()
	{
		measurementThreshold.clear();
		iE_Extensions.clear();

	};
	private:
	measurementThreshold_t	measurementThreshold;
	iE_Extensions_t	iE_Extensions;

};
/*
M3period ::= ENUMERATED {ms100, ms1000, ms10000, ... }
*/

struct M3period : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "M3period";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		ms100
		,ms1000
		,ms10000
	} index_t;

};

/*
M3Configuration-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct M3Configuration_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
M3Configuration ::= SEQUENCE {
	m3period			M3period,
	iE-Extensions		ProtocolExtensionContainer { {M3Configuration-ExtIEs} } OPTIONAL,
	...
}
*/

struct M3Configuration : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "M3Configuration";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct m3period_t : M3period
	{
		static constexpr const char* name() {return "m3period_t";}
		using parent_t = M3period;

	};
	m3period_t& ref_m3period() {return m3period;}
	m3period_t const& ref_m3period() const {return m3period;}
	struct iE_Extensions_t : ProtocolExtensionContainer<M3Configuration_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<M3Configuration_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(m3period);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(m3period);
		v(iE_Extensions);

	};
	void clear()
	{
		m3period.clear();
		iE_Extensions.clear();

	};
	private:
	m3period_t	m3period;
	iE_Extensions_t	iE_Extensions;

};
/*
M4period ::= ENUMERATED {ms1024, ms2048, ms5120, ms10240, min1, ... }
*/

struct M4period : asn::enumerated<5, 0, true>
{
	static constexpr const char* name() {return "M4period";}
	using parent_t = asn::enumerated<5, 0, true>;
	typedef enum {
		ms1024
		,ms2048
		,ms5120
		,ms10240
		,min1
	} index_t;

};

/*
M4Configuration-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct M4Configuration_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
M4Configuration ::= SEQUENCE {
	m4period			M4period,
	m4-links-to-log		Links-to-log,
	iE-Extensions		ProtocolExtensionContainer { {M4Configuration-ExtIEs} } OPTIONAL,
	...
}
*/

struct M4Configuration : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "M4Configuration";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct m4period_t : M4period
	{
		static constexpr const char* name() {return "m4period_t";}
		using parent_t = M4period;

	};
	m4period_t& ref_m4period() {return m4period;}
	m4period_t const& ref_m4period() const {return m4period;}
	struct m4_links_to_log_t : Links_to_log
	{
		static constexpr const char* name() {return "m4_links_to_log_t";}
		using parent_t = Links_to_log;

	};
	m4_links_to_log_t& ref_m4_links_to_log() {return m4_links_to_log;}
	m4_links_to_log_t const& ref_m4_links_to_log() const {return m4_links_to_log;}
	struct iE_Extensions_t : ProtocolExtensionContainer<M4Configuration_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<M4Configuration_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(m4period);
		v(m4_links_to_log);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(m4period);
		v(m4_links_to_log);
		v(iE_Extensions);

	};
	void clear()
	{
		m4period.clear();
		m4_links_to_log.clear();
		iE_Extensions.clear();

	};
	private:
	m4period_t	m4period;
	m4_links_to_log_t	m4_links_to_log;
	iE_Extensions_t	iE_Extensions;

};
/*
M5period ::= ENUMERATED {ms1024, ms2048, ms5120, ms10240, min1, ... }
*/

struct M5period : asn::enumerated<5, 0, true>
{
	static constexpr const char* name() {return "M5period";}
	using parent_t = asn::enumerated<5, 0, true>;
	typedef enum {
		ms1024
		,ms2048
		,ms5120
		,ms10240
		,min1
	} index_t;

};

/*
M5Configuration-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct M5Configuration_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
M5Configuration ::= SEQUENCE {
	m5period			M5period,
	m5-links-to-log		Links-to-log,
	iE-Extensions		ProtocolExtensionContainer { {M5Configuration-ExtIEs} } OPTIONAL,
	...
}
*/

struct M5Configuration : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "M5Configuration";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct m5period_t : M5period
	{
		static constexpr const char* name() {return "m5period_t";}
		using parent_t = M5period;

	};
	m5period_t& ref_m5period() {return m5period;}
	m5period_t const& ref_m5period() const {return m5period;}
	struct m5_links_to_log_t : Links_to_log
	{
		static constexpr const char* name() {return "m5_links_to_log_t";}
		using parent_t = Links_to_log;

	};
	m5_links_to_log_t& ref_m5_links_to_log() {return m5_links_to_log;}
	m5_links_to_log_t const& ref_m5_links_to_log() const {return m5_links_to_log;}
	struct iE_Extensions_t : ProtocolExtensionContainer<M5Configuration_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<M5Configuration_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(m5period);
		v(m5_links_to_log);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(m5period);
		v(m5_links_to_log);
		v(iE_Extensions);

	};
	void clear()
	{
		m5period.clear();
		m5_links_to_log.clear();
		iE_Extensions.clear();

	};
	private:
	m5period_t	m5period;
	m5_links_to_log_t	m5_links_to_log;
	iE_Extensions_t	iE_Extensions;

};
/*
M6report-interval ::= ENUMERATED { ms1024, ms2048, ms5120, ms10240, ... }
*/

struct M6report_interval : asn::enumerated<4, 0, true>
{
	static constexpr const char* name() {return "M6report-interval";}
	using parent_t = asn::enumerated<4, 0, true>;
	typedef enum {
		ms1024
		,ms2048
		,ms5120
		,ms10240
	} index_t;

};

/*
M6delay-threshold ::= ENUMERATED { ms30, ms40, ms50, ms60, ms70, ms80, ms90, ms100, ms150, ms300, ms500, ms750, ... }
*/

struct M6delay_threshold : asn::enumerated<12, 0, true>
{
	static constexpr const char* name() {return "M6delay-threshold";}
	using parent_t = asn::enumerated<12, 0, true>;
	typedef enum {
		ms30
		,ms40
		,ms50
		,ms60
		,ms70
		,ms80
		,ms90
		,ms100
		,ms150
		,ms300
		,ms500
		,ms750
	} index_t;

};

/*
M6Configuration-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct M6Configuration_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
M6Configuration ::= SEQUENCE {
	m6report-interval	M6report-interval,
	m6delay-threshold	M6delay-threshold	OPTIONAL,
-- This IE shall be present if the M6 Links to log IE is set to “uplink” or to “both-uplink-and-downlink” --
	m6-links-to-log		Links-to-log,
	iE-Extensions		ProtocolExtensionContainer { {M6Configuration-ExtIEs} } OPTIONAL,
	...
}
*/

struct M6Configuration : asn::sequence<4, 0, true, 2>
{
	static constexpr const char* name() {return "M6Configuration";}
	using parent_t = asn::sequence<4, 0, true, 2>;
	struct m6report_interval_t : M6report_interval
	{
		static constexpr const char* name() {return "m6report_interval_t";}
		using parent_t = M6report_interval;

	};
	m6report_interval_t& ref_m6report_interval() {return m6report_interval;}
	m6report_interval_t const& ref_m6report_interval() const {return m6report_interval;}
	struct m6delay_threshold_t : M6delay_threshold
	{
		static constexpr const char* name() {return "m6delay_threshold_t";}
		using parent_t = M6delay_threshold;
		static constexpr bool optional = true;

	};
	m6delay_threshold_t& set_m6delay_threshold() { m6delay_threshold.setpresent(true); return m6delay_threshold;}
	m6delay_threshold_t const* get_m6delay_threshold() const {return m6delay_threshold.is_valid() ? &m6delay_threshold : nullptr;}
	struct m6_links_to_log_t : Links_to_log
	{
		static constexpr const char* name() {return "m6_links_to_log_t";}
		using parent_t = Links_to_log;

	};
	m6_links_to_log_t& ref_m6_links_to_log() {return m6_links_to_log;}
	m6_links_to_log_t const& ref_m6_links_to_log() const {return m6_links_to_log;}
	struct iE_Extensions_t : ProtocolExtensionContainer<M6Configuration_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<M6Configuration_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(m6report_interval);
		v(m6delay_threshold);
		v(m6_links_to_log);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(m6report_interval);
		v(m6delay_threshold);
		v(m6_links_to_log);
		v(iE_Extensions);

	};
	void clear()
	{
		m6report_interval.clear();
		m6delay_threshold.clear();
		m6_links_to_log.clear();
		iE_Extensions.clear();

	};
	private:
	m6report_interval_t	m6report_interval;
	m6delay_threshold_t	m6delay_threshold;
	m6_links_to_log_t	m6_links_to_log;
	iE_Extensions_t	iE_Extensions;

};
/*
M7period ::= INTEGER(1..60, ...)
*/

struct M7period : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<1, 60>>;
	static constexpr const char* name() {return "M7period";}
	using parent_t = asn::integer<>;

};

/*
M7Configuration-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct M7Configuration_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
M7Configuration ::= SEQUENCE {
	m7period			M7period,
	m7-links-to-log		Links-to-log,
	iE-Extensions		ProtocolExtensionContainer { {M7Configuration-ExtIEs} } OPTIONAL,
	...
}
*/

struct M7Configuration : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "M7Configuration";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct m7period_t : M7period
	{
		static constexpr const char* name() {return "m7period_t";}
		using parent_t = M7period;

	};
	m7period_t& ref_m7period() {return m7period;}
	m7period_t const& ref_m7period() const {return m7period;}
	struct m7_links_to_log_t : Links_to_log
	{
		static constexpr const char* name() {return "m7_links_to_log_t";}
		using parent_t = Links_to_log;

	};
	m7_links_to_log_t& ref_m7_links_to_log() {return m7_links_to_log;}
	m7_links_to_log_t const& ref_m7_links_to_log() const {return m7_links_to_log;}
	struct iE_Extensions_t : ProtocolExtensionContainer<M7Configuration_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<M7Configuration_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(m7period);
		v(m7_links_to_log);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(m7period);
		v(m7_links_to_log);
		v(iE_Extensions);

	};
	void clear()
	{
		m7period.clear();
		m7_links_to_log.clear();
		iE_Extensions.clear();

	};
	private:
	m7period_t	m7period;
	m7_links_to_log_t	m7_links_to_log;
	iE_Extensions_t	iE_Extensions;

};
/*
MBMS-Service-Area-Identity ::= OCTET STRING (SIZE (2))
*/

struct MBMS_Service_Area_Identity : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<2>>;
	static constexpr const char* name() {return "MBMS-Service-Area-Identity";}
	using parent_t = asn::ostring<>;

};

/*
MBMS-Service-Area-Identity-List ::= SEQUENCE (SIZE(1.. maxnoofMBMSServiceAreaIdentities)) OF MBMS-Service-Area-Identity
*/

struct MBMS_Service_Area_Identity_List_elm : MBMS_Service_Area_Identity
{
	static constexpr const char* name() {return "MBMS_Service_Area_Identity_List_elm";}
	using parent_t = MBMS_Service_Area_Identity;

};
struct MBMS_Service_Area_Identity_List : asn::sequenceof<MBMS_Service_Area_Identity_List_elm>
{
	static constexpr const char* name() {return "MBMS-Service-Area-Identity-List";}
	using parent_t = asn::sequenceof<MBMS_Service_Area_Identity_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofMBMSServiceAreaIdentities >>;

};
/*
RadioframeAllocationPeriod ::= ENUMERATED{
	n1,
	n2,
	n4,
	n8,
	n16,
	n32,
	...
}
*/

struct RadioframeAllocationPeriod : asn::enumerated<6, 0, true>
{
	static constexpr const char* name() {return "RadioframeAllocationPeriod";}
	using parent_t = asn::enumerated<6, 0, true>;
	typedef enum {
		n1
		,n2
		,n4
		,n8
		,n16
		,n32
	} index_t;

};

/*
RadioframeAllocationOffset ::= INTEGER (0..7, ...)
*/

struct RadioframeAllocationOffset : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<0, 7>>;
	static constexpr const char* name() {return "RadioframeAllocationOffset";}
	using parent_t = asn::integer<>;

};

/*
Oneframe ::= BIT STRING (SIZE (6))
*/

struct Oneframe : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<6>>;
	static constexpr const char* name() {return "Oneframe";}
	using parent_t = asn::bstring<>;

};

/*
SubframeAllocation ::= CHOICE {
	oneframe						Oneframe,
	fourframes						Fourframes,
	...
}
*/

struct SubframeAllocation : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "SubframeAllocation";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~SubframeAllocation() {clear();}
	struct oneframe_t : Oneframe
	{
		static constexpr const char* name() {return "oneframe_t";}
		using parent_t = Oneframe;

	};
	struct fourframes_t : Fourframes
	{
		static constexpr const char* name() {return "fourframes_t";}
		using parent_t = Fourframes;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<oneframe_t>(); break;
		case 2: var.destroy<fourframes_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<oneframe_t>());
		case 2: set_index(2); return v(var.build<fourframes_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<oneframe_t>());
		case 2: return v(var.as<fourframes_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<oneframe_t>(1);
		v.template operator()<fourframes_t>(2);

	}
	oneframe_t& select_oneframe() { if(get_index() != 1) { clear(); set_index(1); return var.build<oneframe_t>();} return var.as<oneframe_t>();}
	oneframe_t const* get_oneframe() const { if(get_index() == 1) { return &var.as<oneframe_t>();} return nullptr; }
	fourframes_t& select_fourframes() { if(get_index() != 2) { clear(); set_index(2); return var.build<fourframes_t>();} return var.as<fourframes_t>();}
	fourframes_t const* get_fourframes() const { if(get_index() == 2) { return &var.as<fourframes_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(oneframe_t)];
		char dummy2[sizeof(fourframes_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
MBSFN-Subframe-Info-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct MBSFN_Subframe_Info_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
MBSFN-Subframe-Info	::= SEQUENCE {
	radioframeAllocationPeriod		RadioframeAllocationPeriod,
	radioframeAllocationOffset		RadioframeAllocationOffset,
	subframeAllocation				SubframeAllocation,
	iE-Extensions					ProtocolExtensionContainer { {MBSFN-Subframe-Info-ExtIEs} } 	OPTIONAL,
	...
}
*/

struct MBSFN_Subframe_Info : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "MBSFN-Subframe-Info";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct radioframeAllocationPeriod_t : RadioframeAllocationPeriod
	{
		static constexpr const char* name() {return "radioframeAllocationPeriod_t";}
		using parent_t = RadioframeAllocationPeriod;

	};
	radioframeAllocationPeriod_t& ref_radioframeAllocationPeriod() {return radioframeAllocationPeriod;}
	radioframeAllocationPeriod_t const& ref_radioframeAllocationPeriod() const {return radioframeAllocationPeriod;}
	struct radioframeAllocationOffset_t : RadioframeAllocationOffset
	{
		static constexpr const char* name() {return "radioframeAllocationOffset_t";}
		using parent_t = RadioframeAllocationOffset;

	};
	radioframeAllocationOffset_t& ref_radioframeAllocationOffset() {return radioframeAllocationOffset;}
	radioframeAllocationOffset_t const& ref_radioframeAllocationOffset() const {return radioframeAllocationOffset;}
	struct subframeAllocation_t : SubframeAllocation
	{
		static constexpr const char* name() {return "subframeAllocation_t";}
		using parent_t = SubframeAllocation;

	};
	subframeAllocation_t& ref_subframeAllocation() {return subframeAllocation;}
	subframeAllocation_t const& ref_subframeAllocation() const {return subframeAllocation;}
	struct iE_Extensions_t : ProtocolExtensionContainer<MBSFN_Subframe_Info_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<MBSFN_Subframe_Info_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(radioframeAllocationPeriod);
		v(radioframeAllocationOffset);
		v(subframeAllocation);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(radioframeAllocationPeriod);
		v(radioframeAllocationOffset);
		v(subframeAllocation);
		v(iE_Extensions);

	};
	void clear()
	{
		radioframeAllocationPeriod.clear();
		radioframeAllocationOffset.clear();
		subframeAllocation.clear();
		iE_Extensions.clear();

	};
	private:
	radioframeAllocationPeriod_t	radioframeAllocationPeriod;
	radioframeAllocationOffset_t	radioframeAllocationOffset;
	subframeAllocation_t	subframeAllocation;
	iE_Extensions_t	iE_Extensions;

};
/*
MBSFN-Subframe-Infolist::= SEQUENCE (SIZE(1.. maxnoofMBSFN)) OF MBSFN-Subframe-Info
*/

struct MBSFN_Subframe_Infolist_elm : MBSFN_Subframe_Info
{
	static constexpr const char* name() {return "MBSFN_Subframe_Infolist_elm";}
	using parent_t = MBSFN_Subframe_Info;

};
struct MBSFN_Subframe_Infolist : asn::sequenceof<MBSFN_Subframe_Infolist_elm>
{
	static constexpr const char* name() {return "MBSFN-Subframe-Infolist";}
	using parent_t = asn::sequenceof<MBSFN_Subframe_Infolist_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofMBSFN >>;

};
/*
MDT-Activation		::= ENUMERATED {
	immediate-MDT-only,
	immediate-MDT-and-Trace,
	...
}
*/

struct MDT_Activation : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "MDT-Activation";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		immediate_MDT_only
		,immediate_MDT_and_Trace
	} index_t;

};

/*
MeasurementsToActivate::= BIT STRING (SIZE (8))
*/

struct MeasurementsToActivate : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<8>>;
	static constexpr const char* name() {return "MeasurementsToActivate";}
	using parent_t = asn::bstring<>;

};

/*
MDT-Location-Info ::= BIT STRING (SIZE (8))
*/

struct MDT_Location_Info : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<8>>;
	static constexpr const char* name() {return "MDT-Location-Info";}
	using parent_t = asn::bstring<>;

};

/*
MDTPLMNList ::= SEQUENCE (SIZE(1..maxnoofMDTPLMNs)) OF PLMN-Identity
*/

struct MDTPLMNList_elm : PLMN_Identity
{
	static constexpr const char* name() {return "MDTPLMNList_elm";}
	using parent_t = PLMN_Identity;

};
struct MDTPLMNList : asn::sequenceof<MDTPLMNList_elm>
{
	static constexpr const char* name() {return "MDTPLMNList";}
	using parent_t = asn::sequenceof<MDTPLMNList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofMDTPLMNs >>;

};
/*
WLANMeasConfig::= ENUMERATED {setup,...}
*/

struct WLANMeasConfig : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "WLANMeasConfig";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		setup
	} index_t;

};

/*
WLANName ::= OCTET STRING (SIZE (1..32))
*/

struct WLANName : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::span<1, 32>>;
	static constexpr const char* name() {return "WLANName";}
	using parent_t = asn::ostring<>;

};

/*
WLANMeasConfigNameList ::= SEQUENCE (SIZE(1..maxnoofWLANName)) OF WLANName
*/

struct WLANMeasConfigNameList_elm : WLANName
{
	static constexpr const char* name() {return "WLANMeasConfigNameList_elm";}
	using parent_t = WLANName;

};
struct WLANMeasConfigNameList : asn::sequenceof<WLANMeasConfigNameList_elm>
{
	static constexpr const char* name() {return "WLANMeasConfigNameList";}
	using parent_t = asn::sequenceof<WLANMeasConfigNameList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofWLANName >>;

};
/*
WLANMeasurementConfiguration-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct WLANMeasurementConfiguration_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
WLANMeasurementConfiguration ::= SEQUENCE {
	wlanMeasConfig				WLANMeasConfig,
	wlanMeasConfigNameList		WLANMeasConfigNameList				OPTIONAL,
	wlan-rssi					ENUMERATED {true, ...}				OPTIONAL,
	wlan-rtt					ENUMERATED {true, ...}				OPTIONAL,
	iE-Extensions		ProtocolExtensionContainer { {WLANMeasurementConfiguration-ExtIEs} } OPTIONAL,
	...
}
*/

struct WLANMeasurementConfiguration : asn::sequence<5, 0, true, 4>
{
	static constexpr const char* name() {return "WLANMeasurementConfiguration";}
	using parent_t = asn::sequence<5, 0, true, 4>;
	struct wlanMeasConfig_t : WLANMeasConfig
	{
		static constexpr const char* name() {return "wlanMeasConfig_t";}
		using parent_t = WLANMeasConfig;

	};
	wlanMeasConfig_t& ref_wlanMeasConfig() {return wlanMeasConfig;}
	wlanMeasConfig_t const& ref_wlanMeasConfig() const {return wlanMeasConfig;}
	struct wlanMeasConfigNameList_t : WLANMeasConfigNameList
	{
		static constexpr const char* name() {return "wlanMeasConfigNameList_t";}
		using parent_t = WLANMeasConfigNameList;
		static constexpr bool optional = true;

	};
	wlanMeasConfigNameList_t& set_wlanMeasConfigNameList() { wlanMeasConfigNameList.setpresent(true); return wlanMeasConfigNameList;}
	wlanMeasConfigNameList_t const* get_wlanMeasConfigNameList() const {return wlanMeasConfigNameList.is_valid() ? &wlanMeasConfigNameList : nullptr;}
	struct wlan_rssi_t : asn::enumerated<1, 0, true>
	{
		static constexpr const char* name() {return "wlan_rssi_t";}
		using parent_t = asn::enumerated<1, 0, true>;
		static constexpr bool optional = true;
		typedef enum {
			True
		} index_t;

	};

	wlan_rssi_t& set_wlan_rssi() { wlan_rssi.setpresent(true); return wlan_rssi;}
	wlan_rssi_t const* get_wlan_rssi() const {return wlan_rssi.is_valid() ? &wlan_rssi : nullptr;}
	struct wlan_rtt_t : asn::enumerated<1, 0, true>
	{
		static constexpr const char* name() {return "wlan_rtt_t";}
		using parent_t = asn::enumerated<1, 0, true>;
		static constexpr bool optional = true;
		typedef enum {
			True
		} index_t;

	};

	wlan_rtt_t& set_wlan_rtt() { wlan_rtt.setpresent(true); return wlan_rtt;}
	wlan_rtt_t const* get_wlan_rtt() const {return wlan_rtt.is_valid() ? &wlan_rtt : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<WLANMeasurementConfiguration_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<WLANMeasurementConfiguration_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(wlanMeasConfig);
		v(wlanMeasConfigNameList);
		v(wlan_rssi);
		v(wlan_rtt);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(wlanMeasConfig);
		v(wlanMeasConfigNameList);
		v(wlan_rssi);
		v(wlan_rtt);
		v(iE_Extensions);

	};
	void clear()
	{
		wlanMeasConfig.clear();
		wlanMeasConfigNameList.clear();
		wlan_rssi.clear();
		wlan_rtt.clear();
		iE_Extensions.clear();

	};
	private:
	wlanMeasConfig_t	wlanMeasConfig;
	wlanMeasConfigNameList_t	wlanMeasConfigNameList;
	wlan_rssi_t	wlan_rssi;
	wlan_rtt_t	wlan_rtt;
	iE_Extensions_t	iE_Extensions;

};
/*
MDT-Configuration-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ID id-M3Configuration							CRITICALITY ignore	EXTENSION M3Configuration								PRESENCE conditional}|
	{ID id-M4Configuration							CRITICALITY ignore	EXTENSION M4Configuration								PRESENCE conditional}|
	{ID id-M5Configuration							CRITICALITY ignore	EXTENSION M5Configuration								PRESENCE conditional}|
	{ID id-MDT-Location-Info						CRITICALITY ignore	EXTENSION MDT-Location-Info							PRESENCE optional}|
	{ID id-SignallingBasedMDTPLMNList				CRITICALITY ignore	EXTENSION MDTPLMNList									PRESENCE optional}|
	{ID id-M6Configuration							CRITICALITY ignore	EXTENSION M6Configuration								PRESENCE conditional}|
	{ID id-M7Configuration							CRITICALITY ignore	EXTENSION M7Configuration								PRESENCE conditional}|
	{ ID id-BluetoothMeasurementConfiguration		CRITICALITY ignore	EXTENSION BluetoothMeasurementConfiguration		PRESENCE optional}|
	{ ID id-WLANMeasurementConfiguration			CRITICALITY ignore	EXTENSION WLANMeasurementConfiguration			PRESENCE optional},
	...
}
*/

struct MDT_Configuration_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 10; }
		void clear() {type = 0;}
		void select_id_M3Configuration() { set(id_M3Configuration); type=1;}
		void select_id_M4Configuration() { set(id_M4Configuration); type=2;}
		void select_id_M5Configuration() { set(id_M5Configuration); type=3;}
		void select_id_MDT_Location_Info() { set(id_MDT_Location_Info); type=4;}
		void select_id_SignallingBasedMDTPLMNList() { set(id_SignallingBasedMDTPLMNList); type=5;}
		void select_id_M6Configuration() { set(id_M6Configuration); type=6;}
		void select_id_M7Configuration() { set(id_M7Configuration); type=7;}
		void select_id_BluetoothMeasurementConfiguration() { set(id_BluetoothMeasurementConfiguration); type=8;}
		void select_id_WLANMeasurementConfiguration() { set(id_WLANMeasurementConfiguration); type=9;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_M3Configuration)) { type = 1; return true; }
			else if(equal(id_M4Configuration)) { type = 2; return true; }
			else if(equal(id_M5Configuration)) { type = 3; return true; }
			else if(equal(id_MDT_Location_Info)) { type = 4; return true; }
			else if(equal(id_SignallingBasedMDTPLMNList)) { type = 5; return true; }
			else if(equal(id_M6Configuration)) { type = 6; return true; }
			else if(equal(id_M7Configuration)) { type = 7; return true; }
			else if(equal(id_BluetoothMeasurementConfiguration)) { type = 8; return true; }
			else if(equal(id_WLANMeasurementConfiguration)) { type = 9; return true; }
			else { type = 10; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_M3Configuration);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_M4Configuration);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_M5Configuration);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_MDT_Location_Info);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(id_SignallingBasedMDTPLMNList);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(id_M6Configuration);} return false;
			case 7: type = 7; if(v(ref_nested())) { return equal(id_M7Configuration);} return false;
			case 8: type = 8; if(v(ref_nested())) { return equal(id_BluetoothMeasurementConfiguration);} return false;
			case 9: type = 9; if(v(ref_nested())) { return equal(id_WLANMeasurementConfiguration);} return false;
			case 10: type = 10; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 10; }
		void clear() {type = 0;}
		void select_id_M3Configuration() { set(ignore); type=1;}
		void select_id_M4Configuration() { set(ignore); type=2;}
		void select_id_M5Configuration() { set(ignore); type=3;}
		void select_id_MDT_Location_Info() { set(ignore); type=4;}
		void select_id_SignallingBasedMDTPLMNList() { set(ignore); type=5;}
		void select_id_M6Configuration() { set(ignore); type=6;}
		void select_id_M7Configuration() { set(ignore); type=7;}
		void select_id_BluetoothMeasurementConfiguration() { set(ignore); type=8;}
		void select_id_WLANMeasurementConfiguration() { set(ignore); type=9;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else if(equal(ignore)) { type = 3; return true; }
			else if(equal(ignore)) { type = 4; return true; }
			else if(equal(ignore)) { type = 5; return true; }
			else if(equal(ignore)) { type = 6; return true; }
			else if(equal(ignore)) { type = 7; return true; }
			else if(equal(ignore)) { type = 8; return true; }
			else if(equal(ignore)) { type = 9; return true; }
			else { type = 10; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(ignore);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(ignore);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(ignore);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(ignore);} return false;
			case 7: type = 7; if(v(ref_nested())) { return equal(ignore);} return false;
			case 8: type = 8; if(v(ref_nested())) { return equal(ignore);} return false;
			case 9: type = 9; if(v(ref_nested())) { return equal(ignore);} return false;
			case 10: type = 10; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		M3Configuration& select_id_M3Configuration() { return set<M3Configuration>(1); }
		M3Configuration const* get_id_M3Configuration() const { return get<M3Configuration>(1); }
		M4Configuration& select_id_M4Configuration() { return set<M4Configuration>(2); }
		M4Configuration const* get_id_M4Configuration() const { return get<M4Configuration>(2); }
		M5Configuration& select_id_M5Configuration() { return set<M5Configuration>(3); }
		M5Configuration const* get_id_M5Configuration() const { return get<M5Configuration>(3); }
		MDT_Location_Info& select_id_MDT_Location_Info() { return set<MDT_Location_Info>(4); }
		MDT_Location_Info const* get_id_MDT_Location_Info() const { return get<MDT_Location_Info>(4); }
		MDTPLMNList& select_id_SignallingBasedMDTPLMNList() { return set<MDTPLMNList>(5); }
		MDTPLMNList const* get_id_SignallingBasedMDTPLMNList() const { return get<MDTPLMNList>(5); }
		M6Configuration& select_id_M6Configuration() { return set<M6Configuration>(6); }
		M6Configuration const* get_id_M6Configuration() const { return get<M6Configuration>(6); }
		M7Configuration& select_id_M7Configuration() { return set<M7Configuration>(7); }
		M7Configuration const* get_id_M7Configuration() const { return get<M7Configuration>(7); }
		BluetoothMeasurementConfiguration& select_id_BluetoothMeasurementConfiguration() { return set<BluetoothMeasurementConfiguration>(8); }
		BluetoothMeasurementConfiguration const* get_id_BluetoothMeasurementConfiguration() const { return get<BluetoothMeasurementConfiguration>(8); }
		WLANMeasurementConfiguration& select_id_WLANMeasurementConfiguration() { return set<WLANMeasurementConfiguration>(9); }
		WLANMeasurementConfiguration const* get_id_WLANMeasurementConfiguration() const { return get<WLANMeasurementConfiguration>(9); }
		bool is_unknown() const { return type == 10; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<M3Configuration>(); break;
			case 2: var.destroy<M4Configuration>(); break;
			case 3: var.destroy<M5Configuration>(); break;
			case 4: var.destroy<MDT_Location_Info>(); break;
			case 5: var.destroy<MDTPLMNList>(); break;
			case 6: var.destroy<M6Configuration>(); break;
			case 7: var.destroy<M7Configuration>(); break;
			case 8: var.destroy<BluetoothMeasurementConfiguration>(); break;
			case 9: var.destroy<WLANMeasurementConfiguration>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<M3Configuration>(1);
			v.template operator()<M4Configuration>(2);
			v.template operator()<M5Configuration>(3);
			v.template operator()<MDT_Location_Info>(4);
			v.template operator()<MDTPLMNList>(5);
			v.template operator()<M6Configuration>(6);
			v.template operator()<M7Configuration>(7);
			v.template operator()<BluetoothMeasurementConfiguration>(8);
			v.template operator()<WLANMeasurementConfiguration>(9);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_M3Configuration()); return true;
			case 2: v(select_id_M4Configuration()); return true;
			case 3: v(select_id_M5Configuration()); return true;
			case 4: v(select_id_MDT_Location_Info()); return true;
			case 5: v(select_id_SignallingBasedMDTPLMNList()); return true;
			case 6: v(select_id_M6Configuration()); return true;
			case 7: v(select_id_M7Configuration()); return true;
			case 8: v(select_id_BluetoothMeasurementConfiguration()); return true;
			case 9: v(select_id_WLANMeasurementConfiguration()); return true;
			case 10: if(type != 10) {clear(); asn::base::set();} type = 10; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<M3Configuration>()); return true;
			case 2: v(var.as<M4Configuration>()); return true;
			case 3: v(var.as<M5Configuration>()); return true;
			case 4: v(var.as<MDT_Location_Info>()); return true;
			case 5: v(var.as<MDTPLMNList>()); return true;
			case 6: v(var.as<M6Configuration>()); return true;
			case 7: v(var.as<M7Configuration>()); return true;
			case 8: v(var.as<BluetoothMeasurementConfiguration>()); return true;
			case 9: v(var.as<WLANMeasurementConfiguration>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(BluetoothMeasurementConfiguration)];
			char dummy2[sizeof(M3Configuration)];
			char dummy3[sizeof(M4Configuration)];
			char dummy4[sizeof(M5Configuration)];
			char dummy5[sizeof(M6Configuration)];
			char dummy6[sizeof(M7Configuration)];
			char dummy7[sizeof(MDTPLMNList)];
			char dummy8[sizeof(MDT_Location_Info)];
			char dummy9[sizeof(WLANMeasurementConfiguration)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 10; }
		void clear() {type = 0;}
		void select_id_M3Configuration() { set(conditional); type=1;}
		void select_id_M4Configuration() { set(conditional); type=2;}
		void select_id_M5Configuration() { set(conditional); type=3;}
		void select_id_MDT_Location_Info() { set(optional); type=4;}
		void select_id_SignallingBasedMDTPLMNList() { set(optional); type=5;}
		void select_id_M6Configuration() { set(conditional); type=6;}
		void select_id_M7Configuration() { set(conditional); type=7;}
		void select_id_BluetoothMeasurementConfiguration() { set(optional); type=8;}
		void select_id_WLANMeasurementConfiguration() { set(optional); type=9;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(conditional)) { type = 1; return true; }
			else if(equal(conditional)) { type = 2; return true; }
			else if(equal(conditional)) { type = 3; return true; }
			else if(equal(optional)) { type = 4; return true; }
			else if(equal(optional)) { type = 5; return true; }
			else if(equal(conditional)) { type = 6; return true; }
			else if(equal(conditional)) { type = 7; return true; }
			else if(equal(optional)) { type = 8; return true; }
			else if(equal(optional)) { type = 9; return true; }
			else { type = 10; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(conditional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(conditional);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(conditional);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(optional);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(optional);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(conditional);} return false;
			case 7: type = 7; if(v(ref_nested())) { return equal(conditional);} return false;
			case 8: type = 8; if(v(ref_nested())) { return equal(optional);} return false;
			case 9: type = 9; if(v(ref_nested())) { return equal(optional);} return false;
			case 10: type = 10; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
MDT-Configuration ::= SEQUENCE {
	mdt-Activation				MDT-Activation,
	areaScopeOfMDT				AreaScopeOfMDT,
	measurementsToActivate		MeasurementsToActivate,
	m1reportingTrigger			M1ReportingTrigger,
	m1thresholdeventA2			M1ThresholdEventA2			OPTIONAL,
-- Included in case of event-triggered, or event-triggered periodic reporting for measurement M1
	m1periodicReporting			M1PeriodicReporting			OPTIONAL,
-- Included in case of periodic, or event-triggered periodic reporting for measurement M1
	iE-Extensions				ProtocolExtensionContainer { {MDT-Configuration-ExtIEs} } OPTIONAL,
	...
}
*/

struct MDT_Configuration : asn::sequence<7, 0, true, 3>
{
	static constexpr const char* name() {return "MDT-Configuration";}
	using parent_t = asn::sequence<7, 0, true, 3>;
	struct mdt_Activation_t : MDT_Activation
	{
		static constexpr const char* name() {return "mdt_Activation_t";}
		using parent_t = MDT_Activation;

	};
	mdt_Activation_t& ref_mdt_Activation() {return mdt_Activation;}
	mdt_Activation_t const& ref_mdt_Activation() const {return mdt_Activation;}
	struct areaScopeOfMDT_t : AreaScopeOfMDT
	{
		static constexpr const char* name() {return "areaScopeOfMDT_t";}
		using parent_t = AreaScopeOfMDT;

	};
	areaScopeOfMDT_t& ref_areaScopeOfMDT() {return areaScopeOfMDT;}
	areaScopeOfMDT_t const& ref_areaScopeOfMDT() const {return areaScopeOfMDT;}
	struct measurementsToActivate_t : MeasurementsToActivate
	{
		static constexpr const char* name() {return "measurementsToActivate_t";}
		using parent_t = MeasurementsToActivate;

	};
	measurementsToActivate_t& ref_measurementsToActivate() {return measurementsToActivate;}
	measurementsToActivate_t const& ref_measurementsToActivate() const {return measurementsToActivate;}
	struct m1reportingTrigger_t : M1ReportingTrigger
	{
		static constexpr const char* name() {return "m1reportingTrigger_t";}
		using parent_t = M1ReportingTrigger;

	};
	m1reportingTrigger_t& ref_m1reportingTrigger() {return m1reportingTrigger;}
	m1reportingTrigger_t const& ref_m1reportingTrigger() const {return m1reportingTrigger;}
	struct m1thresholdeventA2_t : M1ThresholdEventA2
	{
		static constexpr const char* name() {return "m1thresholdeventA2_t";}
		using parent_t = M1ThresholdEventA2;
		static constexpr bool optional = true;

	};
	m1thresholdeventA2_t& set_m1thresholdeventA2() { m1thresholdeventA2.setpresent(true); return m1thresholdeventA2;}
	m1thresholdeventA2_t const* get_m1thresholdeventA2() const {return m1thresholdeventA2.is_valid() ? &m1thresholdeventA2 : nullptr;}
	struct m1periodicReporting_t : M1PeriodicReporting
	{
		static constexpr const char* name() {return "m1periodicReporting_t";}
		using parent_t = M1PeriodicReporting;
		static constexpr bool optional = true;

	};
	m1periodicReporting_t& set_m1periodicReporting() { m1periodicReporting.setpresent(true); return m1periodicReporting;}
	m1periodicReporting_t const* get_m1periodicReporting() const {return m1periodicReporting.is_valid() ? &m1periodicReporting : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<MDT_Configuration_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<MDT_Configuration_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(mdt_Activation);
		v(areaScopeOfMDT);
		v(measurementsToActivate);
		v(m1reportingTrigger);
		v(m1thresholdeventA2);
		v(m1periodicReporting);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(mdt_Activation);
		v(areaScopeOfMDT);
		v(measurementsToActivate);
		v(m1reportingTrigger);
		v(m1thresholdeventA2);
		v(m1periodicReporting);
		v(iE_Extensions);

	};
	void clear()
	{
		mdt_Activation.clear();
		areaScopeOfMDT.clear();
		measurementsToActivate.clear();
		m1reportingTrigger.clear();
		m1thresholdeventA2.clear();
		m1periodicReporting.clear();
		iE_Extensions.clear();

	};
	private:
	mdt_Activation_t	mdt_Activation;
	areaScopeOfMDT_t	areaScopeOfMDT;
	measurementsToActivate_t	measurementsToActivate;
	m1reportingTrigger_t	m1reportingTrigger;
	m1thresholdeventA2_t	m1thresholdeventA2;
	m1periodicReporting_t	m1periodicReporting;
	iE_Extensions_t	iE_Extensions;

};
/*
MakeBeforeBreakIndicator::= ENUMERATED {true, ...}
*/

struct MakeBeforeBreakIndicator : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "MakeBeforeBreakIndicator";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		True
	} index_t;

};

/*
ManagementBasedMDTallowed ::= ENUMERATED {allowed, ...}
*/

struct ManagementBasedMDTallowed : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "ManagementBasedMDTallowed";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		allowed
	} index_t;

};

/*
Masked-IMEISV ::= BIT STRING (SIZE (64))
*/

struct Masked_IMEISV : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<64>>;
	static constexpr const char* name() {return "Masked-IMEISV";}
	using parent_t = asn::bstring<>;

};

/*
MeNBCoordinationAssistanceInformation ::= ENUMERATED{
	coordination-not-required,
	...
}
*/

struct MeNBCoordinationAssistanceInformation : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "MeNBCoordinationAssistanceInformation";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		coordination_not_required
	} index_t;

};

/*
NRCellIdentifier ::= BIT STRING (SIZE (36))
*/

struct NRCellIdentifier : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<36>>;
	static constexpr const char* name() {return "NRCellIdentifier";}
	using parent_t = asn::bstring<>;

};

/*
NRCGI-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct NRCGI_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
NRCGI ::= SEQUENCE {
	pLMN-Identity				PLMN-Identity,
	nRcellIdentifier				NRCellIdentifier,
	iE-Extensions				ProtocolExtensionContainer { {NRCGI-ExtIEs} } OPTIONAL,
	...
}
*/

struct NRCGI : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "NRCGI";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct pLMN_Identity_t : PLMN_Identity
	{
		static constexpr const char* name() {return "pLMN_Identity_t";}
		using parent_t = PLMN_Identity;

	};
	pLMN_Identity_t& ref_pLMN_Identity() {return pLMN_Identity;}
	pLMN_Identity_t const& ref_pLMN_Identity() const {return pLMN_Identity;}
	struct nRcellIdentifier_t : NRCellIdentifier
	{
		static constexpr const char* name() {return "nRcellIdentifier_t";}
		using parent_t = NRCellIdentifier;

	};
	nRcellIdentifier_t& ref_nRcellIdentifier() {return nRcellIdentifier;}
	nRcellIdentifier_t const& ref_nRcellIdentifier() const {return nRcellIdentifier;}
	struct iE_Extensions_t : ProtocolExtensionContainer<NRCGI_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<NRCGI_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pLMN_Identity);
		v(nRcellIdentifier);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pLMN_Identity);
		v(nRcellIdentifier);
		v(iE_Extensions);

	};
	void clear()
	{
		pLMN_Identity.clear();
		nRcellIdentifier.clear();
		iE_Extensions.clear();

	};
	private:
	pLMN_Identity_t	pLMN_Identity;
	nRcellIdentifier_t	nRcellIdentifier;
	iE_Extensions_t	iE_Extensions;

};
/*
MeNBResourceCoordinationInformationExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-NRCGI									CRITICALITY ignore	EXTENSION NRCGI												PRESENCE optional}|
	{ ID id-MeNBCoordinationAssistanceInformation		CRITICALITY reject	EXTENSION MeNBCoordinationAssistanceInformation	PRESENCE optional},
	...
}
*/

struct MeNBResourceCoordinationInformationExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_NRCGI() { set(id_NRCGI); type=1;}
		void select_id_MeNBCoordinationAssistanceInformation() { set(id_MeNBCoordinationAssistanceInformation); type=2;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_NRCGI)) { type = 1; return true; }
			else if(equal(id_MeNBCoordinationAssistanceInformation)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_NRCGI);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_MeNBCoordinationAssistanceInformation);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_NRCGI() { set(ignore); type=1;}
		void select_id_MeNBCoordinationAssistanceInformation() { set(reject); type=2;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(reject)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(reject);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		NRCGI& select_id_NRCGI() { return set<NRCGI>(1); }
		NRCGI const* get_id_NRCGI() const { return get<NRCGI>(1); }
		MeNBCoordinationAssistanceInformation& select_id_MeNBCoordinationAssistanceInformation() { return set<MeNBCoordinationAssistanceInformation>(2); }
		MeNBCoordinationAssistanceInformation const* get_id_MeNBCoordinationAssistanceInformation() const { return get<MeNBCoordinationAssistanceInformation>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<NRCGI>(); break;
			case 2: var.destroy<MeNBCoordinationAssistanceInformation>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<NRCGI>(1);
			v.template operator()<MeNBCoordinationAssistanceInformation>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_NRCGI()); return true;
			case 2: v(select_id_MeNBCoordinationAssistanceInformation()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<NRCGI>()); return true;
			case 2: v(var.as<MeNBCoordinationAssistanceInformation>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(MeNBCoordinationAssistanceInformation)];
			char dummy2[sizeof(NRCGI)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_NRCGI() { set(optional); type=1;}
		void select_id_MeNBCoordinationAssistanceInformation() { set(optional); type=2;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
MeNBResourceCoordinationInformation ::= SEQUENCE {
	eUTRA-Cell-ID					ECGI,
	uLCoordinationInformation		BIT STRING (SIZE(6..4400, ...)),
	dLCoordinationInformation		BIT STRING (SIZE(6..4400, ...))		OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {MeNBResourceCoordinationInformationExtIEs} }		 OPTIONAL,
	...
}
*/

struct MeNBResourceCoordinationInformation : asn::sequence<4, 0, true, 2>
{
	static constexpr const char* name() {return "MeNBResourceCoordinationInformation";}
	using parent_t = asn::sequence<4, 0, true, 2>;
	struct eUTRA_Cell_ID_t : ECGI
	{
		static constexpr const char* name() {return "eUTRA_Cell_ID_t";}
		using parent_t = ECGI;

	};
	eUTRA_Cell_ID_t& ref_eUTRA_Cell_ID() {return eUTRA_Cell_ID;}
	eUTRA_Cell_ID_t const& ref_eUTRA_Cell_ID() const {return eUTRA_Cell_ID;}
	struct uLCoordinationInformation_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::span<6, 4400>>;
		static constexpr const char* name() {return "uLCoordinationInformation_t";}
		using parent_t = asn::bstring<>;

	};

	uLCoordinationInformation_t& ref_uLCoordinationInformation() {return uLCoordinationInformation;}
	uLCoordinationInformation_t const& ref_uLCoordinationInformation() const {return uLCoordinationInformation;}
	struct dLCoordinationInformation_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::span<6, 4400>>;
		static constexpr const char* name() {return "dLCoordinationInformation_t";}
		using parent_t = asn::bstring<>;
		static constexpr bool optional = true;

	};

	dLCoordinationInformation_t& set_dLCoordinationInformation() { dLCoordinationInformation.setpresent(true); return dLCoordinationInformation;}
	dLCoordinationInformation_t const* get_dLCoordinationInformation() const {return dLCoordinationInformation.is_valid() ? &dLCoordinationInformation : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<MeNBResourceCoordinationInformationExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<MeNBResourceCoordinationInformationExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(eUTRA_Cell_ID);
		v(uLCoordinationInformation);
		v(dLCoordinationInformation);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(eUTRA_Cell_ID);
		v(uLCoordinationInformation);
		v(dLCoordinationInformation);
		v(iE_Extensions);

	};
	void clear()
	{
		eUTRA_Cell_ID.clear();
		uLCoordinationInformation.clear();
		dLCoordinationInformation.clear();
		iE_Extensions.clear();

	};
	private:
	eUTRA_Cell_ID_t	eUTRA_Cell_ID;
	uLCoordinationInformation_t	uLCoordinationInformation;
	dLCoordinationInformation_t	dLCoordinationInformation;
	iE_Extensions_t	iE_Extensions;

};
/*
MeNBtoSeNBContainer ::= OCTET STRING
*/

struct MeNBtoSeNBContainer : asn::ostring<>
{
	static constexpr const char* name() {return "MeNBtoSeNBContainer";}
	using parent_t = asn::ostring<>;

};

/*
MeNBtoSgNBContainer ::= OCTET STRING
*/

struct MeNBtoSgNBContainer : asn::ostring<>
{
	static constexpr const char* name() {return "MeNBtoSgNBContainer";}
	using parent_t = asn::ostring<>;

};

/*
Measurement-ID	::= INTEGER (1..4095, ...)
*/

struct Measurement_ID : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<1, 4095>>;
	static constexpr const char* name() {return "Measurement-ID";}
	using parent_t = asn::integer<>;

};

/*
MobilityParametersInformation ::= SEQUENCE {
	handoverTriggerChange			INTEGER (-20..20),
	...
}
*/

struct MobilityParametersInformation : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "MobilityParametersInformation";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct handoverTriggerChange_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<-20, 20>>;
		static constexpr const char* name() {return "handoverTriggerChange_t";}
		using parent_t = asn::integer<>;

	};

	handoverTriggerChange_t& ref_handoverTriggerChange() {return handoverTriggerChange;}
	handoverTriggerChange_t const& ref_handoverTriggerChange() const {return handoverTriggerChange;}
	template<typename V> void decode(V& v)
	{
		v(handoverTriggerChange);

	};
	template<typename V> void encode(V& v) const
	{
		v(handoverTriggerChange);

	};
	void clear()
	{
		handoverTriggerChange.clear();

	};
	private:
	handoverTriggerChange_t	handoverTriggerChange;

};
/*
MobilityParametersModificationRange ::= SEQUENCE {
	handoverTriggerChangeLowerLimit		INTEGER (-20..20),
	handoverTriggerChangeUpperLimit		INTEGER (-20..20),
	...
}
*/

struct MobilityParametersModificationRange : asn::sequence<2, 0, true, 0>
{
	static constexpr const char* name() {return "MobilityParametersModificationRange";}
	using parent_t = asn::sequence<2, 0, true, 0>;
	struct handoverTriggerChangeLowerLimit_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<-20, 20>>;
		static constexpr const char* name() {return "handoverTriggerChangeLowerLimit_t";}
		using parent_t = asn::integer<>;

	};

	handoverTriggerChangeLowerLimit_t& ref_handoverTriggerChangeLowerLimit() {return handoverTriggerChangeLowerLimit;}
	handoverTriggerChangeLowerLimit_t const& ref_handoverTriggerChangeLowerLimit() const {return handoverTriggerChangeLowerLimit;}
	struct handoverTriggerChangeUpperLimit_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<-20, 20>>;
		static constexpr const char* name() {return "handoverTriggerChangeUpperLimit_t";}
		using parent_t = asn::integer<>;

	};

	handoverTriggerChangeUpperLimit_t& ref_handoverTriggerChangeUpperLimit() {return handoverTriggerChangeUpperLimit;}
	handoverTriggerChangeUpperLimit_t const& ref_handoverTriggerChangeUpperLimit() const {return handoverTriggerChangeUpperLimit;}
	template<typename V> void decode(V& v)
	{
		v(handoverTriggerChangeLowerLimit);
		v(handoverTriggerChangeUpperLimit);

	};
	template<typename V> void encode(V& v) const
	{
		v(handoverTriggerChangeLowerLimit);
		v(handoverTriggerChangeUpperLimit);

	};
	void clear()
	{
		handoverTriggerChangeLowerLimit.clear();
		handoverTriggerChangeUpperLimit.clear();

	};
	private:
	handoverTriggerChangeLowerLimit_t	handoverTriggerChangeLowerLimit;
	handoverTriggerChangeUpperLimit_t	handoverTriggerChangeUpperLimit;

};
/*
MultibandInfoList ::= SEQUENCE (SIZE(1..maxnoofBands)) OF BandInfo
*/

struct MultibandInfoList_elm : BandInfo
{
	static constexpr const char* name() {return "MultibandInfoList_elm";}
	using parent_t = BandInfo;

};
struct MultibandInfoList : asn::sequenceof<MultibandInfoList_elm>
{
	static constexpr const char* name() {return "MultibandInfoList";}
	using parent_t = asn::sequenceof<MultibandInfoList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBands >>;

};
/*
NRSCS ::= ENUMERATED { scs15, scs30, scs60, scs120, ...}
*/

struct NRSCS : asn::enumerated<4, 0, true>
{
	static constexpr const char* name() {return "NRSCS";}
	using parent_t = asn::enumerated<4, 0, true>;
	typedef enum {
		scs15
		,scs30
		,scs60
		,scs120
	} index_t;

};

/*
NRNRB ::= ENUMERATED { nrb11, nrb18, nrb24, nrb25, nrb31, nrb32, nrb38, nrb51, nrb52, nrb65, nrb66, nrb78, nrb79, nrb93, nrb106, nrb107, nrb121, nrb132, nrb133, nrb135, nrb160, nrb162, nrb189, nrb216, nrb217, nrb245, nrb264, nrb270, nrb273, ...}
*/

struct NRNRB : asn::enumerated<29, 0, true>
{
	static constexpr const char* name() {return "NRNRB";}
	using parent_t = asn::enumerated<29, 0, true>;
	typedef enum {
		nrb11
		,nrb18
		,nrb24
		,nrb25
		,nrb31
		,nrb32
		,nrb38
		,nrb51
		,nrb52
		,nrb65
		,nrb66
		,nrb78
		,nrb79
		,nrb93
		,nrb106
		,nrb107
		,nrb121
		,nrb132
		,nrb133
		,nrb135
		,nrb160
		,nrb162
		,nrb189
		,nrb216
		,nrb217
		,nrb245
		,nrb264
		,nrb270
		,nrb273
	} index_t;

};

/*
NR-TxBW-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct NR_TxBW_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
NR-TxBW	::= SEQUENCE {
	nRSCS	NRSCS,
	nRNRB	NRNRB,
	iE-Extensions				ProtocolExtensionContainer { {NR-TxBW-ExtIEs} } OPTIONAL,
	...
}
*/

struct NR_TxBW : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "NR-TxBW";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct nRSCS_t : NRSCS
	{
		static constexpr const char* name() {return "nRSCS_t";}
		using parent_t = NRSCS;

	};
	nRSCS_t& ref_nRSCS() {return nRSCS;}
	nRSCS_t const& ref_nRSCS() const {return nRSCS;}
	struct nRNRB_t : NRNRB
	{
		static constexpr const char* name() {return "nRNRB_t";}
		using parent_t = NRNRB;

	};
	nRNRB_t& ref_nRNRB() {return nRNRB;}
	nRNRB_t const& ref_nRNRB() const {return nRNRB;}
	struct iE_Extensions_t : ProtocolExtensionContainer<NR_TxBW_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<NR_TxBW_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(nRSCS);
		v(nRNRB);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(nRSCS);
		v(nRNRB);
		v(iE_Extensions);

	};
	void clear()
	{
		nRSCS.clear();
		nRNRB.clear();
		iE_Extensions.clear();

	};
	private:
	nRSCS_t	nRSCS;
	nRNRB_t	nRNRB;
	iE_Extensions_t	iE_Extensions;

};
/*
SULInformation-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct SULInformation_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
SULInformation ::= SEQUENCE {
	sUL-ARFCN				INTEGER (0.. 3279165),
	sUL-TxBW				NR-TxBW,
	iE-Extensions			ProtocolExtensionContainer { {SULInformation-ExtIEs} }		OPTIONAL,
	...
}
*/

struct SULInformation : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "SULInformation";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct sUL_ARFCN_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 3279165>>;
		static constexpr const char* name() {return "sUL_ARFCN_t";}
		using parent_t = asn::integer<>;

	};

	sUL_ARFCN_t& ref_sUL_ARFCN() {return sUL_ARFCN;}
	sUL_ARFCN_t const& ref_sUL_ARFCN() const {return sUL_ARFCN;}
	struct sUL_TxBW_t : NR_TxBW
	{
		static constexpr const char* name() {return "sUL_TxBW_t";}
		using parent_t = NR_TxBW;

	};
	sUL_TxBW_t& ref_sUL_TxBW() {return sUL_TxBW;}
	sUL_TxBW_t const& ref_sUL_TxBW() const {return sUL_TxBW;}
	struct iE_Extensions_t : ProtocolExtensionContainer<SULInformation_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<SULInformation_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(sUL_ARFCN);
		v(sUL_TxBW);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(sUL_ARFCN);
		v(sUL_TxBW);
		v(iE_Extensions);

	};
	void clear()
	{
		sUL_ARFCN.clear();
		sUL_TxBW.clear();
		iE_Extensions.clear();

	};
	private:
	sUL_ARFCN_t	sUL_ARFCN;
	sUL_TxBW_t	sUL_TxBW;
	iE_Extensions_t	iE_Extensions;

};
/*
NRFreqInfo-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct NRFreqInfo_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
NRFreqInfo ::= SEQUENCE{
	nRARFCN			INTEGER (0.. 3279165),
	freqBandListNr	SEQUENCE (SIZE(1..maxnoofNrCellBands)) OF FreqBandNrItem,
	sULInformation	SULInformation		OPTIONAL,
	iE-Extensions	ProtocolExtensionContainer { {NRFreqInfo-ExtIEs} } OPTIONAL,

	...
}
*/

struct NRFreqInfo : asn::sequence<4, 0, true, 2>
{
	static constexpr const char* name() {return "NRFreqInfo";}
	using parent_t = asn::sequence<4, 0, true, 2>;
	struct nRARFCN_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 3279165>>;
		static constexpr const char* name() {return "nRARFCN_t";}
		using parent_t = asn::integer<>;

	};

	nRARFCN_t& ref_nRARFCN() {return nRARFCN;}
	nRARFCN_t const& ref_nRARFCN() const {return nRARFCN;}
	struct freqBandListNr_t_elm : FreqBandNrItem
	{
		static constexpr const char* name() {return "freqBandListNr_t_elm";}
		using parent_t = FreqBandNrItem;

	};
	struct freqBandListNr_t : asn::sequenceof<freqBandListNr_t_elm>
	{
		static constexpr const char* name() {return "freqBandListNr_t";}
		using parent_t = asn::sequenceof<freqBandListNr_t_elm>;
		using constraint_t = asn::constraints<false,asn::span<1,  maxnoofNrCellBands >>;

	};
	freqBandListNr_t& ref_freqBandListNr() {return freqBandListNr;}
	freqBandListNr_t const& ref_freqBandListNr() const {return freqBandListNr;}
	struct sULInformation_t : SULInformation
	{
		static constexpr const char* name() {return "sULInformation_t";}
		using parent_t = SULInformation;
		static constexpr bool optional = true;

	};
	sULInformation_t& set_sULInformation() { sULInformation.setpresent(true); return sULInformation;}
	sULInformation_t const* get_sULInformation() const {return sULInformation.is_valid() ? &sULInformation : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<NRFreqInfo_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<NRFreqInfo_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(nRARFCN);
		v(freqBandListNr);
		v(sULInformation);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(nRARFCN);
		v(freqBandListNr);
		v(sULInformation);
		v(iE_Extensions);

	};
	void clear()
	{
		nRARFCN.clear();
		freqBandListNr.clear();
		sULInformation.clear();
		iE_Extensions.clear();

	};
	private:
	nRARFCN_t	nRARFCN;
	freqBandListNr_t	freqBandListNr;
	sULInformation_t	sULInformation;
	iE_Extensions_t	iE_Extensions;

};
/*
NRPCI ::= INTEGER (0..1007)
*/

struct NRPCI : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 1007>>;
	static constexpr const char* name() {return "NRPCI";}
	using parent_t = asn::integer<>;

};

/*
NRencryptionAlgorithms ::= BIT STRING (SIZE (16,...))
*/

struct NRencryptionAlgorithms : asn::bstring<>
{
	using constraint_t = asn::constraints<true,asn::one<16>>;
	static constexpr const char* name() {return "NRencryptionAlgorithms";}
	using parent_t = asn::bstring<>;

};

/*
NRintegrityProtectionAlgorithms ::= BIT STRING (SIZE (16,...))
*/

struct NRintegrityProtectionAlgorithms : asn::bstring<>
{
	using constraint_t = asn::constraints<true,asn::one<16>>;
	static constexpr const char* name() {return "NRintegrityProtectionAlgorithms";}
	using parent_t = asn::bstring<>;

};

/*
NRUESecurityCapabilities-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct NRUESecurityCapabilities_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
NRUESecurityCapabilities ::= SEQUENCE {
	nRencryptionAlgorithms				NRencryptionAlgorithms,
	nRintegrityProtectionAlgorithms		NRintegrityProtectionAlgorithms,
	iE-Extensions						ProtocolExtensionContainer { {NRUESecurityCapabilities-ExtIEs} }	OPTIONAL,
...
}
*/

struct NRUESecurityCapabilities : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "NRUESecurityCapabilities";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct nRencryptionAlgorithms_t : NRencryptionAlgorithms
	{
		static constexpr const char* name() {return "nRencryptionAlgorithms_t";}
		using parent_t = NRencryptionAlgorithms;

	};
	nRencryptionAlgorithms_t& ref_nRencryptionAlgorithms() {return nRencryptionAlgorithms;}
	nRencryptionAlgorithms_t const& ref_nRencryptionAlgorithms() const {return nRencryptionAlgorithms;}
	struct nRintegrityProtectionAlgorithms_t : NRintegrityProtectionAlgorithms
	{
		static constexpr const char* name() {return "nRintegrityProtectionAlgorithms_t";}
		using parent_t = NRintegrityProtectionAlgorithms;

	};
	nRintegrityProtectionAlgorithms_t& ref_nRintegrityProtectionAlgorithms() {return nRintegrityProtectionAlgorithms;}
	nRintegrityProtectionAlgorithms_t const& ref_nRintegrityProtectionAlgorithms() const {return nRintegrityProtectionAlgorithms;}
	struct iE_Extensions_t : ProtocolExtensionContainer<NRUESecurityCapabilities_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<NRUESecurityCapabilities_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(nRencryptionAlgorithms);
		v(nRintegrityProtectionAlgorithms);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(nRencryptionAlgorithms);
		v(nRintegrityProtectionAlgorithms);
		v(iE_Extensions);

	};
	void clear()
	{
		nRencryptionAlgorithms.clear();
		nRintegrityProtectionAlgorithms.clear();
		iE_Extensions.clear();

	};
	private:
	nRencryptionAlgorithms_t	nRencryptionAlgorithms;
	nRintegrityProtectionAlgorithms_t	nRintegrityProtectionAlgorithms;
	iE_Extensions_t	iE_Extensions;

};
/*
PCI ::= INTEGER (0..503, ...)
*/

struct PCI : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<0, 503>>;
	static constexpr const char* name() {return "PCI";}
	using parent_t = asn::integer<>;

};

/*
Neighbour-Information-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-NeighbourTAC		CRITICALITY ignore	EXTENSION TAC				PRESENCE optional}|
	{ ID id-eARFCNExtension		CRITICALITY reject	EXTENSION EARFCNExtension	PRESENCE optional},
	...
}
*/

struct Neighbour_Information_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_NeighbourTAC() { set(id_NeighbourTAC); type=1;}
		void select_id_eARFCNExtension() { set(id_eARFCNExtension); type=2;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_NeighbourTAC)) { type = 1; return true; }
			else if(equal(id_eARFCNExtension)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_NeighbourTAC);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_eARFCNExtension);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_NeighbourTAC() { set(ignore); type=1;}
		void select_id_eARFCNExtension() { set(reject); type=2;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(reject)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(reject);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		TAC& select_id_NeighbourTAC() { return set<TAC>(1); }
		TAC const* get_id_NeighbourTAC() const { return get<TAC>(1); }
		EARFCNExtension& select_id_eARFCNExtension() { return set<EARFCNExtension>(2); }
		EARFCNExtension const* get_id_eARFCNExtension() const { return get<EARFCNExtension>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<TAC>(); break;
			case 2: var.destroy<EARFCNExtension>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<TAC>(1);
			v.template operator()<EARFCNExtension>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_NeighbourTAC()); return true;
			case 2: v(select_id_eARFCNExtension()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<TAC>()); return true;
			case 2: v(var.as<EARFCNExtension>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(EARFCNExtension)];
			char dummy2[sizeof(TAC)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_NeighbourTAC() { set(optional); type=1;}
		void select_id_eARFCNExtension() { set(optional); type=2;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
Neighbour-Information ::= SEQUENCE (SIZE (0..maxnoofNeighbours)) OF SEQUENCE {
	eCGI						ECGI,
	pCI							PCI,
	eARFCN						EARFCN,
	iE-Extensions				ProtocolExtensionContainer { {Neighbour-Information-ExtIEs} } OPTIONAL,
	...
}
*/

struct Neighbour_Information_elm : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "Neighbour_Information_elm";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct eCGI_t : ECGI
	{
		static constexpr const char* name() {return "eCGI_t";}
		using parent_t = ECGI;

	};
	eCGI_t& ref_eCGI() {return eCGI;}
	eCGI_t const& ref_eCGI() const {return eCGI;}
	struct pCI_t : PCI
	{
		static constexpr const char* name() {return "pCI_t";}
		using parent_t = PCI;

	};
	pCI_t& ref_pCI() {return pCI;}
	pCI_t const& ref_pCI() const {return pCI;}
	struct eARFCN_t : EARFCN
	{
		static constexpr const char* name() {return "eARFCN_t";}
		using parent_t = EARFCN;

	};
	eARFCN_t& ref_eARFCN() {return eARFCN;}
	eARFCN_t const& ref_eARFCN() const {return eARFCN;}
	struct iE_Extensions_t : ProtocolExtensionContainer<Neighbour_Information_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<Neighbour_Information_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(eCGI);
		v(pCI);
		v(eARFCN);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(eCGI);
		v(pCI);
		v(eARFCN);
		v(iE_Extensions);

	};
	void clear()
	{
		eCGI.clear();
		pCI.clear();
		eARFCN.clear();
		iE_Extensions.clear();

	};
	private:
	eCGI_t	eCGI;
	pCI_t	pCI;
	eARFCN_t	eARFCN;
	iE_Extensions_t	iE_Extensions;

};
struct Neighbour_Information : asn::sequenceof<Neighbour_Information_elm>
{
	static constexpr const char* name() {return "Neighbour-Information";}
	using parent_t = asn::sequenceof<Neighbour_Information_elm>;
	using constraint_t = asn::constraints<false,asn::span<0,  maxnoofNeighbours >>;

};
/*
NewDRBIDrequest::= ENUMERATED {true, ...}
*/

struct NewDRBIDrequest : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "NewDRBIDrequest";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		True
	} index_t;

};

/*
Number-of-Antennaports ::= ENUMERATED {
		an1,
	 	an2,
		an4,
		...
}
*/

struct Number_of_Antennaports : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "Number-of-Antennaports";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		an1
		,an2
		,an4
	} index_t;

};

/*
PDCPChangeIndication ::= ENUMERATED {s-KgNB-update-required, pDCP-data-recovery-required,...}
*/

struct PDCPChangeIndication : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "PDCPChangeIndication";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		s_KgNB_update_required
		,pDCP_data_recovery_required
	} index_t;

};

/*
PDCPSnLength	::=	ENUMERATED {twelve-bits,eighteen-bits,...}
*/

struct PDCPSnLength : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "PDCPSnLength";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		twelve_bits
		,eighteen_bits
	} index_t;

};

/*
PRACH-Configuration-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct PRACH_Configuration_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
PRACH-Configuration ::= SEQUENCE {
	rootSequenceIndex						INTEGER (0..837),
	zeroCorrelationIndex					INTEGER (0..15),
	highSpeedFlag							BOOLEAN,
	prach-FreqOffset						INTEGER (0..94),
	prach-ConfigIndex						INTEGER (0..63)		OPTIONAL, -- present for TDD --
	iE-Extensions							ProtocolExtensionContainer { {PRACH-Configuration-ExtIEs} }	OPTIONAL,
	...
}
*/

struct PRACH_Configuration : asn::sequence<6, 0, true, 2>
{
	static constexpr const char* name() {return "PRACH-Configuration";}
	using parent_t = asn::sequence<6, 0, true, 2>;
	struct rootSequenceIndex_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 837>>;
		static constexpr const char* name() {return "rootSequenceIndex_t";}
		using parent_t = asn::integer<>;

	};

	rootSequenceIndex_t& ref_rootSequenceIndex() {return rootSequenceIndex;}
	rootSequenceIndex_t const& ref_rootSequenceIndex() const {return rootSequenceIndex;}
	struct zeroCorrelationIndex_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 15>>;
		static constexpr const char* name() {return "zeroCorrelationIndex_t";}
		using parent_t = asn::integer<>;

	};

	zeroCorrelationIndex_t& ref_zeroCorrelationIndex() {return zeroCorrelationIndex;}
	zeroCorrelationIndex_t const& ref_zeroCorrelationIndex() const {return zeroCorrelationIndex;}
	struct highSpeedFlag_t : asn::boolean
	{
		static constexpr const char* name() {return "highSpeedFlag_t";}
		using parent_t = asn::boolean;

	};
	highSpeedFlag_t& ref_highSpeedFlag() {return highSpeedFlag;}
	highSpeedFlag_t const& ref_highSpeedFlag() const {return highSpeedFlag;}
	struct prach_FreqOffset_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 94>>;
		static constexpr const char* name() {return "prach_FreqOffset_t";}
		using parent_t = asn::integer<>;

	};

	prach_FreqOffset_t& ref_prach_FreqOffset() {return prach_FreqOffset;}
	prach_FreqOffset_t const& ref_prach_FreqOffset() const {return prach_FreqOffset;}
	struct prach_ConfigIndex_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 63>>;
		static constexpr const char* name() {return "prach_ConfigIndex_t";}
		using parent_t = asn::integer<>;
		static constexpr bool optional = true;

	};

	prach_ConfigIndex_t& set_prach_ConfigIndex() { prach_ConfigIndex.setpresent(true); return prach_ConfigIndex;}
	prach_ConfigIndex_t const* get_prach_ConfigIndex() const {return prach_ConfigIndex.is_valid() ? &prach_ConfigIndex : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<PRACH_Configuration_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<PRACH_Configuration_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(rootSequenceIndex);
		v(zeroCorrelationIndex);
		v(highSpeedFlag);
		v(prach_FreqOffset);
		v(prach_ConfigIndex);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(rootSequenceIndex);
		v(zeroCorrelationIndex);
		v(highSpeedFlag);
		v(prach_FreqOffset);
		v(prach_ConfigIndex);
		v(iE_Extensions);

	};
	void clear()
	{
		rootSequenceIndex.clear();
		zeroCorrelationIndex.clear();
		highSpeedFlag.clear();
		prach_FreqOffset.clear();
		prach_ConfigIndex.clear();
		iE_Extensions.clear();

	};
	private:
	rootSequenceIndex_t	rootSequenceIndex;
	zeroCorrelationIndex_t	zeroCorrelationIndex;
	highSpeedFlag_t	highSpeedFlag;
	prach_FreqOffset_t	prach_FreqOffset;
	prach_ConfigIndex_t	prach_ConfigIndex;
	iE_Extensions_t	iE_Extensions;

};
/*
PedestrianUE ::= ENUMERATED {
	authorized,
	not-authorized,
	...
}
*/

struct PedestrianUE : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "PedestrianUE";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		authorized
		,not_authorized
	} index_t;

};

/*
Port-Number ::= OCTET STRING (SIZE (2))
*/

struct Port_Number : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<2>>;
	static constexpr const char* name() {return "Port-Number";}
	using parent_t = asn::ostring<>;

};

/*
ProSeDirectDiscovery ::= ENUMERATED {
	authorized,
	not-authorized,
	...
}
*/

struct ProSeDirectDiscovery : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "ProSeDirectDiscovery";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		authorized
		,not_authorized
	} index_t;

};

/*
ProSeDirectCommunication ::= ENUMERATED {
	authorized,
	not-authorized,
	...
}
*/

struct ProSeDirectCommunication : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "ProSeDirectCommunication";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		authorized
		,not_authorized
	} index_t;

};

/*
ProSeUEtoNetworkRelaying ::= ENUMERATED {
	authorized,
	not-authorized,
	...
}
*/

struct ProSeUEtoNetworkRelaying : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "ProSeUEtoNetworkRelaying";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		authorized
		,not_authorized
	} index_t;

};

/*
ProSeAuthorized-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-ProSeUEtoNetworkRelaying	CRITICALITY ignore	EXTENSION ProSeUEtoNetworkRelaying		PRESENCE optional},
	...
}
*/

struct ProSeAuthorized_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_ProSeUEtoNetworkRelaying() { set(id_ProSeUEtoNetworkRelaying); type=1;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_ProSeUEtoNetworkRelaying)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_ProSeUEtoNetworkRelaying);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_ProSeUEtoNetworkRelaying() { set(ignore); type=1;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		ProSeUEtoNetworkRelaying& select_id_ProSeUEtoNetworkRelaying() { return set<ProSeUEtoNetworkRelaying>(1); }
		ProSeUEtoNetworkRelaying const* get_id_ProSeUEtoNetworkRelaying() const { return get<ProSeUEtoNetworkRelaying>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<ProSeUEtoNetworkRelaying>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<ProSeUEtoNetworkRelaying>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_ProSeUEtoNetworkRelaying()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<ProSeUEtoNetworkRelaying>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(ProSeUEtoNetworkRelaying)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_ProSeUEtoNetworkRelaying() { set(optional); type=1;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ProSeAuthorized ::= SEQUENCE {
	proSeDirectDiscovery		ProSeDirectDiscovery			OPTIONAL,
	proSeDirectCommunication	ProSeDirectCommunication		OPTIONAL,
	iE-Extensions				ProtocolExtensionContainer { {ProSeAuthorized-ExtIEs} }	OPTIONAL,
	...
}
*/

struct ProSeAuthorized : asn::sequence<3, 0, true, 3>
{
	static constexpr const char* name() {return "ProSeAuthorized";}
	using parent_t = asn::sequence<3, 0, true, 3>;
	struct proSeDirectDiscovery_t : ProSeDirectDiscovery
	{
		static constexpr const char* name() {return "proSeDirectDiscovery_t";}
		using parent_t = ProSeDirectDiscovery;
		static constexpr bool optional = true;

	};
	proSeDirectDiscovery_t& set_proSeDirectDiscovery() { proSeDirectDiscovery.setpresent(true); return proSeDirectDiscovery;}
	proSeDirectDiscovery_t const* get_proSeDirectDiscovery() const {return proSeDirectDiscovery.is_valid() ? &proSeDirectDiscovery : nullptr;}
	struct proSeDirectCommunication_t : ProSeDirectCommunication
	{
		static constexpr const char* name() {return "proSeDirectCommunication_t";}
		using parent_t = ProSeDirectCommunication;
		static constexpr bool optional = true;

	};
	proSeDirectCommunication_t& set_proSeDirectCommunication() { proSeDirectCommunication.setpresent(true); return proSeDirectCommunication;}
	proSeDirectCommunication_t const* get_proSeDirectCommunication() const {return proSeDirectCommunication.is_valid() ? &proSeDirectCommunication : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ProSeAuthorized_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ProSeAuthorized_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(proSeDirectDiscovery);
		v(proSeDirectCommunication);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(proSeDirectDiscovery);
		v(proSeDirectCommunication);
		v(iE_Extensions);

	};
	void clear()
	{
		proSeDirectDiscovery.clear();
		proSeDirectCommunication.clear();
		iE_Extensions.clear();

	};
	private:
	proSeDirectDiscovery_t	proSeDirectDiscovery;
	proSeDirectCommunication_t	proSeDirectCommunication;
	iE_Extensions_t	iE_Extensions;

};
/*
ResourceType ::= ENUMERATED {
	downlinknonCRS,
	cRS,
	uplink,
	...
}
*/

struct ResourceType : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "ResourceType";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		downlinknonCRS
		,cRS
		,uplink
	} index_t;

};

/*
ProtectedFootprintTimePattern-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ProtectedFootprintTimePattern_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ProtectedFootprintTimePattern ::= SEQUENCE {
	protectedFootprintTimePeriodicity				INTEGER (1..320, ...),
	protectedFootprintStartTime						INTEGER (1..20, ...),
	iE-Extensions									ProtocolExtensionContainer { {ProtectedFootprintTimePattern-ExtIEs} }	OPTIONAL,
	...
}
*/

struct ProtectedFootprintTimePattern : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "ProtectedFootprintTimePattern";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct protectedFootprintTimePeriodicity_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 320>>;
		static constexpr const char* name() {return "protectedFootprintTimePeriodicity_t";}
		using parent_t = asn::integer<>;

	};

	protectedFootprintTimePeriodicity_t& ref_protectedFootprintTimePeriodicity() {return protectedFootprintTimePeriodicity;}
	protectedFootprintTimePeriodicity_t const& ref_protectedFootprintTimePeriodicity() const {return protectedFootprintTimePeriodicity;}
	struct protectedFootprintStartTime_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 20>>;
		static constexpr const char* name() {return "protectedFootprintStartTime_t";}
		using parent_t = asn::integer<>;

	};

	protectedFootprintStartTime_t& ref_protectedFootprintStartTime() {return protectedFootprintStartTime;}
	protectedFootprintStartTime_t const& ref_protectedFootprintStartTime() const {return protectedFootprintStartTime;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ProtectedFootprintTimePattern_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ProtectedFootprintTimePattern_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(protectedFootprintTimePeriodicity);
		v(protectedFootprintStartTime);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(protectedFootprintTimePeriodicity);
		v(protectedFootprintStartTime);
		v(iE_Extensions);

	};
	void clear()
	{
		protectedFootprintTimePeriodicity.clear();
		protectedFootprintStartTime.clear();
		iE_Extensions.clear();

	};
	private:
	protectedFootprintTimePeriodicity_t	protectedFootprintTimePeriodicity;
	protectedFootprintStartTime_t	protectedFootprintStartTime;
	iE_Extensions_t	iE_Extensions;

};
/*
ProtectedResourceList-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ProtectedResourceList_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ProtectedResourceList-Item ::= SEQUENCE {
	resourceType					ResourceType,
	intraPRBProtectedResourceFootprint 		BIT STRING (SIZE(84, ...)),
	protectedFootprintFrequencyPattern 		BIT STRING (SIZE(6..110, ...)),
	protectedFootprintTimePattern			ProtectedFootprintTimePattern,
	iE-Extensions							ProtocolExtensionContainer { {ProtectedResourceList-Item-ExtIEs} }	OPTIONAL,
	...
}
*/

struct ProtectedResourceList_Item : asn::sequence<5, 0, true, 1>
{
	static constexpr const char* name() {return "ProtectedResourceList-Item";}
	using parent_t = asn::sequence<5, 0, true, 1>;
	struct resourceType_t : ResourceType
	{
		static constexpr const char* name() {return "resourceType_t";}
		using parent_t = ResourceType;

	};
	resourceType_t& ref_resourceType() {return resourceType;}
	resourceType_t const& ref_resourceType() const {return resourceType;}
	struct intraPRBProtectedResourceFootprint_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::one<84>>;
		static constexpr const char* name() {return "intraPRBProtectedResourceFootprint_t";}
		using parent_t = asn::bstring<>;

	};

	intraPRBProtectedResourceFootprint_t& ref_intraPRBProtectedResourceFootprint() {return intraPRBProtectedResourceFootprint;}
	intraPRBProtectedResourceFootprint_t const& ref_intraPRBProtectedResourceFootprint() const {return intraPRBProtectedResourceFootprint;}
	struct protectedFootprintFrequencyPattern_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::span<6, 110>>;
		static constexpr const char* name() {return "protectedFootprintFrequencyPattern_t";}
		using parent_t = asn::bstring<>;

	};

	protectedFootprintFrequencyPattern_t& ref_protectedFootprintFrequencyPattern() {return protectedFootprintFrequencyPattern;}
	protectedFootprintFrequencyPattern_t const& ref_protectedFootprintFrequencyPattern() const {return protectedFootprintFrequencyPattern;}
	struct protectedFootprintTimePattern_t : ProtectedFootprintTimePattern
	{
		static constexpr const char* name() {return "protectedFootprintTimePattern_t";}
		using parent_t = ProtectedFootprintTimePattern;

	};
	protectedFootprintTimePattern_t& ref_protectedFootprintTimePattern() {return protectedFootprintTimePattern;}
	protectedFootprintTimePattern_t const& ref_protectedFootprintTimePattern() const {return protectedFootprintTimePattern;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ProtectedResourceList_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ProtectedResourceList_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(resourceType);
		v(intraPRBProtectedResourceFootprint);
		v(protectedFootprintFrequencyPattern);
		v(protectedFootprintTimePattern);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(resourceType);
		v(intraPRBProtectedResourceFootprint);
		v(protectedFootprintFrequencyPattern);
		v(protectedFootprintTimePattern);
		v(iE_Extensions);

	};
	void clear()
	{
		resourceType.clear();
		intraPRBProtectedResourceFootprint.clear();
		protectedFootprintFrequencyPattern.clear();
		protectedFootprintTimePattern.clear();
		iE_Extensions.clear();

	};
	private:
	resourceType_t	resourceType;
	intraPRBProtectedResourceFootprint_t	intraPRBProtectedResourceFootprint;
	protectedFootprintFrequencyPattern_t	protectedFootprintFrequencyPattern;
	protectedFootprintTimePattern_t	protectedFootprintTimePattern;
	iE_Extensions_t	iE_Extensions;

};
/*
ProtectedResourceList ::= SEQUENCE (SIZE(1.. maxnoofProtectedResourcePatterns)) OF ProtectedResourceList-Item
*/

struct ProtectedResourceList_elm : ProtectedResourceList_Item
{
	static constexpr const char* name() {return "ProtectedResourceList_elm";}
	using parent_t = ProtectedResourceList_Item;

};
struct ProtectedResourceList : asn::sequenceof<ProtectedResourceList_elm>
{
	static constexpr const char* name() {return "ProtectedResourceList";}
	using parent_t = asn::sequenceof<ProtectedResourceList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofProtectedResourcePatterns >>;

};
/*
ProtectedEUTRAResourceIndication-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
} -- Rapporteur: missing extension --
*/

struct ProtectedEUTRAResourceIndication_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ProtectedEUTRAResourceIndication::= SEQUENCE {
	activationSFN							INTEGER (0..1023),
	protectedResourceList					ProtectedResourceList,
	mBSFNControlRegionLength				INTEGER (0..3) OPTIONAL,
	pDCCHRegionLength						INTEGER (1..3) OPTIONAL,
	iE-Extensions							ProtocolExtensionContainer { {ProtectedEUTRAResourceIndication-ExtIEs} }	OPTIONAL,
	...
}
*/

struct ProtectedEUTRAResourceIndication : asn::sequence<5, 0, true, 3>
{
	static constexpr const char* name() {return "ProtectedEUTRAResourceIndication";}
	using parent_t = asn::sequence<5, 0, true, 3>;
	struct activationSFN_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 1023>>;
		static constexpr const char* name() {return "activationSFN_t";}
		using parent_t = asn::integer<>;

	};

	activationSFN_t& ref_activationSFN() {return activationSFN;}
	activationSFN_t const& ref_activationSFN() const {return activationSFN;}
	struct protectedResourceList_t : ProtectedResourceList
	{
		static constexpr const char* name() {return "protectedResourceList_t";}
		using parent_t = ProtectedResourceList;

	};
	protectedResourceList_t& ref_protectedResourceList() {return protectedResourceList;}
	protectedResourceList_t const& ref_protectedResourceList() const {return protectedResourceList;}
	struct mBSFNControlRegionLength_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 3>>;
		static constexpr const char* name() {return "mBSFNControlRegionLength_t";}
		using parent_t = asn::integer<>;
		static constexpr bool optional = true;

	};

	mBSFNControlRegionLength_t& set_mBSFNControlRegionLength() { mBSFNControlRegionLength.setpresent(true); return mBSFNControlRegionLength;}
	mBSFNControlRegionLength_t const* get_mBSFNControlRegionLength() const {return mBSFNControlRegionLength.is_valid() ? &mBSFNControlRegionLength : nullptr;}
	struct pDCCHRegionLength_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<1, 3>>;
		static constexpr const char* name() {return "pDCCHRegionLength_t";}
		using parent_t = asn::integer<>;
		static constexpr bool optional = true;

	};

	pDCCHRegionLength_t& set_pDCCHRegionLength() { pDCCHRegionLength.setpresent(true); return pDCCHRegionLength;}
	pDCCHRegionLength_t const* get_pDCCHRegionLength() const {return pDCCHRegionLength.is_valid() ? &pDCCHRegionLength : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ProtectedEUTRAResourceIndication_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ProtectedEUTRAResourceIndication_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(activationSFN);
		v(protectedResourceList);
		v(mBSFNControlRegionLength);
		v(pDCCHRegionLength);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(activationSFN);
		v(protectedResourceList);
		v(mBSFNControlRegionLength);
		v(pDCCHRegionLength);
		v(iE_Extensions);

	};
	void clear()
	{
		activationSFN.clear();
		protectedResourceList.clear();
		mBSFNControlRegionLength.clear();
		pDCCHRegionLength.clear();
		iE_Extensions.clear();

	};
	private:
	activationSFN_t	activationSFN;
	protectedResourceList_t	protectedResourceList;
	mBSFNControlRegionLength_t	mBSFNControlRegionLength;
	pDCCHRegionLength_t	pDCCHRegionLength;
	iE_Extensions_t	iE_Extensions;

};
/*
Reestablishment-Indication ::= ENUMERATED {
	reestablished,
	...
}
*/

struct Reestablishment_Indication : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "Reestablishment-Indication";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		reestablished
	} index_t;

};

/*
RLC-Status-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct RLC_Status_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
RLC-Status ::= SEQUENCE {
	reestablishment-Indication 	Reestablishment-Indication,
	iE-Extensions				ProtocolExtensionContainer { {RLC-Status-ExtIEs} } OPTIONAL,
	...
}
*/

struct RLC_Status : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "RLC-Status";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct reestablishment_Indication_t : Reestablishment_Indication
	{
		static constexpr const char* name() {return "reestablishment_Indication_t";}
		using parent_t = Reestablishment_Indication;

	};
	reestablishment_Indication_t& ref_reestablishment_Indication() {return reestablishment_Indication;}
	reestablishment_Indication_t const& ref_reestablishment_Indication() const {return reestablishment_Indication;}
	struct iE_Extensions_t : ProtocolExtensionContainer<RLC_Status_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<RLC_Status_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(reestablishment_Indication);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(reestablishment_Indication);
		v(iE_Extensions);

	};
	void clear()
	{
		reestablishment_Indication.clear();
		iE_Extensions.clear();

	};
	private:
	reestablishment_Indication_t	reestablishment_Indication;
	iE_Extensions_t	iE_Extensions;

};
/*
RLCMode ::= ENUMERATED {
	rlc-am,
	rlc-um-bidirectional,
	rlc-um-unidirectional-ul,
	rlc-um-unidirectional-dl,
	...
}
*/

struct RLCMode : asn::enumerated<4, 0, true>
{
	static constexpr const char* name() {return "RLCMode";}
	using parent_t = asn::enumerated<4, 0, true>;
	typedef enum {
		rlc_am
		,rlc_um_bidirectional
		,rlc_um_unidirectional_ul
		,rlc_um_unidirectional_dl
	} index_t;

};

/*
RRC-Config-Ind ::= ENUMERATED {
	full-config,
	delta-config,
	...
}
*/

struct RRC_Config_Ind : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "RRC-Config-Ind";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		full_config
		,delta_config
	} index_t;

};

/*
RRC-Context ::= OCTET STRING
*/

struct RRC_Context : asn::ostring<>
{
	static constexpr const char* name() {return "RRC-Context";}
	using parent_t = asn::ostring<>;

};

/*
RRCConnReestabIndicator ::= ENUMERATED {
	reconfigurationFailure, handoverFailure, otherFailure, ...
}
*/

struct RRCConnReestabIndicator : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "RRCConnReestabIndicator";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		reconfigurationFailure
		,handoverFailure
		,otherFailure
	} index_t;

};

/*
RRCConnSetupIndicator::= ENUMERATED {
	rrcConnSetup,
	...
}
*/

struct RRCConnSetupIndicator : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "RRCConnSetupIndicator";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		rrcConnSetup
	} index_t;

};

/*
RRCContainer ::= OCTET STRING
*/

struct RRCContainer : asn::ostring<>
{
	static constexpr const char* name() {return "RRCContainer";}
	using parent_t = asn::ostring<>;

};

/*
RSRPMeasurementResult-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct RSRPMeasurementResult_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
RSRPMeasurementResult ::= SEQUENCE (SIZE(1..maxCellReport)) OF
	SEQUENCE {
		rSRPCellID						ECGI,
		rSRPMeasured					INTEGER (0..97, ...),
		iE-Extensions					ProtocolExtensionContainer { {RSRPMeasurementResult-ExtIEs} } OPTIONAL,
		...
	}
*/

struct RSRPMeasurementResult_elm : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "RSRPMeasurementResult_elm";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct rSRPCellID_t : ECGI
	{
		static constexpr const char* name() {return "rSRPCellID_t";}
		using parent_t = ECGI;

	};
	rSRPCellID_t& ref_rSRPCellID() {return rSRPCellID;}
	rSRPCellID_t const& ref_rSRPCellID() const {return rSRPCellID;}
	struct rSRPMeasured_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 97>>;
		static constexpr const char* name() {return "rSRPMeasured_t";}
		using parent_t = asn::integer<>;

	};

	rSRPMeasured_t& ref_rSRPMeasured() {return rSRPMeasured;}
	rSRPMeasured_t const& ref_rSRPMeasured() const {return rSRPMeasured;}
	struct iE_Extensions_t : ProtocolExtensionContainer<RSRPMeasurementResult_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<RSRPMeasurementResult_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(rSRPCellID);
		v(rSRPMeasured);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(rSRPCellID);
		v(rSRPMeasured);
		v(iE_Extensions);

	};
	void clear()
	{
		rSRPCellID.clear();
		rSRPMeasured.clear();
		iE_Extensions.clear();

	};
	private:
	rSRPCellID_t	rSRPCellID;
	rSRPMeasured_t	rSRPMeasured;
	iE_Extensions_t	iE_Extensions;

};
struct RSRPMeasurementResult : asn::sequenceof<RSRPMeasurementResult_elm>
{
	static constexpr const char* name() {return "RSRPMeasurementResult";}
	using parent_t = asn::sequenceof<RSRPMeasurementResult_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCellReport >>;

};
/*
RSRPMRList-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-UEID	CRITICALITY ignore	EXTENSION UEID		PRESENCE optional},
	...
}
*/

struct RSRPMRList_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_UEID() { set(id_UEID); type=1;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_UEID)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_UEID);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_UEID() { set(ignore); type=1;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		UEID& select_id_UEID() { return set<UEID>(1); }
		UEID const* get_id_UEID() const { return get<UEID>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<UEID>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<UEID>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_UEID()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<UEID>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(UEID)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_UEID() { set(optional); type=1;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
RSRPMRList ::= SEQUENCE (SIZE(1..maxUEReport)) OF
	SEQUENCE {
		rSRPMeasurementResult			RSRPMeasurementResult,
		iE-Extensions					ProtocolExtensionContainer { {RSRPMRList-ExtIEs} } OPTIONAL,
		...
	}
*/

struct RSRPMRList_elm : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "RSRPMRList_elm";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct rSRPMeasurementResult_t : RSRPMeasurementResult
	{
		static constexpr const char* name() {return "rSRPMeasurementResult_t";}
		using parent_t = RSRPMeasurementResult;

	};
	rSRPMeasurementResult_t& ref_rSRPMeasurementResult() {return rSRPMeasurementResult;}
	rSRPMeasurementResult_t const& ref_rSRPMeasurementResult() const {return rSRPMeasurementResult;}
	struct iE_Extensions_t : ProtocolExtensionContainer<RSRPMRList_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<RSRPMRList_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(rSRPMeasurementResult);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(rSRPMeasurementResult);
		v(iE_Extensions);

	};
	void clear()
	{
		rSRPMeasurementResult.clear();
		iE_Extensions.clear();

	};
	private:
	rSRPMeasurementResult_t	rSRPMeasurementResult;
	iE_Extensions_t	iE_Extensions;

};
struct RSRPMRList : asn::sequenceof<RSRPMRList_elm>
{
	static constexpr const char* name() {return "RSRPMRList";}
	using parent_t = asn::sequenceof<RSRPMRList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxUEReport >>;

};
/*
UL-GBR-PRB-usage::= INTEGER (0..100)
*/

struct UL_GBR_PRB_usage : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 100>>;
	static constexpr const char* name() {return "UL-GBR-PRB-usage";}
	using parent_t = asn::integer<>;

};

/*
UL-non-GBR-PRB-usage::= INTEGER (0..100)
*/

struct UL_non_GBR_PRB_usage : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 100>>;
	static constexpr const char* name() {return "UL-non-GBR-PRB-usage";}
	using parent_t = asn::integer<>;

};

/*
UL-Total-PRB-usage::= INTEGER (0..100)
*/

struct UL_Total_PRB_usage : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 100>>;
	static constexpr const char* name() {return "UL-Total-PRB-usage";}
	using parent_t = asn::integer<>;

};

/*
UL-scheduling-PDCCH-CCE-usage::= INTEGER (0..100)
*/

struct UL_scheduling_PDCCH_CCE_usage : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 100>>;
	static constexpr const char* name() {return "UL-scheduling-PDCCH-CCE-usage";}
	using parent_t = asn::integer<>;

};

/*
RadioResourceStatus-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ID id-DL-scheduling-PDCCH-CCE-usage		CRITICALITY ignore	EXTENSION DL-scheduling-PDCCH-CCE-usage		PRESENCE optional}|

	{ID id-UL-scheduling-PDCCH-CCE-usage		CRITICALITY ignore	EXTENSION UL-scheduling-PDCCH-CCE-usage		PRESENCE optional},
	...
}
*/

struct RadioResourceStatus_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_DL_scheduling_PDCCH_CCE_usage() { set(id_DL_scheduling_PDCCH_CCE_usage); type=1;}
		void select_id_UL_scheduling_PDCCH_CCE_usage() { set(id_UL_scheduling_PDCCH_CCE_usage); type=2;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_DL_scheduling_PDCCH_CCE_usage)) { type = 1; return true; }
			else if(equal(id_UL_scheduling_PDCCH_CCE_usage)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_DL_scheduling_PDCCH_CCE_usage);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_UL_scheduling_PDCCH_CCE_usage);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_DL_scheduling_PDCCH_CCE_usage() { set(ignore); type=1;}
		void select_id_UL_scheduling_PDCCH_CCE_usage() { set(ignore); type=2;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		DL_scheduling_PDCCH_CCE_usage& select_id_DL_scheduling_PDCCH_CCE_usage() { return set<DL_scheduling_PDCCH_CCE_usage>(1); }
		DL_scheduling_PDCCH_CCE_usage const* get_id_DL_scheduling_PDCCH_CCE_usage() const { return get<DL_scheduling_PDCCH_CCE_usage>(1); }
		UL_scheduling_PDCCH_CCE_usage& select_id_UL_scheduling_PDCCH_CCE_usage() { return set<UL_scheduling_PDCCH_CCE_usage>(2); }
		UL_scheduling_PDCCH_CCE_usage const* get_id_UL_scheduling_PDCCH_CCE_usage() const { return get<UL_scheduling_PDCCH_CCE_usage>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<DL_scheduling_PDCCH_CCE_usage>(); break;
			case 2: var.destroy<UL_scheduling_PDCCH_CCE_usage>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<DL_scheduling_PDCCH_CCE_usage>(1);
			v.template operator()<UL_scheduling_PDCCH_CCE_usage>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_DL_scheduling_PDCCH_CCE_usage()); return true;
			case 2: v(select_id_UL_scheduling_PDCCH_CCE_usage()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<DL_scheduling_PDCCH_CCE_usage>()); return true;
			case 2: v(var.as<UL_scheduling_PDCCH_CCE_usage>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(DL_scheduling_PDCCH_CCE_usage)];
			char dummy2[sizeof(UL_scheduling_PDCCH_CCE_usage)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_DL_scheduling_PDCCH_CCE_usage() { set(optional); type=1;}
		void select_id_UL_scheduling_PDCCH_CCE_usage() { set(optional); type=2;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
RadioResourceStatus	::= SEQUENCE {
	dL-GBR-PRB-usage							DL-GBR-PRB-usage,
	uL-GBR-PRB-usage							UL-GBR-PRB-usage,
	dL-non-GBR-PRB-usage						DL-non-GBR-PRB-usage,
	uL-non-GBR-PRB-usage						UL-non-GBR-PRB-usage,
	dL-Total-PRB-usage							DL-Total-PRB-usage,
	uL-Total-PRB-usage							UL-Total-PRB-usage,
	iE-Extensions								ProtocolExtensionContainer { {RadioResourceStatus-ExtIEs} } OPTIONAL,
	...
}
*/

struct RadioResourceStatus : asn::sequence<7, 0, true, 1>
{
	static constexpr const char* name() {return "RadioResourceStatus";}
	using parent_t = asn::sequence<7, 0, true, 1>;
	struct dL_GBR_PRB_usage_t : DL_GBR_PRB_usage
	{
		static constexpr const char* name() {return "dL_GBR_PRB_usage_t";}
		using parent_t = DL_GBR_PRB_usage;

	};
	dL_GBR_PRB_usage_t& ref_dL_GBR_PRB_usage() {return dL_GBR_PRB_usage;}
	dL_GBR_PRB_usage_t const& ref_dL_GBR_PRB_usage() const {return dL_GBR_PRB_usage;}
	struct uL_GBR_PRB_usage_t : UL_GBR_PRB_usage
	{
		static constexpr const char* name() {return "uL_GBR_PRB_usage_t";}
		using parent_t = UL_GBR_PRB_usage;

	};
	uL_GBR_PRB_usage_t& ref_uL_GBR_PRB_usage() {return uL_GBR_PRB_usage;}
	uL_GBR_PRB_usage_t const& ref_uL_GBR_PRB_usage() const {return uL_GBR_PRB_usage;}
	struct dL_non_GBR_PRB_usage_t : DL_non_GBR_PRB_usage
	{
		static constexpr const char* name() {return "dL_non_GBR_PRB_usage_t";}
		using parent_t = DL_non_GBR_PRB_usage;

	};
	dL_non_GBR_PRB_usage_t& ref_dL_non_GBR_PRB_usage() {return dL_non_GBR_PRB_usage;}
	dL_non_GBR_PRB_usage_t const& ref_dL_non_GBR_PRB_usage() const {return dL_non_GBR_PRB_usage;}
	struct uL_non_GBR_PRB_usage_t : UL_non_GBR_PRB_usage
	{
		static constexpr const char* name() {return "uL_non_GBR_PRB_usage_t";}
		using parent_t = UL_non_GBR_PRB_usage;

	};
	uL_non_GBR_PRB_usage_t& ref_uL_non_GBR_PRB_usage() {return uL_non_GBR_PRB_usage;}
	uL_non_GBR_PRB_usage_t const& ref_uL_non_GBR_PRB_usage() const {return uL_non_GBR_PRB_usage;}
	struct dL_Total_PRB_usage_t : DL_Total_PRB_usage
	{
		static constexpr const char* name() {return "dL_Total_PRB_usage_t";}
		using parent_t = DL_Total_PRB_usage;

	};
	dL_Total_PRB_usage_t& ref_dL_Total_PRB_usage() {return dL_Total_PRB_usage;}
	dL_Total_PRB_usage_t const& ref_dL_Total_PRB_usage() const {return dL_Total_PRB_usage;}
	struct uL_Total_PRB_usage_t : UL_Total_PRB_usage
	{
		static constexpr const char* name() {return "uL_Total_PRB_usage_t";}
		using parent_t = UL_Total_PRB_usage;

	};
	uL_Total_PRB_usage_t& ref_uL_Total_PRB_usage() {return uL_Total_PRB_usage;}
	uL_Total_PRB_usage_t const& ref_uL_Total_PRB_usage() const {return uL_Total_PRB_usage;}
	struct iE_Extensions_t : ProtocolExtensionContainer<RadioResourceStatus_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<RadioResourceStatus_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(dL_GBR_PRB_usage);
		v(uL_GBR_PRB_usage);
		v(dL_non_GBR_PRB_usage);
		v(uL_non_GBR_PRB_usage);
		v(dL_Total_PRB_usage);
		v(uL_Total_PRB_usage);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(dL_GBR_PRB_usage);
		v(uL_GBR_PRB_usage);
		v(dL_non_GBR_PRB_usage);
		v(uL_non_GBR_PRB_usage);
		v(dL_Total_PRB_usage);
		v(uL_Total_PRB_usage);
		v(iE_Extensions);

	};
	void clear()
	{
		dL_GBR_PRB_usage.clear();
		uL_GBR_PRB_usage.clear();
		dL_non_GBR_PRB_usage.clear();
		uL_non_GBR_PRB_usage.clear();
		dL_Total_PRB_usage.clear();
		uL_Total_PRB_usage.clear();
		iE_Extensions.clear();

	};
	private:
	dL_GBR_PRB_usage_t	dL_GBR_PRB_usage;
	uL_GBR_PRB_usage_t	uL_GBR_PRB_usage;
	dL_non_GBR_PRB_usage_t	dL_non_GBR_PRB_usage;
	uL_non_GBR_PRB_usage_t	uL_non_GBR_PRB_usage;
	dL_Total_PRB_usage_t	dL_Total_PRB_usage;
	uL_Total_PRB_usage_t	uL_Total_PRB_usage;
	iE_Extensions_t	iE_Extensions;

};
/*
ReceiveStatusOfULPDCPSDUsExtended ::= BIT STRING (SIZE(1..16384))
*/

struct ReceiveStatusOfULPDCPSDUsExtended : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::span<1, 16384>>;
	static constexpr const char* name() {return "ReceiveStatusOfULPDCPSDUsExtended";}
	using parent_t = asn::bstring<>;

};

/*
ReceiveStatusOfULPDCPSDUsPDCP-SNlength18 ::= BIT STRING (SIZE(1..131072))
*/

struct ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::span<1, 131072>>;
	static constexpr const char* name() {return "ReceiveStatusOfULPDCPSDUsPDCP-SNlength18";}
	using parent_t = asn::bstring<>;

};

/*
ReceiveStatusofULPDCPSDUs ::= BIT STRING (SIZE(4096))
*/

struct ReceiveStatusofULPDCPSDUs : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<4096>>;
	static constexpr const char* name() {return "ReceiveStatusofULPDCPSDUs";}
	using parent_t = asn::bstring<>;

};

/*
Registration-Request	::= ENUMERATED {
	start,
	stop,
	...,
	partial-stop,
	add
}
*/

struct Registration_Request : asn::enumerated<4, 2, true>
{
	static constexpr const char* name() {return "Registration-Request";}
	using parent_t = asn::enumerated<4, 2, true>;
	typedef enum {
		start
		,stop
		,partial_stop
		,add
	} index_t;

};

/*
RelativeNarrowbandTxPower-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-enhancedRNTP	CRITICALITY ignore	EXTENSION EnhancedRNTP		PRESENCE optional },
	...
}
*/

struct RelativeNarrowbandTxPower_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_enhancedRNTP() { set(id_enhancedRNTP); type=1;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_enhancedRNTP)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_enhancedRNTP);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_enhancedRNTP() { set(ignore); type=1;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		EnhancedRNTP& select_id_enhancedRNTP() { return set<EnhancedRNTP>(1); }
		EnhancedRNTP const* get_id_enhancedRNTP() const { return get<EnhancedRNTP>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<EnhancedRNTP>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<EnhancedRNTP>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_enhancedRNTP()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<EnhancedRNTP>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(EnhancedRNTP)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_enhancedRNTP() { set(optional); type=1;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
RelativeNarrowbandTxPower ::= SEQUENCE {

	rNTP-PerPRB							BIT STRING (SIZE(6..110, ...)),
	rNTP-Threshold						RNTP-Threshold,
	numberOfCellSpecificAntennaPorts	ENUMERATED {one, two, four, ...},
	p-B									INTEGER (0..3,...),
	pDCCH-InterferenceImpact			INTEGER (0..4,...),
	iE-Extensions						ProtocolExtensionContainer { {RelativeNarrowbandTxPower-ExtIEs} } OPTIONAL,
	...
}
*/

struct RelativeNarrowbandTxPower : asn::sequence<6, 0, true, 1>
{
	static constexpr const char* name() {return "RelativeNarrowbandTxPower";}
	using parent_t = asn::sequence<6, 0, true, 1>;
	struct rNTP_PerPRB_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::span<6, 110>>;
		static constexpr const char* name() {return "rNTP_PerPRB_t";}
		using parent_t = asn::bstring<>;

	};

	rNTP_PerPRB_t& ref_rNTP_PerPRB() {return rNTP_PerPRB;}
	rNTP_PerPRB_t const& ref_rNTP_PerPRB() const {return rNTP_PerPRB;}
	struct rNTP_Threshold_t : RNTP_Threshold
	{
		static constexpr const char* name() {return "rNTP_Threshold_t";}
		using parent_t = RNTP_Threshold;

	};
	rNTP_Threshold_t& ref_rNTP_Threshold() {return rNTP_Threshold;}
	rNTP_Threshold_t const& ref_rNTP_Threshold() const {return rNTP_Threshold;}
	struct numberOfCellSpecificAntennaPorts_t : asn::enumerated<3, 0, true>
	{
		static constexpr const char* name() {return "numberOfCellSpecificAntennaPorts_t";}
		using parent_t = asn::enumerated<3, 0, true>;
		typedef enum {
			one
			,two
			,four
		} index_t;

	};

	numberOfCellSpecificAntennaPorts_t& ref_numberOfCellSpecificAntennaPorts() {return numberOfCellSpecificAntennaPorts;}
	numberOfCellSpecificAntennaPorts_t const& ref_numberOfCellSpecificAntennaPorts() const {return numberOfCellSpecificAntennaPorts;}
	struct p_B_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 3>>;
		static constexpr const char* name() {return "p_B_t";}
		using parent_t = asn::integer<>;

	};

	p_B_t& ref_p_B() {return p_B;}
	p_B_t const& ref_p_B() const {return p_B;}
	struct pDCCH_InterferenceImpact_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 4>>;
		static constexpr const char* name() {return "pDCCH_InterferenceImpact_t";}
		using parent_t = asn::integer<>;

	};

	pDCCH_InterferenceImpact_t& ref_pDCCH_InterferenceImpact() {return pDCCH_InterferenceImpact;}
	pDCCH_InterferenceImpact_t const& ref_pDCCH_InterferenceImpact() const {return pDCCH_InterferenceImpact;}
	struct iE_Extensions_t : ProtocolExtensionContainer<RelativeNarrowbandTxPower_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<RelativeNarrowbandTxPower_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(rNTP_PerPRB);
		v(rNTP_Threshold);
		v(numberOfCellSpecificAntennaPorts);
		v(p_B);
		v(pDCCH_InterferenceImpact);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(rNTP_PerPRB);
		v(rNTP_Threshold);
		v(numberOfCellSpecificAntennaPorts);
		v(p_B);
		v(pDCCH_InterferenceImpact);
		v(iE_Extensions);

	};
	void clear()
	{
		rNTP_PerPRB.clear();
		rNTP_Threshold.clear();
		numberOfCellSpecificAntennaPorts.clear();
		p_B.clear();
		pDCCH_InterferenceImpact.clear();
		iE_Extensions.clear();

	};
	private:
	rNTP_PerPRB_t	rNTP_PerPRB;
	rNTP_Threshold_t	rNTP_Threshold;
	numberOfCellSpecificAntennaPorts_t	numberOfCellSpecificAntennaPorts;
	p_B_t	p_B;
	pDCCH_InterferenceImpact_t	pDCCH_InterferenceImpact;
	iE_Extensions_t	iE_Extensions;

};
/*
ReportCharacteristics	::= BIT STRING (SIZE (32))
*/

struct ReportCharacteristics : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<32>>;
	static constexpr const char* name() {return "ReportCharacteristics";}
	using parent_t = asn::bstring<>;

};

/*
ReportingPeriodicityCSIR ::= ENUMERATED {
	ms5,
	ms10,
	ms20,
	ms40,
	ms80,
...
}
*/

struct ReportingPeriodicityCSIR : asn::enumerated<5, 0, true>
{
	static constexpr const char* name() {return "ReportingPeriodicityCSIR";}
	using parent_t = asn::enumerated<5, 0, true>;
	typedef enum {
		ms5
		,ms10
		,ms20
		,ms40
		,ms80
	} index_t;

};

/*
ReportingPeriodicityRSRPMR ::= ENUMERATED {
	one-hundred-20-ms,
	two-hundred-40-ms,
	four-hundred-80-ms,
	six-hundred-40-ms,
...
}
*/

struct ReportingPeriodicityRSRPMR : asn::enumerated<4, 0, true>
{
	static constexpr const char* name() {return "ReportingPeriodicityRSRPMR";}
	using parent_t = asn::enumerated<4, 0, true>;
	typedef enum {
		one_hundred_20_ms
		,two_hundred_40_ms
		,four_hundred_80_ms
		,six_hundred_40_ms
	} index_t;

};

/*
ResumeID	::= CHOICE {
	non-truncated	BIT STRING(SIZE(40)),
	truncated		BIT STRING(SIZE(24)),
	...
}
*/

struct ResumeID : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "ResumeID";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~ResumeID() {clear();}
	struct non_truncated_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<40>>;
		static constexpr const char* name() {return "non_truncated_t";}
		using parent_t = asn::bstring<>;

	};

	struct truncated_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<24>>;
		static constexpr const char* name() {return "truncated_t";}
		using parent_t = asn::bstring<>;

	};

	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<non_truncated_t>(); break;
		case 2: var.destroy<truncated_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<non_truncated_t>());
		case 2: set_index(2); return v(var.build<truncated_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<non_truncated_t>());
		case 2: return v(var.as<truncated_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<non_truncated_t>(1);
		v.template operator()<truncated_t>(2);

	}
	non_truncated_t& select_non_truncated() { if(get_index() != 1) { clear(); set_index(1); return var.build<non_truncated_t>();} return var.as<non_truncated_t>();}
	non_truncated_t const* get_non_truncated() const { if(get_index() == 1) { return &var.as<non_truncated_t>();} return nullptr; }
	truncated_t& select_truncated() { if(get_index() != 2) { clear(); set_index(2); return var.build<truncated_t>();} return var.as<truncated_t>();}
	truncated_t const* get_truncated() const { if(get_index() == 2) { return &var.as<truncated_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(non_truncated_t)];
		char dummy2[sizeof(truncated_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
S1TNLLoadIndicator-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct S1TNLLoadIndicator_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
S1TNLLoadIndicator ::= SEQUENCE {
	dLS1TNLLoadIndicator			LoadIndicator,
	uLS1TNLLoadIndicator			LoadIndicator,
	iE-Extensions					ProtocolExtensionContainer { {S1TNLLoadIndicator-ExtIEs} } OPTIONAL,
	...
}
*/

struct S1TNLLoadIndicator : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "S1TNLLoadIndicator";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct dLS1TNLLoadIndicator_t : LoadIndicator
	{
		static constexpr const char* name() {return "dLS1TNLLoadIndicator_t";}
		using parent_t = LoadIndicator;

	};
	dLS1TNLLoadIndicator_t& ref_dLS1TNLLoadIndicator() {return dLS1TNLLoadIndicator;}
	dLS1TNLLoadIndicator_t const& ref_dLS1TNLLoadIndicator() const {return dLS1TNLLoadIndicator;}
	struct uLS1TNLLoadIndicator_t : LoadIndicator
	{
		static constexpr const char* name() {return "uLS1TNLLoadIndicator_t";}
		using parent_t = LoadIndicator;

	};
	uLS1TNLLoadIndicator_t& ref_uLS1TNLLoadIndicator() {return uLS1TNLLoadIndicator;}
	uLS1TNLLoadIndicator_t const& ref_uLS1TNLLoadIndicator() const {return uLS1TNLLoadIndicator;}
	struct iE_Extensions_t : ProtocolExtensionContainer<S1TNLLoadIndicator_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<S1TNLLoadIndicator_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(dLS1TNLLoadIndicator);
		v(uLS1TNLLoadIndicator);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(dLS1TNLLoadIndicator);
		v(uLS1TNLLoadIndicator);
		v(iE_Extensions);

	};
	void clear()
	{
		dLS1TNLLoadIndicator.clear();
		uLS1TNLLoadIndicator.clear();
		iE_Extensions.clear();

	};
	private:
	dLS1TNLLoadIndicator_t	dLS1TNLLoadIndicator;
	uLS1TNLLoadIndicator_t	uLS1TNLLoadIndicator;
	iE_Extensions_t	iE_Extensions;

};
/*
SCGChangeIndication ::= ENUMERATED {pDCPCountWrapAround, pSCellChange, other, ...}
*/

struct SCGChangeIndication : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "SCGChangeIndication";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		pDCPCountWrapAround
		,pSCellChange
		,other
	} index_t;

};

/*
SCGConfigurationQuery ::= ENUMERATED {true,...}
*/

struct SCGConfigurationQuery : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "SCGConfigurationQuery";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		True
	} index_t;

};

/*
SGNB-Addition-Trigger-Ind	 ::= ENUMERATED {
	sn-change,
	inter-eNB-HO,
	intra-eNB-HO,
	...
}
*/

struct SGNB_Addition_Trigger_Ind : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "SGNB-Addition-Trigger-Ind";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		sn_change
		,inter_eNB_HO
		,intra_eNB_HO
	} index_t;

};

/*
SIPTOBearerDeactivationIndication ::= ENUMERATED {
	true,
	...
}
*/

struct SIPTOBearerDeactivationIndication : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "SIPTOBearerDeactivationIndication";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		True
	} index_t;

};

/*
SRBType ::= ENUMERATED {srb1, srb2, ...}
*/

struct SRBType : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "SRBType";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		srb1
		,srb2
	} index_t;

};

/*
SRVCCOperationPossible ::= ENUMERATED {
	possible,
	...
}
*/

struct SRVCCOperationPossible : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "SRVCCOperationPossible";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		possible
	} index_t;

};

/*
ScheduledCommunicationTime-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ScheduledCommunicationTime_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ScheduledCommunicationTime ::= SEQUENCE {
	dayofWeek				BIT STRING (SIZE(7))									OPTIONAL,
	timeofDayStart			INTEGER (0..86399, ...) 								OPTIONAL,
	timeofDayEnd				INTEGER (0..86399, ...) 								OPTIONAL,
	iE-Extensions			ProtocolExtensionContainer { { ScheduledCommunicationTime-ExtIEs}}	OPTIONAL,
	...
}
*/

struct ScheduledCommunicationTime : asn::sequence<4, 0, true, 4>
{
	static constexpr const char* name() {return "ScheduledCommunicationTime";}
	using parent_t = asn::sequence<4, 0, true, 4>;
	struct dayofWeek_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<7>>;
		static constexpr const char* name() {return "dayofWeek_t";}
		using parent_t = asn::bstring<>;
		static constexpr bool optional = true;

	};

	dayofWeek_t& set_dayofWeek() { dayofWeek.setpresent(true); return dayofWeek;}
	dayofWeek_t const* get_dayofWeek() const {return dayofWeek.is_valid() ? &dayofWeek : nullptr;}
	struct timeofDayStart_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 86399>>;
		static constexpr const char* name() {return "timeofDayStart_t";}
		using parent_t = asn::integer<>;
		static constexpr bool optional = true;

	};

	timeofDayStart_t& set_timeofDayStart() { timeofDayStart.setpresent(true); return timeofDayStart;}
	timeofDayStart_t const* get_timeofDayStart() const {return timeofDayStart.is_valid() ? &timeofDayStart : nullptr;}
	struct timeofDayEnd_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<0, 86399>>;
		static constexpr const char* name() {return "timeofDayEnd_t";}
		using parent_t = asn::integer<>;
		static constexpr bool optional = true;

	};

	timeofDayEnd_t& set_timeofDayEnd() { timeofDayEnd.setpresent(true); return timeofDayEnd;}
	timeofDayEnd_t const* get_timeofDayEnd() const {return timeofDayEnd.is_valid() ? &timeofDayEnd : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ScheduledCommunicationTime_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ScheduledCommunicationTime_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(dayofWeek);
		v(timeofDayStart);
		v(timeofDayEnd);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(dayofWeek);
		v(timeofDayStart);
		v(timeofDayEnd);
		v(iE_Extensions);

	};
	void clear()
	{
		dayofWeek.clear();
		timeofDayStart.clear();
		timeofDayEnd.clear();
		iE_Extensions.clear();

	};
	private:
	dayofWeek_t	dayofWeek;
	timeofDayStart_t	timeofDayStart;
	timeofDayEnd_t	timeofDayEnd;
	iE_Extensions_t	iE_Extensions;

};
/*
SeNBSecurityKey ::= BIT STRING (SIZE(256))
*/

struct SeNBSecurityKey : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<256>>;
	static constexpr const char* name() {return "SeNBSecurityKey";}
	using parent_t = asn::bstring<>;

};

/*
SeNBtoMeNBContainer ::= OCTET STRING
*/

struct SeNBtoMeNBContainer : asn::ostring<>
{
	static constexpr const char* name() {return "SeNBtoMeNBContainer";}
	using parent_t = asn::ostring<>;

};

/*
SecondaryRATUsageReport-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct SecondaryRATUsageReport_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
SecondaryRATUsageReport-Item ::= SEQUENCE {
	e-RAB-ID						E-RAB-ID,
	secondaryRATType				ENUMERATED {nr, ...},
	e-RABUsageReportList			E-RABUsageReportList,
	iE-Extensions				ProtocolExtensionContainer { {SecondaryRATUsageReport-Item-ExtIEs} } OPTIONAL,
...
}
*/

struct SecondaryRATUsageReport_Item : asn::sequence<4, 0, true, 1>
{
	static constexpr const char* name() {return "SecondaryRATUsageReport-Item";}
	using parent_t = asn::sequence<4, 0, true, 1>;
	struct e_RAB_ID_t : E_RAB_ID
	{
		static constexpr const char* name() {return "e_RAB_ID_t";}
		using parent_t = E_RAB_ID;

	};
	e_RAB_ID_t& ref_e_RAB_ID() {return e_RAB_ID;}
	e_RAB_ID_t const& ref_e_RAB_ID() const {return e_RAB_ID;}
	struct secondaryRATType_t : asn::enumerated<1, 0, true>
	{
		static constexpr const char* name() {return "secondaryRATType_t";}
		using parent_t = asn::enumerated<1, 0, true>;
		typedef enum {
			nr
		} index_t;

	};

	secondaryRATType_t& ref_secondaryRATType() {return secondaryRATType;}
	secondaryRATType_t const& ref_secondaryRATType() const {return secondaryRATType;}
	struct e_RABUsageReportList_t : E_RABUsageReportList
	{
		static constexpr const char* name() {return "e_RABUsageReportList_t";}
		using parent_t = E_RABUsageReportList;

	};
	e_RABUsageReportList_t& ref_e_RABUsageReportList() {return e_RABUsageReportList;}
	e_RABUsageReportList_t const& ref_e_RABUsageReportList() const {return e_RABUsageReportList;}
	struct iE_Extensions_t : ProtocolExtensionContainer<SecondaryRATUsageReport_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<SecondaryRATUsageReport_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(e_RAB_ID);
		v(secondaryRATType);
		v(e_RABUsageReportList);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(e_RAB_ID);
		v(secondaryRATType);
		v(e_RABUsageReportList);
		v(iE_Extensions);

	};
	void clear()
	{
		e_RAB_ID.clear();
		secondaryRATType.clear();
		e_RABUsageReportList.clear();
		iE_Extensions.clear();

	};
	private:
	e_RAB_ID_t	e_RAB_ID;
	secondaryRATType_t	secondaryRATType;
	e_RABUsageReportList_t	e_RABUsageReportList;
	iE_Extensions_t	iE_Extensions;

};
/*
SecondaryRATUsageReport-ItemIEs	X2AP-PROTOCOL-IES ::= {
	{ ID id-SecondaryRATUsageReport-Item		CRITICALITY reject	TYPE SecondaryRATUsageReport-Item		PRESENCE mandatory},
	...
}
*/

struct SecondaryRATUsageReport_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_SecondaryRATUsageReport_Item() { set(id_SecondaryRATUsageReport_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_SecondaryRATUsageReport_Item)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_SecondaryRATUsageReport_Item);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_SecondaryRATUsageReport_Item() { set(reject); type=1;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		SecondaryRATUsageReport_Item& select_id_SecondaryRATUsageReport_Item() { return set<SecondaryRATUsageReport_Item>(1); }
		SecondaryRATUsageReport_Item const* get_id_SecondaryRATUsageReport_Item() const { return get<SecondaryRATUsageReport_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<SecondaryRATUsageReport_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<SecondaryRATUsageReport_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_SecondaryRATUsageReport_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<SecondaryRATUsageReport_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(SecondaryRATUsageReport_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_SecondaryRATUsageReport_Item() { set(mandatory); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
SecondaryRATUsageReportList ::= SEQUENCE (SIZE(1..maxnoofBearers)) OF ProtocolIE-Single-Container {{SecondaryRATUsageReport-ItemIEs}}
*/

struct SecondaryRATUsageReportList_elm : ProtocolIE_Single_Container<SecondaryRATUsageReport_ItemIEs>
{
	static constexpr const char* name() {return "SecondaryRATUsageReportList_elm";}
	using parent_t = ProtocolIE_Single_Container<SecondaryRATUsageReport_ItemIEs>;

};
struct SecondaryRATUsageReportList : asn::sequenceof<SecondaryRATUsageReportList_elm>
{
	static constexpr const char* name() {return "SecondaryRATUsageReportList";}
	using parent_t = asn::sequenceof<SecondaryRATUsageReportList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofBearers >>;

};
/*
ServedCell-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ServedCell_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ServedCell-Information-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-Number-of-Antennaports				CRITICALITY ignore	EXTENSION Number-of-Antennaports					PRESENCE optional}|
	{ ID id-PRACH-Configuration					CRITICALITY ignore	EXTENSION PRACH-Configuration						PRESENCE optional}|
	{ ID id-MBSFN-Subframe-Info					CRITICALITY ignore	EXTENSION MBSFN-Subframe-Infolist				PRESENCE optional}|
	{ ID id-CSG-Id								CRITICALITY ignore	EXTENSION CSG-Id									PRESENCE optional}|
	{ ID id-MBMS-Service-Area-List				CRITICALITY ignore	EXTENSION MBMS-Service-Area-Identity-List		PRESENCE optional}|
	{ ID id-MultibandInfoList					CRITICALITY ignore	EXTENSION MultibandInfoList							PRESENCE optional}|
	{ ID id-FreqBandIndicatorPriority			CRITICALITY ignore	EXTENSION FreqBandIndicatorPriority				PRESENCE optional}|
	{ ID id-BandwidthReducedSI					CRITICALITY ignore	EXTENSION BandwidthReducedSI						PRESENCE optional}|
	{ ID id-ProtectedEUTRAResourceIndication	CRITICALITY ignore	EXTENSION ProtectedEUTRAResourceIndication	PRESENCE optional},
	...
}
*/

struct ServedCell_Information_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 10; }
		void clear() {type = 0;}
		void select_id_Number_of_Antennaports() { set(id_Number_of_Antennaports); type=1;}
		void select_id_PRACH_Configuration() { set(id_PRACH_Configuration); type=2;}
		void select_id_MBSFN_Subframe_Info() { set(id_MBSFN_Subframe_Info); type=3;}
		void select_id_CSG_Id() { set(id_CSG_Id); type=4;}
		void select_id_MBMS_Service_Area_List() { set(id_MBMS_Service_Area_List); type=5;}
		void select_id_MultibandInfoList() { set(id_MultibandInfoList); type=6;}
		void select_id_FreqBandIndicatorPriority() { set(id_FreqBandIndicatorPriority); type=7;}
		void select_id_BandwidthReducedSI() { set(id_BandwidthReducedSI); type=8;}
		void select_id_ProtectedEUTRAResourceIndication() { set(id_ProtectedEUTRAResourceIndication); type=9;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_Number_of_Antennaports)) { type = 1; return true; }
			else if(equal(id_PRACH_Configuration)) { type = 2; return true; }
			else if(equal(id_MBSFN_Subframe_Info)) { type = 3; return true; }
			else if(equal(id_CSG_Id)) { type = 4; return true; }
			else if(equal(id_MBMS_Service_Area_List)) { type = 5; return true; }
			else if(equal(id_MultibandInfoList)) { type = 6; return true; }
			else if(equal(id_FreqBandIndicatorPriority)) { type = 7; return true; }
			else if(equal(id_BandwidthReducedSI)) { type = 8; return true; }
			else if(equal(id_ProtectedEUTRAResourceIndication)) { type = 9; return true; }
			else { type = 10; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_Number_of_Antennaports);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_PRACH_Configuration);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_MBSFN_Subframe_Info);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_CSG_Id);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(id_MBMS_Service_Area_List);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(id_MultibandInfoList);} return false;
			case 7: type = 7; if(v(ref_nested())) { return equal(id_FreqBandIndicatorPriority);} return false;
			case 8: type = 8; if(v(ref_nested())) { return equal(id_BandwidthReducedSI);} return false;
			case 9: type = 9; if(v(ref_nested())) { return equal(id_ProtectedEUTRAResourceIndication);} return false;
			case 10: type = 10; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 10; }
		void clear() {type = 0;}
		void select_id_Number_of_Antennaports() { set(ignore); type=1;}
		void select_id_PRACH_Configuration() { set(ignore); type=2;}
		void select_id_MBSFN_Subframe_Info() { set(ignore); type=3;}
		void select_id_CSG_Id() { set(ignore); type=4;}
		void select_id_MBMS_Service_Area_List() { set(ignore); type=5;}
		void select_id_MultibandInfoList() { set(ignore); type=6;}
		void select_id_FreqBandIndicatorPriority() { set(ignore); type=7;}
		void select_id_BandwidthReducedSI() { set(ignore); type=8;}
		void select_id_ProtectedEUTRAResourceIndication() { set(ignore); type=9;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else if(equal(ignore)) { type = 3; return true; }
			else if(equal(ignore)) { type = 4; return true; }
			else if(equal(ignore)) { type = 5; return true; }
			else if(equal(ignore)) { type = 6; return true; }
			else if(equal(ignore)) { type = 7; return true; }
			else if(equal(ignore)) { type = 8; return true; }
			else if(equal(ignore)) { type = 9; return true; }
			else { type = 10; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(ignore);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(ignore);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(ignore);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(ignore);} return false;
			case 7: type = 7; if(v(ref_nested())) { return equal(ignore);} return false;
			case 8: type = 8; if(v(ref_nested())) { return equal(ignore);} return false;
			case 9: type = 9; if(v(ref_nested())) { return equal(ignore);} return false;
			case 10: type = 10; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		Number_of_Antennaports& select_id_Number_of_Antennaports() { return set<Number_of_Antennaports>(1); }
		Number_of_Antennaports const* get_id_Number_of_Antennaports() const { return get<Number_of_Antennaports>(1); }
		PRACH_Configuration& select_id_PRACH_Configuration() { return set<PRACH_Configuration>(2); }
		PRACH_Configuration const* get_id_PRACH_Configuration() const { return get<PRACH_Configuration>(2); }
		MBSFN_Subframe_Infolist& select_id_MBSFN_Subframe_Info() { return set<MBSFN_Subframe_Infolist>(3); }
		MBSFN_Subframe_Infolist const* get_id_MBSFN_Subframe_Info() const { return get<MBSFN_Subframe_Infolist>(3); }
		CSG_Id& select_id_CSG_Id() { return set<CSG_Id>(4); }
		CSG_Id const* get_id_CSG_Id() const { return get<CSG_Id>(4); }
		MBMS_Service_Area_Identity_List& select_id_MBMS_Service_Area_List() { return set<MBMS_Service_Area_Identity_List>(5); }
		MBMS_Service_Area_Identity_List const* get_id_MBMS_Service_Area_List() const { return get<MBMS_Service_Area_Identity_List>(5); }
		MultibandInfoList& select_id_MultibandInfoList() { return set<MultibandInfoList>(6); }
		MultibandInfoList const* get_id_MultibandInfoList() const { return get<MultibandInfoList>(6); }
		FreqBandIndicatorPriority& select_id_FreqBandIndicatorPriority() { return set<FreqBandIndicatorPriority>(7); }
		FreqBandIndicatorPriority const* get_id_FreqBandIndicatorPriority() const { return get<FreqBandIndicatorPriority>(7); }
		BandwidthReducedSI& select_id_BandwidthReducedSI() { return set<BandwidthReducedSI>(8); }
		BandwidthReducedSI const* get_id_BandwidthReducedSI() const { return get<BandwidthReducedSI>(8); }
		ProtectedEUTRAResourceIndication& select_id_ProtectedEUTRAResourceIndication() { return set<ProtectedEUTRAResourceIndication>(9); }
		ProtectedEUTRAResourceIndication const* get_id_ProtectedEUTRAResourceIndication() const { return get<ProtectedEUTRAResourceIndication>(9); }
		bool is_unknown() const { return type == 10; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<Number_of_Antennaports>(); break;
			case 2: var.destroy<PRACH_Configuration>(); break;
			case 3: var.destroy<MBSFN_Subframe_Infolist>(); break;
			case 4: var.destroy<CSG_Id>(); break;
			case 5: var.destroy<MBMS_Service_Area_Identity_List>(); break;
			case 6: var.destroy<MultibandInfoList>(); break;
			case 7: var.destroy<FreqBandIndicatorPriority>(); break;
			case 8: var.destroy<BandwidthReducedSI>(); break;
			case 9: var.destroy<ProtectedEUTRAResourceIndication>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<Number_of_Antennaports>(1);
			v.template operator()<PRACH_Configuration>(2);
			v.template operator()<MBSFN_Subframe_Infolist>(3);
			v.template operator()<CSG_Id>(4);
			v.template operator()<MBMS_Service_Area_Identity_List>(5);
			v.template operator()<MultibandInfoList>(6);
			v.template operator()<FreqBandIndicatorPriority>(7);
			v.template operator()<BandwidthReducedSI>(8);
			v.template operator()<ProtectedEUTRAResourceIndication>(9);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_Number_of_Antennaports()); return true;
			case 2: v(select_id_PRACH_Configuration()); return true;
			case 3: v(select_id_MBSFN_Subframe_Info()); return true;
			case 4: v(select_id_CSG_Id()); return true;
			case 5: v(select_id_MBMS_Service_Area_List()); return true;
			case 6: v(select_id_MultibandInfoList()); return true;
			case 7: v(select_id_FreqBandIndicatorPriority()); return true;
			case 8: v(select_id_BandwidthReducedSI()); return true;
			case 9: v(select_id_ProtectedEUTRAResourceIndication()); return true;
			case 10: if(type != 10) {clear(); asn::base::set();} type = 10; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<Number_of_Antennaports>()); return true;
			case 2: v(var.as<PRACH_Configuration>()); return true;
			case 3: v(var.as<MBSFN_Subframe_Infolist>()); return true;
			case 4: v(var.as<CSG_Id>()); return true;
			case 5: v(var.as<MBMS_Service_Area_Identity_List>()); return true;
			case 6: v(var.as<MultibandInfoList>()); return true;
			case 7: v(var.as<FreqBandIndicatorPriority>()); return true;
			case 8: v(var.as<BandwidthReducedSI>()); return true;
			case 9: v(var.as<ProtectedEUTRAResourceIndication>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(BandwidthReducedSI)];
			char dummy2[sizeof(CSG_Id)];
			char dummy3[sizeof(FreqBandIndicatorPriority)];
			char dummy4[sizeof(MBMS_Service_Area_Identity_List)];
			char dummy5[sizeof(MBSFN_Subframe_Infolist)];
			char dummy6[sizeof(MultibandInfoList)];
			char dummy7[sizeof(Number_of_Antennaports)];
			char dummy8[sizeof(PRACH_Configuration)];
			char dummy9[sizeof(ProtectedEUTRAResourceIndication)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 10; }
		void clear() {type = 0;}
		void select_id_Number_of_Antennaports() { set(optional); type=1;}
		void select_id_PRACH_Configuration() { set(optional); type=2;}
		void select_id_MBSFN_Subframe_Info() { set(optional); type=3;}
		void select_id_CSG_Id() { set(optional); type=4;}
		void select_id_MBMS_Service_Area_List() { set(optional); type=5;}
		void select_id_MultibandInfoList() { set(optional); type=6;}
		void select_id_FreqBandIndicatorPriority() { set(optional); type=7;}
		void select_id_BandwidthReducedSI() { set(optional); type=8;}
		void select_id_ProtectedEUTRAResourceIndication() { set(optional); type=9;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else if(equal(optional)) { type = 3; return true; }
			else if(equal(optional)) { type = 4; return true; }
			else if(equal(optional)) { type = 5; return true; }
			else if(equal(optional)) { type = 6; return true; }
			else if(equal(optional)) { type = 7; return true; }
			else if(equal(optional)) { type = 8; return true; }
			else if(equal(optional)) { type = 9; return true; }
			else { type = 10; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(optional);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(optional);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(optional);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(optional);} return false;
			case 7: type = 7; if(v(ref_nested())) { return equal(optional);} return false;
			case 8: type = 8; if(v(ref_nested())) { return equal(optional);} return false;
			case 9: type = 9; if(v(ref_nested())) { return equal(optional);} return false;
			case 10: type = 10; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ServedCell-Information ::= SEQUENCE {
	pCI					PCI,
	cellId				ECGI,
	tAC					TAC,
	broadcastPLMNs		BroadcastPLMNs-Item,
	eUTRA-Mode-Info		EUTRA-Mode-Info,
	iE-Extensions		ProtocolExtensionContainer { {ServedCell-Information-ExtIEs} } OPTIONAL,
	...
}
*/

struct ServedCell_Information : asn::sequence<6, 0, true, 1>
{
	static constexpr const char* name() {return "ServedCell-Information";}
	using parent_t = asn::sequence<6, 0, true, 1>;
	struct pCI_t : PCI
	{
		static constexpr const char* name() {return "pCI_t";}
		using parent_t = PCI;

	};
	pCI_t& ref_pCI() {return pCI;}
	pCI_t const& ref_pCI() const {return pCI;}
	struct cellId_t : ECGI
	{
		static constexpr const char* name() {return "cellId_t";}
		using parent_t = ECGI;

	};
	cellId_t& ref_cellId() {return cellId;}
	cellId_t const& ref_cellId() const {return cellId;}
	struct tAC_t : TAC
	{
		static constexpr const char* name() {return "tAC_t";}
		using parent_t = TAC;

	};
	tAC_t& ref_tAC() {return tAC;}
	tAC_t const& ref_tAC() const {return tAC;}
	struct broadcastPLMNs_t : BroadcastPLMNs_Item
	{
		static constexpr const char* name() {return "broadcastPLMNs_t";}
		using parent_t = BroadcastPLMNs_Item;

	};
	broadcastPLMNs_t& ref_broadcastPLMNs() {return broadcastPLMNs;}
	broadcastPLMNs_t const& ref_broadcastPLMNs() const {return broadcastPLMNs;}
	struct eUTRA_Mode_Info_t : EUTRA_Mode_Info
	{
		static constexpr const char* name() {return "eUTRA_Mode_Info_t";}
		using parent_t = EUTRA_Mode_Info;

	};
	eUTRA_Mode_Info_t& ref_eUTRA_Mode_Info() {return eUTRA_Mode_Info;}
	eUTRA_Mode_Info_t const& ref_eUTRA_Mode_Info() const {return eUTRA_Mode_Info;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ServedCell_Information_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ServedCell_Information_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(pCI);
		v(cellId);
		v(tAC);
		v(broadcastPLMNs);
		v(eUTRA_Mode_Info);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(pCI);
		v(cellId);
		v(tAC);
		v(broadcastPLMNs);
		v(eUTRA_Mode_Info);
		v(iE_Extensions);

	};
	void clear()
	{
		pCI.clear();
		cellId.clear();
		tAC.clear();
		broadcastPLMNs.clear();
		eUTRA_Mode_Info.clear();
		iE_Extensions.clear();

	};
	private:
	pCI_t	pCI;
	cellId_t	cellId;
	tAC_t	tAC;
	broadcastPLMNs_t	broadcastPLMNs;
	eUTRA_Mode_Info_t	eUTRA_Mode_Info;
	iE_Extensions_t	iE_Extensions;

};
/*
ServedCells ::= SEQUENCE (SIZE (1.. maxCellineNB)) OF SEQUENCE {
	servedCellInfo					ServedCell-Information,
	neighbour-Info					Neighbour-Information			OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {ServedCell-ExtIEs} } OPTIONAL,
	...
}
*/

struct ServedCells_elm : asn::sequence<3, 0, true, 2>
{
	static constexpr const char* name() {return "ServedCells_elm";}
	using parent_t = asn::sequence<3, 0, true, 2>;
	struct servedCellInfo_t : ServedCell_Information
	{
		static constexpr const char* name() {return "servedCellInfo_t";}
		using parent_t = ServedCell_Information;

	};
	servedCellInfo_t& ref_servedCellInfo() {return servedCellInfo;}
	servedCellInfo_t const& ref_servedCellInfo() const {return servedCellInfo;}
	struct neighbour_Info_t : Neighbour_Information
	{
		static constexpr const char* name() {return "neighbour_Info_t";}
		using parent_t = Neighbour_Information;
		static constexpr bool optional = true;

	};
	neighbour_Info_t& set_neighbour_Info() { neighbour_Info.setpresent(true); return neighbour_Info;}
	neighbour_Info_t const* get_neighbour_Info() const {return neighbour_Info.is_valid() ? &neighbour_Info : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ServedCell_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ServedCell_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(servedCellInfo);
		v(neighbour_Info);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(servedCellInfo);
		v(neighbour_Info);
		v(iE_Extensions);

	};
	void clear()
	{
		servedCellInfo.clear();
		neighbour_Info.clear();
		iE_Extensions.clear();

	};
	private:
	servedCellInfo_t	servedCellInfo;
	neighbour_Info_t	neighbour_Info;
	iE_Extensions_t	iE_Extensions;

};
struct ServedCells : asn::sequenceof<ServedCells_elm>
{
	static constexpr const char* name() {return "ServedCells";}
	using parent_t = asn::sequenceof<ServedCells_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCellineNB >>;

};
/*
ServiceType ::= ENUMERATED{
	qMC-for-streaming-service,
	qMC-for-MTSI-service,
	...
}
*/

struct ServiceType : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "ServiceType";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		qMC_for_streaming_service
		,qMC_for_MTSI_service
	} index_t;

};

/*
SgNB-UE-X2AP-ID ::= INTEGER (0..4294967295)
*/

struct SgNB_UE_X2AP_ID : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 4294967295>>;
	static constexpr const char* name() {return "SgNB-UE-X2AP-ID";}
	using parent_t = asn::integer<>;

};

/*
SgNBCoordinationAssistanceInformation ::= ENUMERATED{
	coordination-not-required,
	...
}
*/

struct SgNBCoordinationAssistanceInformation : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "SgNBCoordinationAssistanceInformation";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		coordination_not_required
	} index_t;

};

/*
SgNBResourceCoordinationInformationExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-ECGI										CRITICALITY ignore	EXTENSION ECGI												PRESENCE optional}|
	{ ID id-SgNBCoordinationAssistanceInformation		CRITICALITY reject	EXTENSION SgNBCoordinationAssistanceInformation	PRESENCE optional},
	...
}
*/

struct SgNBResourceCoordinationInformationExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_ECGI() { set(id_ECGI); type=1;}
		void select_id_SgNBCoordinationAssistanceInformation() { set(id_SgNBCoordinationAssistanceInformation); type=2;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_ECGI)) { type = 1; return true; }
			else if(equal(id_SgNBCoordinationAssistanceInformation)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_ECGI);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_SgNBCoordinationAssistanceInformation);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_ECGI() { set(ignore); type=1;}
		void select_id_SgNBCoordinationAssistanceInformation() { set(reject); type=2;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(reject)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(reject);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		ECGI& select_id_ECGI() { return set<ECGI>(1); }
		ECGI const* get_id_ECGI() const { return get<ECGI>(1); }
		SgNBCoordinationAssistanceInformation& select_id_SgNBCoordinationAssistanceInformation() { return set<SgNBCoordinationAssistanceInformation>(2); }
		SgNBCoordinationAssistanceInformation const* get_id_SgNBCoordinationAssistanceInformation() const { return get<SgNBCoordinationAssistanceInformation>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<ECGI>(); break;
			case 2: var.destroy<SgNBCoordinationAssistanceInformation>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<ECGI>(1);
			v.template operator()<SgNBCoordinationAssistanceInformation>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_ECGI()); return true;
			case 2: v(select_id_SgNBCoordinationAssistanceInformation()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<ECGI>()); return true;
			case 2: v(var.as<SgNBCoordinationAssistanceInformation>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(ECGI)];
			char dummy2[sizeof(SgNBCoordinationAssistanceInformation)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_ECGI() { set(optional); type=1;}
		void select_id_SgNBCoordinationAssistanceInformation() { set(optional); type=2;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
SgNBResourceCoordinationInformation ::= SEQUENCE {
	nR-CGI							NRCGI,
	uLCoordinationInformation		BIT STRING (SIZE(6..4400, ...)),
	dLCoordinationInformation		BIT STRING (SIZE(6..4400, ...))	OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { {SgNBResourceCoordinationInformationExtIEs} }		 OPTIONAL,
	...
}
*/

struct SgNBResourceCoordinationInformation : asn::sequence<4, 0, true, 2>
{
	static constexpr const char* name() {return "SgNBResourceCoordinationInformation";}
	using parent_t = asn::sequence<4, 0, true, 2>;
	struct nR_CGI_t : NRCGI
	{
		static constexpr const char* name() {return "nR_CGI_t";}
		using parent_t = NRCGI;

	};
	nR_CGI_t& ref_nR_CGI() {return nR_CGI;}
	nR_CGI_t const& ref_nR_CGI() const {return nR_CGI;}
	struct uLCoordinationInformation_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::span<6, 4400>>;
		static constexpr const char* name() {return "uLCoordinationInformation_t";}
		using parent_t = asn::bstring<>;

	};

	uLCoordinationInformation_t& ref_uLCoordinationInformation() {return uLCoordinationInformation;}
	uLCoordinationInformation_t const& ref_uLCoordinationInformation() const {return uLCoordinationInformation;}
	struct dLCoordinationInformation_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<true,asn::span<6, 4400>>;
		static constexpr const char* name() {return "dLCoordinationInformation_t";}
		using parent_t = asn::bstring<>;
		static constexpr bool optional = true;

	};

	dLCoordinationInformation_t& set_dLCoordinationInformation() { dLCoordinationInformation.setpresent(true); return dLCoordinationInformation;}
	dLCoordinationInformation_t const* get_dLCoordinationInformation() const {return dLCoordinationInformation.is_valid() ? &dLCoordinationInformation : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<SgNBResourceCoordinationInformationExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<SgNBResourceCoordinationInformationExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(nR_CGI);
		v(uLCoordinationInformation);
		v(dLCoordinationInformation);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(nR_CGI);
		v(uLCoordinationInformation);
		v(dLCoordinationInformation);
		v(iE_Extensions);

	};
	void clear()
	{
		nR_CGI.clear();
		uLCoordinationInformation.clear();
		dLCoordinationInformation.clear();
		iE_Extensions.clear();

	};
	private:
	nR_CGI_t	nR_CGI;
	uLCoordinationInformation_t	uLCoordinationInformation;
	dLCoordinationInformation_t	dLCoordinationInformation;
	iE_Extensions_t	iE_Extensions;

};
/*
SgNBSecurityKey ::= BIT STRING (SIZE(256))
*/

struct SgNBSecurityKey : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<256>>;
	static constexpr const char* name() {return "SgNBSecurityKey";}
	using parent_t = asn::bstring<>;

};

/*
SgNBtoMeNBContainer ::= OCTET STRING
*/

struct SgNBtoMeNBContainer : asn::ostring<>
{
	static constexpr const char* name() {return "SgNBtoMeNBContainer";}
	using parent_t = asn::ostring<>;

};

/*
ShortMAC-I ::= BIT STRING (SIZE(16))
*/

struct ShortMAC_I : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<16>>;
	static constexpr const char* name() {return "ShortMAC-I";}
	using parent_t = asn::bstring<>;

};

/*
SpectrumSharingGroupID ::= INTEGER (1..maxCellineNB)
*/

struct SpectrumSharingGroupID : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<1,  maxCellineNB >>;
	static constexpr const char* name() {return "SpectrumSharingGroupID";}
	using parent_t = asn::integer<>;

};

/*
SplitSRB-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct SplitSRB_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
SplitSRB ::= SEQUENCE {
	rrcContainer 				RRCContainer			OPTIONAL,
	srbType						SRBType,
	deliveryStatus				DeliveryStatus			OPTIONAL,
	iE-Extensions				ProtocolExtensionContainer { {SplitSRB-ExtIEs} } OPTIONAL,
	...
}
*/

struct SplitSRB : asn::sequence<4, 0, true, 3>
{
	static constexpr const char* name() {return "SplitSRB";}
	using parent_t = asn::sequence<4, 0, true, 3>;
	struct rrcContainer_t : RRCContainer
	{
		static constexpr const char* name() {return "rrcContainer_t";}
		using parent_t = RRCContainer;
		static constexpr bool optional = true;

	};
	rrcContainer_t& set_rrcContainer() { rrcContainer.setpresent(true); return rrcContainer;}
	rrcContainer_t const* get_rrcContainer() const {return rrcContainer.is_valid() ? &rrcContainer : nullptr;}
	struct srbType_t : SRBType
	{
		static constexpr const char* name() {return "srbType_t";}
		using parent_t = SRBType;

	};
	srbType_t& ref_srbType() {return srbType;}
	srbType_t const& ref_srbType() const {return srbType;}
	struct deliveryStatus_t : DeliveryStatus
	{
		static constexpr const char* name() {return "deliveryStatus_t";}
		using parent_t = DeliveryStatus;
		static constexpr bool optional = true;

	};
	deliveryStatus_t& set_deliveryStatus() { deliveryStatus.setpresent(true); return deliveryStatus;}
	deliveryStatus_t const* get_deliveryStatus() const {return deliveryStatus.is_valid() ? &deliveryStatus : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<SplitSRB_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<SplitSRB_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(rrcContainer);
		v(srbType);
		v(deliveryStatus);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(rrcContainer);
		v(srbType);
		v(deliveryStatus);
		v(iE_Extensions);

	};
	void clear()
	{
		rrcContainer.clear();
		srbType.clear();
		deliveryStatus.clear();
		iE_Extensions.clear();

	};
	private:
	rrcContainer_t	rrcContainer;
	srbType_t	srbType;
	deliveryStatus_t	deliveryStatus;
	iE_Extensions_t	iE_Extensions;

};
/*
SplitSRBs ::= ENUMERATED {srb1, srb2, srb1and2, ...}
*/

struct SplitSRBs : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "SplitSRBs";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		srb1
		,srb2
		,srb1and2
	} index_t;

};

/*
SubscriberProfileIDforRFP ::= INTEGER (1..256)
*/

struct SubscriberProfileIDforRFP : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<1, 256>>;
	static constexpr const char* name() {return "SubscriberProfileIDforRFP";}
	using parent_t = asn::integer<>;

};

/*
Subscription-Based-UE-DifferentiationInfo-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct Subscription_Based_UE_DifferentiationInfo_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
Subscription-Based-UE-DifferentiationInfo ::= SEQUENCE {
	periodicCommunicationIndicator	ENUMERATED {periodically, ondemand, ...}		OPTIONAL,
	periodicTime					INTEGER (1..3600, ...) 							OPTIONAL,
	scheduledCommunicationTime		ScheduledCommunicationTime 						OPTIONAL,
	stationaryIndication			ENUMERATED {stationary, mobile, ...}			OPTIONAL,
	trafficProfile 					ENUMERATED {single-packet, dual-packets, multiple-packets, ...} 			OPTIONAL,
	batteryIndication				ENUMERATED {battery-powered, battery-powered-not-rechargeable-or-replaceable, not-battery-powered, ...}		OPTIONAL,
	iE-Extensions					ProtocolExtensionContainer { { Subscription-Based-UE-DifferentiationInfo-ExtIEs} } OPTIONAL,
	...
}
*/

struct Subscription_Based_UE_DifferentiationInfo : asn::sequence<7, 0, true, 7>
{
	static constexpr const char* name() {return "Subscription-Based-UE-DifferentiationInfo";}
	using parent_t = asn::sequence<7, 0, true, 7>;
	struct periodicCommunicationIndicator_t : asn::enumerated<2, 0, true>
	{
		static constexpr const char* name() {return "periodicCommunicationIndicator_t";}
		using parent_t = asn::enumerated<2, 0, true>;
		static constexpr bool optional = true;
		typedef enum {
			periodically
			,ondemand
		} index_t;

	};

	periodicCommunicationIndicator_t& set_periodicCommunicationIndicator() { periodicCommunicationIndicator.setpresent(true); return periodicCommunicationIndicator;}
	periodicCommunicationIndicator_t const* get_periodicCommunicationIndicator() const {return periodicCommunicationIndicator.is_valid() ? &periodicCommunicationIndicator : nullptr;}
	struct periodicTime_t : asn::integer<>
	{
		using constraint_t = asn::constraints<true,asn::span<1, 3600>>;
		static constexpr const char* name() {return "periodicTime_t";}
		using parent_t = asn::integer<>;
		static constexpr bool optional = true;

	};

	periodicTime_t& set_periodicTime() { periodicTime.setpresent(true); return periodicTime;}
	periodicTime_t const* get_periodicTime() const {return periodicTime.is_valid() ? &periodicTime : nullptr;}
	struct scheduledCommunicationTime_t : ScheduledCommunicationTime
	{
		static constexpr const char* name() {return "scheduledCommunicationTime_t";}
		using parent_t = ScheduledCommunicationTime;
		static constexpr bool optional = true;

	};
	scheduledCommunicationTime_t& set_scheduledCommunicationTime() { scheduledCommunicationTime.setpresent(true); return scheduledCommunicationTime;}
	scheduledCommunicationTime_t const* get_scheduledCommunicationTime() const {return scheduledCommunicationTime.is_valid() ? &scheduledCommunicationTime : nullptr;}
	struct stationaryIndication_t : asn::enumerated<2, 0, true>
	{
		static constexpr const char* name() {return "stationaryIndication_t";}
		using parent_t = asn::enumerated<2, 0, true>;
		static constexpr bool optional = true;
		typedef enum {
			stationary
			,mobile
		} index_t;

	};

	stationaryIndication_t& set_stationaryIndication() { stationaryIndication.setpresent(true); return stationaryIndication;}
	stationaryIndication_t const* get_stationaryIndication() const {return stationaryIndication.is_valid() ? &stationaryIndication : nullptr;}
	struct trafficProfile_t : asn::enumerated<3, 0, true>
	{
		static constexpr const char* name() {return "trafficProfile_t";}
		using parent_t = asn::enumerated<3, 0, true>;
		static constexpr bool optional = true;
		typedef enum {
			single_packet
			,dual_packets
			,multiple_packets
		} index_t;

	};

	trafficProfile_t& set_trafficProfile() { trafficProfile.setpresent(true); return trafficProfile;}
	trafficProfile_t const* get_trafficProfile() const {return trafficProfile.is_valid() ? &trafficProfile : nullptr;}
	struct batteryIndication_t : asn::enumerated<3, 0, true>
	{
		static constexpr const char* name() {return "batteryIndication_t";}
		using parent_t = asn::enumerated<3, 0, true>;
		static constexpr bool optional = true;
		typedef enum {
			battery_powered
			,battery_powered_not_rechargeable_or_replaceable
			,not_battery_powered
		} index_t;

	};

	batteryIndication_t& set_batteryIndication() { batteryIndication.setpresent(true); return batteryIndication;}
	batteryIndication_t const* get_batteryIndication() const {return batteryIndication.is_valid() ? &batteryIndication : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<Subscription_Based_UE_DifferentiationInfo_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<Subscription_Based_UE_DifferentiationInfo_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(periodicCommunicationIndicator);
		v(periodicTime);
		v(scheduledCommunicationTime);
		v(stationaryIndication);
		v(trafficProfile);
		v(batteryIndication);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(periodicCommunicationIndicator);
		v(periodicTime);
		v(scheduledCommunicationTime);
		v(stationaryIndication);
		v(trafficProfile);
		v(batteryIndication);
		v(iE_Extensions);

	};
	void clear()
	{
		periodicCommunicationIndicator.clear();
		periodicTime.clear();
		scheduledCommunicationTime.clear();
		stationaryIndication.clear();
		trafficProfile.clear();
		batteryIndication.clear();
		iE_Extensions.clear();

	};
	private:
	periodicCommunicationIndicator_t	periodicCommunicationIndicator;
	periodicTime_t	periodicTime;
	scheduledCommunicationTime_t	scheduledCommunicationTime;
	stationaryIndication_t	stationaryIndication;
	trafficProfile_t	trafficProfile;
	batteryIndication_t	batteryIndication;
	iE_Extensions_t	iE_Extensions;

};
/*
TargetCellInUTRAN ::= OCTET STRING -- This IE is to be encoded according to the UTRAN Cell ID in the Last Visited UTRAN Cell Information IE in TS 25.413 [24]
*/

struct TargetCellInUTRAN : asn::ostring<>
{
	static constexpr const char* name() {return "TargetCellInUTRAN";}
	using parent_t = asn::ostring<>;

};

/*
TargeteNBtoSource-eNBTransparentContainer	::= OCTET STRING
*/

struct TargeteNBtoSource_eNBTransparentContainer : asn::ostring<>
{
	static constexpr const char* name() {return "TargeteNBtoSource-eNBTransparentContainer";}
	using parent_t = asn::ostring<>;

};

/*
TimeToWait ::= ENUMERATED {
	v1s,
	v2s,
	v5s,
	v10s,
	v20s,
	v60s,
	...
}
*/

struct TimeToWait : asn::enumerated<6, 0, true>
{
	static constexpr const char* name() {return "TimeToWait";}
	using parent_t = asn::enumerated<6, 0, true>;
	typedef enum {
		v1s
		,v2s
		,v5s
		,v10s
		,v20s
		,v60s
	} index_t;

};

/*
TraceDepth 		::= ENUMERATED {
	minimum,
	medium,
	maximum,
	minimumWithoutVendorSpecificExtension,
	mediumWithoutVendorSpecificExtension,
	maximumWithoutVendorSpecificExtension,
	...
}
*/

struct TraceDepth : asn::enumerated<6, 0, true>
{
	static constexpr const char* name() {return "TraceDepth";}
	using parent_t = asn::enumerated<6, 0, true>;
	typedef enum {
		minimum
		,medium
		,maximum
		,minimumWithoutVendorSpecificExtension
		,mediumWithoutVendorSpecificExtension
		,maximumWithoutVendorSpecificExtension
	} index_t;

};

/*
TraceCollectionEntityIPAddress ::= BIT STRING (SIZE(1..160, ...))
*/

struct TraceCollectionEntityIPAddress : asn::bstring<>
{
	using constraint_t = asn::constraints<true,asn::span<1, 160>>;
	static constexpr const char* name() {return "TraceCollectionEntityIPAddress";}
	using parent_t = asn::bstring<>;

};

/*
UEAppLayerMeasConfig-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ID id-serviceType	CRITICALITY ignore	EXTENSION ServiceType	PRESENCE optional},
	...
}
*/

struct UEAppLayerMeasConfig_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_serviceType() { set(id_serviceType); type=1;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_serviceType)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_serviceType);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_serviceType() { set(ignore); type=1;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		ServiceType& select_id_serviceType() { return set<ServiceType>(1); }
		ServiceType const* get_id_serviceType() const { return get<ServiceType>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<ServiceType>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<ServiceType>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_serviceType()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<ServiceType>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(ServiceType)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_serviceType() { set(optional); type=1;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else { type = 2; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
UEAppLayerMeasConfig ::= SEQUENCE {
	containerForAppLayerMeasConfig			OCTET STRING (SIZE(1..1000)),
	areaScopeOfQMC		AreaScopeOfQMC,
	iE-Extensions		ProtocolExtensionContainer { {UEAppLayerMeasConfig-ExtIEs} } OPTIONAL,
	...
}
*/

struct UEAppLayerMeasConfig : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "UEAppLayerMeasConfig";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct containerForAppLayerMeasConfig_t : asn::ostring<>
	{
		using constraint_t = asn::constraints<false,asn::span<1, 1000>>;
		static constexpr const char* name() {return "containerForAppLayerMeasConfig_t";}
		using parent_t = asn::ostring<>;

	};

	containerForAppLayerMeasConfig_t& ref_containerForAppLayerMeasConfig() {return containerForAppLayerMeasConfig;}
	containerForAppLayerMeasConfig_t const& ref_containerForAppLayerMeasConfig() const {return containerForAppLayerMeasConfig;}
	struct areaScopeOfQMC_t : AreaScopeOfQMC
	{
		static constexpr const char* name() {return "areaScopeOfQMC_t";}
		using parent_t = AreaScopeOfQMC;

	};
	areaScopeOfQMC_t& ref_areaScopeOfQMC() {return areaScopeOfQMC;}
	areaScopeOfQMC_t const& ref_areaScopeOfQMC() const {return areaScopeOfQMC;}
	struct iE_Extensions_t : ProtocolExtensionContainer<UEAppLayerMeasConfig_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<UEAppLayerMeasConfig_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(containerForAppLayerMeasConfig);
		v(areaScopeOfQMC);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(containerForAppLayerMeasConfig);
		v(areaScopeOfQMC);
		v(iE_Extensions);

	};
	void clear()
	{
		containerForAppLayerMeasConfig.clear();
		areaScopeOfQMC.clear();
		iE_Extensions.clear();

	};
	private:
	containerForAppLayerMeasConfig_t	containerForAppLayerMeasConfig;
	areaScopeOfQMC_t	areaScopeOfQMC;
	iE_Extensions_t	iE_Extensions;

};
/*
TraceActivation-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-MDTConfiguration			CRITICALITY ignore	EXTENSION MDT-Configuration			PRESENCE optional}|
	{ ID id-UEAppLayerMeasConfig		CRITICALITY ignore	EXTENSION UEAppLayerMeasConfig		PRESENCE optional},
	...
}
*/

struct TraceActivation_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_MDTConfiguration() { set(id_MDTConfiguration); type=1;}
		void select_id_UEAppLayerMeasConfig() { set(id_UEAppLayerMeasConfig); type=2;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_MDTConfiguration)) { type = 1; return true; }
			else if(equal(id_UEAppLayerMeasConfig)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_MDTConfiguration);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_UEAppLayerMeasConfig);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_MDTConfiguration() { set(ignore); type=1;}
		void select_id_UEAppLayerMeasConfig() { set(ignore); type=2;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		MDT_Configuration& select_id_MDTConfiguration() { return set<MDT_Configuration>(1); }
		MDT_Configuration const* get_id_MDTConfiguration() const { return get<MDT_Configuration>(1); }
		UEAppLayerMeasConfig& select_id_UEAppLayerMeasConfig() { return set<UEAppLayerMeasConfig>(2); }
		UEAppLayerMeasConfig const* get_id_UEAppLayerMeasConfig() const { return get<UEAppLayerMeasConfig>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<MDT_Configuration>(); break;
			case 2: var.destroy<UEAppLayerMeasConfig>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<MDT_Configuration>(1);
			v.template operator()<UEAppLayerMeasConfig>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_MDTConfiguration()); return true;
			case 2: v(select_id_UEAppLayerMeasConfig()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<MDT_Configuration>()); return true;
			case 2: v(var.as<UEAppLayerMeasConfig>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(MDT_Configuration)];
			char dummy2[sizeof(UEAppLayerMeasConfig)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_MDTConfiguration() { set(optional); type=1;}
		void select_id_UEAppLayerMeasConfig() { set(optional); type=2;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
TraceActivation ::= SEQUENCE {
	eUTRANTraceID					EUTRANTraceID,
	interfacesToTrace				InterfacesToTrace,
traceDepth							TraceDepth,
traceCollectionEntityIPAddress		TraceCollectionEntityIPAddress,
	iE-Extensions					ProtocolExtensionContainer { {TraceActivation-ExtIEs} } OPTIONAL,
	...
}
*/

struct TraceActivation : asn::sequence<5, 0, true, 1>
{
	static constexpr const char* name() {return "TraceActivation";}
	using parent_t = asn::sequence<5, 0, true, 1>;
	struct eUTRANTraceID_t : EUTRANTraceID
	{
		static constexpr const char* name() {return "eUTRANTraceID_t";}
		using parent_t = EUTRANTraceID;

	};
	eUTRANTraceID_t& ref_eUTRANTraceID() {return eUTRANTraceID;}
	eUTRANTraceID_t const& ref_eUTRANTraceID() const {return eUTRANTraceID;}
	struct interfacesToTrace_t : InterfacesToTrace
	{
		static constexpr const char* name() {return "interfacesToTrace_t";}
		using parent_t = InterfacesToTrace;

	};
	interfacesToTrace_t& ref_interfacesToTrace() {return interfacesToTrace;}
	interfacesToTrace_t const& ref_interfacesToTrace() const {return interfacesToTrace;}
	struct traceDepth_t : TraceDepth
	{
		static constexpr const char* name() {return "traceDepth_t";}
		using parent_t = TraceDepth;

	};
	traceDepth_t& ref_traceDepth() {return traceDepth;}
	traceDepth_t const& ref_traceDepth() const {return traceDepth;}
	struct traceCollectionEntityIPAddress_t : TraceCollectionEntityIPAddress
	{
		static constexpr const char* name() {return "traceCollectionEntityIPAddress_t";}
		using parent_t = TraceCollectionEntityIPAddress;

	};
	traceCollectionEntityIPAddress_t& ref_traceCollectionEntityIPAddress() {return traceCollectionEntityIPAddress;}
	traceCollectionEntityIPAddress_t const& ref_traceCollectionEntityIPAddress() const {return traceCollectionEntityIPAddress;}
	struct iE_Extensions_t : ProtocolExtensionContainer<TraceActivation_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<TraceActivation_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(eUTRANTraceID);
		v(interfacesToTrace);
		v(traceDepth);
		v(traceCollectionEntityIPAddress);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(eUTRANTraceID);
		v(interfacesToTrace);
		v(traceDepth);
		v(traceCollectionEntityIPAddress);
		v(iE_Extensions);

	};
	void clear()
	{
		eUTRANTraceID.clear();
		interfacesToTrace.clear();
		traceDepth.clear();
		traceCollectionEntityIPAddress.clear();
		iE_Extensions.clear();

	};
	private:
	eUTRANTraceID_t	eUTRANTraceID;
	interfacesToTrace_t	interfacesToTrace;
	traceDepth_t	traceDepth;
	traceCollectionEntityIPAddress_t	traceCollectionEntityIPAddress;
	iE_Extensions_t	iE_Extensions;

};
/*
Tunnel-Information-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct Tunnel_Information_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
TunnelInformation ::= SEQUENCE {
	transportLayerAddress	TransportLayerAddress,
	uDP-Port-Number			Port-Number			OPTIONAL,
	iE-Extensions			ProtocolExtensionContainer { {Tunnel-Information-ExtIEs} } OPTIONAL,
	...
}
*/

struct TunnelInformation : asn::sequence<3, 0, true, 2>
{
	static constexpr const char* name() {return "TunnelInformation";}
	using parent_t = asn::sequence<3, 0, true, 2>;
	struct transportLayerAddress_t : TransportLayerAddress
	{
		static constexpr const char* name() {return "transportLayerAddress_t";}
		using parent_t = TransportLayerAddress;

	};
	transportLayerAddress_t& ref_transportLayerAddress() {return transportLayerAddress;}
	transportLayerAddress_t const& ref_transportLayerAddress() const {return transportLayerAddress;}
	struct uDP_Port_Number_t : Port_Number
	{
		static constexpr const char* name() {return "uDP_Port_Number_t";}
		using parent_t = Port_Number;
		static constexpr bool optional = true;

	};
	uDP_Port_Number_t& set_uDP_Port_Number() { uDP_Port_Number.setpresent(true); return uDP_Port_Number;}
	uDP_Port_Number_t const* get_uDP_Port_Number() const {return uDP_Port_Number.is_valid() ? &uDP_Port_Number : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<Tunnel_Information_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<Tunnel_Information_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(transportLayerAddress);
		v(uDP_Port_Number);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(transportLayerAddress);
		v(uDP_Port_Number);
		v(iE_Extensions);

	};
	void clear()
	{
		transportLayerAddress.clear();
		uDP_Port_Number.clear();
		iE_Extensions.clear();

	};
	private:
	transportLayerAddress_t	transportLayerAddress;
	uDP_Port_Number_t	uDP_Port_Number;
	iE_Extensions_t	iE_Extensions;

};
/*
UE-ContextKeptIndicator ::= ENUMERATED {
	true,
	...
}
*/

struct UE_ContextKeptIndicator : asn::enumerated<1, 0, true>
{
	static constexpr const char* name() {return "UE-ContextKeptIndicator";}
	using parent_t = asn::enumerated<1, 0, true>;
	typedef enum {
		True
	} index_t;

};

/*
UE-HistoryInformation ::= SEQUENCE (SIZE(1..maxnoofCells)) OF LastVisitedCell-Item
*/

struct UE_HistoryInformation_elm : LastVisitedCell_Item
{
	static constexpr const char* name() {return "UE_HistoryInformation_elm";}
	using parent_t = LastVisitedCell_Item;

};
struct UE_HistoryInformation : asn::sequenceof<UE_HistoryInformation_elm>
{
	static constexpr const char* name() {return "UE-HistoryInformation";}
	using parent_t = asn::sequenceof<UE_HistoryInformation_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxnoofCells >>;

};
/*
UE-HistoryInformationFromTheUE ::= OCTET STRING
*/

struct UE_HistoryInformationFromTheUE : asn::ostring<>
{
	static constexpr const char* name() {return "UE-HistoryInformationFromTheUE";}
	using parent_t = asn::ostring<>;

};

/*
UE-RLF-Report-Container::= OCTET STRING
*/

struct UE_RLF_Report_Container : asn::ostring<>
{
	static constexpr const char* name() {return "UE-RLF-Report-Container";}
	using parent_t = asn::ostring<>;

};

/*
UE-RLF-Report-Container-for-extended-bands ::= OCTET STRING
*/

struct UE_RLF_Report_Container_for_extended_bands : asn::ostring<>
{
	static constexpr const char* name() {return "UE-RLF-Report-Container-for-extended-bands";}
	using parent_t = asn::ostring<>;

};

/*
UE-S1AP-ID ::= INTEGER (0.. 4294967295)
*/

struct UE_S1AP_ID : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 4294967295>>;
	static constexpr const char* name() {return "UE-S1AP-ID";}
	using parent_t = asn::integer<>;

};

/*
UE-Sidelink-Aggregate-MaximumBitRate-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct UE_Sidelink_Aggregate_MaximumBitRate_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
UE-X2AP-ID ::= INTEGER (0..4095)
*/

struct UE_X2AP_ID : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 4095>>;
	static constexpr const char* name() {return "UE-X2AP-ID";}
	using parent_t = asn::integer<>;

};

/*
UE-X2AP-ID-Extension ::= INTEGER (0..4095, ...)
*/

struct UE_X2AP_ID_Extension : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<0, 4095>>;
	static constexpr const char* name() {return "UE-X2AP-ID-Extension";}
	using parent_t = asn::integer<>;

};

/*
UEAggregate-MaximumBitrate-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	{ ID id-extended-uEaggregateMaximumBitRateDownlink	CRITICALITY ignore	EXTENSION ExtendedBitRate	PRESENCE optional}|
	{ ID id-extended-uEaggregateMaximumBitRateUplink	CRITICALITY ignore	EXTENSION ExtendedBitRate	PRESENCE optional},
	...
}
*/

struct UEAggregate_MaximumBitrate_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_extended_uEaggregateMaximumBitRateDownlink() { set(id_extended_uEaggregateMaximumBitRateDownlink); type=1;}
		void select_id_extended_uEaggregateMaximumBitRateUplink() { set(id_extended_uEaggregateMaximumBitRateUplink); type=2;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_extended_uEaggregateMaximumBitRateDownlink)) { type = 1; return true; }
			else if(equal(id_extended_uEaggregateMaximumBitRateUplink)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_extended_uEaggregateMaximumBitRateDownlink);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_extended_uEaggregateMaximumBitRateUplink);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_extended_uEaggregateMaximumBitRateDownlink() { set(ignore); type=1;}
		void select_id_extended_uEaggregateMaximumBitRateUplink() { set(ignore); type=2;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(ignore)) { type = 1; return true; }
			else if(equal(ignore)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(ignore);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(ignore);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		ExtendedBitRate& select_id_extended_uEaggregateMaximumBitRateDownlink() { return set<ExtendedBitRate>(1); }
		ExtendedBitRate const* get_id_extended_uEaggregateMaximumBitRateDownlink() const { return get<ExtendedBitRate>(1); }
		ExtendedBitRate& select_id_extended_uEaggregateMaximumBitRateUplink() { return set<ExtendedBitRate>(2); }
		ExtendedBitRate const* get_id_extended_uEaggregateMaximumBitRateUplink() const { return get<ExtendedBitRate>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<ExtendedBitRate>(); break;
			case 2: var.destroy<ExtendedBitRate>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<ExtendedBitRate>(1);
			v.template operator()<ExtendedBitRate>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_extended_uEaggregateMaximumBitRateDownlink()); return true;
			case 2: v(select_id_extended_uEaggregateMaximumBitRateUplink()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<ExtendedBitRate>()); return true;
			case 2: v(var.as<ExtendedBitRate>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(ExtendedBitRate)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_extended_uEaggregateMaximumBitRateDownlink() { set(optional); type=1;}
		void select_id_extended_uEaggregateMaximumBitRateUplink() { set(optional); type=2;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(optional)) { type = 1; return true; }
			else if(equal(optional)) { type = 2; return true; }
			else { type = 3; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(optional);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(optional);} return false;
			case 3: type = 3; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
UEAggregateMaximumBitRate ::= SEQUENCE {
	uEaggregateMaximumBitRateDownlink	BitRate,
	uEaggregateMaximumBitRateUplink		BitRate,
	iE-Extensions						ProtocolExtensionContainer { {UEAggregate-MaximumBitrate-ExtIEs} } OPTIONAL,
	...
}
*/

struct UEAggregateMaximumBitRate : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "UEAggregateMaximumBitRate";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct uEaggregateMaximumBitRateDownlink_t : BitRate
	{
		static constexpr const char* name() {return "uEaggregateMaximumBitRateDownlink_t";}
		using parent_t = BitRate;

	};
	uEaggregateMaximumBitRateDownlink_t& ref_uEaggregateMaximumBitRateDownlink() {return uEaggregateMaximumBitRateDownlink;}
	uEaggregateMaximumBitRateDownlink_t const& ref_uEaggregateMaximumBitRateDownlink() const {return uEaggregateMaximumBitRateDownlink;}
	struct uEaggregateMaximumBitRateUplink_t : BitRate
	{
		static constexpr const char* name() {return "uEaggregateMaximumBitRateUplink_t";}
		using parent_t = BitRate;

	};
	uEaggregateMaximumBitRateUplink_t& ref_uEaggregateMaximumBitRateUplink() {return uEaggregateMaximumBitRateUplink;}
	uEaggregateMaximumBitRateUplink_t const& ref_uEaggregateMaximumBitRateUplink() const {return uEaggregateMaximumBitRateUplink;}
	struct iE_Extensions_t : ProtocolExtensionContainer<UEAggregate_MaximumBitrate_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<UEAggregate_MaximumBitrate_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(uEaggregateMaximumBitRateDownlink);
		v(uEaggregateMaximumBitRateUplink);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(uEaggregateMaximumBitRateDownlink);
		v(uEaggregateMaximumBitRateUplink);
		v(iE_Extensions);

	};
	void clear()
	{
		uEaggregateMaximumBitRateDownlink.clear();
		uEaggregateMaximumBitRateUplink.clear();
		iE_Extensions.clear();

	};
	private:
	uEaggregateMaximumBitRateDownlink_t	uEaggregateMaximumBitRateDownlink;
	uEaggregateMaximumBitRateUplink_t	uEaggregateMaximumBitRateUplink;
	iE_Extensions_t	iE_Extensions;

};
/*
UENRMeasurement-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct UENRMeasurement_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
UENRMeasurement ::= SEQUENCE {
	uENRMeasurements			RRCContainer,
	iE-Extensions			ProtocolExtensionContainer { {UENRMeasurement-ExtIEs} } OPTIONAL,
	...
}
*/

struct UENRMeasurement : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "UENRMeasurement";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct uENRMeasurements_t : RRCContainer
	{
		static constexpr const char* name() {return "uENRMeasurements_t";}
		using parent_t = RRCContainer;

	};
	uENRMeasurements_t& ref_uENRMeasurements() {return uENRMeasurements;}
	uENRMeasurements_t const& ref_uENRMeasurements() const {return uENRMeasurements;}
	struct iE_Extensions_t : ProtocolExtensionContainer<UENRMeasurement_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<UENRMeasurement_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(uENRMeasurements);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(uENRMeasurements);
		v(iE_Extensions);

	};
	void clear()
	{
		uENRMeasurements.clear();
		iE_Extensions.clear();

	};
	private:
	uENRMeasurements_t	uENRMeasurements;
	iE_Extensions_t	iE_Extensions;

};
/*
UESecurityCapabilities-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct UESecurityCapabilities_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
UESecurityCapabilities ::= SEQUENCE {
	encryptionAlgorithms				EncryptionAlgorithms,
	integrityProtectionAlgorithms		IntegrityProtectionAlgorithms,
	iE-Extensions						ProtocolExtensionContainer { {UESecurityCapabilities-ExtIEs} }		OPTIONAL,
...
}
*/

struct UESecurityCapabilities : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "UESecurityCapabilities";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct encryptionAlgorithms_t : EncryptionAlgorithms
	{
		static constexpr const char* name() {return "encryptionAlgorithms_t";}
		using parent_t = EncryptionAlgorithms;

	};
	encryptionAlgorithms_t& ref_encryptionAlgorithms() {return encryptionAlgorithms;}
	encryptionAlgorithms_t const& ref_encryptionAlgorithms() const {return encryptionAlgorithms;}
	struct integrityProtectionAlgorithms_t : IntegrityProtectionAlgorithms
	{
		static constexpr const char* name() {return "integrityProtectionAlgorithms_t";}
		using parent_t = IntegrityProtectionAlgorithms;

	};
	integrityProtectionAlgorithms_t& ref_integrityProtectionAlgorithms() {return integrityProtectionAlgorithms;}
	integrityProtectionAlgorithms_t const& ref_integrityProtectionAlgorithms() const {return integrityProtectionAlgorithms;}
	struct iE_Extensions_t : ProtocolExtensionContainer<UESecurityCapabilities_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<UESecurityCapabilities_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(encryptionAlgorithms);
		v(integrityProtectionAlgorithms);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(encryptionAlgorithms);
		v(integrityProtectionAlgorithms);
		v(iE_Extensions);

	};
	void clear()
	{
		encryptionAlgorithms.clear();
		integrityProtectionAlgorithms.clear();
		iE_Extensions.clear();

	};
	private:
	encryptionAlgorithms_t	encryptionAlgorithms;
	integrityProtectionAlgorithms_t	integrityProtectionAlgorithms;
	iE_Extensions_t	iE_Extensions;

};
/*
UESidelinkAggregateMaximumBitRate ::= SEQUENCE {
	uESidelinkAggregateMaximumBitRate		BitRate,
	iE-Extensions					ProtocolExtensionContainer { {UE-Sidelink-Aggregate-MaximumBitRate-ExtIEs} } OPTIONAL,
	...
}
*/

struct UESidelinkAggregateMaximumBitRate : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "UESidelinkAggregateMaximumBitRate";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct uESidelinkAggregateMaximumBitRate_t : BitRate
	{
		static constexpr const char* name() {return "uESidelinkAggregateMaximumBitRate_t";}
		using parent_t = BitRate;

	};
	uESidelinkAggregateMaximumBitRate_t& ref_uESidelinkAggregateMaximumBitRate() {return uESidelinkAggregateMaximumBitRate;}
	uESidelinkAggregateMaximumBitRate_t const& ref_uESidelinkAggregateMaximumBitRate() const {return uESidelinkAggregateMaximumBitRate;}
	struct iE_Extensions_t : ProtocolExtensionContainer<UE_Sidelink_Aggregate_MaximumBitRate_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<UE_Sidelink_Aggregate_MaximumBitRate_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(uESidelinkAggregateMaximumBitRate);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(uESidelinkAggregateMaximumBitRate);
		v(iE_Extensions);

	};
	void clear()
	{
		uESidelinkAggregateMaximumBitRate.clear();
		iE_Extensions.clear();

	};
	private:
	uESidelinkAggregateMaximumBitRate_t	uESidelinkAggregateMaximumBitRate;
	iE_Extensions_t	iE_Extensions;

};
/*
UEsToBeResetList-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct UEsToBeResetList_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
UEsToBeResetList-Item::= SEQUENCE {
	meNB-ID					UE-X2AP-ID,
	meNB-ID-ext				UE-X2AP-ID-Extension														OPTIONAL,
	sgNB-ID					SgNB-UE-X2AP-ID																OPTIONAL,
	iE-Extensions			ProtocolExtensionContainer { {UEsToBeResetList-Item-ExtIEs} }				OPTIONAL,
	...
}
*/

struct UEsToBeResetList_Item : asn::sequence<4, 0, true, 3>
{
	static constexpr const char* name() {return "UEsToBeResetList-Item";}
	using parent_t = asn::sequence<4, 0, true, 3>;
	struct meNB_ID_t : UE_X2AP_ID
	{
		static constexpr const char* name() {return "meNB_ID_t";}
		using parent_t = UE_X2AP_ID;

	};
	meNB_ID_t& ref_meNB_ID() {return meNB_ID;}
	meNB_ID_t const& ref_meNB_ID() const {return meNB_ID;}
	struct meNB_ID_ext_t : UE_X2AP_ID_Extension
	{
		static constexpr const char* name() {return "meNB_ID_ext_t";}
		using parent_t = UE_X2AP_ID_Extension;
		static constexpr bool optional = true;

	};
	meNB_ID_ext_t& set_meNB_ID_ext() { meNB_ID_ext.setpresent(true); return meNB_ID_ext;}
	meNB_ID_ext_t const* get_meNB_ID_ext() const {return meNB_ID_ext.is_valid() ? &meNB_ID_ext : nullptr;}
	struct sgNB_ID_t : SgNB_UE_X2AP_ID
	{
		static constexpr const char* name() {return "sgNB_ID_t";}
		using parent_t = SgNB_UE_X2AP_ID;
		static constexpr bool optional = true;

	};
	sgNB_ID_t& set_sgNB_ID() { sgNB_ID.setpresent(true); return sgNB_ID;}
	sgNB_ID_t const* get_sgNB_ID() const {return sgNB_ID.is_valid() ? &sgNB_ID : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<UEsToBeResetList_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<UEsToBeResetList_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(meNB_ID);
		v(meNB_ID_ext);
		v(sgNB_ID);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(meNB_ID);
		v(meNB_ID_ext);
		v(sgNB_ID);
		v(iE_Extensions);

	};
	void clear()
	{
		meNB_ID.clear();
		meNB_ID_ext.clear();
		sgNB_ID.clear();
		iE_Extensions.clear();

	};
	private:
	meNB_ID_t	meNB_ID;
	meNB_ID_ext_t	meNB_ID_ext;
	sgNB_ID_t	sgNB_ID;
	iE_Extensions_t	iE_Extensions;

};
/*
UEsToBeResetList ::= SEQUENCE (SIZE (1.. maxUEsinengNBDU)) OF UEsToBeResetList-Item
*/

struct UEsToBeResetList_elm : UEsToBeResetList_Item
{
	static constexpr const char* name() {return "UEsToBeResetList_elm";}
	using parent_t = UEsToBeResetList_Item;

};
struct UEsToBeResetList : asn::sequenceof<UEsToBeResetList_elm>
{
	static constexpr const char* name() {return "UEsToBeResetList";}
	using parent_t = asn::sequenceof<UEsToBeResetList_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxUEsinengNBDU >>;

};
/*
UL-HighInterferenceIndication ::= BIT STRING (SIZE(1..110, ...))
*/

struct UL_HighInterferenceIndication : asn::bstring<>
{
	using constraint_t = asn::constraints<true,asn::span<1, 110>>;
	static constexpr const char* name() {return "UL-HighInterferenceIndication";}
	using parent_t = asn::bstring<>;

};

/*
UL-HighInterferenceIndicationInfo-Item-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct UL_HighInterferenceIndicationInfo_Item_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
UL-HighInterferenceIndicationInfo-Item ::= SEQUENCE {
	target-Cell-ID					ECGI,
	ul-interferenceindication		UL-HighInterferenceIndication,
	iE-Extensions					ProtocolExtensionContainer { {UL-HighInterferenceIndicationInfo-Item-ExtIEs} } OPTIONAL,
	...
}
*/

struct UL_HighInterferenceIndicationInfo_Item : asn::sequence<3, 0, true, 1>
{
	static constexpr const char* name() {return "UL-HighInterferenceIndicationInfo-Item";}
	using parent_t = asn::sequence<3, 0, true, 1>;
	struct target_Cell_ID_t : ECGI
	{
		static constexpr const char* name() {return "target_Cell_ID_t";}
		using parent_t = ECGI;

	};
	target_Cell_ID_t& ref_target_Cell_ID() {return target_Cell_ID;}
	target_Cell_ID_t const& ref_target_Cell_ID() const {return target_Cell_ID;}
	struct ul_interferenceindication_t : UL_HighInterferenceIndication
	{
		static constexpr const char* name() {return "ul_interferenceindication_t";}
		using parent_t = UL_HighInterferenceIndication;

	};
	ul_interferenceindication_t& ref_ul_interferenceindication() {return ul_interferenceindication;}
	ul_interferenceindication_t const& ref_ul_interferenceindication() const {return ul_interferenceindication;}
	struct iE_Extensions_t : ProtocolExtensionContainer<UL_HighInterferenceIndicationInfo_Item_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<UL_HighInterferenceIndicationInfo_Item_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(target_Cell_ID);
		v(ul_interferenceindication);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(target_Cell_ID);
		v(ul_interferenceindication);
		v(iE_Extensions);

	};
	void clear()
	{
		target_Cell_ID.clear();
		ul_interferenceindication.clear();
		iE_Extensions.clear();

	};
	private:
	target_Cell_ID_t	target_Cell_ID;
	ul_interferenceindication_t	ul_interferenceindication;
	iE_Extensions_t	iE_Extensions;

};
/*
UL-HighInterferenceIndicationInfo ::= SEQUENCE (SIZE(1..maxCellineNB)) OF UL-HighInterferenceIndicationInfo-Item
*/

struct UL_HighInterferenceIndicationInfo_elm : UL_HighInterferenceIndicationInfo_Item
{
	static constexpr const char* name() {return "UL_HighInterferenceIndicationInfo_elm";}
	using parent_t = UL_HighInterferenceIndicationInfo_Item;

};
struct UL_HighInterferenceIndicationInfo : asn::sequenceof<UL_HighInterferenceIndicationInfo_elm>
{
	static constexpr const char* name() {return "UL-HighInterferenceIndicationInfo";}
	using parent_t = asn::sequenceof<UL_HighInterferenceIndicationInfo_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxCellineNB >>;

};
/*
UL-UE-Configuration::= ENUMERATED { no-data, shared, only, ... }
*/

struct UL_UE_Configuration : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "UL-UE-Configuration";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		no_data
		,shared
		,only
	} index_t;

};

/*
ULConfiguration-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct ULConfiguration_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
ULConfiguration::= SEQUENCE {
	uL-PDCP			UL-UE-Configuration,
	iE-Extensions					ProtocolExtensionContainer { {ULConfiguration-ExtIEs} } OPTIONAL,
	...
}
*/

struct ULConfiguration : asn::sequence<2, 0, true, 1>
{
	static constexpr const char* name() {return "ULConfiguration";}
	using parent_t = asn::sequence<2, 0, true, 1>;
	struct uL_PDCP_t : UL_UE_Configuration
	{
		static constexpr const char* name() {return "uL_PDCP_t";}
		using parent_t = UL_UE_Configuration;

	};
	uL_PDCP_t& ref_uL_PDCP() {return uL_PDCP;}
	uL_PDCP_t const& ref_uL_PDCP() const {return uL_PDCP;}
	struct iE_Extensions_t : ProtocolExtensionContainer<ULConfiguration_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<ULConfiguration_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(uL_PDCP);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(uL_PDCP);
		v(iE_Extensions);

	};
	void clear()
	{
		uL_PDCP.clear();
		iE_Extensions.clear();

	};
	private:
	uL_PDCP_t	uL_PDCP;
	iE_Extensions_t	iE_Extensions;

};
/*
VehicleUE ::= ENUMERATED {
	authorized,
	not-authorized,
	...
}
*/

struct VehicleUE : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "VehicleUE";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		authorized
		,not_authorized
	} index_t;

};

/*
V2XServicesAuthorized-ExtIEs X2AP-PROTOCOL-EXTENSION ::= {
	...
}
*/

struct V2XServicesAuthorized_ExtIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct Extension_t : asn::typefield<true>
	{
		~Extension_t()	{clear();}
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear()
		{
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: if(type != 1) {clear(); asn::base::set();} type = 1; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			return false;

		}
		private:
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_EXTENSION::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 1; }
		void clear() {type = 0;}
		X2AP_PROTOCOL_EXTENSION::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			{ type = 1; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};

};
/*
V2XServicesAuthorized ::= SEQUENCE {
	vehicleUE			VehicleUE														OPTIONAL,
pedestrianUE 			PedestrianUE													OPTIONAL,
	iE-Extensions		ProtocolExtensionContainer { {V2XServicesAuthorized-ExtIEs} }	OPTIONAL,
	...
}
*/

struct V2XServicesAuthorized : asn::sequence<3, 0, true, 3>
{
	static constexpr const char* name() {return "V2XServicesAuthorized";}
	using parent_t = asn::sequence<3, 0, true, 3>;
	struct vehicleUE_t : VehicleUE
	{
		static constexpr const char* name() {return "vehicleUE_t";}
		using parent_t = VehicleUE;
		static constexpr bool optional = true;

	};
	vehicleUE_t& set_vehicleUE() { vehicleUE.setpresent(true); return vehicleUE;}
	vehicleUE_t const* get_vehicleUE() const {return vehicleUE.is_valid() ? &vehicleUE : nullptr;}
	struct pedestrianUE_t : PedestrianUE
	{
		static constexpr const char* name() {return "pedestrianUE_t";}
		using parent_t = PedestrianUE;
		static constexpr bool optional = true;

	};
	pedestrianUE_t& set_pedestrianUE() { pedestrianUE.setpresent(true); return pedestrianUE;}
	pedestrianUE_t const* get_pedestrianUE() const {return pedestrianUE.is_valid() ? &pedestrianUE : nullptr;}
	struct iE_Extensions_t : ProtocolExtensionContainer<V2XServicesAuthorized_ExtIEs>
	{
		static constexpr const char* name() {return "iE_Extensions_t";}
		using parent_t = ProtocolExtensionContainer<V2XServicesAuthorized_ExtIEs>;
		static constexpr bool optional = true;

	};
	iE_Extensions_t& set_iE_Extensions() { iE_Extensions.setpresent(true); return iE_Extensions;}
	iE_Extensions_t const* get_iE_Extensions() const {return iE_Extensions.is_valid() ? &iE_Extensions : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(vehicleUE);
		v(pedestrianUE);
		v(iE_Extensions);

	};
	template<typename V> void encode(V& v) const
	{
		v(vehicleUE);
		v(pedestrianUE);
		v(iE_Extensions);

	};
	void clear()
	{
		vehicleUE.clear();
		pedestrianUE.clear();
		iE_Extensions.clear();

	};
	private:
	vehicleUE_t	vehicleUE;
	pedestrianUE_t	pedestrianUE;
	iE_Extensions_t	iE_Extensions;

};
/*
WT-UE-XwAP-ID ::= OCTET STRING (SIZE (3))
*/

struct WT_UE_XwAP_ID : asn::ostring<>
{
	using constraint_t = asn::constraints<false,asn::one<3>>;
	static constexpr const char* name() {return "WT-UE-XwAP-ID";}
	using parent_t = asn::ostring<>;

};

/*
WTID-Type1 ::= SEQUENCE {
	pLMN-Identity					PLMN-Identity,
	shortWTID						BIT STRING (SIZE(24)),
	...
}
*/

struct WTID_Type1 : asn::sequence<2, 0, true, 0>
{
	static constexpr const char* name() {return "WTID-Type1";}
	using parent_t = asn::sequence<2, 0, true, 0>;
	struct pLMN_Identity_t : PLMN_Identity
	{
		static constexpr const char* name() {return "pLMN_Identity_t";}
		using parent_t = PLMN_Identity;

	};
	pLMN_Identity_t& ref_pLMN_Identity() {return pLMN_Identity;}
	pLMN_Identity_t const& ref_pLMN_Identity() const {return pLMN_Identity;}
	struct shortWTID_t : asn::bstring<>
	{
		using constraint_t = asn::constraints<false,asn::one<24>>;
		static constexpr const char* name() {return "shortWTID_t";}
		using parent_t = asn::bstring<>;

	};

	shortWTID_t& ref_shortWTID() {return shortWTID;}
	shortWTID_t const& ref_shortWTID() const {return shortWTID;}
	template<typename V> void decode(V& v)
	{
		v(pLMN_Identity);
		v(shortWTID);

	};
	template<typename V> void encode(V& v) const
	{
		v(pLMN_Identity);
		v(shortWTID);

	};
	void clear()
	{
		pLMN_Identity.clear();
		shortWTID.clear();

	};
	private:
	pLMN_Identity_t	pLMN_Identity;
	shortWTID_t	shortWTID;

};
/*
WTID-Long-Type2 ::= BIT STRING (SIZE(48))
*/

struct WTID_Long_Type2 : asn::bstring<>
{
	using constraint_t = asn::constraints<false,asn::one<48>>;
	static constexpr const char* name() {return "WTID-Long-Type2";}
	using parent_t = asn::bstring<>;

};

/*
WTID ::= CHOICE {
	wTID-Type1			WTID-Type1,
	wTID-Type2			WTID-Long-Type2,
	...
}
*/

struct WTID : asn::choice<2, 0, true>
{
	static constexpr const char* name() {return "WTID";}
	using parent_t = asn::choice<2, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 3;}
	void set_unknown() { set_index(3);  }
	~WTID() {clear();}
	struct wTID_Type1_t : WTID_Type1
	{
		static constexpr const char* name() {return "wTID_Type1_t";}
		using parent_t = WTID_Type1;

	};
	struct wTID_Type2_t : WTID_Long_Type2
	{
		static constexpr const char* name() {return "wTID_Type2_t";}
		using parent_t = WTID_Long_Type2;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<wTID_Type1_t>(); break;
		case 2: var.destroy<wTID_Type2_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<wTID_Type1_t>());
		case 2: set_index(2); return v(var.build<wTID_Type2_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<wTID_Type1_t>());
		case 2: return v(var.as<wTID_Type2_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<wTID_Type1_t>(1);
		v.template operator()<wTID_Type2_t>(2);

	}
	wTID_Type1_t& select_wTID_Type1() { if(get_index() != 1) { clear(); set_index(1); return var.build<wTID_Type1_t>();} return var.as<wTID_Type1_t>();}
	wTID_Type1_t const* get_wTID_Type1() const { if(get_index() == 1) { return &var.as<wTID_Type1_t>();} return nullptr; }
	wTID_Type2_t& select_wTID_Type2() { if(get_index() != 2) { clear(); set_index(2); return var.build<wTID_Type2_t>();} return var.as<wTID_Type2_t>();}
	wTID_Type2_t const* get_wTID_Type2() const { if(get_index() == 2) { return &var.as<wTID_Type2_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(wTID_Type1_t)];
		char dummy2[sizeof(wTID_Type2_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
X2BenefitValue ::= INTEGER (1..8, ...)
*/

struct X2BenefitValue : asn::integer<>
{
	using constraint_t = asn::constraints<true,asn::span<1, 8>>;
	static constexpr const char* name() {return "X2BenefitValue";}
	using parent_t = asn::integer<>;

};
