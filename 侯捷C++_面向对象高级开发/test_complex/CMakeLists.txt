
cmake_minimum_required(VERSION 2.8.3)
project(test_complex)

include_directories(
    INCLUDE_DIRECTORIES
    include
)

add_executable(test_complex src/test_complex.cpp)