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

#include "X2AP-CommonDataTypes.hpp"

/*
X2AP-PRIVATE-IES ::= CLASS {
	&id					PrivateIE-ID,
	&criticality		Criticality,
	&Value,
	&presence			Presence
}
WITH SYNTAX {
	ID					&id
	CRITICALITY			&criticality
	TYPE				&Value
	PRESENCE			&presence
}
*/

struct X2AP_PRIVATE_IES
{
	struct id_t : PrivateIE_ID
	{
		static constexpr const char* name() {return "id_t";}
		using parent_t = PrivateIE_ID;

	};
	struct criticality_t : Criticality
	{
		static constexpr const char* name() {return "criticality_t";}
		using parent_t = Criticality;

	};
	struct presence_t : Presence
	{
		static constexpr const char* name() {return "presence_t";}
		using parent_t = Presence;

	};

};
/*
PrivateIE-Field {X2AP-PRIVATE-IES : IEsSetParam} ::= SEQUENCE {
	id				X2AP-PRIVATE-IES.&id			({IEsSetParam}),
	criticality		X2AP-PRIVATE-IES.&criticality	({IEsSetParam}{@id}),
	value			X2AP-PRIVATE-IES.&Value			({IEsSetParam}{@id})
}
*/

template<typename IEsSetParam>
struct PrivateIE_Field : asn::sequence<3, 0, false, 0>
{
	static constexpr const char* name() {return "PrivateIE-Field";}
	using parent_t = asn::sequence<3, 0, false, 0>;
	struct id_t : IEsSetParam::id_t
	{
		static constexpr const char* name() {return "id_t";}
		using parent_t = typename IEsSetParam::id_t;
		template<typename V>  bool decode(V& v, PrivateIE_Field const& c)
		{
			return IEsSetParam::id_t::decode(v);
		};
		template<typename V>  bool encode(V& v, PrivateIE_Field const& c) const
		{
			return IEsSetParam::id_t::encode(v);
		};
	};
	id_t& ref_id() {return id;}
	id_t const& ref_id() const {return id;}
	struct criticality_t : IEsSetParam::criticality_t
	{
		static constexpr const char* name() {return "criticality_t";}
		using parent_t = typename IEsSetParam::criticality_t;
		template<typename V>  bool decode(V& v, PrivateIE_Field const& c)
		{
			return IEsSetParam::criticality_t::decode(c.id.get_index(), v);
		};
		template<typename V>  bool encode(V& v, PrivateIE_Field const& c) const
		{
			return IEsSetParam::criticality_t::encode(c.id.get_index(), v);
		};
	};
	criticality_t& ref_criticality() {return criticality;}
	criticality_t const& ref_criticality() const {return criticality;}
	struct value_t : IEsSetParam::Value_t
	{
		static constexpr const char* name() {return "value_t";}
		using parent_t = typename IEsSetParam::Value_t;
		template<typename V>  bool decode(V& v, PrivateIE_Field const& c)
		{
			return IEsSetParam::Value_t::decode(c.id.get_index(), v);
		};
		template<typename V>  bool encode(V& v, PrivateIE_Field const& c) const
		{
			return IEsSetParam::Value_t::encode(c.id.get_index(), v);
		};
	};
	value_t& ref_value() {return value;}
	value_t const& ref_value() const {return value;}
	template<typename V> void decode(V& v)
	{
		v(id);
		v(criticality);
		v(value);

	};
	template<typename V> void encode(V& v) const
	{
		v(id);
		v(criticality);
		v(value);

	};
	void clear()
	{
		id.clear();
		criticality.clear();
		value.clear();

	};
	private:
	id_t	id;
	criticality_t	criticality;
	value_t	value;

};
/*
PrivateIE-Container {X2AP-PRIVATE-IES : IEsSetParam} ::=
	SEQUENCE (SIZE (1..maxPrivateIEs)) OF
	PrivateIE-Field {{IEsSetParam}}
*/

