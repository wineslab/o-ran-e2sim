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

#include "E2AP-IEs.hpp"
#include "X2AP-IEs.hpp"
#include "X2AP-Constants.hpp"
#include "X2AP-Containers.hpp"
#include "E2AP-Constants.hpp"

/*
RANfunction-Item ::= SEQUENCE {
	ranFunctionID				RANfunctionID,
	ranFunctionDefinition  		RANfunctionDefinition,
	...
}
*/

struct RANfunction_Item : asn::sequence<2, 0, true, 0>
{
	static constexpr const char* name() {return "RANfunction-Item";}
	using parent_t = asn::sequence<2, 0, true, 0>;
	struct ranFunctionID_t : RANfunctionID
	{
		static constexpr const char* name() {return "ranFunctionID_t";}
		using parent_t = RANfunctionID;

	};
	ranFunctionID_t& ref_ranFunctionID() {return ranFunctionID;}
	ranFunctionID_t const& ref_ranFunctionID() const {return ranFunctionID;}
	struct ranFunctionDefinition_t : RANfunctionDefinition
	{
		static constexpr const char* name() {return "ranFunctionDefinition_t";}
		using parent_t = RANfunctionDefinition;

	};
	ranFunctionDefinition_t& ref_ranFunctionDefinition() {return ranFunctionDefinition;}
	ranFunctionDefinition_t const& ref_ranFunctionDefinition() const {return ranFunctionDefinition;}
	template<typename V> void decode(V& v)
	{
		v(ranFunctionID);
		v(ranFunctionDefinition);

	};
	template<typename V> void encode(V& v) const
	{
		v(ranFunctionID);
		v(ranFunctionDefinition);

	};
	void clear()
	{
		ranFunctionID.clear();
		ranFunctionDefinition.clear();

	};
	private:
	ranFunctionID_t	ranFunctionID;
	ranFunctionDefinition_t	ranFunctionDefinition;

};
/*
RANfunction-ItemIEs 	X2AP-PROTOCOL-IES ::= {
	{ ID id-RANfunction-Item	 		CRITICALITY ignore 	TYPE RANfunction-Item 				PRESENCE mandatory },
	...
}
*/

struct RANfunction_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RANfunction_Item() { set(id_RANfunction_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RANfunction_Item)) { type = 1; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RANfunction_Item);} return false;
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
		void select_id_RANfunction_Item() { set(ignore); type=1;}
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
		RANfunction_Item& select_id_RANfunction_Item() { return set<RANfunction_Item>(1); }
		RANfunction_Item const* get_id_RANfunction_Item() const { return get<RANfunction_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RANfunction_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RANfunction_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RANfunction_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RANfunction_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RANfunction_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RANfunction_Item() { set(mandatory); type=1;}
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
RANfunctionID-Item ::= SEQUENCE {
	ranFunctionID				RANfunctionID,
	...
}
*/

struct RANfunctionID_Item : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "RANfunctionID-Item";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct ranFunctionID_t : RANfunctionID
	{
		static constexpr const char* name() {return "ranFunctionID_t";}
		using parent_t = RANfunctionID;

	};
	ranFunctionID_t& ref_ranFunctionID() {return ranFunctionID;}
	ranFunctionID_t const& ref_ranFunctionID() const {return ranFunctionID;}
	template<typename V> void decode(V& v)
	{
		v(ranFunctionID);

	};
	template<typename V> void encode(V& v) const
	{
		v(ranFunctionID);

	};
	void clear()
	{
		ranFunctionID.clear();

	};
	private:
	ranFunctionID_t	ranFunctionID;

};
/*
RANfunctionID-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RANfunctionID-Item			CRITICALITY ignore		TYPE RANfunctionID-Item			PRESENCE mandatory },
	...
}
*/

struct RANfunctionID_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RANfunctionID_Item() { set(id_RANfunctionID_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RANfunctionID_Item)) { type = 1; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RANfunctionID_Item);} return false;
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
		void select_id_RANfunctionID_Item() { set(ignore); type=1;}
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
		RANfunctionID_Item& select_id_RANfunctionID_Item() { return set<RANfunctionID_Item>(1); }
		RANfunctionID_Item const* get_id_RANfunctionID_Item() const { return get<RANfunctionID_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RANfunctionID_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RANfunctionID_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RANfunctionID_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RANfunctionID_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RANfunctionID_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RANfunctionID_Item() { set(mandatory); type=1;}
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
RANfunctionIDcause-Item ::= SEQUENCE {
	ranFunctionID				RANfunctionID,
	ricCause         			RICcause,
	...
}
*/

struct RANfunctionIDcause_Item : asn::sequence<2, 0, true, 0>
{
	static constexpr const char* name() {return "RANfunctionIDcause-Item";}
	using parent_t = asn::sequence<2, 0, true, 0>;
	struct ranFunctionID_t : RANfunctionID
	{
		static constexpr const char* name() {return "ranFunctionID_t";}
		using parent_t = RANfunctionID;

	};
	ranFunctionID_t& ref_ranFunctionID() {return ranFunctionID;}
	ranFunctionID_t const& ref_ranFunctionID() const {return ranFunctionID;}
	struct ricCause_t : RICcause
	{
		static constexpr const char* name() {return "ricCause_t";}
		using parent_t = RICcause;

	};
	ricCause_t& ref_ricCause() {return ricCause;}
	ricCause_t const& ref_ricCause() const {return ricCause;}
	template<typename V> void decode(V& v)
	{
		v(ranFunctionID);
		v(ricCause);

	};
	template<typename V> void encode(V& v) const
	{
		v(ranFunctionID);
		v(ricCause);

	};
	void clear()
	{
		ranFunctionID.clear();
		ricCause.clear();

	};
	private:
	ranFunctionID_t	ranFunctionID;
	ricCause_t	ricCause;

};
/*
RANfunctionIDcause-ItemIEs 	X2AP-PROTOCOL-IES ::= {
	{ ID id-RANfunctionIEcause-Item	 	CRITICALITY ignore 	TYPE RANfunctionIDcause-Item 		PRESENCE mandatory },
	...
}
*/

struct RANfunctionIDcause_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RANfunctionIEcause_Item() { set(id_RANfunctionIEcause_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RANfunctionIEcause_Item)) { type = 1; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RANfunctionIEcause_Item);} return false;
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
		void select_id_RANfunctionIEcause_Item() { set(ignore); type=1;}
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
		RANfunctionIDcause_Item& select_id_RANfunctionIEcause_Item() { return set<RANfunctionIDcause_Item>(1); }
		RANfunctionIDcause_Item const* get_id_RANfunctionIEcause_Item() const { return get<RANfunctionIDcause_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RANfunctionIDcause_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RANfunctionIDcause_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RANfunctionIEcause_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RANfunctionIDcause_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RANfunctionIDcause_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RANfunctionIEcause_Item() { set(mandatory); type=1;}
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
RANfunctions-List ::= SEQUENCE (SIZE(0..maxofRANfunctionID)) OF ProtocolIE-Single-Container { {RANfunction-ItemIEs} }
*/

struct RANfunctions_List_elm : ProtocolIE_Single_Container<RANfunction_ItemIEs>
{
	static constexpr const char* name() {return "RANfunctions_List_elm";}
	using parent_t = ProtocolIE_Single_Container<RANfunction_ItemIEs>;

};
struct RANfunctions_List : asn::sequenceof<RANfunctions_List_elm>
{
	static constexpr const char* name() {return "RANfunctions-List";}
	using parent_t = asn::sequenceof<RANfunctions_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<0,  maxofRANfunctionID >>;

};
/*
RANfunctionsID-List ::= SEQUENCE (SIZE(0..maxofRANfunctionID)) OF ProtocolIE-Single-Container{{RANfunctionID-ItemIEs}}
*/

struct RANfunctionsID_List_elm : ProtocolIE_Single_Container<RANfunctionID_ItemIEs>
{
	static constexpr const char* name() {return "RANfunctionsID_List_elm";}
	using parent_t = ProtocolIE_Single_Container<RANfunctionID_ItemIEs>;

};
struct RANfunctionsID_List : asn::sequenceof<RANfunctionsID_List_elm>
{
	static constexpr const char* name() {return "RANfunctionsID-List";}
	using parent_t = asn::sequenceof<RANfunctionsID_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<0,  maxofRANfunctionID >>;

};
/*
RANfunctionsIDcause-List ::= SEQUENCE (SIZE(0..maxofRANfunctionID)) OF ProtocolIE-Single-Container { {RANfunctionIDcause-ItemIEs} }
*/

struct RANfunctionsIDcause_List_elm : ProtocolIE_Single_Container<RANfunctionIDcause_ItemIEs>
{
	static constexpr const char* name() {return "RANfunctionsIDcause_List_elm";}
	using parent_t = ProtocolIE_Single_Container<RANfunctionIDcause_ItemIEs>;

};
struct RANfunctionsIDcause_List : asn::sequenceof<RANfunctionsIDcause_List_elm>
{
	static constexpr const char* name() {return "RANfunctionsIDcause-List";}
	using parent_t = asn::sequenceof<RANfunctionsIDcause_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<0,  maxofRANfunctionID >>;

};
/*
RICaction-Admitted-Item ::= SEQUENCE {
	ricActionID					RICactionID,
	...
}
*/

struct RICaction_Admitted_Item : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "RICaction-Admitted-Item";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct ricActionID_t : RICactionID
	{
		static constexpr const char* name() {return "ricActionID_t";}
		using parent_t = RICactionID;

	};
	ricActionID_t& ref_ricActionID() {return ricActionID;}
	ricActionID_t const& ref_ricActionID() const {return ricActionID;}
	template<typename V> void decode(V& v)
	{
		v(ricActionID);

	};
	template<typename V> void encode(V& v) const
	{
		v(ricActionID);

	};
	void clear()
	{
		ricActionID.clear();

	};
	private:
	ricActionID_t	ricActionID;

};
/*
RICaction-Admitted-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RICaction-Admitted-Item		CRITICALITY ignore		TYPE RICaction-Admitted-Item	PRESENCE mandatory },
	...
}
*/

