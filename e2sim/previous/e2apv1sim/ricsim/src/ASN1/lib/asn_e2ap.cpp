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
#include "asn_e2ap.hpp"
#include "asn_e2ap_wrapper.hpp"

/*-----------------------------------------------------------------------
                              COMMON ROUTINES
-------------------------------------------------------------------------
*/
e2ap_pdu_t* new_e2ap_pdu(void)
{
    E2APpduWrapper* pduWrapper = new E2APpduWrapper();
    return reinterpret_cast<e2ap_pdu_t*>(pduWrapper);
}

void e2ap_asn_print(e2ap_pdu_t* pdu, char* buf, size_t buf_size)
{
  E2APpduWrapper* pduWrapper = reinterpret_cast<E2APpduWrapper*>(pdu);

  buf[0] = 0;

  strncat(buf, asn::get_printed(pduWrapper->ref_pdu()).c_str(), buf_size - 1);
}

int e2ap_asn_per_encode(e2ap_pdu_t* pdu, unsigned char* buf, size_t buf_size,
                                          char* err_buf, size_t err_buf_size)
{
  E2APpduWrapper* pduWrapper = reinterpret_cast<E2APpduWrapper*>(pdu);

  asn::per::EncoderCtx ctx{ buf, buf_size };

  if (!asn::per::pack(pduWrapper->ref_pdu(), ctx)) {
      err_buf[0] = 0;
      //strncat(err_buf, ctx.refErrorCtx().toString().c_str(), err_buf_size - 1);
      return -1;
  } else {
    return static_cast<int>(ctx.refBuffer().getBytesUsed());
  }

}

int e2ap_asn_per_decode(e2ap_pdu_t* pdu, unsigned char const* buf, size_t buf_size,
                                          char* err_buf, size_t err_buf_size)
{
  E2APpduWrapper* pduWrapper = reinterpret_cast<E2APpduWrapper*>(pdu);

  asn::per::DecoderCtx ctx{ buf,
                            buf_size,
                            pduWrapper->m_allocation_buffer,
                            pduWrapper->m_allocation_buffer_size };

  if (!asn::per::unpack(pduWrapper->ref_pdu(), ctx)) {
      err_buf[0] = 0;
      //strncat(err_buf, ctx.refErrorCtx().toString().c_str(), err_buf_size - 1);
      return -1;
  }

  return 0;

}

int e2ap_get_index(e2ap_pdu_t* pdu)
{
  E2APpduWrapper* pduWrapper = reinterpret_cast<E2APpduWrapper*>(pdu);

  return pduWrapper->ref_pdu().get_index();
}