template<typename IEsSetParam>
struct PrivateIE_Container_elm : PrivateIE_Field<IEsSetParam>
{
	static constexpr const char* name() {return "PrivateIE_Container_elm";}
	using parent_t = PrivateIE_Field<IEsSetParam>;

};
template<typename IEsSetParam>
struct PrivateIE_Container : asn::sequenceof<PrivateIE_Container_elm <IEsSetParam> >
{
	static constexpr const char* name() {return "PrivateIE-Container";}
	using parent_t = asn::sequenceof<PrivateIE_Container_elm <IEsSetParam> >;
	using constraint_t = asn::constraints<false,asn::span<1,  maxPrivateIEs >>;

};
/*
X2AP-PROTOCOL-EXTENSION ::= CLASS {
	&id					ProtocolIE-ID 		UNIQUE,
	&criticality		Criticality,
	&Extension,
	&presence			Presence
}
WITH SYNTAX {
	ID					&id
	CRITICALITY			&criticality
	EXTENSION			&Extension
	PRESENCE			&presence
}
*/

struct X2AP_PROTOCOL_EXTENSION
{
	struct id_t : ProtocolIE_ID
	{
		static constexpr const char* name() {return "id_t";}
		using parent_t = ProtocolIE_ID;

	};
	struct criticality_t : Criticality
	{
		static constexpr const char* name() {return "criticality_t";}
		using parent_t = Criticality;

	};
	struct presence_t : Presence
	{
		static constexpr const char* name() {return "presence_t";}
		using parent_t = Presence;

	};

};
/*
ProtocolExtensionField {X2AP-PROTOCOL-EXTENSION : ExtensionSetParam} ::= SEQUENCE {
	id					X2AP-PROTOCOL-EXTENSION.&id				({ExtensionSetParam}),
	criticality			X2AP-PROTOCOL-EXTENSION.&criticality	({ExtensionSetParam}{@id}),
	extensionValue		X2AP-PROTOCOL-EXTENSION.&Extension		({ExtensionSetParam}{@id})
}
*/

template<typename ExtensionSetParam>
struct ProtocolExtensionField : asn::sequence<3, 0, false, 0>
{
	static constexpr const char* name() {return "ProtocolExtensionField";}
	using parent_t = asn::sequence<3, 0, false, 0>;
	struct id_t : ExtensionSetParam::id_t
	{
		static constexpr const char* name() {return "id_t";}
		using parent_t = typename ExtensionSetParam::id_t;
		template<typename V>  bool decode(V& v, ProtocolExtensionField const& c)
		{
			return ExtensionSetParam::id_t::decode(v);
		};
		template<typename V>  bool encode(V& v, ProtocolExtensionField const& c) const
		{
			return ExtensionSetParam::id_t::encode(v);
		};
	};
	id_t& ref_id() {return id;}
	id_t const& ref_id() const {return id;}
	struct criticality_t : ExtensionSetParam::criticality_t
	{
		static constexpr const char* name() {return "criticality_t";}
		using parent_t = typename ExtensionSetParam::criticality_t;
		template<typename V>  bool decode(V& v, ProtocolExtensionField const& c)
		{
			return ExtensionSetParam::criticality_t::decode(c.id.get_index(), v);
		};
		template<typename V>  bool encode(V& v, ProtocolExtensionField const& c) const
		{
			return ExtensionSetParam::criticality_t::encode(c.id.get_index(), v);
		};
	};
	criticality_t& ref_criticality() {return criticality;}
	criticality_t const& ref_criticality() const {return criticality;}
	struct extensionValue_t : ExtensionSetParam::Extension_t
	{
		static constexpr const char* name() {return "extensionValue_t";}
		using parent_t = typename ExtensionSetParam::Extension_t;
		template<typename V>  bool decode(V& v, ProtocolExtensionField const& c)
		{
			return ExtensionSetParam::Extension_t::decode(c.id.get_index(), v);
		};
		template<typename V>  bool encode(V& v, ProtocolExtensionField const& c) const
		{
			return ExtensionSetParam::Extension_t::encode(c.id.get_index(), v);
		};
	};
	extensionValue_t& ref_extensionValue() {return extensionValue;}
	extensionValue_t const& ref_extensionValue() const {return extensionValue;}
	template<typename V> void decode(V& v)
	{
		v(id);
		v(criticality);
		v(extensionValue);

	};
	template<typename V> void encode(V& v) const
	{
		v(id);
		v(criticality);
		v(extensionValue);

	};
	void clear()
	{
		id.clear();
		criticality.clear();
		extensionValue.clear();

	};
	private:
	id_t	id;
	criticality_t	criticality;
	extensionValue_t	extensionValue;

};
/*
ProtocolExtensionContainer {X2AP-PROTOCOL-EXTENSION : ExtensionSetParam} ::=
	SEQUENCE (SIZE (1..maxProtocolExtensions)) OF
	ProtocolExtensionField {{ExtensionSetParam}}
*/

