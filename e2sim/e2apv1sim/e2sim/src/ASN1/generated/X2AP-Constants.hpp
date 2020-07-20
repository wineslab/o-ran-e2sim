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
id-ABS-Status																ProtocolIE-ID ::= 63
*/

constexpr int64_t id_ABS_Status = 63;
/*
id-ABSInformation															ProtocolIE-ID ::= 61
*/

constexpr int64_t id_ABSInformation = 61;
/*
id-ActivatedCellList														ProtocolIE-ID ::= 58
*/

constexpr int64_t id_ActivatedCellList = 58;
/*
id-ActivatedNRCellList														ProtocolIE-ID ::= 268
*/

constexpr int64_t id_ActivatedNRCellList = 268;
/*
id-ActivationID																ProtocolIE-ID ::= 256
*/

constexpr int64_t id_ActivationID = 256;
/*
id-AdditionalSpecialSubframe-Info											ProtocolIE-ID ::= 97
*/

constexpr int64_t id_AdditionalSpecialSubframe_Info = 97;
/*
id-AdditionalSpecialSubframeExtension-Info									ProtocolIE-ID ::= 179
*/

constexpr int64_t id_AdditionalSpecialSubframeExtension_Info = 179;
/*
id-AdmittedSplitSRBs															ProtocolIE-ID ::= 212
*/

constexpr int64_t id_AdmittedSplitSRBs = 212;
/*
id-AdmittedSplitSRBsrelease													ProtocolIE-ID ::= 281
*/

constexpr int64_t id_AdmittedSplitSRBsrelease = 281;
/*
id-AerialUEsubscriptionInformation											ProtocolIE-ID ::= 277
*/

constexpr int64_t id_AerialUEsubscriptionInformation = 277;
/*
id-BandwidthReducedSI														ProtocolIE-ID ::= 180
*/

constexpr int64_t id_BandwidthReducedSI = 180;
/*
id-BearerType																ProtocolIE-ID ::= 171
*/

constexpr int64_t id_BearerType = 171;
/*
id-BluetoothMeasurementConfiguration										ProtocolIE-ID ::= 303
*/

constexpr int64_t id_BluetoothMeasurementConfiguration = 303;
/*
id-CNTypeRestrictions														ProtocolIE-ID ::= 301
*/

constexpr int64_t id_CNTypeRestrictions = 301;
/*
id-CSG-Id																	ProtocolIE-ID ::= 70
*/

constexpr int64_t id_CSG_Id = 70;
/*
id-CSGMembershipStatus														ProtocolIE-ID ::= 71
*/

constexpr int64_t id_CSGMembershipStatus = 71;
/*
id-CSIReportList															ProtocolIE-ID ::= 146
*/

constexpr int64_t id_CSIReportList = 146;
/*
id-Cause																	ProtocolIE-ID ::= 5
*/

constexpr int64_t id_Cause = 5;
/*
id-CellAssistanceInformation													ProtocolIE-ID ::= 251
*/

constexpr int64_t id_CellAssistanceInformation = 251;
/*
id-CellInformation															ProtocolIE-ID ::= 6
*/

constexpr int64_t id_CellInformation = 6;
/*
id-CellInformation-Item														ProtocolIE-ID ::= 7
*/

constexpr int64_t id_CellInformation_Item = 7;
/*
id-CellMeasurementResult													ProtocolIE-ID ::= 32
*/

constexpr int64_t id_CellMeasurementResult = 32;
/*
id-CellMeasurementResult-Item												ProtocolIE-ID ::= 33
*/

constexpr int64_t id_CellMeasurementResult_Item = 33;
/*
id-CellReportingIndicator													ProtocolIE-ID ::= 170
*/

constexpr int64_t id_CellReportingIndicator = 170;
/*
id-CellToReport																ProtocolIE-ID ::= 29
*/

constexpr int64_t id_CellToReport = 29;
/*
id-CellToReport-Item														ProtocolIE-ID ::= 31
*/

constexpr int64_t id_CellToReport_Item = 31;
/*
id-CoMPInformation															ProtocolIE-ID ::= 108
*/

constexpr int64_t id_CoMPInformation = 108;
/*
id-CompleteFailureCauseInformation-Item										ProtocolIE-ID ::= 69
*/

constexpr int64_t id_CompleteFailureCauseInformation_Item = 69;
/*
id-CompleteFailureCauseInformation-List										ProtocolIE-ID ::= 68
*/

constexpr int64_t id_CompleteFailureCauseInformation_List = 68;
/*
id-CompositeAvailableCapacityGroup											ProtocolIE-ID ::= 42
*/

constexpr int64_t id_CompositeAvailableCapacityGroup = 42;
/*
id-Correlation-ID															ProtocolIE-ID ::= 166
*/

constexpr int64_t id_Correlation_ID = 166;
/*
id-CoverageModificationList													ProtocolIE-ID ::= 143
*/

constexpr int64_t id_CoverageModificationList = 143;
/*
id-CriticalityDiagnostics													ProtocolIE-ID ::= 17
*/

constexpr int64_t id_CriticalityDiagnostics = 17;
/*
id-DL-EARFCNExtension														ProtocolIE-ID ::= 96
*/

constexpr int64_t id_DL_EARFCNExtension = 96;
/*
id-DL-scheduling-PDCCH-CCE-usage											ProtocolIE-ID ::= 193
*/

constexpr int64_t id_DL_scheduling_PDCCH_CCE_usage = 193;
/*
id-DLCOUNTValueExtended														ProtocolIE-ID ::= 93
*/

constexpr int64_t id_DLCOUNTValueExtended = 93;
/*
id-DLCOUNTValuePDCP-SNlength18												ProtocolIE-ID ::= 152
*/

constexpr int64_t id_DLCOUNTValuePDCP_SNlength18 = 152;
/*
id-DataTrafficResourceIndication											ProtocolIE-ID ::= 287
*/

constexpr int64_t id_DataTrafficResourceIndication = 287;
/*
id-DeactivationIndication													ProtocolIE-ID ::= 59
*/

constexpr int64_t id_DeactivationIndication = 59;
/*
id-DownlinkPacketLossRate													ProtocolIE-ID ::= 273
*/

constexpr int64_t id_DownlinkPacketLossRate = 273;
/*
id-DynamicDLTransmissionInformation											ProtocolIE-ID ::= 106
*/

constexpr int64_t id_DynamicDLTransmissionInformation = 106;
/*
id-E-RAB-Item																ProtocolIE-ID ::= 2
*/

constexpr int64_t id_E_RAB_Item = 2;
/*
id-E-RABUsageReport-Item														ProtocolIE-ID ::= 263
*/

constexpr int64_t id_E_RABUsageReport_Item = 263;
/*
id-E-RABs-Admitted-Item														ProtocolIE-ID ::= 0
*/

constexpr int64_t id_E_RABs_Admitted_Item = 0;
/*
id-E-RABs-Admitted-List														ProtocolIE-ID ::= 1
*/

constexpr int64_t id_E_RABs_Admitted_List = 1;
/*
id-E-RABs-Admitted-ToBeAdded-Item											ProtocolIE-ID ::= 121
*/

constexpr int64_t id_E_RABs_Admitted_ToBeAdded_Item = 121;
/*
id-E-RABs-Admitted-ToBeAdded-List											ProtocolIE-ID ::= 120
*/

constexpr int64_t id_E_RABs_Admitted_ToBeAdded_List = 120;
/*
id-E-RABs-Admitted-ToBeAdded-ModAckItem										ProtocolIE-ID ::= 131
*/

constexpr int64_t id_E_RABs_Admitted_ToBeAdded_ModAckItem = 131;
/*
id-E-RABs-Admitted-ToBeAdded-ModAckList										ProtocolIE-ID ::= 128
*/

constexpr int64_t id_E_RABs_Admitted_ToBeAdded_ModAckList = 128;
/*
id-E-RABs-Admitted-ToBeAdded-SgNBAddReqAck-Item								ProtocolIE-ID ::= 213
*/

constexpr int64_t id_E_RABs_Admitted_ToBeAdded_SgNBAddReqAck_Item = 213;
/*
id-E-RABs-Admitted-ToBeAdded-SgNBAddReqAckList								ProtocolIE-ID ::= 210
*/

