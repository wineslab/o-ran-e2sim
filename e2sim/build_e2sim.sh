#!/bin/bash
#set -x

echo "Starting the build of E2SIM"

# log_level = 0 ->  LOG_LEVEL_UNCOND   0
# log_level = 1 -> LOG_LEVEL_ERROR     1
# log_level = 2 -> LOG_LEVEL_INFO      2
# log_level = 3 -> LOG_LEVEL_DEBUG     3

log_level=$1

if [ -n "$log_level" ]; then
  echo "LOG_LEVEL set is custom (${log_level})"
else
  echo "LOG_LEVEL set is 2 (INFO)"
  log_level=2
fi

# build
cd build || (echo "build folder does not exist, the script will create it" && mkdir build && cd build)
cmake .. -DDEV_PKG=1 -DLOG_LEVEL=${log_level}
make package

# uninstall old versions
echo "Going to remove e2sim-dev"
sudo apt-get purge -y e2sim-dev
# echo "Going to remove e2sim"
# sudo apt-get purge -y e2sim

# install new ones
#echo "Going to install e2sim"
#sudo dpkg --install ./e2sim_1.0.0_amd64.deb
echo "Going to install e2sim-dev"
sudo dpkg --install ./e2sim-dev_1.0.0_amd64.deb

cd ..

unset log_level

sudo ldconfig

echo "Build of E2SIM completed"