struct RICaction_Admitted_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RICaction_Admitted_Item() { set(id_RICaction_Admitted_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RICaction_Admitted_Item)) { type = 1; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RICaction_Admitted_Item);} return false;
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
		void select_id_RICaction_Admitted_Item() { set(ignore); type=1;}
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
		RICaction_Admitted_Item& select_id_RICaction_Admitted_Item() { return set<RICaction_Admitted_Item>(1); }
		RICaction_Admitted_Item const* get_id_RICaction_Admitted_Item() const { return get<RICaction_Admitted_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RICaction_Admitted_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RICaction_Admitted_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RICaction_Admitted_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RICaction_Admitted_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RICaction_Admitted_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RICaction_Admitted_Item() { set(mandatory); type=1;}
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
RICaction-Admitted-List ::= SEQUENCE (SIZE(1..maxofRICactionID)) OF ProtocolIE-Single-Container{{RICaction-Admitted-ItemIEs}}
*/

struct RICaction_Admitted_List_elm : ProtocolIE_Single_Container<RICaction_Admitted_ItemIEs>
{
	static constexpr const char* name() {return "RICaction_Admitted_List_elm";}
	using parent_t = ProtocolIE_Single_Container<RICaction_Admitted_ItemIEs>;

};
struct RICaction_Admitted_List : asn::sequenceof<RICaction_Admitted_List_elm>
{
	static constexpr const char* name() {return "RICaction-Admitted-List";}
	using parent_t = asn::sequenceof<RICaction_Admitted_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxofRICactionID >>;

};
/*
RICaction-NotAdmitted-Item ::= SEQUENCE {
	ricActionID					RICactionID,
	ricCause					RICcause,
	...
}
*/

struct RICaction_NotAdmitted_Item : asn::sequence<2, 0, true, 0>
{
	static constexpr const char* name() {return "RICaction-NotAdmitted-Item";}
	using parent_t = asn::sequence<2, 0, true, 0>;
	struct ricActionID_t : RICactionID
	{
		static constexpr const char* name() {return "ricActionID_t";}
		using parent_t = RICactionID;

	};
	ricActionID_t& ref_ricActionID() {return ricActionID;}
	ricActionID_t const& ref_ricActionID() const {return ricActionID;}
	struct ricCause_t : RICcause
	{
		static constexpr const char* name() {return "ricCause_t";}
		using parent_t = RICcause;

	};
	ricCause_t& ref_ricCause() {return ricCause;}
	ricCause_t const& ref_ricCause() const {return ricCause;}
	template<typename V> void decode(V& v)
	{
		v(ricActionID);
		v(ricCause);

	};
	template<typename V> void encode(V& v) const
	{
		v(ricActionID);
		v(ricCause);

	};
	void clear()
	{
		ricActionID.clear();
		ricCause.clear();

	};
	private:
	ricActionID_t	ricActionID;
	ricCause_t	ricCause;

};
/*
RICaction-NotAdmitted-ItemIEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RICaction-NotAdmitted-Item	CRITICALITY ignore	TYPE RICaction-NotAdmitted-Item		PRESENCE mandatory },
	...
}
*/

struct RICaction_NotAdmitted_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RICaction_NotAdmitted_Item() { set(id_RICaction_NotAdmitted_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RICaction_NotAdmitted_Item)) { type = 1; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RICaction_NotAdmitted_Item);} return false;
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
		void select_id_RICaction_NotAdmitted_Item() { set(ignore); type=1;}
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
		RICaction_NotAdmitted_Item& select_id_RICaction_NotAdmitted_Item() { return set<RICaction_NotAdmitted_Item>(1); }
		RICaction_NotAdmitted_Item const* get_id_RICaction_NotAdmitted_Item() const { return get<RICaction_NotAdmitted_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RICaction_NotAdmitted_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RICaction_NotAdmitted_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RICaction_NotAdmitted_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RICaction_NotAdmitted_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RICaction_NotAdmitted_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RICaction_NotAdmitted_Item() { set(mandatory); type=1;}
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
RICaction-NotAdmitted-List ::= SEQUENCE (SIZE(0..maxofRICactionID)) OF ProtocolIE-Single-Container { {RICaction-NotAdmitted-ItemIEs} }
*/

struct RICaction_NotAdmitted_List_elm : ProtocolIE_Single_Container<RICaction_NotAdmitted_ItemIEs>
{
	static constexpr const char* name() {return "RICaction_NotAdmitted_List_elm";}
	using parent_t = ProtocolIE_Single_Container<RICaction_NotAdmitted_ItemIEs>;

};
struct RICaction_NotAdmitted_List : asn::sequenceof<RICaction_NotAdmitted_List_elm>
{
	static constexpr const char* name() {return "RICaction-NotAdmitted-List";}
	using parent_t = asn::sequenceof<RICaction_NotAdmitted_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<0,  maxofRICactionID >>;

};
/*
RICaction-ToBeSetup-Item ::= SEQUENCE {
	ricActionID					RICactionID,
	ricActionType		  		RICactionType,
	ricActionDefinition			RICactionDefinition 	OPTIONAL,
	ricSubsequentAction			RICsubsequentAction 	OPTIONAL,
	...
}
*/

struct RICaction_ToBeSetup_Item : asn::sequence<4, 0, true, 2>
{
	static constexpr const char* name() {return "RICaction-ToBeSetup-Item";}
	using parent_t = asn::sequence<4, 0, true, 2>;
	struct ricActionID_t : RICactionID
	{
		static constexpr const char* name() {return "ricActionID_t";}
		using parent_t = RICactionID;

	};
	ricActionID_t& ref_ricActionID() {return ricActionID;}
	ricActionID_t const& ref_ricActionID() const {return ricActionID;}
	struct ricActionType_t : RICactionType
	{
		static constexpr const char* name() {return "ricActionType_t";}
		using parent_t = RICactionType;

	};
	ricActionType_t& ref_ricActionType() {return ricActionType;}
	ricActionType_t const& ref_ricActionType() const {return ricActionType;}
	struct ricActionDefinition_t : RICactionDefinition
	{
		static constexpr const char* name() {return "ricActionDefinition_t";}
		using parent_t = RICactionDefinition;
		static constexpr bool optional = true;

	};
	ricActionDefinition_t& set_ricActionDefinition() { ricActionDefinition.setpresent(true); return ricActionDefinition;}
	ricActionDefinition_t const* get_ricActionDefinition() const {return ricActionDefinition.is_valid() ? &ricActionDefinition : nullptr;}
	struct ricSubsequentAction_t : RICsubsequentAction
	{
		static constexpr const char* name() {return "ricSubsequentAction_t";}
		using parent_t = RICsubsequentAction;
		static constexpr bool optional = true;

	};
	ricSubsequentAction_t& set_ricSubsequentAction() { ricSubsequentAction.setpresent(true); return ricSubsequentAction;}
	ricSubsequentAction_t const* get_ricSubsequentAction() const {return ricSubsequentAction.is_valid() ? &ricSubsequentAction : nullptr;}
	template<typename V> void decode(V& v)
	{
		v(ricActionID);
		v(ricActionType);
		v(ricActionDefinition);
		v(ricSubsequentAction);

	};
	template<typename V> void encode(V& v) const
	{
		v(ricActionID);
		v(ricActionType);
		v(ricActionDefinition);
		v(ricSubsequentAction);

	};
	void clear()
	{
		ricActionID.clear();
		ricActionType.clear();
		ricActionDefinition.clear();
		ricSubsequentAction.clear();

	};
	private:
	ricActionID_t	ricActionID;
	ricActionType_t	ricActionType;
	ricActionDefinition_t	ricActionDefinition;
	ricSubsequentAction_t	ricSubsequentAction;

};
/*
RICaction-ToBeSetup-ItemIEs 	X2AP-PROTOCOL-IES ::= {
	{ ID id-RICaction-ToBeSetup-Item	 CRITICALITY ignore 	TYPE RICaction-ToBeSetup-Item 	PRESENCE mandatory },
	...
}
*/

struct RICaction_ToBeSetup_ItemIEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RICaction_ToBeSetup_Item() { set(id_RICaction_ToBeSetup_Item); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RICaction_ToBeSetup_Item)) { type = 1; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RICaction_ToBeSetup_Item);} return false;
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
		void select_id_RICaction_ToBeSetup_Item() { set(ignore); type=1;}
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
		RICaction_ToBeSetup_Item& select_id_RICaction_ToBeSetup_Item() { return set<RICaction_ToBeSetup_Item>(1); }
		RICaction_ToBeSetup_Item const* get_id_RICaction_ToBeSetup_Item() const { return get<RICaction_ToBeSetup_Item>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RICaction_ToBeSetup_Item>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RICaction_ToBeSetup_Item>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RICaction_ToBeSetup_Item()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RICaction_ToBeSetup_Item>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RICaction_ToBeSetup_Item)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RICaction_ToBeSetup_Item() { set(mandatory); type=1;}
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
RICactions-ToBeSetup-List ::= SEQUENCE (SIZE(1..maxofRICactionID)) OF ProtocolIE-Single-Container { {RICaction-ToBeSetup-ItemIEs} }
*/

