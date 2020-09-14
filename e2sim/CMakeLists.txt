
project (e2sim)
cmake_minimum_required ( VERSION 3.5 )

set ( major_version "1" )
set ( minor_version "0" )
set ( patch_level "0" )

set( install_root "${CMAKE_INSTALL_PREFIX}" )
set( install_inc "include/e2sim" )

if( MAN_PREFIX )
        set( install_man ${MAN_PREFIX} )                        # is there a cmake var for this -- can't find one
else()
        set( install_man "/usr/share/man" )                     # this needs to be fixed so it's not hard coded
endif()

include ( GNUInstallDirs )

if( NOT CMAKE_INSTALL_LIBDIR )
	set( CMAKE_INSTALL_LIBDIR "lib" )
endif()

set( install_lib "${CMAKE_INSTALL_LIBDIR}" )

if( ${CMAKE_SYSTEM_PROCESSOR} MATCHES "x86_64" )
	if( NOT PRESERVE_PTYPE )
		set( deb_sys_name "amd64" )
	else()
		set( deb_sys_name ${CMAKE_SYSTEM_PROCESSOR} )
	endif()
else()
	set( deb_sys_name ${CMAKE_SYSTEM_PROCESSOR} )
endif()
unset( PRESERVE_PTYPE CACHE )					# we don't want this to persist

set( rpm_sys_name ${CMAKE_SYSTEM_PROCESSOR} )

if( DEV_PKG )
    set( deb_pkg_name "e2sim-dev" )
    set( rpm_pkg_name "e2sim-devel" )
else()
    set( deb_pkg_name "e2sim" )
    set( rpm_pkg_name "e2sim" )
endif()

set( pkg_label "ricxfcpp${spoiled_str}-${major_version}.${minor_version}.${patch_level}-${sys_name}" )
set( rpm_pkg_label "${rpm_pkg_name}${spoiled_str}-${major_version}.${minor_version}.${patch_level}-${rpm_sys_name}" )
set( deb_pkg_label "${deb_pkg_name}${spoiled_str}_${major_version}.${minor_version}.${patch_level}_${deb_sys_name}" )
message( "+++ pkg name: ${deb_pkg_label}.deb" )

set( gen_rpm 0 )
find_program( rpm NAMES rpmbuild )					# rpm package gen requires this to be installed
if( "${rpm}" MATCHES "rpm-NOTFOUND" )				# cannot build rpm
	set( pkg_list "DEB" )
	message( "### make package will generate only deb package; cannot find support to generate rpm packages" )
else()
	message( "+++ pkg name: ${rpm_pkg_label}.rpm" )		# debugging if we think we can gen rpm too
	set( pkg_list "DEB;RPM" )
	set( gen_rpm 1 )
	message( "+++ make package will generate both deb and rpm packages" )
endif()

# bleeding cmake names are short novels; and when lines cannot be split they're a pain
set ( srcd "${CMAKE_CURRENT_SOURCE_DIR}" )

# this gets us round a chicken/egg problem. include files don't exist until make is run
# but Cmake insists on having these exist when we add them to include directories to
# enable code to find them after we build them.
#
include_directories( "${srcd}/src/DEF;${srcd}/src/SCTP;${srcd}/src/messagerouting;${srcd}/src/base;${srcd}/src/encoding" )


# Compiler flags
#
set( CMAKE_POSITION_INDEPENDENT_CODE ON )
set( CMAKE_C_FLAGS "-g " )
set( CMAKE_CPP_FLAGS "-g " )
set( CMAKE_CXX_FLAGS "-g " )
if( GPROF )					# if set, we'll set profiling flag on compiles
	message( "+++ profiling is on" )
	set( CMAKE_C_FLAGS "-pg " )
	set( CMAKE_CPP_FLAGS "-pg " )
else()
	message( "+++ profiling is off" )
endif()
unset( GPROF CACHE )					# we don't want this to persist




