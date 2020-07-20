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

#include <stdio.h>
#include <string>
#include <iostream>

#include "e2sim_defs.h"
#include "asn_x2ap.hpp"
#include "e2sim_sctp.hpp"

using namespace std;

int main(int argc, char* argv[]){

  LOG_I("X2 Agent. Version %s", VERSION);

  options_t ops = read_input_options(argc, argv);

  int server_fd = sctp_start_server(ops.server_ip, ops.server_port);
  int client_fd = sctp_accept_connection(server_fd);


  return 0;
}
