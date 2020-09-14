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

#include "asn_x2ap.hpp"
#include "asn_x2ap_wrapper.hpp"

/*-----------------------------------------------------------------------
                              COMMON ROUTINES
-------------------------------------------------------------------------
*/
x2ap_pdu_t* new_x2ap_pdu(void)
{
    X2APpduWrapper* pduWrapper = new X2APpduWrapper();
    return reinterpret_cast<x2ap_pdu_t*>(pduWrapper);
}

void x2ap_asn_print(x2ap_pdu_t* pdu, char* buf, size_t buf_size)
{
  X2APpduWrapper* pduWrapper = reinterpret_cast<X2APpduWrapper*>(pdu);

  buf[0] = 0;

  strncat(buf, asn::get_printed(pduWrapper->ref_pdu()).c_str(), buf_size - 1);
}

int x2ap_asn_per_encode(x2ap_pdu_t* pdu, unsigned char* buf, size_t buf_size,
                                          char* err_buf, size_t err_buf_size)
{
  X2APpduWrapper* pduWrapper = reinterpret_cast<X2APpduWrapper*>(pdu);

  asn::per::EncoderCtx ctx{ buf, buf_size };

  if (!asn::per::pack(pduWrapper->ref_pdu(), ctx)) {
      err_buf[0] = 0;
      // strncat(err_buf, ctx.refErrorCtx().toString().c_str(), err_buf_size - 1);
      return -1;
  } else {
    return static_cast<int>(ctx.refBuffer().getBytesUsed());
  }

}

int x2ap_asn_per_decode(x2ap_pdu_t* pdu, unsigned char const* buf, size_t buf_size,
                                          char* err_buf, size_t err_buf_size)
{
  X2APpduWrapper* pduWrapper = reinterpret_cast<X2APpduWrapper*>(pdu);

  asn::per::DecoderCtx ctx{ buf,
                            buf_size,
                            pduWrapper->m_allocation_buffer,
                            pduWrapper->m_allocation_buffer_size };

  if (!asn::per::unpack(pduWrapper->ref_pdu(), ctx)) {
      err_buf[0] = 0;
      // strncat(err_buf, ctx.refErrorCtx().toString().c_str(), err_buf_size - 1);
      return -1;
  }

  return 0;

}

int x2ap_get_index(x2ap_pdu_t* pdu)
{
  X2APpduWrapper* pduWrapper = reinterpret_cast<X2APpduWrapper*>(pdu);

  return pduWrapper->ref_pdu().get_index();
}

int x2ap_get_procedureCode(x2ap_pdu_t* pdu)
{
  X2APpduWrapper* pduWrapper = reinterpret_cast<X2APpduWrapper*>(pdu);

  switch(pduWrapper->ref_pdu().get_index())
  {
    case 1:
      return pduWrapper->ref_pdu().get_initiatingMessage()->ref_procedureCode().get();
      break;

    case 2:
      return pduWrapper->ref_pdu().get_successfulOutcome()->ref_procedureCode().get();
      break;

    case 3:
      return pduWrapper->ref_pdu().get_unsuccessfulOutcome()->ref_procedureCode().get();
      break;

    default:
      return -1;
  }

}

/*-----------------------------------------------------------------------
                              MESSAGE GENERATORS
-------------------------------------------------------------------------
*/
//X2Setup
bool x2ap_init_X2SetupRequest(x2ap_pdu_t* pdu)
{
    X2APpduWrapper* pduWrapper = reinterpret_cast<X2APpduWrapper*>(pdu);

    //Initialization
    pduWrapper->ref_pdu().select_initiatingMessage();
    pduWrapper->ref_pdu().select_initiatingMessage().clear();
    pduWrapper->ref_pdu().select_initiatingMessage().ref_procedureCode().select_id_x2Setup();
    pduWrapper->ref_pdu().select_initiatingMessage().ref_criticality().select_id_x2Setup();
    pduWrapper->ref_pdu().select_initiatingMessage().ref_value().select_id_x2Setup();

    return true;
}

