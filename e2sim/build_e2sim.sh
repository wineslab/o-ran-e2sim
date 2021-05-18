#!/bin/bash
#set -x

# build
rm -rf build
mkdir build
cd build
cmake ..
make package
cmake .. -DDEV_PKG=1
make package

# uninstall old versions
sudo apt-get purge -y e2sim-dev
sudo apt-get purge -y e2sim

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
#pwd
#./src/kpm/kpm_sim 192.168.130.80 36422 gnb1 192.168.131.83
