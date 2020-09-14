

#include <iostream>
#include <fstream>
#include <vector>



extern "C" {
  #include "OCUCP-PF-Container.h"
  #include "OCTET_STRING.h"
  #include "asn_application.h"
  #include "E2SM-KPM-IndicationMessage.h"
  #include "FQIPERSlicesPerPlmnListItem.h"
  #include "E2SM-KPM-RANfunction-Description.h"
  #include "Timestamp.h"
  #include "E2AP-PDU.h"
  #include "RICsubscriptionRequest.h"
  #include "RICsubscriptionResponse.h"
  #include "RICactionType.h"
  #include "ProtocolIE-Field.h"
  #include "ProtocolIE-SingleContainer.h"
  #include "InitiatingMessage.h"
}
  
#include "encode_kpm.hpp"

#include "encode_e2apv1.hpp"

#include <nlohmann/json.hpp>
#include <thread>




#include "e2sim.hpp"

using json = nlohmann::json;

using namespace std;

struct neighbor_cell_entry {
  char *cellid;
  int rsrp;
  int rsrq;
  int rssinr;

};

void run_report_loop(long requestorId, long instanceId, long ranFunctionId, long actionId, int socket_fd) {

  //Process simulation file

  ifstream simfile;
  string line;

  long seqNum = 1;
  
  simfile.open("simulation.txt", ios::in);

  cout << "step1" << endl;
    
  std::ifstream ue_stream("ueMeasReport.txt");
  std::ifstream cell_stream("cellMeasReport.txt");

  json all_ues_json;

  ue_stream  >> all_ues_json;

  json all_cells_json;

  cell_stream >> all_cells_json;

  asn_codec_ctx_t *opt_cod;

  cout << "UE RF Measurements" << endl;
  cout << "******************" << endl;

  int numMeasReports = (all_ues_json["/ueMeasReport/ueMeasReportList"_json_pointer]).size();

  for (int i = 0; i < numMeasReports; i++) {
    int nextCellId;
    int nextRsrp;
    int nextRsrq;
    int nextRssinr;
    cout << "UE number " + i << endl;
    cout << "**********" << endl;
    json::json_pointer p1(std::string("/ueMeasReport/ueMeasReportList/") + std::to_string(i) +"/nrCellIdentity");
    nextCellId = all_ues_json[p1].get<int>();
    cout << "Serving Cell " << nextCellId << endl;
    
    json::json_pointer p2(std::string("/ueMeasReport/ueMeasReportList/") + std::to_string(i) +"/servingCellRfReport/rsrp");
    nextRsrp = all_ues_json[p2].get<int>();
    cout << "  RSRP " << nextRsrp << endl;
    json::json_pointer p3(std::string("/ueMeasReport/ueMeasReportList/") + std::to_string(i) +"/servingCellRfReport/rsrq");
    nextRsrq = all_ues_json[p3].get<int>();
    cout << "  RSRQ " << nextRsrq << endl;
    json::json_pointer p4(std::string("/ueMeasReport/ueMeasReportList/") + std::to_string(i) +"/servingCellRfReport/rssinr");
    nextRssinr = all_ues_json[p4].get<int>();
    cout << "  RSSINR " << nextRssinr << endl;

    json::json_pointer p5(std::string("/ueMeasReport/ueMeasReportList/") + std::to_string(i) +"/neighbourCellList");

    int numNeighborCells = (all_ues_json[p5]).size();


    //REPORT Message 3 -- Encode and send OCUCP user-level report
    
    E2SM_KPM_IndicationMessage_t *ind_msg3 =
      (E2SM_KPM_IndicationMessage_t*)calloc(1,sizeof(E2SM_KPM_IndicationMessage_t));
    E2AP_PDU *pdu3 = (E2AP_PDU*)calloc(1,sizeof(E2AP_PDU));
    
    uint8_t *crnti_buf = (uint8_t*)calloc(1,2);

    if (nextCellId == 0) {
      uint8_t *buf2 = (uint8_t*)"12";
      memcpy(crnti_buf, buf2, 2);
    } else if (nextCellId == 1) {
      uint8_t *buf2 = (uint8_t*)"22";
      memcpy(crnti_buf, buf2, 2);
    }

    std::string serving_str = "{\"rsrp\": " + std::to_string(nextRsrp) + ", \"rsrq\": " +
      std::to_string(nextRsrq) + ", \"rssinr\": " + std::to_string(nextRssinr) + "}";
    const uint8_t *serving_buf = reinterpret_cast<const uint8_t*>(serving_str.c_str());
        
    std::string neighbor_str = "[";

    int nextNbCell;
    int nextNbRsrp;
    int nextNbRsrq;
    int nextNbRssinr;

    for (int j = 0; j < numNeighborCells; j++) {
      json::json_pointer p8(std::string("/ueMeasReport/ueMeasReportList/") + std::to_string(i) +"/neighbourCellList/" + std::to_string(j) + "/nbCellIdentity");
      nextNbCell = all_ues_json[p8].get<int>();
      cout << "Neighbor Cell " << all_ues_json[p8] << endl;
      json::json_pointer p9(std::string("/ueMeasReport/ueMeasReportList/") + std::to_string(i)
			    +"/neighbourCellList/" + std::to_string(j) + "/nbCellRfReport/rsrp");
      nextNbRsrp = all_ues_json[p9].get<int>();
      cout << "  RSRP " << nextNbRsrp << endl;

      json::json_pointer p10(std::string("/ueMeasReport/ueMeasReportList/") + std::to_string(i)
			    +"/neighbourCellList/" + std::to_string(j) + "/nbCellRfReport/rsrq");
      nextNbRsrq = all_ues_json[p10].get<int>();
      cout << "  RSRQ " << nextNbRsrq << endl;

      json::json_pointer p11(std::string("/ueMeasReport/ueMeasReportList/") + std::to_string(i)
			     +"/neighbourCellList/" + std::to_string(j) + "/nbCellRfReport/rssinr");
      nextNbRssinr = all_ues_json[p11].get<int>();
      cout << "  RSSINR " << nextNbRssinr << endl;

      if (j != 0) {
	neighbor_str += ",";

      }

      neighbor_str += "{\"CID\" : \"" + std::to_string(nextNbCell) + "\", \"Cell-RF\" : \"{\"rsrp\": " + std::to_string(nextNbRsrp) +
	", \"rsrq\": " + std::to_string(nextNbRsrq) + ", \"rssinr\": " + std::to_string(nextNbRssinr) + "}}";
      
    }

    neighbor_str += "]";
    
    const uint8_t *neighbor_buf = reinterpret_cast<const uint8_t*>(neighbor_str.c_str());
    
    printf("Neighbor string\n%s", neighbor_buf);

    uint8_t *plmnid_buf = (uint8_t*)"747";
    uint8_t *nrcellid_buf = (uint8_t*)"12340";
    
    encode_kpm_report_rancontainer_cucp_parameterized(ind_msg3, plmnid_buf, nrcellid_buf, crnti_buf, serving_buf, neighbor_buf);
    
    uint8_t e2smbuffer3[8192];
    size_t e2smbuffer_size3 = 8192;

    
    asn_enc_rval_t er3 = asn_encode_to_buffer(opt_cod,
					      ATS_ALIGNED_BASIC_PER,
					      &asn_DEF_E2SM_KPM_IndicationMessage,
					      ind_msg3, e2smbuffer3, e2smbuffer_size3);
    
    fprintf(stderr, "er encded is %d\n", er3.encoded);
    fprintf(stderr, "after encoding message\n");
    uint8_t *e2smheader_buf3 = (uint8_t*)"header";
    
    generate_e2apv1_indication_request_parameterized(pdu3, requestorId,
						     instanceId, ranFunctionId,
						     actionId, seqNum, e2smheader_buf3, 6, e2smbuffer3, er3.encoded);
    
    encode_and_send_sctp_data(pdu3, socket_fd);
    
    seqNum++;
        
  }


  cout << "Cell Measurements" << endl;
  cout << "******************" << endl;

  int numCellMeasReports = (all_cells_json["/cellMeasReport/cellMeasReportList"_json_pointer]).size();

  uint8_t *sst_buf = (uint8_t*)"1";
  uint8_t *sd_buf = (uint8_t*)"100";
  uint8_t *plmnid_buf = (uint8_t*)"747";
  
  for (int i = 0; i < numCellMeasReports; i++) {

    int nextCellId;
    int nextPdcpBytesDL;
    int nextPdcpBytesUL;
    int nextPRBBytesDL;
    int nextPRBBytesUL;

    json::json_pointer p1(std::string("/cellMeasReport/cellMeasReportList/") + std::to_string(i) +"/nrCellIdentity");
    nextCellId = all_cells_json[p1].get<int>();
    cout << std::string("Cell number ") << nextCellId << endl;
    
    cout << "**********" << endl;
    
    json::json_pointer p2(std::string("/cellMeasReport/cellMeasReportList/") + std::to_string(i) +"/pdcpByteMeasReport/pdcpBytesDl");
    nextPdcpBytesDL = all_cells_json[p2].get<int>();
    cout << std::string("  PDCP Bytes DL ") << nextPdcpBytesDL << endl;

    json::json_pointer p3(std::string("/cellMeasReport/cellMeasReportList/") + std::to_string(i) +"/pdcpByteMeasReport/pdcpBytesUl");
    nextPdcpBytesUL = all_cells_json[p3].get<int>();    
    cout << std::string("  PDCP Bytes UL ") << nextPdcpBytesUL << endl;

    uint8_t *buf = (uint8_t*)"GNBCUUP5";
    
    int bytes_dl = nextPdcpBytesDL;

    int bytes_ul = nextPdcpBytesUL;

    //    int bytes_dl = 3905;
    //    int bytes_ul = 1609321;    
    
    E2SM_KPM_IndicationMessage_t *ind_msg2 =
      (E2SM_KPM_IndicationMessage_t*)calloc(1,sizeof(E2SM_KPM_IndicationMessage_t));
    E2AP_PDU *pdu2 = (E2AP_PDU*)calloc(1,sizeof(E2AP_PDU));
    
    encode_kpm_report_style5_parameterized(ind_msg2 , buf, bytes_dl, bytes_ul, sst_buf, sd_buf, plmnid_buf);
    
    uint8_t e2smbuffer2[8192];
    size_t e2smbuffer_size2 = 8192;
    
    asn_enc_rval_t er2 = asn_encode_to_buffer(opt_cod,
					      ATS_ALIGNED_BASIC_PER,
					      &asn_DEF_E2SM_KPM_IndicationMessage,
					      ind_msg2, e2smbuffer2, e2smbuffer_size2);
    
    fprintf(stderr, "er encded is %d\n", er2.encoded);
    fprintf(stderr, "after encoding message\n");
    uint8_t *e2smheader_buf2 = (uint8_t*)"header";
    
    generate_e2apv1_indication_request_parameterized(pdu2, requestorId,
						     instanceId, ranFunctionId,
						     actionId, seqNum, e2smheader_buf2, 6, e2smbuffer2, er2.encoded);
    
    encode_and_send_sctp_data(pdu2, socket_fd);
    
    seqNum++;

    

    json::json_pointer p4(std::string("/cellMeasReport/cellMeasReportList/") + std::to_string(i) +"/prbMeasReport/availPrbDl");
    nextPRBBytesDL = all_cells_json[p4].get<int>();    
    cout << std::string("  PRB Bytes DL ") << all_cells_json[p4] << endl;

    json::json_pointer p5(std::string("/cellMeasReport/cellMeasReportList/") + std::to_string(i) +"/prbMeasReport/availPrbUl");
    nextPRBBytesUL = all_cells_json[p5].get<int>();
    cout << std::string("  PRB Bytes UL ") << all_cells_json[p5] << endl;


    //REPORT Message 1 -- Encode and send ODU cell-level report
    
    E2SM_KPM_IndicationMessage_t *ind_msg1 =
      (E2SM_KPM_IndicationMessage_t*)calloc(1,sizeof(E2SM_KPM_IndicationMessage_t));
    E2AP_PDU *pdu = (E2AP_PDU*)calloc(1,sizeof(E2AP_PDU));
    
    long fiveqi = 7;

    uint8_t *nrcellid_buf = (uint8_t*)"12340";
    long dl_prbs = nextPRBBytesDL;
    long ul_prbs = nextPRBBytesUL;
    
    encode_kpm_report_style1_parameterized(ind_msg1, fiveqi, dl_prbs, ul_prbs, sst_buf, sd_buf, plmnid_buf, nrcellid_buf, &dl_prbs, &ul_prbs);
    
    uint8_t e2smbuffer[8192];
    size_t e2smbuffer_size = 8192;
    
    asn_enc_rval_t er = asn_encode_to_buffer(opt_cod,
					     ATS_ALIGNED_BASIC_PER,
					     &asn_DEF_E2SM_KPM_IndicationMessage,
					     ind_msg1, e2smbuffer, e2smbuffer_size);
    
    fprintf(stderr, "er encded is %d\n", er.encoded);
    fprintf(stderr, "after encoding message\n");
    uint8_t *e2smheader_buf = (uint8_t*)"header";
    
    uint8_t *cpid_buf = (uint8_t*)"CPID";
    
    fprintf(stderr, "About to encode Indication\n");
    generate_e2apv1_indication_request_parameterized(pdu, requestorId,
						     instanceId, ranFunctionId,
						     actionId, seqNum, e2smheader_buf, 6, e2smbuffer, er.encoded);
    
    encode_and_send_sctp_data(pdu, socket_fd);
    
    seqNum++;
    
  }


  /*
  if (simfile.is_open()) {

    while (getline(simfile, line)) {
      cout << line << "\n";

      //REPORT Message 1 -- Encode and send ODU cell-level report

      E2SM_KPM_IndicationMessage_t *ind_msg1 =
	(E2SM_KPM_IndicationMessage_t*)calloc(1,sizeof(E2SM_KPM_IndicationMessage_t));
      E2AP_PDU *pdu = (E2AP_PDU*)calloc(1,sizeof(E2AP_PDU));

      long fiveqi = 7;
      uint8_t *sst_buf = (uint8_t*)"1";
      uint8_t *sd_buf = (uint8_t*)"100";
      uint8_t *plmnid_buf = (uint8_t*)"747";
      uint8_t *nrcellid_buf = (uint8_t*)"12340";
      long dl_prbs = 100;
      long ul_prbs = 50; 
     
      encode_kpm_report_style1_parameterized(ind_msg1, fiveqi, dl_prbs, ul_prbs, sst_buf, sd_buf, plmnid_buf, nrcellid_buf, &dl_prbs, &ul_prbs);

      uint8_t e2smbuffer[8192];
      size_t e2smbuffer_size = 8192;
      asn_codec_ctx_t *opt_cod;

      asn_enc_rval_t er = asn_encode_to_buffer(opt_cod,
					       ATS_ALIGNED_BASIC_PER,
					       &asn_DEF_E2SM_KPM_IndicationMessage,
					       ind_msg1, e2smbuffer, e2smbuffer_size);
      
      fprintf(stderr, "er encded is %d\n", er.encoded);
      fprintf(stderr, "after encoding message\n");
      uint8_t *e2smheader_buf = (uint8_t*)"header";

      uint8_t *cpid_buf = (uint8_t*)"CPID";

      fprintf(stderr, "About to encode Indication\n");
      generate_e2apv1_indication_request_parameterized(pdu, requestorId,
						       instanceId, ranFunctionId,
						       actionId, seqNum, e2smheader_buf, 6, e2smbuffer, er.encoded);

      encode_and_send_sctp_data(pdu, socket_fd);
      
      seqNum++;

      //REPORT Message 2 -- Encode and send OCUUP cell-level report

      uint8_t *buf = (uint8_t*)"GNBCUUP5";

      int bytes_dl = 40000;
      int bytes_ul = 50000;

      E2SM_KPM_IndicationMessage_t *ind_msg2 =
	(E2SM_KPM_IndicationMessage_t*)calloc(1,sizeof(E2SM_KPM_IndicationMessage_t));
      E2AP_PDU *pdu2 = (E2AP_PDU*)calloc(1,sizeof(E2AP_PDU));
      
      encode_kpm_report_style5_parameterized(ind_msg2 , buf, bytes_dl, bytes_ul, sst_buf, sd_buf, plmnid_buf);

      uint8_t e2smbuffer2[8192];
      size_t e2smbuffer_size2 = 8192;


      asn_enc_rval_t er2 = asn_encode_to_buffer(opt_cod,
					       ATS_ALIGNED_BASIC_PER,
					       &asn_DEF_E2SM_KPM_IndicationMessage,
					       ind_msg2, e2smbuffer2, e2smbuffer_size2);
      
      fprintf(stderr, "er encded is %d\n", er2.encoded);
      fprintf(stderr, "after encoding message\n");
      uint8_t *e2smheader_buf2 = (uint8_t*)"header";

      generate_e2apv1_indication_request_parameterized(pdu2, requestorId,
						       instanceId, ranFunctionId,
						       actionId, seqNum, e2smheader_buf2, 6, e2smbuffer2, er2.encoded);

      encode_and_send_sctp_data(pdu2, socket_fd);
      
      seqNum++;

      //REPORT Message 3 -- Encode and send OCUCP user-level report

      E2SM_KPM_IndicationMessage_t *ind_msg3 =
	(E2SM_KPM_IndicationMessage_t*)calloc(1,sizeof(E2SM_KPM_IndicationMessage_t));
      E2AP_PDU *pdu3 = (E2AP_PDU*)calloc(1,sizeof(E2AP_PDU));

      uint8_t *crnti_buf = (uint8_t*)"12";
      //      uint8_t *serving_buf = (uint8_t*)"RSRP10";
      //uint8_t *neighbor_buf = (uint8_t*)"-10,-15";
      int rsrpServ = 10;
      int rsrqServ = 0;
      int rssinrServ = 0;

      std::string serving_str = "{\"rsrp\": " + std::to_string(rsrpServ) + ", \"rsrq\": " +
	std::to_string(rsrqServ) + ", \"rssinr\": " + std::to_string(rssinrServ) + "}";
      const uint8_t *serving_buf = reinterpret_cast<const uint8_t*>(serving_str.c_str());


      neighbor_cell_entry n_entries[3];
      n_entries[0] = {"123", 10, 0, 0};
      n_entries[1] = {"456", 10, 0, 0};
      n_entries[2] = {"789", 10, 0, 0};

      std::string neighbor_str = "[";

      for (int i=0; i < sizeof(n_entries)/sizeof(n_entries[0]); i++) {

	if (i != 0) {
	  neighbor_str += ",";
	}
	neighbor_str += "{\"CID\" : \"" + std::string(n_entries[i].cellid) + "\", \"Cell-RF\" : \"{\"rsrp\": " + std::to_string(n_entries[i].rsrp) +
	  ", \"rsrq\": " + std::to_string(n_entries[i].rsrq) + ", \"rssinr\": " + std::to_string(n_entries[i].rsrp) + "}}";
      }

      neighbor_str += "]";

      const uint8_t *neighbor_buf = reinterpret_cast<const uint8_t*>(neighbor_str.c_str());

      printf("Neighbor string\n%s", neighbor_buf);

      encode_kpm_report_rancontainer_cucp_parameterized(ind_msg3, plmnid_buf, nrcellid_buf, crnti_buf, serving_buf, neighbor_buf);
      
      uint8_t e2smbuffer3[8192];
      size_t e2smbuffer_size3 = 8192;

      asn_enc_rval_t er3 = asn_encode_to_buffer(opt_cod,
						ATS_ALIGNED_BASIC_PER,
						&asn_DEF_E2SM_KPM_IndicationMessage,
						ind_msg3, e2smbuffer3, e2smbuffer_size3);
      
      fprintf(stderr, "er encded is %d\n", er3.encoded);
      fprintf(stderr, "after encoding message\n");
      uint8_t *e2smheader_buf3 = (uint8_t*)"header";

      generate_e2apv1_indication_request_parameterized(pdu3, requestorId,
						       instanceId, ranFunctionId,
						       actionId, seqNum, e2smheader_buf3, 6, e2smbuffer3, er3.encoded);

      encode_and_send_sctp_data(pdu3, socket_fd);
            
      seqNum++;
      
      //Encode and send OCUUP user-level report


      
      //Encode and send ODU user-level report

      

      
    }

    simfile.close();

  }
  */

}

