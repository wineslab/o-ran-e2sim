
#include "encode_e2apv1.hpp"

void buildSubsReq(E2AP_PDU_t *pdu) {
  ASN_STRUCT_RESET(asn_DEF_E2AP_PDU, pdu);

  pdu->choice.initiatingMessage = (InitiatingMessage_t *)calloc(1, sizeof(InitiatingMessage_t));
  pdu->present = E2AP_PDU_PR_initiatingMessage;

  auto *initMsg = pdu->choice.initiatingMessage;
  ASN_STRUCT_RESET(asn_DEF_InitiatingMessage, initMsg);
  initMsg->procedureCode = ProcedureCode_id_RICsubscription;
  initMsg->criticality = Criticality_reject;
  initMsg->value.present = InitiatingMessage__value_PR_RICsubscriptionRequest;

  auto *subReq = &(initMsg->value.choice.RICsubscriptionRequest);
  ASN_STRUCT_RESET(asn_DEF_RICsubscriptionRequest, subReq);

  { // RICrequestID
    auto *e = (RICsubscriptionRequest_IEs_t *)calloc(1, sizeof(RICsubscriptionRequest_IEs_t));
    ASN_STRUCT_RESET(asn_DEF_RICsubscriptionRequest_IEs, e);
    e->id = ProtocolIE_ID_id_RICrequestID;
    e->value.present = RICsubscriptionRequest_IEs__value_PR_RICrequestID;
    e->value.choice.RICrequestID.ricRequestorID = 88;
    e->value.choice.RICrequestID.ricInstanceID = 5;
    ASN_SEQUENCE_ADD(&subReq->protocolIEs.list, e);
  }
  { // RANfunctionID
    auto *e = (RICsubscriptionRequest_IEs_t *)calloc(1, sizeof(RICsubscriptionRequest_IEs_t));
    ASN_STRUCT_RESET(asn_DEF_RICsubscriptionRequest_IEs, e);
    e->id = ProtocolIE_ID_id_RANfunctionID;
    e->criticality = Criticality_reject;
    e->value.present = RICsubscriptionRequest_IEs__value_PR_RANfunctionID;
    e->value.choice.RANfunctionID = 8;
    ASN_SEQUENCE_ADD(&subReq->protocolIEs.list, e);
  }
  { // RICrequestID
    auto *e = (RICsubscriptionRequest_IEs_t *)calloc(1, sizeof(RICsubscriptionRequest_IEs_t));
    ASN_STRUCT_RESET(asn_DEF_RICsubscriptionRequest_IEs, e);
    e->id = ProtocolIE_ID_id_RICsubscriptionDetails;
    e->criticality = Criticality_reject;
    e->value.present = RICsubscriptionRequest_IEs__value_PR_RICsubscriptionDetails;

    uint8_t buf[10] = {1,2,3,4,5,6,7,8,9,0} ;
    e->value.choice.RICsubscriptionDetails.ricEventTriggerDefinition.size = 10;
    e->value.choice.RICsubscriptionDetails.ricEventTriggerDefinition.buf = (uint8_t *)calloc(1, 10);
    memcpy(e->value.choice.RICsubscriptionDetails.ricEventTriggerDefinition.buf,
	   buf,
	   e->value.choice.RICsubscriptionDetails.ricEventTriggerDefinition.size);
    { // item 1
      auto ie = (RICaction_ToBeSetup_ItemIEs_t *)calloc(1, sizeof(RICaction_ToBeSetup_ItemIEs_t));
      ASN_STRUCT_RESET(asn_DEF_RICaction_ToBeSetup_ItemIEs, ie);
      ie->id = ProtocolIE_ID_id_RICaction_ToBeSetup_Item;
      ie->criticality = Criticality_ignore;
      ie->value.present = RICaction_ToBeSetup_ItemIEs__value_PR_RICaction_ToBeSetup_Item;
      ie->value.choice.RICaction_ToBeSetup_Item.ricActionID = 22;
      ie->value.choice.RICaction_ToBeSetup_Item.ricActionType = RICactionType_report;

      auto *ad = (RICactionDefinition_t *)calloc(1, sizeof(RICactionDefinition_t));
      ASN_STRUCT_RESET(asn_DEF_RICactionDefinition, ad);
      ad->size = 10;
      uint8_t buf[10] = {1,2,3,4,5,6,7,8,9,0} ;
      ad->buf = (uint8_t *)calloc(1, ad->size);
      memcpy(ad->buf, buf, ad->size);
      ie->value.choice.RICaction_ToBeSetup_Item.ricActionDefinition = ad;

      auto *sa = (RICsubsequentAction_t *) calloc(1, sizeof(RICsubsequentAction_t));
      ASN_STRUCT_RESET(asn_DEF_RICsubsequentAction, sa);

      sa->ricTimeToWait = RICtimeToWait_w500ms;
      sa->ricSubsequentActionType = RICsubsequentActionType_continue;

      ie->value.choice.RICaction_ToBeSetup_Item.ricSubsequentAction = sa;
      ASN_SEQUENCE_ADD(&e->value.choice.RICsubscriptionDetails.ricAction_ToBeSetup_List.list, ie);
    }

    { // item 2
      auto ie = (RICaction_ToBeSetup_ItemIEs_t *)calloc(1, sizeof(RICaction_ToBeSetup_ItemIEs_t));
      ASN_STRUCT_RESET(asn_DEF_RICaction_ToBeSetup_ItemIEs, ie);
      ie->id = ProtocolIE_ID_id_RICaction_ToBeSetup_Item;
      ie->criticality = Criticality_ignore;
      ie->value.present = RICaction_ToBeSetup_ItemIEs__value_PR_RICaction_ToBeSetup_Item;
      ie->value.choice.RICaction_ToBeSetup_Item.ricActionID = 47;
      ie->value.choice.RICaction_ToBeSetup_Item.ricActionType = RICactionType_policy;

      auto *ad = (RICactionDefinition_t *)calloc(1, sizeof(RICactionDefinition_t));
      ASN_STRUCT_RESET(asn_DEF_RICactionDefinition, ad);
      ad->size = 10;
      uint8_t buf[10] = {1,2,3,4,5,6,7,8,9,0} ;
      ad->buf = (uint8_t *)calloc(1, ad->size);
      memcpy(ad->buf, buf, ad->size);
      ie->value.choice.RICaction_ToBeSetup_Item.ricActionDefinition = ad;

      auto *sa = (RICsubsequentAction_t *) calloc(1, sizeof(RICsubsequentAction_t));
      ASN_STRUCT_RESET(asn_DEF_RICsubsequentAction, sa);

      sa->ricTimeToWait = RICtimeToWait_w5s;
      sa->ricSubsequentActionType = RICsubsequentActionType_wait;

      ie->value.choice.RICaction_ToBeSetup_Item.ricSubsequentAction = sa;
      ASN_SEQUENCE_ADD(&e->value.choice.RICsubscriptionDetails.ricAction_ToBeSetup_List.list, ie);
    }

    ASN_SEQUENCE_ADD(&subReq->protocolIEs.list, e);
  }



}