constexpr int64_t id_E_RABs_Admitted_ToBeAdded_SgNBAddReqAckList = 210;
/*
id-E-RABs-Admitted-ToBeAdded-SgNBModAck-Item									ProtocolIE-ID ::= 222
*/

constexpr int64_t id_E_RABs_Admitted_ToBeAdded_SgNBModAck_Item = 222;
/*
id-E-RABs-Admitted-ToBeAdded-SgNBModAckList									ProtocolIE-ID ::= 219
*/

constexpr int64_t id_E_RABs_Admitted_ToBeAdded_SgNBModAckList = 219;
/*
id-E-RABs-Admitted-ToBeModified-ModAckItem									ProtocolIE-ID ::= 132
*/

constexpr int64_t id_E_RABs_Admitted_ToBeModified_ModAckItem = 132;
/*
id-E-RABs-Admitted-ToBeModified-ModAckList									ProtocolIE-ID ::= 129
*/

constexpr int64_t id_E_RABs_Admitted_ToBeModified_ModAckList = 129;
/*
id-E-RABs-Admitted-ToBeModified-SgNBModAck-Item								ProtocolIE-ID ::= 223
*/

constexpr int64_t id_E_RABs_Admitted_ToBeModified_SgNBModAck_Item = 223;
/*
id-E-RABs-Admitted-ToBeModified-SgNBModAckList								ProtocolIE-ID ::= 220
*/

constexpr int64_t id_E_RABs_Admitted_ToBeModified_SgNBModAckList = 220;
/*
id-E-RABs-Admitted-ToBeReleased-ModAckItem									ProtocolIE-ID ::= 133
*/

constexpr int64_t id_E_RABs_Admitted_ToBeReleased_ModAckItem = 133;
/*
id-E-RABs-Admitted-ToBeReleased-ModAckList									ProtocolIE-ID ::= 130
*/

constexpr int64_t id_E_RABs_Admitted_ToBeReleased_ModAckList = 130;
/*
id-E-RABs-Admitted-ToBeReleased-SgNBModAck-Item								ProtocolIE-ID ::= 224
*/

constexpr int64_t id_E_RABs_Admitted_ToBeReleased_SgNBModAck_Item = 224;
/*
id-E-RABs-Admitted-ToBeReleased-SgNBModAckList								ProtocolIE-ID ::= 221
*/

constexpr int64_t id_E_RABs_Admitted_ToBeReleased_SgNBModAckList = 221;
/*
id-E-RABs-Admitted-ToBeReleased-SgNBRelReqAck-Item							ProtocolIE-ID ::= 319
*/

constexpr int64_t id_E_RABs_Admitted_ToBeReleased_SgNBRelReqAck_Item = 319;
/*
id-E-RABs-Admitted-ToBeReleased-SgNBRelReqAckList							ProtocolIE-ID ::= 318
*/

constexpr int64_t id_E_RABs_Admitted_ToBeReleased_SgNBRelReqAckList = 318;
/*
id-E-RABs-AdmittedToBeModified-SgNBModConf-Item								ProtocolIE-ID ::= 295
*/

constexpr int64_t id_E_RABs_AdmittedToBeModified_SgNBModConf_Item = 295;
/*
id-E-RABs-AdmittedToBeModified-SgNBModConfList								ProtocolIE-ID ::= 294
*/

constexpr int64_t id_E_RABs_AdmittedToBeModified_SgNBModConfList = 294;
/*
id-E-RABs-DataForwardingAddress-Item										ProtocolIE-ID ::= 308
*/

constexpr int64_t id_E_RABs_DataForwardingAddress_Item = 308;
/*
id-E-RABs-DataForwardingAddress-List										ProtocolIE-ID ::= 307
*/

constexpr int64_t id_E_RABs_DataForwardingAddress_List = 307;
/*
id-E-RABs-NotAdmitted-List													ProtocolIE-ID ::= 3
*/

constexpr int64_t id_E_RABs_NotAdmitted_List = 3;
/*
id-E-RABs-SubjectToCounterCheck-List										ProtocolIE-ID ::= 141
*/

constexpr int64_t id_E_RABs_SubjectToCounterCheck_List = 141;
/*
id-E-RABs-SubjectToCounterCheckItem											ProtocolIE-ID ::= 142
*/

constexpr int64_t id_E_RABs_SubjectToCounterCheckItem = 142;
/*
id-E-RABs-SubjectToSgNBCounterCheck-Item										ProtocolIE-ID ::= 236
*/

constexpr int64_t id_E_RABs_SubjectToSgNBCounterCheck_Item = 236;
/*
id-E-RABs-SubjectToSgNBCounterCheck-List										ProtocolIE-ID ::= 235
*/

constexpr int64_t id_E_RABs_SubjectToSgNBCounterCheck_List = 235;
/*
id-E-RABs-SubjectToStatusTransfer-Item										ProtocolIE-ID ::= 19
*/

constexpr int64_t id_E_RABs_SubjectToStatusTransfer_Item = 19;
/*
id-E-RABs-SubjectToStatusTransfer-List										ProtocolIE-ID ::= 18
*/

constexpr int64_t id_E_RABs_SubjectToStatusTransfer_List = 18;
/*
id-E-RABs-ToBeAdded-Item													ProtocolIE-ID ::= 118
*/

constexpr int64_t id_E_RABs_ToBeAdded_Item = 118;
/*
id-E-RABs-ToBeAdded-List													ProtocolIE-ID ::= 117
*/

constexpr int64_t id_E_RABs_ToBeAdded_List = 117;
/*
id-E-RABs-ToBeAdded-ModReqItem												ProtocolIE-ID ::= 125
*/

constexpr int64_t id_E_RABs_ToBeAdded_ModReqItem = 125;
/*
id-E-RABs-ToBeAdded-SgNBAddReq-Item											ProtocolIE-ID ::= 209
*/

constexpr int64_t id_E_RABs_ToBeAdded_SgNBAddReq_Item = 209;
/*
id-E-RABs-ToBeAdded-SgNBAddReqList											ProtocolIE-ID ::= 205
*/

constexpr int64_t id_E_RABs_ToBeAdded_SgNBAddReqList = 205;
/*
id-E-RABs-ToBeAdded-SgNBModReq-Item											ProtocolIE-ID ::= 216
*/

constexpr int64_t id_E_RABs_ToBeAdded_SgNBModReq_Item = 216;
/*
id-E-RABs-ToBeModified-ModReqItem											ProtocolIE-ID ::= 126
*/

constexpr int64_t id_E_RABs_ToBeModified_ModReqItem = 126;
/*
id-E-RABs-ToBeModified-SgNBModReq-Item										ProtocolIE-ID ::= 217
*/

constexpr int64_t id_E_RABs_ToBeModified_SgNBModReq_Item = 217;
/*
id-E-RABs-ToBeModified-SgNBModReqd-Item										ProtocolIE-ID ::= 228
*/

constexpr int64_t id_E_RABs_ToBeModified_SgNBModReqd_Item = 228;
/*
id-E-RABs-ToBeModified-SgNBModReqdList										ProtocolIE-ID ::= 226
*/

constexpr int64_t id_E_RABs_ToBeModified_SgNBModReqdList = 226;
/*
id-E-RABs-ToBeReleased-List-RelConf											ProtocolIE-ID ::= 139
*/

constexpr int64_t id_E_RABs_ToBeReleased_List_RelConf = 139;
/*
id-E-RABs-ToBeReleased-List-RelReq											ProtocolIE-ID ::= 137
*/

constexpr int64_t id_E_RABs_ToBeReleased_List_RelReq = 137;
/*
id-E-RABs-ToBeReleased-ModReqItem											ProtocolIE-ID ::= 127
*/

constexpr int64_t id_E_RABs_ToBeReleased_ModReqItem = 127;
/*
id-E-RABs-ToBeReleased-ModReqd												ProtocolIE-ID ::= 134
*/

constexpr int64_t id_E_RABs_ToBeReleased_ModReqd = 134;
/*
id-E-RABs-ToBeReleased-ModReqdItem											ProtocolIE-ID ::= 135
*/

constexpr int64_t id_E_RABs_ToBeReleased_ModReqdItem = 135;
/*
id-E-RABs-ToBeReleased-RelConfItem											ProtocolIE-ID ::= 140
*/

constexpr int64_t id_E_RABs_ToBeReleased_RelConfItem = 140;
/*
id-E-RABs-ToBeReleased-RelReqItem											ProtocolIE-ID ::= 138
*/

