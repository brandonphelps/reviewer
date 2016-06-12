cmake_minimum_required(VERSION 3.0.0)

include_directories(${reviewer_SOURCE_DIR}/main_project/include)
include_directories(${cppjson_include})

aux_source_directory(. SOURCE)
# aux_source_directory(${cppjson_source} SOURCE)

find_package(libgit2)
find_package(cppjson REQUIRED)

message(STATUS "CPP JSON INCLUDE ${CppJson_INCLUDE_DIR}")

add_executable(${TARGET} ${SOURCE})
add_dependencies(${TARGET} cppjson)

# target_link_libraries(${TARGET} cppjson)
# target_link_libraries(${TARGET} ${cppjson_lib})

# add_library(cppjson INTERFACE IMPORTED)

if(LIBGIT2_FOUND)
  include_directories(${LIBGIT2_INCLUDE_DIR})
  target_link_libraries(${TARGET} ${LIBGIT2_LIBRARIES})
endif(LIBGIT2_FOUND)

