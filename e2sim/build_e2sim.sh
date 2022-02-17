#!/bin/bash

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
dpkg --install ./e2sim_?.?.?_amd64.deb
dpkg --install ./e2sim-dev_?.?.?_amd64.deb

# # build json
# git submodule init && git submodule update
# cd ../e2sm_examples/kpm_e2sm/nlohmann_json_release
# mkdir build || true
# cd build/
# cmake ..
# make -j ${nproc}
# make install
# ldconfig

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

