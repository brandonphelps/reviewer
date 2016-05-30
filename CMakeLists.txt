


cmake_minimum_required (VERSION 3.0.0)

project (reviewer)

MESSAGE(${CMAKE_SOURCE_DIR})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

MESSAGE(${CMAKE_MODULE_PATH})

subdirs(main_project)