void generate_e2apv1_setup_request(E2AP_PDU_t *e2ap_pdu) {
  
  //  uint8_t *buf = (uint8_t *)"gnb1";

  BIT_STRING_t *gnb_bstring = (BIT_STRING_t*)calloc(1, sizeof(BIT_STRING_t));;
  gnb_bstring->buf = (uint8_t*)calloc(1,4);
  gnb_bstring->size = 4;
  gnb_bstring->buf[0] = 0xB5;
  gnb_bstring->buf[1] = 0xC6;
  gnb_bstring->buf[2] = 0x77;
  gnb_bstring->buf[3] = 0x88;

  gnb_bstring->bits_unused = 0;

  uint8_t *buf2 = (uint8_t *)"plmn3";
  OCTET_STRING_t *plmn = (OCTET_STRING_t*)calloc(1, sizeof(OCTET_STRING_t));
  plmn->buf = (uint8_t*)calloc(1,5);
  memcpy(plmn->buf, buf2, 5);;
  plmn->size = 5;

  GNB_ID_Choice_t *gnbchoice = (GNB_ID_Choice_t*)calloc(1,sizeof(GNB_ID_Choice_t));
  GNB_ID_Choice_PR pres2 = GNB_ID_Choice_PR_gnb_ID;
  gnbchoice->present = pres2;
  gnbchoice->choice.gnb_ID = *gnb_bstring;

  GlobalgNB_ID_t *gnb = (GlobalgNB_ID_t*)calloc(1, sizeof(GlobalgNB_ID_t));
  gnb->plmn_id = *plmn;
  gnb->gnb_id = *gnbchoice;

  GlobalE2node_gNB_ID_t *e2gnb = (GlobalE2node_gNB_ID_t*)calloc(1, sizeof(GlobalE2node_gNB_ID_t));
  e2gnb->global_gNB_ID = *gnb;

  GlobalE2node_ID_t *globale2nodeid = (GlobalE2node_ID_t*)calloc(1, sizeof(GlobalE2node_ID_t));
  GlobalE2node_ID_PR pres;
  pres = GlobalE2node_ID_PR_gNB;
  globale2nodeid->present = pres;
  globale2nodeid->choice.gNB = e2gnb;
  
  E2setupRequestIEs_t *e2setuprid = (E2setupRequestIEs_t*)calloc(1, sizeof(E2setupRequestIEs_t));;
  E2setupRequestIEs__value_PR pres3;
  pres3 = E2setupRequestIEs__value_PR_GlobalE2node_ID;
  e2setuprid->id = 4;
  e2setuprid->criticality = 0;
  e2setuprid->value.choice.GlobalE2node_ID = *globale2nodeid;
  e2setuprid->value.present = pres3;

  /*
  auto *ranFlistIEs = (E2setupRequestIEs_t *)calloc(1, sizeof(E2setupRequestIEs_t));
  ASN_STRUCT_RESET(asn_DEF_E2setupRequestIEs, ranFlistIEs);
  ranFlistIEs->criticality = 0;
  ranFlistIEs->id = ProtocolIE_ID_id_RANfunctionsAdded;
  ranFlistIEs->value.present = E2setupRequestIEs__value_PR_RANfunctions_List;

  auto *itemIes = (RANfunction_ItemIEs_t *)calloc(1, sizeof(RANfunction_ItemIEs_t));
  itemIes->id = ProtocolIE_ID_id_RANfunction_Item;
  itemIes->criticality = Criticality_reject;
  itemIes->value.present = RANfunction_ItemIEs__value_PR_RANfunction_Item;
  itemIes->value.choice.RANfunction_Item.ranFunctionID = 1;

  ASN_SEQUENCE_ADD(&ranFlistIEs->value.choice.RANfunctions_List.list, itemIes);  
  */
  E2setupRequest_t *e2setupreq = (E2setupRequest_t*)calloc(1, sizeof(E2setupRequest_t));
  ASN_SEQUENCE_ADD(&e2setupreq->protocolIEs.list, e2setuprid);
  //  ASN_SEQUENCE_ADD(&e2setupreq->protocolIEs.list, ranFlistIEs);

  InitiatingMessage__value_PR pres4;
  pres4 = InitiatingMessage__value_PR_E2setupRequest;
  InitiatingMessage_t *initmsg = (InitiatingMessage_t*)calloc(1, sizeof(InitiatingMessage_t));
  //  initmsg->procedureCode = 1;
  initmsg->procedureCode = ProcedureCode_id_E2setup;
  initmsg->criticality = Criticality_reject;
  initmsg->value.present = pres4;
  initmsg->value.choice.E2setupRequest = *e2setupreq;

  E2AP_PDU_PR pres5;
  pres5 = E2AP_PDU_PR_initiatingMessage;
  

  e2ap_pdu->present = pres5;
  e2ap_pdu->choice.initiatingMessage = initmsg;
  /*
  fprintf(stderr, "testing PER encoding of e2ap_pdu\n");

  uint8_t e2apbuffer[8192];
  size_t e2apbuffer_size = 8192;

  auto er =
    asn_encode_to_buffer(nullptr,
			 ATS_ALIGNED_BASIC_PER,
			 &asn_DEF_E2AP_PDU,
			 e2ap_pdu, e2apbuffer, e2apbuffer_size);

  fprintf(stderr, "er encded is %d\n", er.encoded);  
  */
}


