
include_directories(${reviewer_SOURCE_DIR}/main_project/include)

aux_source_directory(. SOURCE)

message(${SOURCE})

add_executable(main ${SOURCE})