struct RICactions_ToBeSetup_List_elm : ProtocolIE_Single_Container<RICaction_ToBeSetup_ItemIEs>
{
	static constexpr const char* name() {return "RICactions_ToBeSetup_List_elm";}
	using parent_t = ProtocolIE_Single_Container<RICaction_ToBeSetup_ItemIEs>;

};
struct RICactions_ToBeSetup_List : asn::sequenceof<RICactions_ToBeSetup_List_elm>
{
	static constexpr const char* name() {return "RICactions-ToBeSetup-List";}
	using parent_t = asn::sequenceof<RICactions_ToBeSetup_List_elm>;
	using constraint_t = asn::constraints<false,asn::span<1,  maxofRICactionID >>;

};
/*
RICcontrolAcknowledge-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RICrequestID				CRITICALITY reject	TYPE RICrequestID					PRESENCE mandatory}|
	{ ID id-RANfunctionID				CRITICALITY reject	TYPE RANfunctionID					PRESENCE mandatory}|
	{ ID id-RICcallProcessID			CRITICALITY reject	TYPE RICcallProcessID				PRESENCE optional}|
	{ ID id-RICcontrolStatus			CRITICALITY reject	TYPE RICcontrolStatus				PRESENCE mandatory},
    ...
}
*/

struct RICcontrolAcknowledge_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(id_RICrequestID); type=1;}
		void select_id_RANfunctionID() { set(id_RANfunctionID); type=2;}
		void select_id_RICcallProcessID() { set(id_RICcallProcessID); type=3;}
		void select_id_RICcontrolStatus() { set(id_RICcontrolStatus); type=4;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RICrequestID)) { type = 1; return true; }
			else if(equal(id_RANfunctionID)) { type = 2; return true; }
			else if(equal(id_RICcallProcessID)) { type = 3; return true; }
			else if(equal(id_RICcontrolStatus)) { type = 4; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RICrequestID);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_RANfunctionID);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_RICcallProcessID);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_RICcontrolStatus);} return false;
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
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(reject); type=1;}
		void select_id_RANfunctionID() { set(reject); type=2;}
		void select_id_RICcallProcessID() { set(reject); type=3;}
		void select_id_RICcontrolStatus() { set(reject); type=4;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
			else if(equal(reject)) { type = 2; return true; }
			else if(equal(reject)) { type = 3; return true; }
			else if(equal(reject)) { type = 4; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(reject);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(reject);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(reject);} return false;
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
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		RICrequestID& select_id_RICrequestID() { return set<RICrequestID>(1); }
		RICrequestID const* get_id_RICrequestID() const { return get<RICrequestID>(1); }
		RANfunctionID& select_id_RANfunctionID() { return set<RANfunctionID>(2); }
		RANfunctionID const* get_id_RANfunctionID() const { return get<RANfunctionID>(2); }
		RICcallProcessID& select_id_RICcallProcessID() { return set<RICcallProcessID>(3); }
		RICcallProcessID const* get_id_RICcallProcessID() const { return get<RICcallProcessID>(3); }
		RICcontrolStatus& select_id_RICcontrolStatus() { return set<RICcontrolStatus>(4); }
		RICcontrolStatus const* get_id_RICcontrolStatus() const { return get<RICcontrolStatus>(4); }
		bool is_unknown() const { return type == 5; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RICrequestID>(); break;
			case 2: var.destroy<RANfunctionID>(); break;
			case 3: var.destroy<RICcallProcessID>(); break;
			case 4: var.destroy<RICcontrolStatus>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RICrequestID>(1);
			v.template operator()<RANfunctionID>(2);
			v.template operator()<RICcallProcessID>(3);
			v.template operator()<RICcontrolStatus>(4);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RICrequestID()); return true;
			case 2: v(select_id_RANfunctionID()); return true;
			case 3: v(select_id_RICcallProcessID()); return true;
			case 4: v(select_id_RICcontrolStatus()); return true;
			case 5: if(type != 5) {clear(); asn::base::set();} type = 5; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RICrequestID>()); return true;
			case 2: v(var.as<RANfunctionID>()); return true;
			case 3: v(var.as<RICcallProcessID>()); return true;
			case 4: v(var.as<RICcontrolStatus>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RANfunctionID)];
			char dummy2[sizeof(RICcallProcessID)];
			char dummy3[sizeof(RICcontrolStatus)];
			char dummy4[sizeof(RICrequestID)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(mandatory); type=1;}
		void select_id_RANfunctionID() { set(mandatory); type=2;}
		void select_id_RICcallProcessID() { set(optional); type=3;}
		void select_id_RICcontrolStatus() { set(mandatory); type=4;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else if(equal(mandatory)) { type = 2; return true; }
			else if(equal(optional)) { type = 3; return true; }
			else if(equal(mandatory)) { type = 4; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(optional);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(mandatory);} return false;
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
RICcontrolAcknowledge ::= SEQUENCE {
	protocolIEs					ProtocolIE-Container	{{RICcontrolAcknowledge-IEs}},
	...
}
*/

struct RICcontrolAcknowledge : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "RICcontrolAcknowledge";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<RICcontrolAcknowledge_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<RICcontrolAcknowledge_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
RICcontrolFailure-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RICrequestID				CRITICALITY reject	TYPE RICrequestID					PRESENCE mandatory}|
	{ ID id-RANfunctionID				CRITICALITY reject	TYPE RANfunctionID					PRESENCE mandatory}|
	{ ID id-RICcallProcessID			CRITICALITY reject	TYPE RICcallProcessID				PRESENCE optional}|
	{ ID id-RICcause				    CRITICALITY reject	TYPE RICcause				        PRESENCE mandatory},
    ...
}
*/

struct RICcontrolFailure_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(id_RICrequestID); type=1;}
		void select_id_RANfunctionID() { set(id_RANfunctionID); type=2;}
		void select_id_RICcallProcessID() { set(id_RICcallProcessID); type=3;}
		void select_id_RICcause() { set(id_RICcause); type=4;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RICrequestID)) { type = 1; return true; }
			else if(equal(id_RANfunctionID)) { type = 2; return true; }
			else if(equal(id_RICcallProcessID)) { type = 3; return true; }
			else if(equal(id_RICcause)) { type = 4; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RICrequestID);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_RANfunctionID);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_RICcallProcessID);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_RICcause);} return false;
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
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(reject); type=1;}
		void select_id_RANfunctionID() { set(reject); type=2;}
		void select_id_RICcallProcessID() { set(reject); type=3;}
		void select_id_RICcause() { set(reject); type=4;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
			else if(equal(reject)) { type = 2; return true; }
			else if(equal(reject)) { type = 3; return true; }
			else if(equal(reject)) { type = 4; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(reject);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(reject);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(reject);} return false;
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
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		RICrequestID& select_id_RICrequestID() { return set<RICrequestID>(1); }
		RICrequestID const* get_id_RICrequestID() const { return get<RICrequestID>(1); }
		RANfunctionID& select_id_RANfunctionID() { return set<RANfunctionID>(2); }
		RANfunctionID const* get_id_RANfunctionID() const { return get<RANfunctionID>(2); }
		RICcallProcessID& select_id_RICcallProcessID() { return set<RICcallProcessID>(3); }
		RICcallProcessID const* get_id_RICcallProcessID() const { return get<RICcallProcessID>(3); }
		RICcause& select_id_RICcause() { return set<RICcause>(4); }
		RICcause const* get_id_RICcause() const { return get<RICcause>(4); }
		bool is_unknown() const { return type == 5; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RICrequestID>(); break;
			case 2: var.destroy<RANfunctionID>(); break;
			case 3: var.destroy<RICcallProcessID>(); break;
			case 4: var.destroy<RICcause>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RICrequestID>(1);
			v.template operator()<RANfunctionID>(2);
			v.template operator()<RICcallProcessID>(3);
			v.template operator()<RICcause>(4);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RICrequestID()); return true;
			case 2: v(select_id_RANfunctionID()); return true;
			case 3: v(select_id_RICcallProcessID()); return true;
			case 4: v(select_id_RICcause()); return true;
			case 5: if(type != 5) {clear(); asn::base::set();} type = 5; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RICrequestID>()); return true;
			case 2: v(var.as<RANfunctionID>()); return true;
			case 3: v(var.as<RICcallProcessID>()); return true;
			case 4: v(var.as<RICcause>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RANfunctionID)];
			char dummy2[sizeof(RICcallProcessID)];
			char dummy3[sizeof(RICcause)];
			char dummy4[sizeof(RICrequestID)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(mandatory); type=1;}
		void select_id_RANfunctionID() { set(mandatory); type=2;}
		void select_id_RICcallProcessID() { set(optional); type=3;}
		void select_id_RICcause() { set(mandatory); type=4;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else if(equal(mandatory)) { type = 2; return true; }
			else if(equal(optional)) { type = 3; return true; }
			else if(equal(mandatory)) { type = 4; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(optional);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(mandatory);} return false;
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
RICcontrolFailure ::= SEQUENCE {
	protocolIEs					ProtocolIE-Container	{{RICcontrolFailure-IEs}},
	...
}
*/

struct RICcontrolFailure : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "RICcontrolFailure";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<RICcontrolFailure_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<RICcontrolFailure_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
RICcontrolRequest-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RICrequestID				CRITICALITY reject	TYPE RICrequestID					PRESENCE mandatory}|
	{ ID id-RANfunctionID				CRITICALITY reject	TYPE RANfunctionID					PRESENCE mandatory}|
	{ ID id-RICcallProcessID			CRITICALITY reject	TYPE RICcallProcessID				PRESENCE optional}|
	{ ID id-RICcontrolHeader			CRITICALITY reject	TYPE RICcontrolHeader				PRESENCE mandatory}|
	{ ID id-RICcontrolMessage			CRITICALITY reject	TYPE RICcontrolMessage				PRESENCE mandatory}|
    { ID id-RICcontrolAckRequest		CRITICALITY reject	TYPE RICcontrolAckRequest     		PRESENCE optional},
    ...
}
*/

