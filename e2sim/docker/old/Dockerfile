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

FROM e2sim_base

# ------------ COPY E2SIM codes ------------------
COPY	 	./ ${E2SIM_DIR}
WORKDIR ${E2SIM_DIR}

# ensure an empty rt is there if none is mounted at spinup
COPY docker/empty.rt /usr/local/route/local.rt

#------------- Build E2SIM -----------------------
RUN   ./build_e2sim --clean
RUN   ./build_e2sim

#-------------- Configure rmr -------------------------
ENV RMR_SEED_RT=/usr/local/route/local.rt
#export RMR_SEED_RT=$HOME/global_rmr_files/global_rmr_routes.rt

ENV RMR_RTG_SVC=localhost:9990
ENV E2TERM_RMR_RCV_PORT=48886
ENV DEMO_SENDER_PTO=1
ENV DEMO_MAX_PAYLOAD_BYTES=240

# --------------- Run E2Termination ---------------------
CMD ./build/e2sim
