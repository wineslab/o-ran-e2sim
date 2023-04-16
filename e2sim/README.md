# E2 Simulator

Provides a simulator for the E2 interface to interact to the O-RAN RAN Intelligent Controller (E Release).
Supports connection with heterogeneous Radio Access Network software (e.g., srsRAN-based [SCOPE](https://github.com/wineslab/colosseum-scope), and [this version](https://github.com/EugenioMoro/openairinterface5g/tree/gbr-sps-xapp) of OpenAirInterface).
In the latter case, messages are expected to be Protobuf-serialized objects, and the `OAI_PROTOBUF` macro definition to be set to `1` in the [`kpm_callbacks.hpp` file](e2sm_examples/kpm_e2sm/src/kpm/kpm_callbacks.hpp)

```cc
#define OAI_PROTOBUF 1
```

## Build
Run `./build_e2sim.sh`, add `-i` to install all required dependencies and build JSON library from source.  

Note: cmake 3.14 or newer is needed. [Update cmake on Ubuntu 16.04](https://askubuntu.com/questions/355565/how-do-i-install-the-latest-version-of-cmake-from-the-command-line)

## Run
Run `./run_e2sim.sh`