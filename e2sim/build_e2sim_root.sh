#!/bin/bash

# build
rm -rf build
mkdir build 
cd build
cmake ..
make package
cmake .. -DDEV_PKG=1
make package

# unistall old versions
apt-get purge e2sim-dev
apt-get purge e2sim

# install new ones
dpkg --install ./e2sim_1.0.0_amd64.deb
dpkg --install ./e2sim-dev_1.0.0_amd64.deb

# build example
cd ../e2sm_examples/kpm_e2sm
rm -rf build
mkdir build
cd build
cmake ..
make

# run the example
cd src/kpm/
./kpm_sim
