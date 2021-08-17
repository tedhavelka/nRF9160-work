# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(blink-plus-uart)

target_sources(app PRIVATE src/main.c)

add_subdirectory(drivers)



## Note per https://interrupt.memfault.com/blog/building-drivers-on-zephyr#adding-a-drivers-folder
##  the above stanza which calls `cmake` function named 'project' sets
##  directory in which this file resides to be given project's root dir.
