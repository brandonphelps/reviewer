cmake_minimum_required (VERSION 3.0.0)

include(ExternalProject)

project(reviewer)


set(cppjson_include "${reviewer_SOURCE_DIR}/cppjson/main_project/include")
set(cppjson_lib "${reviewer_SOURCE_DIR}/build/cppjson/main_project/src/libcppjson")
set(TARGET main)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_PREFIX_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

subdirs(cppjson)
subdirs(main_project)