template<typename ExtensionSetParam>
struct ProtocolExtensionContainer_elm : ProtocolExtensionField<ExtensionSetParam>
{
	static constexpr const char* name() {return "ProtocolExtensionContainer_elm";}
	using parent_t = ProtocolExtensionField<ExtensionSetParam>;

};
template<typename ExtensionSetParam>
struct ProtocolExtensionContainer : asn::sequenceof<ProtocolExtensionContainer_elm <ExtensionSetParam> >
{
	static constexpr const char* name() {return "ProtocolExtensionContainer";}
	using parent_t = asn::sequenceof<ProtocolExtensionContainer_elm <ExtensionSetParam> >;
	using constraint_t = asn::constraints<false,asn::span<1,  maxProtocolExtensions >>;

};
/*
X2AP-PROTOCOL-IES ::= CLASS {
	&id				ProtocolIE-ID 			UNIQUE,
	&criticality	Criticality,
	&Value,
	&presence		Presence
}
WITH SYNTAX {
	ID				&id
	CRITICALITY		&criticality
	TYPE			&Value
	PRESENCE		&presence
}
*/

struct X2AP_PROTOCOL_IES
{
	struct id_t : ProtocolIE_ID
	{
		static constexpr const char* name() {return "id_t";}
		using parent_t = ProtocolIE_ID;

	};
	struct criticality_t : Criticality
	{
		static constexpr const char* name() {return "criticality_t";}
		using parent_t = Criticality;

	};
	struct presence_t : Presence
	{
		static constexpr const char* name() {return "presence_t";}
		using parent_t = Presence;

	};

};
/*
ProtocolIE-Field {X2AP-PROTOCOL-IES : IEsSetParam} ::= SEQUENCE {
	id				X2AP-PROTOCOL-IES.&id					({IEsSetParam}),
	criticality		X2AP-PROTOCOL-IES.&criticality			({IEsSetParam}{@id}),
	value			X2AP-PROTOCOL-IES.&Value				({IEsSetParam}{@id})
}
*/

template<typename IEsSetParam>
struct ProtocolIE_Field : asn::sequence<3, 0, false, 0>
{
	static constexpr const char* name() {return "ProtocolIE-Field";}
	using parent_t = asn::sequence<3, 0, false, 0>;
	struct id_t : IEsSetParam::id_t
	{
		static constexpr const char* name() {return "id_t";}
		using parent_t = typename IEsSetParam::id_t;
		template<typename V>  bool decode(V& v, ProtocolIE_Field const& c)
		{
			return IEsSetParam::id_t::decode(v);
		};
		template<typename V>  bool encode(V& v, ProtocolIE_Field const& c) const
		{
			return IEsSetParam::id_t::encode(v);
		};
	};
	id_t& ref_id() {return id;}
	id_t const& ref_id() const {return id;}
	struct criticality_t : IEsSetParam::criticality_t
	{
		static constexpr const char* name() {return "criticality_t";}
		using parent_t = typename IEsSetParam::criticality_t;
		template<typename V>  bool decode(V& v, ProtocolIE_Field const& c)
		{
			return IEsSetParam::criticality_t::decode(c.id.get_index(), v);
		};
		template<typename V>  bool encode(V& v, ProtocolIE_Field const& c) const
		{
			return IEsSetParam::criticality_t::encode(c.id.get_index(), v);
		};
	};
	criticality_t& ref_criticality() {return criticality;}
	criticality_t const& ref_criticality() const {return criticality;}
	struct value_t : IEsSetParam::Value_t
	{
		static constexpr const char* name() {return "value_t";}
		using parent_t = typename IEsSetParam::Value_t;
		template<typename V>  bool decode(V& v, ProtocolIE_Field const& c)
		{
			return IEsSetParam::Value_t::decode(c.id.get_index(), v);
		};
		template<typename V>  bool encode(V& v, ProtocolIE_Field const& c) const
		{
			return IEsSetParam::Value_t::encode(c.id.get_index(), v);
		};
	};
	value_t& ref_value() {return value;}
	value_t const& ref_value() const {return value;}
	template<typename V> void decode(V& v)
	{
		v(id);
		v(criticality);
		v(value);

	};
	template<typename V> void encode(V& v) const
	{
		v(id);
		v(criticality);
		v(value);

	};
	void clear()
	{
		id.clear();
		criticality.clear();
		value.clear();

	};
	private:
	id_t	id;
	criticality_t	criticality;
	value_t	value;

};
/*
ProtocolIE-Container {X2AP-PROTOCOL-IES : IEsSetParam} ::=
	SEQUENCE (SIZE (0..maxProtocolIEs)) OF
	ProtocolIE-Field {{IEsSetParam}}
*/

