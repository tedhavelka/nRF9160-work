#
# Copyright (c) 2021 Neela Nurseries
#

# Point to this project's root directory.
set(KIONIX_WORK_DIR ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "Kionix driver work root directory")

# Subdirectories
add_subdirectory(drivers)
add_subdirectory_ifdef(CONFIG_KX132_1211 lib)

# Include headers
zephyr_include_directories(include)
zephyr_include_directories(drivers)
