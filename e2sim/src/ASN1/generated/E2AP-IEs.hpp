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

#include "X2AP-IEs.hpp"

/*
CauseRIC ::= ENUMERATED {
	function-id-Invalid,
	action-not-supported,
	excessive-actions,
	duplicate-action,
	duplicate-event,
	function-resource-limit,
	request-id-unknown,
	inconsistent-action-subsequent-action-sequence,
	control-message-invalid,
	call-process-id-invalid,
	function-not-required,
	excessive-functions,
	ric-resource-limit,
	...
}
*/

struct CauseRIC : asn::enumerated<13, 0, true>
{
	static constexpr const char* name() {return "CauseRIC";}
	using parent_t = asn::enumerated<13, 0, true>;
	typedef enum {
		function_id_Invalid
		,action_not_supported
		,excessive_actions
		,duplicate_action
		,duplicate_event
		,function_resource_limit
		,request_id_unknown
		,inconsistent_action_subsequent_action_sequence
		,control_message_invalid
		,call_process_id_invalid
		,function_not_required
		,excessive_functions
		,ric_resource_limit
	} index_t;

};

/*
RANfunctionDefinition ::= OCTET STRING
*/

struct RANfunctionDefinition : asn::ostring<>
{
	static constexpr const char* name() {return "RANfunctionDefinition";}
	using parent_t = asn::ostring<>;

};

/*
RANfunctionID ::= INTEGER (0..4095)
*/

struct RANfunctionID : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 4095>>;
	static constexpr const char* name() {return "RANfunctionID";}
	using parent_t = asn::integer<>;

};

/*
RICactionDefinition ::= OCTET STRING
*/

struct RICactionDefinition : asn::ostring<>
{
	static constexpr const char* name() {return "RICactionDefinition";}
	using parent_t = asn::ostring<>;

};

/*
RICactionID ::= INTEGER (0..255)
*/

struct RICactionID : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 255>>;
	static constexpr const char* name() {return "RICactionID";}
	using parent_t = asn::integer<>;

};

/*
RICactionType ::= ENUMERATED{
	report,
	insert,
	policy,
	...
}
*/

struct RICactionType : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "RICactionType";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		report
		,insert
		,policy
	} index_t;

};

/*
RICcallProcessID ::= OCTET STRING
*/

struct RICcallProcessID : asn::ostring<>
{
	static constexpr const char* name() {return "RICcallProcessID";}
	using parent_t = asn::ostring<>;

};

/*
RICcause ::= CHOICE {
	radioNetwork		CauseRadioNetwork,
	transport			CauseTransport,
	protocol			CauseProtocol,
	misc				CauseMisc,
	ric					CauseRIC,
	...
}
*/

