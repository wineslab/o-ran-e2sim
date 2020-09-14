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
#include "X2AP-PDU-Contents.hpp"
#include "X2AP-Constants.hpp"
#include "E2AP-PDU-Contents.hpp"
#include "E2AP-Constants.hpp"

/*
E2AP-ELEMENTARY-PROCEDURE ::= CLASS {
	&InitiatingMessage				,
	&SuccessfulOutcome				        OPTIONAL,
	&UnsuccessfulOutcome				    OPTIONAL,
	&procedureCode			ProcedureCode 	UNIQUE,
	&criticality			Criticality 	DEFAULT ignore
}
WITH SYNTAX {
	INITIATING MESSAGE		&InitiatingMessage
	[SUCCESSFUL OUTCOME		&SuccessfulOutcome]
	[UNSUCCESSFUL OUTCOME	&UnsuccessfulOutcome]
	PROCEDURE CODE			&procedureCode
	[CRITICALITY			&criticality]
}
*/

struct E2AP_ELEMENTARY_PROCEDURE
{
	struct procedureCode_t : ProcedureCode
	{
		static constexpr const char* name() {return "procedureCode_t";}
		using parent_t = ProcedureCode;

	};
	struct criticality_t : Criticality
	{
		static constexpr const char* name() {return "criticality_t";}
		using parent_t = Criticality;

	};

};
/*
E2AP-ELEMENTARY-PROCEDURES E2AP-ELEMENTARY-PROCEDURE ::= {
    E2AP-ELEMENTARY-PROCEDURES-CLASS-1			|
    E2AP-ELEMENTARY-PROCEDURES-CLASS-2,
    ...
}
*/