int e2ap_get_procedureCode(e2ap_pdu_t* pdu)
{
  E2APpduWrapper* pduWrapper = reinterpret_cast<E2APpduWrapper*>(pdu);

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
bool e2ap_init_X2SetupRequest(e2ap_pdu_t* pdu)
{
  E2APpduWrapper* pduWrapper = reinterpret_cast<E2APpduWrapper*>(pdu);

  //Initialization
  pduWrapper->ref_pdu().select_initiatingMessage();
  pduWrapper->ref_pdu().select_initiatingMessage().clear();
  pduWrapper->ref_pdu().select_initiatingMessage().ref_procedureCode().select_id_x2Setup();
  pduWrapper->ref_pdu().select_initiatingMessage().ref_criticality().select_id_x2Setup();
  pduWrapper->ref_pdu().select_initiatingMessage().ref_value().select_id_x2Setup();

  return true;
}

bool e2ap_create_X2SetupRequest(e2ap_pdu_t* pdu, eNB_config &cfg)
{
  E2APpduWrapper* pduWrapper = reinterpret_cast<E2APpduWrapper*>(pdu);

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

bool e2ap_create_X2SetupResponse(e2ap_pdu_t* pdu, eNB_config &cfg)
{
  E2APpduWrapper* pduWrapper = reinterpret_cast<E2APpduWrapper*>(pdu);

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

bool e2ap_create_X2SetupFailure(e2ap_pdu_t* pdu)
{
  E2APpduWrapper* pduWrapper = reinterpret_cast<E2APpduWrapper*>(pdu);

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
bool e2ap_create_ENDCX2SetupRequest(e2ap_pdu_t* pdu, eNB_config &cfg)
{
  E2APpduWrapper* pduWrapper = reinterpret_cast<E2APpduWrapper*>(pdu);

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

bool e2ap_create_ENDCX2SetupResponse(e2ap_pdu_t* pdu, gNB_config &gnb_cfg)
{
  E2APpduWrapper* pduWrapper = reinterpret_cast<E2APpduWrapper*>(pdu);

  /* Initiaization */
  pduWrapper->ref_pdu().select_successfulOutcome().ref_procedureCode().select_id_endcX2Setup();
  pduWrapper->ref_pdu().select_successfulOutcome().ref_criticality().select_id_endcX2Setup();

  ENDCX2SetupResponse* container =
    &(pduWrapper->ref_pdu().select_successfulOutcome().ref_value().select_id_endcX2Setup());

  using IE_value_t = ENDCX2SetupResponse::protocolIEs_t::value_type;

  /* ENDCX2SetupRequest-IEs = id-RespondingNodeType-EndcX2Setup  */
  IE_value_t* ie = new IE_value_t;
  container->ref_protocolIEs().push_back(*ie);
  ie->ref_id().select_id_RespondingNodeType_EndcX2Setup();
  ie->ref_criticality().select_id_RespondingNodeType_EndcX2Setup();
  ie->ref_value().select_id_RespondingNodeType_EndcX2Setup();

  /* RespondingNodeType-EndcX2Setup = respond-en-gNB {En-gNB-ENDCX2SetupReqAckIEs} */
  ie->ref_value().select_id_RespondingNodeType_EndcX2Setup().select_respond_en_gNB();

  using gNB_val_t = RespondingNodeType_EndcX2Setup::respond_en_gNB_t::value_type;

  ProtocolIE_Container<En_gNB_ENDCX2SetupReqAckIEs>* gNB_node =
    &(ie->ref_value().select_id_RespondingNodeType_EndcX2Setup().select_respond_en_gNB());

  /* En-gNB-ENDCX2SetupReqAckIEs << id-Globalen-gNB-ID */
  gNB_val_t* val_Globalen_gNB_ID = new gNB_val_t;
  gNB_node->push_back(*val_Globalen_gNB_ID);

  val_Globalen_gNB_ID->ref_id().select_id_Globalen_gNB_ID();
  val_Globalen_gNB_ID->ref_criticality().select_id_Globalen_gNB_ID();
  val_Globalen_gNB_ID->ref_value().select_id_Globalen_gNB_ID()
            .ref_pLMN_Identity().set(3, gnb_cfg.pLMN_Identity);
  val_Globalen_gNB_ID->ref_value().select_id_Globalen_gNB_ID().ref_gNB_ID()
    .select_gNB_ID().set_buffer(22, gnb_cfg.gNB_ID);

  /* En-gNB-ENDCX2SetupReqAckIEs << id-ServedNRcellsENDCX2ManagementList */
  gNB_val_t* val_ServedNRCells = new gNB_val_t;
  gNB_node->push_back(*val_ServedNRCells);

  val_ServedNRCells->ref_id().select_id_ServedNRcellsENDCX2ManagementList();
  val_ServedNRCells->ref_criticality().select_id_ServedNRcellsENDCX2ManagementList();
  val_ServedNRCells->ref_value().select_id_ServedNRcellsENDCX2ManagementList();

  /* ServedNRcellsENDCX2ManagementList <-- servedNRCellInfo*/
  ServedNRcellsENDCX2ManagementList::value_type* elm =
                          new ServedNRcellsENDCX2ManagementList::value_type();

  /*
  ServedNRCell-Information ::= SEQUENCE {
  	nrpCI				NRPCI,
  	nrCellID			NRCGI,
  	fiveGS-TAC			FiveGS-TAC	OPTIONAL,
  	configured-TAC		TAC			OPTIONAL,
  	broadcastPLMNs		BroadcastPLMNs-Item,
  	nrModeInfo			CHOICE {
  		fdd		FDD-InfoServedNRCell-Information,
  		tdd		TDD-InfoServedNRCell-Information,
  		...
  	},
  	measurementTimingConfiguration	OCTET STRING,
  	iE-Extensions						ProtocolExtensionContainer { {ServedNRCell-Information-ExtIEs} } OPTIONAL,
  	...
  }
  */
  ServedNRCell_Information* info = &(elm->ref_servedNRCellInfo());
  {
    // nrpCI				NRPCI,
    info->ref_nrpCI().set(gnb_cfg.nrpCI);

    /* nrCellID			NRCGI,

      NRCGI ::= SEQUENCE {
        pLMN-Identity				PLMN-Identity,
        nRcellIdentifier				NRCellIdentifier,
        iE-Extensions				ProtocolExtensionContainer { {NRCGI-ExtIEs} } OPTIONAL,
        ...
      }
    */
    info->ref_nrCellID().ref_pLMN_Identity().set(3, gnb_cfg.pLMN_Identity);
    info->ref_nrCellID().ref_nRcellIdentifier().set_buffer(36, gnb_cfg.nRcellIdentifier);

    /* broadcastPLMNs		BroadcastPLMNs-Item */
    BroadcastPLMNs_Item::value_type* item = new BroadcastPLMNs_Item::value_type();
    item->set(3, gnb_cfg.pLMN_Identity);
    info->ref_broadcastPLMNs().push_back(*item);

    /* nrModeInfo			CHOICE {
  		fdd		FDD-InfoServedNRCell-Information,
  		tdd		TDD-InfoServedNRCell-Information,
  		...
  	},

    FDD-InfoServedNRCell-Information ::= SEQUENCE {
    	ul-NRFreqInfo				NRFreqInfo,
    	dl-NRFreqInfo				NRFreqInfo,
    	ul-NR-TxBW				NR-TxBW,
    	dl-NR-TxBW				NR-TxBW,
    	iE-Extensions			ProtocolExtensionContainer { {FDD-InfoServedNRCell-Information-ExtIEs} }		OPTIONAL,
    	...
    }

    NRFreqInfo ::= SEQUENCE{
    	nRARFCN			INTEGER (0.. 3279165),
    	freqBandListNr	SEQUENCE (SIZE(1..maxnoofNrCellBands)) OF FreqBandNrItem,
    	sULInformation	SULInformation		OPTIONAL,
    	iE-Extensions	ProtocolExtensionContainer { {NRFreqInfo-ExtIEs} } OPTIONAL,

    	...
    }

    */
    info->ref_nrModeInfo().select_fdd().ref_ul_NRFreqInfo().ref_nRARFCN().set(gnb_cfg.uL_nRARFCN);
    info->ref_nrModeInfo().select_fdd().ref_dl_NRFreqInfo().ref_nRARFCN().set(gnb_cfg.dL_nRARFCN);

    /*
    FreqBandNrItem ::= SEQUENCE {
    	freqBandIndicatorNr 			INTEGER (1..1024,...),
    	supportedSULBandList	SEQUENCE (SIZE(0..maxnoofNrCellBands)) OF SupportedSULFreqBandItem,
    	iE-Extensions				ProtocolExtensionContainer { {FreqBandNrItem-ExtIEs} } OPTIONAL,
    	...
    }
    */
    //uplink
    asn::sequenceof<NRFreqInfo::freqBandListNr_t_elm>::value_type* ul_band_item =
                          new asn::sequenceof<NRFreqInfo::freqBandListNr_t_elm>::value_type();
    {
      ul_band_item->ref_freqBandIndicatorNr().set(gnb_cfg.ul_freqBandIndicatorNr);

      /*
      SupportedSULFreqBandItem ::= SEQUENCE {
        freqBandIndicatorNr 			INTEGER (1..1024,...),
        iE-Extensions			ProtocolExtensionContainer { {SupportedSULFreqBandItem-ExtIEs} }		OPTIONAL,
        ...
      }
      */

      asn::sequenceof<FreqBandNrItem::supportedSULBandList_t_elm>::value_type* ul_supported_band_item =
          new asn::sequenceof<FreqBandNrItem::supportedSULBandList_t_elm>::value_type();

      ul_supported_band_item->ref_freqBandIndicatorNr().set(gnb_cfg.ul_freqBandIndicatorNr);

      ul_band_item->ref_supportedSULBandList().push_back(*ul_supported_band_item);
    }
    info->ref_nrModeInfo().select_fdd().ref_ul_NRFreqInfo()
                                    .ref_freqBandListNr().push_back(*ul_band_item);

    //downlink
    asn::sequenceof<NRFreqInfo::freqBandListNr_t_elm>::value_type* dl_band_item =
                          new asn::sequenceof<NRFreqInfo::freqBandListNr_t_elm>::value_type();
    {
      dl_band_item->ref_freqBandIndicatorNr().set(gnb_cfg.dl_freqBandIndicatorNr);

      /*
      SupportedSULFreqBandItem ::= SEQUENCE {
        freqBandIndicatorNr 			INTEGER (1..1024,...),
        iE-Extensions			ProtocolExtensionContainer { {SupportedSULFreqBandItem-ExtIEs} }		OPTIONAL,
        ...
      }
      */

      asn::sequenceof<FreqBandNrItem::supportedSULBandList_t_elm>::value_type* dl_supported_band_item =
          new asn::sequenceof<FreqBandNrItem::supportedSULBandList_t_elm>::value_type();

      dl_supported_band_item->ref_freqBandIndicatorNr().set(gnb_cfg.dl_freqBandIndicatorNr);

      dl_band_item->ref_supportedSULBandList().push_back(*dl_supported_band_item);
    }
    info->ref_nrModeInfo().select_fdd().ref_dl_NRFreqInfo()
                                    .ref_freqBandListNr().push_back(*dl_band_item);

    /*
    NR-TxBW	::= SEQUENCE {
    	nRSCS	NRSCS,
    	nRNRB	NRNRB,
    	iE-Extensions				ProtocolExtensionContainer { {NR-TxBW-ExtIEs} } OPTIONAL,
    	...
    }
    */
    {
      info->ref_nrModeInfo().select_fdd().ref_ul_NR_TxBW().ref_nRNRB()
                          .set( static_cast<NRNRB::index_t>(gnb_cfg.uL_NRNRB) );
      info->ref_nrModeInfo().select_fdd().ref_ul_NR_TxBW().ref_nRSCS()
                          .set( static_cast<NRSCS::index_t>(gnb_cfg.uL_NRSCS) );

      info->ref_nrModeInfo().select_fdd().ref_dl_NR_TxBW().ref_nRNRB()
                          .set( static_cast<NRNRB::index_t>(gnb_cfg.dL_NRNRB) );
      info->ref_nrModeInfo().select_fdd().ref_dl_NR_TxBW().ref_nRSCS()
                          .set( static_cast<NRSCS::index_t>(gnb_cfg.dL_NRSCS) );
    }

    /*
    measurementTimingConfiguration	OCTET STRING,
    */
    info->ref_measurementTimingConfiguration().set(gnb_cfg.measurementTimingConfiguration);
  }
  val_ServedNRCells->ref_value().select_id_ServedNRcellsENDCX2ManagementList().push_back(*elm);



  return true;
}

bool e2ap_create_ENDCX2SetupFailure(e2ap_pdu_t* pdu)
{

  E2APpduWrapper* pduWrapper = reinterpret_cast<E2APpduWrapper*>(pdu);

  /* Initiaization */
  pduWrapper->ref_pdu().select_unsuccessfulOutcome().ref_procedureCode().select_id_endcX2Setup();
  pduWrapper->ref_pdu().select_unsuccessfulOutcome().ref_criticality().select_id_endcX2Setup();

  ENDCX2SetupFailure* container =
        &(pduWrapper->ref_pdu().select_unsuccessfulOutcome().ref_value().select_id_endcX2Setup());

  using IE_value_t = ENDCX2SetupFailure::protocolIEs_t::value_type;

  /* ENDCX2SetupFailure-IEs := id-Cause*/
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

//RICSubscription
bool e2ap_create_RICsubscriptionRequest(e2ap_pdu_t* pdu, RICsubscription_params_t &params)
{
  E2APpduWrapper* pduWrapper = reinterpret_cast<E2APpduWrapper*>(pdu);

  /* Initiaization */
  pduWrapper->ref_pdu().select_initiatingMessage()
                              .ref_procedureCode().select_id_ricSubscription();
  pduWrapper->ref_pdu().select_initiatingMessage()
                                .ref_criticality().select_id_ricSubscription();

  RICsubscriptionRequest* container = &(pduWrapper->ref_pdu()
        .select_initiatingMessage().ref_value().select_id_ricSubscription());

  using IE_value_t = RICsubscriptionRequest::protocolIEs_t::value_type;

  /* RICsubscriptionRequest-IEs :  RICrequestID */
  IE_value_t* ie_RICrequestID = new IE_value_t;
  container->ref_protocolIEs().push_back(*ie_RICrequestID);

  ie_RICrequestID->ref_id().select_id_RICrequestID();
  ie_RICrequestID->ref_criticality().select_id_RICrequestID();
  ie_RICrequestID->ref_value().select_id_RICrequestID()
                                .ref_ricRequestorID().set(params.request_id);
  ie_RICrequestID->ref_value().select_id_RICrequestID()
                      .ref_ricRequestSequenceNumber().set(params.seq_number);

  /* RICsubscriptionRequest-IEs :  RANfunctionID */
  IE_value_t* ie_RANfunctionID = new IE_value_t;
  container->ref_protocolIEs().push_back(*ie_RANfunctionID);

  ie_RANfunctionID->ref_id().select_id_RANfunctionID();
  ie_RANfunctionID->ref_criticality().select_id_RANfunctionID();
  ie_RANfunctionID->ref_value().select_id_RANfunctionID().set(params.ran_func_id);


  /*
  RICsubscription ::= SEQUENCE {
  	ricEventTriggerDefinition	RICeventTriggerDefinition,
  	ricAction-ToBeSetup-List	RICactions-ToBeSetup-List,
  	...
  }

  RICeventTriggerDefinition ::= OCTET STRING
  RICactions-ToBeSetup-List ::= SEQUENCE (SIZE(1..maxofRICactionID)) OF ProtocolIE-Single-Container { {RICaction-ToBeSetup-ItemIEs} }

  RICaction-ToBeSetup-ItemIEs 	X2AP-PROTOCOL-IES ::= {
  	{ ID id-RICaction-ToBeSetup-Item	 CRITICALITY ignore 	TYPE RICaction-ToBeSetup-Item 	PRESENCE mandatory },
  	...
  }

  RICaction-ToBeSetup-Item ::= SEQUENCE {
  	ricActionID					RICactionID,
  	ricActionType		  		RICactionType,
  	ricActionDefinition			RICactionDefinition 	OPTIONAL,
  	ricSubsequentAction			RICsubsequentAction 	OPTIONAL,
  	...
  }

  RICactionID ::= INTEGER (0..255)

  RICactionType ::= ENUMERATED{
  	report,
  	insert,
  	policy,
  	...
  }
  */

  /* RICsubscriptionRequest-IEs :  RICsubscription */
  IE_value_t* ie_RICsubscription = new IE_value_t;
  container->ref_protocolIEs().push_back(*ie_RICsubscription);

  ie_RICsubscription->ref_id().select_id_RICsubscription();
  ie_RICsubscription->ref_criticality().select_id_RICsubscription();

  // RICeventTriggerDefinition
  ie_RICsubscription->ref_value().select_id_RICsubscription()
    .ref_ricEventTriggerDefinition().set<std::string>(params.event_trigger_def);

  //RICactions-ToBeSetup-List
  for( auto const  &action : params.actionList)
  {
    RICactions_ToBeSetup_List::value_type* item =
                                  new RICactions_ToBeSetup_List::value_type();

    ie_RICsubscription->ref_value().select_id_RICsubscription()
                            .ref_ricAction_ToBeSetup_List().push_back(*item);

    item->ref_id().select_id_RICaction_ToBeSetup_Item();
    item->ref_criticality().select_id_RICaction_ToBeSetup_Item();
    item->ref_value().select_id_RICaction_ToBeSetup_Item()
                                    .ref_ricActionID().set(action.action_id);
    item->ref_value().select_id_RICaction_ToBeSetup_Item()
                                .ref_ricActionType().set(action.action_type);

  }

  return true;
}

bool e2ap_parse_RICsubscriptionRequest(e2ap_pdu_t* pdu, RICsubscription_params_t &params)
{
  E2APpduWrapper* pduWrapper = reinterpret_cast<E2APpduWrapper*>(pdu);

  RICsubscriptionRequest* container = &(pduWrapper->ref_pdu()
        .select_initiatingMessage().ref_value().select_id_ricSubscription());


  for(auto &e : container->ref_protocolIEs())
  {
    /*See struct RICsubscriptionRequest_IEs*/
    size_t type = e.ref_value().get_index();

    switch(type)
    {
      case 1: //RICrequestID
        {
          params.request_id = e.ref_value().select_id_RICrequestID().ref_ricRequestorID().get();
          params.seq_number = e.ref_value().select_id_RICrequestID().ref_ricRequestSequenceNumber().get();
        }
        break;

      case 2: //RANfunctionID
        params.ran_func_id = e.ref_value().select_id_RANfunctionID().get();
        break;

      case 3: //RICsubscription
        {
          auto event = e.ref_value().select_id_RICsubscription().ref_ricEventTriggerDefinition().get();
          (params.event_trigger_def).assign(std::string(event.data(), event.data() + event.size()));

          //ricAction_ToBeSetup_List
          for (auto  & f : e.ref_value().select_id_RICsubscription().ref_ricAction_ToBeSetup_List())
          {
            RIC_action_t action;
            action.action_id = f.ref_value()
                .select_id_RICaction_ToBeSetup_Item().ref_ricActionID().get();
            action.action_type = static_cast<enum_RICactionType>(f.ref_value()
              .select_id_RICaction_ToBeSetup_Item().ref_ricActionType().get());

            params.actionList.push_back(action);
          }
        }
        break;

      default:
        printf("Unknown IE type = %d\n", (int)type);
        return false;
    }
  }

  return true;
}

bool e2ap_create_RICsubscriptionResponse(e2ap_pdu_t* pdu, RICsubscription_params_t &params)
{
  E2APpduWrapper* pduWrapper = reinterpret_cast<E2APpduWrapper*>(pdu);

  /* Initiaization */
  pduWrapper->ref_pdu().select_successfulOutcome().ref_procedureCode().select_id_ricSubscription();
  pduWrapper->ref_pdu().select_successfulOutcome().ref_criticality().select_id_ricSubscription();

  RICsubscriptionResponse* container = &(pduWrapper->ref_pdu()
        .select_successfulOutcome().ref_value().select_id_ricSubscription());

  using IE_value_t = RICsubscriptionResponse::protocolIEs_t::value_type;

  /* RICsubscriptionResponse-IEs :  RICrequestID */
  IE_value_t* ie_RICrequestID = new IE_value_t;
  container->ref_protocolIEs().push_back(*ie_RICrequestID);

  ie_RICrequestID->ref_id().select_id_RICrequestID();
  ie_RICrequestID->ref_criticality().select_id_RICrequestID();
  ie_RICrequestID->ref_value().select_id_RICrequestID()
                                .ref_ricRequestorID().set(params.request_id);
  ie_RICrequestID->ref_value().select_id_RICrequestID()
                      .ref_ricRequestSequenceNumber().set(params.seq_number);

  /* RICsubscriptionResponse-IEs :  RANfunctionID */
  IE_value_t* ie_RANfunctionID = new IE_value_t;
  container->ref_protocolIEs().push_back(*ie_RANfunctionID);

  ie_RANfunctionID->ref_id().select_id_RANfunctionID();
  ie_RANfunctionID->ref_criticality().select_id_RANfunctionID();
  ie_RANfunctionID->ref_value().select_id_RANfunctionID().set(params.ran_func_id);

  /* RICsubscriptionResponse-IEs :  RICaction-Admitted-List */
  IE_value_t* ie_admittedList = new IE_value_t;
  container->ref_protocolIEs().push_back(*ie_admittedList);

  ie_admittedList->ref_id().select_id_RICactions_Admitted();
  ie_admittedList->ref_criticality().select_id_RICactions_Admitted();

  /* RICsubscriptionResponse-IEs :  RICaction-NotAdmitted-List */
  IE_value_t* ie_notAdmittedList = new IE_value_t;
  container->ref_protocolIEs().push_back(*ie_notAdmittedList);

  ie_notAdmittedList->ref_id().select_id_RICactions_NotAdmitted();
  ie_notAdmittedList->ref_criticality().select_id_RICactions_NotAdmitted();

  //add action to admitted and not-admitted list
  for(auto const &a : params.actionList)
  {
    if(a.isAdmitted)
    {
      RICaction_Admitted_List::value_type* item = new RICaction_Admitted_List::value_type();

      ie_admittedList->ref_value().select_id_RICactions_Admitted().push_back(*item);

      item->ref_id().select_id_RICaction_Admitted_Item();
      item->ref_criticality().select_id_RICaction_Admitted_Item();
      item->ref_value().select_id_RICaction_Admitted_Item().ref_ricActionID().set(a.action_id);
    }
    else
    {
      RICaction_NotAdmitted_List::value_type* item = new RICaction_NotAdmitted_List::value_type();

      ie_notAdmittedList->ref_value().select_id_RICactions_NotAdmitted().push_back(*item);

      item->ref_id().select_id_RICaction_NotAdmitted_Item();
      item->ref_criticality().select_id_RICaction_NotAdmitted_Item();
      item->ref_value().select_id_RICaction_NotAdmitted_Item().ref_ricActionID().set(a.action_id);

      // set cause and sub-cause
      switch(a.notAdmitted_cause)
      {
        case RICcause_radioNetwork:
          item->ref_value().select_id_RICaction_NotAdmitted_Item().ref_ricCause().select_radioNetwork().set(a.notAdmitted_subCause);
          break;

        case RICcause_transport:
          item->ref_value().select_id_RICaction_NotAdmitted_Item().ref_ricCause().select_transport().set(a.notAdmitted_subCause);
          break;

        case RICcause_protocol:
          item->ref_value().select_id_RICaction_NotAdmitted_Item().ref_ricCause().select_protocol().set(a.notAdmitted_subCause);
          break;

        case RICcause_misc:
          item->ref_value().select_id_RICaction_NotAdmitted_Item().ref_ricCause().select_misc().set(a.notAdmitted_subCause);
          break;

        case RICcause_ric:
          item->ref_value().select_id_RICaction_NotAdmitted_Item().ref_ricCause().select_ric().set(a.notAdmitted_subCause);
          break;

        default:
          printf("Unknown cause for action not admitted = %d", (int)a.notAdmitted_cause);
      }
    }
  }

  return true;
}

bool e2ap_create_RICsubscriptionFailure(e2ap_pdu_t* pdu, RICsubscription_params_t &params)
{
  E2APpduWrapper* pduWrapper = reinterpret_cast<E2APpduWrapper*>(pdu);

  /* Initiaization */
  pduWrapper->ref_pdu().select_unsuccessfulOutcome().ref_procedureCode().select_id_ricSubscription();
  pduWrapper->ref_pdu().select_unsuccessfulOutcome().ref_criticality().select_id_ricSubscription();

  RICsubscriptionFailure* container = &(pduWrapper->ref_pdu()
        .select_unsuccessfulOutcome().ref_value().select_id_ricSubscription());

  using IE_value_t = RICsubscriptionFailure::protocolIEs_t::value_type;

  /* RICsubscriptionFailure-IEs :  RICrequestID */
  IE_value_t* ie_RICrequestID = new IE_value_t;
  container->ref_protocolIEs().push_back(*ie_RICrequestID);

  ie_RICrequestID->ref_id().select_id_RICrequestID();
  ie_RICrequestID->ref_criticality().select_id_RICrequestID();
  ie_RICrequestID->ref_value().select_id_RICrequestID()
                                .ref_ricRequestorID().set(params.request_id);
  ie_RICrequestID->ref_value().select_id_RICrequestID()
                      .ref_ricRequestSequenceNumber().set(params.seq_number);

  /* RICsubscriptionFailure-IEs :  RANfunctionID */
  IE_value_t* ie_RANfunctionID = new IE_value_t;
  container->ref_protocolIEs().push_back(*ie_RANfunctionID);

  ie_RANfunctionID->ref_id().select_id_RANfunctionID();
  ie_RANfunctionID->ref_criticality().select_id_RANfunctionID();
  ie_RANfunctionID->ref_value().select_id_RANfunctionID().set(params.ran_func_id);

  /* RICsubscriptionFailure-IEs :  RICaction-NotAdmitted-List */
  IE_value_t* ie_notAdmittedList = new IE_value_t;
  container->ref_protocolIEs().push_back(*ie_notAdmittedList);

  ie_notAdmittedList->ref_id().select_id_RICactions_NotAdmitted();
  ie_notAdmittedList->ref_criticality().select_id_RICactions_NotAdmitted();

  for(auto const &a : params.actionList)
  {
    if(!a.isAdmitted)
    {
      RICaction_NotAdmitted_List::value_type* item = new RICaction_NotAdmitted_List::value_type();

      ie_notAdmittedList->ref_value().select_id_RICactions_NotAdmitted().push_back(*item);

      item->ref_id().select_id_RICaction_NotAdmitted_Item();
      item->ref_criticality().select_id_RICaction_NotAdmitted_Item();
      item->ref_value().select_id_RICaction_NotAdmitted_Item().ref_ricActionID().set(a.action_id);

      // set cause and sub-cause
      switch(a.notAdmitted_cause)
      {
        case RICcause_radioNetwork:
          item->ref_value().select_id_RICaction_NotAdmitted_Item().ref_ricCause().select_radioNetwork().set(a.notAdmitted_subCause);
          break;

        case RICcause_transport:
          item->ref_value().select_id_RICaction_NotAdmitted_Item().ref_ricCause().select_transport().set(a.notAdmitted_subCause);
          break;

        case RICcause_protocol:
          item->ref_value().select_id_RICaction_NotAdmitted_Item().ref_ricCause().select_protocol().set(a.notAdmitted_subCause);
          break;

        case RICcause_misc:
          item->ref_value().select_id_RICaction_NotAdmitted_Item().ref_ricCause().select_misc().set(a.notAdmitted_subCause);
          break;

        case RICcause_ric:
          item->ref_value().select_id_RICaction_NotAdmitted_Item().ref_ricCause().select_ric().set(a.notAdmitted_subCause);
          break;

        default:
          printf("Unknown cause for action not admitted = %d", (int)a.notAdmitted_cause);
      }
    }
  }

  return true;
}


/*-----------------------------------------------------------------------
                              TESTS
-------------------------------------------------------------------------
*/
void test_E2AP_X2Setup_codec(void)
{
  e2ap_pdu_t* pdu = new_e2ap_pdu();

  // e2ap_init_X2SetupRequest(pdu);
  eNB_config cfg;
  e2ap_create_X2SetupRequest(pdu, cfg);

  char pdu_str[1024];
  e2ap_asn_print(pdu, pdu_str, sizeof(pdu_str));
  printf("%s\n", pdu_str);

  //Test encode
  unsigned char packed_buf[4096];
  char          err_buf[1024];

  int packed_len = e2ap_asn_per_encode(pdu, packed_buf, sizeof(packed_buf),
                                            err_buf, sizeof(err_buf));
  if(packed_len != -1) {
    printf("Encode successful, packed_len = %d\n", packed_len);
  } else {
    printf("Encode Error: %s\n", err_buf);
  }

  //Test decode
  e2ap_pdu_t* pdu2 = new_e2ap_pdu();
  int rc = e2ap_asn_per_decode(pdu2, packed_buf, packed_len, err_buf, sizeof(err_buf));
  if(rc == -1) {
    printf("Decode error: %s\n", err_buf);
  } else {
    printf("Decode successful\n");
  }

  e2ap_asn_print(pdu2, pdu_str, sizeof(pdu_str));
  printf("%s\n", pdu_str);

  printf("index = %d\n", e2ap_get_index(pdu2));
  printf("procedureCode = %d\n", e2ap_get_procedureCode(pdu2));

  //Test X2SetupResponse
  e2ap_pdu_t* pdu_resp = new_e2ap_pdu();
  e2ap_create_X2SetupResponse(pdu_resp, cfg);
  e2ap_asn_print(pdu_resp, pdu_str, sizeof(pdu_str));
  printf("%s\n", pdu_str);

  //Test X2SetupFailure
  e2ap_pdu_t* pdu_failure = new_e2ap_pdu();
  e2ap_create_X2SetupFailure(pdu_failure);
  e2ap_asn_print(pdu_failure, pdu_str, sizeof(pdu_str));
  printf("%s \n", pdu_str);
}
