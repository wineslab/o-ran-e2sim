/*****************************************************************************
#                                                                            *
# Copyright 2019 AT&T Intellectual Property                                  *
# Copyright 2019 Nokia                                                       *
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
#include "e2sm.h"

#include "ActionParameter-Item.h"
#include "ActionParameter-Value.h"
#include "PLMN-Identity.h"
#include "GlobalENB-ID.h"
#include "GlobalGNB-ID.h"
#include "Interface-ID.h"
#include "ProtocolIE-Field.h"
#include "InterfaceMessageType.h"
#include "InterfaceProtocolIE-Item.h"

static PLMN_Identity_t *createPLMN_ID(const unsigned char *data) {

    PLMN_Identity_t *plmnId = calloc(1, sizeof(PLMN_Identity_t));
    ASN_STRUCT_RESET(asn_DEF_PLMN_Identity, plmnId);
    plmnId->size = 3;
    plmnId->buf = calloc(1, 3);
    memcpy(plmnId->buf, data, 3);

    return plmnId;
}

static GNB_ID_t *createGnb_id(const unsigned char *data, int numOfBits) {

    if (numOfBits < 22 || numOfBits > 32) {
        printf("[Error] GNB_ID_t number of bits = %d, needs to be 22 .. 32", numOfBits);
        return NULL;
    }

    GNB_ID_t *gnb = calloc(1, sizeof(GNB_ID_t));
    ASN_STRUCT_RESET(asn_DEF_GNB_ID, gnb);

    gnb->present = GNB_ID_PR_gNB_ID;
    gnb->choice.gNB_ID.size = numOfBits % 8 == 0 ? (unsigned int)(numOfBits / 8) : (unsigned int)(numOfBits / 8 + 1);
    gnb->choice.gNB_ID.bits_unused = gnb->choice.gNB_ID.size * 8 - numOfBits;
    gnb->choice.gNB_ID.buf = calloc(1, gnb->choice.gNB_ID.size);
    memcpy(gnb->choice.gNB_ID.buf, data, gnb->choice.gNB_ID.size);
    gnb->choice.gNB_ID.buf[gnb->choice.gNB_ID.size - 1] =
            ((unsigned)(gnb->choice.gNB_ID.buf[gnb->choice.gNB_ID.size - 1] >> (unsigned)gnb->choice.gNB_ID.bits_unused)
                  << (unsigned)gnb->choice.gNB_ID.bits_unused);

    return gnb;
}

static GlobalGNB_ID_t *createGlobalGNB_ID(PLMN_Identity_t *plmnIdentity, GNB_ID_t *gnb) {

    GlobalGNB_ID_t *ggnbId = calloc(1, sizeof(GlobalGNB_ID_t));
    ASN_STRUCT_RESET(asn_DEF_GlobalGNB_ID, ggnbId);

    memcpy(&ggnbId->pLMN_Identity, plmnIdentity, sizeof(PLMN_Identity_t));
    memcpy(&ggnbId->gNB_ID, gnb, sizeof(GNB_ID_t));

    return ggnbId;
}

static Interface_ID_t *createInterfaceIDForGnb(GlobalGNB_ID_t *gnb) {

    Interface_ID_t *interfaceId = calloc(1, sizeof(Interface_ID_t));
    ASN_STRUCT_RESET(asn_DEF_Interface_ID, interfaceId);

    interfaceId->present = Interface_ID_PR_global_gNB_ID;
    interfaceId->choice.global_gNB_ID = gnb;

    return interfaceId;
}

static InterfaceMessageType_t *createInterfaceMessageInitiating(long procedureCode) {

    InterfaceMessageType_t *intMsgT = calloc(1, sizeof(InterfaceMessageType_t));
    ASN_STRUCT_RESET(asn_DEF_InterfaceMessageType, intMsgT);

    intMsgT->procedureCode = procedureCode;
    intMsgT->typeOfMessage = TypeOfMessage_initiating_message;

    return intMsgT;
}

E2SM_gNB_X2_eventTriggerDefinition_t* create_eventTriggerDefinition(void)
{
  //PLMN_Identity
  unsigned char plmnidData[3] = {0x33, 0xF4, 0x55};
  PLMN_Identity_t *plmnid = createPLMN_ID(plmnidData);
  // xer_fprint(stdout, &asn_DEF_PLMN_Identity, (void *)plmnid);

  //GNB_ID
  unsigned char gnbData[3] = {0x99, 0xaa, 0xbb};
  GNB_ID_t *gnb = createGnb_id(gnbData, 26);
  // xer_fprint(stdout, &asn_DEF_GNB_ID, (void *)gnb);

  //GlobalGNB_ID
  GlobalGNB_ID_t *globaGnb = createGlobalGNB_ID(plmnid, gnb);
  // xer_fprint(stdout, &asn_DEF_GlobalGNB_ID, (void *)globaGnb);

  //Interface_ID
  Interface_ID_t *gnbInterfaceId = createInterfaceIDForGnb(globaGnb);
  // xer_fprint(stdout, &asn_DEF_Interface_ID, (void *)gnbInterfaceId);

  //InterfaceMessageType
  InterfaceMessageType_t *initiatingInterface = createInterfaceMessageInitiating(35);

  //EventTriggerDefinition
  E2SM_gNB_X2_eventTriggerDefinition_t *eventTrigger = calloc(1, sizeof(E2SM_gNB_X2_eventTriggerDefinition_t));
  ASN_STRUCT_RESET(asn_DEF_E2SM_gNB_X2_eventTriggerDefinition, eventTrigger);

  memcpy(&eventTrigger->interface_ID , gnbInterfaceId, sizeof(Interface_ID_t));

  eventTrigger->interfaceDirection = 0;
  memcpy(&eventTrigger->interfaceMessageType, initiatingInterface, sizeof(InterfaceMessageType_t));

  return eventTrigger;
}

#define E2AP_ASN1C_FIND_PROTOCOLIE_BY_ID(IE_TYPE, ie, container, IE_ID) \
  do {\
    IE_TYPE **ptr; \
    ie = NULL; \
    for (ptr = container->protocolIEs.list.array; \
         ptr < &container->protocolIEs.list.array[container->protocolIEs.list.count]; \
         ptr++) { \
      if((*ptr)->id == IE_ID) { \
        ie = *ptr; \
        break; \
      } \
    } \
  } while(0)


void test_eventTriggerDefinition(void)
{
  E2SM_gNB_X2_eventTriggerDefinition_t *eventTrigger = create_eventTriggerDefinition();

  xer_fprint(stdout, &asn_DEF_E2SM_gNB_X2_eventTriggerDefinition, (void *)eventTrigger);
  printf("\n");

  uint8_t *eventBuff;
  int eventBuff_len;

  eventBuff_len = aper_encode_to_new_buffer(&asn_DEF_E2SM_gNB_X2_eventTriggerDefinition,
                                        0, eventTrigger, (void **)&eventBuff);

  LOG_I("Encoded eventBuff_len = %d", eventBuff_len);

  //-----------------------------------------------------------------------
  E2AP_PDU_t* pdu = e2ap_xml_to_pdu("E2AP_RICsubscriptionRequest.xml");
  e2ap_asn1c_print_pdu(pdu);

  InitiatingMessage_t *initiatingMessage = pdu->choice.initiatingMessage;
  xer_fprint(stdout, &asn_DEF_InitiatingMessage, (void *)initiatingMessage);

  RICsubscriptionRequest_t *request = &initiatingMessage->value.choice.RICsubscriptionRequest;
  xer_fprint(stdout, &asn_DEF_RICsubscriptionRequest, (void *)request);

  LOG_I("num of IEs = %d", request->protocolIEs.list.count);


  RICsubscriptionRequest_IEs_t *ie;

  ie = request->protocolIEs.list.array[2];

  // E2AP_ASN1C_FIND_PROTOCOLIE_BY_ID(RICsubscriptionRequest_IEs_t, ie, request, ProtocolIE_ID_id_RICsubscription);
  // E2AP_ASN1C_FIND_PROTOCOLIE_BY_ID(RICsubscriptionRequest_IEs_t, ie, request, ProtocolIE_ID_id_RICrequestID);

  assert( ie != NULL);

  xer_fprint(stdout, &asn_DEF_RICsubscription, (void *)ie);
  // xer_fprint(stdout, &asn_DEF_RICrequestID, (void *)ie);


}

//
// typedef struct ProtocolIE_Container_119P0 {
// 	A_SEQUENCE_OF(struct RICsubscriptionRequest_IEs) list;
//
// 	/* Context for parsing across buffer boundaries */
// 	asn_struct_ctx_t _asn_ctx;
// } ProtocolIE_Container_119P0_t;