constexpr int64_t id_E_RABs_ToBeReleased_RelReqItem = 138;
/*
id-E-RABs-ToBeReleased-SgNBChaConf-Item										ProtocolIE-ID ::= 230
*/

constexpr int64_t id_E_RABs_ToBeReleased_SgNBChaConf_Item = 230;
/*
id-E-RABs-ToBeReleased-SgNBChaConfList										ProtocolIE-ID ::= 229
*/

constexpr int64_t id_E_RABs_ToBeReleased_SgNBChaConfList = 229;
/*
id-E-RABs-ToBeReleased-SgNBModReq-Item										ProtocolIE-ID ::= 218
*/

constexpr int64_t id_E_RABs_ToBeReleased_SgNBModReq_Item = 218;
/*
id-E-RABs-ToBeReleased-SgNBModReqd-Item										ProtocolIE-ID ::= 227
*/

constexpr int64_t id_E_RABs_ToBeReleased_SgNBModReqd_Item = 227;
/*
id-E-RABs-ToBeReleased-SgNBModReqdList										ProtocolIE-ID ::= 225
*/

constexpr int64_t id_E_RABs_ToBeReleased_SgNBModReqdList = 225;
/*
id-E-RABs-ToBeReleased-SgNBRelConf-Item										ProtocolIE-ID ::= 234
*/

constexpr int64_t id_E_RABs_ToBeReleased_SgNBRelConf_Item = 234;
/*
id-E-RABs-ToBeReleased-SgNBRelConfList										ProtocolIE-ID ::= 233
*/

constexpr int64_t id_E_RABs_ToBeReleased_SgNBRelConfList = 233;
/*
id-E-RABs-ToBeReleased-SgNBRelReq-Item										ProtocolIE-ID ::= 232
*/

constexpr int64_t id_E_RABs_ToBeReleased_SgNBRelReq_Item = 232;
/*
id-E-RABs-ToBeReleased-SgNBRelReqList										ProtocolIE-ID ::= 231
*/

constexpr int64_t id_E_RABs_ToBeReleased_SgNBRelReqList = 231;
/*
id-E-RABs-ToBeReleased-SgNBRelReqd-Item										ProtocolIE-ID ::= 321
*/

constexpr int64_t id_E_RABs_ToBeReleased_SgNBRelReqd_Item = 321;
/*
id-E-RABs-ToBeReleased-SgNBRelReqdList										ProtocolIE-ID ::= 320
*/

constexpr int64_t id_E_RABs_ToBeReleased_SgNBRelReqdList = 320;
/*
id-E-RABs-ToBeSetup-Item													ProtocolIE-ID ::= 4
*/

constexpr int64_t id_E_RABs_ToBeSetup_Item = 4;
/*
id-E-RABs-ToBeSetupRetrieve-Item											ProtocolIE-ID ::= 174
*/

constexpr int64_t id_E_RABs_ToBeSetupRetrieve_Item = 174;
/*
id-ECGI																		ProtocolIE-ID ::= 316
*/

constexpr int64_t id_ECGI = 316;
/*
id-ENB1-Cell-ID																ProtocolIE-ID ::= 43
*/

constexpr int64_t id_ENB1_Cell_ID = 43;
/*
id-ENB1-Measurement-ID														ProtocolIE-ID ::= 39
*/

constexpr int64_t id_ENB1_Measurement_ID = 39;
/*
id-ENB1-Mobility-Parameters													ProtocolIE-ID ::= 46
*/

constexpr int64_t id_ENB1_Mobility_Parameters = 46;
/*
id-ENB2-Cell-ID																ProtocolIE-ID ::= 44
*/

constexpr int64_t id_ENB2_Cell_ID = 44;
/*
id-ENB2-Measurement-ID														ProtocolIE-ID ::= 40
*/

constexpr int64_t id_ENB2_Measurement_ID = 40;
/*
id-ENB2-Mobility-Parameters-Modification-Range								ProtocolIE-ID ::= 47
*/

constexpr int64_t id_ENB2_Mobility_Parameters_Modification_Range = 47;
/*
id-ENB2-Proposed-Mobility-Parameters										ProtocolIE-ID ::= 45
*/

constexpr int64_t id_ENB2_Proposed_Mobility_Parameters = 45;
/*
id-ERABActivityNotifyItemList												ProtocolIE-ID ::= 297
*/

constexpr int64_t id_ERABActivityNotifyItemList = 297;
/*
id-ExpectedUEBehaviour														ProtocolIE-ID ::= 104
*/

constexpr int64_t id_ExpectedUEBehaviour = 104;
/*
id-ExtendedULInterferenceOverloadInfo										ProtocolIE-ID ::= 100
*/

constexpr int64_t id_ExtendedULInterferenceOverloadInfo = 100;
/*
id-FailureCellCRNTI															ProtocolIE-ID ::= 50
*/

constexpr int64_t id_FailureCellCRNTI = 50;
/*
id-FailureCellECGI															ProtocolIE-ID ::= 53
*/

constexpr int64_t id_FailureCellECGI = 53;
/*
id-FailureCellPCI															ProtocolIE-ID ::= 48
*/

constexpr int64_t id_FailureCellPCI = 48;
/*
id-FreqBandIndicatorPriority												ProtocolIE-ID ::= 160
*/

constexpr int64_t id_FreqBandIndicatorPriority = 160;
/*
id-GNBOverloadInformation													ProtocolIE-ID ::= 310
*/

constexpr int64_t id_GNBOverloadInformation = 310;
/*
id-GUGroupIDList															ProtocolIE-ID ::= 24
*/

constexpr int64_t id_GUGroupIDList = 24;
/*
id-GUGroupIDToAddList														ProtocolIE-ID ::= 34
*/

constexpr int64_t id_GUGroupIDToAddList = 34;
/*
id-GUGroupIDToDeleteList													ProtocolIE-ID ::= 35
*/

constexpr int64_t id_GUGroupIDToDeleteList = 35;
/*
id-GUMMEI-ID																ProtocolIE-ID ::= 23
*/

constexpr int64_t id_GUMMEI_ID = 23;
/*
id-GW-TransportLayerAddress													ProtocolIE-ID ::= 165
*/

constexpr int64_t id_GW_TransportLayerAddress = 165;
/*
id-GlobalENB-ID																ProtocolIE-ID ::= 21
*/

constexpr int64_t id_GlobalENB_ID = 21;
/*
id-Globalen-gNB-ID															ProtocolIE-ID ::= 252
*/

constexpr int64_t id_Globalen_gNB_ID = 252;
/*
id-HO-cause																	ProtocolIE-ID ::= 80
*/

constexpr int64_t id_HO_cause = 80;
/*
id-HandoverReportType														ProtocolIE-ID ::= 54
*/

constexpr int64_t id_HandoverReportType = 54;
/*
id-HandoverRestrictionList													ProtocolIE-ID ::= 240
*/

constexpr int64_t id_HandoverRestrictionList = 240;
/*
id-InitiatingNodeType-EndcConfigUpdate										ProtocolIE-ID ::= 245
*/

constexpr int64_t id_InitiatingNodeType_EndcConfigUpdate = 245;
/*
id-InitiatingNodeType-EndcX2Removal											ProtocolIE-ID ::= 298
*/

constexpr int64_t id_InitiatingNodeType_EndcX2Removal = 298;
/*
id-InitiatingNodeType-EndcX2Setup											ProtocolIE-ID ::= 244
*/

constexpr int64_t id_InitiatingNodeType_EndcX2Setup = 244;
/*
id-InitiatingNodeType-EutranrCellResourceCoordination						ProtocolIE-ID ::= 285
*/

constexpr int64_t id_InitiatingNodeType_EutranrCellResourceCoordination = 285;
/*
id-IntendedULDLConfiguration												ProtocolIE-ID ::= 99
*/

constexpr int64_t id_IntendedULDLConfiguration = 99;
/*
id-InvokeIndication															ProtocolIE-ID ::= 62
*/

constexpr int64_t id_InvokeIndication = 62;
/*
id-LHN-ID																	ProtocolIE-ID ::= 159
*/

constexpr int64_t id_LHN_ID = 159;
/*
id-ListofEUTRACellsinEUTRACoordinationReq									ProtocolIE-ID ::= 289
*/