bool x2ap_create_X2SetupRequest(x2ap_pdu_t* pdu, eNB_config &cfg)
{
  X2APpduWrapper* pduWrapper = reinterpret_cast<X2APpduWrapper*>(pdu);

  /* Initiaization */
  pduWrapper->ref_pdu().select_initiatingMessage().ref_procedureCode().select_id_x2Setup();
  pduWrapper->ref_pdu().select_initiatingMessage().ref_criticality().select_id_x2Setup();

  X2SetupRequest* container =
    &(pduWrapper->ref_pdu().select_initiatingMessage().ref_value().select_id_x2Setup());

  using IE_value_t = X2SetupRequest::protocolIEs_t::value_type;

  /* X2SetupRequest-IEs : GlobalENB-ID*/
  IE_value_t* val_GlobalENB_ID = new IE_value_t;
  container->ref_protocolIEs().push_back(*val_GlobalENB_ID);

  val_GlobalENB_ID->ref_id().select_id_GlobalENB_ID();
  val_GlobalENB_ID->ref_criticality().select_id_GlobalENB_ID();
  val_GlobalENB_ID->ref_value().select_id_GlobalENB_ID().ref_pLMN_Identity()
                                         .set(3, cfg.pLMN_Identity);

  val_GlobalENB_ID->ref_value().select_id_GlobalENB_ID().ref_eNB_ID()
                  .select_macro_eNB_ID().set_buffer(20, cfg.macro_eNB_ID);

  /* X2SetupRequest-IEs : ServedCells*/
  IE_value_t* val_ServedCells = new IE_value_t;
  container->ref_protocolIEs().push_back(*val_ServedCells);

  val_ServedCells->ref_id().select_id_ServedCells();
  val_ServedCells->ref_criticality().select_id_ServedCells();
  val_ServedCells->ref_value().select_id_ServedCells();

  //Add servedCellInfo
  ServedCells::value_type* elm = new ServedCells::value_type();
  ServedCell_Information* info = &(elm->ref_servedCellInfo());
  {
    //Set ServedCell-Information: pCI, cellId, tAC, broadcastPLMNs, eUTRA-Mode-Info
    info->ref_pCI().set(cfg.pCI);
    info->ref_cellId().ref_pLMN_Identity().set(3, cfg.pLMN_Identity);
    info->ref_cellId().ref_eUTRANcellIdentifier().set_buffer(28, cfg.eUTRANcellIdentifier);
    info->ref_tAC().set(2, cfg.tAC);

    BroadcastPLMNs_Item::value_type* item = new BroadcastPLMNs_Item::value_type();
    item->set(3, cfg.pLMN_Identity);
    info->ref_broadcastPLMNs().push_back(*item);

    info->ref_eUTRA_Mode_Info().select_fDD().ref_uL_EARFCN().set(cfg.uL_EARFCN);
    info->ref_eUTRA_Mode_Info().select_fDD().ref_dL_EARFCN().set(cfg.dL_EARFCN);
    info->ref_eUTRA_Mode_Info().select_fDD().ref_uL_Transmission_Bandwidth()
          .set(static_cast<Transmission_Bandwidth::index_t>(cfg.uL_Bandwidth));
    info->ref_eUTRA_Mode_Info().select_fDD().ref_dL_Transmission_Bandwidth()
          .set(static_cast<Transmission_Bandwidth::index_t>(cfg.dL_Bandwidth));
  }
  val_ServedCells->ref_value().select_id_ServedCells().push_back(*elm);

  return true;
}

