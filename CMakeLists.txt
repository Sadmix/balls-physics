cmake_minimum_required(VERSION 3.22)

project(balls_physics LANGUAGES CXX C)

set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

enable_testing()

include_directories(include)

add_subdirectory(src)
add_subdirectory(tests)