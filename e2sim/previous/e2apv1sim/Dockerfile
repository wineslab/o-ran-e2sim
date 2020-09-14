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

FROM ubuntu:16.04

# location in the container
ENV E2SIM_DIR /home/e2sim

# Install necessary packages
RUN apt-get update \
	&& apt-get install -y \
	build-essential \
	git \
	cmake \
	libsctp-dev \
	lksctp-tools \
	autoconf \
	automake \
	libtool \
	bison \
	flex \
  libboost-all-dev \
	iputils-ping \
	net-tools \
	nano \
	vim \
	tcpdump \
	net-tools \
	nmap \
  && apt-get clean

# Copy E2Sim sources into the container
COPY	 	./ ${E2SIM_DIR}
WORKDIR ${E2SIM_DIR}

#------------- Build E2SIM -----------------------
RUN   ./build_e2sim --clean
RUN   ./build_e2sim
CMD ./build/e2sim 10.107.70.168 36422