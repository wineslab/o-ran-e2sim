#!/bin/bash
#set -x

log_level=$1

if [ -n "${log_level}" ]; then
  echo "Setting custom log level"
else
  echo "Setting log level to INFO"
  log_level=2
fi

# build
cd build || (echo "build folder does not exist" && return)
cmake ..
make package
cmake .. -DDEV_PKG=1 -DLOG_LEVEL="${log_level}"
make package

# uninstall old versions
sudo apt-get purge -y e2sim-dev
sudo apt-get purge -y e2sim

# install new ones
sudo dpkg --install ./e2sim_1.0.0_amd64.deb
sudo dpkg --install ./e2sim-dev_1.0.0_amd64.deb

cd ..