add_subdirectory(src/ASN1c)
add_subdirectory(src/DEF)
add_subdirectory(src/SCTP)
add_subdirectory(src/messagerouting)
add_subdirectory(src/base)
add_subdirectory(src/encoding)


add_library( e2sim_shared SHARED

"$<TARGET_OBJECTS:def_objects>;$<TARGET_OBJECTS:sctp_objects>;$<TARGET_OBJECTS:messagerouting_objects>;$<TARGET_OBJECTS:encoding_objects>;$<TARGET_OBJECTS:base_objects>"

)


# we only build/export the static archive (.a) if generating a dev package
if( DEV_PKG )
    	add_library( e2sim_static STATIC
        	     "$<TARGET_OBJECTS:def_objects>;$<TARGET_OBJECTS:sctp_objects>;$<TARGET_OBJECTS:messagerouting_objects>;$<TARGET_OBJECTS:encoding_objects>;$<TARGET_OBJECTS:base_objects>"
	)

	set_target_properties( e2sim_static
   			       PROPERTIES
   			       OUTPUT_NAME "e2sim"
   			       SOVERSION 1
   			       VERSION ${major_version}.${minor_version}.${patch_level}
	)

	target_include_directories( e2sim_static PUBLIC "src/DEF" "src/SCTP" "src/messagerouting" "src/base" "src/encoding" )	
endif()


if (DEV_PKG )
   set (target_list "e2sim_static" )
else()
   set (target_list "e2sim_shared" )
endif()

install( TARGETS ${target_list} EXPORT LibraryConfig
       LIBRARY  DESTINATION ${install_lib}
       ARCHIVE  DESTINATION ${install_lib}
       PUBLIC_HEADER DESTINATION ${install_inc}
)


unset( DEV_PKG  CACHE )			# prevent from being a hidden setting if user redoes things

IF( EXISTS "${CMAKE_ROOT}/Modules/CPack.cmake" )
	include( InstallRequiredSystemLibraries )

	set( CPACK_DEBIAN_PACKAGE_NAME ${deb_pkg_name} )
	set( CPACK_RPM_PACKAGE_NAME ${rpm_pkg_name} )

	set( CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/usr/local;/usr/local/bin;/usr/local/include;/usr/local/share;/usr/local/lib" )

	set( CPACK_set_DESTDIR "on" )
	set( CPACK_PACKAGING_INSTALL_PREFIX "${install_root}" )
	set( CPACK_GENERATOR "${pkg_list}" )

	set( CPACK_PACKAGE_DESCRIPTION "C++ framework for RIC xAPPs based on RMR." )
	set( CPACK_PACKAGE_DESCRIPTION_SUMMARY "RIC xAPP C++ framework library" )
	set( CPACK_PACKAGE_VENDOR "None" )
	set( CPACK_PACKAGE_CONTACT "None" )
	set( CPACK_PACKAGE_VERSION_MAJOR "${major_version}" )
	set( CPACK_PACKAGE_VERSION_MINOR "${minor_version}" )
	set( CPACK_PACKAGE_VERSION_PATCH "${patch_level}" )
	set( CPACK_PACKAGE "${pkg_label}" )						# generic name for old versions of cpack
	set( CPACK_DEBIAN_FILE_NAME "${deb_pkg_label}.deb" )
	set( CPACK_RPM_FILE_NAME "${rpm_pkg_label}.rpm" )

	# Future: define dependencies on RMR and other libs

	set( CPACK_DEBIAN_PACKAGE_PRIORITY "optional" )
	set( CPACK_DEBIAN_PACKAGE_SECTION "ric" )
	set( CPACK_DEBIAN_ARCHITECTURE ${CMAKE_SYSTEM_PROCESSOR} )
	set( CPACK_RPM_ARCHITECTURE ${CMAKE_SYSTEM_PROCESSOR} )

	# this seems ingnored if included
	#set( CPACK_COMPONENTS_ALL Libraries ApplicationData )

	INCLUDE( CPack )
ENDIF()
