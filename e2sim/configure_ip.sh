#!/bin/bash

# set -x
echo "Configure IPs"

if [ -z "$1" ]; then
  bs=1
else
  bs=$1
fi

for ((i = 83; i < 83 + bs; i++)); do
  echo "Created interface for NS with address 192.168.130.$i"
  sudo ifconfig lo:NS"$i" "192.168.130.$i"
done
