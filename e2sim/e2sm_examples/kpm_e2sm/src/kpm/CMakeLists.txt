#==================================================================================
#	Copyright (c) 2020 AT&T Intellectual Property.
#
#   Licensed under the Apache License, Version 2.0 (the "License"),
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#==================================================================================
#

add_executable( kpm_sim kpm_callbacks.cpp encode_kpm.cpp )

add_dependencies( kpm_sim asn1objects )
include_directories(.)
include_directories(../ASN1c)
include_directories(/usr/local/include/e2sim)
include_directories(/usr/local/include)

target_link_libraries( kpm_sim asn1objects )
target_link_libraries( kpm_sim e2sim )
target_link_libraries( kpm_sim asn1objects )
target_link_libraries( kpm_sim pthread)

install( 
    TARGETS kpm_sim
    DESTINATION ${install_bin}
)

