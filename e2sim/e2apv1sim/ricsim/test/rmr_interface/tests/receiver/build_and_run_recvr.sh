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
gcc rmr_rcvr.c -g -o rmr_rcvr -L $HOME/usr/lib -lrmr_nng -lnng -lpthread -lm

export PENDULUM_XAPP_RMR_RCV_PORT=5560
export DEMO_SENDER_PTO=1			# poll timeout listening for replies

export PRINT_FREQ=10000 #frequency at which test stats will be printed

RMR_RCV_ACK=1 ./rmr_rcvr $PRINT_FREQ;  # receiver that will ack every sender message