struct RICcause : asn::choice<5, 0, true>
{
	static constexpr const char* name() {return "RICcause";}
	using parent_t = asn::choice<5, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 6;}
	void set_unknown() { set_index(6);  }
	~RICcause() {clear();}
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
	struct ric_t : CauseRIC
	{
		static constexpr const char* name() {return "ric_t";}
		using parent_t = CauseRIC;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<radioNetwork_t>(); break;
		case 2: var.destroy<transport_t>(); break;
		case 3: var.destroy<protocol_t>(); break;
		case 4: var.destroy<misc_t>(); break;
		case 5: var.destroy<ric_t>(); break;
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
		case 5: set_index(5); return v(var.build<ric_t>());
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
		case 5: return v(var.as<ric_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<radioNetwork_t>(1);
		v.template operator()<transport_t>(2);
		v.template operator()<protocol_t>(3);
		v.template operator()<misc_t>(4);
		v.template operator()<ric_t>(5);

	}
	radioNetwork_t& select_radioNetwork() { if(get_index() != 1) { clear(); set_index(1); return var.build<radioNetwork_t>();} return var.as<radioNetwork_t>();}
	radioNetwork_t const* get_radioNetwork() const { if(get_index() == 1) { return &var.as<radioNetwork_t>();} return nullptr; }
	transport_t& select_transport() { if(get_index() != 2) { clear(); set_index(2); return var.build<transport_t>();} return var.as<transport_t>();}
	transport_t const* get_transport() const { if(get_index() == 2) { return &var.as<transport_t>();} return nullptr; }
	protocol_t& select_protocol() { if(get_index() != 3) { clear(); set_index(3); return var.build<protocol_t>();} return var.as<protocol_t>();}
	protocol_t const* get_protocol() const { if(get_index() == 3) { return &var.as<protocol_t>();} return nullptr; }
	misc_t& select_misc() { if(get_index() != 4) { clear(); set_index(4); return var.build<misc_t>();} return var.as<misc_t>();}
	misc_t const* get_misc() const { if(get_index() == 4) { return &var.as<misc_t>();} return nullptr; }
	ric_t& select_ric() { if(get_index() != 5) { clear(); set_index(5); return var.build<ric_t>();} return var.as<ric_t>();}
	ric_t const* get_ric() const { if(get_index() == 5) { return &var.as<ric_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(radioNetwork_t)];
		char dummy2[sizeof(transport_t)];
		char dummy3[sizeof(protocol_t)];
		char dummy4[sizeof(misc_t)];
		char dummy5[sizeof(ric_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
/*
RICcontrolAckRequest ::= ENUMERATED{
	noAck,
	ack,
	nAck,
	...
}
*/

struct RICcontrolAckRequest : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "RICcontrolAckRequest";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		noAck
		,ack
		,nAck
	} index_t;

};

/*
RICcontrolHeader ::= OCTET STRING
*/

struct RICcontrolHeader : asn::ostring<>
{
	static constexpr const char* name() {return "RICcontrolHeader";}
	using parent_t = asn::ostring<>;

};

/*
RICcontrolMessage ::= OCTET STRING
*/

struct RICcontrolMessage : asn::ostring<>
{
	static constexpr const char* name() {return "RICcontrolMessage";}
	using parent_t = asn::ostring<>;

};

/*
RICcontrolStatus ::= ENUMERATED{
	success,
	rejected,
	failed,
	...
}
*/

struct RICcontrolStatus : asn::enumerated<3, 0, true>
{
	static constexpr const char* name() {return "RICcontrolStatus";}
	using parent_t = asn::enumerated<3, 0, true>;
	typedef enum {
		success
		,rejected
		,failed
	} index_t;

};

/*
RICeventTriggerDefinition ::= OCTET STRING
*/

struct RICeventTriggerDefinition : asn::ostring<>
{
	static constexpr const char* name() {return "RICeventTriggerDefinition";}
	using parent_t = asn::ostring<>;

};

/*
RICindicationHeader ::= OCTET STRING
*/

struct RICindicationHeader : asn::ostring<>
{
	static constexpr const char* name() {return "RICindicationHeader";}
	using parent_t = asn::ostring<>;

};

/*
RICindicationMessage ::= OCTET STRING
*/

struct RICindicationMessage : asn::ostring<>
{
	static constexpr const char* name() {return "RICindicationMessage";}
	using parent_t = asn::ostring<>;

};

/*
RICindicationSN ::= INTEGER (0..65535)
*/

struct RICindicationSN : asn::integer<>
{
	using constraint_t = asn::constraints<false,asn::span<0, 65535>>;
	static constexpr const char* name() {return "RICindicationSN";}
	using parent_t = asn::integer<>;

};

/*
RICindicationType ::= ENUMERATED{
	report,
	insert,
	...
}
*/

struct RICindicationType : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "RICindicationType";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		report
		,insert
	} index_t;

};

/*
RICrequestID ::= SEQUENCE {
	ricRequestorID				INTEGER (0..65535),
	ricRequestSequenceNumber	INTEGER (0..65535),
	...
}
*/