struct RICcontrolRequest_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 7; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(id_RICrequestID); type=1;}
		void select_id_RANfunctionID() { set(id_RANfunctionID); type=2;}
		void select_id_RICcallProcessID() { set(id_RICcallProcessID); type=3;}
		void select_id_RICcontrolHeader() { set(id_RICcontrolHeader); type=4;}
		void select_id_RICcontrolMessage() { set(id_RICcontrolMessage); type=5;}
		void select_id_RICcontrolAckRequest() { set(id_RICcontrolAckRequest); type=6;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RICrequestID)) { type = 1; return true; }
			else if(equal(id_RANfunctionID)) { type = 2; return true; }
			else if(equal(id_RICcallProcessID)) { type = 3; return true; }
			else if(equal(id_RICcontrolHeader)) { type = 4; return true; }
			else if(equal(id_RICcontrolMessage)) { type = 5; return true; }
			else if(equal(id_RICcontrolAckRequest)) { type = 6; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RICrequestID);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_RANfunctionID);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_RICcallProcessID);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_RICcontrolHeader);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(id_RICcontrolMessage);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(id_RICcontrolAckRequest);} return false;
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
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 7; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(reject); type=1;}
		void select_id_RANfunctionID() { set(reject); type=2;}
		void select_id_RICcallProcessID() { set(reject); type=3;}
		void select_id_RICcontrolHeader() { set(reject); type=4;}
		void select_id_RICcontrolMessage() { set(reject); type=5;}
		void select_id_RICcontrolAckRequest() { set(reject); type=6;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
			else if(equal(reject)) { type = 2; return true; }
			else if(equal(reject)) { type = 3; return true; }
			else if(equal(reject)) { type = 4; return true; }
			else if(equal(reject)) { type = 5; return true; }
			else if(equal(reject)) { type = 6; return true; }
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
			case 5: type = 5; if(v(ref_nested())) { return equal(reject);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(reject);} return false;
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
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		RICrequestID& select_id_RICrequestID() { return set<RICrequestID>(1); }
		RICrequestID const* get_id_RICrequestID() const { return get<RICrequestID>(1); }
		RANfunctionID& select_id_RANfunctionID() { return set<RANfunctionID>(2); }
		RANfunctionID const* get_id_RANfunctionID() const { return get<RANfunctionID>(2); }
		RICcallProcessID& select_id_RICcallProcessID() { return set<RICcallProcessID>(3); }
		RICcallProcessID const* get_id_RICcallProcessID() const { return get<RICcallProcessID>(3); }
		RICcontrolHeader& select_id_RICcontrolHeader() { return set<RICcontrolHeader>(4); }
		RICcontrolHeader const* get_id_RICcontrolHeader() const { return get<RICcontrolHeader>(4); }
		RICcontrolMessage& select_id_RICcontrolMessage() { return set<RICcontrolMessage>(5); }
		RICcontrolMessage const* get_id_RICcontrolMessage() const { return get<RICcontrolMessage>(5); }
		RICcontrolAckRequest& select_id_RICcontrolAckRequest() { return set<RICcontrolAckRequest>(6); }
		RICcontrolAckRequest const* get_id_RICcontrolAckRequest() const { return get<RICcontrolAckRequest>(6); }
		bool is_unknown() const { return type == 7; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RICrequestID>(); break;
			case 2: var.destroy<RANfunctionID>(); break;
			case 3: var.destroy<RICcallProcessID>(); break;
			case 4: var.destroy<RICcontrolHeader>(); break;
			case 5: var.destroy<RICcontrolMessage>(); break;
			case 6: var.destroy<RICcontrolAckRequest>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RICrequestID>(1);
			v.template operator()<RANfunctionID>(2);
			v.template operator()<RICcallProcessID>(3);
			v.template operator()<RICcontrolHeader>(4);
			v.template operator()<RICcontrolMessage>(5);
			v.template operator()<RICcontrolAckRequest>(6);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RICrequestID()); return true;
			case 2: v(select_id_RANfunctionID()); return true;
			case 3: v(select_id_RICcallProcessID()); return true;
			case 4: v(select_id_RICcontrolHeader()); return true;
			case 5: v(select_id_RICcontrolMessage()); return true;
			case 6: v(select_id_RICcontrolAckRequest()); return true;
			case 7: if(type != 7) {clear(); asn::base::set();} type = 7; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RICrequestID>()); return true;
			case 2: v(var.as<RANfunctionID>()); return true;
			case 3: v(var.as<RICcallProcessID>()); return true;
			case 4: v(var.as<RICcontrolHeader>()); return true;
			case 5: v(var.as<RICcontrolMessage>()); return true;
			case 6: v(var.as<RICcontrolAckRequest>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RANfunctionID)];
			char dummy2[sizeof(RICcallProcessID)];
			char dummy3[sizeof(RICcontrolAckRequest)];
			char dummy4[sizeof(RICcontrolHeader)];
			char dummy5[sizeof(RICcontrolMessage)];
			char dummy6[sizeof(RICrequestID)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 7; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(mandatory); type=1;}
		void select_id_RANfunctionID() { set(mandatory); type=2;}
		void select_id_RICcallProcessID() { set(optional); type=3;}
		void select_id_RICcontrolHeader() { set(mandatory); type=4;}
		void select_id_RICcontrolMessage() { set(mandatory); type=5;}
		void select_id_RICcontrolAckRequest() { set(optional); type=6;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else if(equal(mandatory)) { type = 2; return true; }
			else if(equal(optional)) { type = 3; return true; }
			else if(equal(mandatory)) { type = 4; return true; }
			else if(equal(mandatory)) { type = 5; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(optional);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(mandatory);} return false;
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
RICcontrolRequest ::= SEQUENCE {
	protocolIEs					ProtocolIE-Container	{{RICcontrolRequest-IEs}},
	...
}
*/

struct RICcontrolRequest : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "RICcontrolRequest";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<RICcontrolRequest_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<RICcontrolRequest_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
RICindication-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RICrequestID				CRITICALITY reject	TYPE RICrequestID					PRESENCE mandatory}|
	{ ID id-RANfunctionID				CRITICALITY reject	TYPE RANfunctionID					PRESENCE mandatory}|
	{ ID id-RICactionID					CRITICALITY reject	TYPE RICactionID					PRESENCE mandatory}|
	{ ID id-RICindicationSN				CRITICALITY reject	TYPE RICindicationSN				PRESENCE mandatory}|
    { ID id-RICindicationType			CRITICALITY reject	TYPE RICindicationType  			PRESENCE mandatory}|
	{ ID id-RICindicationHeader			CRITICALITY reject	TYPE RICindicationHeader			PRESENCE mandatory}|
	{ ID id-RICindicationMessage		CRITICALITY reject	TYPE RICindicationMessage           PRESENCE mandatory} |
	{ ID id-RICcallProcessID			CRITICALITY reject	TYPE RICcallProcessID				PRESENCE optional},
    ...
}
*/

