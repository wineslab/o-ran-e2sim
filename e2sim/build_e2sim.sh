#!/bin/bash

PWD=$(pwd)

# build e2sim
rm -rf build
mkdir build
cd build
cmake ..
make -j ${nproc} package
cmake .. -DDEV_PKG=1
make -j ${nproc} package
make -j ${nproc} install
ldconfig

# unistall old versions
apt-get remove --purge e2sim-dev
apt-get remove --purge e2sim

# install new ones
dpkg --install ./e2sim_?.?.?_amd64.deb
#dpkg --install ./e2sim_1.0.0_amd64.deb
dpkg --install ./e2sim-dev_?.?.?_amd64.deb
#dpkg --install ./e2sim-dev_1.0.0_amd64.deb

# build example
cd ${PWD}/e2sm_examples/kpm_e2sm
rm -rf build
mkdir build
cd build
cmake ..
make -j ${nproc}

# run the example
# cd src/kpm/
# ./kpm_sim