constexpr int64_t id_ListofEUTRACellsinEUTRACoordinationReq = 289;
/*
id-ListofEUTRACellsinEUTRACoordinationResp									ProtocolIE-ID ::= 290
*/

constexpr int64_t id_ListofEUTRACellsinEUTRACoordinationResp = 290;
/*
id-ListofEUTRACellsinNRCoordinationReq										ProtocolIE-ID ::= 291
*/

constexpr int64_t id_ListofEUTRACellsinNRCoordinationReq = 291;
/*
id-ListofNRCellsinNRCoordinationReq											ProtocolIE-ID ::= 292
*/

constexpr int64_t id_ListofNRCellsinNRCoordinationReq = 292;
/*
id-ListofNRCellsinNRCoordinationResp										ProtocolIE-ID ::= 293
*/

constexpr int64_t id_ListofNRCellsinNRCoordinationResp = 293;
/*
id-M3Configuration															ProtocolIE-ID ::= 85
*/

constexpr int64_t id_M3Configuration = 85;
/*
id-M4Configuration															ProtocolIE-ID ::= 86
*/

constexpr int64_t id_M4Configuration = 86;
/*
id-M5Configuration															ProtocolIE-ID ::= 87
*/

constexpr int64_t id_M5Configuration = 87;
/*
id-M6Configuration															ProtocolIE-ID ::= 161
*/

constexpr int64_t id_M6Configuration = 161;
/*
id-M7Configuration															ProtocolIE-ID ::= 162
*/

constexpr int64_t id_M7Configuration = 162;
/*
id-MBMS-Service-Area-List													ProtocolIE-ID ::= 79
*/

constexpr int64_t id_MBMS_Service_Area_List = 79;
/*
id-MBSFN-Subframe-Info														ProtocolIE-ID ::= 56
*/

constexpr int64_t id_MBSFN_Subframe_Info = 56;
/*
id-MDT-Location-Info														ProtocolIE-ID ::= 88
*/

constexpr int64_t id_MDT_Location_Info = 88;
/*
id-MDTConfiguration															ProtocolIE-ID ::= 72
*/

constexpr int64_t id_MDTConfiguration = 72;
/*
id-MakeBeforeBreakIndicator													ProtocolIE-ID ::= 181
*/

constexpr int64_t id_MakeBeforeBreakIndicator = 181;
/*
id-ManagementBasedMDTPLMNList												ProtocolIE-ID ::= 89
*/

constexpr int64_t id_ManagementBasedMDTPLMNList = 89;
/*
id-ManagementBasedMDTallowed												ProtocolIE-ID ::= 74
*/

constexpr int64_t id_ManagementBasedMDTallowed = 74;
/*
id-Masked-IMEISV															ProtocolIE-ID ::= 98
*/

constexpr int64_t id_Masked_IMEISV = 98;
/*
id-MeNB-UE-X2AP-ID															ProtocolIE-ID ::= 111
*/

constexpr int64_t id_MeNB_UE_X2AP_ID = 111;
/*
id-MeNB-UE-X2AP-ID-Extension												ProtocolIE-ID ::= 157
*/

constexpr int64_t id_MeNB_UE_X2AP_ID_Extension = 157;
/*
id-MeNBCell-ID																ProtocolIE-ID ::= 279
*/

constexpr int64_t id_MeNBCell_ID = 279;
/*
id-MeNBCoordinationAssistanceInformation									ProtocolIE-ID ::= 323
*/

constexpr int64_t id_MeNBCoordinationAssistanceInformation = 323;
/*
id-MeNBResourceCoordinationInformation										ProtocolIE-ID ::= 257
*/

constexpr int64_t id_MeNBResourceCoordinationInformation = 257;
/*
id-MeNBtoSeNBContainer														ProtocolIE-ID ::= 119
*/

constexpr int64_t id_MeNBtoSeNBContainer = 119;
/*
id-MeNBtoSgNBContainer														ProtocolIE-ID ::= 206
*/

constexpr int64_t id_MeNBtoSgNBContainer = 206;
/*
id-Measurement-ID															ProtocolIE-ID ::= 37
*/

constexpr int64_t id_Measurement_ID = 37;
/*
id-MeasurementFailureCause-Item												ProtocolIE-ID ::= 67
*/

constexpr int64_t id_MeasurementFailureCause_Item = 67;
/*
id-MeasurementInitiationResult-Item											ProtocolIE-ID ::= 66
*/

constexpr int64_t id_MeasurementInitiationResult_Item = 66;
/*
id-MeasurementInitiationResult-List											ProtocolIE-ID ::= 65
*/

constexpr int64_t id_MeasurementInitiationResult_List = 65;
/*
id-MobilityInformation														ProtocolIE-ID ::= 82
*/

constexpr int64_t id_MobilityInformation = 82;
/*
id-MultibandInfoList														ProtocolIE-ID ::= 84
*/

constexpr int64_t id_MultibandInfoList = 84;
/*
id-NRCGI																	ProtocolIE-ID ::= 322
*/

constexpr int64_t id_NRCGI = 322;
/*
id-NRS-NSSS-PowerOffset														ProtocolIE-ID ::= 282
*/

constexpr int64_t id_NRS_NSSS_PowerOffset = 282;
/*
id-NRUESecurityCapabilities													ProtocolIE-ID ::= 248
*/

constexpr int64_t id_NRUESecurityCapabilities = 248;
/*
id-NRrestrictionin5GS														ProtocolIE-ID ::= 305
*/

constexpr int64_t id_NRrestrictionin5GS = 305;
/*
id-NRrestrictioninEPSasSecondaryRAT											ProtocolIE-ID ::= 202
*/

constexpr int64_t id_NRrestrictioninEPSasSecondaryRAT = 202;
/*
id-NSSS-NumOccasionDifferentPrecoder										ProtocolIE-ID ::= 283
*/

constexpr int64_t id_NSSS_NumOccasionDifferentPrecoder = 283;
/*
id-NeighbourTAC																ProtocolIE-ID ::= 76
*/

constexpr int64_t id_NeighbourTAC = 76;
/*
id-New-eNB-UE-X2AP-ID														ProtocolIE-ID ::= 9
*/

constexpr int64_t id_New_eNB_UE_X2AP_ID = 9;
/*
id-New-eNB-UE-X2AP-ID-Extension												ProtocolIE-ID ::= 155
*/

constexpr int64_t id_New_eNB_UE_X2AP_ID_Extension = 155;
/*
id-NewEUTRANCellIdentifier													ProtocolIE-ID ::= 175
*/

constexpr int64_t id_NewEUTRANCellIdentifier = 175;
/*
id-Number-of-Antennaports													ProtocolIE-ID ::= 41
*/

constexpr int64_t id_Number_of_Antennaports = 41;
/*
id-OffsetOfNbiotChannelNumberToDL-EARFCN									ProtocolIE-ID ::= 177
*/

constexpr int64_t id_OffsetOfNbiotChannelNumberToDL_EARFCN = 177;
/*
id-OffsetOfNbiotChannelNumberToUL-EARFCN									ProtocolIE-ID ::= 178
*/

constexpr int64_t id_OffsetOfNbiotChannelNumberToUL_EARFCN = 178;
/*
id-Old-SgNB-UE-X2AP-ID														ProtocolIE-ID ::= 264
*/

constexpr int64_t id_Old_SgNB_UE_X2AP_ID = 264;
/*
id-Old-eNB-UE-X2AP-ID														ProtocolIE-ID ::= 10
*/

constexpr int64_t id_Old_eNB_UE_X2AP_ID = 10;
/*
id-Old-eNB-UE-X2AP-ID-Extension												ProtocolIE-ID ::= 156
*/

constexpr int64_t id_Old_eNB_UE_X2AP_ID_Extension = 156;
/*
id-PDCPChangeIndication														ProtocolIE-ID ::= 249
*/

constexpr int64_t id_PDCPChangeIndication = 249;
/*
id-PRACH-Configuration														ProtocolIE-ID ::= 55
*/

constexpr int64_t id_PRACH_Configuration = 55;
/*
id-PartialSuccessIndicator													ProtocolIE-ID ::= 64
*/

constexpr int64_t id_PartialSuccessIndicator = 64;
/*
id-ProSeAuthorized															ProtocolIE-ID ::= 103
*/

