#include <stdio.h>
#include <unistd.h>
#include <assert.h>

#include "e2sim_sctp.hpp"
#include "e2ap_message_handler.hpp"
#include "encode_kpm.hpp"


extern "C" {
#include "e2sim_defs.h"
#include "E2AP-PDU.h"
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
#include "ProtocolIE-SingleContainer.h"
#include "RANfunctions-List.h"
#include "RICindication.h"
#include "RICsubsequentActionType.h"
#include "RICsubsequentAction.h"  
#include "RICtimeToWait.h"  

}

void buildSubsReq(E2AP_PDU_t *pdu);

void generate_e2apv1_setup_request(E2AP_PDU_t *setup_req_pdu);

void generate_e2apv1_setup_response(E2AP_PDU_t *setup_resp_pdu);

void generate_e2apv1_subscription_request(E2AP_PDU_t *sub_req_pdu);

void generate_e2apv1_subscription_response(E2AP_PDU_t *sub_resp_pdu);

void generate_e2apv1_indication_request(E2AP_PDU_t *ind_req_pdu);