struct RICrequestID : asn::sequence<2, 0, true, 0>
{
	static constexpr const char* name() {return "RICrequestID";}
	using parent_t = asn::sequence<2, 0, true, 0>;
	struct ricRequestorID_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 65535>>;
		static constexpr const char* name() {return "ricRequestorID_t";}
		using parent_t = asn::integer<>;

	};

	ricRequestorID_t& ref_ricRequestorID() {return ricRequestorID;}
	ricRequestorID_t const& ref_ricRequestorID() const {return ricRequestorID;}
	struct ricRequestSequenceNumber_t : asn::integer<>
	{
		using constraint_t = asn::constraints<false,asn::span<0, 65535>>;
		static constexpr const char* name() {return "ricRequestSequenceNumber_t";}
		using parent_t = asn::integer<>;

	};

	ricRequestSequenceNumber_t& ref_ricRequestSequenceNumber() {return ricRequestSequenceNumber;}
	ricRequestSequenceNumber_t const& ref_ricRequestSequenceNumber() const {return ricRequestSequenceNumber;}
	template<typename V> void decode(V& v)
	{
		v(ricRequestorID);
		v(ricRequestSequenceNumber);

	};
	template<typename V> void encode(V& v) const
	{
		v(ricRequestorID);
		v(ricRequestSequenceNumber);

	};
	void clear()
	{
		ricRequestorID.clear();
		ricRequestSequenceNumber.clear();

	};
	private:
	ricRequestorID_t	ricRequestorID;
	ricRequestSequenceNumber_t	ricRequestSequenceNumber;

};
/*
RICsubsequentActionType ::= ENUMERATED{
	continue,
	wait,
	...
}
*/

struct RICsubsequentActionType : asn::enumerated<2, 0, true>
{
	static constexpr const char* name() {return "RICsubsequentActionType";}
	using parent_t = asn::enumerated<2, 0, true>;
	typedef enum {
		Continue
		,wait
	} index_t;

};

/*
RICtimeToWait ::= ENUMERATED{
	zero,
	w1ms,
	w2ms,
	w5ms,
	w10ms,
	w20ms,
	w30ms,
	w40ms,
	w50ms,
	w100ms,
	w200ms,
	w500ms,
	w1s,
	w2s,
	w5s,
	w10s,
	w20s,
	w60s,
	...
}
*/

struct RICtimeToWait : asn::enumerated<18, 0, true>
{
	static constexpr const char* name() {return "RICtimeToWait";}
	using parent_t = asn::enumerated<18, 0, true>;
	typedef enum {
		zero
		,w1ms
		,w2ms
		,w5ms
		,w10ms
		,w20ms
		,w30ms
		,w40ms
		,w50ms
		,w100ms
		,w200ms
		,w500ms
		,w1s
		,w2s
		,w5s
		,w10s
		,w20s
		,w60s
	} index_t;

};

/*
RICsubsequentAction ::=SEQUENCE{
	ricSubsequentActionType		RICsubsequentActionType,
	ricTimeToWait				RICtimeToWait,
	...
}
*/

struct RICsubsequentAction : asn::sequence<2, 0, true, 0>
{
	static constexpr const char* name() {return "RICsubsequentAction";}
	using parent_t = asn::sequence<2, 0, true, 0>;
	struct ricSubsequentActionType_t : RICsubsequentActionType
	{
		static constexpr const char* name() {return "ricSubsequentActionType_t";}
		using parent_t = RICsubsequentActionType;

	};
	ricSubsequentActionType_t& ref_ricSubsequentActionType() {return ricSubsequentActionType;}
	ricSubsequentActionType_t const& ref_ricSubsequentActionType() const {return ricSubsequentActionType;}
	struct ricTimeToWait_t : RICtimeToWait
	{
		static constexpr const char* name() {return "ricTimeToWait_t";}
		using parent_t = RICtimeToWait;

	};
	ricTimeToWait_t& ref_ricTimeToWait() {return ricTimeToWait;}
	ricTimeToWait_t const& ref_ricTimeToWait() const {return ricTimeToWait;}
	template<typename V> void decode(V& v)
	{
		v(ricSubsequentActionType);
		v(ricTimeToWait);

	};
	template<typename V> void encode(V& v) const
	{
		v(ricSubsequentActionType);
		v(ricTimeToWait);

	};
	void clear()
	{
		ricSubsequentActionType.clear();
		ricTimeToWait.clear();

	};
	private:
	ricSubsequentActionType_t	ricSubsequentActionType;
	ricTimeToWait_t	ricTimeToWait;

};