constexpr int64_t id_ProSeAuthorized = 103;
/*
id-ProSeUEtoNetworkRelaying													ProtocolIE-ID ::= 149
*/

constexpr int64_t id_ProSeUEtoNetworkRelaying = 149;
/*
id-ProtectedEUTRAResourceIndication											ProtocolIE-ID ::= 284
*/

constexpr int64_t id_ProtectedEUTRAResourceIndication = 284;
/*
id-RLC-Status																ProtocolIE-ID ::= 300
*/

constexpr int64_t id_RLC_Status = 300;
/*
id-RLCMode-transferred														ProtocolIE-ID ::= 317
*/

constexpr int64_t id_RLCMode_transferred = 317;
/*
id-RNL-Header																ProtocolIE-ID ::= 101
*/

constexpr int64_t id_RNL_Header = 101;
/*
id-RRCConfigIndication														ProtocolIE-ID ::= 272
*/

constexpr int64_t id_RRCConfigIndication = 272;
/*
id-RRCConnReestabIndicator													ProtocolIE-ID ::= 78
*/

constexpr int64_t id_RRCConnReestabIndicator = 78;
/*
id-RRCConnSetupIndicator													ProtocolIE-ID ::= 75
*/

constexpr int64_t id_RRCConnSetupIndicator = 75;
/*
id-RRCContainer																ProtocolIE-ID ::= 237
*/

constexpr int64_t id_RRCContainer = 237;
/*
id-RSRPMRList																ProtocolIE-ID ::= 110
*/

constexpr int64_t id_RSRPMRList = 110;
/*
id-Re-establishmentCellECGI													ProtocolIE-ID ::= 49
*/

constexpr int64_t id_Re_establishmentCellECGI = 49;
/*
id-ReceiveStatusOfULPDCPSDUsExtended										ProtocolIE-ID ::= 91
*/

constexpr int64_t id_ReceiveStatusOfULPDCPSDUsExtended = 91;
/*
id-ReceiveStatusOfULPDCPSDUsPDCP-SNlength18									ProtocolIE-ID ::= 150
*/

constexpr int64_t id_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18 = 150;
/*
id-Registration-Request														ProtocolIE-ID ::= 28
*/

constexpr int64_t id_Registration_Request = 28;
/*
id-ReportCharacteristics													ProtocolIE-ID ::= 38
*/

constexpr int64_t id_ReportCharacteristics = 38;
/*
id-ReportingPeriodicity														ProtocolIE-ID ::= 30
*/

constexpr int64_t id_ReportingPeriodicity = 30;
/*
id-ReportingPeriodicityCSIR													ProtocolIE-ID ::= 145
*/

constexpr int64_t id_ReportingPeriodicityCSIR = 145;
/*
id-ReportingPeriodicityRSRPMR												ProtocolIE-ID ::= 109
*/

constexpr int64_t id_ReportingPeriodicityRSRPMR = 109;
/*
id-RequestedSplitSRBs														ProtocolIE-ID ::= 208
*/

constexpr int64_t id_RequestedSplitSRBs = 208;
/*
id-RequestedSplitSRBsrelease												ProtocolIE-ID ::= 280
*/

constexpr int64_t id_RequestedSplitSRBsrelease = 280;
/*
id-RespondingNodeType-EndcConfigUpdate										ProtocolIE-ID ::= 247
*/

constexpr int64_t id_RespondingNodeType_EndcConfigUpdate = 247;
/*
id-RespondingNodeType-EndcX2Removal											ProtocolIE-ID ::= 299
*/

constexpr int64_t id_RespondingNodeType_EndcX2Removal = 299;
/*
id-RespondingNodeType-EndcX2Setup											ProtocolIE-ID ::= 246
*/

constexpr int64_t id_RespondingNodeType_EndcX2Setup = 246;
/*
id-RespondingNodeType-EutranrCellResourceCoordination						ProtocolIE-ID ::= 286
*/

constexpr int64_t id_RespondingNodeType_EutranrCellResourceCoordination = 286;
/*
id-ResponseInformationSeNBReconfComp										ProtocolIE-ID ::= 123
*/

constexpr int64_t id_ResponseInformationSeNBReconfComp = 123;
/*
id-ResponseInformationSgNBReconfComp											ProtocolIE-ID ::= 214
*/

constexpr int64_t id_ResponseInformationSgNBReconfComp = 214;
/*
id-SCGChangeIndication														ProtocolIE-ID ::= 136
*/

constexpr int64_t id_SCGChangeIndication = 136;
/*
id-SCGConfigurationQuery														ProtocolIE-ID ::= 241
*/

constexpr int64_t id_SCGConfigurationQuery = 241;
/*
id-SGNB-Addition-Trigger-Ind												ProtocolIE-ID ::= 278
*/

constexpr int64_t id_SGNB_Addition_Trigger_Ind = 278;
/*
id-SIPTO-BearerDeactivationIndication										ProtocolIE-ID ::= 164
*/

constexpr int64_t id_SIPTO_BearerDeactivationIndication = 164;
/*
id-SIPTO-Correlation-ID														ProtocolIE-ID ::= 167
*/

constexpr int64_t id_SIPTO_Correlation_ID = 167;
/*
id-SIPTO-L-GW-TransportLayerAddress											ProtocolIE-ID ::= 168
*/

constexpr int64_t id_SIPTO_L_GW_TransportLayerAddress = 168;
/*
id-SRBType																	ProtocolIE-ID ::= 238
*/

constexpr int64_t id_SRBType = 238;
/*
id-SRVCCOperationPossible													ProtocolIE-ID ::= 36
*/

constexpr int64_t id_SRVCCOperationPossible = 36;
/*
id-SeNB-UE-X2AP-ID															ProtocolIE-ID ::= 112
*/

constexpr int64_t id_SeNB_UE_X2AP_ID = 112;
/*
id-SeNB-UE-X2AP-ID-Extension												ProtocolIE-ID ::= 158
*/

constexpr int64_t id_SeNB_UE_X2AP_ID_Extension = 158;
/*
id-SeNBSecurityKey															ProtocolIE-ID ::= 114
*/

constexpr int64_t id_SeNBSecurityKey = 114;
/*
id-SeNBUEAggregateMaximumBitRate											ProtocolIE-ID ::= 115
*/

constexpr int64_t id_SeNBUEAggregateMaximumBitRate = 115;
/*
id-SeNBtoMeNBContainer														ProtocolIE-ID ::= 122
*/

constexpr int64_t id_SeNBtoMeNBContainer = 122;
/*
id-SecondaryRATUsageReport													ProtocolIE-ID ::= 255
*/

constexpr int64_t id_SecondaryRATUsageReport = 255;
/*
id-SecondaryRATUsageReport-Item												ProtocolIE-ID ::= 266
*/

constexpr int64_t id_SecondaryRATUsageReport_Item = 266;
/*
id-SecondaryRATUsageReportList												ProtocolIE-ID ::= 265
*/

constexpr int64_t id_SecondaryRATUsageReportList = 265;
/*
id-SelectedPLMN																ProtocolIE-ID ::= 269
*/

constexpr int64_t id_SelectedPLMN = 269;
/*
id-ServedCells																ProtocolIE-ID ::= 20
*/

constexpr int64_t id_ServedCells = 20;
/*
id-ServedCellsToActivate													ProtocolIE-ID ::= 57
*/

constexpr int64_t id_ServedCellsToActivate = 57;
/*
id-ServedCellsToAdd															ProtocolIE-ID ::= 25
*/

constexpr int64_t id_ServedCellsToAdd = 25;
/*
id-ServedCellsToDelete														ProtocolIE-ID ::= 27
*/

constexpr int64_t id_ServedCellsToDelete = 27;
/*
id-ServedCellsToModify														ProtocolIE-ID ::= 26
*/

constexpr int64_t id_ServedCellsToModify = 26;
/*
id-ServedEUTRAcellsENDCX2ManagementList										ProtocolIE-ID ::= 250
*/

constexpr int64_t id_ServedEUTRAcellsENDCX2ManagementList = 250;
/*
id-ServedEUTRAcellsToDeleteListENDCConfUpd									ProtocolIE-ID ::= 260
*/

constexpr int64_t id_ServedEUTRAcellsToDeleteListENDCConfUpd = 260;
/*
id-ServedEUTRAcellsToModifyListENDCConfUpd									ProtocolIE-ID ::= 259
*/

