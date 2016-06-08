cmake_minimum_required(VERSION 3.0.0)

include_directories(${reviewer_SOURCE_DIR}/main_project/include)

# message(STATUS ${cppjson_include})
include_directories(${cppjson_include})

aux_source_directory(. SOURCE)

find_package(libgit2)

add_executable(${TARGET} ${SOURCE})

target_link_libraries(${TARGET} ${cppjson_lib})


if(LIBGIT2_FOUND)
  message(${LIBGIT2_LIBRARIES})
  include_directories(${LIBGIT2_INCLUDE_DIR})
  target_link_libraries(${TARGET} ${LIBGIT2_LIBRARIES})
  message("Found libgit 2")
endif(LIBGIT2_FOUND)