void callback_kpm_subscription_request(E2AP_PDU_t *sub_req_pdu, int socket_fd) {


  //Record RIC Request ID
  //Go through RIC action to be Setup List
  //Find first entry with REPORT action Type
  //Record ricActionID
  //Encode subscription response

  RICsubscriptionRequest_t orig_req =
    sub_req_pdu->choice.initiatingMessage->value.choice.RICsubscriptionRequest;
  
  RICsubscriptionResponse_IEs_t *ricreqid =
    (RICsubscriptionResponse_IEs_t*)calloc(1, sizeof(RICsubscriptionResponse_IEs_t));
					   
  int count = orig_req.protocolIEs.list.count;
  int size = orig_req.protocolIEs.list.size;
  
  RICsubscriptionRequest_IEs_t **ies = (RICsubscriptionRequest_IEs_t**)orig_req.protocolIEs.list.array;

  fprintf(stderr, "count%d\n", count);
  fprintf(stderr, "size%d\n", size);

  RICsubscriptionRequest_IEs__value_PR pres;

  long reqRequestorId;
  long reqInstanceId;
  long reqActionId;

  std::vector<long> actionIdsAccept;
  std::vector<long> actionIdsReject;

  for (int i=0; i < count; i++) {
    RICsubscriptionRequest_IEs_t *next_ie = ies[i];
    pres = next_ie->value.present;
    
    fprintf(stderr, "next present value %d\n", pres);

    switch(pres) {
    case RICsubscriptionRequest_IEs__value_PR_RICrequestID:
      {
	RICrequestID_t reqId = next_ie->value.choice.RICrequestID;
	long requestorId = reqId.ricRequestorID;
	long instanceId = reqId.ricInstanceID;
	fprintf(stderr, "requestorId %d\n", requestorId);
	fprintf(stderr, "instanceId %d\n", instanceId);
	reqRequestorId = requestorId;
	reqInstanceId = instanceId;

	break;
      }
    case RICsubscriptionRequest_IEs__value_PR_RANfunctionID:
      break;
    case RICsubscriptionRequest_IEs__value_PR_RICsubscriptionDetails:
      {
	RICsubscriptionDetails_t subDetails = next_ie->value.choice.RICsubscriptionDetails; 
	RICeventTriggerDefinition_t triggerDef = subDetails.ricEventTriggerDefinition;
	RICactions_ToBeSetup_List_t actionList = subDetails.ricAction_ToBeSetup_List;

	//We are ignoring the trigger definition

	//We identify the first action whose type is REPORT
	//That is the only one accepted; all others are rejected
	
	int actionCount = actionList.list.count;
	fprintf(stderr, "action count%d\n", actionCount);

	auto **item_array = actionList.list.array;

	bool foundAction = false;

	for (int i=0; i < actionCount; i++) {

	  auto *next_item = item_array[i];
	  RICactionID_t actionId = ((RICaction_ToBeSetup_ItemIEs*)next_item)->value.choice.RICaction_ToBeSetup_Item.ricActionID;
	  RICactionType_t actionType = ((RICaction_ToBeSetup_ItemIEs*)next_item)->value.choice.RICaction_ToBeSetup_Item.ricActionType;

	  if (!foundAction && actionType == RICactionType_report) {
	    reqActionId = actionId;
	    actionIdsAccept.push_back(reqActionId);
	    printf("adding accept\n");
	    foundAction = true;
	  } else {
	    reqActionId = actionId;
	    printf("adding reject\n");
	    actionIdsReject.push_back(reqActionId);
	  }
	}
	
	break;
      }
    }
    
  }

  fprintf(stderr, "After Processing Subscription Request\n");

  fprintf(stderr, "requestorId %d\n", reqRequestorId);
  fprintf(stderr, "instanceId %d\n", reqInstanceId);


  for (int i=0; i < actionIdsAccept.size(); i++) {
    fprintf(stderr, "Action ID %d %ld\n", i, actionIdsAccept.at(i));
    
  }

  E2AP_PDU *e2ap_pdu = (E2AP_PDU*)calloc(1,sizeof(E2AP_PDU));

  long *accept_array = &actionIdsAccept[0];
  long *reject_array = &actionIdsReject[0];
  int accept_size = actionIdsAccept.size();
  int reject_size = actionIdsReject.size();

  generate_e2apv1_subscription_response_success(e2ap_pdu, accept_array, reject_array, accept_size, reject_size, reqRequestorId, reqInstanceId);

  encode_and_send_sctp_data(e2ap_pdu,socket_fd);

  //Start thread for sending REPORT messages

  //  std::thread loop_thread;

  long funcId = 1;

  run_report_loop(reqRequestorId, reqInstanceId, funcId, reqActionId, socket_fd);

  //  loop_thread = std::thread(&run_report_loop);

}