constexpr int64_t id_ServedEUTRAcellsToModifyListENDCConfUpd = 259;
/*
id-ServedNRCellsToActivate													ProtocolIE-ID ::= 267
*/

constexpr int64_t id_ServedNRCellsToActivate = 267;
/*
id-ServedNRcellsENDCX2ManagementList											ProtocolIE-ID ::= 253
*/

constexpr int64_t id_ServedNRcellsENDCX2ManagementList = 253;
/*
id-ServedNRcellsToDeleteListENDCConfUpd										ProtocolIE-ID ::= 262
*/

constexpr int64_t id_ServedNRcellsToDeleteListENDCConfUpd = 262;
/*
id-ServedNRcellsToModifyListENDCConfUpd										ProtocolIE-ID ::= 261
*/

constexpr int64_t id_ServedNRcellsToModifyListENDCConfUpd = 261;
/*
id-ServingPLMN																ProtocolIE-ID ::= 116
*/

constexpr int64_t id_ServingPLMN = 116;
/*
id-SgNB-UE-X2AP-ID															ProtocolIE-ID ::= 207
*/

constexpr int64_t id_SgNB_UE_X2AP_ID = 207;
/*
id-SgNBActivityNotification										ProcedureCode ::= 42
*/

constexpr int64_t id_SgNBActivityNotification = 42;
/*
id-SgNBCoordinationAssistanceInformation									ProtocolIE-ID ::= 324
*/

constexpr int64_t id_SgNBCoordinationAssistanceInformation = 324;
/*
id-SgNBResourceCoordinationInformation										ProtocolIE-ID ::= 258
*/

constexpr int64_t id_SgNBResourceCoordinationInformation = 258;
/*
id-SgNBSecurityKey															ProtocolIE-ID ::= 203
*/

constexpr int64_t id_SgNBSecurityKey = 203;
/*
id-SgNBUEAggregateMaximumBitRate												ProtocolIE-ID ::= 204
*/

constexpr int64_t id_SgNBUEAggregateMaximumBitRate = 204;
/*
id-SgNBtoMeNBContainer														ProtocolIE-ID ::= 211
*/

constexpr int64_t id_SgNBtoMeNBContainer = 211;
/*
id-ShortMAC-I																ProtocolIE-ID ::= 51
*/

constexpr int64_t id_ShortMAC_I = 51;
/*
id-SignallingBasedMDTPLMNList												ProtocolIE-ID ::= 90
*/

constexpr int64_t id_SignallingBasedMDTPLMNList = 90;
/*
id-SourceCellCRNTI															ProtocolIE-ID ::= 83
*/

constexpr int64_t id_SourceCellCRNTI = 83;
/*
id-SourceCellECGI															ProtocolIE-ID ::= 52
*/

constexpr int64_t id_SourceCellECGI = 52;
/*
id-SpectrumSharingGroupID													ProtocolIE-ID ::= 288
*/

constexpr int64_t id_SpectrumSharingGroupID = 288;
/*
id-SplitSRB																	ProtocolIE-ID ::= 242
*/

constexpr int64_t id_SplitSRB = 242;
/*
id-SubscriberProfileIDforRFP												ProtocolIE-ID ::= 275
*/

constexpr int64_t id_SubscriberProfileIDforRFP = 275;
/*
id-Subscription-Based-UE-DifferentiationInfo								ProtocolIE-ID ::= 309
*/

constexpr int64_t id_Subscription_Based_UE_DifferentiationInfo = 309;
/*
id-Target-SgNB-ID															ProtocolIE-ID ::= 239
*/

constexpr int64_t id_Target_SgNB_ID = 239;
/*
id-TargetCell-ID															ProtocolIE-ID ::= 11
*/

constexpr int64_t id_TargetCell_ID = 11;
/*
id-TargetCellInUTRAN														ProtocolIE-ID ::= 81
*/

constexpr int64_t id_TargetCellInUTRAN = 81;
/*
id-TargeteNBtoSource-eNBTransparentContainer								ProtocolIE-ID ::= 12
*/

constexpr int64_t id_TargeteNBtoSource_eNBTransparentContainer = 12;
/*
id-Time-UE-StayedInCell-EnhancedGranularity									ProtocolIE-ID ::= 77
*/

constexpr int64_t id_Time_UE_StayedInCell_EnhancedGranularity = 77;
/*
id-TimeToWait																ProtocolIE-ID ::= 22
*/

constexpr int64_t id_TimeToWait = 22;
/*
id-TraceActivation															ProtocolIE-ID ::= 13
*/

constexpr int64_t id_TraceActivation = 13;
/*
id-Tunnel-Information-for-BBF												ProtocolIE-ID ::= 163
*/

constexpr int64_t id_Tunnel_Information_for_BBF = 163;
/*
id-UE-ContextInformation													ProtocolIE-ID ::= 14
*/

constexpr int64_t id_UE_ContextInformation = 14;
/*
id-UE-ContextInformation-SgNBModReq											ProtocolIE-ID ::= 215
*/

constexpr int64_t id_UE_ContextInformation_SgNBModReq = 215;
/*
id-UE-ContextInformationRetrieve											ProtocolIE-ID ::= 173
*/

constexpr int64_t id_UE_ContextInformationRetrieve = 173;
/*
id-UE-ContextInformationSeNBModReq											ProtocolIE-ID ::= 124
*/

constexpr int64_t id_UE_ContextInformationSeNBModReq = 124;
/*
id-UE-ContextKeptIndicator													ProtocolIE-ID ::= 154
*/

constexpr int64_t id_UE_ContextKeptIndicator = 154;
/*
id-UE-ContextReferenceAtSeNB												ProtocolIE-ID ::= 153
*/

constexpr int64_t id_UE_ContextReferenceAtSeNB = 153;
/*
id-UE-ContextReferenceAtSgNB													ProtocolIE-ID ::= 254
*/

constexpr int64_t id_UE_ContextReferenceAtSgNB = 254;
/*
id-UE-ContextReferenceAtWT													ProtocolIE-ID ::= 182
*/

constexpr int64_t id_UE_ContextReferenceAtWT = 182;
/*
id-UE-HistoryInformation													ProtocolIE-ID ::= 15
*/

constexpr int64_t id_UE_HistoryInformation = 15;
/*
id-UE-HistoryInformationFromTheUE											ProtocolIE-ID ::= 105
*/

constexpr int64_t id_UE_HistoryInformationFromTheUE = 105;
/*
id-UE-RLF-Report-Container													ProtocolIE-ID ::= 60
*/

constexpr int64_t id_UE_RLF_Report_Container = 60;
/*
id-UE-RLF-Report-Container-for-extended-bands								ProtocolIE-ID ::= 107
*/

constexpr int64_t id_UE_RLF_Report_Container_for_extended_bands = 107;
/*
id-UE-SecurityCapabilities													ProtocolIE-ID ::= 113
*/

constexpr int64_t id_UE_SecurityCapabilities = 113;
/*
id-UE-X2AP-ID																ProtocolIE-ID ::= 16
*/

constexpr int64_t id_UE_X2AP_ID = 16;
/*
id-UEAppLayerMeasConfig														ProtocolIE-ID ::= 195
*/

constexpr int64_t id_UEAppLayerMeasConfig = 195;
/*
id-UEContextLevelUserPlaneActivity											ProtocolIE-ID ::= 296
*/

constexpr int64_t id_UEContextLevelUserPlaneActivity = 296;
/*
id-UEID																		ProtocolIE-ID ::= 147
*/

constexpr int64_t id_UEID = 147;
/*
id-UENRMeasurement															ProtocolIE-ID ::= 243
*/

constexpr int64_t id_UENRMeasurement = 243;
/*
id-UESidelinkAggregateMaximumBitRate										ProtocolIE-ID ::= 184
*/

constexpr int64_t id_UESidelinkAggregateMaximumBitRate = 184;
/*
id-UEs-Admitted-ToBeReset													ProtocolIE-ID ::= 271
*/

constexpr int64_t id_UEs_Admitted_ToBeReset = 271;
/*
id-UEs-ToBeReset															ProtocolIE-ID ::= 270
*/

constexpr int64_t id_UEs_ToBeReset = 270;
/*
id-UL-EARFCNExtension														ProtocolIE-ID ::= 95
*/