template<typename IEsSetParam>
struct ProtocolIE_Container_elm : ProtocolIE_Field<IEsSetParam>
{
	static constexpr const char* name() {return "ProtocolIE_Container_elm";}
	using parent_t = ProtocolIE_Field<IEsSetParam>;

};
template<typename IEsSetParam>
struct ProtocolIE_Container : asn::sequenceof<ProtocolIE_Container_elm <IEsSetParam> >
{
	static constexpr const char* name() {return "ProtocolIE-Container";}
	using parent_t = asn::sequenceof<ProtocolIE_Container_elm <IEsSetParam> >;
	using constraint_t = asn::constraints<false,asn::span<0,  maxProtocolIEs >>;

};
/*
ProtocolIE-ContainerList {INTEGER : lowerBound, INTEGER : upperBound, X2AP-PROTOCOL-IES : IEsSetParam} ::=
	SEQUENCE (SIZE (lowerBound..upperBound)) OF
	ProtocolIE-Container {{IEsSetParam}}
*/

template<int64_t lowerBound, int64_t upperBound, typename IEsSetParam>
struct ProtocolIE_ContainerList_elm : ProtocolIE_Container<IEsSetParam>
{
	static constexpr const char* name() {return "ProtocolIE_ContainerList_elm";}
	using parent_t = ProtocolIE_Container<IEsSetParam>;

};
template<int64_t lowerBound, int64_t upperBound, typename IEsSetParam>
struct ProtocolIE_ContainerList : asn::sequenceof<ProtocolIE_ContainerList_elm <lowerBound, upperBound, IEsSetParam> >
{
	static constexpr const char* name() {return "ProtocolIE-ContainerList";}
	using parent_t = asn::sequenceof<ProtocolIE_ContainerList_elm <lowerBound, upperBound, IEsSetParam> >;
	using constraint_t = asn::constraints<false,asn::span< lowerBound ,  upperBound >>;

};
/*
X2AP-PROTOCOL-IES-PAIR ::= CLASS {
	&id						ProtocolIE-ID 		UNIQUE,
	&firstCriticality		Criticality,
	&FirstValue,
	&secondCriticality		Criticality,
	&SecondValue,
	&presence				Presence
}
WITH SYNTAX {
	ID						&id
	FIRST CRITICALITY 		&firstCriticality
	FIRST TYPE				&FirstValue
	SECOND CRITICALITY 		&secondCriticality
	SECOND TYPE				&SecondValue
	PRESENCE				&presence
}
*/