struct E2AP_ELEMENTARY_PROCEDURES
{
	struct InitiatingMessage_t : asn::typefield<true>
	{
		~InitiatingMessage_t()	{clear();}
		size_t get_index() const {return type;}
		RICsubscriptionRequest& select_id_ricSubscription() { return set<RICsubscriptionRequest>(1); }
		RICsubscriptionRequest const* get_id_ricSubscription() const { return get<RICsubscriptionRequest>(1); }
		RICsubscriptionDeleteRequest& select_id_ricSubscriptionDelete() { return set<RICsubscriptionDeleteRequest>(2); }
		RICsubscriptionDeleteRequest const* get_id_ricSubscriptionDelete() const { return get<RICsubscriptionDeleteRequest>(2); }
		RICserviceUpdate& select_id_ricServiceUpdate() { return set<RICserviceUpdate>(3); }
		RICserviceUpdate const* get_id_ricServiceUpdate() const { return get<RICserviceUpdate>(3); }
		RICcontrolRequest& select_id_ricControl() { return set<RICcontrolRequest>(4); }
		RICcontrolRequest const* get_id_ricControl() const { return get<RICcontrolRequest>(4); }
		X2SetupRequest& select_id_x2Setup() { return set<X2SetupRequest>(5); }
		X2SetupRequest const* get_id_x2Setup() const { return get<X2SetupRequest>(5); }
		ENDCX2SetupRequest& select_id_endcX2Setup() { return set<ENDCX2SetupRequest>(6); }
		ENDCX2SetupRequest const* get_id_endcX2Setup() const { return get<ENDCX2SetupRequest>(6); }
		ResourceStatusRequest& select_id_resourceStatusReportingInitiation() { return set<ResourceStatusRequest>(7); }
		ResourceStatusRequest const* get_id_resourceStatusReportingInitiation() const { return get<ResourceStatusRequest>(7); }
		ENBConfigurationUpdate& select_id_eNBConfigurationUpdate() { return set<ENBConfigurationUpdate>(8); }
		ENBConfigurationUpdate const* get_id_eNBConfigurationUpdate() const { return get<ENBConfigurationUpdate>(8); }
		ENDCConfigurationUpdate& select_id_endcConfigurationUpdate() { return set<ENDCConfigurationUpdate>(9); }
		ENDCConfigurationUpdate const* get_id_endcConfigurationUpdate() const { return get<ENDCConfigurationUpdate>(9); }
		ResetRequest& select_id_reset() { return set<ResetRequest>(10); }
		ResetRequest const* get_id_reset() const { return get<ResetRequest>(10); }
		RICindication& select_id_ricIndication() { return set<RICindication>(11); }
		RICindication const* get_id_ricIndication() const { return get<RICindication>(11); }
		RICserviceQuery& select_id_ricServiceQuery() { return set<RICserviceQuery>(12); }
		RICserviceQuery const* get_id_ricServiceQuery() const { return get<RICserviceQuery>(12); }
		LoadInformation& select_id_loadIndication() { return set<LoadInformation>(13); }
		LoadInformation const* get_id_loadIndication() const { return get<LoadInformation>(13); }
		GNBStatusIndication& select_id_gNBStatusIndication() { return set<GNBStatusIndication>(14); }
		GNBStatusIndication const* get_id_gNBStatusIndication() const { return get<GNBStatusIndication>(14); }
		ResourceStatusUpdate& select_id_resourceStatusReporting() { return set<ResourceStatusUpdate>(15); }
		ResourceStatusUpdate const* get_id_resourceStatusReporting() const { return get<ResourceStatusUpdate>(15); }
		ErrorIndication& select_id_errorIndication() { return set<ErrorIndication>(16); }
		ErrorIndication const* get_id_errorIndication() const { return get<ErrorIndication>(16); }
		bool is_unknown() const { return type == 17; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RICsubscriptionRequest>(); break;
			case 2: var.destroy<RICsubscriptionDeleteRequest>(); break;
			case 3: var.destroy<RICserviceUpdate>(); break;
			case 4: var.destroy<RICcontrolRequest>(); break;
			case 5: var.destroy<X2SetupRequest>(); break;
			case 6: var.destroy<ENDCX2SetupRequest>(); break;
			case 7: var.destroy<ResourceStatusRequest>(); break;
			case 8: var.destroy<ENBConfigurationUpdate>(); break;
			case 9: var.destroy<ENDCConfigurationUpdate>(); break;
			case 10: var.destroy<ResetRequest>(); break;
			case 11: var.destroy<RICindication>(); break;
			case 12: var.destroy<RICserviceQuery>(); break;
			case 13: var.destroy<LoadInformation>(); break;
			case 14: var.destroy<GNBStatusIndication>(); break;
			case 15: var.destroy<ResourceStatusUpdate>(); break;
			case 16: var.destroy<ErrorIndication>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RICsubscriptionRequest>(1);
			v.template operator()<RICsubscriptionDeleteRequest>(2);
			v.template operator()<RICserviceUpdate>(3);
			v.template operator()<RICcontrolRequest>(4);
			v.template operator()<X2SetupRequest>(5);
			v.template operator()<ENDCX2SetupRequest>(6);
			v.template operator()<ResourceStatusRequest>(7);
			v.template operator()<ENBConfigurationUpdate>(8);
			v.template operator()<ENDCConfigurationUpdate>(9);
			v.template operator()<ResetRequest>(10);
			v.template operator()<RICindication>(11);
			v.template operator()<RICserviceQuery>(12);
			v.template operator()<LoadInformation>(13);
			v.template operator()<GNBStatusIndication>(14);
			v.template operator()<ResourceStatusUpdate>(15);
			v.template operator()<ErrorIndication>(16);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_ricSubscription()); return true;
			case 2: v(select_id_ricSubscriptionDelete()); return true;
			case 3: v(select_id_ricServiceUpdate()); return true;
			case 4: v(select_id_ricControl()); return true;
			case 5: v(select_id_x2Setup()); return true;
			case 6: v(select_id_endcX2Setup()); return true;
			case 7: v(select_id_resourceStatusReportingInitiation()); return true;
			case 8: v(select_id_eNBConfigurationUpdate()); return true;
			case 9: v(select_id_endcConfigurationUpdate()); return true;
			case 10: v(select_id_reset()); return true;
			case 11: v(select_id_ricIndication()); return true;
			case 12: v(select_id_ricServiceQuery()); return true;
			case 13: v(select_id_loadIndication()); return true;
			case 14: v(select_id_gNBStatusIndication()); return true;
			case 15: v(select_id_resourceStatusReporting()); return true;
			case 16: v(select_id_errorIndication()); return true;
			case 17: if(type != 17) {clear(); asn::base::set();} type = 17; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RICsubscriptionRequest>()); return true;
			case 2: v(var.as<RICsubscriptionDeleteRequest>()); return true;
			case 3: v(var.as<RICserviceUpdate>()); return true;
			case 4: v(var.as<RICcontrolRequest>()); return true;
			case 5: v(var.as<X2SetupRequest>()); return true;
			case 6: v(var.as<ENDCX2SetupRequest>()); return true;
			case 7: v(var.as<ResourceStatusRequest>()); return true;
			case 8: v(var.as<ENBConfigurationUpdate>()); return true;
			case 9: v(var.as<ENDCConfigurationUpdate>()); return true;
			case 10: v(var.as<ResetRequest>()); return true;
			case 11: v(var.as<RICindication>()); return true;
			case 12: v(var.as<RICserviceQuery>()); return true;
			case 13: v(var.as<LoadInformation>()); return true;
			case 14: v(var.as<GNBStatusIndication>()); return true;
			case 15: v(var.as<ResourceStatusUpdate>()); return true;
			case 16: v(var.as<ErrorIndication>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(ENBConfigurationUpdate)];
			char dummy2[sizeof(ENDCConfigurationUpdate)];
			char dummy3[sizeof(ENDCX2SetupRequest)];
			char dummy4[sizeof(ErrorIndication)];
			char dummy5[sizeof(GNBStatusIndication)];
			char dummy6[sizeof(LoadInformation)];
			char dummy7[sizeof(RICcontrolRequest)];
			char dummy8[sizeof(RICindication)];
			char dummy9[sizeof(RICserviceQuery)];
			char dummy10[sizeof(RICserviceUpdate)];
			char dummy11[sizeof(RICsubscriptionDeleteRequest)];
			char dummy12[sizeof(RICsubscriptionRequest)];
			char dummy13[sizeof(ResetRequest)];
			char dummy14[sizeof(ResourceStatusRequest)];
			char dummy15[sizeof(ResourceStatusUpdate)];
			char dummy16[sizeof(X2SetupRequest)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct SuccessfulOutcome_t : asn::typefield<true>
	{
		~SuccessfulOutcome_t()	{clear();}
		size_t get_index() const {return type;}
		RICsubscriptionResponse& select_id_ricSubscription() { return set<RICsubscriptionResponse>(1); }
		RICsubscriptionResponse const* get_id_ricSubscription() const { return get<RICsubscriptionResponse>(1); }
		RICsubscriptionDeleteResponse& select_id_ricSubscriptionDelete() { return set<RICsubscriptionDeleteResponse>(2); }
		RICsubscriptionDeleteResponse const* get_id_ricSubscriptionDelete() const { return get<RICsubscriptionDeleteResponse>(2); }
		RICserviceUpdateAcknowledge& select_id_ricServiceUpdate() { return set<RICserviceUpdateAcknowledge>(3); }
		RICserviceUpdateAcknowledge const* get_id_ricServiceUpdate() const { return get<RICserviceUpdateAcknowledge>(3); }
		RICcontrolAcknowledge& select_id_ricControl() { return set<RICcontrolAcknowledge>(4); }
		RICcontrolAcknowledge const* get_id_ricControl() const { return get<RICcontrolAcknowledge>(4); }
		X2SetupResponse& select_id_x2Setup() { return set<X2SetupResponse>(5); }
		X2SetupResponse const* get_id_x2Setup() const { return get<X2SetupResponse>(5); }
		ENDCX2SetupResponse& select_id_endcX2Setup() { return set<ENDCX2SetupResponse>(6); }
		ENDCX2SetupResponse const* get_id_endcX2Setup() const { return get<ENDCX2SetupResponse>(6); }
		ResourceStatusResponse& select_id_resourceStatusReportingInitiation() { return set<ResourceStatusResponse>(7); }
		ResourceStatusResponse const* get_id_resourceStatusReportingInitiation() const { return get<ResourceStatusResponse>(7); }
		ENBConfigurationUpdateAcknowledge& select_id_eNBConfigurationUpdate() { return set<ENBConfigurationUpdateAcknowledge>(8); }
		ENBConfigurationUpdateAcknowledge const* get_id_eNBConfigurationUpdate() const { return get<ENBConfigurationUpdateAcknowledge>(8); }
		ENDCConfigurationUpdateAcknowledge& select_id_endcConfigurationUpdate() { return set<ENDCConfigurationUpdateAcknowledge>(9); }
		ENDCConfigurationUpdateAcknowledge const* get_id_endcConfigurationUpdate() const { return get<ENDCConfigurationUpdateAcknowledge>(9); }
		ResetResponse& select_id_reset() { return set<ResetResponse>(10); }
		ResetResponse const* get_id_reset() const { return get<ResetResponse>(10); }
		bool is_unknown() const { return type == 17; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RICsubscriptionResponse>(); break;
			case 2: var.destroy<RICsubscriptionDeleteResponse>(); break;
			case 3: var.destroy<RICserviceUpdateAcknowledge>(); break;
			case 4: var.destroy<RICcontrolAcknowledge>(); break;
			case 5: var.destroy<X2SetupResponse>(); break;
			case 6: var.destroy<ENDCX2SetupResponse>(); break;
			case 7: var.destroy<ResourceStatusResponse>(); break;
			case 8: var.destroy<ENBConfigurationUpdateAcknowledge>(); break;
			case 9: var.destroy<ENDCConfigurationUpdateAcknowledge>(); break;
			case 10: var.destroy<ResetResponse>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RICsubscriptionResponse>(1);
			v.template operator()<RICsubscriptionDeleteResponse>(2);
			v.template operator()<RICserviceUpdateAcknowledge>(3);
			v.template operator()<RICcontrolAcknowledge>(4);
			v.template operator()<X2SetupResponse>(5);
			v.template operator()<ENDCX2SetupResponse>(6);
			v.template operator()<ResourceStatusResponse>(7);
			v.template operator()<ENBConfigurationUpdateAcknowledge>(8);
			v.template operator()<ENDCConfigurationUpdateAcknowledge>(9);
			v.template operator()<ResetResponse>(10);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_ricSubscription()); return true;
			case 2: v(select_id_ricSubscriptionDelete()); return true;
			case 3: v(select_id_ricServiceUpdate()); return true;
			case 4: v(select_id_ricControl()); return true;
			case 5: v(select_id_x2Setup()); return true;
			case 6: v(select_id_endcX2Setup()); return true;
			case 7: v(select_id_resourceStatusReportingInitiation()); return true;
			case 8: v(select_id_eNBConfigurationUpdate()); return true;
			case 9: v(select_id_endcConfigurationUpdate()); return true;
			case 10: v(select_id_reset()); return true;
			case 17: if(type != 17) {clear(); asn::base::set();} type = 17; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RICsubscriptionResponse>()); return true;
			case 2: v(var.as<RICsubscriptionDeleteResponse>()); return true;
			case 3: v(var.as<RICserviceUpdateAcknowledge>()); return true;
			case 4: v(var.as<RICcontrolAcknowledge>()); return true;
			case 5: v(var.as<X2SetupResponse>()); return true;
			case 6: v(var.as<ENDCX2SetupResponse>()); return true;
			case 7: v(var.as<ResourceStatusResponse>()); return true;
			case 8: v(var.as<ENBConfigurationUpdateAcknowledge>()); return true;
			case 9: v(var.as<ENDCConfigurationUpdateAcknowledge>()); return true;
			case 10: v(var.as<ResetResponse>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(ENBConfigurationUpdateAcknowledge)];
			char dummy2[sizeof(ENDCConfigurationUpdateAcknowledge)];
			char dummy3[sizeof(ENDCX2SetupResponse)];
			char dummy4[sizeof(RICcontrolAcknowledge)];
			char dummy5[sizeof(RICserviceUpdateAcknowledge)];
			char dummy6[sizeof(RICsubscriptionDeleteResponse)];
			char dummy7[sizeof(RICsubscriptionResponse)];
			char dummy8[sizeof(ResetResponse)];
			char dummy9[sizeof(ResourceStatusResponse)];
			char dummy10[sizeof(X2SetupResponse)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct UnsuccessfulOutcome_t : asn::typefield<true>
	{
		~UnsuccessfulOutcome_t()	{clear();}
		size_t get_index() const {return type;}
		RICsubscriptionFailure& select_id_ricSubscription() { return set<RICsubscriptionFailure>(1); }
		RICsubscriptionFailure const* get_id_ricSubscription() const { return get<RICsubscriptionFailure>(1); }
		RICsubscriptionDeleteFailure& select_id_ricSubscriptionDelete() { return set<RICsubscriptionDeleteFailure>(2); }
		RICsubscriptionDeleteFailure const* get_id_ricSubscriptionDelete() const { return get<RICsubscriptionDeleteFailure>(2); }
		RICserviceUpdateFailure& select_id_ricServiceUpdate() { return set<RICserviceUpdateFailure>(3); }
		RICserviceUpdateFailure const* get_id_ricServiceUpdate() const { return get<RICserviceUpdateFailure>(3); }
		RICcontrolFailure& select_id_ricControl() { return set<RICcontrolFailure>(4); }
		RICcontrolFailure const* get_id_ricControl() const { return get<RICcontrolFailure>(4); }
		X2SetupFailure& select_id_x2Setup() { return set<X2SetupFailure>(5); }
		X2SetupFailure const* get_id_x2Setup() const { return get<X2SetupFailure>(5); }
		ENDCX2SetupFailure& select_id_endcX2Setup() { return set<ENDCX2SetupFailure>(6); }
		ENDCX2SetupFailure const* get_id_endcX2Setup() const { return get<ENDCX2SetupFailure>(6); }
		ResourceStatusFailure& select_id_resourceStatusReportingInitiation() { return set<ResourceStatusFailure>(7); }
		ResourceStatusFailure const* get_id_resourceStatusReportingInitiation() const { return get<ResourceStatusFailure>(7); }
		ENBConfigurationUpdateFailure& select_id_eNBConfigurationUpdate() { return set<ENBConfigurationUpdateFailure>(8); }
		ENBConfigurationUpdateFailure const* get_id_eNBConfigurationUpdate() const { return get<ENBConfigurationUpdateFailure>(8); }
		ENDCConfigurationUpdateFailure& select_id_endcConfigurationUpdate() { return set<ENDCConfigurationUpdateFailure>(9); }
		ENDCConfigurationUpdateFailure const* get_id_endcConfigurationUpdate() const { return get<ENDCConfigurationUpdateFailure>(9); }
		bool is_unknown() const { return type == 17; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<RICsubscriptionFailure>(); break;
			case 2: var.destroy<RICsubscriptionDeleteFailure>(); break;
			case 3: var.destroy<RICserviceUpdateFailure>(); break;
			case 4: var.destroy<RICcontrolFailure>(); break;
			case 5: var.destroy<X2SetupFailure>(); break;
			case 6: var.destroy<ENDCX2SetupFailure>(); break;
			case 7: var.destroy<ResourceStatusFailure>(); break;
			case 8: var.destroy<ENBConfigurationUpdateFailure>(); break;
			case 9: var.destroy<ENDCConfigurationUpdateFailure>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<RICsubscriptionFailure>(1);
			v.template operator()<RICsubscriptionDeleteFailure>(2);
			v.template operator()<RICserviceUpdateFailure>(3);
			v.template operator()<RICcontrolFailure>(4);
			v.template operator()<X2SetupFailure>(5);
			v.template operator()<ENDCX2SetupFailure>(6);
			v.template operator()<ResourceStatusFailure>(7);
			v.template operator()<ENBConfigurationUpdateFailure>(8);
			v.template operator()<ENDCConfigurationUpdateFailure>(9);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_ricSubscription()); return true;
			case 2: v(select_id_ricSubscriptionDelete()); return true;
			case 3: v(select_id_ricServiceUpdate()); return true;
			case 4: v(select_id_ricControl()); return true;
			case 5: v(select_id_x2Setup()); return true;
			case 6: v(select_id_endcX2Setup()); return true;
			case 7: v(select_id_resourceStatusReportingInitiation()); return true;
			case 8: v(select_id_eNBConfigurationUpdate()); return true;
			case 9: v(select_id_endcConfigurationUpdate()); return true;
			case 17: if(type != 17) {clear(); asn::base::set();} type = 17; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<RICsubscriptionFailure>()); return true;
			case 2: v(var.as<RICsubscriptionDeleteFailure>()); return true;
			case 3: v(var.as<RICserviceUpdateFailure>()); return true;
			case 4: v(var.as<RICcontrolFailure>()); return true;
			case 5: v(var.as<X2SetupFailure>()); return true;
			case 6: v(var.as<ENDCX2SetupFailure>()); return true;
			case 7: v(var.as<ResourceStatusFailure>()); return true;
			case 8: v(var.as<ENBConfigurationUpdateFailure>()); return true;
			case 9: v(var.as<ENDCConfigurationUpdateFailure>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(ENBConfigurationUpdateFailure)];
			char dummy2[sizeof(ENDCConfigurationUpdateFailure)];
			char dummy3[sizeof(ENDCX2SetupFailure)];
			char dummy4[sizeof(RICcontrolFailure)];
			char dummy5[sizeof(RICserviceUpdateFailure)];
			char dummy6[sizeof(RICsubscriptionDeleteFailure)];
			char dummy7[sizeof(RICsubscriptionFailure)];
			char dummy8[sizeof(ResourceStatusFailure)];
			char dummy9[sizeof(X2SetupFailure)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct procedureCode_t : asn::fixedtypefield<E2AP_ELEMENTARY_PROCEDURE::procedureCode_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 17; }
		void clear() {type = 0;}
		void select_id_ricSubscription() { set(id_ricSubscription); type=1;}
		void select_id_ricSubscriptionDelete() { set(id_ricSubscriptionDelete); type=2;}
		void select_id_ricServiceUpdate() { set(id_ricServiceUpdate); type=3;}
		void select_id_ricControl() { set(id_ricControl); type=4;}
		void select_id_x2Setup() { set(id_x2Setup); type=5;}
		void select_id_endcX2Setup() { set(id_endcX2Setup); type=6;}
		void select_id_resourceStatusReportingInitiation() { set(id_resourceStatusReportingInitiation); type=7;}
		void select_id_eNBConfigurationUpdate() { set(id_eNBConfigurationUpdate); type=8;}
		void select_id_endcConfigurationUpdate() { set(id_endcConfigurationUpdate); type=9;}
		void select_id_reset() { set(id_reset); type=10;}
		void select_id_ricIndication() { set(id_ricIndication); type=11;}
		void select_id_ricServiceQuery() { set(id_ricServiceQuery); type=12;}
		void select_id_loadIndication() { set(id_loadIndication); type=13;}
		void select_id_gNBStatusIndication() { set(id_gNBStatusIndication); type=14;}
		void select_id_resourceStatusReporting() { set(id_resourceStatusReporting); type=15;}
		void select_id_errorIndication() { set(id_errorIndication); type=16;}
		E2AP_ELEMENTARY_PROCEDURE::procedureCode_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_ricSubscription)) { type = 1; return true; }
			else if(equal(id_ricSubscriptionDelete)) { type = 2; return true; }
			else if(equal(id_ricServiceUpdate)) { type = 3; return true; }
			else if(equal(id_ricControl)) { type = 4; return true; }
			else if(equal(id_x2Setup)) { type = 5; return true; }
			else if(equal(id_endcX2Setup)) { type = 6; return true; }
			else if(equal(id_resourceStatusReportingInitiation)) { type = 7; return true; }
			else if(equal(id_eNBConfigurationUpdate)) { type = 8; return true; }
			else if(equal(id_endcConfigurationUpdate)) { type = 9; return true; }
			else if(equal(id_reset)) { type = 10; return true; }
			else if(equal(id_ricIndication)) { type = 11; return true; }
			else if(equal(id_ricServiceQuery)) { type = 12; return true; }
			else if(equal(id_loadIndication)) { type = 13; return true; }
			else if(equal(id_gNBStatusIndication)) { type = 14; return true; }
			else if(equal(id_resourceStatusReporting)) { type = 15; return true; }
			else if(equal(id_errorIndication)) { type = 16; return true; }
			else { type = 17; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_ricSubscription);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_ricSubscriptionDelete);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_ricServiceUpdate);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_ricControl);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(id_x2Setup);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(id_endcX2Setup);} return false;
			case 7: type = 7; if(v(ref_nested())) { return equal(id_resourceStatusReportingInitiation);} return false;
			case 8: type = 8; if(v(ref_nested())) { return equal(id_eNBConfigurationUpdate);} return false;
			case 9: type = 9; if(v(ref_nested())) { return equal(id_endcConfigurationUpdate);} return false;
			case 10: type = 10; if(v(ref_nested())) { return equal(id_reset);} return false;
			case 11: type = 11; if(v(ref_nested())) { return equal(id_ricIndication);} return false;
			case 12: type = 12; if(v(ref_nested())) { return equal(id_ricServiceQuery);} return false;
			case 13: type = 13; if(v(ref_nested())) { return equal(id_loadIndication);} return false;
			case 14: type = 14; if(v(ref_nested())) { return equal(id_gNBStatusIndication);} return false;
			case 15: type = 15; if(v(ref_nested())) { return equal(id_resourceStatusReporting);} return false;
			case 16: type = 16; if(v(ref_nested())) { return equal(id_errorIndication);} return false;
			case 17: type = 17; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<E2AP_ELEMENTARY_PROCEDURE::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 17; }
		void clear() {type = 0;}
		void select_id_ricSubscription() { set(reject); type=1;}
		void select_id_ricSubscriptionDelete() { set(reject); type=2;}
		void select_id_ricServiceUpdate() { set(reject); type=3;}
		void select_id_ricControl() { set(reject); type=4;}
		void select_id_x2Setup() { set(reject); type=5;}
		void select_id_endcX2Setup() { set(reject); type=6;}
		void select_id_resourceStatusReportingInitiation() { set(reject); type=7;}
		void select_id_eNBConfigurationUpdate() { set(reject); type=8;}
		void select_id_endcConfigurationUpdate() { set(reject); type=9;}
		void select_id_reset() { set(reject); type=10;}
		void select_id_ricIndication() { set(ignore); type=11;}
		void select_id_ricServiceQuery() { set(ignore); type=12;}
		void select_id_loadIndication() { set(ignore); type=13;}
		void select_id_gNBStatusIndication() { set(ignore); type=14;}
		void select_id_resourceStatusReporting() { set(ignore); type=15;}
		void select_id_errorIndication() { set(ignore); type=16;}
		E2AP_ELEMENTARY_PROCEDURE::criticality_t const& ref_value() const {return ref_nested();}
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
			else if(equal(reject)) { type = 9; return true; }
			else if(equal(reject)) { type = 10; return true; }
			else if(equal(ignore)) { type = 11; return true; }
			else if(equal(ignore)) { type = 12; return true; }
			else if(equal(ignore)) { type = 13; return true; }
			else if(equal(ignore)) { type = 14; return true; }
			else if(equal(ignore)) { type = 15; return true; }
			else if(equal(ignore)) { type = 16; return true; }
			else { type = 17; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
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
			case 9: type = 9; if(v(ref_nested())) { return equal(reject);} return false;
			case 10: type = 10; if(v(ref_nested())) { return equal(reject);} return false;
			case 11: type = 11; if(v(ref_nested())) { return equal(ignore);} return false;
			case 12: type = 12; if(v(ref_nested())) { return equal(ignore);} return false;
			case 13: type = 13; if(v(ref_nested())) { return equal(ignore);} return false;
			case 14: type = 14; if(v(ref_nested())) { return equal(ignore);} return false;
			case 15: type = 15; if(v(ref_nested())) { return equal(ignore);} return false;
			case 16: type = 16; if(v(ref_nested())) { return equal(ignore);} return false;
			case 17: type = 17; return v(ref_nested());
			ref_nested().clear();
			}
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
InitiatingMessage ::= SEQUENCE {
	procedureCode		E2AP-ELEMENTARY-PROCEDURE.&procedureCode({E2AP-ELEMENTARY-PROCEDURES}),
	criticality			E2AP-ELEMENTARY-PROCEDURE.&criticality({E2AP-ELEMENTARY-PROCEDURES}{@procedureCode}),
	value				E2AP-ELEMENTARY-PROCEDURE.&InitiatingMessage({E2AP-ELEMENTARY-PROCEDURES}{@procedureCode})
}
*/