constexpr int64_t id_UL_EARFCNExtension = 95;
/*
id-UL-scheduling-PDCCH-CCE-usage											ProtocolIE-ID ::= 194
*/

constexpr int64_t id_UL_scheduling_PDCCH_CCE_usage = 194;
/*
id-ULCOUNTValueExtended														ProtocolIE-ID ::= 92
*/

constexpr int64_t id_ULCOUNTValueExtended = 92;
/*
id-ULCOUNTValuePDCP-SNlength18												ProtocolIE-ID ::= 151
*/

constexpr int64_t id_ULCOUNTValuePDCP_SNlength18 = 151;
/*
id-UplinkPacketLossRate														ProtocolIE-ID ::= 274
*/

constexpr int64_t id_UplinkPacketLossRate = 274;
/*
id-V2XServicesAuthorized													ProtocolIE-ID ::= 176
*/

constexpr int64_t id_V2XServicesAuthorized = 176;
/*
id-WLANMeasurementConfiguration												ProtocolIE-ID ::= 304
*/

constexpr int64_t id_WLANMeasurementConfiguration = 304;
/*
id-WT-UE-ContextKeptIndicator												ProtocolIE-ID ::= 183
*/

constexpr int64_t id_WT_UE_ContextKeptIndicator = 183;
/*
id-X2RemovalThreshold														ProtocolIE-ID ::= 169
*/

constexpr int64_t id_X2RemovalThreshold = 169;
/*
id-cellActivation												ProcedureCode ::= 15
*/

constexpr int64_t id_cellActivation = 15;
/*
id-dL-Forwarding															ProtocolIE-ID ::= 306
*/

constexpr int64_t id_dL_Forwarding = 306;
/*
id-dLPDCPSnLength															ProtocolIE-ID ::= 311
*/

constexpr int64_t id_dLPDCPSnLength = 311;
/*
id-dataForwardingAddressIndication								ProcedureCode ::= 44
*/

constexpr int64_t id_dataForwardingAddressIndication = 44;
/*
id-duplicationActivation													ProtocolIE-ID ::= 315
*/

constexpr int64_t id_duplicationActivation = 315;
/*
id-eARFCNExtension															ProtocolIE-ID ::= 94
*/

constexpr int64_t id_eARFCNExtension = 94;
/*
id-eNBConfigurationUpdate										ProcedureCode ::= 8
*/

constexpr int64_t id_eNBConfigurationUpdate = 8;
/*
id-eUTRANRCellResourceCoordination								ProcedureCode ::= 41
*/

constexpr int64_t id_eUTRANRCellResourceCoordination = 41;
/*
id-endcCellActivation											ProcedureCode ::= 39
*/

constexpr int64_t id_endcCellActivation = 39;
/*
id-endcConfigurationUpdate										ProcedureCode ::= 37
*/

constexpr int64_t id_endcConfigurationUpdate = 37;
/*
id-endcPartialReset												ProcedureCode ::= 40
*/

constexpr int64_t id_endcPartialReset = 40;
/*
id-endcX2Removal												ProcedureCode ::= 43
*/

constexpr int64_t id_endcX2Removal = 43;
/*
id-endcX2Setup													ProcedureCode ::= 36
*/

constexpr int64_t id_endcX2Setup = 36;
/*
id-enhancedRNTP																ProtocolIE-ID ::= 148
*/

constexpr int64_t id_enhancedRNTP = 148;
/*
id-errorIndication												ProcedureCode ::= 3
*/

constexpr int64_t id_errorIndication = 3;
/*
id-extended-e-RAB-GuaranteedBitrateDL										ProtocolIE-ID ::= 198
*/

constexpr int64_t id_extended_e_RAB_GuaranteedBitrateDL = 198;
/*
id-extended-e-RAB-GuaranteedBitrateUL										ProtocolIE-ID ::= 199
*/

constexpr int64_t id_extended_e_RAB_GuaranteedBitrateUL = 199;
/*
id-extended-e-RAB-MaximumBitrateDL											ProtocolIE-ID ::= 196
*/

constexpr int64_t id_extended_e_RAB_MaximumBitrateDL = 196;
/*
id-extended-e-RAB-MaximumBitrateUL											ProtocolIE-ID ::= 197
*/

constexpr int64_t id_extended_e_RAB_MaximumBitrateUL = 197;
/*
id-extended-uEaggregateMaximumBitRateDownlink								ProtocolIE-ID ::= 200
*/

constexpr int64_t id_extended_uEaggregateMaximumBitRateDownlink = 200;
/*
id-extended-uEaggregateMaximumBitRateUplink									ProtocolIE-ID ::= 201
*/

constexpr int64_t id_extended_uEaggregateMaximumBitRateUplink = 201;
/*
id-gNBStatusIndication											ProcedureCode ::= 45
*/

constexpr int64_t id_gNBStatusIndication = 45;
/*
id-handoverCancel												ProcedureCode ::= 1
*/

constexpr int64_t id_handoverCancel = 1;
/*
id-handoverPreparation											ProcedureCode ::= 0
*/

constexpr int64_t id_handoverPreparation = 0;
/*
id-handoverReport												ProcedureCode ::= 14
*/

constexpr int64_t id_handoverReport = 14;
/*
id-lCID																		ProtocolIE-ID ::= 314
*/

constexpr int64_t id_lCID = 314;
/*
id-loadIndication												ProcedureCode ::= 2
*/

constexpr int64_t id_loadIndication = 2;
/*
id-meNBinitiatedSeNBModificationPreparation						ProcedureCode ::= 21
*/

constexpr int64_t id_meNBinitiatedSeNBModificationPreparation = 21;
/*
id-meNBinitiatedSeNBRelease										ProcedureCode ::= 23
*/

constexpr int64_t id_meNBinitiatedSeNBRelease = 23;
/*
id-meNBinitiatedSgNBModificationPreparation						ProcedureCode ::= 29
*/

constexpr int64_t id_meNBinitiatedSgNBModificationPreparation = 29;
/*
id-meNBinitiatedSgNBRelease										ProcedureCode ::= 31
*/

constexpr int64_t id_meNBinitiatedSgNBRelease = 31;
/*
id-mobilitySettingsChange										ProcedureCode ::= 12
*/

constexpr int64_t id_mobilitySettingsChange = 12;
/*
id-new-drb-ID-req															ProtocolIE-ID ::= 325
*/

constexpr int64_t id_new_drb_ID_req = 325;
/*
id-privateMessage												ProcedureCode ::= 11
*/

constexpr int64_t id_privateMessage = 11;
/*
id-rLFIndication												ProcedureCode ::= 13
*/

constexpr int64_t id_rLFIndication = 13;
/*
id-rRCTransfer													ProcedureCode ::= 35
*/

constexpr int64_t id_rRCTransfer = 35;
/*
id-reset														ProcedureCode ::= 7
*/

constexpr int64_t id_reset = 7;
/*
id-resourceStatusReporting										ProcedureCode ::= 10
*/

constexpr int64_t id_resourceStatusReporting = 10;
/*
id-resourceStatusReportingInitiation							ProcedureCode ::= 9
*/

constexpr int64_t id_resourceStatusReportingInitiation = 9;
/*
id-resumeID																	ProtocolIE-ID ::= 172
*/

constexpr int64_t id_resumeID = 172;
/*
id-retrieveUEContext											ProcedureCode ::= 26
*/

constexpr int64_t id_retrieveUEContext = 26;
/*
id-seNBAdditionPreparation										ProcedureCode ::= 19
*/

constexpr int64_t id_seNBAdditionPreparation = 19;
/*
id-seNBCounterCheck												ProcedureCode ::= 25
*/

constexpr int64_t id_seNBCounterCheck = 25;
/*
id-seNBReconfigurationCompletion								ProcedureCode ::= 20
*/

constexpr int64_t id_seNBReconfigurationCompletion = 20;
/*
id-seNBinitiatedSeNBModification								ProcedureCode ::= 22
*/

constexpr int64_t id_seNBinitiatedSeNBModification = 22;
/*
id-seNBinitiatedSeNBRelease										ProcedureCode ::= 24
*/

constexpr int64_t id_seNBinitiatedSeNBRelease = 24;
/*
id-secondaryRATDataUsageReport									ProcedureCode ::= 38
*/

