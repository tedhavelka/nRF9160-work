#-------------------------------------------------------------------------------
# Kionix work, based on 'Zephyr Example Application'
#
# Copyright (c) <team name here>
# SPDX-License-Identifier: Apache-2.0


## https://cmake.org/cmake/help/latest/command/project.html


cmake_minimum_required(VERSION 3.13.1)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

## project(app LANGUAGES C VERSION 1.0.0)
## Reference https://cmake.org/cmake/help/latest/command/project.html
project(kionix-work LANGUAGES C VERSION 1.0.0)

## configure_file(app_version.h.in ${CMAKE_BINARY_DIR}/app/include/app_version.h)
## Reference https://cmake.org/cmake/help/latest/command/configure_file.html
## @brief from cmake:  "Copy a file to another location and modify its contents."
configure_file(kionix_work_version.h.in ${CMAKE_BINARY_DIR}/app/include/kionix_work_version.h)

## target_include_directories(app PRIVATE ${CMAKE_BINARY_DIR}/app/include src)
## Reference https://cmake.org/cmake/help/latest/command/target_include_directories.html
target_include_directories(kionix-work PRIVATE ${CMAKE_BINARY_DIR}/app/include src)

## target_sources(app PRIVATE src/main.c)
## Reference https://cmake.org/cmake/help/latest/command/target_sources.html
target_sources(kionix-work PRIVATE src/main.c)
