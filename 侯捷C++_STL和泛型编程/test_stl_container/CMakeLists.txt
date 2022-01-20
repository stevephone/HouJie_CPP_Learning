cmake_minimum_required(VERSION 2.8.3)
add_compile_options(-std=c++11)

project(test_stl_container)

#set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})
#set(CMAKE_BUILD_TYPE "Debug")

add_executable(test_stl_container test_stl_container.cpp)