struct RICindication_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 9; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(id_RICrequestID); type=1;}
		void select_id_RANfunctionID() { set(id_RANfunctionID); type=2;}
		void select_id_RICactionID() { set(id_RICactionID); type=3;}
		void select_id_RICindicationSN() { set(id_RICindicationSN); type=4;}
		void select_id_RICindicationType() { set(id_RICindicationType); type=5;}
		void select_id_RICindicationHeader() { set(id_RICindicationHeader); type=6;}
		void select_id_RICindicationMessage() { set(id_RICindicationMessage); type=7;}
		void select_id_RICcallProcessID() { set(id_RICcallProcessID); type=8;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RICrequestID)) { type = 1; return true; }
			else if(equal(id_RANfunctionID)) { type = 2; return true; }
			else if(equal(id_RICactionID)) { type = 3; return true; }
			else if(equal(id_RICindicationSN)) { type = 4; return true; }
			else if(equal(id_RICindicationType)) { type = 5; return true; }
			else if(equal(id_RICindicationHeader)) { type = 6; return true; }
			else if(equal(id_RICindicationMessage)) { type = 7; return true; }
			else if(equal(id_RICcallProcessID)) { type = 8; return true; }
			else { type = 9; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RICrequestID);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_RANfunctionID);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_RICactionID);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_RICindicationSN);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(id_RICindicationType);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(id_RICindicationHeader);} return false;
			case 7: type = 7; if(v(ref_nested())) { return equal(id_RICindicationMessage);} return false;
			case 8: type = 8; if(v(ref_nested())) { return equal(id_RICcallProcessID);} return false;
			case 9: type = 9; return v(ref_nested());
			ref_nested().clear();
			}
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
		bool is_unknown() const { return type == 9; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(reject); type=1;}
		void select_id_RANfunctionID() { set(reject); type=2;}
		void select_id_RICactionID() { set(reject); type=3;}
		void select_id_RICindicationSN() { set(reject); type=4;}
		void select_id_RICindicationType() { set(reject); type=5;}
		void select_id_RICindicationHeader() { set(reject); type=6;}
		void select_id_RICindicationMessage() { set(reject); type=7;}
		void select_id_RICcallProcessID() { set(reject); type=8;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
			else if(equal(reject)) { type = 2; return true; }
			else if(equal(reject)) { type = 3; return true; }
			else if(equal(reject)) { type = 4; return true; }
			else if(equal(reject)) { type = 5; return true; }
			else if(equal(reject)) { type = 6; return true; }
			else if(equal(reject)) { type = 7; return true; }
			else if(equal(reject)) { type = 8; return true; }
			else { type = 9; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
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
			case 5: type = 5; if(v(ref_nested())) { return equal(reject);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(reject);} return false;
			case 7: type = 7; if(v(ref_nested())) { return equal(reject);} return false;
			case 8: type = 8; if(v(ref_nested())) { return equal(reject);} return false;
			case 9: type = 9; return v(ref_nested());
			ref_nested().clear();
			}
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
		RICrequestID& select_id_RICrequestID() { return set<RICrequestID>(1); }
		RICrequestID const* get_id_RICrequestID() const { return get<RICrequestID>(1); }
		RANfunctionID& select_id_RANfunctionID() { return set<RANfunctionID>(2); }
		RANfunctionID const* get_id_RANfunctionID() const { return get<RANfunctionID>(2); }
		RICactionID& select_id_RICactionID() { return set<RICactionID>(3); }
		RICactionID const* get_id_RICactionID() const { return get<RICactionID>(3); }
		RICindicationSN& select_id_RICindicationSN() { return set<RICindicationSN>(4); }
		RICindicationSN const* get_id_RICindicationSN() const { return get<RICindicationSN>(4); }
		RICindicationType& select_id_RICindicationType() { return set<RICindicationType>(5); }
		RICindicationType const* get_id_RICindicationType() const { return get<RICindicationType>(5); }
		RICindicationHeader& select_id_RICindicationHeader() { return set<RICindicationHeader>(6); }
		RICindicationHeader const* get_id_RICindicationHeader() const { return get<RICindicationHeader>(6); }
		RICindicationMessage& select_id_RICindicationMessage() { return set<RICindicationMessage>(7); }
		RICindicationMessage const* get_id_RICindicationMessage() const { return get<RICindicationMessage>(7); }
		RICcallProcessID& select_id_RICcallProcessID() { return set<RICcallProcessID>(8); }
		RICcallProcessID const* get_id_RICcallProcessID() const { return get<RICcallProcessID>(8); }
		bool is_unknown() const { return type == 9; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RICrequestID>(); break;
			case 2: var.destroy<RANfunctionID>(); break;
			case 3: var.destroy<RICactionID>(); break;
			case 4: var.destroy<RICindicationSN>(); break;
			case 5: var.destroy<RICindicationType>(); break;
			case 6: var.destroy<RICindicationHeader>(); break;
			case 7: var.destroy<RICindicationMessage>(); break;
			case 8: var.destroy<RICcallProcessID>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RICrequestID>(1);
			v.template operator()<RANfunctionID>(2);
			v.template operator()<RICactionID>(3);
			v.template operator()<RICindicationSN>(4);
			v.template operator()<RICindicationType>(5);
			v.template operator()<RICindicationHeader>(6);
			v.template operator()<RICindicationMessage>(7);
			v.template operator()<RICcallProcessID>(8);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RICrequestID()); return true;
			case 2: v(select_id_RANfunctionID()); return true;
			case 3: v(select_id_RICactionID()); return true;
			case 4: v(select_id_RICindicationSN()); return true;
			case 5: v(select_id_RICindicationType()); return true;
			case 6: v(select_id_RICindicationHeader()); return true;
			case 7: v(select_id_RICindicationMessage()); return true;
			case 8: v(select_id_RICcallProcessID()); return true;
			case 9: if(type != 9) {clear(); asn::base::set();} type = 9; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RICrequestID>()); return true;
			case 2: v(var.as<RANfunctionID>()); return true;
			case 3: v(var.as<RICactionID>()); return true;
			case 4: v(var.as<RICindicationSN>()); return true;
			case 5: v(var.as<RICindicationType>()); return true;
			case 6: v(var.as<RICindicationHeader>()); return true;
			case 7: v(var.as<RICindicationMessage>()); return true;
			case 8: v(var.as<RICcallProcessID>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RANfunctionID)];
			char dummy2[sizeof(RICactionID)];
			char dummy3[sizeof(RICcallProcessID)];
			char dummy4[sizeof(RICindicationHeader)];
			char dummy5[sizeof(RICindicationMessage)];
			char dummy6[sizeof(RICindicationSN)];
			char dummy7[sizeof(RICindicationType)];
			char dummy8[sizeof(RICrequestID)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 9; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(mandatory); type=1;}
		void select_id_RANfunctionID() { set(mandatory); type=2;}
		void select_id_RICactionID() { set(mandatory); type=3;}
		void select_id_RICindicationSN() { set(mandatory); type=4;}
		void select_id_RICindicationType() { set(mandatory); type=5;}
		void select_id_RICindicationHeader() { set(mandatory); type=6;}
		void select_id_RICindicationMessage() { set(mandatory); type=7;}
		void select_id_RICcallProcessID() { set(optional); type=8;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else if(equal(mandatory)) { type = 2; return true; }
			else if(equal(mandatory)) { type = 3; return true; }
			else if(equal(mandatory)) { type = 4; return true; }
			else if(equal(mandatory)) { type = 5; return true; }
			else if(equal(mandatory)) { type = 6; return true; }
			else if(equal(mandatory)) { type = 7; return true; }
			else if(equal(optional)) { type = 8; return true; }
			else { type = 9; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
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
			case 2: type = 2; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 7: type = 7; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 8: type = 8; if(v(ref_nested())) { return equal(optional);} return false;
			case 9: type = 9; return v(ref_nested());
			ref_nested().clear();
			}
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
RICindication ::= SEQUENCE {
	protocolIEs					ProtocolIE-Container	{{RICindication-IEs}},
	...
}
*/

struct RICindication : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "RICindication";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<RICindication_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<RICindication_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
RICserviceQuery-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RANfunctionsAccepted		CRITICALITY reject	TYPE RANfunctionsID-List			PRESENCE optional},
	...
}
*/

struct RICserviceQuery_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RANfunctionsAccepted() { set(id_RANfunctionsAccepted); type=1;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RANfunctionsAccepted)) { type = 1; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RANfunctionsAccepted);} return false;
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
		void select_id_RANfunctionsAccepted() { set(reject); type=1;}
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
		RANfunctionsID_List& select_id_RANfunctionsAccepted() { return set<RANfunctionsID_List>(1); }
		RANfunctionsID_List const* get_id_RANfunctionsAccepted() const { return get<RANfunctionsID_List>(1); }
		bool is_unknown() const { return type == 2; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RANfunctionsID_List>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RANfunctionsID_List>(1);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RANfunctionsAccepted()); return true;
			case 2: if(type != 2) {clear(); asn::base::set();} type = 2; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RANfunctionsID_List>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RANfunctionsID_List)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 2; }
		void clear() {type = 0;}
		void select_id_RANfunctionsAccepted() { set(optional); type=1;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
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
RICserviceQuery ::= SEQUENCE {
	protocolIEs					ProtocolIE-Container	{{RICserviceQuery-IEs}},
	...
}
*/

struct RICserviceQuery : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "RICserviceQuery";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<RICserviceQuery_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<RICserviceQuery_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
RICserviceUpdate-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RANfunctionsAdded			CRITICALITY reject	TYPE RANfunctions-List		     	PRESENCE optional}|
	{ ID id-RANfunctionsModified		CRITICALITY reject	TYPE RANfunctions-List		        PRESENCE optional}|
    { ID id-RANfunctionsDeleted			CRITICALITY reject	TYPE RANfunctionsID-List	        PRESENCE optional},
	...
}
*/

struct RICserviceUpdate_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_RANfunctionsAdded() { set(id_RANfunctionsAdded); type=1;}
		void select_id_RANfunctionsModified() { set(id_RANfunctionsModified); type=2;}
		void select_id_RANfunctionsDeleted() { set(id_RANfunctionsDeleted); type=3;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RANfunctionsAdded)) { type = 1; return true; }
			else if(equal(id_RANfunctionsModified)) { type = 2; return true; }
			else if(equal(id_RANfunctionsDeleted)) { type = 3; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RANfunctionsAdded);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_RANfunctionsModified);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_RANfunctionsDeleted);} return false;
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
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_RANfunctionsAdded() { set(reject); type=1;}
		void select_id_RANfunctionsModified() { set(reject); type=2;}
		void select_id_RANfunctionsDeleted() { set(reject); type=3;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
			else if(equal(reject)) { type = 2; return true; }
			else if(equal(reject)) { type = 3; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(reject);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(reject);} return false;
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
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		RANfunctions_List& select_id_RANfunctionsAdded() { return set<RANfunctions_List>(1); }
		RANfunctions_List const* get_id_RANfunctionsAdded() const { return get<RANfunctions_List>(1); }
		RANfunctions_List& select_id_RANfunctionsModified() { return set<RANfunctions_List>(2); }
		RANfunctions_List const* get_id_RANfunctionsModified() const { return get<RANfunctions_List>(2); }
		RANfunctionsID_List& select_id_RANfunctionsDeleted() { return set<RANfunctionsID_List>(3); }
		RANfunctionsID_List const* get_id_RANfunctionsDeleted() const { return get<RANfunctionsID_List>(3); }
		bool is_unknown() const { return type == 4; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RANfunctions_List>(); break;
			case 2: var.destroy<RANfunctions_List>(); break;
			case 3: var.destroy<RANfunctionsID_List>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RANfunctions_List>(1);
			v.template operator()<RANfunctions_List>(2);
			v.template operator()<RANfunctionsID_List>(3);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RANfunctionsAdded()); return true;
			case 2: v(select_id_RANfunctionsModified()); return true;
			case 3: v(select_id_RANfunctionsDeleted()); return true;
			case 4: if(type != 4) {clear(); asn::base::set();} type = 4; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RANfunctions_List>()); return true;
			case 2: v(var.as<RANfunctions_List>()); return true;
			case 3: v(var.as<RANfunctionsID_List>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RANfunctionsID_List)];
			char dummy2[sizeof(RANfunctions_List)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_RANfunctionsAdded() { set(optional); type=1;}
		void select_id_RANfunctionsModified() { set(optional); type=2;}
		void select_id_RANfunctionsDeleted() { set(optional); type=3;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
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
RICserviceUpdate ::= SEQUENCE {
	protocolIEs					ProtocolIE-Container	{{RICserviceUpdate-IEs}},
	...
}
*/

struct RICserviceUpdate : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "RICserviceUpdate";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<RICserviceUpdate_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<RICserviceUpdate_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
RICserviceUpdateAcknowledge-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RANfunctionsAccepted		CRITICALITY reject	TYPE RANfunctionsID-List			PRESENCE optional}|
	{ ID id-RANfunctionsRejected		CRITICALITY reject	TYPE RANfunctionsIDcause-List		PRESENCE optional},
	...
}
*/