struct InitiatingMessage : asn::sequence<3, 0, false, 0>
{
	static constexpr const char* name() {return "InitiatingMessage";}
	using parent_t = asn::sequence<3, 0, false, 0>;
	struct procedureCode_t : E2AP_ELEMENTARY_PROCEDURES::procedureCode_t
	{
		static constexpr const char* name() {return "procedureCode_t";}
		using parent_t = typename E2AP_ELEMENTARY_PROCEDURES::procedureCode_t;
		template<typename V>  bool decode(V& v, InitiatingMessage const& c)
		{
			return E2AP_ELEMENTARY_PROCEDURES::procedureCode_t::decode(v);
		};
		template<typename V>  bool encode(V& v, InitiatingMessage const& c) const
		{
			return E2AP_ELEMENTARY_PROCEDURES::procedureCode_t::encode(v);
		};
	};
	procedureCode_t& ref_procedureCode() {return procedureCode;}
	procedureCode_t const& ref_procedureCode() const {return procedureCode;}
	struct criticality_t : E2AP_ELEMENTARY_PROCEDURES::criticality_t
	{
		static constexpr const char* name() {return "criticality_t";}
		using parent_t = typename E2AP_ELEMENTARY_PROCEDURES::criticality_t;
		template<typename V>  bool decode(V& v, InitiatingMessage const& c)
		{
			return E2AP_ELEMENTARY_PROCEDURES::criticality_t::decode(c.procedureCode.get_index(), v);
		};
		template<typename V>  bool encode(V& v, InitiatingMessage const& c) const
		{
			return E2AP_ELEMENTARY_PROCEDURES::criticality_t::encode(c.procedureCode.get_index(), v);
		};
	};
	criticality_t& ref_criticality() {return criticality;}
	criticality_t const& ref_criticality() const {return criticality;}
	struct value_t : E2AP_ELEMENTARY_PROCEDURES::InitiatingMessage_t
	{
		static constexpr const char* name() {return "value_t";}
		using parent_t = typename E2AP_ELEMENTARY_PROCEDURES::InitiatingMessage_t;
		template<typename V>  bool decode(V& v, InitiatingMessage const& c)
		{
			return E2AP_ELEMENTARY_PROCEDURES::InitiatingMessage_t::decode(c.procedureCode.get_index(), v);
		};
		template<typename V>  bool encode(V& v, InitiatingMessage const& c) const
		{
			return E2AP_ELEMENTARY_PROCEDURES::InitiatingMessage_t::encode(c.procedureCode.get_index(), v);
		};
	};
	value_t& ref_value() {return value;}
	value_t const& ref_value() const {return value;}
	template<typename V> void decode(V& v)
	{
		v(procedureCode);
		v(criticality);
		v(value);

	};
	template<typename V> void encode(V& v) const
	{
		v(procedureCode);
		v(criticality);
		v(value);

	};
	void clear()
	{
		procedureCode.clear();
		criticality.clear();
		value.clear();

	};
	private:
	procedureCode_t	procedureCode;
	criticality_t	criticality;
	value_t	value;

};
/*
SuccessfulOutcome ::= SEQUENCE {
	procedureCode		E2AP-ELEMENTARY-PROCEDURE.&procedureCode({E2AP-ELEMENTARY-PROCEDURES}),
	criticality			E2AP-ELEMENTARY-PROCEDURE.&criticality({E2AP-ELEMENTARY-PROCEDURES}{@procedureCode}),
	value				E2AP-ELEMENTARY-PROCEDURE.&SuccessfulOutcome({E2AP-ELEMENTARY-PROCEDURES}{@procedureCode})
}
*/