void generate_e2apv1_setup_response(E2AP_PDU_t *e2ap_pdu) {

  E2setupResponseIEs *resp_ies1 = (E2setupResponseIEs_t*)calloc(1, sizeof(E2setupResponseIEs_t));
  E2setupResponseIEs *resp_ies2 = (E2setupResponseIEs_t*)calloc(1, sizeof(E2setupResponseIEs_t));
  E2setupResponseIEs *resp_ies3 = (E2setupResponseIEs_t*)calloc(1, sizeof(E2setupResponseIEs_t));

  uint8_t *buf = (uint8_t *)"gnb1";

  BIT_STRING_t *ricid_bstring = (BIT_STRING_t*)calloc(1,sizeof(BIT_STRING_t));
  ricid_bstring->buf = buf;
  ricid_bstring->size = 4;
  ricid_bstring->bits_unused = 0;

  uint8_t *buf2 = (uint8_t *)"plmn3";
  OCTET_STRING_t *plmn = (OCTET_STRING_t*)calloc(1,sizeof(OCTET_STRING_t));
  plmn->buf = buf2;
  plmn->size = 5;

  GlobalRIC_ID_t *globalricid = (GlobalRIC_ID_t*)calloc(1,sizeof(GlobalRIC_ID_t));
  globalricid->pLMN_Identity = *plmn;
  globalricid->ric_ID = *ricid_bstring;

  E2setupResponseIEs__value_PR pres1;
  pres1 = E2setupResponseIEs__value_PR_GlobalRIC_ID;
  
  resp_ies1->id = ProtocolIE_ID_id_GlobalRIC_ID;
  resp_ies1->criticality = 0;
  resp_ies1->value.present = pres1;
  resp_ies1->value.choice.GlobalRIC_ID = *globalricid;

  E2setupResponse_t *e2setupresp = (E2setupResponse_t*)calloc(1,sizeof(E2setupResponse_t));
  int ret = ASN_SEQUENCE_ADD(&e2setupresp->protocolIEs.list, resp_ies1);


  SuccessfulOutcome__value_PR pres;
  pres = SuccessfulOutcome__value_PR_E2setupResponse;
  SuccessfulOutcome_t *successoutcome = (SuccessfulOutcome_t*)calloc(1, sizeof(SuccessfulOutcome_t));
  successoutcome->procedureCode = 1;
  successoutcome->criticality = 0;
  successoutcome->value.present = pres;
  successoutcome->value.choice.E2setupResponse = *e2setupresp;

  E2AP_PDU_PR pres5 = E2AP_PDU_PR_successfulOutcome;
  
  e2ap_pdu->present = pres5;
  e2ap_pdu->choice.successfulOutcome = successoutcome;
  
}


