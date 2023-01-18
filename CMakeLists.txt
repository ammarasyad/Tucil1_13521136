cmake_minimum_required(VERSION 3.24)
project(StimaTucil1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mrdrnd")

add_executable(StimaTucil1 src/main.cpp src/inputhandler.h)