bool x2ap_create_X2SetupResponse(x2ap_pdu_t* pdu, eNB_config &cfg)
{
  X2APpduWrapper* pduWrapper = reinterpret_cast<X2APpduWrapper*>(pdu);

  /* Initiaization */
  pduWrapper->ref_pdu().select_successfulOutcome().ref_procedureCode().select_id_x2Setup();
  pduWrapper->ref_pdu().select_successfulOutcome().ref_criticality().select_id_x2Setup();

  X2SetupResponse* container =
    &(pduWrapper->ref_pdu().select_successfulOutcome().ref_value().select_id_x2Setup());

  using IE_value_t = X2SetupResponse::protocolIEs_t::value_type;

  /* X2SetupResponse-IEs : GlobalENB-ID*/
  IE_value_t* val_GlobalENB_ID = new IE_value_t;
  container->ref_protocolIEs().push_back(*val_GlobalENB_ID);

  val_GlobalENB_ID->ref_id().select_id_GlobalENB_ID();
  val_GlobalENB_ID->ref_criticality().select_id_GlobalENB_ID();
  val_GlobalENB_ID->ref_value().select_id_GlobalENB_ID().ref_pLMN_Identity()
                                         .set(3, cfg.pLMN_Identity);

  val_GlobalENB_ID->ref_value().select_id_GlobalENB_ID().ref_eNB_ID()
                  .select_macro_eNB_ID().set_buffer(20, cfg.macro_eNB_ID);

  /* X2SetupResponse-IEs : ServedCells*/
  IE_value_t* val_ServedCells = new IE_value_t;
  container->ref_protocolIEs().push_back(*val_ServedCells);

  val_ServedCells->ref_id().select_id_ServedCells();
  val_ServedCells->ref_criticality().select_id_ServedCells();
  val_ServedCells->ref_value().select_id_ServedCells();

  //Add servedCellInfo
  ServedCells::value_type* elm = new ServedCells::value_type();
  ServedCell_Information* info = &(elm->ref_servedCellInfo());
  {
    //Set ServedCell-Information: pCI, cellId, tAC, broadcastPLMNs, eUTRA-Mode-Info
    info->ref_pCI().set(cfg.pCI);
    info->ref_cellId().ref_pLMN_Identity().set(3, cfg.pLMN_Identity);
    info->ref_cellId().ref_eUTRANcellIdentifier().set_buffer(28, cfg.eUTRANcellIdentifier);
    info->ref_tAC().set(2, cfg.tAC);

    BroadcastPLMNs_Item::value_type* item = new BroadcastPLMNs_Item::value_type();
    item->set(3, cfg.pLMN_Identity);
    info->ref_broadcastPLMNs().push_back(*item);

    info->ref_eUTRA_Mode_Info().select_fDD().ref_uL_EARFCN().set(cfg.uL_EARFCN);
    info->ref_eUTRA_Mode_Info().select_fDD().ref_dL_EARFCN().set(cfg.dL_EARFCN);
    info->ref_eUTRA_Mode_Info().select_fDD().ref_uL_Transmission_Bandwidth()
          .set(static_cast<Transmission_Bandwidth::index_t>(cfg.uL_Bandwidth));
    info->ref_eUTRA_Mode_Info().select_fDD().ref_dL_Transmission_Bandwidth()
          .set(static_cast<Transmission_Bandwidth::index_t>(cfg.dL_Bandwidth));
  }
  val_ServedCells->ref_value().select_id_ServedCells().push_back(*elm);

  return true;
}

bool x2ap_create_X2SetupFailure(x2ap_pdu_t* pdu)
{
  X2APpduWrapper* pduWrapper = reinterpret_cast<X2APpduWrapper*>(pdu);

  /* Initiaization */
  pduWrapper->ref_pdu().select_unsuccessfulOutcome().ref_procedureCode().select_id_x2Setup();
  pduWrapper->ref_pdu().select_unsuccessfulOutcome().ref_criticality().select_id_x2Setup();

  X2SetupFailure* container =
    &(pduWrapper->ref_pdu().select_unsuccessfulOutcome().ref_value().select_id_x2Setup());

  using IE_value_t = X2SetupFailure::protocolIEs_t::value_type;

  /* X2SetupFailure-IEs << id-Cause */
  IE_value_t* val_cause = new IE_value_t;
  container->ref_protocolIEs().push_back(*val_cause);

  val_cause->ref_id().select_id_Cause();
  val_cause->ref_criticality().select_id_Cause();

  /* Cause << radioNetwork */
  val_cause->ref_value().select_id_Cause().select_radioNetwork();

  /* CauseRadioNetwork = ho-target-not-allowed (enum = 8)*/
  val_cause->ref_value().select_id_Cause().select_radioNetwork()
                        .set(static_cast<CauseRadioNetwork::index_t>(8));

  return true;
}

