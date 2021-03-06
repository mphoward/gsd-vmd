# Copyright (c) 2017-2020, Michael P. Howard
# Copyright (c) 2021, Auburn University
# This file is part of the gsd-vmd project, released under the Modified BSD License.

cmake_minimum_required(VERSION 3.1)

project(gsd-vmd)
set(C_STANDARD_REQUIRED ON)

# find the vmd directory, and configure installation prefix
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)
find_package(VMD REQUIRED)
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX ${VMD_PLUGIN_MOLFILE_PATH} CACHE PATH "Install path prefix, prepended onto install directories." FORCE)
endif (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

# default is to compile for 32-bit and 64-bit architectures on OS X to guarantee compatibility
if (APPLE)
    set(CMAKE_OSX_ARCHITECTURES "i386;x86_64" CACHE STRING "Build architectures for OSX")
endif (APPLE)

# configure library target
include_directories(${VMD_PLUGIN_INCLUDE_PATH})
add_library(gsdplugin SHARED gsdplugin.c gsd.c)
set_target_properties(gsdplugin PROPERTIES PREFIX "" SUFFIX ".so" C_STANDARD 99)
install(TARGETS gsdplugin DESTINATION ${VMD_PLUGIN_MOLFILE_PATH})

# add the testing tree
enable_testing()
include(CTest)
if (BUILD_TESTING)
    add_subdirectory(tests)
endif (BUILD_TESTING)
