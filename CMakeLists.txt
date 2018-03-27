cmake_minimum_required(VERSION 2.8)

project (Storage)

aux_source_directory(./src SRCS)
INCLUDE_DIRECTORIES(./src)

set(CMAKE_CXX_FLAGS_RELEASE "-std=c++11")

add_executable(Storage ${SRCS})
