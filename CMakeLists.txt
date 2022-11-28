cmake_minimum_required(VERSION 3.21)
project(3946S_V1)

set(CMAKE_CXX_STANDARD 14)

add_executable(3946S_V1 src/main.cpp src/subsystemFiles/flywheel_indexer.cpp include/subsystemHeaders/flywheel_indexer.hpp)
