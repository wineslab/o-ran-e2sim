#!/bin/bash -eu
#
#
# Copyright 2019 AT&T Intellectual Property
# Copyright 2019 Nokia
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

export C_INCLUDE_PATH=$HOME/usr/include
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/usr/lib
export RMR_SEED_RT=$HOME/global_rmr_files/global_rmr_routes.rt
gcc rmr_sender.c -g -o rmr_sender -L $HOME/usr/lib -lrmr_nng -lnng -lpthread -lm

export DUMMY_SENDER_RMR_RCV_PORT=38086 
export DEMO_SENDER_PTO=1			# poll timeout listening for replies
export DEMO_MAX_PAYLOAD_BYTES=240		# max_size of payload

./rmr_sender;