//ENDCX2Setup
bool x2ap_create_ENDCX2SetupRequest(x2ap_pdu_t* pdu, eNB_config &cfg)
{
  X2APpduWrapper* pduWrapper = reinterpret_cast<X2APpduWrapper*>(pdu);

  /* Initiaization */
  pduWrapper->ref_pdu().select_initiatingMessage().ref_procedureCode().select_id_endcX2Setup();
  pduWrapper->ref_pdu().select_initiatingMessage().ref_criticality().select_id_endcX2Setup();

  ENDCX2SetupRequest* container =
    &(pduWrapper->ref_pdu().select_initiatingMessage().ref_value().select_id_endcX2Setup());

  using IE_value_t = ENDCX2SetupRequest::protocolIEs_t::value_type;

  /* ENDCX2SetupRequest-IEs = id-InitiatingNodeType-EndcX2Setup  */
  IE_value_t* ie = new IE_value_t;
  container->ref_protocolIEs().push_back(*ie);
  ie->ref_id().select_id_InitiatingNodeType_EndcX2Setup();
  ie->ref_criticality().select_id_InitiatingNodeType_EndcX2Setup();
  ie->ref_value().select_id_InitiatingNodeType_EndcX2Setup();

  /* InitiatingNodeType-EndcX2Setup = init-eNB {ENB-ENDCX2SetupReqIEs} */
  ie->ref_value().select_id_InitiatingNodeType_EndcX2Setup().select_init_eNB();

  using eNB_val_t = InitiatingNodeType_EndcX2Setup::init_eNB_t::value_type;

  ProtocolIE_Container<ENB_ENDCX2SetupReqIEs>* eNB_node =
    &(ie->ref_value().select_id_InitiatingNodeType_EndcX2Setup().select_init_eNB());

  /* ENB-ENDCX2SetupReqIEs <-- id-GlobalENB-ID */
  eNB_val_t* val_GlobalENB_ID = new eNB_val_t;
  eNB_node->push_back(*val_GlobalENB_ID);

  val_GlobalENB_ID->ref_id().select_id_GlobalENB_ID();
  val_GlobalENB_ID->ref_criticality().select_id_GlobalENB_ID();
  val_GlobalENB_ID->ref_value().select_id_GlobalENB_ID()
                      .ref_pLMN_Identity().set(3, cfg.pLMN_Identity);
  val_GlobalENB_ID->ref_value().select_id_GlobalENB_ID().ref_eNB_ID()
                  .select_macro_eNB_ID().set_buffer(20, cfg.macro_eNB_ID);

  /* ENB-ENDCX2SetupReqIEs <-- id-ServedEUTRAcellsENDCX2ManagementList */
  eNB_val_t* val_EUTRAlist = new eNB_val_t;
  eNB_node->push_back(*val_EUTRAlist);

  val_EUTRAlist->ref_id().select_id_ServedEUTRAcellsENDCX2ManagementList();
  val_EUTRAlist->ref_criticality().select_id_ServedEUTRAcellsENDCX2ManagementList();
  val_EUTRAlist->ref_value().select_id_ServedEUTRAcellsENDCX2ManagementList();

  /* ServedEUTRAcellsENDCX2ManagementList <-- servedEUTRACellInfo */
  ServedEUTRAcellsENDCX2ManagementList::value_type* elm =
                        new ServedEUTRAcellsENDCX2ManagementList::value_type();
  ServedCell_Information* info = &(elm->ref_servedEUTRACellInfo());
  {
    //Set ServedCell-Information: pCI, cellId, tAC, broadcastPLMNs, eUTRA-Mode-Info
    info->ref_pCI().set(cfg.pCI);
    info->ref_cellId().ref_pLMN_Identity().set(3, cfg.pLMN_Identity);
    info->ref_cellId().ref_eUTRANcellIdentifier().set_buffer(28, cfg.eUTRANcellIdentifier);
    info->ref_tAC().set(2, cfg.tAC);

    BroadcastPLMNs_Item::value_type* item = new BroadcastPLMNs_Item::value_type();
    item->set(3, cfg.pLMN_Identity);
    info->ref_broadcastPLMNs().push_back(*item);

    info->ref_eUTRA_Mode_Info().select_fDD().ref_uL_EARFCN().set(cfg.uL_EARFCN);
    info->ref_eUTRA_Mode_Info().select_fDD().ref_dL_EARFCN().set(cfg.dL_EARFCN);
    info->ref_eUTRA_Mode_Info().select_fDD().ref_uL_Transmission_Bandwidth()
          .set(static_cast<Transmission_Bandwidth::index_t>(cfg.uL_Bandwidth));
    info->ref_eUTRA_Mode_Info().select_fDD().ref_dL_Transmission_Bandwidth()
          .set(static_cast<Transmission_Bandwidth::index_t>(cfg.dL_Bandwidth));
  }
  val_EUTRAlist->ref_value().select_id_ServedEUTRAcellsENDCX2ManagementList()
                                                        .push_back(*elm);

  return true;
}

