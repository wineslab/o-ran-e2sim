{{/*
   Copyright (c) 2019 AT&T Intellectual Property.
   Copyright (c) 2019 Nokia.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/}}
#!/bin/sh

# Launch the e2 simulator on ${E2SIM_BIND_ADDR}:${E2SIM_BIND_PORT}
#  If E2SIM_BIND_ADDR is not supplied, picks the address of the interface
#  associated with the default route for E2SIM_BIND_AF (either
#  "inet" [default] or "inet6").

if [ -z "${E2SIM_BIND_ADDR}" ]; then
  if [ `echo "x${E2SIM_BIND_AF}x" | tr [A-Z] [a-z]` != "xinet6x" ]; then
    AF='inet'
    DEFROUTE='0/0'
    LO='127.0.0.1'
  else
    AF='inet6'
    DEFROUTE='::0/0'
    LO='00:00:00:00:00:00'
  fi
  if [ -z "${E2SIM_BIND_IF}" ]; then
    # bind on the address associated with the default route
    E2SIM_BIND_IF=`ip -br -f ${AF} route show ${DEFROUTE}| sed 's/.*dev[\ ]*\([^\ ]*\).*/\1/'`
    if [ -z ${E2SIM_BIND_IF} ]; then
      # this is kinda bogus, but it's the only real fallback: take the first
      # non-loopback interface.
      E2SIM_BIND_IF=`ip -f ${AF} -o link list up | grep -v LOOPBACK | head -1 |awk -F: '{print $2}'`
    fi
  fi
  E2SIM_BIND_ADDR=`ip -f ${AF} -o addr show ${E2SIM_BIND_IF:-eth0} scope global | sed -e 's/.*inet[6\ ]*\([^\ ]*\)\/.*/\1/'`
fi

if [ -z $E2SIM_BIND_ADDR ]; then
  # search failed.  be nondestructively useless.
  echo "No suitable address found, binding on loopback addess ${LO}"
  E2SIM_BIND_ADDR=${LO}
else
  echo "e2sim starting at ${E2SIM_BIND_ADDR}:${E2SIM_PORT:-36421}"
fi

${E2SIM:-/home/e2sim/build/e2sim} ${E2SIM_BIND_ADDR} ${E2SIM_PORT:-36421}
