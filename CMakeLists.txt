cmake_minimum_required(VERSION 3.7)
project(MemSteve)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/Encoding.cpp include/Encoding.h include/Counter.h src/Counter.cpp include/Common.h src/Common.cpp)
add_executable(MemSteve ${SOURCE_FILES})