cmake_minimum_required(VERSION 3.15)
# set the project name
project(MakeCHeader)
set(SRC_LIST pwd.h pwd.c file_exist.h file_exist.c memory.h memory.c main.c)
# add the executable
add_executable(${PROJECT_NAME} ${SRC_LIST})
