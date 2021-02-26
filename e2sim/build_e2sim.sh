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
sudo apt-get purge e2sim-dev
sudo apt-get purge e2sim

# install new ones
sudo dpkg --install ./e2sim_1.0.0_amd64.deb
sudo dpkg --install ./e2sim-dev_1.0.0_amd64.deb

# build example
cd ../e2sm_examples/kpm_e2sm
rm -rf build
mkdir build
cd build
cmake ..
make

# run the example
cd build/src/kpm/
./kpm_sim
