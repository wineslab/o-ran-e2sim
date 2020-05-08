#include <stdio.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <vector>

#include "encode_kpm.hpp";

using namespace std;

void encode_kpm(E2SM_KPM_IndicationMessage_t* indicationmessage) {
  ASN_STRUCT_RESET(asn_DEF_E2SM_KPM_IndicationMessage, indicationmessage);
  std::string gn = "GNBCUUP5";
  std::vector<uint8_t> gnvec(gn.begin(), gn.end());
  uint8_t *buf = &gnvec[0];
  OCTET_STRING_t *gnbcuupname = (OCTET_STRING_t*)calloc(1, sizeof(OCTET_STRING_t));
  gnbcuupname->size = 8;
  gnbcuupname->buf = (uint8_t*)calloc(1,8);
  memcpy(gnbcuupname->buf, buf, gnbcuupname->size);


  INTEGER_t *bytesdl = (INTEGER_t*)calloc(1, sizeof(INTEGER_t));
  uint8_t buffer[1];
  buffer[0]= 40000;
  bytesdl->buf = (uint8_t*)calloc(1,1);
  memcpy(bytesdl->buf, buffer,1);
  bytesdl->size = 1;

  INTEGER_t *bytesul = (INTEGER_t*)calloc(1, sizeof(INTEGER_t));
  uint8_t buffer1[1];
  buffer1[0] = 50000;
  bytesul->buf = (uint8_t*)calloc(1,1);
  memcpy(bytesul->buf, buffer1, 1);
  bytesul->size = 1;

  FQIPERSlicesPerPlmnListItem_t *fqilistitem = (FQIPERSlicesPerPlmnListItem_t*)calloc(1, sizeof(FQIPERSlicesPerPlmnListItem_t));
  ASN_STRUCT_RESET(asn_DEF_FQIPERSlicesPerPlmnListItem, fqilistitem);
  fqilistitem->fiveQI = 9;
  fqilistitem->pDCPBytesDL = bytesdl;
  fqilistitem->pDCPBytesUL = bytesul;



  std::string sl = "SLICE4";
  std::vector<uint8_t> slvec(sl.begin(), sl.end());
  //  uint8_t *buf1 = &slvec[0];
  uint8_t *buf1 = (uint8_t*)"SLICE4";  
  OCTET_STRING_t *sst = (OCTET_STRING_t*)calloc(1, sizeof(OCTET_STRING_t));
  sst->size = 6;
  sst->buf = (uint8_t*)calloc(1,6);
  memcpy(sst->buf,buf1,sst->size);

  std::string sd = "SD1";
  std::vector<uint8_t> sdvec(sd.begin(), sd.end());
  //  uint8_t *bufz = &sdvec[0];
  uint8_t *bufz = (uint8_t*)"SD1";
  OCTET_STRING_t *sds = (OCTET_STRING_t*)calloc(1, sizeof(OCTET_STRING_t));
  sds->size = 3;
  sds->buf = (uint8_t*)calloc(1,3);
  memcpy(sds->buf, bufz, sds->size);

  
  SNSSAI_t *snssai = (SNSSAI_t*)calloc(1, sizeof(SNSSAI_t));
  ASN_STRUCT_RESET(asn_DEF_SNSSAI,snssai);
  snssai->sST.buf = (uint8_t*)calloc(6,1);
  snssai->sST.size = 6;
  memcpy(snssai->sST.buf, buf1, 6);
  snssai->sD = (OCTET_STRING_t*)calloc(1, sizeof(OCTET_STRING_t));
  snssai->sD->buf = (uint8_t*)calloc(1,3);
  snssai->sD->size = 3;
  memcpy(snssai->sD->buf, bufz, 3);

  

  SliceToReportListItem_t *slicelistitem = (SliceToReportListItem_t*)calloc(1,sizeof(SliceToReportListItem_t));
  ASN_STRUCT_RESET(asn_DEF_SliceToReportListItem, slicelistitem);
  slicelistitem->sliceID = *snssai;
  int ret = ASN_SEQUENCE_ADD(&slicelistitem->fQIPERSlicesPerPlmnList.list, fqilistitem);

  uint8_t e2smbuffera[8192];
  size_t e2smbuffer_sizea = 8192;  

  auto era =
    asn_encode_to_buffer(nullptr,
			 ATS_ALIGNED_BASIC_PER,
			 &asn_DEF_SliceToReportListItem,
			 slicelistitem, e2smbuffera, e2smbuffer_sizea);
  fprintf(stderr, "inner er encded is %d\n", era.encoded);
  fprintf(stderr, "after encoding message\n");      

  FGC_CUUP_PM_Format_t *pm_format = (FGC_CUUP_PM_Format_t*)calloc(1,sizeof(FGC_CUUP_PM_Format_t));
  ASN_STRUCT_RESET(asn_DEF_FGC_CUUP_PM_Format, pm_format);
  ret = ASN_SEQUENCE_ADD(&pm_format->sliceToReportList.list, slicelistitem);

  std::string pl = "PLMNID7";
  std::vector<uint8_t> plvec(pl.begin(), pl.end());
  uint8_t *buf2 = &plvec[0];
  
  OCTET_STRING_t *plmnid = (OCTET_STRING_t*)calloc(1,sizeof(OCTET_STRING_t));
  plmnid->buf = (uint8_t*)calloc(1,7);
  plmnid->size = 7;  
  memcpy(plmnid->buf, buf2, plmnid->size);


  PlmnID_List_t *plmnidlist = (PlmnID_List_t*)calloc(1,sizeof(PlmnID_List_t));
  ASN_STRUCT_RESET(asn_DEF_PlmnID_List, plmnidlist);
  plmnidlist->pLMN_Identity = *plmnid;
  plmnidlist->cu_UP_PM_5GC = pm_format;

  CUUPMeasurement_Container_t *meas_cont = (CUUPMeasurement_Container_t*)calloc(1, sizeof(CUUPMeasurement_Container_t));
  ASN_STRUCT_RESET(asn_DEF_CUUPMeasurement_Container, meas_cont);
  ret = ASN_SEQUENCE_ADD(&meas_cont->plmnList.list, plmnidlist);


  
  
  PF_ContainerListItem_t *listitem1 = (PF_ContainerListItem_t*)calloc(1, sizeof(PF_ContainerListItem_t));
  ASN_STRUCT_RESET(asn_DEF_PF_ContainerListItem, listitem1);
  listitem1->interface_type = 2;
  listitem1->o_CU_UP_PM_Container = *meas_cont;

  OCUUP_PF_Container_t *cuupcont = (OCUUP_PF_Container_t*)calloc(1,sizeof(OCUUP_PF_Container_t));
  ASN_STRUCT_RESET(asn_DEF_OCUUP_PF_Container, cuupcont);
  cuupcont->gNB_CU_UP_Name = gnbcuupname;
  ret = ASN_SEQUENCE_ADD(&cuupcont->pf_ContainerList.list, listitem1);
  
  PF_Container_PR pres1 = PF_Container_PR_oCU_UP;

  PF_Container_t *pfcontainer = (PF_Container_t*)calloc(1, sizeof(PF_Container_t));
  ASN_STRUCT_RESET(asn_DEF_PF_Container, pfcontainer);
  pfcontainer->present = pres1;
  pfcontainer->choice.oCU_UP = *cuupcont;

  PM_Containers_List_t *containers_list = (PM_Containers_List_t*)calloc(1, sizeof(PM_Containers_List_t));
  ASN_STRUCT_RESET(asn_DEF_PM_Containers_List, containers_list);
  containers_list->performanceContainer = pfcontainer;

  E2SM_KPM_IndicationMessage_Format1_t *format =
    (E2SM_KPM_IndicationMessage_Format1_t*)calloc(1, sizeof(E2SM_KPM_IndicationMessage_Format1_t));
  ASN_STRUCT_RESET(asn_DEF_E2SM_KPM_IndicationMessage_Format1, format);

  ret = ASN_SEQUENCE_ADD(&format->pm_Containers.list, containers_list);
  
  E2SM_KPM_IndicationMessage_PR pres = E2SM_KPM_IndicationMessage_PR_indicationMessage_Format1;

  indicationmessage->present = pres;

  indicationmessage->choice.indicationMessage_Format1 = *format;

  char *error_buf = (char*)calloc(300, sizeof(char));
  size_t errlen;

  asn_check_constraints(&asn_DEF_E2SM_KPM_IndicationMessage, indicationmessage, error_buf, &errlen);
  printf("error length %d\n", errlen);
  printf("error buf %s\n", error_buf);
  

  uint8_t e2smbuffer[8192];
  size_t e2smbuffer_size = 8192;

  uint8_t e2smbuffer2[8192];
  size_t e2smbuffer_size2 = 8192;  

  auto er =
    asn_encode_to_buffer(nullptr,
			 ATS_ALIGNED_BASIC_PER,
			 &asn_DEF_E2SM_KPM_IndicationMessage,
			 indicationmessage, e2smbuffer, e2smbuffer_size);

  fprintf(stderr, "er encded is %d\n", er.encoded);
  fprintf(stderr, "after encoding message\n");

  
}