struct SuccessfulOutcome : asn::sequence<3, 0, false, 0>
{
	static constexpr const char* name() {return "SuccessfulOutcome";}
	using parent_t = asn::sequence<3, 0, false, 0>;
	struct procedureCode_t : E2AP_ELEMENTARY_PROCEDURES::procedureCode_t
	{
		static constexpr const char* name() {return "procedureCode_t";}
		using parent_t = typename E2AP_ELEMENTARY_PROCEDURES::procedureCode_t;
		template<typename V>  bool decode(V& v, SuccessfulOutcome const& c)
		{
			return E2AP_ELEMENTARY_PROCEDURES::procedureCode_t::decode(v);
		};
		template<typename V>  bool encode(V& v, SuccessfulOutcome const& c) const
		{
			return E2AP_ELEMENTARY_PROCEDURES::procedureCode_t::encode(v);
		};
	};
	procedureCode_t& ref_procedureCode() {return procedureCode;}
	procedureCode_t const& ref_procedureCode() const {return procedureCode;}
	struct criticality_t : E2AP_ELEMENTARY_PROCEDURES::criticality_t
	{
		static constexpr const char* name() {return "criticality_t";}
		using parent_t = typename E2AP_ELEMENTARY_PROCEDURES::criticality_t;
		template<typename V>  bool decode(V& v, SuccessfulOutcome const& c)
		{
			return E2AP_ELEMENTARY_PROCEDURES::criticality_t::decode(c.procedureCode.get_index(), v);
		};
		template<typename V>  bool encode(V& v, SuccessfulOutcome const& c) const
		{
			return E2AP_ELEMENTARY_PROCEDURES::criticality_t::encode(c.procedureCode.get_index(), v);
		};
	};
	criticality_t& ref_criticality() {return criticality;}
	criticality_t const& ref_criticality() const {return criticality;}
	struct value_t : E2AP_ELEMENTARY_PROCEDURES::SuccessfulOutcome_t
	{
		static constexpr const char* name() {return "value_t";}
		using parent_t = typename E2AP_ELEMENTARY_PROCEDURES::SuccessfulOutcome_t;
		template<typename V>  bool decode(V& v, SuccessfulOutcome const& c)
		{
			return E2AP_ELEMENTARY_PROCEDURES::SuccessfulOutcome_t::decode(c.procedureCode.get_index(), v);
		};
		template<typename V>  bool encode(V& v, SuccessfulOutcome const& c) const
		{
			return E2AP_ELEMENTARY_PROCEDURES::SuccessfulOutcome_t::encode(c.procedureCode.get_index(), v);
		};
	};
	value_t& ref_value() {return value;}
	value_t const& ref_value() const {return value;}
	template<typename V> void decode(V& v)
	{
		v(procedureCode);
		v(criticality);
		v(value);

	};
	template<typename V> void encode(V& v) const
	{
		v(procedureCode);
		v(criticality);
		v(value);

	};
	void clear()
	{
		procedureCode.clear();
		criticality.clear();
		value.clear();

	};
	private:
	procedureCode_t	procedureCode;
	criticality_t	criticality;
	value_t	value;

};
/*
UnsuccessfulOutcome ::= SEQUENCE {
	procedureCode		E2AP-ELEMENTARY-PROCEDURE.&procedureCode({E2AP-ELEMENTARY-PROCEDURES}),
	criticality			E2AP-ELEMENTARY-PROCEDURE.&criticality({E2AP-ELEMENTARY-PROCEDURES}{@procedureCode}),
	value				E2AP-ELEMENTARY-PROCEDURE.&UnsuccessfulOutcome({E2AP-ELEMENTARY-PROCEDURES}{@procedureCode})
}
*/

