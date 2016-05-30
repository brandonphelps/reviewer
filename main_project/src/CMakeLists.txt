



include_directories(${reviewer_SOURCE_DIR}/main_project/include)

aux_source_directory(. SOURCE)

find_package(libgit2)

if(LIBGIT2_FOUND)
  message("Found libgit 2")
endif(LIBGIT2_FOUND)

message(${SOURCE})

add_executable(main ${SOURCE})
