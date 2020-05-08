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

/*
X2AP-ELEMENTARY-PROCEDURE ::= CLASS {
	&InitiatingMessage				,
	&SuccessfulOutcome				OPTIONAL,
	&UnsuccessfulOutcome				OPTIONAL,
	&procedureCode			ProcedureCode 	UNIQUE,
	&criticality			Criticality 	DEFAULT ignore
}
WITH SYNTAX {
	INITIATING MESSAGE		&InitiatingMessage
	[SUCCESSFUL OUTCOME		&SuccessfulOutcome]
	[UNSUCCESSFUL OUTCOME		&UnsuccessfulOutcome]
	PROCEDURE CODE			&procedureCode
	[CRITICALITY			&criticality]
}
*/

struct X2AP_ELEMENTARY_PROCEDURE
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
X2AP-ELEMENTARY-PROCEDURES X2AP-ELEMENTARY-PROCEDURE ::= {
	X2AP-ELEMENTARY-PROCEDURES-CLASS-1			|
	X2AP-ELEMENTARY-PROCEDURES-CLASS-2			,
	...
}
*/

struct X2AP_ELEMENTARY_PROCEDURES
{
	struct InitiatingMessage_t : asn::typefield<true>
	{
		~InitiatingMessage_t()	{clear();}
		size_t get_index() const {return type;}
		HandoverRequest& select_id_handoverPreparation() { return set<HandoverRequest>(1); }
		HandoverRequest const* get_id_handoverPreparation() const { return get<HandoverRequest>(1); }
		ResetRequest& select_id_reset() { return set<ResetRequest>(2); }
		ResetRequest const* get_id_reset() const { return get<ResetRequest>(2); }
		X2SetupRequest& select_id_x2Setup() { return set<X2SetupRequest>(3); }
		X2SetupRequest const* get_id_x2Setup() const { return get<X2SetupRequest>(3); }
		ResourceStatusRequest& select_id_resourceStatusReportingInitiation() { return set<ResourceStatusRequest>(4); }
		ResourceStatusRequest const* get_id_resourceStatusReportingInitiation() const { return get<ResourceStatusRequest>(4); }
		ENBConfigurationUpdate& select_id_eNBConfigurationUpdate() { return set<ENBConfigurationUpdate>(5); }
		ENBConfigurationUpdate const* get_id_eNBConfigurationUpdate() const { return get<ENBConfigurationUpdate>(5); }
		MobilityChangeRequest& select_id_mobilitySettingsChange() { return set<MobilityChangeRequest>(6); }
		MobilityChangeRequest const* get_id_mobilitySettingsChange() const { return get<MobilityChangeRequest>(6); }
		CellActivationRequest& select_id_cellActivation() { return set<CellActivationRequest>(7); }
		CellActivationRequest const* get_id_cellActivation() const { return get<CellActivationRequest>(7); }
		SeNBAdditionRequest& select_id_seNBAdditionPreparation() { return set<SeNBAdditionRequest>(8); }
		SeNBAdditionRequest const* get_id_seNBAdditionPreparation() const { return get<SeNBAdditionRequest>(8); }
		SeNBModificationRequest& select_id_meNBinitiatedSeNBModificationPreparation() { return set<SeNBModificationRequest>(9); }
		SeNBModificationRequest const* get_id_meNBinitiatedSeNBModificationPreparation() const { return get<SeNBModificationRequest>(9); }
		SeNBModificationRequired& select_id_seNBinitiatedSeNBModification() { return set<SeNBModificationRequired>(10); }
		SeNBModificationRequired const* get_id_seNBinitiatedSeNBModification() const { return get<SeNBModificationRequired>(10); }
		SeNBReleaseRequired& select_id_seNBinitiatedSeNBRelease() { return set<SeNBReleaseRequired>(11); }
		SeNBReleaseRequired const* get_id_seNBinitiatedSeNBRelease() const { return get<SeNBReleaseRequired>(11); }
		X2RemovalRequest& select_id_x2Removal() { return set<X2RemovalRequest>(12); }
		X2RemovalRequest const* get_id_x2Removal() const { return get<X2RemovalRequest>(12); }
		RetrieveUEContextRequest& select_id_retrieveUEContext() { return set<RetrieveUEContextRequest>(13); }
		RetrieveUEContextRequest const* get_id_retrieveUEContext() const { return get<RetrieveUEContextRequest>(13); }
		SgNBAdditionRequest& select_id_sgNBAdditionPreparation() { return set<SgNBAdditionRequest>(14); }
		SgNBAdditionRequest const* get_id_sgNBAdditionPreparation() const { return get<SgNBAdditionRequest>(14); }
		SgNBModificationRequest& select_id_meNBinitiatedSgNBModificationPreparation() { return set<SgNBModificationRequest>(15); }
		SgNBModificationRequest const* get_id_meNBinitiatedSgNBModificationPreparation() const { return get<SgNBModificationRequest>(15); }
		SgNBModificationRequired& select_id_sgNBinitiatedSgNBModification() { return set<SgNBModificationRequired>(16); }
		SgNBModificationRequired const* get_id_sgNBinitiatedSgNBModification() const { return get<SgNBModificationRequired>(16); }
		SgNBReleaseRequest& select_id_meNBinitiatedSgNBRelease() { return set<SgNBReleaseRequest>(17); }
		SgNBReleaseRequest const* get_id_meNBinitiatedSgNBRelease() const { return get<SgNBReleaseRequest>(17); }
		SgNBReleaseRequired& select_id_sgNBinitiatedSgNBRelease() { return set<SgNBReleaseRequired>(18); }
		SgNBReleaseRequired const* get_id_sgNBinitiatedSgNBRelease() const { return get<SgNBReleaseRequired>(18); }
		SgNBChangeRequired& select_id_sgNBChange() { return set<SgNBChangeRequired>(19); }
		SgNBChangeRequired const* get_id_sgNBChange() const { return get<SgNBChangeRequired>(19); }
		ENDCX2SetupRequest& select_id_endcX2Setup() { return set<ENDCX2SetupRequest>(20); }
		ENDCX2SetupRequest const* get_id_endcX2Setup() const { return get<ENDCX2SetupRequest>(20); }
		ENDCConfigurationUpdate& select_id_endcConfigurationUpdate() { return set<ENDCConfigurationUpdate>(21); }
		ENDCConfigurationUpdate const* get_id_endcConfigurationUpdate() const { return get<ENDCConfigurationUpdate>(21); }
		ENDCCellActivationRequest& select_id_endcCellActivation() { return set<ENDCCellActivationRequest>(22); }
		ENDCCellActivationRequest const* get_id_endcCellActivation() const { return get<ENDCCellActivationRequest>(22); }
		ENDCPartialResetRequired& select_id_endcPartialReset() { return set<ENDCPartialResetRequired>(23); }
		ENDCPartialResetRequired const* get_id_endcPartialReset() const { return get<ENDCPartialResetRequired>(23); }
		EUTRANRCellResourceCoordinationRequest& select_id_eUTRANRCellResourceCoordination() { return set<EUTRANRCellResourceCoordinationRequest>(24); }
		EUTRANRCellResourceCoordinationRequest const* get_id_eUTRANRCellResourceCoordination() const { return get<EUTRANRCellResourceCoordinationRequest>(24); }
		ENDCX2RemovalRequest& select_id_endcX2Removal() { return set<ENDCX2RemovalRequest>(25); }
		ENDCX2RemovalRequest const* get_id_endcX2Removal() const { return get<ENDCX2RemovalRequest>(25); }
		SNStatusTransfer& select_id_snStatusTransfer() { return set<SNStatusTransfer>(26); }
		SNStatusTransfer const* get_id_snStatusTransfer() const { return get<SNStatusTransfer>(26); }
		UEContextRelease& select_id_uEContextRelease() { return set<UEContextRelease>(27); }
		UEContextRelease const* get_id_uEContextRelease() const { return get<UEContextRelease>(27); }
		HandoverCancel& select_id_handoverCancel() { return set<HandoverCancel>(28); }
		HandoverCancel const* get_id_handoverCancel() const { return get<HandoverCancel>(28); }
		ErrorIndication& select_id_errorIndication() { return set<ErrorIndication>(29); }
		ErrorIndication const* get_id_errorIndication() const { return get<ErrorIndication>(29); }
		ResourceStatusUpdate& select_id_resourceStatusReporting() { return set<ResourceStatusUpdate>(30); }
		ResourceStatusUpdate const* get_id_resourceStatusReporting() const { return get<ResourceStatusUpdate>(30); }
		LoadInformation& select_id_loadIndication() { return set<LoadInformation>(31); }
		LoadInformation const* get_id_loadIndication() const { return get<LoadInformation>(31); }
		PrivateMessage& select_id_privateMessage() { return set<PrivateMessage>(32); }
		PrivateMessage const* get_id_privateMessage() const { return get<PrivateMessage>(32); }
		RLFIndication& select_id_rLFIndication() { return set<RLFIndication>(33); }
		RLFIndication const* get_id_rLFIndication() const { return get<RLFIndication>(33); }
		HandoverReport& select_id_handoverReport() { return set<HandoverReport>(34); }
		HandoverReport const* get_id_handoverReport() const { return get<HandoverReport>(34); }
		X2Release& select_id_x2Release() { return set<X2Release>(35); }
		X2Release const* get_id_x2Release() const { return get<X2Release>(35); }
		X2APMessageTransfer& select_id_x2APMessageTransfer() { return set<X2APMessageTransfer>(36); }
		X2APMessageTransfer const* get_id_x2APMessageTransfer() const { return get<X2APMessageTransfer>(36); }
		SeNBReconfigurationComplete& select_id_seNBReconfigurationCompletion() { return set<SeNBReconfigurationComplete>(37); }
		SeNBReconfigurationComplete const* get_id_seNBReconfigurationCompletion() const { return get<SeNBReconfigurationComplete>(37); }
		SeNBReleaseRequest& select_id_meNBinitiatedSeNBRelease() { return set<SeNBReleaseRequest>(38); }
		SeNBReleaseRequest const* get_id_meNBinitiatedSeNBRelease() const { return get<SeNBReleaseRequest>(38); }
		SeNBCounterCheckRequest& select_id_seNBCounterCheck() { return set<SeNBCounterCheckRequest>(39); }
		SeNBCounterCheckRequest const* get_id_seNBCounterCheck() const { return get<SeNBCounterCheckRequest>(39); }
		SgNBReconfigurationComplete& select_id_sgNBReconfigurationCompletion() { return set<SgNBReconfigurationComplete>(40); }
		SgNBReconfigurationComplete const* get_id_sgNBReconfigurationCompletion() const { return get<SgNBReconfigurationComplete>(40); }
		SgNBCounterCheckRequest& select_id_sgNBCounterCheck() { return set<SgNBCounterCheckRequest>(41); }
		SgNBCounterCheckRequest const* get_id_sgNBCounterCheck() const { return get<SgNBCounterCheckRequest>(41); }
		RRCTransfer& select_id_rRCTransfer() { return set<RRCTransfer>(42); }
		RRCTransfer const* get_id_rRCTransfer() const { return get<RRCTransfer>(42); }
		SecondaryRATDataUsageReport& select_id_secondaryRATDataUsageReport() { return set<SecondaryRATDataUsageReport>(43); }
		SecondaryRATDataUsageReport const* get_id_secondaryRATDataUsageReport() const { return get<SecondaryRATDataUsageReport>(43); }
		SgNBActivityNotification& select_id_SgNBActivityNotification() { return set<SgNBActivityNotification>(44); }
		SgNBActivityNotification const* get_id_SgNBActivityNotification() const { return get<SgNBActivityNotification>(44); }
		DataForwardingAddressIndication& select_id_dataForwardingAddressIndication() { return set<DataForwardingAddressIndication>(45); }
		DataForwardingAddressIndication const* get_id_dataForwardingAddressIndication() const { return get<DataForwardingAddressIndication>(45); }
		bool is_unknown() const { return type == 46; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<HandoverRequest>(); break;
			case 2: var.destroy<ResetRequest>(); break;
			case 3: var.destroy<X2SetupRequest>(); break;
			case 4: var.destroy<ResourceStatusRequest>(); break;
			case 5: var.destroy<ENBConfigurationUpdate>(); break;
			case 6: var.destroy<MobilityChangeRequest>(); break;
			case 7: var.destroy<CellActivationRequest>(); break;
			case 8: var.destroy<SeNBAdditionRequest>(); break;
			case 9: var.destroy<SeNBModificationRequest>(); break;
			case 10: var.destroy<SeNBModificationRequired>(); break;
			case 11: var.destroy<SeNBReleaseRequired>(); break;
			case 12: var.destroy<X2RemovalRequest>(); break;
			case 13: var.destroy<RetrieveUEContextRequest>(); break;
			case 14: var.destroy<SgNBAdditionRequest>(); break;
			case 15: var.destroy<SgNBModificationRequest>(); break;
			case 16: var.destroy<SgNBModificationRequired>(); break;
			case 17: var.destroy<SgNBReleaseRequest>(); break;
			case 18: var.destroy<SgNBReleaseRequired>(); break;
			case 19: var.destroy<SgNBChangeRequired>(); break;
			case 20: var.destroy<ENDCX2SetupRequest>(); break;
			case 21: var.destroy<ENDCConfigurationUpdate>(); break;
			case 22: var.destroy<ENDCCellActivationRequest>(); break;
			case 23: var.destroy<ENDCPartialResetRequired>(); break;
			case 24: var.destroy<EUTRANRCellResourceCoordinationRequest>(); break;
			case 25: var.destroy<ENDCX2RemovalRequest>(); break;
			case 26: var.destroy<SNStatusTransfer>(); break;
			case 27: var.destroy<UEContextRelease>(); break;
			case 28: var.destroy<HandoverCancel>(); break;
			case 29: var.destroy<ErrorIndication>(); break;
			case 30: var.destroy<ResourceStatusUpdate>(); break;
			case 31: var.destroy<LoadInformation>(); break;
			case 32: var.destroy<PrivateMessage>(); break;
			case 33: var.destroy<RLFIndication>(); break;
			case 34: var.destroy<HandoverReport>(); break;
			case 35: var.destroy<X2Release>(); break;
			case 36: var.destroy<X2APMessageTransfer>(); break;
			case 37: var.destroy<SeNBReconfigurationComplete>(); break;
			case 38: var.destroy<SeNBReleaseRequest>(); break;
			case 39: var.destroy<SeNBCounterCheckRequest>(); break;
			case 40: var.destroy<SgNBReconfigurationComplete>(); break;
			case 41: var.destroy<SgNBCounterCheckRequest>(); break;
			case 42: var.destroy<RRCTransfer>(); break;
			case 43: var.destroy<SecondaryRATDataUsageReport>(); break;
			case 44: var.destroy<SgNBActivityNotification>(); break;
			case 45: var.destroy<DataForwardingAddressIndication>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<HandoverRequest>(1);
			v.template operator()<ResetRequest>(2);
			v.template operator()<X2SetupRequest>(3);
			v.template operator()<ResourceStatusRequest>(4);
			v.template operator()<ENBConfigurationUpdate>(5);
			v.template operator()<MobilityChangeRequest>(6);
			v.template operator()<CellActivationRequest>(7);
			v.template operator()<SeNBAdditionRequest>(8);
			v.template operator()<SeNBModificationRequest>(9);
			v.template operator()<SeNBModificationRequired>(10);
			v.template operator()<SeNBReleaseRequired>(11);
			v.template operator()<X2RemovalRequest>(12);
			v.template operator()<RetrieveUEContextRequest>(13);
			v.template operator()<SgNBAdditionRequest>(14);
			v.template operator()<SgNBModificationRequest>(15);
			v.template operator()<SgNBModificationRequired>(16);
			v.template operator()<SgNBReleaseRequest>(17);
			v.template operator()<SgNBReleaseRequired>(18);
			v.template operator()<SgNBChangeRequired>(19);
			v.template operator()<ENDCX2SetupRequest>(20);
			v.template operator()<ENDCConfigurationUpdate>(21);
			v.template operator()<ENDCCellActivationRequest>(22);
			v.template operator()<ENDCPartialResetRequired>(23);
			v.template operator()<EUTRANRCellResourceCoordinationRequest>(24);
			v.template operator()<ENDCX2RemovalRequest>(25);
			v.template operator()<SNStatusTransfer>(26);
			v.template operator()<UEContextRelease>(27);
			v.template operator()<HandoverCancel>(28);
			v.template operator()<ErrorIndication>(29);
			v.template operator()<ResourceStatusUpdate>(30);
			v.template operator()<LoadInformation>(31);
			v.template operator()<PrivateMessage>(32);
			v.template operator()<RLFIndication>(33);
			v.template operator()<HandoverReport>(34);
			v.template operator()<X2Release>(35);
			v.template operator()<X2APMessageTransfer>(36);
			v.template operator()<SeNBReconfigurationComplete>(37);
			v.template operator()<SeNBReleaseRequest>(38);
			v.template operator()<SeNBCounterCheckRequest>(39);
			v.template operator()<SgNBReconfigurationComplete>(40);
			v.template operator()<SgNBCounterCheckRequest>(41);
			v.template operator()<RRCTransfer>(42);
			v.template operator()<SecondaryRATDataUsageReport>(43);
			v.template operator()<SgNBActivityNotification>(44);
			v.template operator()<DataForwardingAddressIndication>(45);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_handoverPreparation()); return true;
			case 2: v(select_id_reset()); return true;
			case 3: v(select_id_x2Setup()); return true;
			case 4: v(select_id_resourceStatusReportingInitiation()); return true;
			case 5: v(select_id_eNBConfigurationUpdate()); return true;
			case 6: v(select_id_mobilitySettingsChange()); return true;
			case 7: v(select_id_cellActivation()); return true;
			case 8: v(select_id_seNBAdditionPreparation()); return true;
			case 9: v(select_id_meNBinitiatedSeNBModificationPreparation()); return true;
			case 10: v(select_id_seNBinitiatedSeNBModification()); return true;
			case 11: v(select_id_seNBinitiatedSeNBRelease()); return true;
			case 12: v(select_id_x2Removal()); return true;
			case 13: v(select_id_retrieveUEContext()); return true;
			case 14: v(select_id_sgNBAdditionPreparation()); return true;
			case 15: v(select_id_meNBinitiatedSgNBModificationPreparation()); return true;
			case 16: v(select_id_sgNBinitiatedSgNBModification()); return true;
			case 17: v(select_id_meNBinitiatedSgNBRelease()); return true;
			case 18: v(select_id_sgNBinitiatedSgNBRelease()); return true;
			case 19: v(select_id_sgNBChange()); return true;
			case 20: v(select_id_endcX2Setup()); return true;
			case 21: v(select_id_endcConfigurationUpdate()); return true;
			case 22: v(select_id_endcCellActivation()); return true;
			case 23: v(select_id_endcPartialReset()); return true;
			case 24: v(select_id_eUTRANRCellResourceCoordination()); return true;
			case 25: v(select_id_endcX2Removal()); return true;
			case 26: v(select_id_snStatusTransfer()); return true;
			case 27: v(select_id_uEContextRelease()); return true;
			case 28: v(select_id_handoverCancel()); return true;
			case 29: v(select_id_errorIndication()); return true;
			case 30: v(select_id_resourceStatusReporting()); return true;
			case 31: v(select_id_loadIndication()); return true;
			case 32: v(select_id_privateMessage()); return true;
			case 33: v(select_id_rLFIndication()); return true;
			case 34: v(select_id_handoverReport()); return true;
			case 35: v(select_id_x2Release()); return true;
			case 36: v(select_id_x2APMessageTransfer()); return true;
			case 37: v(select_id_seNBReconfigurationCompletion()); return true;
			case 38: v(select_id_meNBinitiatedSeNBRelease()); return true;
			case 39: v(select_id_seNBCounterCheck()); return true;
			case 40: v(select_id_sgNBReconfigurationCompletion()); return true;
			case 41: v(select_id_sgNBCounterCheck()); return true;
			case 42: v(select_id_rRCTransfer()); return true;
			case 43: v(select_id_secondaryRATDataUsageReport()); return true;
			case 44: v(select_id_SgNBActivityNotification()); return true;
			case 45: v(select_id_dataForwardingAddressIndication()); return true;
			case 46: if(type != 46) {clear(); asn::base::set();} type = 46; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<HandoverRequest>()); return true;
			case 2: v(var.as<ResetRequest>()); return true;
			case 3: v(var.as<X2SetupRequest>()); return true;
			case 4: v(var.as<ResourceStatusRequest>()); return true;
			case 5: v(var.as<ENBConfigurationUpdate>()); return true;
			case 6: v(var.as<MobilityChangeRequest>()); return true;
			case 7: v(var.as<CellActivationRequest>()); return true;
			case 8: v(var.as<SeNBAdditionRequest>()); return true;
			case 9: v(var.as<SeNBModificationRequest>()); return true;
			case 10: v(var.as<SeNBModificationRequired>()); return true;
			case 11: v(var.as<SeNBReleaseRequired>()); return true;
			case 12: v(var.as<X2RemovalRequest>()); return true;
			case 13: v(var.as<RetrieveUEContextRequest>()); return true;
			case 14: v(var.as<SgNBAdditionRequest>()); return true;
			case 15: v(var.as<SgNBModificationRequest>()); return true;
			case 16: v(var.as<SgNBModificationRequired>()); return true;
			case 17: v(var.as<SgNBReleaseRequest>()); return true;
			case 18: v(var.as<SgNBReleaseRequired>()); return true;
			case 19: v(var.as<SgNBChangeRequired>()); return true;
			case 20: v(var.as<ENDCX2SetupRequest>()); return true;
			case 21: v(var.as<ENDCConfigurationUpdate>()); return true;
			case 22: v(var.as<ENDCCellActivationRequest>()); return true;
			case 23: v(var.as<ENDCPartialResetRequired>()); return true;
			case 24: v(var.as<EUTRANRCellResourceCoordinationRequest>()); return true;
			case 25: v(var.as<ENDCX2RemovalRequest>()); return true;
			case 26: v(var.as<SNStatusTransfer>()); return true;
			case 27: v(var.as<UEContextRelease>()); return true;
			case 28: v(var.as<HandoverCancel>()); return true;
			case 29: v(var.as<ErrorIndication>()); return true;
			case 30: v(var.as<ResourceStatusUpdate>()); return true;
			case 31: v(var.as<LoadInformation>()); return true;
			case 32: v(var.as<PrivateMessage>()); return true;
			case 33: v(var.as<RLFIndication>()); return true;
			case 34: v(var.as<HandoverReport>()); return true;
			case 35: v(var.as<X2Release>()); return true;
			case 36: v(var.as<X2APMessageTransfer>()); return true;
			case 37: v(var.as<SeNBReconfigurationComplete>()); return true;
			case 38: v(var.as<SeNBReleaseRequest>()); return true;
			case 39: v(var.as<SeNBCounterCheckRequest>()); return true;
			case 40: v(var.as<SgNBReconfigurationComplete>()); return true;
			case 41: v(var.as<SgNBCounterCheckRequest>()); return true;
			case 42: v(var.as<RRCTransfer>()); return true;
			case 43: v(var.as<SecondaryRATDataUsageReport>()); return true;
			case 44: v(var.as<SgNBActivityNotification>()); return true;
			case 45: v(var.as<DataForwardingAddressIndication>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(CellActivationRequest)];
			char dummy2[sizeof(DataForwardingAddressIndication)];
			char dummy3[sizeof(ENBConfigurationUpdate)];
			char dummy4[sizeof(ENDCCellActivationRequest)];
			char dummy5[sizeof(ENDCConfigurationUpdate)];
			char dummy6[sizeof(ENDCPartialResetRequired)];
			char dummy7[sizeof(ENDCX2RemovalRequest)];
			char dummy8[sizeof(ENDCX2SetupRequest)];
			char dummy9[sizeof(EUTRANRCellResourceCoordinationRequest)];
			char dummy10[sizeof(ErrorIndication)];
			char dummy11[sizeof(HandoverCancel)];
			char dummy12[sizeof(HandoverReport)];
			char dummy13[sizeof(HandoverRequest)];
			char dummy14[sizeof(LoadInformation)];
			char dummy15[sizeof(MobilityChangeRequest)];
			char dummy16[sizeof(PrivateMessage)];
			char dummy17[sizeof(RLFIndication)];
			char dummy18[sizeof(RRCTransfer)];
			char dummy19[sizeof(ResetRequest)];
			char dummy20[sizeof(ResourceStatusRequest)];
			char dummy21[sizeof(ResourceStatusUpdate)];
			char dummy22[sizeof(RetrieveUEContextRequest)];
			char dummy23[sizeof(SNStatusTransfer)];
			char dummy24[sizeof(SeNBAdditionRequest)];
			char dummy25[sizeof(SeNBCounterCheckRequest)];
			char dummy26[sizeof(SeNBModificationRequest)];
			char dummy27[sizeof(SeNBModificationRequired)];
			char dummy28[sizeof(SeNBReconfigurationComplete)];
			char dummy29[sizeof(SeNBReleaseRequest)];
			char dummy30[sizeof(SeNBReleaseRequired)];
			char dummy31[sizeof(SecondaryRATDataUsageReport)];
			char dummy32[sizeof(SgNBActivityNotification)];
			char dummy33[sizeof(SgNBAdditionRequest)];
			char dummy34[sizeof(SgNBChangeRequired)];
			char dummy35[sizeof(SgNBCounterCheckRequest)];
			char dummy36[sizeof(SgNBModificationRequest)];
			char dummy37[sizeof(SgNBModificationRequired)];
			char dummy38[sizeof(SgNBReconfigurationComplete)];
			char dummy39[sizeof(SgNBReleaseRequest)];
			char dummy40[sizeof(SgNBReleaseRequired)];
			char dummy41[sizeof(UEContextRelease)];
			char dummy42[sizeof(X2APMessageTransfer)];
			char dummy43[sizeof(X2Release)];
			char dummy44[sizeof(X2RemovalRequest)];
			char dummy45[sizeof(X2SetupRequest)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct SuccessfulOutcome_t : asn::typefield<true>
	{
		~SuccessfulOutcome_t()	{clear();}
		size_t get_index() const {return type;}
		HandoverRequestAcknowledge& select_id_handoverPreparation() { return set<HandoverRequestAcknowledge>(1); }
		HandoverRequestAcknowledge const* get_id_handoverPreparation() const { return get<HandoverRequestAcknowledge>(1); }
		ResetResponse& select_id_reset() { return set<ResetResponse>(2); }
		ResetResponse const* get_id_reset() const { return get<ResetResponse>(2); }
		X2SetupResponse& select_id_x2Setup() { return set<X2SetupResponse>(3); }
		X2SetupResponse const* get_id_x2Setup() const { return get<X2SetupResponse>(3); }
		ResourceStatusResponse& select_id_resourceStatusReportingInitiation() { return set<ResourceStatusResponse>(4); }
		ResourceStatusResponse const* get_id_resourceStatusReportingInitiation() const { return get<ResourceStatusResponse>(4); }
		ENBConfigurationUpdateAcknowledge& select_id_eNBConfigurationUpdate() { return set<ENBConfigurationUpdateAcknowledge>(5); }
		ENBConfigurationUpdateAcknowledge const* get_id_eNBConfigurationUpdate() const { return get<ENBConfigurationUpdateAcknowledge>(5); }
		MobilityChangeAcknowledge& select_id_mobilitySettingsChange() { return set<MobilityChangeAcknowledge>(6); }
		MobilityChangeAcknowledge const* get_id_mobilitySettingsChange() const { return get<MobilityChangeAcknowledge>(6); }
		CellActivationResponse& select_id_cellActivation() { return set<CellActivationResponse>(7); }
		CellActivationResponse const* get_id_cellActivation() const { return get<CellActivationResponse>(7); }
		SeNBAdditionRequestAcknowledge& select_id_seNBAdditionPreparation() { return set<SeNBAdditionRequestAcknowledge>(8); }
		SeNBAdditionRequestAcknowledge const* get_id_seNBAdditionPreparation() const { return get<SeNBAdditionRequestAcknowledge>(8); }
		SeNBModificationRequestAcknowledge& select_id_meNBinitiatedSeNBModificationPreparation() { return set<SeNBModificationRequestAcknowledge>(9); }
		SeNBModificationRequestAcknowledge const* get_id_meNBinitiatedSeNBModificationPreparation() const { return get<SeNBModificationRequestAcknowledge>(9); }
		SeNBModificationConfirm& select_id_seNBinitiatedSeNBModification() { return set<SeNBModificationConfirm>(10); }
		SeNBModificationConfirm const* get_id_seNBinitiatedSeNBModification() const { return get<SeNBModificationConfirm>(10); }
		SeNBReleaseConfirm& select_id_seNBinitiatedSeNBRelease() { return set<SeNBReleaseConfirm>(11); }
		SeNBReleaseConfirm const* get_id_seNBinitiatedSeNBRelease() const { return get<SeNBReleaseConfirm>(11); }
		X2RemovalResponse& select_id_x2Removal() { return set<X2RemovalResponse>(12); }
		X2RemovalResponse const* get_id_x2Removal() const { return get<X2RemovalResponse>(12); }
		RetrieveUEContextResponse& select_id_retrieveUEContext() { return set<RetrieveUEContextResponse>(13); }
		RetrieveUEContextResponse const* get_id_retrieveUEContext() const { return get<RetrieveUEContextResponse>(13); }
		SgNBAdditionRequestAcknowledge& select_id_sgNBAdditionPreparation() { return set<SgNBAdditionRequestAcknowledge>(14); }
		SgNBAdditionRequestAcknowledge const* get_id_sgNBAdditionPreparation() const { return get<SgNBAdditionRequestAcknowledge>(14); }
		SgNBModificationRequestAcknowledge& select_id_meNBinitiatedSgNBModificationPreparation() { return set<SgNBModificationRequestAcknowledge>(15); }
		SgNBModificationRequestAcknowledge const* get_id_meNBinitiatedSgNBModificationPreparation() const { return get<SgNBModificationRequestAcknowledge>(15); }
		SgNBModificationConfirm& select_id_sgNBinitiatedSgNBModification() { return set<SgNBModificationConfirm>(16); }
		SgNBModificationConfirm const* get_id_sgNBinitiatedSgNBModification() const { return get<SgNBModificationConfirm>(16); }
		SgNBReleaseRequestAcknowledge& select_id_meNBinitiatedSgNBRelease() { return set<SgNBReleaseRequestAcknowledge>(17); }
		SgNBReleaseRequestAcknowledge const* get_id_meNBinitiatedSgNBRelease() const { return get<SgNBReleaseRequestAcknowledge>(17); }
		SgNBReleaseConfirm& select_id_sgNBinitiatedSgNBRelease() { return set<SgNBReleaseConfirm>(18); }
		SgNBReleaseConfirm const* get_id_sgNBinitiatedSgNBRelease() const { return get<SgNBReleaseConfirm>(18); }
		SgNBChangeConfirm& select_id_sgNBChange() { return set<SgNBChangeConfirm>(19); }
		SgNBChangeConfirm const* get_id_sgNBChange() const { return get<SgNBChangeConfirm>(19); }
		ENDCX2SetupResponse& select_id_endcX2Setup() { return set<ENDCX2SetupResponse>(20); }
		ENDCX2SetupResponse const* get_id_endcX2Setup() const { return get<ENDCX2SetupResponse>(20); }
		ENDCConfigurationUpdateAcknowledge& select_id_endcConfigurationUpdate() { return set<ENDCConfigurationUpdateAcknowledge>(21); }
		ENDCConfigurationUpdateAcknowledge const* get_id_endcConfigurationUpdate() const { return get<ENDCConfigurationUpdateAcknowledge>(21); }
		ENDCCellActivationResponse& select_id_endcCellActivation() { return set<ENDCCellActivationResponse>(22); }
		ENDCCellActivationResponse const* get_id_endcCellActivation() const { return get<ENDCCellActivationResponse>(22); }
		ENDCPartialResetConfirm& select_id_endcPartialReset() { return set<ENDCPartialResetConfirm>(23); }
		ENDCPartialResetConfirm const* get_id_endcPartialReset() const { return get<ENDCPartialResetConfirm>(23); }
		EUTRANRCellResourceCoordinationResponse& select_id_eUTRANRCellResourceCoordination() { return set<EUTRANRCellResourceCoordinationResponse>(24); }
		EUTRANRCellResourceCoordinationResponse const* get_id_eUTRANRCellResourceCoordination() const { return get<EUTRANRCellResourceCoordinationResponse>(24); }
		ENDCX2RemovalResponse& select_id_endcX2Removal() { return set<ENDCX2RemovalResponse>(25); }
		ENDCX2RemovalResponse const* get_id_endcX2Removal() const { return get<ENDCX2RemovalResponse>(25); }
		bool is_unknown() const { return type == 46; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<HandoverRequestAcknowledge>(); break;
			case 2: var.destroy<ResetResponse>(); break;
			case 3: var.destroy<X2SetupResponse>(); break;
			case 4: var.destroy<ResourceStatusResponse>(); break;
			case 5: var.destroy<ENBConfigurationUpdateAcknowledge>(); break;
			case 6: var.destroy<MobilityChangeAcknowledge>(); break;
			case 7: var.destroy<CellActivationResponse>(); break;
			case 8: var.destroy<SeNBAdditionRequestAcknowledge>(); break;
			case 9: var.destroy<SeNBModificationRequestAcknowledge>(); break;
			case 10: var.destroy<SeNBModificationConfirm>(); break;
			case 11: var.destroy<SeNBReleaseConfirm>(); break;
			case 12: var.destroy<X2RemovalResponse>(); break;
			case 13: var.destroy<RetrieveUEContextResponse>(); break;
			case 14: var.destroy<SgNBAdditionRequestAcknowledge>(); break;
			case 15: var.destroy<SgNBModificationRequestAcknowledge>(); break;
			case 16: var.destroy<SgNBModificationConfirm>(); break;
			case 17: var.destroy<SgNBReleaseRequestAcknowledge>(); break;
			case 18: var.destroy<SgNBReleaseConfirm>(); break;
			case 19: var.destroy<SgNBChangeConfirm>(); break;
			case 20: var.destroy<ENDCX2SetupResponse>(); break;
			case 21: var.destroy<ENDCConfigurationUpdateAcknowledge>(); break;
			case 22: var.destroy<ENDCCellActivationResponse>(); break;
			case 23: var.destroy<ENDCPartialResetConfirm>(); break;
			case 24: var.destroy<EUTRANRCellResourceCoordinationResponse>(); break;
			case 25: var.destroy<ENDCX2RemovalResponse>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<HandoverRequestAcknowledge>(1);
			v.template operator()<ResetResponse>(2);
			v.template operator()<X2SetupResponse>(3);
			v.template operator()<ResourceStatusResponse>(4);
			v.template operator()<ENBConfigurationUpdateAcknowledge>(5);
			v.template operator()<MobilityChangeAcknowledge>(6);
			v.template operator()<CellActivationResponse>(7);
			v.template operator()<SeNBAdditionRequestAcknowledge>(8);
			v.template operator()<SeNBModificationRequestAcknowledge>(9);
			v.template operator()<SeNBModificationConfirm>(10);
			v.template operator()<SeNBReleaseConfirm>(11);
			v.template operator()<X2RemovalResponse>(12);
			v.template operator()<RetrieveUEContextResponse>(13);
			v.template operator()<SgNBAdditionRequestAcknowledge>(14);
			v.template operator()<SgNBModificationRequestAcknowledge>(15);
			v.template operator()<SgNBModificationConfirm>(16);
			v.template operator()<SgNBReleaseRequestAcknowledge>(17);
			v.template operator()<SgNBReleaseConfirm>(18);
			v.template operator()<SgNBChangeConfirm>(19);
			v.template operator()<ENDCX2SetupResponse>(20);
			v.template operator()<ENDCConfigurationUpdateAcknowledge>(21);
			v.template operator()<ENDCCellActivationResponse>(22);
			v.template operator()<ENDCPartialResetConfirm>(23);
			v.template operator()<EUTRANRCellResourceCoordinationResponse>(24);
			v.template operator()<ENDCX2RemovalResponse>(25);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_handoverPreparation()); return true;
			case 2: v(select_id_reset()); return true;
			case 3: v(select_id_x2Setup()); return true;
			case 4: v(select_id_resourceStatusReportingInitiation()); return true;
			case 5: v(select_id_eNBConfigurationUpdate()); return true;
			case 6: v(select_id_mobilitySettingsChange()); return true;
			case 7: v(select_id_cellActivation()); return true;
			case 8: v(select_id_seNBAdditionPreparation()); return true;
			case 9: v(select_id_meNBinitiatedSeNBModificationPreparation()); return true;
			case 10: v(select_id_seNBinitiatedSeNBModification()); return true;
			case 11: v(select_id_seNBinitiatedSeNBRelease()); return true;
			case 12: v(select_id_x2Removal()); return true;
			case 13: v(select_id_retrieveUEContext()); return true;
			case 14: v(select_id_sgNBAdditionPreparation()); return true;
			case 15: v(select_id_meNBinitiatedSgNBModificationPreparation()); return true;
			case 16: v(select_id_sgNBinitiatedSgNBModification()); return true;
			case 17: v(select_id_meNBinitiatedSgNBRelease()); return true;
			case 18: v(select_id_sgNBinitiatedSgNBRelease()); return true;
			case 19: v(select_id_sgNBChange()); return true;
			case 20: v(select_id_endcX2Setup()); return true;
			case 21: v(select_id_endcConfigurationUpdate()); return true;
			case 22: v(select_id_endcCellActivation()); return true;
			case 23: v(select_id_endcPartialReset()); return true;
			case 24: v(select_id_eUTRANRCellResourceCoordination()); return true;
			case 25: v(select_id_endcX2Removal()); return true;
			case 46: if(type != 46) {clear(); asn::base::set();} type = 46; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<HandoverRequestAcknowledge>()); return true;
			case 2: v(var.as<ResetResponse>()); return true;
			case 3: v(var.as<X2SetupResponse>()); return true;
			case 4: v(var.as<ResourceStatusResponse>()); return true;
			case 5: v(var.as<ENBConfigurationUpdateAcknowledge>()); return true;
			case 6: v(var.as<MobilityChangeAcknowledge>()); return true;
			case 7: v(var.as<CellActivationResponse>()); return true;
			case 8: v(var.as<SeNBAdditionRequestAcknowledge>()); return true;
			case 9: v(var.as<SeNBModificationRequestAcknowledge>()); return true;
			case 10: v(var.as<SeNBModificationConfirm>()); return true;
			case 11: v(var.as<SeNBReleaseConfirm>()); return true;
			case 12: v(var.as<X2RemovalResponse>()); return true;
			case 13: v(var.as<RetrieveUEContextResponse>()); return true;
			case 14: v(var.as<SgNBAdditionRequestAcknowledge>()); return true;
			case 15: v(var.as<SgNBModificationRequestAcknowledge>()); return true;
			case 16: v(var.as<SgNBModificationConfirm>()); return true;
			case 17: v(var.as<SgNBReleaseRequestAcknowledge>()); return true;
			case 18: v(var.as<SgNBReleaseConfirm>()); return true;
			case 19: v(var.as<SgNBChangeConfirm>()); return true;
			case 20: v(var.as<ENDCX2SetupResponse>()); return true;
			case 21: v(var.as<ENDCConfigurationUpdateAcknowledge>()); return true;
			case 22: v(var.as<ENDCCellActivationResponse>()); return true;
			case 23: v(var.as<ENDCPartialResetConfirm>()); return true;
			case 24: v(var.as<EUTRANRCellResourceCoordinationResponse>()); return true;
			case 25: v(var.as<ENDCX2RemovalResponse>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(CellActivationResponse)];
			char dummy2[sizeof(ENBConfigurationUpdateAcknowledge)];
			char dummy3[sizeof(ENDCCellActivationResponse)];
			char dummy4[sizeof(ENDCConfigurationUpdateAcknowledge)];
			char dummy5[sizeof(ENDCPartialResetConfirm)];
			char dummy6[sizeof(ENDCX2RemovalResponse)];
			char dummy7[sizeof(ENDCX2SetupResponse)];
			char dummy8[sizeof(EUTRANRCellResourceCoordinationResponse)];
			char dummy9[sizeof(HandoverRequestAcknowledge)];
			char dummy10[sizeof(MobilityChangeAcknowledge)];
			char dummy11[sizeof(ResetResponse)];
			char dummy12[sizeof(ResourceStatusResponse)];
			char dummy13[sizeof(RetrieveUEContextResponse)];
			char dummy14[sizeof(SeNBAdditionRequestAcknowledge)];
			char dummy15[sizeof(SeNBModificationConfirm)];
			char dummy16[sizeof(SeNBModificationRequestAcknowledge)];
			char dummy17[sizeof(SeNBReleaseConfirm)];
			char dummy18[sizeof(SgNBAdditionRequestAcknowledge)];
			char dummy19[sizeof(SgNBChangeConfirm)];
			char dummy20[sizeof(SgNBModificationConfirm)];
			char dummy21[sizeof(SgNBModificationRequestAcknowledge)];
			char dummy22[sizeof(SgNBReleaseConfirm)];
			char dummy23[sizeof(SgNBReleaseRequestAcknowledge)];
			char dummy24[sizeof(X2RemovalResponse)];
			char dummy25[sizeof(X2SetupResponse)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct UnsuccessfulOutcome_t : asn::typefield<true>
	{
		~UnsuccessfulOutcome_t()	{clear();}
		size_t get_index() const {return type;}
		HandoverPreparationFailure& select_id_handoverPreparation() { return set<HandoverPreparationFailure>(1); }
		HandoverPreparationFailure const* get_id_handoverPreparation() const { return get<HandoverPreparationFailure>(1); }
		X2SetupFailure& select_id_x2Setup() { return set<X2SetupFailure>(3); }
		X2SetupFailure const* get_id_x2Setup() const { return get<X2SetupFailure>(3); }
		ResourceStatusFailure& select_id_resourceStatusReportingInitiation() { return set<ResourceStatusFailure>(4); }
		ResourceStatusFailure const* get_id_resourceStatusReportingInitiation() const { return get<ResourceStatusFailure>(4); }
		ENBConfigurationUpdateFailure& select_id_eNBConfigurationUpdate() { return set<ENBConfigurationUpdateFailure>(5); }
		ENBConfigurationUpdateFailure const* get_id_eNBConfigurationUpdate() const { return get<ENBConfigurationUpdateFailure>(5); }
		MobilityChangeFailure& select_id_mobilitySettingsChange() { return set<MobilityChangeFailure>(6); }
		MobilityChangeFailure const* get_id_mobilitySettingsChange() const { return get<MobilityChangeFailure>(6); }
		CellActivationFailure& select_id_cellActivation() { return set<CellActivationFailure>(7); }
		CellActivationFailure const* get_id_cellActivation() const { return get<CellActivationFailure>(7); }
		SeNBAdditionRequestReject& select_id_seNBAdditionPreparation() { return set<SeNBAdditionRequestReject>(8); }
		SeNBAdditionRequestReject const* get_id_seNBAdditionPreparation() const { return get<SeNBAdditionRequestReject>(8); }
		SeNBModificationRequestReject& select_id_meNBinitiatedSeNBModificationPreparation() { return set<SeNBModificationRequestReject>(9); }
		SeNBModificationRequestReject const* get_id_meNBinitiatedSeNBModificationPreparation() const { return get<SeNBModificationRequestReject>(9); }
		SeNBModificationRefuse& select_id_seNBinitiatedSeNBModification() { return set<SeNBModificationRefuse>(10); }
		SeNBModificationRefuse const* get_id_seNBinitiatedSeNBModification() const { return get<SeNBModificationRefuse>(10); }
		X2RemovalFailure& select_id_x2Removal() { return set<X2RemovalFailure>(12); }
		X2RemovalFailure const* get_id_x2Removal() const { return get<X2RemovalFailure>(12); }
		RetrieveUEContextFailure& select_id_retrieveUEContext() { return set<RetrieveUEContextFailure>(13); }
		RetrieveUEContextFailure const* get_id_retrieveUEContext() const { return get<RetrieveUEContextFailure>(13); }
		SgNBAdditionRequestReject& select_id_sgNBAdditionPreparation() { return set<SgNBAdditionRequestReject>(14); }
		SgNBAdditionRequestReject const* get_id_sgNBAdditionPreparation() const { return get<SgNBAdditionRequestReject>(14); }
		SgNBModificationRequestReject& select_id_meNBinitiatedSgNBModificationPreparation() { return set<SgNBModificationRequestReject>(15); }
		SgNBModificationRequestReject const* get_id_meNBinitiatedSgNBModificationPreparation() const { return get<SgNBModificationRequestReject>(15); }
		SgNBModificationRefuse& select_id_sgNBinitiatedSgNBModification() { return set<SgNBModificationRefuse>(16); }
		SgNBModificationRefuse const* get_id_sgNBinitiatedSgNBModification() const { return get<SgNBModificationRefuse>(16); }
		SgNBReleaseRequestReject& select_id_meNBinitiatedSgNBRelease() { return set<SgNBReleaseRequestReject>(17); }
		SgNBReleaseRequestReject const* get_id_meNBinitiatedSgNBRelease() const { return get<SgNBReleaseRequestReject>(17); }
		SgNBChangeRefuse& select_id_sgNBChange() { return set<SgNBChangeRefuse>(19); }
		SgNBChangeRefuse const* get_id_sgNBChange() const { return get<SgNBChangeRefuse>(19); }
		ENDCX2SetupFailure& select_id_endcX2Setup() { return set<ENDCX2SetupFailure>(20); }
		ENDCX2SetupFailure const* get_id_endcX2Setup() const { return get<ENDCX2SetupFailure>(20); }
		ENDCConfigurationUpdateFailure& select_id_endcConfigurationUpdate() { return set<ENDCConfigurationUpdateFailure>(21); }
		ENDCConfigurationUpdateFailure const* get_id_endcConfigurationUpdate() const { return get<ENDCConfigurationUpdateFailure>(21); }
		ENDCCellActivationFailure& select_id_endcCellActivation() { return set<ENDCCellActivationFailure>(22); }
		ENDCCellActivationFailure const* get_id_endcCellActivation() const { return get<ENDCCellActivationFailure>(22); }
		ENDCX2RemovalFailure& select_id_endcX2Removal() { return set<ENDCX2RemovalFailure>(25); }
		ENDCX2RemovalFailure const* get_id_endcX2Removal() const { return get<ENDCX2RemovalFailure>(25); }
		bool is_unknown() const { return type == 46; }
		void clear()
		{
			switch(type)
			{
			case 1: var.destroy<HandoverPreparationFailure>(); break;
			case 3: var.destroy<X2SetupFailure>(); break;
			case 4: var.destroy<ResourceStatusFailure>(); break;
			case 5: var.destroy<ENBConfigurationUpdateFailure>(); break;
			case 6: var.destroy<MobilityChangeFailure>(); break;
			case 7: var.destroy<CellActivationFailure>(); break;
			case 8: var.destroy<SeNBAdditionRequestReject>(); break;
			case 9: var.destroy<SeNBModificationRequestReject>(); break;
			case 10: var.destroy<SeNBModificationRefuse>(); break;
			case 12: var.destroy<X2RemovalFailure>(); break;
			case 13: var.destroy<RetrieveUEContextFailure>(); break;
			case 14: var.destroy<SgNBAdditionRequestReject>(); break;
			case 15: var.destroy<SgNBModificationRequestReject>(); break;
			case 16: var.destroy<SgNBModificationRefuse>(); break;
			case 17: var.destroy<SgNBReleaseRequestReject>(); break;
			case 19: var.destroy<SgNBChangeRefuse>(); break;
			case 20: var.destroy<ENDCX2SetupFailure>(); break;
			case 21: var.destroy<ENDCConfigurationUpdateFailure>(); break;
			case 22: var.destroy<ENDCCellActivationFailure>(); break;
			case 25: var.destroy<ENDCX2RemovalFailure>(); break;
			}
			type = 0; ref_nested().clear();
		}
		template<typename V> static inline void enumerate(V& v)
		{
			v.template operator()<HandoverPreparationFailure>(1);
			v.template operator()<X2SetupFailure>(3);
			v.template operator()<ResourceStatusFailure>(4);
			v.template operator()<ENBConfigurationUpdateFailure>(5);
			v.template operator()<MobilityChangeFailure>(6);
			v.template operator()<CellActivationFailure>(7);
			v.template operator()<SeNBAdditionRequestReject>(8);
			v.template operator()<SeNBModificationRequestReject>(9);
			v.template operator()<SeNBModificationRefuse>(10);
			v.template operator()<X2RemovalFailure>(12);
			v.template operator()<RetrieveUEContextFailure>(13);
			v.template operator()<SgNBAdditionRequestReject>(14);
			v.template operator()<SgNBModificationRequestReject>(15);
			v.template operator()<SgNBModificationRefuse>(16);
			v.template operator()<SgNBReleaseRequestReject>(17);
			v.template operator()<SgNBChangeRefuse>(19);
			v.template operator()<ENDCX2SetupFailure>(20);
			v.template operator()<ENDCConfigurationUpdateFailure>(21);
			v.template operator()<ENDCCellActivationFailure>(22);
			v.template operator()<ENDCX2RemovalFailure>(25);

		}
		protected:
		template<typename V> bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: v(select_id_handoverPreparation()); return true;
			case 3: v(select_id_x2Setup()); return true;
			case 4: v(select_id_resourceStatusReportingInitiation()); return true;
			case 5: v(select_id_eNBConfigurationUpdate()); return true;
			case 6: v(select_id_mobilitySettingsChange()); return true;
			case 7: v(select_id_cellActivation()); return true;
			case 8: v(select_id_seNBAdditionPreparation()); return true;
			case 9: v(select_id_meNBinitiatedSeNBModificationPreparation()); return true;
			case 10: v(select_id_seNBinitiatedSeNBModification()); return true;
			case 12: v(select_id_x2Removal()); return true;
			case 13: v(select_id_retrieveUEContext()); return true;
			case 14: v(select_id_sgNBAdditionPreparation()); return true;
			case 15: v(select_id_meNBinitiatedSgNBModificationPreparation()); return true;
			case 16: v(select_id_sgNBinitiatedSgNBModification()); return true;
			case 17: v(select_id_meNBinitiatedSgNBRelease()); return true;
			case 19: v(select_id_sgNBChange()); return true;
			case 20: v(select_id_endcX2Setup()); return true;
			case 21: v(select_id_endcConfigurationUpdate()); return true;
			case 22: v(select_id_endcCellActivation()); return true;
			case 25: v(select_id_endcX2Removal()); return true;
			case 46: if(type != 46) {clear(); asn::base::set();} type = 46; return true;
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) return false;
			switch(type)
			{
			case 1: v(var.as<HandoverPreparationFailure>()); return true;
			case 3: v(var.as<X2SetupFailure>()); return true;
			case 4: v(var.as<ResourceStatusFailure>()); return true;
			case 5: v(var.as<ENBConfigurationUpdateFailure>()); return true;
			case 6: v(var.as<MobilityChangeFailure>()); return true;
			case 7: v(var.as<CellActivationFailure>()); return true;
			case 8: v(var.as<SeNBAdditionRequestReject>()); return true;
			case 9: v(var.as<SeNBModificationRequestReject>()); return true;
			case 10: v(var.as<SeNBModificationRefuse>()); return true;
			case 12: v(var.as<X2RemovalFailure>()); return true;
			case 13: v(var.as<RetrieveUEContextFailure>()); return true;
			case 14: v(var.as<SgNBAdditionRequestReject>()); return true;
			case 15: v(var.as<SgNBModificationRequestReject>()); return true;
			case 16: v(var.as<SgNBModificationRefuse>()); return true;
			case 17: v(var.as<SgNBReleaseRequestReject>()); return true;
			case 19: v(var.as<SgNBChangeRefuse>()); return true;
			case 20: v(var.as<ENDCX2SetupFailure>()); return true;
			case 21: v(var.as<ENDCConfigurationUpdateFailure>()); return true;
			case 22: v(var.as<ENDCCellActivationFailure>()); return true;
			case 25: v(var.as<ENDCX2RemovalFailure>()); return true;
			}
			return false;

		}
		private:
		template<class T> T& set(size_t index) {if(type != index) {clear(); type = index; return var.build<T>();} return var.as<T>();}
		template<class T> T const* get(size_t index) const {if(type == index) {return &var.as<T>();} return nullptr;}
		union union_type
		{
			char dummy1[sizeof(CellActivationFailure)];
			char dummy2[sizeof(ENBConfigurationUpdateFailure)];
			char dummy3[sizeof(ENDCCellActivationFailure)];
			char dummy4[sizeof(ENDCConfigurationUpdateFailure)];
			char dummy5[sizeof(ENDCX2RemovalFailure)];
			char dummy6[sizeof(ENDCX2SetupFailure)];
			char dummy7[sizeof(HandoverPreparationFailure)];
			char dummy8[sizeof(MobilityChangeFailure)];
			char dummy9[sizeof(ResourceStatusFailure)];
			char dummy10[sizeof(RetrieveUEContextFailure)];
			char dummy11[sizeof(SeNBAdditionRequestReject)];
			char dummy12[sizeof(SeNBModificationRefuse)];
			char dummy13[sizeof(SeNBModificationRequestReject)];
			char dummy14[sizeof(SgNBAdditionRequestReject)];
			char dummy15[sizeof(SgNBChangeRefuse)];
			char dummy16[sizeof(SgNBModificationRefuse)];
			char dummy17[sizeof(SgNBModificationRequestReject)];
			char dummy18[sizeof(SgNBReleaseRequestReject)];
			char dummy19[sizeof(X2RemovalFailure)];
			char dummy20[sizeof(X2SetupFailure)];

		};
		asn::variant<sizeof(union_type)> var;
		size_t type {0};

	};
	struct procedureCode_t : asn::fixedtypefield<X2AP_ELEMENTARY_PROCEDURE::procedureCode_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 46; }
		void clear() {type = 0;}
		void select_id_handoverPreparation() { set(id_handoverPreparation); type=1;}
		void select_id_reset() { set(id_reset); type=2;}
		void select_id_x2Setup() { set(id_x2Setup); type=3;}
		void select_id_resourceStatusReportingInitiation() { set(id_resourceStatusReportingInitiation); type=4;}
		void select_id_eNBConfigurationUpdate() { set(id_eNBConfigurationUpdate); type=5;}
		void select_id_mobilitySettingsChange() { set(id_mobilitySettingsChange); type=6;}
		void select_id_cellActivation() { set(id_cellActivation); type=7;}
		void select_id_seNBAdditionPreparation() { set(id_seNBAdditionPreparation); type=8;}
		void select_id_meNBinitiatedSeNBModificationPreparation() { set(id_meNBinitiatedSeNBModificationPreparation); type=9;}
		void select_id_seNBinitiatedSeNBModification() { set(id_seNBinitiatedSeNBModification); type=10;}
		void select_id_seNBinitiatedSeNBRelease() { set(id_seNBinitiatedSeNBRelease); type=11;}
		void select_id_x2Removal() { set(id_x2Removal); type=12;}
		void select_id_retrieveUEContext() { set(id_retrieveUEContext); type=13;}
		void select_id_sgNBAdditionPreparation() { set(id_sgNBAdditionPreparation); type=14;}
		void select_id_meNBinitiatedSgNBModificationPreparation() { set(id_meNBinitiatedSgNBModificationPreparation); type=15;}
		void select_id_sgNBinitiatedSgNBModification() { set(id_sgNBinitiatedSgNBModification); type=16;}
		void select_id_meNBinitiatedSgNBRelease() { set(id_meNBinitiatedSgNBRelease); type=17;}
		void select_id_sgNBinitiatedSgNBRelease() { set(id_sgNBinitiatedSgNBRelease); type=18;}
		void select_id_sgNBChange() { set(id_sgNBChange); type=19;}
		void select_id_endcX2Setup() { set(id_endcX2Setup); type=20;}
		void select_id_endcConfigurationUpdate() { set(id_endcConfigurationUpdate); type=21;}
		void select_id_endcCellActivation() { set(id_endcCellActivation); type=22;}
		void select_id_endcPartialReset() { set(id_endcPartialReset); type=23;}
		void select_id_eUTRANRCellResourceCoordination() { set(id_eUTRANRCellResourceCoordination); type=24;}
		void select_id_endcX2Removal() { set(id_endcX2Removal); type=25;}
		void select_id_snStatusTransfer() { set(id_snStatusTransfer); type=26;}
		void select_id_uEContextRelease() { set(id_uEContextRelease); type=27;}
		void select_id_handoverCancel() { set(id_handoverCancel); type=28;}
		void select_id_errorIndication() { set(id_errorIndication); type=29;}
		void select_id_resourceStatusReporting() { set(id_resourceStatusReporting); type=30;}
		void select_id_loadIndication() { set(id_loadIndication); type=31;}
		void select_id_privateMessage() { set(id_privateMessage); type=32;}
		void select_id_rLFIndication() { set(id_rLFIndication); type=33;}
		void select_id_handoverReport() { set(id_handoverReport); type=34;}
		void select_id_x2Release() { set(id_x2Release); type=35;}
		void select_id_x2APMessageTransfer() { set(id_x2APMessageTransfer); type=36;}
		void select_id_seNBReconfigurationCompletion() { set(id_seNBReconfigurationCompletion); type=37;}
		void select_id_meNBinitiatedSeNBRelease() { set(id_meNBinitiatedSeNBRelease); type=38;}
		void select_id_seNBCounterCheck() { set(id_seNBCounterCheck); type=39;}
		void select_id_sgNBReconfigurationCompletion() { set(id_sgNBReconfigurationCompletion); type=40;}
		void select_id_sgNBCounterCheck() { set(id_sgNBCounterCheck); type=41;}
		void select_id_rRCTransfer() { set(id_rRCTransfer); type=42;}
		void select_id_secondaryRATDataUsageReport() { set(id_secondaryRATDataUsageReport); type=43;}
		void select_id_SgNBActivityNotification() { set(id_SgNBActivityNotification); type=44;}
		void select_id_dataForwardingAddressIndication() { set(id_dataForwardingAddressIndication); type=45;}
		X2AP_ELEMENTARY_PROCEDURE::procedureCode_t const& ref_value() const {return ref_nested();}
		template<typename V>  bool decode(V& v)
		{
			clear();
			if(!v(ref_nested())) return false;
			if(equal(id_handoverPreparation)) { type = 1; return true; }
			else if(equal(id_reset)) { type = 2; return true; }
			else if(equal(id_x2Setup)) { type = 3; return true; }
			else if(equal(id_resourceStatusReportingInitiation)) { type = 4; return true; }
			else if(equal(id_eNBConfigurationUpdate)) { type = 5; return true; }
			else if(equal(id_mobilitySettingsChange)) { type = 6; return true; }
			else if(equal(id_cellActivation)) { type = 7; return true; }
			else if(equal(id_seNBAdditionPreparation)) { type = 8; return true; }
			else if(equal(id_meNBinitiatedSeNBModificationPreparation)) { type = 9; return true; }
			else if(equal(id_seNBinitiatedSeNBModification)) { type = 10; return true; }
			else if(equal(id_seNBinitiatedSeNBRelease)) { type = 11; return true; }
			else if(equal(id_x2Removal)) { type = 12; return true; }
			else if(equal(id_retrieveUEContext)) { type = 13; return true; }
			else if(equal(id_sgNBAdditionPreparation)) { type = 14; return true; }
			else if(equal(id_meNBinitiatedSgNBModificationPreparation)) { type = 15; return true; }
			else if(equal(id_sgNBinitiatedSgNBModification)) { type = 16; return true; }
			else if(equal(id_meNBinitiatedSgNBRelease)) { type = 17; return true; }
			else if(equal(id_sgNBinitiatedSgNBRelease)) { type = 18; return true; }
			else if(equal(id_sgNBChange)) { type = 19; return true; }
			else if(equal(id_endcX2Setup)) { type = 20; return true; }
			else if(equal(id_endcConfigurationUpdate)) { type = 21; return true; }
			else if(equal(id_endcCellActivation)) { type = 22; return true; }
			else if(equal(id_endcPartialReset)) { type = 23; return true; }
			else if(equal(id_eUTRANRCellResourceCoordination)) { type = 24; return true; }
			else if(equal(id_endcX2Removal)) { type = 25; return true; }
			else if(equal(id_snStatusTransfer)) { type = 26; return true; }
			else if(equal(id_uEContextRelease)) { type = 27; return true; }
			else if(equal(id_handoverCancel)) { type = 28; return true; }
			else if(equal(id_errorIndication)) { type = 29; return true; }
			else if(equal(id_resourceStatusReporting)) { type = 30; return true; }
			else if(equal(id_loadIndication)) { type = 31; return true; }
			else if(equal(id_privateMessage)) { type = 32; return true; }
			else if(equal(id_rLFIndication)) { type = 33; return true; }
			else if(equal(id_handoverReport)) { type = 34; return true; }
			else if(equal(id_x2Release)) { type = 35; return true; }
			else if(equal(id_x2APMessageTransfer)) { type = 36; return true; }
			else if(equal(id_seNBReconfigurationCompletion)) { type = 37; return true; }
			else if(equal(id_meNBinitiatedSeNBRelease)) { type = 38; return true; }
			else if(equal(id_seNBCounterCheck)) { type = 39; return true; }
			else if(equal(id_sgNBReconfigurationCompletion)) { type = 40; return true; }
			else if(equal(id_sgNBCounterCheck)) { type = 41; return true; }
			else if(equal(id_rRCTransfer)) { type = 42; return true; }
			else if(equal(id_secondaryRATDataUsageReport)) { type = 43; return true; }
			else if(equal(id_SgNBActivityNotification)) { type = 44; return true; }
			else if(equal(id_dataForwardingAddressIndication)) { type = 45; return true; }
			else { type = 46; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
		{
			return v(ref_nested());

		}
		protected:
		template<typename V>  bool decode(size_t index, V& v)
		{
			clear();
			switch(index)
			{
			case 1: type = 1; if(v(ref_nested())) { return equal(id_handoverPreparation);} return false;
			case 2: type = 2; if(v(ref_nested())) { return equal(id_reset);} return false;
			case 3: type = 3; if(v(ref_nested())) { return equal(id_x2Setup);} return false;
			case 4: type = 4; if(v(ref_nested())) { return equal(id_resourceStatusReportingInitiation);} return false;
			case 5: type = 5; if(v(ref_nested())) { return equal(id_eNBConfigurationUpdate);} return false;
			case 6: type = 6; if(v(ref_nested())) { return equal(id_mobilitySettingsChange);} return false;
			case 7: type = 7; if(v(ref_nested())) { return equal(id_cellActivation);} return false;
			case 8: type = 8; if(v(ref_nested())) { return equal(id_seNBAdditionPreparation);} return false;
			case 9: type = 9; if(v(ref_nested())) { return equal(id_meNBinitiatedSeNBModificationPreparation);} return false;
			case 10: type = 10; if(v(ref_nested())) { return equal(id_seNBinitiatedSeNBModification);} return false;
			case 11: type = 11; if(v(ref_nested())) { return equal(id_seNBinitiatedSeNBRelease);} return false;
			case 12: type = 12; if(v(ref_nested())) { return equal(id_x2Removal);} return false;
			case 13: type = 13; if(v(ref_nested())) { return equal(id_retrieveUEContext);} return false;
			case 14: type = 14; if(v(ref_nested())) { return equal(id_sgNBAdditionPreparation);} return false;
			case 15: type = 15; if(v(ref_nested())) { return equal(id_meNBinitiatedSgNBModificationPreparation);} return false;
			case 16: type = 16; if(v(ref_nested())) { return equal(id_sgNBinitiatedSgNBModification);} return false;
			case 17: type = 17; if(v(ref_nested())) { return equal(id_meNBinitiatedSgNBRelease);} return false;
			case 18: type = 18; if(v(ref_nested())) { return equal(id_sgNBinitiatedSgNBRelease);} return false;
			case 19: type = 19; if(v(ref_nested())) { return equal(id_sgNBChange);} return false;
			case 20: type = 20; if(v(ref_nested())) { return equal(id_endcX2Setup);} return false;
			case 21: type = 21; if(v(ref_nested())) { return equal(id_endcConfigurationUpdate);} return false;
			case 22: type = 22; if(v(ref_nested())) { return equal(id_endcCellActivation);} return false;
			case 23: type = 23; if(v(ref_nested())) { return equal(id_endcPartialReset);} return false;
			case 24: type = 24; if(v(ref_nested())) { return equal(id_eUTRANRCellResourceCoordination);} return false;
			case 25: type = 25; if(v(ref_nested())) { return equal(id_endcX2Removal);} return false;
			case 26: type = 26; if(v(ref_nested())) { return equal(id_snStatusTransfer);} return false;
			case 27: type = 27; if(v(ref_nested())) { return equal(id_uEContextRelease);} return false;
			case 28: type = 28; if(v(ref_nested())) { return equal(id_handoverCancel);} return false;
			case 29: type = 29; if(v(ref_nested())) { return equal(id_errorIndication);} return false;
			case 30: type = 30; if(v(ref_nested())) { return equal(id_resourceStatusReporting);} return false;
			case 31: type = 31; if(v(ref_nested())) { return equal(id_loadIndication);} return false;
			case 32: type = 32; if(v(ref_nested())) { return equal(id_privateMessage);} return false;
			case 33: type = 33; if(v(ref_nested())) { return equal(id_rLFIndication);} return false;
			case 34: type = 34; if(v(ref_nested())) { return equal(id_handoverReport);} return false;
			case 35: type = 35; if(v(ref_nested())) { return equal(id_x2Release);} return false;
			case 36: type = 36; if(v(ref_nested())) { return equal(id_x2APMessageTransfer);} return false;
			case 37: type = 37; if(v(ref_nested())) { return equal(id_seNBReconfigurationCompletion);} return false;
			case 38: type = 38; if(v(ref_nested())) { return equal(id_meNBinitiatedSeNBRelease);} return false;
			case 39: type = 39; if(v(ref_nested())) { return equal(id_seNBCounterCheck);} return false;
			case 40: type = 40; if(v(ref_nested())) { return equal(id_sgNBReconfigurationCompletion);} return false;
			case 41: type = 41; if(v(ref_nested())) { return equal(id_sgNBCounterCheck);} return false;
			case 42: type = 42; if(v(ref_nested())) { return equal(id_rRCTransfer);} return false;
			case 43: type = 43; if(v(ref_nested())) { return equal(id_secondaryRATDataUsageReport);} return false;
			case 44: type = 44; if(v(ref_nested())) { return equal(id_SgNBActivityNotification);} return false;
			case 45: type = 45; if(v(ref_nested())) { return equal(id_dataForwardingAddressIndication);} return false;
			case 46: type = 46; return v(ref_nested());
			ref_nested().clear();
			}
			return false;

		}
		template<typename V> bool encode(size_t index, V& v) const
		{
			if(index != type) {return false;} return v(ref_nested());

		}
		private:
		size_t type {0};

	};
	struct criticality_t : asn::fixedtypefield<X2AP_ELEMENTARY_PROCEDURE::criticality_t, true>
	{
		size_t get_index() const {return type;}
		bool is_unknown() const { return type == 46; }
		void clear() {type = 0;}
		void select_id_handoverPreparation() { set(reject); type=1;}
		void select_id_reset() { set(reject); type=2;}
		void select_id_x2Setup() { set(reject); type=3;}
		void select_id_resourceStatusReportingInitiation() { set(reject); type=4;}
		void select_id_eNBConfigurationUpdate() { set(reject); type=5;}
		void select_id_mobilitySettingsChange() { set(reject); type=6;}
		void select_id_cellActivation() { set(reject); type=7;}
		void select_id_seNBAdditionPreparation() { set(reject); type=8;}
		void select_id_meNBinitiatedSeNBModificationPreparation() { set(reject); type=9;}
		void select_id_seNBinitiatedSeNBModification() { set(reject); type=10;}
		void select_id_seNBinitiatedSeNBRelease() { set(reject); type=11;}
		void select_id_x2Removal() { set(reject); type=12;}
		void select_id_retrieveUEContext() { set(reject); type=13;}
		void select_id_sgNBAdditionPreparation() { set(reject); type=14;}
		void select_id_meNBinitiatedSgNBModificationPreparation() { set(reject); type=15;}
		void select_id_sgNBinitiatedSgNBModification() { set(reject); type=16;}
		void select_id_meNBinitiatedSgNBRelease() { set(ignore); type=17;}
		void select_id_sgNBinitiatedSgNBRelease() { set(reject); type=18;}
		void select_id_sgNBChange() { set(reject); type=19;}
		void select_id_endcX2Setup() { set(reject); type=20;}
		void select_id_endcConfigurationUpdate() { set(reject); type=21;}
		void select_id_endcCellActivation() { set(reject); type=22;}
		void select_id_endcPartialReset() { set(reject); type=23;}
		void select_id_eUTRANRCellResourceCoordination() { set(reject); type=24;}
		void select_id_endcX2Removal() { set(reject); type=25;}
		void select_id_snStatusTransfer() { set(ignore); type=26;}
		void select_id_uEContextRelease() { set(ignore); type=27;}
		void select_id_handoverCancel() { set(ignore); type=28;}
		void select_id_errorIndication() { set(ignore); type=29;}
		void select_id_resourceStatusReporting() { set(ignore); type=30;}
		void select_id_loadIndication() { set(ignore); type=31;}
		void select_id_privateMessage() { set(ignore); type=32;}
		void select_id_rLFIndication() { set(ignore); type=33;}
		void select_id_handoverReport() { set(ignore); type=34;}
		void select_id_x2Release() { set(reject); type=35;}
		void select_id_x2APMessageTransfer() { set(reject); type=36;}
		void select_id_seNBReconfigurationCompletion() { set(ignore); type=37;}
		void select_id_meNBinitiatedSeNBRelease() { set(ignore); type=38;}
		void select_id_seNBCounterCheck() { set(reject); type=39;}
		void select_id_sgNBReconfigurationCompletion() { set(ignore); type=40;}
		void select_id_sgNBCounterCheck() { set(reject); type=41;}
		void select_id_rRCTransfer() { set(reject); type=42;}
		void select_id_secondaryRATDataUsageReport() { set(reject); type=43;}
		void select_id_SgNBActivityNotification() { set(reject); type=44;}
		void select_id_dataForwardingAddressIndication() { set(ignore); type=45;}
		X2AP_ELEMENTARY_PROCEDURE::criticality_t const& ref_value() const {return ref_nested();}
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
			else if(equal(reject)) { type = 11; return true; }
			else if(equal(reject)) { type = 12; return true; }
			else if(equal(reject)) { type = 13; return true; }
			else if(equal(reject)) { type = 14; return true; }
			else if(equal(reject)) { type = 15; return true; }
			else if(equal(reject)) { type = 16; return true; }
			else if(equal(ignore)) { type = 17; return true; }
			else if(equal(reject)) { type = 18; return true; }
			else if(equal(reject)) { type = 19; return true; }
			else if(equal(reject)) { type = 20; return true; }
			else if(equal(reject)) { type = 21; return true; }
			else if(equal(reject)) { type = 22; return true; }
			else if(equal(reject)) { type = 23; return true; }
			else if(equal(reject)) { type = 24; return true; }
			else if(equal(reject)) { type = 25; return true; }
			else if(equal(ignore)) { type = 26; return true; }
			else if(equal(ignore)) { type = 27; return true; }
			else if(equal(ignore)) { type = 28; return true; }
			else if(equal(ignore)) { type = 29; return true; }
			else if(equal(ignore)) { type = 30; return true; }
			else if(equal(ignore)) { type = 31; return true; }
			else if(equal(ignore)) { type = 32; return true; }
			else if(equal(ignore)) { type = 33; return true; }
			else if(equal(ignore)) { type = 34; return true; }
			else if(equal(reject)) { type = 35; return true; }
			else if(equal(reject)) { type = 36; return true; }
			else if(equal(ignore)) { type = 37; return true; }
			else if(equal(ignore)) { type = 38; return true; }
			else if(equal(reject)) { type = 39; return true; }
			else if(equal(ignore)) { type = 40; return true; }
			else if(equal(reject)) { type = 41; return true; }
			else if(equal(reject)) { type = 42; return true; }
			else if(equal(reject)) { type = 43; return true; }
			else if(equal(reject)) { type = 44; return true; }
			else if(equal(ignore)) { type = 45; return true; }
			else { type = 46; return true;}
			return false;

		}
		template<typename V> bool encode(V& v) const
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
			case 11: type = 11; if(v(ref_nested())) { return equal(reject);} return false;
			case 12: type = 12; if(v(ref_nested())) { return equal(reject);} return false;
			case 13: type = 13; if(v(ref_nested())) { return equal(reject);} return false;
			case 14: type = 14; if(v(ref_nested())) { return equal(reject);} return false;
			case 15: type = 15; if(v(ref_nested())) { return equal(reject);} return false;
			case 16: type = 16; if(v(ref_nested())) { return equal(reject);} return false;
			case 17: type = 17; if(v(ref_nested())) { return equal(ignore);} return false;
			case 18: type = 18; if(v(ref_nested())) { return equal(reject);} return false;
			case 19: type = 19; if(v(ref_nested())) { return equal(reject);} return false;
			case 20: type = 20; if(v(ref_nested())) { return equal(reject);} return false;
			case 21: type = 21; if(v(ref_nested())) { return equal(reject);} return false;
			case 22: type = 22; if(v(ref_nested())) { return equal(reject);} return false;
			case 23: type = 23; if(v(ref_nested())) { return equal(reject);} return false;
			case 24: type = 24; if(v(ref_nested())) { return equal(reject);} return false;
			case 25: type = 25; if(v(ref_nested())) { return equal(reject);} return false;
			case 26: type = 26; if(v(ref_nested())) { return equal(ignore);} return false;
			case 27: type = 27; if(v(ref_nested())) { return equal(ignore);} return false;
			case 28: type = 28; if(v(ref_nested())) { return equal(ignore);} return false;
			case 29: type = 29; if(v(ref_nested())) { return equal(ignore);} return false;
			case 30: type = 30; if(v(ref_nested())) { return equal(ignore);} return false;
			case 31: type = 31; if(v(ref_nested())) { return equal(ignore);} return false;
			case 32: type = 32; if(v(ref_nested())) { return equal(ignore);} return false;
			case 33: type = 33; if(v(ref_nested())) { return equal(ignore);} return false;
			case 34: type = 34; if(v(ref_nested())) { return equal(ignore);} return false;
			case 35: type = 35; if(v(ref_nested())) { return equal(reject);} return false;
			case 36: type = 36; if(v(ref_nested())) { return equal(reject);} return false;
			case 37: type = 37; if(v(ref_nested())) { return equal(ignore);} return false;
			case 38: type = 38; if(v(ref_nested())) { return equal(ignore);} return false;
			case 39: type = 39; if(v(ref_nested())) { return equal(reject);} return false;
			case 40: type = 40; if(v(ref_nested())) { return equal(ignore);} return false;
			case 41: type = 41; if(v(ref_nested())) { return equal(reject);} return false;
			case 42: type = 42; if(v(ref_nested())) { return equal(reject);} return false;
			case 43: type = 43; if(v(ref_nested())) { return equal(reject);} return false;
			case 44: type = 44; if(v(ref_nested())) { return equal(reject);} return false;
			case 45: type = 45; if(v(ref_nested())) { return equal(ignore);} return false;
			case 46: type = 46; return v(ref_nested());
			ref_nested().clear();
			}
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
	procedureCode	X2AP-ELEMENTARY-PROCEDURE.&procedureCode		({X2AP-ELEMENTARY-PROCEDURES}),
	criticality		X2AP-ELEMENTARY-PROCEDURE.&criticality			({X2AP-ELEMENTARY-PROCEDURES}{@procedureCode}),
	value			X2AP-ELEMENTARY-PROCEDURE.&InitiatingMessage	({X2AP-ELEMENTARY-PROCEDURES}{@procedureCode})
}
*/

