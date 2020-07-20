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
#ifndef E2AP_CONFIG_HPP
#define E2AP_CONFIG_HPP

#include <string>
#include <vector>

enum enum_Transmission_Bandwidth {
  enum_bw6,
  enum_bw15,
  enum_bw25,
  enum_bw50,
  enum_bw75,
  enum_bw100,
  enum_bw1
};

enum enum_NRNRB{
  enum_nrb11, enum_nrb18, enum_nrb24, enum_nrb25, enum_nrb31, enum_nrb32,
  enum_nrb38, enum_nrb51, enum_nrb52, enum_nrb65, enum_nrb66, enum_nrb78,
  enum_nrb79, enum_nrb93, enum_nrb106, enum_nrb107, enum_nrb121,
  enum_nrb132, enum_nrb133, enum_nrb135, enum_nrb160, enum_nrb162,
  enum_nrb189, enum_nrb216, enum_nrb217, enum_nrb245, enum_nrb264,
  enum_nrb270, enum_nrb273
};

enum enum_NRSCS {
  enum_scs15, enum_scs30, enum_scs60, enum_scs120
};

class eNB_config {
  public:
    uint8_t* pLMN_Identity;
    uint8_t* macro_eNB_ID;
    int64_t  pCI;
    uint8_t* tAC;
    uint8_t* eUTRANcellIdentifier;

    int64_t   uL_EARFCN;
    int64_t   dL_EARFCN;

    enum_Transmission_Bandwidth uL_Bandwidth;
    enum_Transmission_Bandwidth dL_Bandwidth;

    /*Default Constructor*/
    eNB_config() {
      pLMN_Identity         = (uint8_t*)"abc";
      macro_eNB_ID          = (uint8_t*)"5";
      pCI                   = 0;
      tAC                   = (uint8_t*)"ab";
      eUTRANcellIdentifier  = (uint8_t*)"def";
      uL_EARFCN             = 21400;
      dL_EARFCN             = 3400;
      uL_Bandwidth          = enum_bw25;
      dL_Bandwidth          = enum_bw50;
    }
};

class gNB_config {
  public:
    uint8_t* pLMN_Identity;
    uint8_t* gNB_ID;
    int64_t  nrpCI;
    uint8_t* tAC;
    uint8_t* nRcellIdentifier;

    int64_t   uL_nRARFCN;
    int64_t   dL_nRARFCN;

    enum enum_NRNRB uL_NRNRB;
    enum enum_NRNRB dL_NRNRB;

    enum enum_NRSCS uL_NRSCS;
    enum enum_NRSCS dL_NRSCS;

    uint8_t ul_freqBandIndicatorNr;
    uint8_t dl_freqBandIndicatorNr;

    std::string measurementTimingConfiguration;

    /*Default Constructor*/
    gNB_config() {
      pLMN_Identity         = (uint8_t*)"xyz";
      gNB_ID                = (uint8_t*)"3";
      nrpCI                 = 1;
      tAC                   = (uint8_t*)"ab";
      nRcellIdentifier      = (uint8_t*)"gnb_id_123";
      uL_nRARFCN            = 21400;
      dL_nRARFCN            = 21500;

      uL_NRNRB              = enum_nrb11;
      dL_NRNRB              = enum_nrb121;

      uL_NRSCS              = enum_scs15;
      dL_NRSCS              = enum_scs120;

      ul_freqBandIndicatorNr   = 11;
      dl_freqBandIndicatorNr   = 12;

      measurementTimingConfiguration = "dummy timing";
    }
};

enum enum_RICactionType {
  RICactionType_report,
  RICactionType_insert,
  RICactionType_policy
};

enum enum_RICcause {
  RICcause_radioNetwork = 1,
  RICcause_transport,
  RICcause_protocol,
  RICcause_misc,
  RICcause_ric
};

struct RIC_action_t {
    unsigned char       action_id;
    enum_RICactionType  action_type;
    bool                isAdmitted = false;   //for response/failure only
    enum_RICcause       notAdmitted_cause;    //for response/failure only
    unsigned int        notAdmitted_subCause; //for response/failure only

    RIC_action_t() {;}

    RIC_action_t(unsigned char id, enum_RICactionType type)
    {
        action_id   = id;
        action_type = type;
    }
};

struct RICsubscription_params_t {
  uint16_t request_id             = 0;
  uint16_t seq_number             = 0;
  uint16_t ran_func_id            = 0;
  std::string event_trigger_def   = "";

  std::vector<RIC_action_t> actionList;
} ;

#endif