struct RICserviceUpdateAcknowledge_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_RANfunctionsAccepted() { set(id_RANfunctionsAccepted); type=1;}
		void select_id_RANfunctionsRejected() { set(id_RANfunctionsRejected); type=2;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RANfunctionsAccepted)) { type = 1; return true; }
			else if(equal(id_RANfunctionsRejected)) { type = 2; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RANfunctionsAccepted);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_RANfunctionsRejected);} return false;
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
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_RANfunctionsAccepted() { set(reject); type=1;}
		void select_id_RANfunctionsRejected() { set(reject); type=2;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
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
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		RANfunctionsID_List& select_id_RANfunctionsAccepted() { return set<RANfunctionsID_List>(1); }
		RANfunctionsID_List const* get_id_RANfunctionsAccepted() const { return get<RANfunctionsID_List>(1); }
		RANfunctionsIDcause_List& select_id_RANfunctionsRejected() { return set<RANfunctionsIDcause_List>(2); }
		RANfunctionsIDcause_List const* get_id_RANfunctionsRejected() const { return get<RANfunctionsIDcause_List>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RANfunctionsID_List>(); break;
			case 2: var.destroy<RANfunctionsIDcause_List>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RANfunctionsID_List>(1);
			v.template operator()<RANfunctionsIDcause_List>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RANfunctionsAccepted()); return true;
			case 2: v(select_id_RANfunctionsRejected()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RANfunctionsID_List>()); return true;
			case 2: v(var.as<RANfunctionsIDcause_List>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RANfunctionsID_List)];
			char dummy2[sizeof(RANfunctionsIDcause_List)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_RANfunctionsAccepted() { set(optional); type=1;}
		void select_id_RANfunctionsRejected() { set(optional); type=2;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
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
RICserviceUpdateAcknowledge ::= SEQUENCE {
	protocolIEs					ProtocolIE-Container	{{RICserviceUpdateAcknowledge-IEs}},
	...
}
*/

struct RICserviceUpdateAcknowledge : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "RICserviceUpdateAcknowledge";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<RICserviceUpdateAcknowledge_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<RICserviceUpdateAcknowledge_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
RICserviceUpdateFailure-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RANfunctionsRejected		CRITICALITY reject	TYPE RANfunctionsIDcause-List		PRESENCE optional}|
	{ ID id-TimeToWait					CRITICALITY ignore	TYPE TimeToWait						PRESENCE optional}|
    { ID id-CriticalityDiagnostics		CRITICALITY ignore	TYPE CriticalityDiagnostics			PRESENCE optional},
	...
}
*/

struct RICserviceUpdateFailure_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_RANfunctionsRejected() { set(id_RANfunctionsRejected); type=1;}
		void select_id_TimeToWait() { set(id_TimeToWait); type=2;}
		void select_id_CriticalityDiagnostics() { set(id_CriticalityDiagnostics); type=3;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RANfunctionsRejected)) { type = 1; return true; }
			else if(equal(id_TimeToWait)) { type = 2; return true; }
			else if(equal(id_CriticalityDiagnostics)) { type = 3; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RANfunctionsRejected);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_TimeToWait);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_CriticalityDiagnostics);} return false;
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
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_RANfunctionsRejected() { set(reject); type=1;}
		void select_id_TimeToWait() { set(ignore); type=2;}
		void select_id_CriticalityDiagnostics() { set(ignore); type=3;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
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
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		RANfunctionsIDcause_List& select_id_RANfunctionsRejected() { return set<RANfunctionsIDcause_List>(1); }
		RANfunctionsIDcause_List const* get_id_RANfunctionsRejected() const { return get<RANfunctionsIDcause_List>(1); }
		TimeToWait& select_id_TimeToWait() { return set<TimeToWait>(2); }
		TimeToWait const* get_id_TimeToWait() const { return get<TimeToWait>(2); }
		CriticalityDiagnostics& select_id_CriticalityDiagnostics() { return set<CriticalityDiagnostics>(3); }
		CriticalityDiagnostics const* get_id_CriticalityDiagnostics() const { return get<CriticalityDiagnostics>(3); }
		bool is_unknown() const { return type == 4; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RANfunctionsIDcause_List>(); break;
			case 2: var.destroy<TimeToWait>(); break;
			case 3: var.destroy<CriticalityDiagnostics>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RANfunctionsIDcause_List>(1);
			v.template operator()<TimeToWait>(2);
			v.template operator()<CriticalityDiagnostics>(3);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RANfunctionsRejected()); return true;
			case 2: v(select_id_TimeToWait()); return true;
			case 3: v(select_id_CriticalityDiagnostics()); return true;
			case 4: if(type != 4) {clear(); asn::base::set();} type = 4; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RANfunctionsIDcause_List>()); return true;
			case 2: v(var.as<TimeToWait>()); return true;
			case 3: v(var.as<CriticalityDiagnostics>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(CriticalityDiagnostics)];
			char dummy2[sizeof(RANfunctionsIDcause_List)];
			char dummy3[sizeof(TimeToWait)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_RANfunctionsRejected() { set(optional); type=1;}
		void select_id_TimeToWait() { set(optional); type=2;}
		void select_id_CriticalityDiagnostics() { set(optional); type=3;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
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
RICserviceUpdateFailure ::= SEQUENCE {
	protocolIEs			ProtocolIE-Container	{{RICserviceUpdateFailure-IEs}},
	...
}
*/

struct RICserviceUpdateFailure : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "RICserviceUpdateFailure";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<RICserviceUpdateFailure_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<RICserviceUpdateFailure_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
RICsubscription ::= SEQUENCE {
	ricEventTriggerDefinition	RICeventTriggerDefinition,
	ricAction-ToBeSetup-List	RICactions-ToBeSetup-List,
	...
}
*/

struct RICsubscription : asn::sequence<2, 0, true, 0>
{
	static constexpr const char* name() {return "RICsubscription";}
	using parent_t = asn::sequence<2, 0, true, 0>;
	struct ricEventTriggerDefinition_t : RICeventTriggerDefinition
	{
		static constexpr const char* name() {return "ricEventTriggerDefinition_t";}
		using parent_t = RICeventTriggerDefinition;

	};
	ricEventTriggerDefinition_t& ref_ricEventTriggerDefinition() {return ricEventTriggerDefinition;}
	ricEventTriggerDefinition_t const& ref_ricEventTriggerDefinition() const {return ricEventTriggerDefinition;}
	struct ricAction_ToBeSetup_List_t : RICactions_ToBeSetup_List
	{
		static constexpr const char* name() {return "ricAction_ToBeSetup_List_t";}
		using parent_t = RICactions_ToBeSetup_List;

	};
	ricAction_ToBeSetup_List_t& ref_ricAction_ToBeSetup_List() {return ricAction_ToBeSetup_List;}
	ricAction_ToBeSetup_List_t const& ref_ricAction_ToBeSetup_List() const {return ricAction_ToBeSetup_List;}
	template<typename V> void decode(V& v)
	{
		v(ricEventTriggerDefinition);
		v(ricAction_ToBeSetup_List);

	};
	template<typename V> void encode(V& v) const
	{
		v(ricEventTriggerDefinition);
		v(ricAction_ToBeSetup_List);

	};
	void clear()
	{
		ricEventTriggerDefinition.clear();
		ricAction_ToBeSetup_List.clear();

	};
	private:
	ricEventTriggerDefinition_t	ricEventTriggerDefinition;
	ricAction_ToBeSetup_List_t	ricAction_ToBeSetup_List;

};
/*
RICsubscriptionDeleteFailure-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RICrequestID				CRITICALITY reject	TYPE RICrequestID					PRESENCE mandatory}|
	{ ID id-RANfunctionID				CRITICALITY reject	TYPE RANfunctionID					PRESENCE mandatory}|
    { ID id-RICcause					CRITICALITY reject	TYPE RICcause						PRESENCE mandatory}|
    { ID id-CriticalityDiagnostics		CRITICALITY ignore	TYPE CriticalityDiagnostics			PRESENCE optional},
    ...
}
*/

struct RICsubscriptionDeleteFailure_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(id_RICrequestID); type=1;}
		void select_id_RANfunctionID() { set(id_RANfunctionID); type=2;}
		void select_id_RICcause() { set(id_RICcause); type=3;}
		void select_id_CriticalityDiagnostics() { set(id_CriticalityDiagnostics); type=4;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RICrequestID)) { type = 1; return true; }
			else if(equal(id_RANfunctionID)) { type = 2; return true; }
			else if(equal(id_RICcause)) { type = 3; return true; }
			else if(equal(id_CriticalityDiagnostics)) { type = 4; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RICrequestID);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_RANfunctionID);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_RICcause);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_CriticalityDiagnostics);} return false;
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
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(reject); type=1;}
		void select_id_RANfunctionID() { set(reject); type=2;}
		void select_id_RICcause() { set(reject); type=3;}
		void select_id_CriticalityDiagnostics() { set(ignore); type=4;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
			else if(equal(reject)) { type = 2; return true; }
			else if(equal(reject)) { type = 3; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(reject);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(reject);} return false;
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
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		RICrequestID& select_id_RICrequestID() { return set<RICrequestID>(1); }
		RICrequestID const* get_id_RICrequestID() const { return get<RICrequestID>(1); }
		RANfunctionID& select_id_RANfunctionID() { return set<RANfunctionID>(2); }
		RANfunctionID const* get_id_RANfunctionID() const { return get<RANfunctionID>(2); }
		RICcause& select_id_RICcause() { return set<RICcause>(3); }
		RICcause const* get_id_RICcause() const { return get<RICcause>(3); }
		CriticalityDiagnostics& select_id_CriticalityDiagnostics() { return set<CriticalityDiagnostics>(4); }
		CriticalityDiagnostics const* get_id_CriticalityDiagnostics() const { return get<CriticalityDiagnostics>(4); }
		bool is_unknown() const { return type == 5; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RICrequestID>(); break;
			case 2: var.destroy<RANfunctionID>(); break;
			case 3: var.destroy<RICcause>(); break;
			case 4: var.destroy<CriticalityDiagnostics>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RICrequestID>(1);
			v.template operator()<RANfunctionID>(2);
			v.template operator()<RICcause>(3);
			v.template operator()<CriticalityDiagnostics>(4);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RICrequestID()); return true;
			case 2: v(select_id_RANfunctionID()); return true;
			case 3: v(select_id_RICcause()); return true;
			case 4: v(select_id_CriticalityDiagnostics()); return true;
			case 5: if(type != 5) {clear(); asn::base::set();} type = 5; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RICrequestID>()); return true;
			case 2: v(var.as<RANfunctionID>()); return true;
			case 3: v(var.as<RICcause>()); return true;
			case 4: v(var.as<CriticalityDiagnostics>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(CriticalityDiagnostics)];
			char dummy2[sizeof(RANfunctionID)];
			char dummy3[sizeof(RICcause)];
			char dummy4[sizeof(RICrequestID)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(mandatory); type=1;}
		void select_id_RANfunctionID() { set(mandatory); type=2;}
		void select_id_RICcause() { set(mandatory); type=3;}
		void select_id_CriticalityDiagnostics() { set(optional); type=4;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else if(equal(mandatory)) { type = 2; return true; }
			else if(equal(mandatory)) { type = 3; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(mandatory);} return false;
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
RICsubscriptionDeleteFailure ::= SEQUENCE {
	protocolIEs					ProtocolIE-Container	{{RICsubscriptionDeleteFailure-IEs}},
	...
}
*/

struct RICsubscriptionDeleteFailure : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "RICsubscriptionDeleteFailure";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<RICsubscriptionDeleteFailure_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<RICsubscriptionDeleteFailure_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
RICsubscriptionDeleteRequest-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RICrequestID				CRITICALITY reject	TYPE RICrequestID					PRESENCE mandatory}|
	{ ID id-RANfunctionID				CRITICALITY reject	TYPE RANfunctionID					PRESENCE mandatory},
    ...
}
*/

