# Start from Ubuntu 18.04 base image
FROM ubuntu:bionic

# Set non-interactive mode for apt-get
ENV DEBIAN_FRONTEND=noninteractive

# Update the package list
RUN apt-get update && \
    # Install necessary packages
    apt-get install -y wget nano vim git dnsutils && \
    # Clone the git repository
    git clone https://github.com/wineslab/ran-e2sim.git && \
    cd ran-e2sim && \
    git checkout x5g-e2sim && \
    # Remove existing CMake installation
    apt-get remove -y --purge cmake && \
    # Download and extract the specified version of CMake
    cd /opt/ && \
    wget -nv --progress=bar https://github.com/Kitware/CMake/releases/download/v3.23.0-rc1/cmake-3.23.0-rc1-linux-x86_64.tar.gz && \
    tar -xf cmake-3.23.0-rc1-linux-x86_64.tar.gz && \
    rm -Rf cmake-3.23.0-rc1-linux-x86_64.tar.gz && \
    # Create symbolic links to the CMake binaries
    ln -s /opt/cmake-3.23.0-rc1-linux-x86_64/bin/* /usr/local/bin && \
    # Update the shared library cache
    ldconfig && \
    # Clean up the apt cache
    rm -rf /var/lib/apt/lists/* && \
    # Build the E2Sim project
    cd /ran-e2sim && \
    ./build_e2sim.sh -i && \
    ldconfig

# Set the working directory
WORKDIR /ran-e2sim

# Default command
CMD ["sleep infinity"]
