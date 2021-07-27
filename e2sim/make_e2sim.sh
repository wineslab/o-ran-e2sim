#!/bin/bash
#set -x

# build
cd build
cmake ..
make package
cmake .. -DDEV_PKG=1
make package