struct RICsubscriptionDeleteRequest_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(id_RICrequestID); type=1;}
		void select_id_RANfunctionID() { set(id_RANfunctionID); type=2;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RICrequestID)) { type = 1; return true; }
			else if(equal(id_RANfunctionID)) { type = 2; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RICrequestID);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_RANfunctionID);} return false;
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
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(reject); type=1;}
		void select_id_RANfunctionID() { set(reject); type=2;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
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
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		RICrequestID& select_id_RICrequestID() { return set<RICrequestID>(1); }
		RICrequestID const* get_id_RICrequestID() const { return get<RICrequestID>(1); }
		RANfunctionID& select_id_RANfunctionID() { return set<RANfunctionID>(2); }
		RANfunctionID const* get_id_RANfunctionID() const { return get<RANfunctionID>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RICrequestID>(); break;
			case 2: var.destroy<RANfunctionID>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RICrequestID>(1);
			v.template operator()<RANfunctionID>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RICrequestID()); return true;
			case 2: v(select_id_RANfunctionID()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RICrequestID>()); return true;
			case 2: v(var.as<RANfunctionID>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RANfunctionID)];
			char dummy2[sizeof(RICrequestID)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(mandatory); type=1;}
		void select_id_RANfunctionID() { set(mandatory); type=2;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else if(equal(mandatory)) { type = 2; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(mandatory);} return false;
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
RICsubscriptionDeleteRequest ::= SEQUENCE {
	protocolIEs					ProtocolIE-Container	{{RICsubscriptionDeleteRequest-IEs}},
	...
}
*/

struct RICsubscriptionDeleteRequest : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "RICsubscriptionDeleteRequest";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<RICsubscriptionDeleteRequest_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<RICsubscriptionDeleteRequest_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
RICsubscriptionDeleteResponse-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RICrequestID				CRITICALITY reject	TYPE RICrequestID					PRESENCE mandatory}|
	{ ID id-RANfunctionID				CRITICALITY reject	TYPE RANfunctionID					PRESENCE mandatory},
    ...
}
*/

struct RICsubscriptionDeleteResponse_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(id_RICrequestID); type=1;}
		void select_id_RANfunctionID() { set(id_RANfunctionID); type=2;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RICrequestID)) { type = 1; return true; }
			else if(equal(id_RANfunctionID)) { type = 2; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RICrequestID);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_RANfunctionID);} return false;
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
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(reject); type=1;}
		void select_id_RANfunctionID() { set(reject); type=2;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
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
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		RICrequestID& select_id_RICrequestID() { return set<RICrequestID>(1); }
		RICrequestID const* get_id_RICrequestID() const { return get<RICrequestID>(1); }
		RANfunctionID& select_id_RANfunctionID() { return set<RANfunctionID>(2); }
		RANfunctionID const* get_id_RANfunctionID() const { return get<RANfunctionID>(2); }
		bool is_unknown() const { return type == 3; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RICrequestID>(); break;
			case 2: var.destroy<RANfunctionID>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RICrequestID>(1);
			v.template operator()<RANfunctionID>(2);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RICrequestID()); return true;
			case 2: v(select_id_RANfunctionID()); return true;
			case 3: if(type != 3) {clear(); asn::base::set();} type = 3; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RICrequestID>()); return true;
			case 2: v(var.as<RANfunctionID>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RANfunctionID)];
			char dummy2[sizeof(RICrequestID)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 3; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(mandatory); type=1;}
		void select_id_RANfunctionID() { set(mandatory); type=2;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else if(equal(mandatory)) { type = 2; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(mandatory);} return false;
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
RICsubscriptionDeleteResponse ::= SEQUENCE {
	protocolIEs					ProtocolIE-Container	{{RICsubscriptionDeleteResponse-IEs}},
	...
}
*/

struct RICsubscriptionDeleteResponse : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "RICsubscriptionDeleteResponse";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<RICsubscriptionDeleteResponse_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<RICsubscriptionDeleteResponse_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
RICsubscriptionFailure-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RICrequestID				CRITICALITY reject	TYPE RICrequestID					PRESENCE mandatory}|
	{ ID id-RANfunctionID				CRITICALITY reject	TYPE RANfunctionID					PRESENCE mandatory}|
	{ ID id-RICactions-NotAdmitted		CRITICALITY reject	TYPE RICaction-NotAdmitted-List		PRESENCE mandatory}|
    { ID id-CriticalityDiagnostics		CRITICALITY ignore	TYPE CriticalityDiagnostics			PRESENCE optional},
    ...
}
*/

struct RICsubscriptionFailure_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(id_RICrequestID); type=1;}
		void select_id_RANfunctionID() { set(id_RANfunctionID); type=2;}
		void select_id_RICactions_NotAdmitted() { set(id_RICactions_NotAdmitted); type=3;}
		void select_id_CriticalityDiagnostics() { set(id_CriticalityDiagnostics); type=4;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RICrequestID)) { type = 1; return true; }
			else if(equal(id_RANfunctionID)) { type = 2; return true; }
			else if(equal(id_RICactions_NotAdmitted)) { type = 3; return true; }
			else if(equal(id_CriticalityDiagnostics)) { type = 4; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RICrequestID);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_RANfunctionID);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_RICactions_NotAdmitted);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_CriticalityDiagnostics);} return false;
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
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(reject); type=1;}
		void select_id_RANfunctionID() { set(reject); type=2;}
		void select_id_RICactions_NotAdmitted() { set(reject); type=3;}
		void select_id_CriticalityDiagnostics() { set(ignore); type=4;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
			else if(equal(reject)) { type = 2; return true; }
			else if(equal(reject)) { type = 3; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(reject);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(reject);} return false;
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
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		RICrequestID& select_id_RICrequestID() { return set<RICrequestID>(1); }
		RICrequestID const* get_id_RICrequestID() const { return get<RICrequestID>(1); }
		RANfunctionID& select_id_RANfunctionID() { return set<RANfunctionID>(2); }
		RANfunctionID const* get_id_RANfunctionID() const { return get<RANfunctionID>(2); }
		RICaction_NotAdmitted_List& select_id_RICactions_NotAdmitted() { return set<RICaction_NotAdmitted_List>(3); }
		RICaction_NotAdmitted_List const* get_id_RICactions_NotAdmitted() const { return get<RICaction_NotAdmitted_List>(3); }
		CriticalityDiagnostics& select_id_CriticalityDiagnostics() { return set<CriticalityDiagnostics>(4); }
		CriticalityDiagnostics const* get_id_CriticalityDiagnostics() const { return get<CriticalityDiagnostics>(4); }
		bool is_unknown() const { return type == 5; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RICrequestID>(); break;
			case 2: var.destroy<RANfunctionID>(); break;
			case 3: var.destroy<RICaction_NotAdmitted_List>(); break;
			case 4: var.destroy<CriticalityDiagnostics>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RICrequestID>(1);
			v.template operator()<RANfunctionID>(2);
			v.template operator()<RICaction_NotAdmitted_List>(3);
			v.template operator()<CriticalityDiagnostics>(4);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RICrequestID()); return true;
			case 2: v(select_id_RANfunctionID()); return true;
			case 3: v(select_id_RICactions_NotAdmitted()); return true;
			case 4: v(select_id_CriticalityDiagnostics()); return true;
			case 5: if(type != 5) {clear(); asn::base::set();} type = 5; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RICrequestID>()); return true;
			case 2: v(var.as<RANfunctionID>()); return true;
			case 3: v(var.as<RICaction_NotAdmitted_List>()); return true;
			case 4: v(var.as<CriticalityDiagnostics>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(CriticalityDiagnostics)];
			char dummy2[sizeof(RANfunctionID)];
			char dummy3[sizeof(RICaction_NotAdmitted_List)];
			char dummy4[sizeof(RICrequestID)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(mandatory); type=1;}
		void select_id_RANfunctionID() { set(mandatory); type=2;}
		void select_id_RICactions_NotAdmitted() { set(mandatory); type=3;}
		void select_id_CriticalityDiagnostics() { set(optional); type=4;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else if(equal(mandatory)) { type = 2; return true; }
			else if(equal(mandatory)) { type = 3; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(mandatory);} return false;
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
RICsubscriptionFailure ::= SEQUENCE {
	protocolIEs					ProtocolIE-Container	{{RICsubscriptionFailure-IEs}},
	...
}
*/

struct RICsubscriptionFailure : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "RICsubscriptionFailure";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<RICsubscriptionFailure_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<RICsubscriptionFailure_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
RICsubscriptionRequest-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RICrequestID				CRITICALITY reject	TYPE RICrequestID					PRESENCE mandatory}|
	{ ID id-RANfunctionID				CRITICALITY reject	TYPE RANfunctionID					PRESENCE mandatory}|
	{ ID id-RICsubscription				CRITICALITY reject	TYPE RICsubscription				PRESENCE mandatory},
	...
}
*/

