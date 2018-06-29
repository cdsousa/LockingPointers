cmake_minimum_required(VERSION 3.5)
project(LockingPointers)

set(CMAKE_CXX_STANDARD 14)

add_executable(LockingPointers lock_ptr.hpp main.cpp)
target_link_libraries(LockingPointers pthread)
