cmake_minimum_required(VERSION 3.10)
project(ThreadKV)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(
    threadkv src/main.cpp
    src/KeyValueStore.cpp
)