struct InitiatingMessage : asn::sequence<3, 0, false, 0>
{
	static constexpr const char* name() {return "InitiatingMessage";}
	using parent_t = asn::sequence<3, 0, false, 0>;
	struct procedureCode_t : X2AP_ELEMENTARY_PROCEDURES::procedureCode_t
	{
		static constexpr const char* name() {return "procedureCode_t";}
		using parent_t = typename X2AP_ELEMENTARY_PROCEDURES::procedureCode_t;
		template<typename V>  bool decode(V& v, InitiatingMessage const& c)
		{
			return X2AP_ELEMENTARY_PROCEDURES::procedureCode_t::decode(v);
		};
		template<typename V>  bool encode(V& v, InitiatingMessage const& c) const
		{
			return X2AP_ELEMENTARY_PROCEDURES::procedureCode_t::encode(v);
		};
	};
	procedureCode_t& ref_procedureCode() {return procedureCode;}
	procedureCode_t const& ref_procedureCode() const {return procedureCode;}
	struct criticality_t : X2AP_ELEMENTARY_PROCEDURES::criticality_t
	{
		static constexpr const char* name() {return "criticality_t";}
		using parent_t = typename X2AP_ELEMENTARY_PROCEDURES::criticality_t;
		template<typename V>  bool decode(V& v, InitiatingMessage const& c)
		{
			return X2AP_ELEMENTARY_PROCEDURES::criticality_t::decode(c.procedureCode.get_index(), v);
		};
		template<typename V>  bool encode(V& v, InitiatingMessage const& c) const
		{
			return X2AP_ELEMENTARY_PROCEDURES::criticality_t::encode(c.procedureCode.get_index(), v);
		};
	};
	criticality_t& ref_criticality() {return criticality;}
	criticality_t const& ref_criticality() const {return criticality;}
	struct value_t : X2AP_ELEMENTARY_PROCEDURES::InitiatingMessage_t
	{
		static constexpr const char* name() {return "value_t";}
		using parent_t = typename X2AP_ELEMENTARY_PROCEDURES::InitiatingMessage_t;
		template<typename V>  bool decode(V& v, InitiatingMessage const& c)
		{
			return X2AP_ELEMENTARY_PROCEDURES::InitiatingMessage_t::decode(c.procedureCode.get_index(), v);
		};
		template<typename V>  bool encode(V& v, InitiatingMessage const& c) const
		{
			return X2AP_ELEMENTARY_PROCEDURES::InitiatingMessage_t::encode(c.procedureCode.get_index(), v);
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
	procedureCode	X2AP-ELEMENTARY-PROCEDURE.&procedureCode		({X2AP-ELEMENTARY-PROCEDURES}),
	criticality		X2AP-ELEMENTARY-PROCEDURE.&criticality			({X2AP-ELEMENTARY-PROCEDURES}{@procedureCode}),
	value			X2AP-ELEMENTARY-PROCEDURE.&SuccessfulOutcome	({X2AP-ELEMENTARY-PROCEDURES}{@procedureCode})
}
*/

struct SuccessfulOutcome : asn::sequence<3, 0, false, 0>
{
	static constexpr const char* name() {return "SuccessfulOutcome";}
	using parent_t = asn::sequence<3, 0, false, 0>;
	struct procedureCode_t : X2AP_ELEMENTARY_PROCEDURES::procedureCode_t
	{
		static constexpr const char* name() {return "procedureCode_t";}
		using parent_t = typename X2AP_ELEMENTARY_PROCEDURES::procedureCode_t;
		template<typename V>  bool decode(V& v, SuccessfulOutcome const& c)
		{
			return X2AP_ELEMENTARY_PROCEDURES::procedureCode_t::decode(v);
		};
		template<typename V>  bool encode(V& v, SuccessfulOutcome const& c) const
		{
			return X2AP_ELEMENTARY_PROCEDURES::procedureCode_t::encode(v);
		};
	};
	procedureCode_t& ref_procedureCode() {return procedureCode;}
	procedureCode_t const& ref_procedureCode() const {return procedureCode;}
	struct criticality_t : X2AP_ELEMENTARY_PROCEDURES::criticality_t
	{
		static constexpr const char* name() {return "criticality_t";}
		using parent_t = typename X2AP_ELEMENTARY_PROCEDURES::criticality_t;
		template<typename V>  bool decode(V& v, SuccessfulOutcome const& c)
		{
			return X2AP_ELEMENTARY_PROCEDURES::criticality_t::decode(c.procedureCode.get_index(), v);
		};
		template<typename V>  bool encode(V& v, SuccessfulOutcome const& c) const
		{
			return X2AP_ELEMENTARY_PROCEDURES::criticality_t::encode(c.procedureCode.get_index(), v);
		};
	};
	criticality_t& ref_criticality() {return criticality;}
	criticality_t const& ref_criticality() const {return criticality;}
	struct value_t : X2AP_ELEMENTARY_PROCEDURES::SuccessfulOutcome_t
	{
		static constexpr const char* name() {return "value_t";}
		using parent_t = typename X2AP_ELEMENTARY_PROCEDURES::SuccessfulOutcome_t;
		template<typename V>  bool decode(V& v, SuccessfulOutcome const& c)
		{
			return X2AP_ELEMENTARY_PROCEDURES::SuccessfulOutcome_t::decode(c.procedureCode.get_index(), v);
		};
		template<typename V>  bool encode(V& v, SuccessfulOutcome const& c) const
		{
			return X2AP_ELEMENTARY_PROCEDURES::SuccessfulOutcome_t::encode(c.procedureCode.get_index(), v);
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
	procedureCode	X2AP-ELEMENTARY-PROCEDURE.&procedureCode		({X2AP-ELEMENTARY-PROCEDURES}),
	criticality		X2AP-ELEMENTARY-PROCEDURE.&criticality			({X2AP-ELEMENTARY-PROCEDURES}{@procedureCode}),
	value			X2AP-ELEMENTARY-PROCEDURE.&UnsuccessfulOutcome	({X2AP-ELEMENTARY-PROCEDURES}{@procedureCode})
}
*/

struct UnsuccessfulOutcome : asn::sequence<3, 0, false, 0>
{
	static constexpr const char* name() {return "UnsuccessfulOutcome";}
	using parent_t = asn::sequence<3, 0, false, 0>;
	struct procedureCode_t : X2AP_ELEMENTARY_PROCEDURES::procedureCode_t
	{
		static constexpr const char* name() {return "procedureCode_t";}
		using parent_t = typename X2AP_ELEMENTARY_PROCEDURES::procedureCode_t;
		template<typename V>  bool decode(V& v, UnsuccessfulOutcome const& c)
		{
			return X2AP_ELEMENTARY_PROCEDURES::procedureCode_t::decode(v);
		};
		template<typename V>  bool encode(V& v, UnsuccessfulOutcome const& c) const
		{
			return X2AP_ELEMENTARY_PROCEDURES::procedureCode_t::encode(v);
		};
	};
	procedureCode_t& ref_procedureCode() {return procedureCode;}
	procedureCode_t const& ref_procedureCode() const {return procedureCode;}
	struct criticality_t : X2AP_ELEMENTARY_PROCEDURES::criticality_t
	{
		static constexpr const char* name() {return "criticality_t";}
		using parent_t = typename X2AP_ELEMENTARY_PROCEDURES::criticality_t;
		template<typename V>  bool decode(V& v, UnsuccessfulOutcome const& c)
		{
			return X2AP_ELEMENTARY_PROCEDURES::criticality_t::decode(c.procedureCode.get_index(), v);
		};
		template<typename V>  bool encode(V& v, UnsuccessfulOutcome const& c) const
		{
			return X2AP_ELEMENTARY_PROCEDURES::criticality_t::encode(c.procedureCode.get_index(), v);
		};
	};
	criticality_t& ref_criticality() {return criticality;}
	criticality_t const& ref_criticality() const {return criticality;}
	struct value_t : X2AP_ELEMENTARY_PROCEDURES::UnsuccessfulOutcome_t
	{
		static constexpr const char* name() {return "value_t";}
		using parent_t = typename X2AP_ELEMENTARY_PROCEDURES::UnsuccessfulOutcome_t;
		template<typename V>  bool decode(V& v, UnsuccessfulOutcome const& c)
		{
			return X2AP_ELEMENTARY_PROCEDURES::UnsuccessfulOutcome_t::decode(c.procedureCode.get_index(), v);
		};
		template<typename V>  bool encode(V& v, UnsuccessfulOutcome const& c) const
		{
			return X2AP_ELEMENTARY_PROCEDURES::UnsuccessfulOutcome_t::encode(c.procedureCode.get_index(), v);
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
X2AP-PDU ::= CHOICE {
	initiatingMessage	InitiatingMessage,
	successfulOutcome	SuccessfulOutcome,
	unsuccessfulOutcome	UnsuccessfulOutcome,
	...
}
*/

struct X2AP_PDU : asn::choice<3, 0, true>
{
	static constexpr const char* name() {return "X2AP-PDU";}
	using parent_t = asn::choice<3, 0, true>;
	index_type get_index() const {return index;}
	bool is_unknown() const {return index == 4;}
	void set_unknown() { set_index(4);  }
	~X2AP_PDU() {clear();}
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
