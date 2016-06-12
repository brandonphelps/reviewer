cmake_minimum_required (VERSION 3.0.0)

include(ExternalProject)

project(reviewer)

set(cppjson_source "${reviewer_SOURCE_DIR}/cppjson/src/cppjson/main_project/src")

set(TARGET main)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_PREFIX_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

subdirs(cppjson)
subdirs(main_project)