constexpr int64_t id_secondaryRATDataUsageReport = 38;
/*
id-secondarymeNBULGTPTEIDatPDCP												ProtocolIE-ID ::= 313
*/

constexpr int64_t id_secondarymeNBULGTPTEIDatPDCP = 313;
/*
id-secondarysgNBDLGTPTEIDatPDCP												ProtocolIE-ID ::= 312
*/

constexpr int64_t id_secondarysgNBDLGTPTEIDatPDCP = 312;
/*
id-serviceType																ProtocolIE-ID ::= 276
*/

constexpr int64_t id_serviceType = 276;
/*
id-sgNBAdditionPreparation										ProcedureCode ::= 27
*/

constexpr int64_t id_sgNBAdditionPreparation = 27;
/*
id-sgNBChange													ProcedureCode ::= 34
*/

constexpr int64_t id_sgNBChange = 34;
/*
id-sgNBCounterCheck												ProcedureCode ::= 33
*/

constexpr int64_t id_sgNBCounterCheck = 33;
/*
id-sgNBReconfigurationCompletion									ProcedureCode ::= 28
*/

constexpr int64_t id_sgNBReconfigurationCompletion = 28;
/*
id-sgNBinitiatedSgNBModification									ProcedureCode ::= 30
*/

constexpr int64_t id_sgNBinitiatedSgNBModification = 30;
/*
id-sgNBinitiatedSgNBRelease										ProcedureCode ::= 32
*/

constexpr int64_t id_sgNBinitiatedSgNBRelease = 32;
/*
id-snStatusTransfer												ProcedureCode ::= 4
*/

constexpr int64_t id_snStatusTransfer = 4;
/*
id-uEContextRelease												ProcedureCode ::= 5
*/

constexpr int64_t id_uEContextRelease = 5;
/*
id-uL-GTPtunnelEndpoint														ProtocolIE-ID ::= 185
*/

constexpr int64_t id_uL_GTPtunnelEndpoint = 185;
/*
id-uLpDCPSnLength															ProtocolIE-ID ::= 302
*/

constexpr int64_t id_uLpDCPSnLength = 302;
/*
id-x2APMessage																ProtocolIE-ID ::= 102
*/

constexpr int64_t id_x2APMessage = 102;
/*
id-x2APMessageTransfer											ProcedureCode ::= 17
*/

constexpr int64_t id_x2APMessageTransfer = 17;
/*
id-x2Release													ProcedureCode ::= 16
*/

constexpr int64_t id_x2Release = 16;
/*
id-x2Removal													ProcedureCode ::= 18
*/

constexpr int64_t id_x2Removal = 18;
/*
id-x2Setup														ProcedureCode ::= 6
*/

constexpr int64_t id_x2Setup = 6;
/*
maxCSIProcess								INTEGER ::= 4
*/

constexpr int64_t maxCSIProcess = 4;
/*
maxCSIReport								INTEGER ::= 2
*/

constexpr int64_t maxCSIReport = 2;
/*
maxCellReport								INTEGER ::= 9
*/

constexpr int64_t maxCellReport = 9;
/*
maxCellineNB								INTEGER ::= 256
*/

constexpr int64_t maxCellineNB = 256;
/*
maxCellinengNB								INTEGER ::= 16384
*/

constexpr int64_t maxCellinengNB = 16384;
/*
maxEARFCN									INTEGER ::= 65535
*/

constexpr int64_t maxEARFCN = 65535;
/*
maxEARFCNPlusOne							INTEGER ::= 65536
*/

constexpr int64_t maxEARFCNPlusOne = 65536;
/*
maxFailedMeasObjects						INTEGER ::= 32
*/

constexpr int64_t maxFailedMeasObjects = 32;
/*
maxInterfaces								INTEGER ::= 16
*/

constexpr int64_t maxInterfaces = 16;
/*
maxNrOfErrors								INTEGER ::= 256
*/

constexpr int64_t maxNrOfErrors = 256;
/*
maxPools									INTEGER ::= 16
*/

constexpr int64_t maxPools = 16;
/*
maxSubband									INTEGER ::= 14
*/

constexpr int64_t maxSubband = 14;
/*
maxUEReport									INTEGER ::= 128
*/

constexpr int64_t maxUEReport = 128;
/*
maxUEsinengNBDU								INTEGER ::= 8192
*/

constexpr int64_t maxUEsinengNBDU = 8192;
/*
maxnoNRcellsSpectrumSharingWithE-UTRA		INTEGER ::= 64
*/

constexpr int64_t maxnoNRcellsSpectrumSharingWithE_UTRA = 64;
/*
maxnoofBPLMNs								INTEGER ::= 6
*/

constexpr int64_t maxnoofBPLMNs = 6;
/*
maxnoofBands								INTEGER ::= 16
*/

constexpr int64_t maxnoofBands = 16;
/*
maxnoofBearers								INTEGER ::= 256
*/

constexpr int64_t maxnoofBearers = 256;
/*
maxnoofBluetoothName						INTEGER ::= 4
*/

constexpr int64_t maxnoofBluetoothName = 4;
/*
maxnoofCellIDforMDT							INTEGER ::= 32
*/

constexpr int64_t maxnoofCellIDforMDT = 32;
/*
maxnoofCellIDforQMC							INTEGER ::= 32
*/

constexpr int64_t maxnoofCellIDforQMC = 32;
/*
maxnoofCells								INTEGER ::= 16
*/

constexpr int64_t maxnoofCells = 16;
/*
maxnoofCoMPCells							INTEGER ::= 32
*/

constexpr int64_t maxnoofCoMPCells = 32;
/*
maxnoofCoMPHypothesisSet					INTEGER ::= 256
*/

constexpr int64_t maxnoofCoMPHypothesisSet = 256;
/*
maxnoofEPLMNs								INTEGER ::= 15
*/

constexpr int64_t maxnoofEPLMNs = 15;
/*
maxnoofEPLMNsPlusOne						INTEGER ::= 16
*/

constexpr int64_t maxnoofEPLMNsPlusOne = 16;
/*
maxnoofForbLACs								INTEGER ::= 4096
*/

constexpr int64_t maxnoofForbLACs = 4096;
/*
maxnoofForbTACs								INTEGER ::= 4096
*/

constexpr int64_t maxnoofForbTACs = 4096;
/*
maxnoofMBMSServiceAreaIdentities			INTEGER ::= 256
*/

constexpr int64_t maxnoofMBMSServiceAreaIdentities = 256;
/*
maxnoofMBSFN								INTEGER ::= 8
*/

constexpr int64_t maxnoofMBSFN = 8;
/*
maxnoofMDTPLMNs								INTEGER ::= 16
*/

constexpr int64_t maxnoofMDTPLMNs = 16;
/*
maxnoofNeighbours							INTEGER ::= 512
*/

constexpr int64_t maxnoofNeighbours = 512;
/*
maxnoofNrCellBands							INTEGER ::= 32
*/

constexpr int64_t maxnoofNrCellBands = 32;
/*
maxnoofPA									INTEGER ::= 3
*/

constexpr int64_t maxnoofPA = 3;
/*
maxnoofPDCP-SN								INTEGER ::= 16
*/

constexpr int64_t maxnoofPDCP_SN = 16;
/*
maxnoofPLMNforQMC							INTEGER ::= 16
*/

constexpr int64_t maxnoofPLMNforQMC = 16;
/*
maxnoofPRBs									INTEGER ::= 110
*/

constexpr int64_t maxnoofPRBs = 110;
/*
maxnoofProtectedResourcePatterns			INTEGER ::= 16
*/

constexpr int64_t maxnoofProtectedResourcePatterns = 16;
/*
maxnoofTAforMDT								INTEGER ::= 8
*/

constexpr int64_t maxnoofTAforMDT = 8;
/*
maxnoofTAforQMC								INTEGER ::= 8
*/

constexpr int64_t maxnoofTAforQMC = 8;
/*
maxnoofWLANName								INTEGER ::= 4
*/

constexpr int64_t maxnoofWLANName = 4;
/*
maxnooftimeperiods							INTEGER ::= 2
*/

constexpr int64_t maxnooftimeperiods = 2;
/*
maxofNRNeighbours							INTEGER ::= 1024
*/

constexpr int64_t maxofNRNeighbours = 1024;
/*
newmaxEARFCN								INTEGER ::= 262143
*/

constexpr int64_t newmaxEARFCN = 262143;