struct X2AP_PROTOCOL_IES_PAIR
{
	struct id_t : ProtocolIE_ID
	{
		static constexpr const char* name() {return "id_t";}
		using parent_t = ProtocolIE_ID;

	};
	struct firstCriticality_t : Criticality
	{
		static constexpr const char* name() {return "firstCriticality_t";}
		using parent_t = Criticality;

	};
	struct secondCriticality_t : Criticality
	{
		static constexpr const char* name() {return "secondCriticality_t";}
		using parent_t = Criticality;

	};
	struct presence_t : Presence
	{
		static constexpr const char* name() {return "presence_t";}
		using parent_t = Presence;

	};

};
/*
ProtocolIE-FieldPair {X2AP-PROTOCOL-IES-PAIR : IEsSetParam} ::= SEQUENCE {
	id					X2AP-PROTOCOL-IES-PAIR.&id					({IEsSetParam}),
	firstCriticality	X2AP-PROTOCOL-IES-PAIR.&firstCriticality	({IEsSetParam}{@id}),
	firstValue			X2AP-PROTOCOL-IES-PAIR.&FirstValue			({IEsSetParam}{@id}),
	secondCriticality	X2AP-PROTOCOL-IES-PAIR.&secondCriticality	({IEsSetParam}{@id}),
	secondValue			X2AP-PROTOCOL-IES-PAIR.&SecondValue			({IEsSetParam}{@id})
}
*/

template<typename IEsSetParam>
struct ProtocolIE_FieldPair : asn::sequence<5, 0, false, 0>
{
	static constexpr const char* name() {return "ProtocolIE-FieldPair";}
	using parent_t = asn::sequence<5, 0, false, 0>;
	struct id_t : IEsSetParam::id_t
	{
		static constexpr const char* name() {return "id_t";}
		using parent_t = typename IEsSetParam::id_t;
		template<typename V>  bool decode(V& v, ProtocolIE_FieldPair const& c)
		{
			return IEsSetParam::id_t::decode(v);
		};
		template<typename V>  bool encode(V& v, ProtocolIE_FieldPair const& c) const
		{
			return IEsSetParam::id_t::encode(v);
		};
	};
	id_t& ref_id() {return id;}
	id_t const& ref_id() const {return id;}
	struct firstCriticality_t : IEsSetParam::firstCriticality_t
	{
		static constexpr const char* name() {return "firstCriticality_t";}
		using parent_t = typename IEsSetParam::firstCriticality_t;
		template<typename V>  bool decode(V& v, ProtocolIE_FieldPair const& c)
		{
			return IEsSetParam::firstCriticality_t::decode(c.id.get_index(), v);
		};
		template<typename V>  bool encode(V& v, ProtocolIE_FieldPair const& c) const
		{
			return IEsSetParam::firstCriticality_t::encode(c.id.get_index(), v);
		};
	};
	firstCriticality_t& ref_firstCriticality() {return firstCriticality;}
	firstCriticality_t const& ref_firstCriticality() const {return firstCriticality;}
	struct firstValue_t : IEsSetParam::FirstValue_t
	{
		static constexpr const char* name() {return "firstValue_t";}
		using parent_t = typename IEsSetParam::FirstValue_t;
		template<typename V>  bool decode(V& v, ProtocolIE_FieldPair const& c)
		{
			return IEsSetParam::FirstValue_t::decode(c.id.get_index(), v);
		};
		template<typename V>  bool encode(V& v, ProtocolIE_FieldPair const& c) const
		{
			return IEsSetParam::FirstValue_t::encode(c.id.get_index(), v);
		};
	};
	firstValue_t& ref_firstValue() {return firstValue;}
	firstValue_t const& ref_firstValue() const {return firstValue;}
	struct secondCriticality_t : IEsSetParam::secondCriticality_t
	{
		static constexpr const char* name() {return "secondCriticality_t";}
		using parent_t = typename IEsSetParam::secondCriticality_t;
		template<typename V>  bool decode(V& v, ProtocolIE_FieldPair const& c)
		{
			return IEsSetParam::secondCriticality_t::decode(c.id.get_index(), v);
		};
		template<typename V>  bool encode(V& v, ProtocolIE_FieldPair const& c) const
		{
			return IEsSetParam::secondCriticality_t::encode(c.id.get_index(), v);
		};
	};
	secondCriticality_t& ref_secondCriticality() {return secondCriticality;}
	secondCriticality_t const& ref_secondCriticality() const {return secondCriticality;}
	struct secondValue_t : IEsSetParam::SecondValue_t
	{
		static constexpr const char* name() {return "secondValue_t";}
		using parent_t = typename IEsSetParam::SecondValue_t;
		template<typename V>  bool decode(V& v, ProtocolIE_FieldPair const& c)
		{
			return IEsSetParam::SecondValue_t::decode(c.id.get_index(), v);
		};
		template<typename V>  bool encode(V& v, ProtocolIE_FieldPair const& c) const
		{
			return IEsSetParam::SecondValue_t::encode(c.id.get_index(), v);
		};
	};
	secondValue_t& ref_secondValue() {return secondValue;}
	secondValue_t const& ref_secondValue() const {return secondValue;}
	template<typename V> void decode(V& v)
	{
		v(id);
		v(firstCriticality);
		v(firstValue);
		v(secondCriticality);
		v(secondValue);

	};
	template<typename V> void encode(V& v) const
	{
		v(id);
		v(firstCriticality);
		v(firstValue);
		v(secondCriticality);
		v(secondValue);

	};
	void clear()
	{
		id.clear();
		firstCriticality.clear();
		firstValue.clear();
		secondCriticality.clear();
		secondValue.clear();

	};
	private:
	id_t	id;
	firstCriticality_t	firstCriticality;
	firstValue_t	firstValue;
	secondCriticality_t	secondCriticality;
	secondValue_t	secondValue;

};
/*
ProtocolIE-ContainerPair {X2AP-PROTOCOL-IES-PAIR : IEsSetParam} ::=
	SEQUENCE (SIZE (0..maxProtocolIEs)) OF
	ProtocolIE-FieldPair {{IEsSetParam}}
*/