/*-----------------------------------------------------------------------
                              TESTS
-------------------------------------------------------------------------
*/
void test_X2Setup_codec(void)
{
  x2ap_pdu_t* pdu = new_x2ap_pdu();

  eNB_config cfg;
  x2ap_create_X2SetupRequest(pdu, cfg);

  char pdu_str[1024];
  x2ap_asn_print(pdu, pdu_str, sizeof(pdu_str));
  printf("%s\n", pdu_str);

  //Test encode
  unsigned char packed_buf[4096];
  char          err_buf[1024];

  int packed_len = x2ap_asn_per_encode(pdu, packed_buf, sizeof(packed_buf),
                                            err_buf, sizeof(err_buf));
  if(packed_len != -1) {
    printf("Encode successful, packed_len = %d\n", packed_len);
  } else {
    printf("Encode Error: %s\n", err_buf);
  }

  //Test encode error
  x2ap_pdu_t* pdu1 = new_x2ap_pdu();
  x2ap_init_X2SetupRequest(pdu1);

  int packed_len1 = x2ap_asn_per_encode(pdu1, packed_buf, sizeof(packed_buf),
                                            err_buf, sizeof(err_buf));
  if(packed_len1 != -1) {
    printf("Encode successful, packed_len = %d\n", packed_len1);
  } else {
    printf("Encode Error: %s\n", err_buf);
  }

  //Test decode
  x2ap_pdu_t* pdu2 = new_x2ap_pdu();
  int rc = x2ap_asn_per_decode(pdu2, packed_buf, packed_len, err_buf, sizeof(err_buf));
  if(rc == -1) {
    printf("Decode error: %s\n", err_buf);
  } else {
    printf("Decode successful\n");
  }

  x2ap_asn_print(pdu2, pdu_str, sizeof(pdu_str));
  printf("%s\n", pdu_str);

  printf("index = %d\n", x2ap_get_index(pdu2));
  printf("procedureCode = %d\n", x2ap_get_procedureCode(pdu2));


  //Test decode error
  x2ap_pdu_t* pdu3 = new_x2ap_pdu();
  int rc2 = x2ap_asn_per_decode(pdu3, packed_buf, 1, err_buf, sizeof(err_buf));
  if(rc2 == -1) {
    printf("Decode error: %s\n", err_buf);
  } else {
    printf("Decode successful\n");
  }

  //Test X2SetupResponse
  x2ap_pdu_t* pdu_resp = new_x2ap_pdu();
  x2ap_create_X2SetupResponse(pdu_resp, cfg);
  x2ap_asn_print(pdu_resp, pdu_str, sizeof(pdu_str));
  printf("%s\n", pdu_str);

  //Test X2SetupFailure
  x2ap_pdu_t* pdu_failure = new_x2ap_pdu();
  x2ap_create_X2SetupFailure(pdu_failure);
  x2ap_asn_print(pdu_failure, pdu_str, sizeof(pdu_str));
  printf("%s \n", pdu_str);
}