void generate_e2apv1_subscription_request(E2AP_PDU *e2ap_pdu) {

  fprintf(stderr, "in sub 1\n");
  RICsubscriptionRequest_IEs_t *ricreqid = (RICsubscriptionRequest_IEs_t*)calloc(1, sizeof(RICsubscriptionRequest_IEs_t));
  fprintf(stderr, "in sub 2\n");  
  ASN_STRUCT_RESET(asn_DEF_RICsubscriptionRequest_IEs, ricreqid);
  fprintf(stderr, "in sub 3\n");  
  auto *ricsubrid = (RICsubscriptionRequest_IEs_t*)calloc(1, sizeof(RICsubscriptionRequest_IEs_t));
  fprintf(stderr, "in sub 4\n");  
  ASN_STRUCT_RESET(asn_DEF_RICsubscriptionRequest_IEs, ricsubrid);
  
  fprintf(stderr, "in generate sub\n");
  uint8_t *buf2 = (uint8_t *)"SubscriptionTriggers";
  fprintf(stderr, "in gen sub 1\n");
  OCTET_STRING_t *triggerdef = (OCTET_STRING_t*)calloc(1, sizeof(OCTET_STRING_t));
  triggerdef->buf = (uint8_t *)calloc(1,20);
  triggerdef->size = 20;  
  memcpy(triggerdef->buf, buf2, triggerdef->size);


  fprintf(stderr, "sub1\n");
  ProtocolIE_ID_t proto_id= ProtocolIE_ID_id_RICaction_ToBeSetup_Item;

  RICaction_ToBeSetup_ItemIEs__value_PR pres6;
  pres6 = RICaction_ToBeSetup_ItemIEs__value_PR_RICaction_ToBeSetup_Item;

  printf("sub2\n");

  uint8_t *buf5 = (uint8_t *)"ActionDef";

  OCTET_STRING_t *actdef = (OCTET_STRING_t*)calloc(1, sizeof(OCTET_STRING_t));
  actdef->buf = (uint8_t *)calloc(1,9);
  actdef->size = 9;  
  memcpy(triggerdef->buf, buf5, 9);

  auto *sa = (RICsubsequentAction_t *) calloc(1, sizeof(RICsubsequentAction_t));
  ASN_STRUCT_RESET(asn_DEF_RICsubsequentAction, sa);
  
  sa->ricTimeToWait = RICtimeToWait_w500ms;
  sa->ricSubsequentActionType = RICsubsequentActionType_continue;
    
  /*
  RICaction_ToBeSetup_Item_t *action_item = (RICaction_ToBeSetup_Item_t*)calloc(1, sizeof(RICaction_ToBeSetup_Item_t));
  action_item->ricActionID = 5;
  action_item->ricActionType = 9;
  action_item->ricActionDefinition = actdef;
  action_item->ricSubsequentAction = sa;
  */
  printf("sub3\n");

  RICaction_ToBeSetup_ItemIEs_t *action_item_ies = (RICaction_ToBeSetup_ItemIEs_t *)calloc(1, sizeof(RICaction_ToBeSetup_Item_t));
  action_item_ies->id = proto_id;
  action_item_ies->criticality = 0;

  action_item_ies->value.present = pres6;
  action_item_ies->value.choice.RICaction_ToBeSetup_Item.ricActionID = 5;
  action_item_ies->value.choice.RICaction_ToBeSetup_Item.ricActionType = RICactionType_report;
  action_item_ies->value.choice.RICaction_ToBeSetup_Item.ricActionDefinition = actdef;
  action_item_ies->value.choice.RICaction_ToBeSetup_Item.ricSubsequentAction = sa;


  printf("sub5\n");
  /*
  RICsubscriptionDetails_t *ricsubdetails = (RICsubscriptionDetails_t*)calloc(1, sizeof(RICsubscriptionDetails_t));
  printf("sub5.5\n");

  ASN_SEQUENCE_ADD(&ricsubdetails->ricAction_ToBeSetup_List.list, action_item_ies);
  ricsubdetails->ricEventTriggerDefinition = *triggerdef;

  printf("sub6\n");
  */
  

  RICsubscriptionRequest_IEs__value_PR pres3;
  printf("sub6.1\n");
  pres3 = RICsubscriptionRequest_IEs__value_PR_RICsubscriptionDetails;
  ricsubrid->id = ProtocolIE_ID_id_RICsubscriptionDetails;
  printf("sub6.2\n");
  
  ricsubrid->criticality = 0;
  ricsubrid->value.present = pres3;
  printf("sub6.3\n");    

  ricsubrid->value.choice.RICsubscriptionDetails.ricEventTriggerDefinition = *triggerdef;
  printf("sub6.4\n");
  
  ASN_SEQUENCE_ADD(&ricsubrid->value.choice.RICsubscriptionDetails.ricAction_ToBeSetup_List.list, action_item_ies);

  printf("sub7\n");


  ricreqid->id = ProtocolIE_ID_id_RICrequestID;
  ricreqid->criticality = 0;
  ricreqid->value.present = RICsubscriptionRequest_IEs__value_PR_RICrequestID;
  ricreqid->value.choice.RICrequestID.ricRequestorID = 22;
  ricreqid->value.choice.RICrequestID.ricInstanceID = 6;

  RICsubscriptionRequest_t *ricsubreq = (RICsubscriptionRequest_t*)calloc(1, sizeof(RICsubscriptionRequest_t));

  ASN_SEQUENCE_ADD(&ricsubreq->protocolIEs.list,ricreqid);
  ASN_SEQUENCE_ADD(&ricsubreq->protocolIEs.list,ricsubrid);



  InitiatingMessage__value_PR pres4;
  pres4 = InitiatingMessage__value_PR_RICsubscriptionRequest;
  InitiatingMessage_t *initmsg = (InitiatingMessage_t*)calloc(1, sizeof(InitiatingMessage_t));
  initmsg->procedureCode = ProcedureCode_id_RICsubscription;
  initmsg->criticality = Criticality_reject;
  initmsg->value.present = pres4;
  initmsg->value.choice.RICsubscriptionRequest = *ricsubreq;

  E2AP_PDU_PR pres5;
  pres5 = E2AP_PDU_PR_initiatingMessage;
  

  e2ap_pdu->present = pres5;
  e2ap_pdu->choice.initiatingMessage = initmsg;

  char *error_buf = (char*)calloc(300, sizeof(char));;
  size_t errlen;
									  
  asn_check_constraints(&asn_DEF_E2AP_PDU, e2ap_pdu, error_buf, &errlen);
  printf("error length %d\n", errlen);
  printf("error buf %s\n", error_buf);

  //  xer_fprint(stderr, &asn_DEF_E2AP_PDU, e2ap_pdu);  

}



