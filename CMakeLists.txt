cmake_minimum_required(VERSION 3.24)
project(Tucil1_13521136)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mrdrnd")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(Tucil1_13521136 src/main.cpp src/inputhandler.h src/solver.cpp src/solver.h)
