cmake_minimum_required(VERSION 3.7)
project(MemSteve)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/Encoding.cpp include/Encoding.h include/WordCounter.h src/WordCounter.cpp)
add_executable(MemSteve ${SOURCE_FILES})