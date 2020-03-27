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

set (E2SIM_ROOT ../../)

include_directories("${E2SIM_ROOT}/src")
include_directories("${E2SIM_ROOT}/src/DEF")
include_directories("${E2SIM_ROOT}/src/SCTP/")
include_directories("${E2SIM_ROOT}/src/E2AP")
include_directories("${E2SIM_ROOT}/src/E2AP/E2SM")
include_directories("${E2SIM_ROOT}/ASN1c")

find_library( SCTP_STD_LIB sctp )  #needed for sctp_sendmsg

#----------------------------------------------
file(GLOB WLG_SOURCES
      "${E2SIM_ROOT}/test/WLG/ric_wlg.cpp"
      "${E2SIM_ROOT}/src/DEF/*.cpp"
      "${E2SIM_ROOT}/src/SCTP/*.cpp"
      "${E2SIM_ROOT}/src/E2AP/*.c"
      "${E2SIM_ROOT}/src/E2AP/*.cpp"
      "${E2SIM_ROOT}/ASN1c/*.c"
      )
add_executable(ric_wlg ${WLG_SOURCES})
target_link_libraries( ric_wlg  ${SCTP_STD_LIB} )

#----------------------------------------------
file(GLOB RICPERF_SOURCES
      "${E2SIM_ROOT}/test/WLG/ric_perf.cpp"
      "${E2SIM_ROOT}/src/DEF/*.cpp"
      "${E2SIM_ROOT}/src/SCTP/*.cpp"
      "${E2SIM_ROOT}/src/E2AP/*.c"
      "${E2SIM_ROOT}/src/E2AP/*.cpp"
      "${E2SIM_ROOT}/ASN1c/*.c"
      )
add_executable(ric_perf ${RICPERF_SOURCES})
target_link_libraries( ric_perf ${SCTP_STD_LIB} )
