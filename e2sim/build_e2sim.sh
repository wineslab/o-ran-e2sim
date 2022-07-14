#!/bin/bash

## dependencies
set -x

root_folder=$(pwd)

function build_json_from_source(){
git submodule init && git submodule update
cd $root_folder/e2sm_examples/kpm_e2sm/nlohmann_json_release
mkdir build || true
cd build/
cmake ..
make -j ${nproc}
make install
ldconfig
}

function clean_build(){
rm -rf $root_folder/build
}

function install_dependencies(){
apt-get update && apt-get install -y \
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
  libboost-all-dev
build_json_from_source
}

function print_help(){
echo "Usage:"
echo "-h: print this message"
echo "-i: install required dependencies"
echo "-c: clean build files"
exit 1
}


until [ -z "$1" ]
  do
    case "$1" in
       -h)
            print_help
            shift;;
       -i)
            install_dependencies
            shift;;
       -c)
	    clean_build
	    shift;;
        *)
           print_help
	   break;;
     esac
done

# this is the main code
# reset to root folder
cd $root_folder

CURR_DIR=$(pwd)
DEBUG=0

# build e2sim
rm -Rf build
mkdir build
cd build
cmake ..
make -j ${nproc} package
cmake .. -DDEV_PKG=1
make -j ${nproc} package
make -j ${nproc} install
ldconfig

# unistall old versions
apt-get remove --purge -y e2sim-dev
apt-get remove --purge -y e2sim

# install new ones
dpkg --install $(pwd)/e2sim*
#dpkg --install ./e2sim-dev_?.?.?_amd64.deb


# setup debug field
echo -e "\n[`date`] Setting metrics DEBUG field to ${DEBUG}\n"
sed -i "s/^#define DEBUG.*/#define DEBUG ${DEBUG}/g" ${CURR_DIR}/e2sm_examples/kpm_e2sm/src/kpm/bs_connector.hpp

# build example
cd ${CURR_DIR}/e2sm_examples/kpm_e2sm/
rm -Rf build
mkdir build
cd build
cmake ..
make -j ${nproc}