struct RICsubscriptionRequest_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(id_RICrequestID); type=1;}
		void select_id_RANfunctionID() { set(id_RANfunctionID); type=2;}
		void select_id_RICsubscription() { set(id_RICsubscription); type=3;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RICrequestID)) { type = 1; return true; }
			else if(equal(id_RANfunctionID)) { type = 2; return true; }
			else if(equal(id_RICsubscription)) { type = 3; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RICrequestID);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_RANfunctionID);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_RICsubscription);} return false;
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
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(reject); type=1;}
		void select_id_RANfunctionID() { set(reject); type=2;}
		void select_id_RICsubscription() { set(reject); type=3;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
			else if(equal(reject)) { type = 2; return true; }
			else if(equal(reject)) { type = 3; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(reject);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(reject);} return false;
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
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		RICrequestID& select_id_RICrequestID() { return set<RICrequestID>(1); }
		RICrequestID const* get_id_RICrequestID() const { return get<RICrequestID>(1); }
		RANfunctionID& select_id_RANfunctionID() { return set<RANfunctionID>(2); }
		RANfunctionID const* get_id_RANfunctionID() const { return get<RANfunctionID>(2); }
		RICsubscription& select_id_RICsubscription() { return set<RICsubscription>(3); }
		RICsubscription const* get_id_RICsubscription() const { return get<RICsubscription>(3); }
		bool is_unknown() const { return type == 4; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RICrequestID>(); break;
			case 2: var.destroy<RANfunctionID>(); break;
			case 3: var.destroy<RICsubscription>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RICrequestID>(1);
			v.template operator()<RANfunctionID>(2);
			v.template operator()<RICsubscription>(3);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RICrequestID()); return true;
			case 2: v(select_id_RANfunctionID()); return true;
			case 3: v(select_id_RICsubscription()); return true;
			case 4: if(type != 4) {clear(); asn::base::set();} type = 4; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RICrequestID>()); return true;
			case 2: v(var.as<RANfunctionID>()); return true;
			case 3: v(var.as<RICsubscription>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RANfunctionID)];
			char dummy2[sizeof(RICrequestID)];
			char dummy3[sizeof(RICsubscription)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 4; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(mandatory); type=1;}
		void select_id_RANfunctionID() { set(mandatory); type=2;}
		void select_id_RICsubscription() { set(mandatory); type=3;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else if(equal(mandatory)) { type = 2; return true; }
			else if(equal(mandatory)) { type = 3; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(mandatory);} return false;
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
RICsubscriptionRequest ::= SEQUENCE {
	protocolIEs					ProtocolIE-Container	{{RICsubscriptionRequest-IEs}},
	...
}
*/

struct RICsubscriptionRequest : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "RICsubscriptionRequest";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<RICsubscriptionRequest_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<RICsubscriptionRequest_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
/*
RICsubscriptionResponse-IEs X2AP-PROTOCOL-IES ::= {
	{ ID id-RICrequestID				CRITICALITY reject		TYPE RICrequestID				PRESENCE mandatory } |
	{ ID id-RANfunctionID				CRITICALITY reject		TYPE RANfunctionID				PRESENCE mandatory } |
	{ ID id-RICactions-Admitted			CRITICALITY reject		TYPE RICaction-Admitted-List	PRESENCE mandatory } |
	{ ID id-RICactions-NotAdmitted		CRITICALITY reject		TYPE RICaction-NotAdmitted-List	PRESENCE optional },
    ...
}
*/

struct RICsubscriptionResponse_IEs
{
	struct id_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::id_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(id_RICrequestID); type=1;}
		void select_id_RANfunctionID() { set(id_RANfunctionID); type=2;}
		void select_id_RICactions_Admitted() { set(id_RICactions_Admitted); type=3;}
		void select_id_RICactions_NotAdmitted() { set(id_RICactions_NotAdmitted); type=4;}
		X2AP_PROTOCOL_IES::id_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_RICrequestID)) { type = 1; return true; }
			else if(equal(id_RANfunctionID)) { type = 2; return true; }
			else if(equal(id_RICactions_Admitted)) { type = 3; return true; }
			else if(equal(id_RICactions_NotAdmitted)) { type = 4; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(id_RICrequestID);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_RANfunctionID);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_RICactions_Admitted);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_RICactions_NotAdmitted);} return false;
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
	struct criticality_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(reject); type=1;}
		void select_id_RANfunctionID() { set(reject); type=2;}
		void select_id_RICactions_Admitted() { set(reject); type=3;}
		void select_id_RICactions_NotAdmitted() { set(reject); type=4;}
		X2AP_PROTOCOL_IES::criticality_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(reject)) { type = 1; return true; }
			else if(equal(reject)) { type = 2; return true; }
			else if(equal(reject)) { type = 3; return true; }
			else if(equal(reject)) { type = 4; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(reject);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(reject);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(reject);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(reject);} return false;
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
	struct Value_t : asn::typefield<true>
	{
		~Value_t()	{clear();}
		size_t get_index() const {return type;}
		RICrequestID& select_id_RICrequestID() { return set<RICrequestID>(1); }
		RICrequestID const* get_id_RICrequestID() const { return get<RICrequestID>(1); }
		RANfunctionID& select_id_RANfunctionID() { return set<RANfunctionID>(2); }
		RANfunctionID const* get_id_RANfunctionID() const { return get<RANfunctionID>(2); }
		RICaction_Admitted_List& select_id_RICactions_Admitted() { return set<RICaction_Admitted_List>(3); }
		RICaction_Admitted_List const* get_id_RICactions_Admitted() const { return get<RICaction_Admitted_List>(3); }
		RICaction_NotAdmitted_List& select_id_RICactions_NotAdmitted() { return set<RICaction_NotAdmitted_List>(4); }
		RICaction_NotAdmitted_List const* get_id_RICactions_NotAdmitted() const { return get<RICaction_NotAdmitted_List>(4); }
		bool is_unknown() const { return type == 5; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RICrequestID>(); break;
			case 2: var.destroy<RANfunctionID>(); break;
			case 3: var.destroy<RICaction_Admitted_List>(); break;
			case 4: var.destroy<RICaction_NotAdmitted_List>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RICrequestID>(1);
			v.template operator()<RANfunctionID>(2);
			v.template operator()<RICaction_Admitted_List>(3);
			v.template operator()<RICaction_NotAdmitted_List>(4);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_RICrequestID()); return true;
			case 2: v(select_id_RANfunctionID()); return true;
			case 3: v(select_id_RICactions_Admitted()); return true;
			case 4: v(select_id_RICactions_NotAdmitted()); return true;
			case 5: if(type != 5) {clear(); asn::base::set();} type = 5; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RICrequestID>()); return true;
			case 2: v(var.as<RANfunctionID>()); return true;
			case 3: v(var.as<RICaction_Admitted_List>()); return true;
			case 4: v(var.as<RICaction_NotAdmitted_List>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(RANfunctionID)];
			char dummy2[sizeof(RICaction_Admitted_List)];
			char dummy3[sizeof(RICaction_NotAdmitted_List)];
			char dummy4[sizeof(RICrequestID)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct presence_t : asn::fixedtypefield<X2AP_PROTOCOL_IES::presence_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 5; }
		void clear() {type = 0;}
		void select_id_RICrequestID() { set(mandatory); type=1;}
		void select_id_RANfunctionID() { set(mandatory); type=2;}
		void select_id_RICactions_Admitted() { set(mandatory); type=3;}
		void select_id_RICactions_NotAdmitted() { set(optional); type=4;}
		X2AP_PROTOCOL_IES::presence_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(mandatory)) { type = 1; return true; }
			else if(equal(mandatory)) { type = 2; return true; }
			else if(equal(mandatory)) { type = 3; return true; }
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
			case 1: type = 1; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(mandatory);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(mandatory);} return false;
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
RICsubscriptionResponse ::= SEQUENCE {
	protocolIEs					ProtocolIE-Container{{RICsubscriptionResponse-IEs}},
	...
}
*/

struct RICsubscriptionResponse : asn::sequence<1, 0, true, 0>
{
	static constexpr const char* name() {return "RICsubscriptionResponse";}
	using parent_t = asn::sequence<1, 0, true, 0>;
	struct protocolIEs_t : ProtocolIE_Container<RICsubscriptionResponse_IEs>
	{
		static constexpr const char* name() {return "protocolIEs_t";}
		using parent_t = ProtocolIE_Container<RICsubscriptionResponse_IEs>;

	};
	protocolIEs_t& ref_protocolIEs() {return protocolIEs;}
	protocolIEs_t const& ref_protocolIEs() const {return protocolIEs;}
	template<typename V> void decode(V& v)
	{
		v(protocolIEs);

	};
	template<typename V> void encode(V& v) const
	{
		v(protocolIEs);

	};
	void clear()
	{
		protocolIEs.clear();

	};
	private:
	protocolIEs_t	protocolIEs;

};