struct UnsuccessfulOutcome : asn::sequence<3, 0, false, 0>
{
	static constexpr const char* name() {return "UnsuccessfulOutcome";}
	using parent_t = asn::sequence<3, 0, false, 0>;
	struct procedureCode_t : E2AP_ELEMENTARY_PROCEDURES::procedureCode_t
	{
		static constexpr const char* name() {return "procedureCode_t";}
		using parent_t = typename E2AP_ELEMENTARY_PROCEDURES::procedureCode_t;
		template<typename V>  bool decode(V& v, UnsuccessfulOutcome const& c)
		{
			return E2AP_ELEMENTARY_PROCEDURES::procedureCode_t::decode(v);
		};
		template<typename V>  bool encode(V& v, UnsuccessfulOutcome const& c) const
		{
			return E2AP_ELEMENTARY_PROCEDURES::procedureCode_t::encode(v);
		};
	};
	procedureCode_t& ref_procedureCode() {return procedureCode;}
	procedureCode_t const& ref_procedureCode() const {return procedureCode;}
	struct criticality_t : E2AP_ELEMENTARY_PROCEDURES::criticality_t
	{
		static constexpr const char* name() {return "criticality_t";}
		using parent_t = typename E2AP_ELEMENTARY_PROCEDURES::criticality_t;
		template<typename V>  bool decode(V& v, UnsuccessfulOutcome const& c)
		{
			return E2AP_ELEMENTARY_PROCEDURES::criticality_t::decode(c.procedureCode.get_index(), v);
		};
		template<typename V>  bool encode(V& v, UnsuccessfulOutcome const& c) const
		{
			return E2AP_ELEMENTARY_PROCEDURES::criticality_t::encode(c.procedureCode.get_index(), v);
		};
	};
	criticality_t& ref_criticality() {return criticality;}
	criticality_t const& ref_criticality() const {return criticality;}
	struct value_t : E2AP_ELEMENTARY_PROCEDURES::UnsuccessfulOutcome_t
	{
		static constexpr const char* name() {return "value_t";}
		using parent_t = typename E2AP_ELEMENTARY_PROCEDURES::UnsuccessfulOutcome_t;
		template<typename V>  bool decode(V& v, UnsuccessfulOutcome const& c)
		{
			return E2AP_ELEMENTARY_PROCEDURES::UnsuccessfulOutcome_t::decode(c.procedureCode.get_index(), v);
		};
		template<typename V>  bool encode(V& v, UnsuccessfulOutcome const& c) const
		{
			return E2AP_ELEMENTARY_PROCEDURES::UnsuccessfulOutcome_t::encode(c.procedureCode.get_index(), v);
		};
	};
	value_t& ref_value() {return value;}
	value_t const& ref_value() const {return value;}
	template<typename V> void decode(V& v)
	{
		v(procedureCode);
		v(criticality);
		v(value);

	};
	template<typename V> void encode(V& v) const
	{
		v(procedureCode);
		v(criticality);
		v(value);

	};
	void clear()
	{
		procedureCode.clear();
		criticality.clear();
		value.clear();

	};
	private:
	procedureCode_t	procedureCode;
	criticality_t	criticality;
	value_t	value;

};
/*
E2AP-PDU ::= CHOICE {
	initiatingMessage	InitiatingMessage,
	successfulOutcome	SuccessfulOutcome,
	unsuccessfulOutcome	UnsuccessfulOutcome,
	...
}
*/