template<typename IEsSetParam>
struct ProtocolIE_ContainerPair_elm : ProtocolIE_FieldPair<IEsSetParam>
{
	static constexpr const char* name() {return "ProtocolIE_ContainerPair_elm";}
	using parent_t = ProtocolIE_FieldPair<IEsSetParam>;

};
template<typename IEsSetParam>
struct ProtocolIE_ContainerPair : asn::sequenceof<ProtocolIE_ContainerPair_elm <IEsSetParam> >
{
	static constexpr const char* name() {return "ProtocolIE-ContainerPair";}
	using parent_t = asn::sequenceof<ProtocolIE_ContainerPair_elm <IEsSetParam> >;
	using constraint_t = asn::constraints<false,asn::span<0,  maxProtocolIEs >>;

};
/*
ProtocolIE-ContainerPairList {INTEGER : lowerBound, INTEGER : upperBound, X2AP-PROTOCOL-IES-PAIR : IEsSetParam} ::=
	SEQUENCE (SIZE (lowerBound..upperBound)) OF
	ProtocolIE-ContainerPair {{IEsSetParam}}
*/

template<int64_t lowerBound, int64_t upperBound, typename IEsSetParam>
struct ProtocolIE_ContainerPairList_elm : ProtocolIE_ContainerPair<IEsSetParam>
{
	static constexpr const char* name() {return "ProtocolIE_ContainerPairList_elm";}
	using parent_t = ProtocolIE_ContainerPair<IEsSetParam>;

};
template<int64_t lowerBound, int64_t upperBound, typename IEsSetParam>
struct ProtocolIE_ContainerPairList : asn::sequenceof<ProtocolIE_ContainerPairList_elm <lowerBound, upperBound, IEsSetParam> >
{
	static constexpr const char* name() {return "ProtocolIE-ContainerPairList";}
	using parent_t = asn::sequenceof<ProtocolIE_ContainerPairList_elm <lowerBound, upperBound, IEsSetParam> >;
	using constraint_t = asn::constraints<false,asn::span< lowerBound ,  upperBound >>;

};
/*
ProtocolIE-Single-Container {X2AP-PROTOCOL-IES : IEsSetParam} ::=
	ProtocolIE-Field {{IEsSetParam}}
*/

template<typename IEsSetParam>
struct ProtocolIE_Single_Container : ProtocolIE_Field<IEsSetParam>
{
	static constexpr const char* name() {return "ProtocolIE-Single-Container";}
	using parent_t = ProtocolIE_Field<IEsSetParam>;

};
