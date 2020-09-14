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
id-RANfunction-Item								ProtocolIE-ID ::= 60001
*/

constexpr int64_t id_RANfunction_Item = 60001;
/*
id-RANfunctionDefinition 						ProtocolIE-ID ::= 60002
*/

constexpr int64_t id_RANfunctionDefinition = 60002;
/*
id-RANfunctionID   								ProtocolIE-ID ::= 60003
*/

constexpr int64_t id_RANfunctionID = 60003;
/*
id-RANfunctionID-Item   						ProtocolIE-ID ::= 60004
*/

constexpr int64_t id_RANfunctionID_Item = 60004;
/*
id-RANfunctionIEcause-Item						ProtocolIE-ID ::= 60005
*/

constexpr int64_t id_RANfunctionIEcause_Item = 60005;
/*
id-RANfunctionsAccepted	 						ProtocolIE-ID ::= 60006
*/

constexpr int64_t id_RANfunctionsAccepted = 60006;
/*
id-RANfunctionsAdded	 						ProtocolIE-ID ::= 60007
*/

constexpr int64_t id_RANfunctionsAdded = 60007;
/*
id-RANfunctionsDeleted	 						ProtocolIE-ID ::= 60008
*/

constexpr int64_t id_RANfunctionsDeleted = 60008;
/*
id-RANfunctionsModified	 						ProtocolIE-ID ::= 60009
*/

constexpr int64_t id_RANfunctionsModified = 60009;
/*
id-RANfunctionsRejected	 						ProtocolIE-ID ::= 60010
*/

constexpr int64_t id_RANfunctionsRejected = 60010;
/*
id-RICaction-Admitted-Item						ProtocolIE-ID ::= 60013
*/

constexpr int64_t id_RICaction_Admitted_Item = 60013;
/*
id-RICaction-NotAdmitted-Item					ProtocolIE-ID ::= 60015
*/

constexpr int64_t id_RICaction_NotAdmitted_Item = 60015;
/*
id-RICaction-ToBeSetup-Item						ProtocolIE-ID ::= 60011
*/

constexpr int64_t id_RICaction_ToBeSetup_Item = 60011;
/*
id-RICactionDefinition							ProtocolIE-ID ::= 60016
*/

constexpr int64_t id_RICactionDefinition = 60016;
/*
id-RICactionID									ProtocolIE-ID ::= 60017
*/

constexpr int64_t id_RICactionID = 60017;
/*
id-RICactionType					    		ProtocolIE-ID ::= 60018
*/

constexpr int64_t id_RICactionType = 60018;
/*
id-RICactions-Admitted							ProtocolIE-ID ::= 60012
*/

constexpr int64_t id_RICactions_Admitted = 60012;
/*
id-RICactions-NotAdmitted						ProtocolIE-ID ::= 60014
*/

constexpr int64_t id_RICactions_NotAdmitted = 60014;
/*
id-RICcallProcessID								ProtocolIE-ID ::= 60019
*/

constexpr int64_t id_RICcallProcessID = 60019;
/*
id-RICcause 									ProtocolIE-ID ::= 60020
*/

constexpr int64_t id_RICcause = 60020;
/*
id-RICcontrolAckRequest							ProtocolIE-ID ::= 60021
*/

constexpr int64_t id_RICcontrolAckRequest = 60021;
/*
id-RICcontrolHeader								ProtocolIE-ID ::= 60022
*/

constexpr int64_t id_RICcontrolHeader = 60022;
/*
id-RICcontrolMessage							ProtocolIE-ID ::= 60023
*/

constexpr int64_t id_RICcontrolMessage = 60023;
/*
id-RICcontrolStatus								ProtocolIE-ID ::= 60024
*/

constexpr int64_t id_RICcontrolStatus = 60024;
/*
id-RICeventTriggerDefinition  					ProtocolIE-ID ::= 60025
*/

constexpr int64_t id_RICeventTriggerDefinition = 60025;
/*
id-RICindicationHeader							ProtocolIE-ID ::= 60026
*/

constexpr int64_t id_RICindicationHeader = 60026;
/*
id-RICindicationMessage							ProtocolIE-ID ::= 60027
*/

constexpr int64_t id_RICindicationMessage = 60027;
/*
id-RICindicationSN								ProtocolIE-ID ::= 60028
*/

constexpr int64_t id_RICindicationSN = 60028;
/*
id-RICindicationType							ProtocolIE-ID ::= 60029
*/

constexpr int64_t id_RICindicationType = 60029;
/*
id-RICrequestID									ProtocolIE-ID ::= 60030
*/

constexpr int64_t id_RICrequestID = 60030;
/*
id-RICrequestSequenceNumber						ProtocolIE-ID ::= 60032
*/

constexpr int64_t id_RICrequestSequenceNumber = 60032;
/*
id-RICrequestorID								ProtocolIE-ID ::= 60031
*/

constexpr int64_t id_RICrequestorID = 60031;
/*
id-RICsubscription								ProtocolIE-ID ::= 60033
*/

constexpr int64_t id_RICsubscription = 60033;
/*
id-RICsubsequentAction							ProtocolIE-ID ::= 60034
*/

constexpr int64_t id_RICsubsequentAction = 60034;
/*
id-RICsubsequentActionType						ProtocolIE-ID ::= 60035
*/

constexpr int64_t id_RICsubsequentActionType = 60035;
/*
id-RICtimeToWait								ProtocolIE-ID ::= 60036
*/

constexpr int64_t id_RICtimeToWait = 60036;
/*
id-ricControl									ProcedureCode ::= 204
*/

constexpr int64_t id_ricControl = 204;
/*
id-ricIndication								ProcedureCode ::= 205
*/

constexpr int64_t id_ricIndication = 205;
/*
id-ricServiceQuery								ProcedureCode ::= 206
*/

constexpr int64_t id_ricServiceQuery = 206;
/*
id-ricServiceUpdate								ProcedureCode ::= 203
*/

constexpr int64_t id_ricServiceUpdate = 203;
/*
id-ricSubscription								ProcedureCode ::= 201
*/

constexpr int64_t id_ricSubscription = 201;
/*
id-ricSubscriptionDelete						ProcedureCode ::= 202
*/

constexpr int64_t id_ricSubscriptionDelete = 202;
/*
maxofRANfunctionID                              INTEGER ::=256
*/

constexpr int64_t maxofRANfunctionID = 256;
/*
maxofRICactionID								INTEGER ::= 16
*/

constexpr int64_t maxofRICactionID = 16;