struct E2AP_PDU : asn::choice<3, 0, true>
{
	static constexpr const char* name() {return "E2AP-PDU";}
	using parent_t = asn::choice<3, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 4;}
	void set_unknown() { set_index(4);  }
	~E2AP_PDU() {clear();}
	struct initiatingMessage_t : InitiatingMessage
	{
		static constexpr const char* name() {return "initiatingMessage_t";}
		using parent_t = InitiatingMessage;

	};
	struct successfulOutcome_t : SuccessfulOutcome
	{
		static constexpr const char* name() {return "successfulOutcome_t";}
		using parent_t = SuccessfulOutcome;

	};
	struct unsuccessfulOutcome_t : UnsuccessfulOutcome
	{
		static constexpr const char* name() {return "unsuccessfulOutcome_t";}
		using parent_t = UnsuccessfulOutcome;

	};
	void clear()
	{
		switch(get_index())
		{
		case 1: var.destroy<initiatingMessage_t>(); break;
		case 2: var.destroy<successfulOutcome_t>(); break;
		case 3: var.destroy<unsuccessfulOutcome_t>(); break;
		}
		index = 0;
		base::clear();
	}
	template<typename V> bool decode(size_t idx, V& v)
	{
		clear();
		switch(idx)
		{
		case 1: set_index(1); return v(var.build<initiatingMessage_t>());
		case 2: set_index(2); return v(var.build<successfulOutcome_t>());
		case 3: set_index(3); return v(var.build<unsuccessfulOutcome_t>());
		}
		return false;

	}
	template<typename V> bool encode(V& v) const
	{
		switch(get_index())
		{
		case 1: return v(var.as<initiatingMessage_t>());
		case 2: return v(var.as<successfulOutcome_t>());
		case 3: return v(var.as<unsuccessfulOutcome_t>());
		}
		return false;
	}
	template<typename V> static inline void enumerate(V& v)
	{
		v.template operator()<initiatingMessage_t>(1);
		v.template operator()<successfulOutcome_t>(2);
		v.template operator()<unsuccessfulOutcome_t>(3);

	}
	initiatingMessage_t& select_initiatingMessage() { if(get_index() != 1) { clear(); set_index(1); return var.build<initiatingMessage_t>();} return var.as<initiatingMessage_t>();}
	initiatingMessage_t const* get_initiatingMessage() const { if(get_index() == 1) { return &var.as<initiatingMessage_t>();} return nullptr; }
	successfulOutcome_t& select_successfulOutcome() { if(get_index() != 2) { clear(); set_index(2); return var.build<successfulOutcome_t>();} return var.as<successfulOutcome_t>();}
	successfulOutcome_t const* get_successfulOutcome() const { if(get_index() == 2) { return &var.as<successfulOutcome_t>();} return nullptr; }
	unsuccessfulOutcome_t& select_unsuccessfulOutcome() { if(get_index() != 3) { clear(); set_index(3); return var.build<unsuccessfulOutcome_t>();} return var.as<unsuccessfulOutcome_t>();}
	unsuccessfulOutcome_t const* get_unsuccessfulOutcome() const { if(get_index() == 3) { return &var.as<unsuccessfulOutcome_t>();} return nullptr; }
	private:
	void set_index(index_type i) {index = i; base::set();}
	union union_type
	{
		char dummy1[sizeof(initiatingMessage_t)];
		char dummy2[sizeof(successfulOutcome_t)];
		char dummy3[sizeof(unsuccessfulOutcome_t)];

	};
	asn::variant<sizeof(union_type)>	var;
	index_type	index {0};
};
