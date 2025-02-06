cmake_minimum_required(VERSION 3.30)
project(ZSV)

set(CMAKE_CXX_STANDARD 20)

add_library(ZSV SHARED zsv.cpp)
target_include_directories(ZSV PUBLIC include)