cmake_minimum_required (VERSION 3.0.0)

include(ExternalProject)

project(reviewer)

set(TARGET main)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_PREFIX_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

subdirs(main_project)

