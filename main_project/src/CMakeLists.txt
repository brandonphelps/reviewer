cmake_minimum_required(VERSION 3.0.0)

include_directories(${reviewer_SOURCE_DIR}/main_project/include)
include_directories(${cppjson_include})

aux_source_directory(. SOURCE)

find_package(libgit2)

message(STATUS "CPP JSON INCLUDE ${CppJson_INCLUDE_DIR}")

add_executable(${TARGET} ${SOURCE})
add_dependencies(${TARGET} cppjson)

if(APPLE)
  message(STATUS "Detected apple using .dylib")
  target_link_libraries(${TARGET} "${cppjson_lib}.dylib")
endif(APPLE)

if(MINGW)
  message(STATUS "Detected MINGW using .a")
  target_link_libraries(${TARGET} "${cppjson_lib}.a")
endif(MINGW)

if(LIBGIT2_FOUND)
  include_directories(${LIBGIT2_INCLUDE_DIR})
  target_link_libraries(${TARGET} ${LIBGIT2_LIBRARIES})
endif(LIBGIT2_FOUND)

