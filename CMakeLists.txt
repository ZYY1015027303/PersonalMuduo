cmake_minimum_required(VERSION 2.5)
project(MYmumuduo)

# MYmumuduo create as a so
set(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
#set debug info && start cpp11 stands
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# define comp file
aux_source_directory(. SRC_LIST)

add_library(mymuduo SHARED ${SRC_LIST})