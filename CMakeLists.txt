cmake_minimum_required (VERSION 3.0.0)

include(ExternalProject)


ExternalProject_Add(
  cppjson
  GIT_REPOSITORY "https://github.com/brandonphelps/my_cppjson"
  GIT_TAG "master"

  INSTALL_COMMAND cp ${reviewer_SOURCE_DIR}/cppjson-prefix/src/cppjson-build/cppjsonConfig.cmake ${CMAKE_SOURCE_DIR}/cmake/Modules/
)

project(reviewer)

set(cppjson_include "${reviewer_SOURCE_DIR}/cppjson-prefix/src/cppjson/main_project/include")
set(cppjson_lib "${reviewer_SOURCE_DIR}/cppjson-prefix/src/cppjson-build/main_project/src/libcppjson.dylib")

set(TARGET main)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

subdirs(main_project)
