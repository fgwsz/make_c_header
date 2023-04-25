cmake_minimum_required(VERSION 3.15)
# set the project name
project(make_c_header)
aux_source_directory(src SRC_LIST)
include_directories(include)
# add the executable
add_executable(${PROJECT_NAME} ${SRC_LIST})
