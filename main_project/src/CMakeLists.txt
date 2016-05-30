



include_directories(${reviewer_SOURCE_DIR}/main_project/include)

aux_source_directory(. SOURCE)

find_package(libgit2)

message(${SOURCE})

add_executable(${TARGET} ${SOURCE})

if(LIBGIT2_FOUND)
  message(${LIBGIT2_LIBRARIES})
  include_directories(${LIBGIT2_INCLUDE_DIR})
  target_link_libraries(${TARGET} ${LIBGIT2_LIBRARIES})
  message("Found libgit 2")
endif(LIBGIT2_FOUND)




