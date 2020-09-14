#!/bin/bash -eu
#
#
# Copyright 2019 AT&T Intellectual Property
# Copyright 2019 Nokia
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#


#git clone https://gerrit.oran-osc.org/r/ric-plt/lib/rmr && (cd rmr && curl -kLo `git rev-parse --git-dir`/hooks/commit-msg https://gerrit.oran-osc.org/r/tools/hooks/commit-msg; chmod +x `git rev-parse --git-dir`/hooks/commit-msg &&  git checkout 6735f136906ce2  )

cd rmr/
mkdir $HOME/usr
mkdir .build
cd .build
cmake .. -DCMAKE_INSTALL_PREFIX=$HOME/usr
make install
