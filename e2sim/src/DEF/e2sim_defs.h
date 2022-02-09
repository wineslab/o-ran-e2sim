/*
 *
 * Copyright 2019 AT&T Intellectual Property
 * Copyright 2019 Nokia
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef E2SIM_DEFS_H
#define E2SIM_DEFS_H

// #include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define VERSION             "1.2.0"      //May 2019
#define DEFAULT_SCTP_IP     "127.0.0.1"
#define X2AP_PPID           (452984832) //27 = 1b, PPID = 1b000000(hex) -> 452984832(dec)
#define X2AP_SCTP_PORT      36421
#define RIC_SCTP_SRC_PORT   38472
#define MAX_SCTP_BUFFER     10000
#define WORKDIR_ENV         "E2SIM_DIR" //environment variable


#ifndef LOG_LEVEL_USER
    #define LOG_LEVEL       3
#else
    #define LOG_LEVEL       LOG_LEVEL_USER
#endif
#define LOG_LEVEL_DEBUG     3
#define LOG_LEVEL_INFO      2
#define LOG_LEVEL_ERROR     1
#define LOG_LEVEL_UNCOND    0


char* time_stamp();

#define LOG_I(...) if(LOG_LEVEL>=LOG_LEVEL_INFO){printf("[%s] ", "INFO ");printf(__VA_ARGS__);printf("\n");}
#define LOG_E(...) if(LOG_LEVEL>=LOG_LEVEL_ERROR){printf("[%s] ", "ERROR");printf(__VA_ARGS__);printf("\n");}
#define LOG_D(...) if(LOG_LEVEL>=LOG_LEVEL_DEBUG){printf("[%s] ", "DEBUG");printf(__VA_ARGS__);printf("\n");}
#define LOG_U(...) if(LOG_LEVEL>=LOG_LEVEL_UNCOND){printf("[%s] ", "UNCON");printf(__VA_ARGS__);printf("\n");}

typedef struct SCTP_DATA {
  unsigned char *data;
  int           len;
} sctp_data_t;

typedef struct {
  unsigned char buffer[MAX_SCTP_BUFFER];
  int           len;
} sctp_buffer_t;

typedef struct {
  char* server_ip;
  int   server_port;
  char* gnb_id;
  int client_port;
  char* plmn_id;
} options_t;

options_t read_input_options(int argc, char *argv[]);



#endif
