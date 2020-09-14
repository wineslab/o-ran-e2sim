#==================================================================================
#	Copyright (c) 2020 AT&T Intellectual Property.
#
#   Licensed under the Apache License, Version 2.0 (the "License"),
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#==================================================================================
#


project( ricxfcpp )
cmake_minimum_required( VERSION 3.14 )

set( major_version "1" )		# until CI supports auto tagging; must hard set
set( minor_version "0" )
set( patch_level "0" )

set( install_root "${CMAKE_INSTALL_PREFIX}" )
set( install_inc "/usr/local/include" )

# Must use GNUInstallDirs to install libraries into correct
# locations on all platforms.
include( GNUInstallDirs )

# externals may install using LIBDIR as established by the gnu include; it varies from system
# to system, and we don't trust that it is always set, so we default to lib if it is missing.
#
if( NOT CMAKE_INSTALL_LIBDIR )
	set( CMAKE_INSTALL_LIBDIR "lib" )
endif()

set( install_lib "${CMAKE_INSTALL_LIBDIR}" )

if( DEBUG )					# if set, we'll set debugging on in the compile
	set( debugging ${DEBUG} )
	message( "+++ debugging is being set to ${DEBUG}" )
else()
	set( debugging 0 )
	message( "+++ debugging is set to off" )
endif()
unset( DEBUG CACHE )					# we don't want this to persist


# ---------------- extract some things from git ------------------------------

# commit id for the version string
execute_process(
	COMMAND bash -c "git rev-parse --short HEAD|awk '{printf\"%s\", $0}'"
	OUTPUT_VARIABLE git_id
)

# define constants used in the version string, debugging, etc.
add_definitions(
	-DGIT_ID=${git_id}
	-DMAJOR_VER=${major_version}
	-DMINOR_VER=${minor_version}
	-DPATCH_VER=${patch_level}
	-DDEBUG=${debugging}
)

# Compiler flags
#
set( CMAKE_POSITION_INDEPENDENT_CODE ON )
if( GPROF )					# if set, we'll set profiling flag on compiles
	message( "+++ profiling is on" )
	set( CMAKE_C_FLAGS "-pg " )
	set( CMAKE_CPP_FLAGS "-pg " )
else()
	set( CMAKE_C_FLAGS "-g " )
	set( CMAKE_CPP_FLAGS "-g " )
	message( "+++ profiling is off" )
endif()
unset( GPROF CACHE )					# ensure this does not persist

# each binary is built from a subset
add_subdirectory( src/ASN1c )
add_subdirectory( src/kpm )


