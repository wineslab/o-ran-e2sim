#/*****************************************************************************
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
#******************************************************************************/

cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 14)

add_definitions("-D ASN_DISABLE_OER_SUPPORT")

project(e2sim)

set (HOME_DIR $ENV{HOME})
#set (E2SIM_ROOT ../../../)

include_directories("src")
include_directories("src/SCTP/")
include_directories("src/E2AP")
include_directories("src/E2AP/E2SM")
include_directories("ASN1c")

find_library( SCTP_LIBRARY sctp )  #needed for sctp_sendmsg

#----------------------------------------------
file(GLOB E2AGENT_SOURCES
      "src/e2agent.cpp"
      "src/e2sim_defs.cpp"
      "src/SCTP/*.cpp"
      "src/E2AP/*.c"
      "src/E2AP/*.cpp"
      "ASN1c/*.c"
      )
add_executable(e2agent ${E2AGENT_SOURCES})
target_link_libraries( e2agent ${SCTP_LIBRARY} )

#----------------------------------------------
file(GLOB RICSIM_SOURCES
      "src/ric_sim.cpp"
      "src/e2sim_defs.cpp"
      "src/SCTP/*.cpp"
      "src/E2AP/*.c"
      "src/E2AP/*.cpp"
      "ASN1c/*.c"
      )
add_executable(ric_sim ${RICSIM_SOURCES})
target_link_libraries( ric_sim ${SCTP_LIBRARY} )


#----------------------------------------------
file(GLOB X2TERM_SOURCES
      "src/x2term.cpp"
      "src/e2sim_defs.cpp"
      "src/SCTP/*.cpp"
      "src/E2AP/*.c"
      "src/E2AP/*.cpp"
      "ASN1c/*.c"
      )
add_executable(x2term ${X2TERM_SOURCES})
target_link_libraries( x2term ${SCTP_LIBRARY} )


#-----------------------------------------------
file(GLOB TEST
      "src/test_asn1c.cpp"
      "src/e2sim_defs.cpp"
#      "src/SCTP/*.cpp"
      "ASN1c/*.c"
      "src/E2AP/*.c"
      "src/E2AP/E2SM/*.c"
      )
add_executable(test_asn1c ${TEST})
