#!/bin/bash
#set -x

# build
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

cd ..
return