void generate_e2apv1_indication_request(E2AP_PDU *e2ap_pdu) {
  fprintf(stderr, "ind1\n");
  RICindication_IEs_t *ricind_ies = (RICindication_IEs_t*)calloc(1, sizeof(RICindication_IEs_t));
  RICindication_IEs_t *ricind_ies2 = (RICindication_IEs_t*)calloc(1, sizeof(RICindication_IEs_t));
  RICindication_IEs_t *ricind_ies3 = (RICindication_IEs_t*)calloc(1, sizeof(RICindication_IEs_t));
  RICindication_IEs_t *ricind_ies4 = (RICindication_IEs_t*)calloc(1, sizeof(RICindication_IEs_t));
  RICindication_IEs_t *ricind_ies5 = (RICindication_IEs_t*)calloc(1, sizeof(RICindication_IEs_t));
  RICindication_IEs_t *ricind_ies6 = (RICindication_IEs_t*)calloc(1, sizeof(RICindication_IEs_t));
  RICindication_IEs_t *ricind_ies7 = (RICindication_IEs_t*)calloc(1, sizeof(RICindication_IEs_t));
  RICindication_IEs_t *ricind_ies8 = (RICindication_IEs_t*)calloc(1, sizeof(RICindication_IEs_t));

  RICindication_IEs__value_PR pres3;

  pres3 = RICindication_IEs__value_PR_RICrequestID;
  ricind_ies->id = ProtocolIE_ID_id_RICrequestID;
  ricind_ies->criticality = 0;
  ricind_ies->value.present = pres3;
  ricind_ies->value.choice.RICrequestID.ricRequestorID = 25;
  ricind_ies->value.choice.RICrequestID.ricInstanceID = 3;

  fprintf(stderr, "ind2\n");  

  pres3 = RICindication_IEs__value_PR_RANfunctionID;
  ricind_ies2->id = ProtocolIE_ID_id_RANfunctionID;
  ricind_ies2->criticality = 0;
  ricind_ies2->value.present = pres3;
  ricind_ies2->value.choice.RANfunctionID = 70;

  
  ricind_ies3->id = ProtocolIE_ID_id_RICactionID;
  ricind_ies3->criticality = 0;
  pres3 =  RICindication_IEs__value_PR_RICactionID;
  ricind_ies3->value.present = pres3;
  ricind_ies3->value.choice.RICactionID = 80;


  pres3 = RICindication_IEs__value_PR_RICindicationSN;
  ricind_ies4->id = ProtocolIE_ID_id_RICindicationSN;
  ricind_ies4->criticality = 0;
  ricind_ies4->value.present = pres3;
  ricind_ies4->value.choice.RICindicationSN = 45;

  pres3 = RICindication_IEs__value_PR_RICindicationType;
  ricind_ies5->id = ProtocolIE_ID_id_RICindicationType;
  ricind_ies5->criticality = 0;
  ricind_ies5->value.present = pres3;
  ricind_ies5->value.choice.RICindicationType = 0;


  uint8_t *buf2 = (uint8_t *)"reportheader";
  OCTET_STRING_t *hdr_str = (OCTET_STRING_t*)calloc(1,sizeof(OCTET_STRING_t));
  hdr_str->buf = (uint8_t*)calloc(1,12);
  hdr_str->size = 12;
  memcpy(hdr_str->buf, buf2, 12);

  fprintf(stderr, "ind3\n");

  ricind_ies6->value.choice.RICindicationHeader.buf = (uint8_t*)calloc(1,12);

  pres3 = RICindication_IEs__value_PR_RICindicationHeader;
  ricind_ies6->id = ProtocolIE_ID_id_RICindicationHeader;
  ricind_ies6->criticality = 0;
  ricind_ies6->value.present = pres3;
  ricind_ies6->value.choice.RICindicationHeader.size = 12;
  memcpy(ricind_ies6->value.choice.RICindicationHeader.buf, buf2, 12);
  
  ricind_ies7->value.choice.RICindicationMessage.buf = (uint8_t*)calloc(1,8192);
  uint8_t *buf9 = (uint8_t *)"reportmsg";
  OCTET_STRING_t *msg_str = (OCTET_STRING_t*)calloc(1,sizeof(OCTET_STRING_t));
  msg_str->buf = (uint8_t*)calloc(1,9);
  msg_str->size = 9;
  memcpy(msg_str->buf, buf9, 9);

  fprintf(stderr, "ind4\n");  


  pres3 = RICindication_IEs__value_PR_RICindicationMessage;
  ricind_ies7->id = ProtocolIE_ID_id_RICindicationMessage;
  fprintf(stderr, "after encoding message 1\n");

  ricind_ies7->criticality = 0;
  ricind_ies7->value.present = pres3;

  fprintf(stderr, "after encoding message 2\n");

  fprintf(stderr, "after encoding message 3\n");      
  ricind_ies7->value.choice.RICindicationMessage.size = 9;

  fprintf(stderr, "after encoding message 4\n");      
  memcpy(ricind_ies7->value.choice.RICindicationMessage.buf, buf9, 9);

  fprintf(stderr, "after encoding message 5\n");      

  uint8_t *buf4 = (uint8_t *)"cpid";
  OCTET_STRING_t cpid_str;
  cpid_str.buf = buf4;
  cpid_str.size = 4;      


  pres3 = RICindication_IEs__value_PR_RICcallProcessID;
  ricind_ies8->id = ProtocolIE_ID_id_RICcallProcessID;

  ricind_ies8->criticality = 0;
  ricind_ies8->value.present = pres3;

  ricind_ies8->value.choice.RICcallProcessID = cpid_str;


  RICindication_t *ricindication = (RICindication_t*)calloc(1, sizeof(RICindication_t));

  
  int ret;
  /*
    ret = ASN_SEQUENCE_ADD(&ricindication->protocolIEs.list, ricind_ies);

    ret = ASN_SEQUENCE_ADD(&ricindication->protocolIEs.list, ricind_ies2);

    ret = ASN_SEQUENCE_ADD(&ricindication->protocolIEs.list, ricind_ies3);  
    ret = ASN_SEQUENCE_ADD(&ricindication->protocolIEs.list, ricind_ies4);
    ret = ASN_SEQUENCE_ADD(&ricindication->protocolIEs.list, ricind_ies5);  

    ret = ASN_SEQUENCE_ADD(&ricindication->protocolIEs.list, ricind_ies6);
  */
    ret = ASN_SEQUENCE_ADD(&ricindication->protocolIEs.list, ricind_ies7);  

  ret = ASN_SEQUENCE_ADD(&ricindication->protocolIEs.list, ricind_ies8);    


  InitiatingMessage__value_PR pres4;
  pres4 = InitiatingMessage__value_PR_RICindication;
  InitiatingMessage_t *initmsg = (InitiatingMessage_t*)calloc(1, sizeof(InitiatingMessage_t));
  initmsg->procedureCode = 5;
  initmsg->criticality = 1;
  initmsg->value.present = pres4;
  initmsg->value.choice.RICindication = *ricindication;

  E2AP_PDU_PR pres5;
  pres5 = E2AP_PDU_PR_initiatingMessage;
  
  e2ap_pdu->present = pres5;
  e2ap_pdu->choice.initiatingMessage = initmsg;

  char *error_buf = (char*)calloc(300, sizeof(char));;
  size_t errlen;  

  asn_check_constraints(&asn_DEF_E2AP_PDU, e2ap_pdu, error_buf, &errlen);
  printf("error length %d\n", errlen);
  printf("error buf %s\n", error_buf);

  //  xer_fprint(stderr, &asn_DEF_E2AP_PDU, e2ap_pdu);
}
