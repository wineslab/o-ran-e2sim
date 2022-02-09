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