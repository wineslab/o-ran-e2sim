# vim: ts=4 sw=4 noet:
#==================================================================================
#	Copyright (c) 2018-2019 AT&T Intellectual Property.
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#	   http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#==================================================================================


# --------------------------------------------------------------------------------------
#	Mnemonic:	Dockerfile
#	Abstract:	This dockerfile is used to create an image that can be used to
#				run the traffic steering xAPP in a container.
#
#				Building should be as simple as:
#
#					docker build -f Dockerfile -t ric-app-ts:[version]
#
#	Date:		27 April 2020
#	Author:		E. Scott Daniels
# --------------------------------------------------------------------------------------

# the builder has: git, wget, cmake, gcc/g++, make, python2/3. v7 dropped nng support
#
ARG CONTAINER_PULL_REGISTRY=nexus3.o-ran-sc.org:10001
FROM ${CONTAINER_PULL_REGISTRY}/o-ran-sc/bldr-ubuntu18-c-go:1.9.0 as buildenv

# spaces to save things in the build image to copy to final image
RUN mkdir -p /playpen/assets /playpen/src /playpen/bin
ARG SRC=.

WORKDIR /playpen

# versions we snarf from package cloud
ARG E2SIM_VER=1.0.0

# package cloud urls for wget
#ARG PC_REL_URL=https://packagecloud.io/o-ran-sc/release/packages/debian/stretch
#ARG PC_STG_URL=https://packagecloud.io/o-ran-sc/staging/packages/debian/stretch


# snarf up E2SIM dependencies, then pull E2SIM package and install
# Dependencies: sctp

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


#RUN wget -nv --content-disposition ${PC_STG_URL}/sdl_${SDL_VER}-1_amd64.deb/download.deb && \
#	wget -nv --content-disposition ${PC_STG_URL}/sdl-dev_${SDL_VER}-1_amd64.deb/download.deb &&\
#	dpkg -i sdl-dev_${SDL_VER}-1_amd64.deb sdl_${SDL_VER}-1_amd64.deb

#
# build and install the application(s)
#


COPY e2sim_1.0.0_amd64.deb /playpen
COPY e2sim-dev_1.0.0_amd64.deb /playpen

RUN dpkg -i e2sim_1.0.0_amd64.deb e2sim-dev_1.0.0_amd64.deb


RUN mkdir /usr/local/include/nlohmann
RUN git clone https://github.com/azadkuh/nlohmann_json_release.git
RUN cp nlohmann_json_release/json.hpp /usr/local/include/nlohmann

COPY . /playpen/src/
RUN wc -l /playpen/src/reports.json
RUN cd /playpen/src && \
	rm -fr .build &&\
	mkdir  .build && \
	cd .build && \
	cmake .. && \
	make install


CMD kpm_sim 10.110.102.29 36422
