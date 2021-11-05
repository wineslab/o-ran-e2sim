

/*****************************************************************************
#                                                                            *
# Copyright 2020 AT&T Intellectual Property                                  *
# Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved.      *
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

#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>

#include <iterator>
#include <vector>
#include <GlobalE2node-eNB-ID.h>
#include <GlobalE2node-ng-eNB-ID.h>
#include <GlobalE2node-en-gNB-ID.h>


#include "encode_e2apv1.hpp"

extern "C" {


#include "e2ap_asn1c_codec.h"
#include "GlobalE2node-ID.h"
#include "GlobalE2node-gNB-ID.h"
#include "GlobalgNB-ID.h"
#include "OCTET_STRING.h"
#include "asn_application.h"
#include "GNB-ID-Choice.h"
#include "ProtocolIE-Field.h"
#include "E2setupRequest.h"
#include "RICaction-ToBeSetup-Item.h"
#include "RICactions-ToBeSetup-List.h"
#include "RICeventTriggerDefinition.h"
#include "RICsubscriptionRequest.h"
#include "RICsubscriptionResponse.h"
#include "ProtocolIE-SingleContainer.h"
#include "RANfunctions-List.h"
#include "RICindication.h"
#include "RICsubsequentActionType.h"
#include "RICsubsequentAction.h"
#include "RICtimeToWait.h"
}

long encoding::get_function_id_from_subscription(E2AP_PDU_t *e2ap_pdu) {

    RICsubscriptionRequest_t orig_req =
            e2ap_pdu->choice.initiatingMessage->value.choice.RICsubscriptionRequest;

//  RICsubscriptionResponse_IEs_t *ricreqid =
//    (RICsubscriptionResponse_IEs_t*)calloc(1, sizeof(RICsubscriptionResponse_IEs_t));

    int count = orig_req.protocolIEs.list.count;
    int size = orig_req.protocolIEs.list.size;

    auto **ies = (RICsubscriptionRequest_IEs_t **) orig_req.protocolIEs.list.array;

    LOG_D("count%d\n", count)
    LOG_D("size%d\n", size)

    RICsubscriptionRequest_IEs__value_PR pres;

    long func_id;

    for (int i = 0; i < count; i++) {
        RICsubscriptionRequest_IEs_t *next_ie = ies[i];
        pres = next_ie->value.present;

        if (pres == RICsubscriptionRequest_IEs__value_PR_RANfunctionID) {
            func_id = next_ie->value.choice.RANfunctionID;
        }

    }

    LOG_D("After loop, func_id is %ld", func_id);

    return func_id;

}


long encoding::get_function_id_from_control_request(E2AP_PDU_t *pdu) {
    auto *orig_req = (RICcontrolRequest_t *) &pdu->choice.initiatingMessage->value.choice.RICcontrolRequest;
    for (RICcontrolRequest_IEs_t *ie = *orig_req->protocolIEs.list.array;
         ie != nullptr; ie++) {
        if (ie->value.present == RICcontrolRequest_IEs__value_PR_RANfunctionID) {
            return ie->value.choice.RANfunctionID;
        }
    }
    return -1;
}

void encoding::generate_e2apv1_service_update(E2AP_PDU_t *e2ap_pdu, std::vector<encoding::ran_func_info> all_funcs) {
    char *ran_function_op_type = getenv("RAN_FUNCTION_OP_TYPE");
    LOG_D("Ran funciton : %s", ran_function_op_type);
    ProtocolIE_ID_t prID;
    if (ran_function_op_type != NULL) {
        if (strcmp(ran_function_op_type, "ADD") == 0) {
            prID = ProtocolIE_ID_id_RANfunctionsAdded;
        } else if (strcmp(ran_function_op_type, "DELETE")) {
            prID = ProtocolIE_ID_id_RANfunctionsDeleted;
        }
    } else {
        prID = ProtocolIE_ID_id_RANfunctionsModified;
    }


    RICserviceUpdate_IEs_t *e2serviceUpdateList = (RICserviceUpdate_IEs_t *) calloc(1, sizeof(RICserviceUpdate_IEs_t));
    e2serviceUpdateList->id = prID;
    e2serviceUpdateList->criticality = Criticality_reject;
    e2serviceUpdateList->value.present = RICserviceUpdate_IEs__value_PR_RANfunctions_List;


    for (int i = 0; i < all_funcs.size(); i++) {

        encoding::ran_func_info nextRanFunc = all_funcs.at(i);
        long nextRanFuncId = nextRanFunc.ranFunctionId;
        OCTET_STRING_t *nextRanFuncDesc = nextRanFunc.ranFunctionDesc;
        long nextRanFuncRev = nextRanFunc.ranFunctionRev;

        auto *itemIes = (RANfunction_ItemIEs_t *) calloc(1, sizeof(RANfunction_ItemIEs_t));
        itemIes->id = ProtocolIE_ID_id_RANfunction_Item;
        itemIes->criticality = Criticality_reject;
        itemIes->value.present = RANfunction_ItemIEs__value_PR_RANfunction_Item;
        itemIes->value.choice.RANfunction_Item.ranFunctionID = 1;

        itemIes->value.choice.RANfunction_Item.ranFunctionDefinition = *nextRanFuncDesc;
        itemIes->value.choice.RANfunction_Item.ranFunctionRevision = nextRanFuncRev + 1;

        ASN_SEQUENCE_ADD(&e2serviceUpdateList->value.choice.RANfunctions_List.list, itemIes);
    }

    RICserviceUpdate_t *ricServiceUpdate = (RICserviceUpdate_t *) calloc(1, sizeof(RICserviceUpdate_t));
    ASN_SEQUENCE_ADD(&ricServiceUpdate->protocolIEs.list, e2serviceUpdateList);

    InitiatingMessage_t *initiatingMessage = (InitiatingMessage_t *) calloc(1, sizeof(InitiatingMessage_t));
    initiatingMessage->criticality = Criticality_reject;
    initiatingMessage->procedureCode = ProcedureCode_id_RICserviceUpdate;
    initiatingMessage->value.present = InitiatingMessage__value_PR_RICserviceUpdate;
    initiatingMessage->value.choice.RICserviceUpdate = *ricServiceUpdate;

    E2AP_PDU_PR pres6 = E2AP_PDU_PR_initiatingMessage;
    e2ap_pdu->present = pres6;
    e2ap_pdu->choice.initiatingMessage = initiatingMessage;
}

void encoding::generate_e2apv1_setup_request_parameterized(E2AP_PDU_t *e2ap_pdu, std::vector<ran_func_info> all_funcs,
                                                           uint8_t * gnb_id, uint8_t * plmn_id) {
    // CGI encoding
    int size_gnb_id = 4; // 3GPP Specs
    BIT_STRING_t *gnb_bstring = (BIT_STRING_t *) calloc(1, sizeof(BIT_STRING_t));;
    gnb_bstring->buf = (uint8_t *) calloc(1, size_gnb_id);
    memcpy(gnb_bstring->buf, gnb_id, size_gnb_id);
    gnb_bstring->size = size_gnb_id;
    gnb_bstring->bits_unused = 8 - size_gnb_id;

    // PLMNID is the same for every CGI
    int size_plmnid = 3;
    OCTET_STRING_t *plmnid = (OCTET_STRING_t *) calloc(1, sizeof(OCTET_STRING_t));
    plmnid->buf = (uint8_t *) calloc(1, size_plmnid);
    memcpy(plmnid->buf, plmn_id, size_plmnid);
    plmnid->size = size_plmnid;

    GNB_ID_Choice_t *gnbchoice = (GNB_ID_Choice_t *) calloc(1, sizeof(GNB_ID_Choice_t));
    gnbchoice->present = GNB_ID_Choice_PR_gnb_ID;
    gnbchoice->choice.gnb_ID = *gnb_bstring;
//    free(gnb_bstring);

    GlobalgNB_ID_t *gnb = (GlobalgNB_ID_t *) calloc(1, sizeof(GlobalgNB_ID_t));
    gnb->plmn_id = *plmnid;
    gnb->gnb_id = *gnbchoice;

    GlobalE2node_gNB_ID_t *e2gnb = (GlobalE2node_gNB_ID_t *) calloc(1, sizeof(GlobalE2node_gNB_ID_t));
    e2gnb->global_gNB_ID = *gnb;

    GlobalE2node_ID_t *globalE2nodeIdBuf = (GlobalE2node_ID_t *) calloc (1, sizeof (GlobalE2node_ID_t));
    globalE2nodeIdBuf->present = GlobalE2node_ID_PR_gNB;
    globalE2nodeIdBuf->choice.gNB = e2gnb;

    E2setupRequestIEs_t *e2setuprid = (E2setupRequestIEs_t *) calloc(1, sizeof(E2setupRequestIEs_t));
    e2setuprid->id = ProtocolIE_ID_id_GlobalE2node_ID;
    e2setuprid->criticality = Criticality_reject;
    e2setuprid->value.choice.GlobalE2node_ID = *globalE2nodeIdBuf;
    e2setuprid->value.present = E2setupRequestIEs__value_PR_GlobalE2node_ID;

    auto *ranFlistIEs = (E2setupRequestIEs_t *) calloc(1, sizeof(E2setupRequestIEs_t));
    ASN_STRUCT_RESET(asn_DEF_E2setupRequestIEs, ranFlistIEs);
    ranFlistIEs->criticality = Criticality_reject;
    ranFlistIEs->id = ProtocolIE_ID_id_RANfunctionsAdded;
    ranFlistIEs->value.present = E2setupRequestIEs__value_PR_RANfunctions_List;


    for (auto nextRanFunc: all_funcs) {
        LOG_I("About to register a function");

        long nextRanFuncId = nextRanFunc.ranFunctionId;
        OCTET_STRING_t *nextRanFuncDesc = nextRanFunc.ranFunctionDesc;
        long nextRanFuncRev = nextRanFunc.ranFunctionRev;

        auto *itemIes = (RANfunction_ItemIEs_t *) calloc(1, sizeof(RANfunction_ItemIEs_t));
        itemIes->id = ProtocolIE_ID_id_RANfunction_Item;
        itemIes->criticality = Criticality_reject;
        itemIes->value.present = RANfunction_ItemIEs__value_PR_RANfunction_Item;
        itemIes->value.choice.RANfunction_Item.ranFunctionID = nextRanFuncId;

        itemIes->value.choice.RANfunction_Item.ranFunctionDefinition = *nextRanFuncDesc;
        itemIes->value.choice.RANfunction_Item.ranFunctionRevision = nextRanFuncRev;

        ASN_SEQUENCE_ADD(&ranFlistIEs->value.choice.RANfunctions_List.list, itemIes);
    }

    auto *e2setupreq = (E2setupRequest_t *) calloc(1, sizeof(E2setupRequest_t));
    ASN_SEQUENCE_ADD(&e2setupreq->protocolIEs.list, e2setuprid);
    ASN_SEQUENCE_ADD(&e2setupreq->protocolIEs.list, ranFlistIEs);

    auto *initmsg = (InitiatingMessage_t *) calloc(1, sizeof(InitiatingMessage_t));

    initmsg->procedureCode = ProcedureCode_id_E2setup;
    initmsg->criticality = Criticality_reject;
    initmsg->value.present = InitiatingMessage__value_PR_E2setupRequest;
    initmsg->value.choice.E2setupRequest = *e2setupreq;

    e2ap_pdu->present = E2AP_PDU_PR_initiatingMessage;
    e2ap_pdu->choice.initiatingMessage = initmsg;
}

// For the moment it has just the mandatory fields, check documentation
void encoding::generate_e2apv1_ric_control_acknowledge(E2AP_PDU_t *control_resp_pdu) {

    auto *req_id_ie = (RICcontrolAcknowledge_IEs *) calloc(1, sizeof(RICcontrolAcknowledge_IEs_t));

    auto *ricRequestId = (RICrequestID_t *) calloc(1, sizeof(RICrequestID_t));
    // TODO fill
    //    ricRequestId->ricRequestorID;
    //    ricRequestId->ricInstanceID;

    req_id_ie->id = ProtocolIE_ID_id_RICrequestID;
    req_id_ie->criticality = Criticality_reject;
    req_id_ie->value.present = RICcontrolAcknowledge_IEs__value_PR_RICrequestID;
    req_id_ie->value.choice.RICrequestID = *ricRequestId;

    auto *ran_func_id_ie = (RICcontrolAcknowledge_IEs *) calloc(1, sizeof(RICcontrolAcknowledge_IEs_t));

    auto *ranFunctionId = (RANfunctionID_t *) calloc(1, sizeof(RANfunctionID_t));
    // TODO fill
//        ranFunctionId

    ran_func_id_ie->id = ProtocolIE_ID_id_RANfunctionID;
    ran_func_id_ie->criticality = Criticality_reject;
    ran_func_id_ie->value.present = RICcontrolAcknowledge_IEs__value_PR_RANfunctionID;
    ran_func_id_ie->value.choice.RANfunctionID = *ranFunctionId;

    auto *ric_control_status_ie = (RICcontrolAcknowledge_IEs *) calloc(1, sizeof(RICcontrolAcknowledge_IEs_t));

    auto *ricControlStatus = (RICcontrolStatus_t *) calloc(1, sizeof(RICcontrolStatus_t));
    // TODO fill
//        ricControlStatus

    ric_control_status_ie->id = ProtocolIE_ID_id_RICcontrolStatus;
    ric_control_status_ie->criticality = Criticality_reject;
    ric_control_status_ie->value.present = RICcontrolAcknowledge_IEs__value_PR_RICcontrolStatus;
    ric_control_status_ie->value.choice.RICcontrolStatus = *ricControlStatus;

    auto *riCcontrolAcknowledge = (RICcontrolAcknowledge_t *) calloc(1, sizeof(RICcontrolAcknowledge_t));
    ASN_SEQUENCE_ADD(&riCcontrolAcknowledge->protocolIEs.list, req_id_ie);
    ASN_SEQUENCE_ADD(&riCcontrolAcknowledge->protocolIEs.list, ran_func_id_ie);
    ASN_SEQUENCE_ADD(&riCcontrolAcknowledge->protocolIEs.list, ric_control_status_ie);

    auto *successOutcome = (SuccessfulOutcome_t *) calloc(1, sizeof(SuccessfulOutcome_t));
    successOutcome->procedureCode = ProcedureCode_id_RICcontrol;
    successOutcome->criticality = Criticality_reject;
    successOutcome->value.present = SuccessfulOutcome__value_PR_RICcontrolAcknowledge;
    successOutcome->value.choice.RICcontrolAcknowledge = *riCcontrolAcknowledge;

    control_resp_pdu->present = E2AP_PDU_PR_successfulOutcome;
    control_resp_pdu->choice.successfulOutcome = successOutcome;
}

void encoding::generate_e2apv1_setup_response(E2AP_PDU_t *e2ap_pdu) {

    auto *resp_ies1 = (E2setupResponseIEs_t *) calloc(1, sizeof(E2setupResponseIEs_t));

    auto *buf = (uint8_t *) "gnb1";

    auto *ricid_bstring = (BIT_STRING_t *) calloc(1, sizeof(BIT_STRING_t));
    ricid_bstring->buf = buf;
    ricid_bstring->size = 4;
    ricid_bstring->bits_unused = 0;

    auto *buf2 = (uint8_t *) "plmn3";
    auto *plmn = (OCTET_STRING_t *) calloc(1, sizeof(OCTET_STRING_t));
    plmn->buf = buf2;
    plmn->size = 5;

    auto *globalricid = (GlobalRIC_ID_t *) calloc(1, sizeof(GlobalRIC_ID_t));
    globalricid->pLMN_Identity = *plmn;
    globalricid->ric_ID = *ricid_bstring;

    resp_ies1->id = ProtocolIE_ID_id_GlobalRIC_ID;
    resp_ies1->criticality = Criticality_reject;
    resp_ies1->value.present = E2setupResponseIEs__value_PR_GlobalRIC_ID;
    resp_ies1->value.choice.GlobalRIC_ID = *globalricid;

    auto *e2setupresp = (E2setupResponse_t *) calloc(1, sizeof(E2setupResponse_t));
    ASN_SEQUENCE_ADD(&e2setupresp->protocolIEs.list, resp_ies1);

    auto *successoutcome = (SuccessfulOutcome_t *) calloc(1, sizeof(SuccessfulOutcome_t));
    successoutcome->procedureCode = ProcedureCode_id_E2setup;
    successoutcome->criticality = Criticality_reject;
    successoutcome->value.present = SuccessfulOutcome__value_PR_E2setupResponse;
    successoutcome->value.choice.E2setupResponse = *e2setupresp;

    e2ap_pdu->present = E2AP_PDU_PR_successfulOutcome;
    e2ap_pdu->choice.successfulOutcome = successoutcome;

}


void encoding::generate_e2apv1_subscription_request(E2AP_PDU *e2ap_pdu) {

    auto *ricreqid = (RICsubscriptionRequest_IEs_t *) calloc(1,  sizeof(RICsubscriptionRequest_IEs_t));
    ASN_STRUCT_RESET(asn_DEF_RICsubscriptionRequest_IEs, ricreqid);

    auto *ricsubrid = (RICsubscriptionRequest_IEs_t *) calloc(1, sizeof(RICsubscriptionRequest_IEs_t));

    ASN_STRUCT_RESET(asn_DEF_RICsubscriptionRequest_IEs, ricsubrid);

    auto *buf2 = (uint8_t *) "SubscriptionTriggers";

    auto *triggerdef = (OCTET_STRING_t *) calloc(1, sizeof(OCTET_STRING_t));
    triggerdef->buf = (uint8_t *) calloc(1, 20);
    triggerdef->size = 20;
    memcpy(triggerdef->buf, buf2, triggerdef->size);

    ProtocolIE_ID_t proto_id = ProtocolIE_ID_id_RICaction_ToBeSetup_Item;

    auto *buf5 = (uint8_t *) "ActionDef";

    auto *actdef = (OCTET_STRING_t *) calloc(1, sizeof(OCTET_STRING_t));
    actdef->buf = (uint8_t *) calloc(1, 9);
    actdef->size = 9;
    memcpy(triggerdef->buf, buf5, 9);

    auto *sa = (RICsubsequentAction_t *) calloc(1, sizeof(RICsubsequentAction_t));
    ASN_STRUCT_RESET(asn_DEF_RICsubsequentAction, sa);

    sa->ricTimeToWait = RICtimeToWait_w500ms;
    sa->ricSubsequentActionType = RICsubsequentActionType_continue;

    auto *action_item_ies = (RICaction_ToBeSetup_ItemIEs_t *) calloc(1,
                                                                                              sizeof(RICaction_ToBeSetup_Item_t));
    action_item_ies->id = proto_id;
    action_item_ies->criticality = 0;

    action_item_ies->value.present = RICaction_ToBeSetup_ItemIEs__value_PR_RICaction_ToBeSetup_Item;
    action_item_ies->value.choice.RICaction_ToBeSetup_Item.ricActionID = 5;
    action_item_ies->value.choice.RICaction_ToBeSetup_Item.ricActionType = RICactionType_report;
    action_item_ies->value.choice.RICaction_ToBeSetup_Item.ricActionDefinition = actdef;
    action_item_ies->value.choice.RICaction_ToBeSetup_Item.ricSubsequentAction = sa;

    ricsubrid->id = ProtocolIE_ID_id_RICsubscriptionDetails;

    ricsubrid->criticality = Criticality_reject;
    ricsubrid->value.present = RICsubscriptionRequest_IEs__value_PR_RICsubscriptionDetails;
    ricsubrid->value.choice.RICsubscriptionDetails.ricEventTriggerDefinition = *triggerdef;

    ASN_SEQUENCE_ADD(&ricsubrid->value.choice.RICsubscriptionDetails.ricAction_ToBeSetup_List.list, action_item_ies);


    ricreqid->id = ProtocolIE_ID_id_RICrequestID;
    ricreqid->criticality = Criticality_reject;
    ricreqid->value.present = RICsubscriptionRequest_IEs__value_PR_RICrequestID;
    ricreqid->value.choice.RICrequestID.ricRequestorID = 22;
    ricreqid->value.choice.RICrequestID.ricInstanceID = 6;

    auto *ricsubreq = (RICsubscriptionRequest_t *) calloc(1, sizeof(RICsubscriptionRequest_t));

    ASN_SEQUENCE_ADD(&ricsubreq->protocolIEs.list, ricreqid);
    ASN_SEQUENCE_ADD(&ricsubreq->protocolIEs.list, ricsubrid);

    auto *initmsg = (InitiatingMessage_t *) calloc(1, sizeof(InitiatingMessage_t));
    initmsg->procedureCode = ProcedureCode_id_RICsubscription;
    initmsg->criticality = Criticality_reject;
    initmsg->value.present = InitiatingMessage__value_PR_RICsubscriptionRequest;
    initmsg->value.choice.RICsubscriptionRequest = *ricsubreq;

    e2ap_pdu->present = E2AP_PDU_PR_initiatingMessage;
    e2ap_pdu->choice.initiatingMessage = initmsg;

    char *error_buf = (char *) calloc(300, sizeof(char));;
    size_t errlen;

    asn_check_constraints(&asn_DEF_E2AP_PDU, e2ap_pdu, error_buf, &errlen);

}

void encoding::generate_e2apv1_subscription_response_success(E2AP_PDU *e2ap_pdu, long reqActionIdsAccepted[],
                                                             long reqActionIdsRejected[], int accept_size,
                                                             int reject_size,
                                                             long reqRequestorId, long reqInstanceId) {

    auto *respricreqid =
            (RICsubscriptionResponse_IEs_t *) calloc(1, sizeof(RICsubscriptionResponse_IEs_t));

    respricreqid->id = ProtocolIE_ID_id_RICrequestID;
    respricreqid->criticality = Criticality_reject;
    respricreqid->value.present = RICsubscriptionResponse_IEs__value_PR_RICrequestID;
    respricreqid->value.choice.RICrequestID.ricRequestorID = reqRequestorId;

    respricreqid->value.choice.RICrequestID.ricInstanceID = reqInstanceId;

    auto *respfuncid =
            (RICsubscriptionResponse_IEs_t *) calloc(1, sizeof(RICsubscriptionResponse_IEs_t));
    respfuncid->id = ProtocolIE_ID_id_RANfunctionID;
    respfuncid->criticality = Criticality_reject;
    respfuncid->value.present = RICsubscriptionResponse_IEs__value_PR_RANfunctionID;
    respfuncid->value.choice.RANfunctionID = (long) 0;


    auto *ricactionadmitted =
            (RICsubscriptionResponse_IEs_t *) calloc(1, sizeof(RICsubscriptionResponse_IEs_t));
    ricactionadmitted->id = ProtocolIE_ID_id_RICactions_Admitted;
    ricactionadmitted->criticality = Criticality_reject;
    ricactionadmitted->value.present = RICsubscriptionResponse_IEs__value_PR_RICaction_Admitted_List;

    auto *admlist =
            (RICaction_Admitted_List_t *) calloc(1, sizeof(RICaction_Admitted_List_t));
    ricactionadmitted->value.choice.RICaction_Admitted_List = *admlist;

    int numAccept = accept_size;
    int numReject = reject_size;

    for (int i = 0; i < numAccept; i++) {
        LOG_D("in for loop i = %d\n", i);

        long aid = reqActionIdsAccepted[i];

        auto *admitie = (RICaction_Admitted_ItemIEs_t *) calloc(1, sizeof(RICaction_Admitted_ItemIEs_t));
        admitie->id = ProtocolIE_ID_id_RICaction_Admitted_Item;
        admitie->criticality = Criticality_reject;
        admitie->value.present = RICaction_Admitted_ItemIEs__value_PR_RICaction_Admitted_Item;
        admitie->value.choice.RICaction_Admitted_Item.ricActionID = aid;

        ASN_SEQUENCE_ADD(&ricactionadmitted->value.choice.RICaction_Admitted_List.list, admitie);
    }

    auto *ricsubresp = (RICsubscriptionResponse_t *) calloc(1, sizeof(RICsubscriptionResponse_t));
    ASN_SEQUENCE_ADD(&ricsubresp->protocolIEs.list, respricreqid);
    ASN_SEQUENCE_ADD(&ricsubresp->protocolIEs.list, respfuncid);
    ASN_SEQUENCE_ADD(&ricsubresp->protocolIEs.list, ricactionadmitted);


    if (numReject > 0) {

        auto *ricactionrejected =
                (RICsubscriptionResponse_IEs_t *) calloc(1, sizeof(RICsubscriptionResponse_IEs_t));
        ricactionrejected->id = ProtocolIE_ID_id_RICactions_NotAdmitted;
        ricactionrejected->criticality = Criticality_reject;
        ricactionrejected->value.present = RICsubscriptionResponse_IEs__value_PR_RICaction_NotAdmitted_List;

        auto *rejectlist =
                (RICaction_NotAdmitted_List_t *) calloc(1, sizeof(RICaction_NotAdmitted_List_t));
        ricactionadmitted->value.choice.RICaction_NotAdmitted_List = *rejectlist;

        for (int i = 0; i < numReject; i++) {
            LOG_D("in for loop i = %d\n", i);

            long aid = reqActionIdsRejected[i];

            auto *noadmitie = (RICaction_NotAdmitted_ItemIEs_t *) calloc(1, sizeof(RICaction_NotAdmitted_ItemIEs_t));
            noadmitie->id = ProtocolIE_ID_id_RICaction_NotAdmitted_Item;
            noadmitie->criticality = Criticality_reject;
            noadmitie->value.present = RICaction_NotAdmitted_ItemIEs__value_PR_RICaction_NotAdmitted_Item;
            noadmitie->value.choice.RICaction_NotAdmitted_Item.ricActionID = aid;

            ASN_SEQUENCE_ADD(&ricactionrejected->value.choice.RICaction_NotAdmitted_List.list, noadmitie);
            ASN_SEQUENCE_ADD(&ricsubresp->protocolIEs.list, ricactionrejected);
        }
    }

    auto *successoutcome = (SuccessfulOutcome_t *) calloc(1, sizeof(SuccessfulOutcome_t));
    successoutcome->procedureCode = ProcedureCode_id_RICsubscription;
    successoutcome->criticality = Criticality_reject;
    successoutcome->value.present = SuccessfulOutcome__value_PR_RICsubscriptionResponse;
    successoutcome->value.choice.RICsubscriptionResponse = *ricsubresp;

    e2ap_pdu->present = E2AP_PDU_PR_successfulOutcome;
    e2ap_pdu->choice.successfulOutcome = successoutcome;

    char *error_buf = (char *) calloc(300, sizeof(char));
    size_t errlen;

    asn_check_constraints(&asn_DEF_E2AP_PDU, e2ap_pdu, error_buf, &errlen);
}

void encoding::generate_e2apv1_subscription_response(E2AP_PDU *e2ap_pdu, E2AP_PDU *sub_req_pdu) {

    //Gather details of the request

    RICsubscriptionRequest_t orig_req =
            sub_req_pdu->choice.initiatingMessage->value.choice.RICsubscriptionRequest;

    int count = orig_req.protocolIEs.list.count;
    int size = orig_req.protocolIEs.list.size;

    auto **ies = (RICsubscriptionRequest_IEs_t **) orig_req.protocolIEs.list.array;

    LOG_D("count%d\n", count);
    LOG_D("size%d\n", size);

    RICsubscriptionRequest_IEs__value_PR pres;

    long responseRequestorId;
    long responseInstanceId;
    long responseActionId;

    std::vector<long> actionIds;

    for (int i = 0; i < count; i++) {
        RICsubscriptionRequest_IEs_t *next_ie = ies[i];

        switch (next_ie->value.present) {
            case RICsubscriptionRequest_IEs__value_PR_RICrequestID: {
                RICrequestID_t reqId = next_ie->value.choice.RICrequestID;
                long requestorId = reqId.ricRequestorID;
                long instanceId = reqId.ricInstanceID;
                LOG_D("RequestorId %ld", requestorId);
                LOG_D("InstanceId %ld", instanceId);
                responseRequestorId = requestorId;
                responseInstanceId = instanceId;
                break;
            }
            case RICsubscriptionRequest_IEs__value_PR_RANfunctionID:
                break;
            case RICsubscriptionRequest_IEs__value_PR_RICsubscriptionDetails: {
                RICsubscriptionDetails_t subDetails = next_ie->value.choice.RICsubscriptionDetails;
                RICeventTriggerDefinition_t triggerDef = subDetails.ricEventTriggerDefinition;
                RICactions_ToBeSetup_List_t actionList = subDetails.ricAction_ToBeSetup_List;

                int actionCount = actionList.list.count;
                LOG_D("Action count%d", actionCount);

                auto **item_array = actionList.list.array;

                for (int j = 0; j < actionCount; j++) {
                    //RICaction_ToBeSetup_Item_t
                    auto *next_item = item_array[j];
                    RICactionID_t actionId = ((RICaction_ToBeSetup_ItemIEs *) next_item)->value.choice.RICaction_ToBeSetup_Item.ricActionID;
                    responseActionId = actionId;
                    actionIds.push_back(responseActionId);
                }

                break;
            }
            case RICsubscriptionRequest_IEs__value_PR_NOTHING:
                LOG_E("Error, RIC subscription Request has value equal to Nothing");
                break;
        }

    }

    auto *respricreqid =
            (RICsubscriptionResponse_IEs_t *) calloc(1, sizeof(RICsubscriptionResponse_IEs_t));

    respricreqid->id = ProtocolIE_ID_id_RICrequestID;
    respricreqid->criticality = Criticality_reject;
    respricreqid->value.present = RICsubscriptionResponse_IEs__value_PR_RICrequestID;
    respricreqid->value.choice.RICrequestID.ricRequestorID = responseRequestorId;

    respricreqid->value.choice.RICrequestID.ricInstanceID = responseInstanceId;


    auto *ricactionadmitted =
            (RICsubscriptionResponse_IEs_t *) calloc(1, sizeof(RICsubscriptionResponse_IEs_t));
    ricactionadmitted->id = ProtocolIE_ID_id_RICactions_Admitted;
    ricactionadmitted->criticality = Criticality_reject;
    ricactionadmitted->value.present = RICsubscriptionResponse_IEs__value_PR_RICaction_Admitted_List;

    auto *admlist =
            (RICaction_Admitted_List_t *) calloc(1, sizeof(RICaction_Admitted_List_t));
    ricactionadmitted->value.choice.RICaction_Admitted_List = *admlist;

    for (int i = 0; i < actionIds.size(); i++) {

        long aid = actionIds.at(i);

        auto *admitie = (RICaction_Admitted_ItemIEs_t *) calloc(1, sizeof(RICaction_Admitted_ItemIEs_t));
        admitie->id = ProtocolIE_ID_id_RICaction_Admitted_Item;
        admitie->criticality = 0;
        admitie->value.present = RICaction_Admitted_ItemIEs__value_PR_RICaction_Admitted_Item;
        admitie->value.choice.RICaction_Admitted_Item.ricActionID = aid;

        ASN_SEQUENCE_ADD(&ricactionadmitted->value.choice.RICaction_Admitted_List.list, admitie);

    }

    auto *ricsubresp = (RICsubscriptionResponse_t *) calloc(1, sizeof(RICsubscriptionResponse_t));

    ASN_SEQUENCE_ADD(&ricsubresp->protocolIEs.list, respricreqid);
    ASN_SEQUENCE_ADD(&ricsubresp->protocolIEs.list, ricactionadmitted);

    auto *successoutcome = (SuccessfulOutcome_t *) calloc(1, sizeof(SuccessfulOutcome_t));
    successoutcome->procedureCode = ProcedureCode_id_RICsubscription;
    successoutcome->criticality = Criticality_reject;
    successoutcome->value.present = SuccessfulOutcome__value_PR_RICsubscriptionResponse;
    successoutcome->value.choice.RICsubscriptionResponse = *ricsubresp;

    e2ap_pdu->present = E2AP_PDU_PR_successfulOutcome;
    e2ap_pdu->choice.successfulOutcome = successoutcome;

    char *error_buf = (char *) calloc(300, sizeof(char));
    size_t errlen;

    asn_check_constraints(&asn_DEF_E2AP_PDU, e2ap_pdu, error_buf, &errlen);
}

void encoding::generate_e2apv1_indication_request_parameterized(E2AP_PDU *e2ap_pdu,
                                                                long requestorId,
                                                                long instanceId,
                                                                long ranFunctionId,
                                                                long actionId,
                                                                long seqNum,
                                                                uint8_t *ind_header_buf,
                                                                int header_length,
                                                                uint8_t *ind_message_buf,
                                                                int message_length) {

    auto *ricind_ies = (RICindication_IEs_t *) calloc(1, sizeof(RICindication_IEs_t));
    auto *ricind_ies2 = (RICindication_IEs_t *) calloc(1, sizeof(RICindication_IEs_t));
    auto *ricind_ies3 = (RICindication_IEs_t *) calloc(1, sizeof(RICindication_IEs_t));
    auto *ricind_ies4 = (RICindication_IEs_t *) calloc(1, sizeof(RICindication_IEs_t));
    auto *ricind_ies5 = (RICindication_IEs_t *) calloc(1, sizeof(RICindication_IEs_t));
    auto *ricind_ies6 = (RICindication_IEs_t *) calloc(1, sizeof(RICindication_IEs_t));
    auto *ricind_ies7 = (RICindication_IEs_t *) calloc(1, sizeof(RICindication_IEs_t));
    auto *ricind_ies8 = (RICindication_IEs_t *) calloc(1, sizeof(RICindication_IEs_t));


    ricind_ies->id = ProtocolIE_ID_id_RICrequestID;
    ricind_ies->criticality = Criticality_reject;
    ricind_ies->value.present = RICindication_IEs__value_PR_RICrequestID;
    ricind_ies->value.choice.RICrequestID.ricRequestorID = requestorId;
    ricind_ies->value.choice.RICrequestID.ricInstanceID = instanceId;

    ricind_ies2->id = ProtocolIE_ID_id_RANfunctionID;
    ricind_ies2->criticality = Criticality_reject;
    ricind_ies2->value.present = RICindication_IEs__value_PR_RANfunctionID;
    ricind_ies2->value.choice.RANfunctionID = ranFunctionId;


    ricind_ies3->id = ProtocolIE_ID_id_RICactionID;
    ricind_ies3->criticality = Criticality_reject;
    ricind_ies3->value.present = RICindication_IEs__value_PR_RICactionID;
    ricind_ies3->value.choice.RICactionID = actionId;

    ricind_ies4->id = ProtocolIE_ID_id_RICindicationSN;
    ricind_ies4->criticality = Criticality_reject;
    ricind_ies4->value.present = RICindication_IEs__value_PR_RICindicationSN;
    ricind_ies4->value.choice.RICindicationSN = seqNum;

    //Indication type is REPORT
    ricind_ies5->id = ProtocolIE_ID_id_RICindicationType;
    ricind_ies5->criticality = Criticality_reject;
    ricind_ies5->value.present = RICindication_IEs__value_PR_RICindicationType;
    ricind_ies5->value.choice.RICindicationType = RICindicationType_report;

    auto *hdr_str = (OCTET_STRING_t *) calloc(1, sizeof(OCTET_STRING_t));

    hdr_str->buf = (uint8_t *) calloc(1, header_length);
    hdr_str->size = header_length;
    memcpy(hdr_str->buf, ind_header_buf, header_length);

    ricind_ies6->value.choice.RICindicationHeader.buf = (uint8_t *) calloc(1, header_length);

    ricind_ies6->id = ProtocolIE_ID_id_RICindicationHeader;
    ricind_ies6->criticality = Criticality_reject;
    ricind_ies6->value.present = RICindication_IEs__value_PR_RICindicationHeader;
    ricind_ies6->value.choice.RICindicationHeader.size = header_length;
    memcpy(ricind_ies6->value.choice.RICindicationHeader.buf, ind_header_buf, header_length);

    ricind_ies7->value.choice.RICindicationMessage.buf = (uint8_t *) calloc(1, 8192);

    ricind_ies7->id = ProtocolIE_ID_id_RICindicationMessage;

    ricind_ies7->criticality = Criticality_reject;
    ricind_ies7->value.present = RICindication_IEs__value_PR_RICindicationMessage;

    ricind_ies7->value.choice.RICindicationMessage.size = message_length;

    memcpy(ricind_ies7->value.choice.RICindicationMessage.buf, ind_message_buf, message_length);

    // TODO : this should be deleted
    uint8_t *cpid_buf = (uint8_t *) "cpid";
    OCTET_STRING_t cpid_str;

    int cpid_buf_len = strlen((char *) cpid_buf);
    ricind_ies8->id = ProtocolIE_ID_id_RICcallProcessID;

    ricind_ies8->criticality = Criticality_reject;
    ricind_ies8->value.present = RICindication_IEs__value_PR_RICcallProcessID;

    ricind_ies8->value.choice.RICcallProcessID.buf = (uint8_t *) calloc(1, cpid_buf_len);
    ricind_ies8->value.choice.RICcallProcessID.size = cpid_buf_len;

    memcpy(ricind_ies8->value.choice.RICcallProcessID.buf, cpid_buf, cpid_buf_len);

    auto *ricindication = (RICindication_t *) calloc(1, sizeof(RICindication_t));

    ASN_SEQUENCE_ADD(&ricindication->protocolIEs.list, ricind_ies);

    ASN_SEQUENCE_ADD(&ricindication->protocolIEs.list, ricind_ies2);

    ASN_SEQUENCE_ADD(&ricindication->protocolIEs.list, ricind_ies3);

    ASN_SEQUENCE_ADD(&ricindication->protocolIEs.list, ricind_ies4);

    ASN_SEQUENCE_ADD(&ricindication->protocolIEs.list, ricind_ies5);

    ASN_SEQUENCE_ADD(&ricindication->protocolIEs.list, ricind_ies6);

    ASN_SEQUENCE_ADD(&ricindication->protocolIEs.list, ricind_ies7);

    ASN_SEQUENCE_ADD(&ricindication->protocolIEs.list, ricind_ies8);


    auto *initmsg = (InitiatingMessage_t *) calloc(1, sizeof(InitiatingMessage_t));
    initmsg->procedureCode = ProcedureCode_id_RICindication;
    initmsg->criticality = Criticality_ignore;
    initmsg->value.present = InitiatingMessage__value_PR_RICindication;
    initmsg->value.choice.RICindication = *ricindication;

    e2ap_pdu->present = E2AP_PDU_PR_initiatingMessage;
    e2ap_pdu->choice.initiatingMessage = initmsg;

    size_t errlen = 10000;
    auto errbuff = (char *) calloc(errlen, sizeof(char));

    int ret = asn_check_constraints(&asn_DEF_E2AP_PDU, e2ap_pdu, errbuff, &errlen);
    if (ret < 0) {
        LOG_E("%s", errbuff);
    } else if (LOG_LEVEL == LOG_LEVEL_DEBUG)
        xer_fprint(stderr, &asn_DEF_E2AP_PDU, e2ap_pdu);
    free(errbuff);
}
