# E2 Simulator

Provides a simulator for the E2 interface to interact to the O-RAN RAN Intelligent Controller (E Release).
Supports connection with heterogeneous Radio Access Network software (e.g., srsRAN-based [SCOPE](https://github.com/wineslab/colosseum-scope), and [this version](https://github.com/EugenioMoro/openairinterface5g/tree/gbr-sps-xapp) of OpenAirInterface).
In the latter case, messages are expected to be Protobuf-serialized objects, and the `OAI_PROTOBUF` macro definition to be set to `1` in the [`kpm_callbacks.hpp` file](e2sm_examples/kpm_e2sm/src/kpm/kpm_callbacks.hpp) (or in the [`./build_e2sim.sh` script](build_e2sim.sh))

```cc
#define OAI_PROTOBUF 1
```

## Build
Run `./build_e2sim.sh`, add `-i` to install all required dependencies and build JSON library from source.

Note:
- cmake 3.14 or newer is needed. [Update cmake on Ubuntu 16.04](https://askubuntu.com/questions/355565/how-do-i-install-the-latest-version-of-cmake-from-the-command-line)
- compiles only with gcc-9 and g++-9. [Set gcc and g++ alternatives](https://askubuntu.com/questions/26498/how-to-choose-the-default-gcc-and-g-version)

### Building Parameters

Building parameters can be found in: `build_e2sim.sh`.
To run with X5G KPM-xApp, please use the default `OAI_PROTOBUF=1`.

#### DEBUG
It sends a demo string to the DRL agent, used to test if there is an exchange of messages and if the control comes back.
Note that currently `DEBUG=1` does not work in combination with `OAI_PROTOBUF=1`.

#### OAI_PROTOBUF
Whether to use protobuf (1) or the asn1 encoding (0).

# RUN
Run `run_e2sim.sh <e2term-address> <e2term-port>`
