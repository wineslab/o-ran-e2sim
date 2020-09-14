#/*****************************************************************************
#                                                                            *
# Copyright 2019 AT&T Intellectual Property                                  *
# Copyright 2019 Nokia                                                       *
#                                                                            *
# Licensed under the Apache License, Version 2.0 (the "License");            *
# you may not use this file except in compliance with the License.           *
# You may obtain a copy of the License at                                    *
#                                                                            *
#      http://www.apache.org/licenses/LICENSE-2.0                            *
#                                                                            *
# Unless required by applicable law or agreed to in writing, software        *
# distributed under the License is distributed on an "AS IS" BASIS,          *
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
# See the License for the specific language governing permissions and        *
# limitations under the License.                                             *
#                                                                            *
#******************************************************************************/

This is an update to E2 Simulator, based on E2AP v1.



# INSTALLATION (tested on Ubuntu 16.04)
  1. Install dependencies
    $ sudo apt-get update
    $ sudo apt-get install -y
        build-essential
        git
        cmake
        libsctp-dev
        lksctp-tools
        autoconf
        automake
        libtool
        bison
        flex
        libboost-all-dev
    $ sudo apt-get clean

  2. SET ENVIRONMENT VARIABLE
    Add this line to `~/.bashrc`
      export E2SIM_DIR=<your e2sim directory>

  3. Build the official e2sim
    $ ./build_e2sim

# USAGE
  $  $E2SIM_DIR/build/e2sim [SERVER IP] [PORT]

  By default, SERVER IP = 127.0.0.1, PORT = 36421
  The RIC (i.e., E2 Manager) will need to setup X2 or E2 connection to e2sim on
  this SERVER IP and PORT

# DOCKER
  * Build docker image: run this command from $E2SIM_DIR
  $ sudo docker build -f docker/Dockerfile -t [DOCKER_IMAGE]:[TAG] .

  * Example how to run docker container
  $ sudo docker run --rm --net host -it [DOCKER_IMAGE]:[TAG] sh -c "./build/e2sim [SERVER IP] [PORT]"
  ex: sudo docker run --rm --net host -it e2sim:1.0.0 sh -c "./build/e2sim 127.0.0.1 36422"

